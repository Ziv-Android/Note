#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget
from ui_tool_text_rsa import Ui_WidgetRSA
from tool_text_rsa_create_verify_secret_key import WidgetRsaCreateSecretKey
from tool_text_rsa_change_private_key_password import WidgetRsaChangePrivateKeyPassword
from tool_text_rsa_encrypt import WidgetRsaEncrypt


class WidgetRSA(QWidget, Ui_WidgetRSA):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.listWidget.addItems(["创建/验证密钥对", "修改私钥密码", "RSA加密/解密"])
        self.listWidget.itemClicked.connect(self.rsa_widget_changed)
        self.listWidget.setCurrentIndex(QModelIndex())

        self.createSecretKey = WidgetRsaCreateSecretKey()
        self.rsaStackedWidget.addWidget(self.createSecretKey)
        self.changePrivateKeyPassword = WidgetRsaChangePrivateKeyPassword()
        self.rsaStackedWidget.addWidget(self.changePrivateKeyPassword)
        self.encrypt = WidgetRsaEncrypt()
        self.rsaStackedWidget.addWidget(self.encrypt)

    def rsa_widget_changed(self, item):
        self.rsaStackedWidget.setCurrentIndex(item.)
