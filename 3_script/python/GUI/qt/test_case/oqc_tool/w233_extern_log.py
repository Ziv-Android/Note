#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_log import *
from oqc_tool.ui_w233_extern_log import Ui_W233ExternLog


#
class W233ExternLog(QtWidgets.QWidget, Ui_W233ExternLog):
    name = "log"
    log_read_finish_signal = pyqtSignal(str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.pLogBtn.clicked.connect(self.autotest_usercase)
        self.log_read_finish_signal.connect(self.edit_log)

    def edit_log(self, log):
        self.pLogEdit.appendPlainText(log)

    def autotest_usercase(self):
        webc = self.pwm.http_client_handle()
        ret, resp = c_log_sys(webc)
        if resp is None:
            return False

        try:
            jl = json.loads(resp)
            log = ""
            if jl['body']['rec_size'] == 0:
                return True
            for log_line in jl['body']['logs']:
                log += "%s\t%s\n" % (log_line['time'], log_line['data'])
            self.log_read_finish_signal.emit(log)
            print('log autotest_usercase')
            return True
        except Exception as e:
            print('log autotest_usercase', e)
            return False