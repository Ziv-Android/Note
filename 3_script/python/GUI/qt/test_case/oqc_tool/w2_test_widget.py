# !/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import time

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QProgressDialog

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
        self.client = None
        self.prt = ui_parent
        self.pro_fd = ConfigProduct('test')
        self.product = str

        self.cus_fd = ConfigClient('test')
        self.customer = str

        dtc = QtWidgets.QVBoxLayout()
        #
        self.w21_dat = W21DevAndTest(self)
        self.w21_dat.pDevHostEdit.textChanged.connect(self.reset_http_client_handle)
        self.w21_dat.pUsernameEdit.textChanged.connect(self.reset_http_client_handle)
        self.w21_dat.pPasswordEdit.textChanged.connect(self.reset_http_client_handle)
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

    def set_soft_ver(self, ver):
        self.w21_dat.set_soft_ver(ver)

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

    def get_custom_sn_file(self):
        return self.prt.get_custom_sn_file()

    def widget_init(self):
        self.w21_dat.widget_init()
        self.w22_vdo.widget_init()
        self.w23_ext.widget_init()
        self.w24_ret.widget_init()

    def reset_http_client_handle(self):
        if self.client is not None:
            self.client.close()
            self.client = None

    def http_client_handle(self):
        if self.client is None:
            host = self.w21_dat.pDevHostEdit.text()
            username = self.w21_dat.pUsernameEdit.text()
            password = self.w21_dat.pPasswordEdit.text()
            try:
                url = 'http://%s:80' % host
                self.client = WEBClient(url, username, password)
                QtWidgets.QApplication.processEvents()
                if not self.client.login():
                    print("login failed, retry 1")
                    # time.sleep(2)
                QtWidgets.QApplication.processEvents()
                if not self.client.login():
                    print("login failed, retry 2")
                    # time.sleep(1)
                QtWidgets.QApplication.processEvents()
                if not self.client.login():
                    print("login failed, retry 3")
                    self.client = None
            except:
                print("can't connect %s " % host)
                self.client = None
        return self.client

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
            self.w24_ret.get_custom_sn_cfg_client()
        else:
            self.pTestStackWidget.setCurrentWidget(self.w22_vdo)
        self.w22_vdo.autotest_stop(0)
        self.w23_ext.autotest_stop(0)


