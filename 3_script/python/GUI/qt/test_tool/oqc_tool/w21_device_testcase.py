# from oqc_tool import Ui_MainWindow
from oqc_tool import *
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_w21_device_testcase import Ui_W21DeviceTestCase


#
class W21DeviceTestCase(QtWidgets.QWidget, Ui_W21DeviceTestCase):
    def __init__(self, pwm):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm

        self.pSearchButton.clicked.connect(self.search_device)

        self.pSearchButton.setShortcut('F5')
        self.pTestStartButton.setShortcut('F8')
        # self.update_device_widget()

    #
    def search_device(self):
        # self.pQCEdit.setText("hello worlds")
        print("hello worlds")
        self.pwm.test_func()

    #
    def dev_list_update_widget(self):
        self.pDevListWidget.addItem('192.168.1.100')

    #
    def dev_list_click_item(self):
        print('aaa')
