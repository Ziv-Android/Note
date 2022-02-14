#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import ctypes
import re
import time
import os
import _thread
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt, QThread, pyqtSignal
from PyQt5.QtWidgets import QApplication

from oqc_tool import *
from oqc_tool.cfg_factory_param_hs import *
from oqc_tool.cfg_device_info import *
from oqc_tool.ui_w22_video_check_hs import Ui_W22VideoCheck

#
from oqc_tool.w221_video_ircut import W221VideoIRCUT
from oqc_tool.w222_video_led import W222VideoLed
from oqc_tool.w223_video_lens import W223VideoLens
from oqc_tool.w224_video_ptz import W224VideoPTZ

from libutils.wordreport import *


class W22VideoCheck(QtWidgets.QWidget, Ui_W22VideoCheck):
    name = 'video'
    fail_test_signal = pyqtSignal()  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    auto_test_signal = pyqtSignal(str, str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串
    auto_test_finish_signal = pyqtSignal(str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串

    # config:需要测试的内容; hs=high side
    def __init__(self, pwm, config="hs_lens_ircut_ptz"):
        super().__init__()
        self.setupUi(self)
        self.is_485_pass = -1

        self.pwm = pwm
        self.sdk_hdl = 0
        self.vdo_hdl = 0
        self.autotest_state = 0  # 0=未开始,1=开始,5=停止,8=完成

        self.usercase = {}
        self.config = config
        self.auto_test_signal.connect(self.test_case_update_state)
        self.fail_test_signal.connect(self.show_fail_dialog)
        self.auto_test_finish_signal.connect(self.test_case_finish_state)

        self.vdo_ircut = W221VideoIRCUT(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ircut)

        self.vdo_led = W222VideoLed(self)
        self.pTestCaseVLayout.addWidget(self.vdo_led)

        self.vdo_lens = W223VideoLens(self)
        self.pTestCaseVLayout.addWidget(self.vdo_lens)

        self.vdo_ptz = W224VideoPTZ(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ptz)

        self.pTestCaseLWdg.itemDoubleClicked.connect(self.testcase_item_doubleclick)

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
            QtWidgets.QApplication.processEvents()
            if self.sdk_hdl == 0:
                self.sdk_hdl = objdll.VzLPRClient_Open(host.encode('utf-8'), 80,
                                                       username.encode('utf-8'),
                                                       password.encode('utf-8'))
                print("retry open objdll.VzLPRClient_OpenV3 %d" % self.sdk_hdl)
            time.sleep(2)
            QtWidgets.QApplication.processEvents()
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
            '镜头配置',
            '定制协议',
            '云台复位1',
            '镜头复位',
            '镜头最小焦1',
            '镜头最大焦',
            'IRCUT夜间',
            'IRCUT白天',
            '云台-上',
            '云台-下',
            '云台复位2',
            '云台-左',
            '云台-右',
            '云台复位3',
            '镜头最小焦2',
            '补光灯'
        ]
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)

    def testcase_item_doubleclick(self, item):
        tt = item.text()
        if tt == '镜头配置':
            self.lens_config()
        elif tt == '定制协议':
            self.protocol_config()

    # 请求设备信息-序列号sn
    def device_info(self):
        print('device_config')
        webc = self.http_client_handle()
        QtWidgets.QApplication.processEvents()
        return get_device_info(webc)

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
        QtWidgets.QApplication.processEvents()
        return cfg_factory_param_customer(webc,
                                          cc.get_conf_pname(cus),
                                          cc.get_conf_library(cus))

    # 镜头
    # 镜头配置
    def lens_config(self):
        print("lens_config")
        cp, pro = self.pwm.get_product()
        print(cp.get_desc())
        webc = self.http_client_handle()
        QtWidgets.QApplication.processEvents()
        return cfg_factory_param_product(webc,
                                         cp.get_capacity_num('lens'),
                                         cp.get_capacity_num('dlens'))

    def autotest_stop(self, i=-1):
        print('video autotest_stop')
        self.autotest_state = 5
        self.pwm.w21_dat.pAutotestButton.setText("开始测试(F8)")
        if i == -1:
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
            self.autotest_stop(0)
            return

        self.autotest_state = 1
        try:
            self.show_video(host, username, password)
            QApplication.processEvents()
            _thread.start_new_thread(self.autotest_usercase_traversal,
                                     ("autotest", host, username, password, i))
        except:
            print("can't start thread")

    def show_fail_dialog(self):
        QtWidgets.QMessageBox.warning(self, "失败", "测试未通过")

    # 更新QListWidget item显示
    def test_case_update_state(self, text, suc):
        print(text, suc)
        count = self.pTestCaseLWdg.count()
        for i in range(count):
            tt = self.pTestCaseLWdg.item(i).text()
            if tt.find(text) != -1:
                self.pTestCaseLWdg.item(i).setText(text + '\t\t' + suc)
                break

    # 自动
    def autotest_usercase_traversal(self, tname, host, username, password, i):
        print("video autotest_usercase_traversal %s %s %s %s " % (tname, host, username, password), i)

        if i == 0:
            if self.pwm.w21_dat.is_search:
                self.pwm.w21_dat.search_device()
            print("video autotest_usercase_traversal i=", i)
            report_doc.report_start(time.time())
            report_doc.report_sn(self.device_info())
        params = report_doc.get_empty_params()

        # '镜头配置'
        i = 0
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.lens_config()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '定制协议'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.protocol_config()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        params[self.testcase[i]] = "成功"
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '云台复位'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ptz.ptz_reset()
        time.sleep(15)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头复位'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_lens.lens_reset()
        time.sleep(2)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
        else:
            time.sleep(3)
            ret = False
            for time_index in range(18):
                time.sleep(2)
                ret = self.vdo_lens.lens_get_reset_status()
                if ret:
                    break
            if ret:
                path = self.save_pic_in_path()
                params[self.testcase[i]] = path
                self.auto_test_signal.emit(self.testcase[i], '成功')
            else:
                params[self.testcase[i]] = "获取镜头复位状态失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')

        # '镜头最小焦'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_lens.lens_zoom_out()
        time.sleep(5)
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_zoom_out()
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_auto_focus()
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(30)
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头最大焦'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_lens.lens_zoom_in()
        time.sleep(3)
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_zoom_in()
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_auto_focus()
        time.sleep(30)
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IRCUT夜间'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ircut.ircut_night()
        time.sleep(1)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IRCUT白天'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ircut.ircut_day()
        time.sleep(1)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-上'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        time.sleep(1)
        ret = self.vdo_ptz.ptz_up()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(8)
        ret = self.vdo_ptz.ptz_up()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-下'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        time.sleep(2)
        ret = self.vdo_ptz.ptz_down()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(16)
        ret = self.vdo_ptz.ptz_down()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台复位1'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ptz.ptz_reset()
        time.sleep(15)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-左'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ptz.ptz_left()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(8)
        ret = self.vdo_ptz.ptz_left()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-右'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ptz.ptz_right()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(16)
        ret = self.vdo_ptz.ptz_right()
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台复位2'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_ptz.ptz_reset()
        time.sleep(15)
        if ret == 404 or ret is False:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头最小焦1'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.vdo_lens.lens_zoom_out()
        time.sleep(5)
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_zoom_out()
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        ret = self.vdo_lens.lens_auto_focus()
        if ret != 200:
            params[self.testcase[i]] = "失败"
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_stop()
            return False
        time.sleep(30)
        path = self.save_pic_in_path()
        params[self.testcase[i]] = path
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '485测试'
        if self.autotest_state == 5:
            return False
        url = 'http://%s' % host
        webc = WEBClient(url, username, password)
        self.auto_test_signal.emit(self.testcase[i], '开始')
        c_rs485_write(webc, 0, '$001,01&')
        time.sleep(1)
        ret, data = c_rs485_read(webc, 0)
        if data == 'OK':
            self.is_485_pass = 1
        else:
            self.is_485_pass = 0

        # '补光灯'
        i = i + 1
        if self.autotest_state == 5:
            return False
        self.auto_test_signal.emit(self.testcase[i], '开始')
        if self.is_485_pass == 1:
            ret = self.vdo_led.led_ctrl(10)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(50)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(100)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            ret = self.vdo_led.led_ctrl(-1)
            time.sleep(1)
            if ret != 200:
                params[self.testcase[i]] = "失败"
                self.auto_test_signal.emit(self.testcase[i], '失败')
                self.autotest_stop()
                return False
            params[self.testcase[i]] = "成功"
            self.auto_test_signal.emit(self.testcase[i], '成功')
        else:
            params[self.testcase[i]] = "跳过"
            self.auto_test_signal.emit(self.testcase[i], '跳过')

        report_doc.report_video(params)

        time.sleep(0.5)
        self.auto_test_finish_signal.emit("video finish")

    def test_case_finish_state(self, result):
        print(f"all test case finish {result}, switch -> {self.pwm.w23_ext.name}")
        self.autotest_reset()
        self.pwm.pTestStackWidget.setCurrentIndex(1)
        self.pwm.w21_dat.start_autotest_click(1)
        report_doc.delete_pic()

    def save_pic_in_path(self, count=0):
        try:
            _pic_path = os.path.join(os.getcwd(), "doc", "pic")
            if not os.path.exists(_pic_path):
                os.makedirs(_pic_path)
            filename = time.strftime("%Y-%m-%d-%H-%M-%S", time.localtime((time.time()))) + ".jpg"
            path = os.path.join(_pic_path, filename)
            result = objdll.VzLPRClient_SaveSnapImageToJpeg(self.sdk_hdl, path.encode('gb2312'))
            if result != 0:
                self.save_pic_in_path(count + 1)
                if count > 3:
                    return "图片获取失败"
            return path
        except Exception as e:
            return "图片获取异常"

    def isLegalSn(self, sn):
        result = re.match(r"^[0-9a-fA-F]{8}-[0-9a-fA-F]{8}", sn) is not None
        print("isLegalSn", sn, result)
        return result
