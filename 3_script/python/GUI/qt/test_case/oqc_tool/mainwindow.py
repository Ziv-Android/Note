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
        try:
            ret = objdll.VzLPRClient_Setup()
            print("objdll.VzLPRClient_Setup %d" % ret)
        except:
            print("objdll is not define")

        # 测试主界面
        self.w2_test_wdg = W2TestWidget()
        self.pMainStackWidget.addWidget(self.w2_test_wdg)

        # 产品选择界面
        self.w1_pro_chg = W1ProductChange('h', self)
        self.pMainStackWidget.addWidget(self.w1_pro_chg)

        # 初始化时为当前界面=产品选择界面
        self.pMainStackWidget.setCurrentWidget(self.w1_pro_chg)

    def closeEvent(self, event):
        print("closeEvent")
        try:
            self.w2_test_wdg.w21_dat.fdev.stop()
        except:
            print('finddevice is not define')
        objdll.VzLPRClient_Cleanup()

    def finish_callback(self, cp_fd, product, cc_fd, customer):
        self.w2_test_wdg.set_product(cp_fd, product)
        self.w2_test_wdg.set_customer(cc_fd, customer)
        self.w2_test_wdg.widget_init()

        self.pMainStackWidget.setCurrentWidget(self.w2_test_wdg)


