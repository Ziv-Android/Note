#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow
import os
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.config_client import ConfigClient
from oqc_tool.config_product import ConfigProduct
from oqc_tool.ui_w1_product_change import Ui_W01_ProductChange


#
class W1ProductChange(QtWidgets.QWidget, Ui_W01_ProductChange):
    def __init__(self, product, pwm):
        super().__init__()
        self.setupUi(self)
        self.pSrvGBox.setVisible(False)

        self.pwm = pwm
        self.dir = "./product/%s/" % product  # 产品目录
        print(self.dir)

        self.init_product()
        self.init_customer()
        self.pFinishCfgBtn.clicked.connect(self.finish_config_product)
        self.pProductCBox.currentIndexChanged.connect(self.pro_change_slots)

    # 初始化客户列表
    def init_customer(self):
        self.cc = ConfigClient(self.dir)
        for i in range(1, 10):
            section = "c%02d" % i
            name = self.cc.get_name(section)
            if name:
                self.pCustomerCBox.addItem(name, section)
            else:
                break

    # 初始化产品列表
    def init_product(self):
        filelist = self.get_filelist(self.dir, [])
        self.pProductCBox.addItem('-')
        for file in filelist:
            self.pProductCBox.addItem(file)
        print(filelist)

    # 遍历文件夹及其子文件夹中的文件，并存储在一个列表中
    # 输入文件夹路径、空文件列表[]
    # 返回 文件列表Filelist,包含文件名（完整路径）
    def get_filelist(self, dir, file_list):
        new_dir = dir
        if os.path.isfile(dir):
            filename = os.path.basename(dir)    # 文件名
            if filename.endswith(".ini"):
                file_list.append(filename.split(".")[0])

        elif os.path.isdir(dir):
            for s in os.listdir(dir):
                # 如果需要忽略某些文件夹，使用以下代码
                if s == "customer.ini":
                   continue
                new_dir = os.path.join(dir, s)
                self.get_filelist(new_dir, file_list)

        return file_list

    # 产品选择
    def pro_change_slots(self):
        pro = self.pProductCBox.currentText()
        path = self.dir + pro + '.ini'
        print(path)

        self.pProductInfo.clear()
        self.cp = ConfigProduct(path)
        if not self.cp.is_init():
            return

        # 照片
        img_path = self.dir + 'image/' + self.cp.get_image_path()
        img = QtGui.QPixmap()
        img.load(img_path)
        mw = self.pProductImage.width()
        mh = self.pProductImage.height()
        self.pProductImage.setPixmap(img.scaled(mw, mh))

        # 产品信息:描述+测试点
        self.pProductInfo.appendPlainText(self.cp.get_desc())
        caps = self.cp.get_capacity()
        for cap in caps:
            self.pProductInfo.appendPlainText(str(cap))
        # print(cp.get_capacity())

    # 确认产品选择
    def finish_config_product(self):
        product = self.pProductCBox.currentText()
        customer = self.pCustomerCBox.currentData()
        if product == '-':
            return
        if not self.cc.is_init():
            print('ConfigClient failed')
            return
        if not self.cp.is_init():
            print('ConfigProduct failed')
            return
        self.pwm.finish_callback(self.cp, product, self.cc, customer)
