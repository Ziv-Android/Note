#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import base64
import binascii
import sys
import time

from PyQt5.QtWidgets import QMainWindow, QApplication, QMessageBox
try:
    from ui.ui_home import Ui_MainWindow
except:
    from ui_home import Ui_MainWindow
import configparser
import ast

test_data_0 = "7F 10 2D 34 37 63 66 31 39 63 35 2D 30 63 65 65 64 62 35 37 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 22 04 12 14 52 11 00 01 01 00 01 00 01 16"
test_data_1 = "7F 12 89 34 37 63 66 31 39 63 35 2D 30 63 65 65 64 62 35 37 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 20 22 04 12 15 51 20 00 0A 01 00 00 00 00 00 00 00 00 02 00 E8 8B 8F 42 46 30 38 33 34 33 00 00 00 00 00 00 05 00 5F 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 69 16"
test_data_2 = "fxKJNDdjZjE5YzUtMGNlZWRiNTcAAAAAAAAAAAAAAAAAAAAgIgQSGFZDAAoBAAAAAAAAAAACAOaXoOeJjOi9pgAAAAAAAAAAIAACAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAArFg=="
test_data_3 = "{'设备唯一编号': '47cf19c5-0ceedb57', '时间': '2022041218564300', '触发类型': '0A', '车位编号': '01', '识别id': '00000000', '证据链id': '00000000', '车位状态': '02', '报警状态': '00', '车牌号': '无牌车', '车牌颜色': '00', '车牌类型': '20', '车牌置信度': '00', '停车方向': '02', '准入状态': '02', '车型': '', '车标': ''}"

test_data = [test_data_0, test_data_1, test_data_2, test_data_3]


class HomeWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, config=None):
        super(HomeWindow, self).__init__()
        self.setupUi(self)
        self.event_list = {}
        self.date_is_base64 = False
        self.current_mode = None

        self.cfg = self.read_config(config)

        self.comboBox.addItems(self.event_list.keys())
        self.comboBox.currentIndexChanged.connect(self.mode_changed)

        self.pushButton_data_maker.clicked.connect(self.data_maker)
        self.pushButton_analysis.clicked.connect(self.data_analysis)
        self.pushButton_clean.clicked.connect(self.data_clean)

        self.checkBox_base64.stateChanged.connect(self.input_data_format)

        self.mode_changed(self.cfg)

    def input_data_format(self, data):
        self.date_is_base64 = (data == 2)

    def read_config(self, path=None):
        cfg = configparser.RawConfigParser()
        try:
            cfg.read(path, encoding="utf-8")
        except Exception as e:
            print("ConfigManager init exception:", e)

        sections = cfg.sections()
        for item in sections[1:]:
            self.event_list[cfg[item]['name']] = item
        print(self.event_list)
        return cfg

    # 模式变化
    def mode_changed(self, mode):
        current_mode_text = self.comboBox.currentText()
        self.current_mode = self.event_list[current_mode_text]
        modes = self.cfg.items(self.current_mode)

        result = {}
        for i in range(1, len(modes)):
            key, value = modes[i]
            if key == '时间':
                result[key] = time.strftime('%Y%m%d%H%M%S', time.localtime((time.time())))
            elif key == '设备唯一编号':
                result[key] = self.lineEdit_sn.text().strip()
            else:
                result[key] = ''

        self.textEdit_result.setText(str(result))
        print("algorithm_changed:", self.current_mode)

    def data_check(self, data):
        if len(data) < 5 or data[0] != "7F" or data[-1] != '16':
            QMessageBox.warning(self, "错误", "数据异常")
            return False

        check = 0
        for item in data[1:-3]:
            check += int(item, 16)

        print(check, int(data[1], 16), check % 256, int(data[-2], 16))
        if check % 256 != int(data[-2], 16):
            QMessageBox.warning(self, "错误", f"数据校验未通过({int(data[-2], 16)}, {check % 256})")
            return False

        return True

    def data_analysis(self):
        data = self.textEdit_origin_data.toPlainText()
        if self.date_is_base64:
            data = base64.b64decode(data).hex().upper()
            print(len(data), data)
            data = [data[2*i:2*(i+1)] for i in range(int(len(data)/2))]
        else:
            data = data.split(" ")
        # print("data_analysis", len(data), data)
        if not self.data_check(data):
            return

        temp = []
        result = {}
        modes = self.cfg.items(self.current_mode)
        # print(modes)
        config_data_start = 3

        for i in range(1, len(modes)):
            key, value = modes[i]
            for item in data[config_data_start:config_data_start + int(value)]:
                if key == "设备唯一编号":
                    if item == '00' and len(temp) >= 17:
                        break
                    else:
                        char = chr(int(item, 16))
                        temp.append(char)
                else:
                    temp.append(item)
            temp_str = "".join(temp)
            if key in ["车牌号", "车型", "车标", "语音内容"]:
                temp_str_hex = temp_str.encode('utf-8')
                str_bin = binascii.unhexlify(temp_str_hex)
                temp_str = str_bin.decode('utf-8').strip().strip(b'\x00'.decode())
                print(key, temp_str)
            result[key] = temp_str
            temp.clear()
            config_data_start = config_data_start + int(value)

        self.textEdit_result.setText(str(result))

    def data_maker(self):
        data = self.textEdit_origin_data.toPlainText()
        try:
            data = ast.literal_eval(data)
        except Exception as e:
            print("data_maker", e)
            return

        modes = self.cfg.items(self.current_mode)
        length_total = 0
        for key, value in modes[1:]:
            length_total += int(value)

        result = ['7F', self.current_mode[2:].upper(), str(hex(length_total))[-2:].upper()]

        for i in range(1, len(modes)):
            key, value = modes[i]
            temp = []
            if key in ["设备唯一编号", "车牌号", "车型", "车标", "语音内容"]:
                temp_str = data[key].encode('utf-8')
                if key in ["语音内容"]:
                    temp_str = base64.b64encode(temp_str)
                temp_str_hex = binascii.hexlify(temp_str).decode('utf-8').upper()
                temp = [temp_str_hex[2 * i:2 * (i + 1)] for i in range(int(len(temp_str_hex) / 2))]
            else:
                try:
                    temp_str = data[key].upper()
                    temp = [temp_str[2 * i:2 * (i + 1)] for i in range(int(len(temp_str) / 2))]
                except Exception as e:
                    print("data_maker", e)

            size = int(value) - len(temp)
            if size > 0:
                for j in range(size):
                    temp.append('00')
            result.extend(temp)

        check = 0
        for item in result[1:]:
            check += int(item, 16)

        check = check % 256
        if check < 16:
            check = hex(check)[2:].zfill(2)
        else:
            check = str(hex(check))[-2:]
        result.append(check.upper())
        result.append('16')
        self.textEdit_result.setText(" ".join(result))

    def data_clean(self):
        self.textEdit_origin_data.clear()
        self.textEdit_result.clear()


if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = HomeWindow()
    window.show()

    sys.exit(app.exec_())
