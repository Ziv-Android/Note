#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread
import time

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_ptz import *
from oqc_tool.ui_w224_video_ptz import Ui_W224VideoPTZ


#
class W224VideoPTZ(QtWidgets.QWidget, Ui_W224VideoPTZ):
    name = "ptz"
    message_signal = pyqtSignal(str, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.login_state = False
        # 云台
        self.pPTZResetBtn.clicked.connect(self.ptz_reset)

        self.ptz_up_sta = 0  # 0=无,1=按一下
        self.pPTZUpBtn.pressed.connect(self.ptz_up)
        self.pPTZUpBtn.released.connect(self.ptz_up)

        self.ptz_down_sta = 0
        self.pPTZDownBtn.pressed.connect(self.ptz_down)
        self.pPTZDownBtn.released.connect(self.ptz_down)

        self.ptz_left_sta = 0
        self.pPTZLeftBtn.pressed.connect(self.ptz_left)
        self.pPTZLeftBtn.released.connect(self.ptz_left)

        self.ptz_right_sta = 0
        self.pPTZRightBtn.pressed.connect(self.ptz_right)
        self.pPTZRightBtn.released.connect(self.ptz_right)

        self.message_signal.connect(self.show_message_box)

    def show_message_box(self, title, msg):
        QtWidgets.QMessageBox.warning(self, title, msg)

    def ptz_reset(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_ptz_reset(webc)

    #
    def ptz_up(self):
        webc = self.pwm.http_client_handle()
        if self.ptz_up_sta == 1:
            self.ptz_up_sta = 0
            return c_ptz_stop_ud(webc)
        elif self.ptz_up_sta == 0:
            self.ptz_up_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            ret = c_ptz_up(webc)
            # time.sleep(0.2)
            return c_ptz_keep(webc, ret + 1)

    #
    def ptz_down(self):
        webc = self.pwm.http_client_handle()
        if self.ptz_down_sta == 1:
            self.ptz_down_sta = 0
            return c_ptz_stop_ud(webc)
        elif self.ptz_down_sta == 0:
            self.ptz_down_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            ret = c_ptz_down(webc)
            # time.sleep(0.2)
            return c_ptz_keep(webc, ret + 1)

    #
    def ptz_left(self):
        webc = self.pwm.http_client_handle()
        if self.ptz_left_sta == 1:
            self.ptz_left_sta = 0
            return c_ptz_stop_lr(webc)
        elif self.ptz_left_sta == 0:
            self.ptz_left_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            ret = c_ptz_left(webc)
            # time.sleep(0.2)
            return c_ptz_keep(webc, ret + 1)

    #
    def ptz_right(self):
        webc = self.pwm.http_client_handle()
        if self.ptz_right_sta == 1:
            self.ptz_right_sta = 0
            return c_ptz_stop_lr(webc)
        elif self.ptz_right_sta == 0:
            self.ptz_right_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            ret = c_ptz_right(webc)
            # time.sleep(0.2)
            return c_ptz_keep(webc, ret + 1)

    def set_login_state(self, state):
        self.login_state = state
