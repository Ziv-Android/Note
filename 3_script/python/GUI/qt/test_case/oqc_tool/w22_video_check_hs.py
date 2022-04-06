#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import ctypes
import re
import socket
import struct
import threading
from ctypes import create_string_buffer
import telnetlib
import time
import os
import _thread
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt, QThread, pyqtSignal, QTimer
from PyQt5.QtGui import QColor
from PyQt5.QtWidgets import QApplication

from oqc_tool import *
from c_heart_beat import *
from oqc_tool.cfg_factory_param_hs import *
from oqc_tool.cfg_device_info import *
from oqc_tool.ui_w22_video_check_hs import Ui_W22VideoCheck
from oqc_tool.ui_w2241_video_ptz_dialog import Ui_ptz_Dialog
from oqc_tool.ui_w2242_video_lens_dialog import Ui_lens_Dialog
#
from oqc_tool.w221_video_ircut import W221VideoIRCUT
from oqc_tool.w222_video_led import W222VideoLed
from oqc_tool.w223_video_lens import W223VideoLens
from oqc_tool.w224_video_ptz import W224VideoPTZ

from libutils.wordreport import *


class LensDialog(QtWidgets.QDialog, Ui_lens_Dialog):
    name = "镜头测试"
    child_window_signal_time = pyqtSignal(str, int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    child_window_signal_pic = pyqtSignal(str, str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串

    def __init__(self, pwm):
        super().__init__()
        self.setWindowFlags(Qt.WindowMinMaxButtonsHint | Qt.WindowCloseButtonHint | Qt.WindowContextHelpButtonHint | Qt.WindowStaysOnTopHint)
        self.setupUi(self)
        self.pwm = pwm
        self.progress = 0
        self.progress_total = 0
        self.dialog_state = "init"
        self.my_qtimer = None
        self.test_result = ""

        self.pushButton_pass.setEnabled(False)
        self.pushButton_pass.clicked.connect(self.passTest)
        self.pushButton_failed.clicked.connect(self.failedTest)

        self.child_window_signal_time.connect(self.timeGo)
        self.child_window_signal_pic.connect(self.showResult)

    def showResult(self, direction, path_img):
        if self.dialog_state != "testing":
            return
        if direction == "镜头复位":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_lens_reset_pic.width(), self.label_lens_reset_pic.height())
            self.label_lens_reset_pic.setPixmap(jpg)
        elif direction == "镜头最小焦1":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_lens_min_1_pic.width(), self.label_lens_min_1_pic.height())
            self.label_lens_min_1_pic.setPixmap(jpg)
        elif direction == "镜头最大焦":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_lens_max_pic.width(), self.label_lens_max_pic.height())
            self.label_lens_max_pic.setPixmap(jpg)
        elif direction == "镜头最小焦2":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_lens_min_2_pic.width(), self.label_lens_min_2_pic.height())
            self.label_lens_min_2_pic.setPixmap(jpg)

    def timeGo(self, tt, time):
        if time >= 0:
            self.stop_qtimer()
            self.dialog_state = "testing"
            self.label_step.setText(f"正在测试：{tt}")
            self.progress_total = time
            print("timeGo:", tt, self.progress_total)
            self.progressBar.setVisible(True)
            self.progressBar.setRange(0, self.progress_total)
            self.progressBar.setValue(0)
            if time != 0:
                self.my_qtimer = QtCore.QTimer(self)
                self.my_qtimer.timeout.connect(self.timer_timeout)
                self.my_qtimer.start(1000)
        else:
            self.dialog_state = "test-end"
            self.progressBar.setVisible(False)
            self.label_step.setText(f"{self.name}完成，请确认测试结果")
            self.pushButton_pass.setEnabled(True)

    def timer_timeout(self):
        self.progress += 1
        if self.progress >= self.progress_total:
            self.stop_qtimer()
            self.progress = 0

        self.update_ui()

    def update_ui(self):
        self.progressBar.setValue(self.progress)

    def stop_qtimer(self):
        if self.my_qtimer is not None:
            self.my_qtimer.stop()
            self.my_qtimer = None

    def reset_ui(self):
        self.label_lens_reset_pic.clear()
        self.label_lens_min_1_pic.clear()
        self.label_lens_max_pic.clear()
        self.label_lens_min_2_pic.clear()

        self.progress = 0
        self.progress_total = 0
        self.test_result = ""
        self.pushButton_pass.setEnabled(False)

    def closeEvent(self, a0: QtGui.QCloseEvent):
        self.dialog_state = "close"
        if self.test_result == "pass":
            code_close = 0
        else:
            code_close = 1
        self.pwm.report_lens(code_close)
        self.stop_qtimer()
        self.reset_ui()

    def passTest(self):
        self.test_result = "pass"
        self.close()

    def failedTest(self):
        self.test_result = "failed"
        self.close()


class PtzDialog(QtWidgets.QDialog, Ui_ptz_Dialog):
    name = "云台测试"
    child_window_signal_time = pyqtSignal(str, int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    child_window_signal_pic = pyqtSignal(str, str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串

    def __init__(self, pwm):
        super().__init__()
        self.setWindowFlags(Qt.WindowMinMaxButtonsHint | Qt.WindowCloseButtonHint | Qt.WindowContextHelpButtonHint | Qt.WindowStaysOnTopHint)
        self.setupUi(self)
        self.pwm = pwm
        self.progress = 0
        self.progress_total = 0
        self.dialog_state = "init"
        self.my_qtimer = None
        self.test_result = ""

        self.pushButton_pass.setEnabled(False)
        self.pushButton_pass.clicked.connect(self.passTest)
        self.pushButton_failed.clicked.connect(self.failedTest)

        self.child_window_signal_time.connect(self.timeGo)
        self.child_window_signal_pic.connect(self.showResult)

    def showResult(self, direction, path_img):
        if self.dialog_state != "testing":
            return
        if direction == "云台复位1":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_reset_1_pic.width(), self.label_ptz_reset_1_pic.height())
            self.label_ptz_reset_1_pic.setPixmap(jpg)
        elif direction == "云台-上":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_up_pic.width(), self.label_ptz_up_pic.height())
            self.label_ptz_up_pic.setPixmap(jpg)
        elif direction == "云台-下":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_down_pic.width(), self.label_ptz_down_pic.height())
            self.label_ptz_down_pic.setPixmap(jpg)
        elif direction == "云台复位2":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_reset_2_pic.width(), self.label_ptz_reset_2_pic.height())
            self.label_ptz_reset_2_pic.setPixmap(jpg)
        elif direction == "云台-左":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_left_pic.width(), self.label_ptz_left_pic.height())
            self.label_ptz_left_pic.setPixmap(jpg)
        elif direction == "云台-右":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_right_pic.width(), self.label_ptz_right_pic.height())
            self.label_ptz_right_pic.setPixmap(jpg)
        elif direction == "云台复位3":
            jpg = QtGui.QPixmap(path_img).scaled(self.label_ptz_reset_3_pic.width(), self.label_ptz_reset_3_pic.height())
            self.label_ptz_reset_3_pic.setPixmap(jpg)

    def timeGo(self, tt, time):
        if time >= 0:
            self.stop_qtimer()
            self.dialog_state = "testing"
            self.label_step.setText(f"正在测试：{tt}")
            self.progress_total = time
            self.progressBar.setVisible(True)
            self.progressBar.setRange(0, self.progress_total)
            self.progressBar.setValue(0)
            self.my_qtimer = QtCore.QTimer(self)
            self.my_qtimer.timeout.connect(self.timer_timeout)
            self.my_qtimer.start(1000)
        else:
            self.dialog_state = "test-end"
            self.progressBar.setVisible(False)
            self.label_step.setText(f"{self.name}完成，请确认测试结果")
            self.pushButton_pass.setEnabled(True)

    def timer_timeout(self):
        self.progress += 1
        if self.progress >= self.progress_total:
            self.stop_qtimer()
            self.progress = 0

        self.update_ui()

    def update_ui(self):
        self.progressBar.setValue(self.progress)

    def stop_qtimer(self):
        if self.my_qtimer is not None:
            self.my_qtimer.stop()
            self.my_qtimer = None

    def reset_ui(self):
        self.label_ptz_reset_1_pic.clear()
        self.label_ptz_reset_2_pic.clear()
        self.label_ptz_reset_3_pic.clear()
        self.label_ptz_up_pic.clear()
        self.label_ptz_down_pic.clear()
        self.label_ptz_left_pic.clear()
        self.label_ptz_right_pic.clear()

        self.progress = 0
        self.progress_total = 0
        self.test_result = ""
        self.pushButton_pass.setEnabled(False)

    def closeEvent(self, a0: QtGui.QCloseEvent):
        self.dialog_state = "close"
        if self.test_result == "pass":
            code_close = 0
        else:
            code_close = 1
        self.pwm.report_ptz(code_close)
        self.timer_timeout()
        self.reset_ui()

    def passTest(self):
        self.test_result = "pass"
        self.close()

    def failedTest(self):
        self.test_result = "failed"
        self.close()


class W22VideoCheck(QtWidgets.QWidget, Ui_W22VideoCheck):
    name = 'video'
    fail_test_signal = pyqtSignal()  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    control_ptz_dialog_signal = pyqtSignal(int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    control_lens_dialog_signal = pyqtSignal(int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    stop_click_signal = pyqtSignal(int)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    auto_test_signal = pyqtSignal(str, str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    auto_test_finish_signal = pyqtSignal(str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串

    # config:需要测试的内容; hs=high side
    def __init__(self, pwm, config="hs_lens_ircut_ptz"):
        super().__init__()
        self.setupUi(self)
        self.is_485_pass = -1
        self.is_ptz_ok = -1
        self.is_lens_ok = -1

        self.pwm = pwm
        self.sdk_hdl = 0
        self.vdo_hdl = 0
        self.autotest_state = 0  # 0=未开始,1=开始,5=停止,8=完成
        self.params = None
        self.fail_dialog_is_showing = False

        self.usercase = {}
        self.config = config
        self.auto_test_signal.connect(self.test_case_update_state)
        self.fail_test_signal.connect(self.show_fail_dialog)
        self.auto_test_finish_signal.connect(self.test_case_finish_state)
        self.stop_click_signal.connect(self.stop_test_click)

        self.vdo_ircut = W221VideoIRCUT(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ircut)

        self.vdo_led = W222VideoLed(self)
        self.pTestCaseVLayout.addWidget(self.vdo_led)

        self.vdo_lens = W223VideoLens(self)
        self.pTestCaseVLayout.addWidget(self.vdo_lens)

        self.vdo_ptz = W224VideoPTZ(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ptz)

        self.pTestCaseLWdg.itemDoubleClicked.connect(self.testcase_item_doubleclick)

        self.ptz_test_dialog = PtzDialog(self)
        self.control_ptz_dialog_signal.connect(self.show_ptz_test_dialog)

        self.lens_test_dialog = LensDialog(self)
        self.control_lens_dialog_signal.connect(self.show_lens_test_dialog)

    #
    def close_sdk_hdl(self):
        print('close_sdk_hdl')
        if self.sdk_hdl != 0:
            print("objdll.VzLPRClient_StopRealPlay %d vdo_hdl %d" % (self.sdk_hdl, self.vdo_hdl))
            if self.vdo_hdl:
                objdll.VzLPRClient_StopRealPlay(self.vdo_hdl)
                self.vdo_hdl = 0
            objdll.VzLPRClient_Close(self.sdk_hdl)
            self.pShowVideoLabel.clear()
            self.sdk_hdl = 0

    def set_login_state(self, state=False):
        self.vdo_ircut.set_login_state(state)
        self.vdo_led.set_login_state(state)
        self.vdo_lens.set_login_state(state)
        self.vdo_ptz.set_login_state(state)

    #
    def show_video(self, host, username, password):
        print('set_dev_host entry %s %s %s' % (host, username, password))

        try:
            self.close_sdk_hdl()
            sn = self.device_info()
            if not self.isLegalSn(sn):
                self.set_login_state()
                return False
            self.sdk_hdl = objdll.VzLPRClient_Open(host.encode('utf-8'), 80,
                                                   username.encode('utf-8'),
                                                   password.encode('utf-8'))
            print("objdll.VzLPRClient_OpenV3 %d" % self.sdk_hdl)
            time.sleep(2)
            QApplication.processEvents()
            if self.sdk_hdl == 0:
                self.sdk_hdl = objdll.VzLPRClient_Open(host.encode('utf-8'), 80,
                                                       username.encode('utf-8'),
                                                       password.encode('utf-8'))
                print("retry open objdll.VzLPRClient_OpenV3 %d" % self.sdk_hdl)

            if self.sdk_hdl == 0:
                self.set_login_state()
                return False
            self.vdo_hdl = objdll.VzLPRClient_StartRealPlay(self.sdk_hdl, int(self.pShowVideoLabel.winId()))
            print("objdll.VzLPRClient_StartRealPlay %d vdo_hdl %d" % (self.sdk_hdl, self.vdo_hdl))
            for i in range(4):
                time.sleep(5)
                QApplication.processEvents()
                if self.vdo_hdl == -1:
                    self.vdo_hdl = objdll.VzLPRClient_StartRealPlay(self.sdk_hdl, int(self.pShowVideoLabel.winId()))
                    print("retry open objdll.VzLPRClient_StartRealPlay %d vdo_hdl %d" % (self.sdk_hdl, self.vdo_hdl))
                else:
                    break
            self.set_login_state(True)
            return True
        except:
            print("can't show video")
            self.set_login_state()
            return False

    def http_client_handle(self):
        return self.pwm.http_client_handle()

    # 自动测试
    def widget_init(self):
        self.pTestCaseLWdg.clear()
        self.testcase = [
            '网卡检测',
            '镜头配置',
            '定制协议',
            '云台测试',
            '镜头测试',
            'IRCUT夜间',
            'IRCUT白天',
        ]
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)

    def testcase_item_doubleclick(self, item):
        if isinstance(item, str):
            tt = item
        else:
            tt = item.text()
        doubleclick_thread = threading.Thread(target=self.testcase_item_doubleclick_run, args=(tt, ))
        doubleclick_thread.start()

    def testcase_item_doubleclick_run(self, tt):
        if tt not in self.testcase:
            return
        ret = False
        self.autotest_state = 1
        self.auto_test_signal.emit(tt, '开始')
        if tt == '镜头配置':
            cp, pro = self.pwm.get_product()
            host = self.pwm.w21_dat.pDevHostEdit.text()
            ret = self.lens_config(cp, host)
        elif tt == '定制协议':
            ret = self.protocol_config()
        elif tt == '网卡检测':
            cp, pro = self.pwm.get_product()
            host = self.pwm.w21_dat.pDevHostEdit.text()
            ret = self.check_net_type(cp, host)
        elif tt == '镜头复位':
            ret = self.vdo_lens.lens_reset()
        elif tt == '镜头最小焦1' or tt == '镜头最小焦2':
            ret = self.vdo_lens.lens_zoom_out()
            time.sleep(40)
            ret = self.vdo_lens.lens_zoom_out()
            self.vdo_lens.lens_auto_focus()
        elif tt == '镜头最大焦':
            ret = self.vdo_lens.lens_zoom_in()
            time.sleep(40)
            ret = self.vdo_lens.lens_zoom_in()
            self.vdo_lens.lens_auto_focus()
        elif tt == '云台测试':
            ret = self.autotest_usercase_traversal_ptz()
            if ret is False:
                self.control_ptz_dialog_signal.emit(0)
        elif tt == '镜头测试':
            ret = self.autotest_usercase_traversal_lens()
            if ret is False:
                self.control_lens_dialog_signal.emit(0)
        elif tt == '云台复位1' or tt == '云台复位2' or tt == '云台复位3':
            self.show_ptz_test_signal.emit()
            ret = self.autotest_step(tt, self.ptz_reset, self.record_doc_params, self.ptz_test_dialog, True, 15)
        elif tt == '云台-上':
            self.show_ptz_test_signal.emit()
            ret = self.vdo_ptz.ptz_up()
            self.ptz_test_dialog.child_window_signal_time.emit(tt, 8)
            time.sleep(8)
            ret = self.vdo_ptz.ptz_up()
            path = self.save_pic_in_path()
            self.ptz_test_dialog.child_window_signal_result.emit(tt, path)
        elif tt == '云台-下':
            self.show_ptz_test_signal.emit()
            ret = self.vdo_ptz.ptz_down()
            self.ptz_test_dialog.child_window_signal_time.emit(tt, 8)
            time.sleep(8)
            ret = self.vdo_ptz.ptz_down()
            path = self.save_pic_in_path()
            self.ptz_test_dialog.child_window_signal_result.emit(tt, path)
        elif tt == '云台-左':
            self.show_ptz_test_signal.emit()
            ret = self.vdo_ptz.ptz_left()
            self.ptz_test_dialog.child_window_signal_time.emit(tt, 8)
            time.sleep(8)
            ret = self.vdo_ptz.ptz_left()
            path = self.save_pic_in_path()
            self.ptz_test_dialog.child_window_signal_result.emit(tt, path)
        elif tt == '云台-右':
            self.show_ptz_test_signal.emit()
            ret = self.vdo_ptz.ptz_right()
            self.ptz_test_dialog.child_window_signal_time.emit(tt, 8)
            time.sleep(8)
            ret = self.vdo_ptz.ptz_right()
            path = self.save_pic_in_path()
            self.ptz_test_dialog.child_window_signal_result.emit(tt, path)

        if ret:
            self.auto_test_signal.emit(tt, '成功')
        else:
            self.auto_test_signal.emit(tt, '失败')

    def show_ptz_test_dialog(self, key):
        if key == 1:
            if not self.ptz_test_dialog.isVisible():
                self.ptz_test_dialog.show()
                self.ptz_test_dialog.exec_()
        elif key == 0:
            if self.ptz_test_dialog is not None:
                self.ptz_test_dialog.failedTest()

    def show_lens_test_dialog(self, key):
        if key == 1:
            if not self.lens_test_dialog.isVisible():
                self.lens_test_dialog.show()
                self.lens_test_dialog.exec_()
        elif key == 0:
            if self.lens_test_dialog is not None:
                self.lens_test_dialog.failedTest()

    # 请求设备信息-序列号sn
    def device_info(self):
        print('device_config')
        webc = self.http_client_handle()
        QApplication.processEvents()
        sn, soft_ver = get_device_info(webc)
        self.pwm.set_soft_ver(soft_ver)
        return sn

    # 产品
    # 定制协议
    def protocol_config(self):
        print('protocol_config')
        cc, cus = self.pwm.get_customer()
        pname = cc.get_conf_pname(cus)
        if pname == '':
            print("don't need set protocol")
            return True
        webc = self.http_client_handle()
        QApplication.processEvents()
        return cfg_factory_param_customer(webc,
                                          cc.get_conf_pname(cus),
                                          cc.get_conf_library(cus))

    # 镜头
    # 镜头配置
    def lens_config(self, cp, host):
        print("lens_config:", host)
        print(cp.get_desc())
        dlens = cp.get_capacity_num('dlens')
        if dlens == 1:
            return True
        webc = self.http_client_handle()
        num_max_stop = cp.get_capacity_num('num_max_stop')
        QApplication.processEvents()
        return cfg_factory_param_product(webc,
                                         num_max_stop,
                                         cp.get_capacity_num('lens'),
                                         cp.get_capacity_num('dlens'))

    def autotest_stop(self, i=-1):
        time.sleep(0.5)
        print('video autotest_stop')
        self.autotest_state = 5
        self.pwm.w21_dat.pAutotestButton.setText("开始测试(F8)")
        if i == -1:
            self.pwm.w21_dat.pAutotestButton.setEnabled(True)
            self.fail_test_signal.emit()

    def autotest_reset(self):
        print('video autotest_reset')
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

        print('video start_autotest %s %s %s' % (host, username, password))
        if self.autotest_state == 1:
            print('has been in the test')
            self.pwm.w21_dat.pAutotestButton.setEnabled(False)
            self.autotest_stop(0)
            return

        self.autotest_state = 1
        try:
            self.show_video(host, username, password)
            _thread.start_new_thread(self.autotest_usercase_traversal,
                                     ("autotest", host, username, password, i))
            QApplication.processEvents()
        except:
            print("can't start thread")

    def show_fail_dialog(self):
        if self.fail_dialog_is_showing:
            return
        self.fail_dialog_is_showing = True
        ret = QtWidgets.QMessageBox.warning(self, "失败", "测试未通过")
        print("show_fail_dialog", ret)
        if ret == QtWidgets.QMessageBox.Ok:
            self.is_ptz_ok = -1
            self.is_lens_ok = -1
            self.fail_dialog_is_showing = False

    # 更新QListWidget item显示
    def test_case_update_state(self, text, suc):
        print("test_case_update_state", text, suc, self.autotest_state)
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

    def stop_test_click(self):
        self.pwm.w21_dat.pAutotestButton.setEnabled(True)

    def tcp_send_base(self, client, cmd_data):
        cmd_data = cmd_data.encode()
        cmd_len = len(cmd_data)
        # init all \x00
        buf = create_string_buffer(cmd_len)
        struct.pack_into(">" + str(cmd_len) + "s", buf, 0, cmd_data)
        try:
            print("[TCP send]:", cmd_data)
            client.sendall(buf)
            QApplication.processEvents()
        except socket.error as e:
            print("TCP send exception", e)

    def tcp_connect(self, host, port=23):
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            print("get_net_type connect:", host, str(port))
            client.connect((host, port))
            QApplication.processEvents()
        except Exception as e:
            print("get_net_type connect except", host, str(port), e)
            if client is None:
                return False
            client.close()
            client = None

        return client

    def tcp_send_cmd(self, client, cmd):
        if client is None:
            return None
        try:
            msg_length = 128
            self.send_base(client, f"{cmd}\n")
            data = client.recv(msg_length)
            print("get_net_type root:", data)
            return data
        except Exception as e:
            print("get_net_type send msg except", e)
        finally:
            client.close()

        return None

    def compare_tcp_result(self, data, cp, keyword):
        return data == cp.get_capacity_num(keyword)

    def check_net_type(self, cp, host, port=23, finish=b'~ # '):
        try:
            config_net_type = cp.get_capacity_num('net_type')
            print('config eth:', config_net_type)
            result = False
            with telnetlib.Telnet(host=host, port=port, timeout=10) as tn:
                QApplication.processEvents()
                tn.set_debuglevel(2)
                tn.read_until(b'login:')
                tn.write('root\n'.encode())
                tn.read_until(b'Password:')
                tn.write('108balance\n'.encode())
                tn.read_until(finish)
                tn.write('cat /sys/class/net/eth0/speed\n'.encode())
                time.sleep(1)
                data = tn.read_very_eager().decode()
                print('recv eth0:', data)
                if data is not None and len(data) > 0:
                    lines = data.split("\r\n")
                    for _item in lines:
                        if _item == str(config_net_type):
                            result = True
                            break

                    print('recv eth0:', result)

                if result is False:
                    tn.write('cat /sys/class/net/eth1/speed\n'.encode())
                    time.sleep(1)
                    data = tn.read_very_eager().decode()
                    print('recv eth1:', data)
                    if data is not None and len(data) > 0:
                        lines = data.split("\r\n")
                        print(lines)
                        for _item in lines:
                            if _item == str(config_net_type):
                                result = True
                                break

                        print('recv eth1:', result)

                tn.write(b"exit\n")
        except Exception as e:
            print(e)

        print("check_net_type result:", result)
        return result

    def autotest_step(self, test_step, test_func, test_report, test_window=None, should_continue=0, sava_pic=False, delay_time=0, *arg):
        if self.autotest_state == 5 or should_continue > 0:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(test_step, '开始')
        time.sleep(0.2)

        if delay_time >= 0 and test_window is not None:
            test_window.child_window_signal_time.emit(test_step, delay_time)
        ret = test_func(delay_time, *arg)
        if ret is False:
            test_report(test_step, '失败')
            self.auto_test_signal.emit(test_step, '失败')
            # self.autotest_stop(0)
            return False

        if sava_pic:
            path_pic = self.save_pic_in_path()
            if test_window is not None:
                time.sleep(0.1)
                test_window.child_window_signal_pic.emit(test_step, path_pic)
            test_report(test_step, path_pic)
        else:
            test_report(test_step, '成功')
        self.auto_test_signal.emit(test_step, '成功')
        return True

    def record_doc_params(self, test_step, result):
        if self.params is not None:
            self.params[test_step] = result

    def ptz_reset(self, delay_time, *arg):
        ret = self.vdo_ptz.ptz_reset()
        if ret == 404 or ret is False:
            return False
        time.sleep(delay_time)
        return True

    def ptz_up(self, delay_time, *arg):
        ret = self.vdo_ptz.ptz_up()
        if ret == 404 or ret is False:
            return False
        time.sleep(delay_time)
        ret = self.vdo_ptz.ptz_up()
        if ret == 404 or ret is False:
            return False
        return True

    def ptz_down(self, delay_time, *arg):
        ret = self.vdo_ptz.ptz_down()
        if ret == 404 or ret is False:
            return False
        time.sleep(delay_time)
        ret = self.vdo_ptz.ptz_down()
        if ret == 404 or ret is False:
            return False
        return True

    def ptz_left(self, delay_time, *arg):
        ret = self.vdo_ptz.ptz_left()
        if ret == 404 or ret is False:
            return False
        time.sleep(delay_time)
        ret = self.vdo_ptz.ptz_left()
        if ret == 404 or ret is False:
            return False
        return True

    def ptz_right(self, delay_time, *arg):
        ret = self.vdo_ptz.ptz_right()
        if ret == 404 or ret is False:
            return False
        time.sleep(delay_time)
        ret = self.vdo_ptz.ptz_right()
        if ret == 404 or ret is False:
            return False
        return True

    # 自动 - 云台
    def autotest_usercase_traversal_ptz(self):
        self.control_ptz_dialog_signal.emit(1)
        # '云台复位1'
        ret = self.autotest_step('云台复位1', self.ptz_reset, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 16)
        if not ret:
            return False

        # '云台-上'
        ret = self.autotest_step('云台-上', self.ptz_up, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 8)
        if not ret:
            return False

        # '云台-下'
        ret = self.autotest_step('云台-下', self.ptz_down, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 12)
        if not ret:
            return False

        # '云台复位2'
        ret = self.autotest_step('云台复位2', self.ptz_reset, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 16)
        if not ret:
            return False

        # '云台-左'
        ret = self.autotest_step('云台-左', self.ptz_left, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 4)
        if not ret:
            return False

        # '云台-右'
        ret = self.autotest_step('云台-右', self.ptz_right, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 6)
        if not ret:
            return False

        # '云台复位3'
        ret = self.autotest_step('云台复位3', self.ptz_reset, self.record_doc_params, self.ptz_test_dialog, self.is_ptz_ok, True, 16)
        if not ret:
            return False

        self.ptz_test_dialog.child_window_signal_time.emit("", -1)
        return True

    def report_ptz(self, code_close):
        if code_close != 0:
            self.pwm.w21_dat.pAutotestButton.setEnabled(False)
        self.is_ptz_ok = code_close
        print("云台测试", self.is_ptz_ok)

    def lens_reset(self, delay_time=0, *arg):
        time_focus = 12
        ret = self.vdo_lens.lens_reset()
        time.sleep(2)
        if ret == 404 or ret is False:
            return False
        else:
            time.sleep(3)
            ret = False
            for time_index in range(20):
                time.sleep(2)
                ret = self.vdo_lens.lens_get_reset_status()
                if ret:
                    time.sleep(0.2)
                    self.vdo_lens.lens_auto_focus()
                    time.sleep(time_focus)
                    break

            return ret

    def lens_zoom_out(self, delay_time, *arg):
        time_focus = 12
        time_re_zoom_out = 5
        for _time in range(time_re_zoom_out):
            ret = self.vdo_lens.lens_zoom_out()
            if ret != 200:
                return False
            time.sleep(0.5)
        ret = self.vdo_lens.lens_zoom_out()
        if ret != 200:
            return False
        time.sleep(delay_time - time_focus - time_re_zoom_out)
        ret = self.vdo_lens.lens_zoom_out_stop()
        if ret != 200:
            return False
        time.sleep(0.2)
        ret = self.vdo_lens.lens_auto_focus()
        if ret != 200:
            return False
        time.sleep(time_focus)

    def lens_zoom_in(self, delay_time, *arg):
        time_focus = 12
        time_re_zoom_in = 5
        for _time in range(time_re_zoom_in):
            ret = self.vdo_lens.lens_zoom_in()
            if ret != 200:
                return False
            time.sleep(0.5)
        ret = self.vdo_lens.lens_zoom_in()
        if ret != 200:
            return False
        time.sleep(delay_time - time_focus - time_re_zoom_in)
        ret = self.vdo_lens.lens_zoom_in_stop()
        if ret != 200:
            return False
        time.sleep(0.2)
        ret = self.vdo_lens.lens_auto_focus()
        if ret != 200:
            return False
        time.sleep(time_focus)

    # 自动 - 镜头
    def autotest_usercase_traversal_lens(self):
        self.control_lens_dialog_signal.emit(1)
        # '镜头复位'
        ret = self.autotest_step('镜头复位', self.lens_reset, self.record_doc_params, self.lens_test_dialog, self.is_lens_ok, True, 0)
        if not ret:
            return False

        # '镜头最小焦1'
        ret = self.autotest_step('镜头最小焦1', self.lens_zoom_out, self.record_doc_params, self.lens_test_dialog, self.is_lens_ok, True, 35)
        if not ret:
            return False

        # '镜头最大焦'
        ret = self.autotest_step('镜头最大焦', self.lens_zoom_in, self.record_doc_params, self.lens_test_dialog, self.is_lens_ok, True, 35)
        if not ret:
            return False

        # '镜头最小焦2'
        ret = self.autotest_step('镜头最小焦2', self.lens_zoom_out, self.record_doc_params, self.lens_test_dialog, self.is_lens_ok, True, 35)
        if not ret:
            return False

        self.lens_test_dialog.child_window_signal_time.emit("", -1)
        return True

    def report_lens(self, code_close):
        if code_close != 0:
            self.pwm.w21_dat.pAutotestButton.setEnabled(False)
        self.is_lens_ok = code_close
        print("镜头测试", self.is_lens_ok)

    # 自动
    def autotest_usercase_traversal(self, tname, host, username, password, i):
        print("video autotest_usercase_traversal %s %s %s %s " % (tname, host, username, password), i)
        count = self.pTestCaseLWdg.count()
        if count <= 0:
            return False

        if i == 0:
            if self.pwm.w21_dat.is_search:
                self.pwm.w21_dat.search_device()
            print("video autotest_usercase_traversal i=", i)
            report_doc.report_start(time.time())
            report_doc.report_sn(self.device_info())
        self.params = report_doc.get_empty_params()

        cp, pro = self.pwm.get_product()

        # '网卡检测'
        i = 0
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.check_net_type(cp, host)
        if ret is False:
            self.params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        self.params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '镜头配置'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.lens_config(cp, host)
        if ret == 404 or ret is False:
            self.params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        self.params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '定制协议'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.protocol_config()
        if ret == 404 or ret is False:
            self.params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        self.params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '云台测试'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.is_ptz_ok = -1
        ret = self.autotest_usercase_traversal_ptz()
        if ret is False:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.control_ptz_dialog_signal.emit(0)
            self.autotest_stop()
            return False

        while self.is_ptz_ok < 0:
            time.sleep(3)
        if self.is_ptz_ok == 0:
            self.auto_test_signal.emit(self.testcase[i], '成功')
        else:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False

        # '镜头测试'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.is_lens_ok = -1
        ret = self.autotest_usercase_traversal_lens()
        if ret is False:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.control_lens_dialog_signal.emit(0)
            self.autotest_stop()
            return False

        while self.is_lens_ok < 0:
            time.sleep(3)
        if self.is_lens_ok == 0:
            self.auto_test_signal.emit(self.testcase[i], '成功')
        else:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False

        # 'IRCUT夜间'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ircut.ircut_night()
        time.sleep(1)
        if ret == 404 or ret is False:
            self.params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        self.params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IRCUT白天'
        i = i + 1
        if self.autotest_state == 5:
            self.stop_click_signal.emit(self.autotest_state)
            return False
        c_heart(self.http_client_handle())
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ircut.ircut_day()
        time.sleep(1)
        if ret == 404 or ret is False:
            self.params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        self.params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        report_doc.report_video(self.params)

        time.sleep(0.5)
        self.auto_test_finish_signal.emit("video finish")

    def test_case_finish_state(self, result):
        print(f"all test case finish {result}, switch -> {self.pwm.w23_ext.name}")
        self.autotest_reset()
        self.pwm.pTestStackWidget.setCurrentIndex(1)
        self.pwm.w21_dat.start_autotest_click(1)
        report_doc.delete_pic()

    def save_pic_in_path(self, count=3):
        try:
            _pic_path = os.path.join(os.getcwd(), "doc", "pic")
            if not os.path.exists(_pic_path):
                os.makedirs(_pic_path)
            filename = time.strftime("%Y-%m-%d-%H-%M-%S", time.localtime((time.time()))) + ".jpg"
            path = os.path.join(_pic_path, filename)
            for i in range(count):
                result = objdll.VzLPRClient_SaveSnapImageToJpeg(self.sdk_hdl, path.encode('gb2312'))
                print('save_pic_in_path', path, result)
                if result != 0:
                    continue
                else:
                    return path
            return "图片获取失败"
        except Exception as e:
            return "图片获取异常"

    def isLegalSn(self, sn):
        result = re.match(r"^[0-9a-fA-F]{8}-[0-9a-fA-F]{8}", sn) is not None
        print("isLegalSn", sn, result)
        return result
