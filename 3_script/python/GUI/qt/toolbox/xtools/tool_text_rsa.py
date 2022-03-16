#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget, QStackedWidget, QListWidgetItem
from ui_tool_text_rsa import Ui_WidgetRSA
from tool_text_rsa_create_verify_secret_key import WidgetRsaCreateSecretKey
from tool_text_rsa_change_private_key_password import WidgetRsaChangePrivateKeyPassword
from tool_text_rsa_encrypt import WidgetRsaEncrypt


class WidgetRSA(QWidget, Ui_WidgetRSA):
    items = ["创建/验证密钥对", "修改私钥密码", "RSA加密/解密"]

    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.listItemCreateSecretKey = QListWidgetItem(WidgetRSA.items[0])
        self.listWidget.addItem(self.listItemCreateSecretKey)
        self.stackedItemCreateSecretKey = WidgetRsaCreateSecretKey()
        self.rsaStackedWidget.addWidget(self.stackedItemCreateSecretKey)

        self.listItemChangePrivateKeyPassword = QListWidgetItem(WidgetRSA.items[1])
        self.listWidget.addItem(self.listItemChangePrivateKeyPassword)
        self.changePrivateKeyPassword = WidgetRsaChangePrivateKeyPassword()
        self.rsaStackedWidget.addWidget(self.changePrivateKeyPassword)

        self.listItemEncrypt = QListWidgetItem(WidgetRSA.items[2])
        self.listWidget.addItem(self.listItemEncrypt)
        self.encrypt = WidgetRsaEncrypt()
        self.rsaStackedWidget.addWidget(self.encrypt)

        self.listWidget.itemClicked.connect(self.rsa_widget_changed)
        self.listWidget.setCurrentItem(self.listItemCreateSecretKey)

    def rsa_widget_changed(self, item):
        index_stacked_page = WidgetRSA.items.index(item.text())
        self.rsaStackedWidget.setCurrentIndex(index_stacked_page)
