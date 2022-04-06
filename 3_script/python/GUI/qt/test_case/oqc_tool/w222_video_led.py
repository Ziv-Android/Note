#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_led import *
from oqc_tool.ui_w222_video_led import Ui_W222VideoLed


#
class W222VideoLed(QtWidgets.QWidget, Ui_W222VideoLed):
    name = "led"
    message_signal = pyqtSignal(str, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.login_state = False
        self.pLEDHSlider.valueChanged.connect(self.value_change)

        self.message_signal.connect(self.show_message_box)

    def show_message_box(self, title, msg):
        QtWidgets.QMessageBox.warning(self, title, msg)

    def value_change(self):
        self.led_ctrl(self.pLEDHSlider.value(), 0)
        print(self.pLEDHSlider.value())

    def led_ctrl(self, value, mode):
        if mode == 0 and not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        print("led_ctrl_level", value)
        return c_led(webc, value)

    def set_login_state(self, state):
        self.login_state = state
