#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5 import QtWidgets

# 导入 Qt designer 设计的页面
from GUI.qt.login_upgrade.src.login.LoginWindow import Ui_Dialog as Login_Ui
from GUI.qt.login_upgrade.src.upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui


# 登陆窗口
class LoginWindow(QtWidgets.QDialog, Login_Ui):
    def __init__(self):
        super(LoginWindow, self).__init__()
        self.setupUi(self)


# 升级窗口
class UpgradeWindow(QtWidgets.QMainWindow, Upgrade_Ui):
    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setupUi(self)


# 控制器控制页面跳转
class Controller:
    def __init__(self):
        pass

    def show_login(self):
        self.login = LoginWindow()
        self.login.show()

    def show_upgrade(self):
        self.upgrade = UpgradeWindow()
        self.login.close()
        self.upgrade.show()

