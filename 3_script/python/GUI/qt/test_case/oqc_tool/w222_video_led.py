#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets

from c_led import *
from oqc_tool.ui_w222_video_led import Ui_W222VideoLed


#
class W222VideoLed(QtWidgets.QWidget, Ui_W222VideoLed):
    name = "led"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.pLEDHSlider.valueChanged.connect(self.value_change)

    def value_change(self):
        self.led_ctrl(self.pLEDHSlider.value())
        print(self.pLEDHSlider.value())

    def led_ctrl(self, value):
        webc = self.pwm.http_client_handle()
        return c_led(webc, value)
