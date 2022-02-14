#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_ircut import *
from oqc_tool.ui_w221_video_ircut import Ui_W221VideoIRCUT


#
class W221VideoIRCUT(QtWidgets.QWidget, Ui_W221VideoIRCUT):
    name = "ircut"
    message_signal = pyqtSignal(str, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.login_state = False

        # IR-CUT
        self.pIRCUTDayBtn.clicked.connect(self.ircut_day)
        self.pIRCUTNightBtn.clicked.connect(self.ircut_night)

        self.message_signal.connect(self.show_message_box)

    def show_message_box(self, title, msg):
        QtWidgets.QMessageBox.warning(self, title, msg)

    # IR-CUT
    def ircut_day(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_ircut_day(webc)

    def ircut_night(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_ircut_night(webc)

    def set_login_state(self, state):
        self.login_state = state
