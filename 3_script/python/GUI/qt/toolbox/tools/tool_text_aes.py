#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget
from ui_tool_text_aes import Ui_WidgetAES


class WidgetAES(QWidget, Ui_WidgetAES):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
