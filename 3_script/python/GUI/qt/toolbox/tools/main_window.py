#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
import sys

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QMainWindow, QApplication
from ui_main_window import Ui_MainWindow

from tool_image_base64 import WidgetImageBase64
from tool_text_aes import WidgetAES
from tool_text_json import WidgetJson
from tool_text_timestamp import WidgetTimestamp


class TMainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(TMainWindow, self).__init__()
        self.setupUi(self)

        self.tab_image_base64 = WidgetImageBase64()
        self.tab_text_aes = WidgetAES()
        self.tab_text_json = WidgetJson()
        self.tab_text_timestamp = WidgetTimestamp()

        # self.tabWidget.currentChanged.connect(self.on_current_changed)
        self.tabWidget.addTab(self.tab_image_base64, "图片Base64")
        self.tabWidget.addTab(self.tab_text_aes, "AES加密")
        self.tabWidget.addTab(self.tab_text_json, "Json格式化")
        self.tabWidget.addTab(self.tab_text_timestamp, "时间戳")


if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = TMainWindow()
    window.show()

    sys.exit(app.exec_())
