#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from oqc_tool.w241_final_log import W241FinalLog
from oqc_tool.ui_w24_final_result import Ui_W24FinalResult


#
class W24FinalResult(QtWidgets.QWidget, Ui_W24FinalResult):
    name = "result"

    auto_test_signal = pyqtSignal(str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm

        self.final_log = W241FinalLog(self)
        self.pFinalGLayout.addWidget(self.final_log)
        self.auto_test_signal.connect(self.test_case_update_state)

    # 更新QListWidget item显示
    def test_case_update_state(self, text):
        self.final_log.show_result(text)
