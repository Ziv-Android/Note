#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread
import time

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal
from PyQt5.QtGui import QColor
from PyQt5.QtWidgets import QMessageBox

from c_factory import *
from c_heart_beat import *
from oqc_tool.cfg_device_info import *
from oqc_tool.w233_extern_log import W233ExternLog
from oqc_tool.w231_extern_gpio import W231ExternGPIO
from oqc_tool.w232_extern_serial import W232ExternSerial
from oqc_tool.ui_w23_extern_device import Ui_W23ExternDevice

from libutils.wordreport import *
from c_rs485 import *


#
class W23ExternDevice(QtWidgets.QWidget, Ui_W23ExternDevice):
    name = "interface"
    fail_test_signal = pyqtSignal()
    stop_click_signal = pyqtSignal(int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    auto_test_signal = pyqtSignal(str, str)
    auto_test_finish_signal = pyqtSignal(str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm

        self.is_485_pass = 0
        self.autotest_state = 0

        self.ext_gpio = W231ExternGPIO(self)
        self.pWidgetVLayout.addWidget(self.ext_gpio)

        self.ext_serial = W232ExternSerial(self)
        self.pWidgetVLayout.addWidget(self.ext_serial)

        self.vdo_led = self.pwm.w22_vdo.vdo_led

        self.ext_log = W233ExternLog(self)
        self.pWidgetVLayout.addWidget(self.ext_log)
        self.auto_test_signal.connect(self.test_case_update_state)
        self.fail_test_signal.connect(self.show_fail_dialog)
        self.auto_test_finish_signal.connect(self.test_case_finish_state)
        self.stop_click_signal.connect(self.stop_test_click)

    def http_client_handle(self):
        return self.pwm.http_client_handle()

    def widget_init(self):
        # 产品相关
        cp, pro = self.pwm.get_product()
        self.dlens = cp.get_capacity_num('dlens')
        print("widget_init", "reset", cp.get_capacity_num(self.ext_gpio.name_reset),
              "ioin", cp.get_capacity_num(self.ext_gpio.name_ioin),
              "ioout", cp.get_capacity_num(self.ext_gpio.name_ioout))
        self.ext_gpio.widget_init(cp.get_capacity_num(self.ext_gpio.name_reset),
                                  cp.get_capacity_num(self.ext_gpio.name_ioin),
                                  cp.get_capacity_num(self.ext_gpio.name_ioout))
        self.ext_serial.widget_init(cp.get_capacity_num(self.ext_serial.name))

        self.pTestCaseLWdg.clear()
        self.testcase = [
            '485连接',
            '补光灯',
            'IO-测试',
            '串口通信',
            '复位按键',
            # '网口信息',
            '日志读取',
            '恢复出厂'
        ]
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)

    def autotest_stop(self, i=-1):
        print('extern autotest_stop')
        self.autotest_state = 5
        self.pwm.w21_dat.pAutotestButton.setText("开始测试(F8)")
        if i == -1:
            self.fail_test_signal.emit()

    def autotest_reset(self):
        print('extern autotest_reset')
        self.autotest_state = 0
        self.pTestCaseLWdg.clear()
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)
        self.pwm.w21_dat.pAutotestButton.setText("开始测试(F8)")

    #
    def autotest_start(self, host, username, password, i):
        self.widget_init()
        if self.autotest_state == 0 or self.autotest_state == 5:
            self.pwm.w21_dat.pAutotestButton.setText("停止测试(F8)")

        print('extern start_autotest %s %s %s' % (host, username, password))
        if self.autotest_state == 1:
            print('has been in the test')
            self.pwm.w21_dat.pAutotestButton.setEnabled(False)
            self.autotest_stop(0)
            return

        self.host = host
        self.username = username
        self.password = password

        try:
            self.autotest_state = 1
            _thread.start_new_thread(self.autotest_usercase_traversal,
                                     ("autotest", host, username, password, i,))
        except:
            print("can't start thread")

    # 更新QListWidget item显示
    def test_case_update_state(self, text, suc):
        print(text, suc)
        if self.autotest_state == 5:
            return
        count = self.pTestCaseLWdg.count()
        for i in range(count):
            tt = self.pTestCaseLWdg.item(i).text()
            if tt.find(text) != -1:
                self.pTestCaseLWdg.item(i).setText(text + '\t\t' + suc)
                if suc == "成功":
                    self.pTestCaseLWdg.item(i).setBackground(QColor('green'))
                elif suc == "失败":
                    self.pTestCaseLWdg.item(i).setBackground(QColor('red'))
                elif suc == "跳过":
                    self.pTestCaseLWdg.item(i).setBackground(QColor('blue'))
                break

    def show_fail_dialog(self):
        QtWidgets.QMessageBox.warning(self, "失败", "测试未通过")

    def stop_test_click(self):
        self.pwm.w21_dat.pAutotestButton.setEnabled(True)

    # 自动
    def autotest_usercase_traversal(self, tname, host, username, password, i):
        print("extern autotest_usercase_traversal %s %s %s %s " % (tname, host, username, password), i)
        count = self.pTestCaseLWdg.count()
        if count <= 0:
            return False
        self.auto_test_signal.emit(self.testcase[0], '开始')
        if i == 0:
            if self.pwm.w21_dat.is_search:
                self.pwm.w21_dat.search_device()
            print("extern autotest_usercase_traversal i=", i)
            report_doc.report_start(time.time())
            report_doc.report_sn(self.device_info())
        params = report_doc.get_empty_params()

        cp, pro = self.pwm.get_product()

        num_485 = cp.get_capacity_num("num_485")
        dlens = cp.get_capacity_num("dlens")
        # '485测试'
        i = 0
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        url = 'http://%s' % host
        webc = WEBClient(url, username, password)
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if num_485 == 1:
            c_rs485_write(webc, 0, '$001,01&')
            time.sleep(1)
            ret, data = c_rs485_read(webc, 0)
            if data == 'OK':
                self.is_485_pass = 1
                params[self.testcase[i]] = "成功"
                self.auto_test_signal.emit(self.testcase[i], '成功')
            else:
                self.is_485_pass = 0
                if dlens == 1:
                    params[self.testcase[i]] = "双目远端无此接口"
                    self.auto_test_signal.emit(self.testcase[i], '双目远端无此接口')
                else:
                    params[self.testcase[i]] = "失败"
                    self.auto_test_signal.emit(self.testcase[i], '失败')
        elif num_485 == 2:
            c_rs485_write(webc, 0, '$001,01&')
            time.sleep(0.5)
            ret, data = c_rs485_read(webc, 1)
            if ret == 200:
                c_rs485_write(webc, 1, '$001,01&')
                time.sleep(0.5)
                ret, data = c_rs485_read(webc, 0)
                if ret == 200:
                    self.is_485_pass = 1
                    params[self.testcase[i]] = "成功"
                    self.auto_test_signal.emit(self.testcase[i], '成功')
                else:
                    self.is_485_pass = 0
                    params[self.testcase[i]] = "失败"
                    self.auto_test_signal.emit(self.testcase[i], '失败')
            else:
                self.is_485_pass = 0
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
            # if data == 'OK' or data == '$001,01&':
            #     c_rs485_write(webc, 1, '$001,01&')
            #     time.sleep(0.5)
            #     ret, data = c_rs485_read(webc, 0)
            #     if data == 'OK' or data == '$001,01&':
            #         self.is_485_pass = 1
            #         params[self.testcase[i]] = "成功"
            #         self.auto_test_signal.emit(self.testcase[i], '成功')
            #     else:
            #         self.is_485_pass = 0
            #         params[self.testcase[i]] = "失败"
            #         self.auto_test_signal.emit(self.testcase[i], '失败')
            # else:
            #     self.is_485_pass = 0
            #     params[self.testcase[i]] = "失败"
            #     self.auto_test_signal.emit(self.testcase[i], '失败')

        # '补光灯'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if dlens == 1 and self.is_485_pass == 0:
            params[self.testcase[i]] = "跳过"
            self.auto_test_signal.emit(self.testcase[i], '跳过')
        else:
            ret = self.vdo_led.led_ctrl(10, 1)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(50, 1)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(100, 1)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(-1, 1)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            params[self.testcase[i]] = "成功"
            self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IO-测试'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if dlens == 1 and self.is_485_pass == 0:
            params[self.testcase[i]] = "跳过"
            self.auto_test_signal.emit(self.testcase[i], '跳过')
        else:
            ret = self.ext_gpio.autotest_usercase_gpio()
            if ret == 404 or ret is False:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            params[self.testcase[i]] = "成功"
            self.auto_test_signal.emit(self.testcase[i], '成功')

        # '串口通信'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if dlens == 1 and self.is_485_pass == 0:
            params[self.testcase[i]] = "跳过"
            self.auto_test_signal.emit(self.testcase[i], '跳过')
        else:
            if self.ext_serial.num_serial <= 0:
                params[self.testcase[i]] = "无此接口"
                self.auto_test_signal.emit(self.testcase[i], '无此接口')
            else:
                ret = self.ext_serial.autotest_usercase()
                if ret == 404 or ret is False:
                    params[self.testcase[i]] = "失败"
                    self.auto_test_signal.emit(self.testcase[i], '失败')
                    self.autotest_stop()
                    return False
                params[self.testcase[i]] = "成功"
                self.auto_test_signal.emit(self.testcase[i], '成功')

        # '网口信息'
        # i = i+1
        # if self.autotest_state == 5:
        #     return False
        # self.auto_test_signal.emit(self.testcase[i], '开始')
        # # ret = self.ext_serial.autotest_usercase(self.webc)
        # time.sleep(1)
        # if ret == 404 or ret is False:
        #     self.auto_test_signal.emit(self.testcase[i], '失败')
        #     self.autotest_state = 0
        #     return False
        # self.auto_test_signal.emit(self.testcase[i], '成功')

        # '复位按键'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_gpio.autotest_usercase_reset()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '日志读取'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_log.autotest_usercase()
        time.sleep(1)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '恢复出厂'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if self.dlens == 0:
            self.pwm.w22_vdo.close_sdk_hdl()
            self.pwm.w21_dat.pLoginButton.setText("设备登录")
        else:
            if host == "192.168.1.101":
                self.pwm.w22_vdo.close_sdk_hdl()
                self.pwm.w21_dat.pLoginButton.setText("设备登录")

        webc = self.http_client_handle()
        ret = c_factory(webc, 2)
        time.sleep(0.5)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_state = 5
            return False
        params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')

        report_doc.report_extern(params)
        report_doc.report_end("通过", time.time())

        time.sleep(0.5)
        report_doc.save_doc()
        self.auto_test_finish_signal.emit(host)

    def test_case_finish_state(self, host):
        print(f"all test case finish {host}, switch -> {self.pwm.w24_ret.name}")
        self.autotest_reset()
        QtWidgets.QApplication.processEvents()
        if self.dlens == 0:
            source, content = report_doc.doc2html()
            print(f"output: {source}")
            # 单目
            self.pwm.pTestStackWidget.setCurrentIndex(2)
            self.pwm.w24_ret.final_log.show_result_html(source)
            return

        if host == "192.168.1.100":
            report_doc.add_compose_file(report_doc.get_report_file_path())
            report_doc.reset_flag()
            # 双目，切换至第二个摄像头测试
            self.pwm.pTestStackWidget.setCurrentIndex(0)
            self.pwm.w21_dat.pDevHostEdit.setText("192.168.1.101")
            self.pwm.w21_dat.start_autotest_click(0)
        else:
            report_doc.add_compose_file(report_doc.get_report_file_path())
            files = report_doc.get_compose_files()
            print(files)
            report_doc.compose_doc(files)
            source, content = report_doc.doc2html()
            print(f"output: {source}")
            report_doc.clear_compose_file()
            # 切换至结果页并显示报告
            self.pwm.pTestStackWidget.setCurrentIndex(2)
            self.pwm.w24_ret.final_log.show_result_html(source)

    # 请求设备信息-序列号sn
    def device_info(self):
        print('device_config')
        webc = self.http_client_handle()
        QtWidgets.QApplication.processEvents()
        return get_device_info(webc)
