#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
import json

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget, QMessageBox
from ui_tool_text_json import Ui_WidgetJson


class WidgetJson(QWidget, Ui_WidgetJson):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        # self.jsonFromatBtn.clicked.connect(self.jsonFromat)

    def jsonFromat(self):
        print("json")
        json_str = self.text_result.toPlainText()
        try:
            json_str = "{'a': 1, 'b': 2}"
            json.loads(json_str)
            js = json.dumps(json_str, sort_keys=True, indent=4, separators=(', ', ': '))
            print(js)
            self.text_result.setPlainText(js)
            return True
        except:
            QMessageBox.warning(self, "警告", "Json格式不合法")
            return False
