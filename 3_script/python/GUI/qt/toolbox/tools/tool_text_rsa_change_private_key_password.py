#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget
from ui_tool_text_rsa_change_private_key_password import Ui_WidgetRsaChangePrivateKeyPassword


class WidgetRsaChangePrivateKeyPassword(QWidget, Ui_WidgetRsaChangePrivateKeyPassword):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
