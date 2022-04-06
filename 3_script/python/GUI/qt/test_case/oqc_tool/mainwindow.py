#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
from ctypes import *
from oqc_tool import *
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_mainwindow import Ui_MainWindow
from oqc_tool.w2_test_widget import W2TestWidget
from oqc_tool.w1_product_change import W1ProductChange

import win32api
from libutils.wordreport import *
from oqc_tool.config_app import *


#
class CMainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        try:
            ret = objdll.VzLPRClient_Setup()
            print("objdll.VzLPRClient_Setup %d" % ret)
        except:
            print("objdll is not define")

        self.windowTitle = self.windowTitle()
        self.setWindowTitle(f"{self.windowTitle}({version_app})")

        # 测试主界面
        self.w2_test_wdg = W2TestWidget(self)
        self.pMainStackWidget.addWidget(self.w2_test_wdg)

        # 产品选择界面
        self.w1_pro_chg = W1ProductChange('h', self)
        self.pMainStackWidget.addWidget(self.w1_pro_chg)

        # 初始化时为当前界面=产品选择界面
        self.pMainStackWidget.setCurrentWidget(self.w1_pro_chg)

    def closeEvent(self, event):
        print("closeEvent")
        try:
            self.w2_test_wdg.w21_dat.fdev.stop()
        except:
            print('finddevice is not define')
        objdll.VzLPRClient_Cleanup()
        win32api.FreeLibrary(objdll._handle)  # 发现程序运行结束时无法正常退出dll，需要显式释放dll
        # self.report_doc.save_doc()

    def finish_callback(self, cp_fd, product, cc_fd, customer):
        self.setWindowTitle(f"{self.windowTitle}({version_app})-{cc_fd.get_name(customer)}-{product}")
        params = report_doc.get_empty_params()
        params["产品型号"] = product
        self.w2_test_wdg.set_product(cp_fd, product)
        params["订货客户"] = cc_fd.get_name(customer)
        self.w2_test_wdg.set_customer(cc_fd, customer)
        self.w2_test_wdg.widget_init()

        self.pMainStackWidget.setCurrentWidget(self.w2_test_wdg)

        report_doc.report_basic(params)

    def back_to_product_page(self):
        self.pMainStackWidget.setCurrentWidget(self.w1_pro_chg)

    def get_custom_sn_file(self):
        return self.w1_pro_chg.custom_sn_file
