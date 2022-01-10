#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QMainWindow
from .ui.ui_window_main import Ui_MainWindow
from .widget_upgrade import UpgradeWidget


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        # 升级主窗口
        self.upgrade_widget = UpgradeWidget(self)
        self.stackedWidget.addWidget(self.upgrade_widget)

    def closeEvent(self, event):
        print("MainWindow closeEvent.")
        pass
