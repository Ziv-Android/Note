# from oqc_tool import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_w22_video_check import Ui_W22VideoCheck


#
class W22VideoCheck(QtWidgets.QWidget, Ui_W22VideoCheck):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        # self.pLoginButton.clicked.connect(self.LoginClickedSlot)

        # self.cfg = CProTypeCfg()
        # self.pTestTreeView

    def LoginClickedSlot(self):
        self.pQCEdit.setText("hello worlds")
