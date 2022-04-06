#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_lens import *
from oqc_tool.ui_w223_video_lens import Ui_W223VideoLens


#
class W223VideoLens(QtWidgets.QWidget, Ui_W223VideoLens):
    name = "lens"
    message_signal = pyqtSignal(str, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.motor = 0
        self.runmode = 0
        self.login_state = False

        # 镜头
        self.lens_zoomin_sta = 0
        self.pLensZoomInBtn.pressed.connect(self.lens_zoom_in)
        self.pLensZoomInBtn.released.connect(self.lens_zoom_in)

        self.lens_zoomout_sta = 0
        self.pLensZoomOutBtn.pressed.connect(self.lens_zoom_out)
        self.pLensZoomOutBtn.released.connect(self.lens_zoom_out)

        self.lens_focusin_sta = 0
        self.pLensFocusInBtn.pressed.connect(self.lens_focus_in)
        self.pLensFocusInBtn.released.connect(self.lens_focus_in)

        self.lens_focusout_sta = 0
        self.pLensFocusOutBtn.pressed.connect(self.lens_focus_out)
        self.pLensFocusOutBtn.released.connect(self.lens_focus_out)

        self.pLensFocusAutoBtn.clicked.connect(self.lens_auto_focus)

        self.message_signal.connect(self.show_message_box)

    def show_message_box(self, title, msg):
        QtWidgets.QMessageBox.warning(self, title, msg)

    def lens_reset(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_lens_reset(webc)

    def lens_get_reset_status(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_lens_get_reset_state(webc)

    # 镜头
    def lens_zoom_in(self):
        webc = self.pwm.http_client_handle()
        self.lens_zoomin_sta = 1
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        self.motor, self.runmode = c_lens_zoom_in(webc, 1)
        if not self.pLensSpeedCBox.isChecked():
            time.sleep(0.3)
            return c_lens_keep(webc, self.motor, self.runmode)

    def lens_zoom_in_stop(self):
        self.lens_zoomin_sta = 0
        return self.lens_zoom_stop()

    #
    def lens_zoom_out(self):
        webc = self.pwm.http_client_handle()
        self.lens_zoomout_sta = 1
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        self.motor, self.runmode = c_lens_zoom_out(webc)
        if not self.pLensSpeedCBox.isChecked():
            time.sleep(0.3)
            return c_lens_keep(webc, self.motor, self.runmode)

    def lens_zoom_out_stop(self):
        self.lens_zoomout_sta = 0
        return self.lens_zoom_stop()

    def lens_zoom_stop(self):
        webc = self.pwm.http_client_handle()
        return c_lens_stop(webc, self.motor, self.runmode)

    #
    def lens_focus_in(self):
        webc = self.pwm.http_client_handle()
        if self.lens_focusin_sta == 1:
            self.lens_focusin_sta = 0
            return c_lens_stop(webc, self.motor, self.runmode)
        elif self.lens_focusin_sta == 0:
            self.lens_focusin_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            self.motor, self.runmode = c_lens_focus_in(webc)
            if not self.pLensSpeedCBox.isChecked():
                time.sleep(0.3)
                return c_lens_keep(webc, self.motor, self.runmode)

    #
    def lens_focus_out(self):
        webc = self.pwm.http_client_handle()
        if self.lens_focusout_sta == 1:
            self.lens_focusout_sta = 0
            return c_lens_stop(webc, self.motor, self.runmode)
        elif self.lens_focusout_sta == 0:
            self.lens_focusout_sta = 1
            if not self.login_state:
                self.message_signal.emit("失败", "设备未登录")
                return 404
            self.motor, self.runmode = c_lens_focus_out(webc, 1)
            if not self.pLensSpeedCBox.isChecked():
                time.sleep(0.3)
                return c_lens_keep(webc, self.motor, self.runmode)

    #
    def lens_auto_focus(self):
        if not self.login_state:
            self.message_signal.emit("失败", "设备未登录")
            return 404
        webc = self.pwm.http_client_handle()
        return c_lens_autofocus(webc)

    def set_login_state(self, state):
        self.login_state = state
