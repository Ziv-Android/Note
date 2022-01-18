#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
import json

from PyQt5.QtGui import QStandardItemModel, QStandardItem
from PyQt5.QtWidgets import QWidget, QMessageBox
from ui_tool_text_json import Ui_WidgetJson


class WidgetJson(QWidget, Ui_WidgetJson):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.chineseToUnicode = False
        # 格式化
        self.formatBtn.clicked.connect(self.json_format)
        # 压缩
        self.reduceBtn.clicked.connect(self.json_reduce)
        # 转义
        self.escapedBtn.clicked.connect(self.json_escaped)
        # 去转义
        self.unescapedBtn.clicked.connect(self.json_unescaped)
        # Unicode转中文
        self.unicodeToChineseBtn.clicked.connect(self.json_unicode_to_chinese)
        # 中文转Unicode
        self.chineseToUnicodeBtn.clicked.connect(self.json_chinese_to_unicode)
        # 清空
        self.cleanBtn.clicked.connect(self.json_clean)

    def json_parse(self, skipkeys=False, ensure_ascii=True, check_circular=True,
                   allow_nan=True, cls=None, indent=None, separators=None,
                   default=None, sort_keys=False):
        json_str = self.textEdit.toPlainText()
        json_str.replace('\n', '').replace('\r', '').strip()
        print("json_parse:", json_str)
        try:
            # str -> dict
            json_data = json.loads(json_str)
            # dict -> str
            js = json.dumps(json_data, skipkeys=skipkeys, ensure_ascii=ensure_ascii, check_circular=check_circular,
                            allow_nan=allow_nan, cls=cls, indent=indent, separators=separators,
                            default=default, sort_keys=sort_keys)
            self.textEdit.setPlainText(js)
            self.show_json_in_tree_view(json_data)
            return True
        except Exception as e:
            QMessageBox.warning(self, "警告", f"Json格式不合法\n{e}")
            return False

    def json_format(self):
        self.json_parse(sort_keys=True, indent=4, separators=(', ', ': '), ensure_ascii=self.chineseToUnicode)

    def json_reduce(self):
        self.json_parse(sort_keys=True, ensure_ascii=self.chineseToUnicode)

    def json_escaped(self):
        json_str = self.textEdit.toPlainText()
        json_str = json_str.replace("\"", "\\\"")
        self.textEdit.setPlainText(json_str)
        return True

    def json_unescaped(self):
        json_str = self.textEdit.toPlainText()
        json_str = json_str.replace("\\\"", "\"")
        self.textEdit.setPlainText(json_str)

    def json_unicode_to_chinese(self):
        self.chineseToUnicode = False
        self.json_parse(sort_keys=True, indent=4, separators=(', ', ': '), ensure_ascii=self.chineseToUnicode)

    def json_chinese_to_unicode(self):
        self.chineseToUnicode = True
        self.json_parse(sort_keys=True, indent=4, separators=(', ', ': '), ensure_ascii=self.chineseToUnicode)

    def json_clean(self):
        self.originTextEdit.clear()
        self.resultTextEdit.clear()

    def show_json_in_tree_view(self, json_data):
        tree_model = QStandardItemModel()
        self.treeView.setModel(tree_model)
        self.treeView.model().setHorizontalHeaderLabels(['Key', 'Values'])
        self.set_trew_view_model_data(tree_model.invisibleRootItem(), json_data)

    def set_trew_view_model_data(self, parent, data):
        print(parent, data)
        if isinstance(data, dict):
            for k, v in data.items():
                child = QStandardItem(str(k))
                if isinstance(v, (dict, list)):
                    # value = QStandardItem(str(type(v)))
                    # parent.appendRow([child, value])
                    parent.appendRow(child)
                else:
                    value = QStandardItem(str(v))
                    parent.appendRow([child, value])
                self.set_trew_view_model_data(child, v)
        elif isinstance(data, list):
            for i in range(len(data)):
                child = QStandardItem(str(i))
                v = data[i]
                if isinstance(v, (dict, list)):
                    # value = QStandardItem(str(type(v)))
                    # parent.appendRow([child, value])
                    parent.appendRow(child)
                else:
                    value = QStandardItem(str(v))
                    parent.appendRow([child, value])
                self.set_trew_view_model_data(child, v)
        # else:
        #     print(data)
        #     parent.appendRow(QStandardItem(str(data)))
