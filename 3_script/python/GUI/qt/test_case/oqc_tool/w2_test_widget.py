# !/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QMessageBox

from libutils.webclient import WEBClient
# from oqc_tool import objdll
from oqc_tool.config_client import ConfigClient
from oqc_tool.config_product import ConfigProduct
from oqc_tool.ui_w2_test_widget import Ui_W2TestWidget
from oqc_tool.w21_dev_and_test import W21DevAndTest
from oqc_tool.w22_video_check_hs import W22VideoCheck
from oqc_tool.w23_extern_device import W23ExternDevice
from oqc_tool.w24_final_result import W24FinalResult


#
class W2TestWidget(QtWidgets.QWidget, Ui_W2TestWidget):
    def __init__(self, ui_parent=None):
        super().__init__()
        self.setupUi(self)
        self.prt = ui_parent
        self.pro_fd = ConfigProduct('test')
        self.product = str

        self.cus_fd = ConfigClient('test')
        self.customer = str

        dtc = QtWidgets.QVBoxLayout()
        #
        self.w21_dat = W21DevAndTest(self)
        dtc.addWidget(self.w21_dat)
        self.pDeviceTestCase.setLayout(dtc)
        self.pDeviceTestCase.setMaximumWidth(240)
        #
        self.w22_vdo = W22VideoCheck(self)
        self.pTestStackWidget.addWidget(self.w22_vdo)
        #
        self.w23_ext = W23ExternDevice(self)
        self.pTestStackWidget.addWidget(self.w23_ext)
        #
        self.w24_ret = W24FinalResult(self)
        self.pTestStackWidget.addWidget(self.w24_ret)
        #
        self.pTestStackWidget.setCurrentWidget(self.w22_vdo)

    def set_product(self, fd, product):
        self.pro_fd = fd
        self.product = product

    def get_product(self):
        return self.pro_fd, self.product

    def set_customer(self, fd, customer):
        self.cus_fd = fd
        self.customer = customer

    def get_customer(self):
        return self.cus_fd, self.customer

    def widget_init(self):
        self.w21_dat.widget_init()
        self.w22_vdo.widget_init()
        self.w23_ext.widget_init()

    def http_client_handle(self):
        host = self.w21_dat.pDevHostEdit.text()
        username = self.w21_dat.pUsernameEdit.text()
        password = self.w21_dat.pPasswordEdit.text()
        try:
            url = 'http://%s:80' % host
            webc = WEBClient(url, username, password)
            if not webc.login():
                print("login failed")
                return None
            return webc
        except:
            print("can't connect %s " % host)
            return None

    # 自动测试开始
    def autotest_start(self, host, username, password, i):
        cur_wdg = self.pTestStackWidget.currentWidget()
        if cur_wdg == self.w22_vdo:
            self.w22_vdo.autotest_start(host, username, password, i)
        elif cur_wdg == self.w23_ext:
            self.w23_ext.autotest_start(host, username, password, i)

    # def show_video(self, host, username, password):
    #     self.w22_vdo.show_video(host, username, password)

    # 测试列表-切换测试主窗口
    def test_widget_switch(self, name):
        if self.w22_vdo.name == name:
            self.pTestStackWidget.setCurrentWidget(self.w22_vdo)
        elif self.w23_ext.name == name:
            self.pTestStackWidget.setCurrentWidget(self.w23_ext)
        elif self.w24_ret.name == name:
            self.pTestStackWidget.setCurrentWidget(self.w24_ret)
        else:
            self.pTestStackWidget.setCurrentWidget(self.w22_vdo)
        self.w22_vdo.autotest_stop()
        self.w23_ext.autotest_stop()


