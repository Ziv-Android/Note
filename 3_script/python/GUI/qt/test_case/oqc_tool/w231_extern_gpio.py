#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_gpio import *
from oqc_tool.ui_w231_extern_gpio import Ui_W231ExternGPIO


#
class W231ExternGPIO(QtWidgets.QWidget, Ui_W231ExternGPIO):
    name_reset = "io_reset"
    name_ioin = "io_in"
    name_ioout = "io_out"
    gpio_signal = pyqtSignal(int, int, int, int)  # IO-IN,STA, IO-OUT,STA
    reset_signal = pyqtSignal(int)  # STA

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.num_ioin = 0
        self.num_ioout = 0
        self.num_reset = 0

        self.ioin_gbox = [
            self.pIOIn0GBox,
            self.pIOIn1GBox,
            self.pIOIn2GBox,
            self.pIOIn3GBox
        ]
        self.ioin_state = [
            self.pIOIn0Label,
            self.pIOIn1Label,
            self.pIOIn2Label,
            self.pIOIn3Label
        ]
        self.ioout_gbox = [
            self.pIOOut0GBox,
            self.pIOOut1GBox,
            self.pIOOut2GBox
        ]
        self.ioout_state = [
            self.pIOOut0Label,
            self.pIOOut1Label,
            self.pIOOut2Label
        ]
        self.gpio_signal.connect(self.gpio_update_state)
        self.reset_signal.connect(self.reset_update_state)

        self.pIOOut0OffBtn.clicked.connect(self.gpio_out_0_low)
        self.pIOOut0OnBtn.clicked.connect(self.gpio_out_0_high)
        self.pIOOut1OffBtn.clicked.connect(self.gpio_out_1_low)
        self.pIOOut1OnBtn.clicked.connect(self.gpio_out_1_high)
        self.pIOOut2OffBtn.clicked.connect(self.gpio_out_2_low)
        self.pIOOut2OnBtn.clicked.connect(self.gpio_out_2_high)
        self.pResetKeyBtn.clicked.connect(self.autotest_usercase_reset)

    def widget_init(self, reset_num=1, in_num=2, out_num=2):
        self.num_ioin = in_num
        self.num_ioout = out_num
        self.num_reset = reset_num

        if reset_num == 0:
            self.pResetKeyGBox.setVisible(False)

        for i in range(4):
            if i < in_num:
                self.ioin_gbox[i].setVisible(True)
            else:
                self.ioin_gbox[i].setVisible(False)

        for i in range(3):
            if i < out_num:
                self.ioout_gbox[i].setVisible(True)
            else:
                self.ioout_gbox[i].setVisible(False)

    def gpio_out(self, out_num, out_sta):
        webc = self.pwm.http_client_handle()
        if webc is None:
            return {}

        in_sta = {}
        ret = c_gpio_out(webc, out_num, out_sta)
        if ret != 200:
            print('c_gpio_set %d failed' % out_num)
            return in_sta

        if self.num_ioin == 0:
            return {0: out_sta}

        time.sleep(0.1)
        for i in range(self.num_ioin):
            sta = c_io_out_get(webc, i)  # io-0
            self.gpio_signal.emit(i, sta, -1, 0)
            in_sta[i] = sta
        return in_sta

    def gpio_out_0_low(self):
        self.gpio_out(0, 0)
        self.ioout_state[0].setText(str(0))

    def gpio_out_0_high(self):
        self.gpio_out(0, 1)
        self.ioout_state[0].setText(str(1))

    def gpio_out_1_low(self):
        self.gpio_out(1, 0)
        self.ioout_state[1].setText(str(0))

    def gpio_out_1_high(self):
        self.gpio_out(1, 1)
        self.ioout_state[1].setText(str(1))

    def gpio_out_2_low(self):
        self.gpio_out(2, 0)
        self.ioout_state[2].setText(str(0))

    def gpio_out_2_high(self):
        self.gpio_out(2, 1)
        self.ioout_state[2].setText(str(1))

    # 更新GPIO显示
    def gpio_update_state(self, in_num, in_sta, out_num, out_sta):
        if 0 <= in_num < self.num_ioin:
            self.ioin_state[in_num].setText(str(in_sta))
        if 0 <= out_num < self.num_ioout:
            self.ioout_state[out_num].setText(str(out_sta))

    # 更新RESET显示
    def reset_update_state(self, state):
        self.pResetKeyLabel.setText(str(state))

    # 自动测试
    def autotest_usercase_gpio(self):
        print('w231 autotest_usercase_gpio')
        for i in range(self.num_ioout):
            in_old = self.gpio_out(i, 1)
            if len(in_old) == 0:
                return False
            print(in_old)
            time.sleep(1)
            in_new = self.gpio_out(i, 0)
            print(in_new)
            if self.num_ioin > 0:
                if in_old == in_new:
                    return False
        return True

    def autotest_usercase_reset(self):
        webc = self.pwm.http_client_handle()
        if webc is None:
            return False
        return True
        old = c_gpio_get(webc, 3, 0)
        self.reset_signal.emit(old)
        # self.reset_update_state(old)
        for i in range(10):
            time.sleep(1)
            new = c_gpio_get(webc, 3, 0)
            if new == -1:
                return False

            self.reset_signal.emit(new)
            # self.reset_update_state(new)
            if new != old:
                return True
        return False
