#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow

# import webbrowser

from PyQt5 import QtWidgets

from c_protocol import *
from libutils.tcpclient import TCPClient
from oqc_tool.ui_w241_final_log import Ui_W241FinalLog


#
class W241FinalLog(QtWidgets.QWidget, Ui_W241FinalLog):
    name = "log"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.pname = None
        self.client_tcp = None

        # self.testResultText = QtWebEngineWidgets.QWebEngineView(self)
        self.testResultText.setOpenExternalLinks(True) # 使其成为超链接
        self.pFinishBtn.clicked.connect(self.autotest_finish)
        self.pushButton_set_data.clicked.connect(self.set_custom_sn_cfg_client)

        self.set_custom_sn_layout_visible(False)

    def set_customer(self, cc, cus):
        self.pname = cc.get_conf_pname(cus)

    def autotest_restart(self):
        print('log autotest_restart')
        return True

    def autotest_finish(self):
        # webc = self.pwm.http_client_handle()
        # ret, resp = c_log_sys(webc)
        # jl = json.loads(resp)
        # for log in jl['body']['logs']:
        #     ss = "%s\t%s" % (log['time'], log['data'])
        #     self.pLogEdit.appendPlainText(ss)
        print('log autotest_finish')
        self.pwm.pwm.pTestStackWidget.setCurrentIndex(0)
        self.pwm.pwm.w21_dat.pDevHostEdit.setText("192.168.1.100")
        return True

    def show_result_html(self, path):
        local_path_url = "file:///" + path.replace("\\", "/")
        print(local_path_url)
        # self.testResultText.load(QtCore.QUrl(local_path_url))
        # webbrowser.open_new_tab(local_path_url)
        self.testResultText.setText(f'测试报告：<a href={local_path_url}>{local_path_url}</a> 浏览器打开查看详情<br/><br/>测试报告存档在doc路径下<br/>')

    def show_custom_sn_cfg(self, secret_key, secret_sn):
        self.lineEdit_data.setText(secret_key)
        self.lineEdit_custom_sn.setText(secret_sn)

    def set_custom_sn_layout_visible(self, visible):
        self.label_custom_sn.setVisible(visible)
        self.lineEdit_custom_sn.setVisible(visible)
        self.label_data.setVisible(visible)
        self.lineEdit_data.setVisible(visible)
        self.pushButton_set_data.setVisible(visible)

    def set_custom_sn_cfg(self, tcp=None, secret_key=None, secret_sn=None):
        if tcp is None:
            host = self.pwm.pwm.w21_dat.pDevHostEdit.text()
            self.client_tcp = TCPClient(host)
        else:
            self.client_tcp = tcp
        return set_custom_cfg(self.client_tcp, secret_key, secret_sn)

    def get_custom_sn_cfg(self, tcp=None):
        if tcp is None:
            host = self.pwm.pwm.w21_dat.pDevHostEdit.text()
            self.client_tcp = TCPClient(host)
        else:
            self.client_tcp = tcp
        return get_custom_cfg(self.client_tcp)

    def get_sn(self, tcp=None):
        if tcp is None:
            host = self.pwm.pwm.w21_dat.pDevHostEdit.text()
            self.client_tcp = TCPClient(host)
        else:
            self.client_tcp = tcp
        return get_device_info(self.client_tcp)

    def set_custom_sn_cfg_auto(self, enable=False):
        if self.pname != 'lifang':
            self.set_custom_sn_layout_visible(False)
            return False
        path = self.pwm.get_custom_sn_file()
        if path == '':
            QtWidgets.QMessageBox.warning(self, "警告", "未选择密钥文件")
            self.get_custom_sn_cfg_client()
            return False
        self.set_custom_sn_layout_visible(True)
        _tcp = TCPClient(self.pwm.pwm.w21_dat.pDevHostEdit.text())
        secret_key, secret_sn = self.get_custom_sn_cfg(_tcp)
        print("原有数据", "secret_sn", secret_sn, "secret_key", secret_key)
        if secret_key == "" or secret_sn == "":
            title_data, excel_data = load_excel_data(path)
            # print(title_data, excel_data)
            for key, value in excel_data.items():
                if value[4].strip() == '':
                    print("自动烧录", "secret_sn", value[1], "secret_key", value[2])
                    result_set_custom_sn = self.set_custom_sn_cfg(_tcp, secret_key=value[2], secret_sn=value[1])
                    if result_set_custom_sn:
                        value[4] = self.get_sn(_tcp)
                        print("自动烧录成功", value[4])
                        write_excel_data(title_data, excel_data, path)
                        self.show_custom_sn_cfg(value[2], value[1])
                        QtWidgets.QMessageBox.warning(self, "提示", "烧录成功")
                        return True
                    else:
                        print("自动烧录失败，烧录错误")
                        QtWidgets.QMessageBox.warning(self, "警告", "烧录错误")
                        return False
            print("自动烧录失败，所有密钥已使用")
            QtWidgets.QMessageBox.warning(self, "警告", "所有密钥已使用")
        else:
            print("自动烧录失败，密钥已存在")
            self.show_custom_sn_cfg(secret_key, secret_sn)
            QtWidgets.QMessageBox.warning(self, "警告", "密钥已存在")
        return False

    def set_custom_sn_cfg_client(self):
        self.pushButton_set_data.setEnabled(False)
        secret_sn = self.lineEdit_custom_sn.text()
        secret_key = self.lineEdit_data.text()
        print("烧录", secret_sn, secret_key)
        result_set_custom_sn = self.set_custom_sn_cfg(tcp=None, secret_key=secret_key, secret_sn=secret_sn)
        if result_set_custom_sn:
            print("烧录成功")
            self.show_custom_sn_cfg(secret_key, secret_sn)
            QtWidgets.QMessageBox.warning(self, "提示", "烧录成功")
        else:
            print("烧录错误")
            QtWidgets.QMessageBox.warning(self, "警告", "烧录错误")
        self.pushButton_set_data.setEnabled(True)

    def get_custom_sn_cfg_client(self):
        if self.pname == 'lifang':
            self.set_custom_sn_layout_visible(True)
            secret_key, secret_sn = self.get_custom_sn_cfg()
            print("原有数据", "secret_sn", secret_sn, "secret_key", secret_key)
            if secret_key is None:
                secret_key = ''
            if secret_sn is None:
                secret_sn = ''
            self.show_custom_sn_cfg(secret_key, secret_sn)
            self.show_sn_cfg_client()

    def show_sn_cfg_client(self):
        sn = self.get_sn()
        if sn is None or sn == "":
            self.label_sn.setVisible(False)
        else:
            self.label_sn.setVisible(True)
            self.label_sn.setText(f"SN: {sn}")
