# from oqc_tool import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_w2_test_widget import Ui_W2TestWidget
from oqc_tool.w22_video_check import W22VideoCheck
from oqc_tool.w21_device_testcase import W21DeviceTestCase

#
class W2TestWidget(QtWidgets.QWidget, Ui_W2TestWidget):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        # self.pLoginButton.clicked.connect(self.LoginClickedSlot)

        # self.cfg = CProTypeCfg()
        # self.pTestTreeView

        dtc = QtWidgets.QVBoxLayout()
        self.w2_dev_tc = W21DeviceTestCase(self)
        dtc.addWidget(self.w2_dev_tc)
        self.pDeviceTestCase.setLayout(dtc)
        self.pDeviceTestCase.setMaximumWidth(240)

        #
        self.w3_vdo_ch = W22VideoCheck()
        self.pTestStackWidget.addWidget(self.w3_vdo_ch)

    def test_func(self):
        print("hello worlds test widget")
