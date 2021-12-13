# from oqc_tool import Ui_MainWindow
from ctypes import *
from oqc_tool import *
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_mainwindow import Ui_MainWindow
from oqc_tool.w2_test_widget import W2TestWidget
from oqc_tool.w1_product_change import W1ProductChange


#
class CMainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        objdll.VzLPRClient_Setup()

        # 产品选择界面
        self.w1_pro_chg = W1ProductChange()
        self.pMainStackWidget.addWidget(self.w1_pro_chg)

        # 测试主界面
        self.w2_test_wdg = W2TestWidget()
        self.pMainStackWidget.addWidget(self.w2_test_wdg)

        # 初始化时为当前界面=产品选择界面
        # self.pMainStackWidget.setCurrentWidget(self.w1_pro_chg)
        self.pMainStackWidget.setCurrentWidget(self.w2_test_wdg)
        # self.pLoginButton.clicked.connect(self.LoginClickedSlot)

    # def LoginClickedSlot(self):
    #     self.pQCEdit.setText("hello worlds")
