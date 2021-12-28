#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import _thread
from PyQt5 import QtCore, QtGui, QtWidgets
from libutils.finddevice import CFindDevice
from oqc_tool.cfg_factory_param_hs import *
from oqc_tool.ui_w21_dev_and_test import Ui_W21DevAndTest


#
class W21DevAndTest(QtWidgets.QWidget, Ui_W21DevAndTest):
    def __init__(self, pwm):
        super().__init__()
        self.is_search = False
        self.setupUi(self)
        self.pwm = pwm
        # 找设备
        self.fdev = CFindDevice()
        self.fdev.start()

        self.dev_host = '192.168.1.100'
        self.pSearchButton.clicked.connect(self.search_device)

        self.pSearchButton.setShortcut('F5')
        self.pAutotestButton.setShortcut('F8')

        self.devs_time = QtCore.QTimer()
        self.devs_time.timeout.connect(self.device_list_update)

        # 自动测试按钮
        self.pAutotestButton.clicked.connect(self.start_autotest_click)
        self.pTestListWidget.itemClicked.connect(self.test_widget_switch)

        # 设备更改IP
        self.pExchangeIPBtn.clicked.connect(self.dlens_exchange_host)

        # 设备列表
        self.pDevListWidget.itemClicked.connect(self.device_item_clicked)
        # self.pDevListWidget.itemDoubleClicked.connect(self.device_item_dclicked)

        item = QtWidgets.QListWidgetItem()
        item.setText('video')
        self.pTestListWidget.addItem(item)
        self.pTestListWidget.addItem('interface')
        self.pTestListWidget.addItem('result')
        self.pTestListWidget.setCurrentItem(item)

    def widget_init(self):
        # print('w21 widget_init')
        addrs = self.fdev.get_addrs()
        for addr in addrs:
            self.pLocalHostCBox.addItem(addr)

        fd, pro = self.pwm.get_product()
        self.dlens = fd.get_capacity_num('dlens')
        if self.dlens == 0:
            self.pExchangeIPBtn.setVisible(False)

    #
    def search_device(self):
        addrs = []
        addrs.append(self.pLocalHostCBox.currentText())
        self.fdev.set_addrs(addrs)
        if not self.is_search:
            self.is_search = True
            self.fdev.clear_devices()
            self.devs_time.start(1000)
            self.pSearchButton.setText('搜索停止(F5)')
        else:
            self.is_search = False
            # self.fdev.stop()
            self.devs_time.stop()
            self.pSearchButton.setText('搜索设备(F5)')

    def device_list_update(self):
        print('device_list_update')
        self.pDevListWidget.clear()
        devs_list = self.fdev.get_devices()
        for key in devs_list.keys():
            aitem = QtWidgets.QListWidgetItem()
            aitem.setData(0, devs_list[key]['addr'])
            aitem.setData(1, key)
            self.pDevListWidget.addItem(aitem)

    #
    def device_item_clicked(self, item):
        self.pDevHostEdit.setText(item.text())

    #
    # def device_item_dclicked(self, item):
    #     self.pDevHostEdit.setText(item.text())
    #     self.pwm.show_video(self.pDevHostEdit.text(),
    #                         self.pUsernameEdit.text(),
    #                         self.pPasswordEdit.text())

    #
    def start_autotest_click(self, i=0):
        self.pwm.autotest_start(self.pDevHostEdit.text(),
                                self.pUsernameEdit.text(),
                                self.pPasswordEdit.text(), i)

    # 测试窗口
    def test_widget_switch(self, item):
        self.pwm.test_widget_switch(item.text())

    # 双目更改IP地址
    def dlens_exchange_host(self):
        print('双目更改IP地址')
        devs = self.fdev.get_devices()
        # devs = {}
        try:
            _thread.start_new_thread(cfg_factory_param_dlens,
                                     (list(devs.values()), self.pUsernameEdit.text(), self.pPasswordEdit.text()))
        except:
            print("can't start thread")

