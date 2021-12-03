#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from main import *

# 导入 Qt designer 设计的页面
from login.LoginWindow import Ui_Dialog as Login_Ui


# 登陆窗口
class LoginWindow(QtWidgets.QDialog, Login_Ui):
    # 析构函数，第一个执行，进行项目初始化
    def __init__(self):
        # 重载
        super(LoginWindow, self).__init__()
        self.setupUi(self)
        # 绑定事件与槽函数
        self.buttonBox.accepted.connect(self.btn_accept_func)
        self.buttonBox.rejected.connect(self.btn_reject_func)

    def btn_accept_func(self):
        print("确定")
        account = self.username.text()
        password = self.password.text()

        # if account == "" or password == "":
        #     QtWidgets.QMessageBox.warning(self, "警告", "账号密码不能为空")
        #     return

        # home = UpgradeWindow()
        home.show()
        self.close()

    def btn_reject_func(self):
        print("取消")
        self.close()


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    login = LoginWindow()
    home = UpgradeWindow()
    login.show()
    sys.exit(app.exec_())
    # main()

