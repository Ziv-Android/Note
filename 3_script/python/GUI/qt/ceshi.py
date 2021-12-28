#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5 import QtWebEngineWidgets


class Ui(QMainWindow):
    def __init__(self):
        super(Ui, self).__init__()
        self.setWindowTitle("测试显示")
        self.setFixedSize(800, 600)
        self.centralWidget = QWidget()
        self.setCentralWidget(self.centralWidget)
        self.textBrowser = QtWebEngineWidgets.QWebEngineView()
        # Set the layout
        layout = QVBoxLayout()
        layout.addWidget(self.textBrowser)
        # layout.addStretch()
        self.centralWidget.setLayout(layout)

        self.showReport()

    def showReport(self):
        self.textBrowser.load(QUrl("file:///E:/workspace/private/Note/3_script/python/GUI/qt/ceshi_report.html"))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = Ui()
    win.show()
    sys.exit(app.exec())
