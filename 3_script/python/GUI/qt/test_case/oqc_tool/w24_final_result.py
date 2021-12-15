# from oqc_tool import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets

from oqc_tool.ui_w24_final_result import Ui_W24FinalResult


#
class W24FinalResult(QtWidgets.QWidget, Ui_W24FinalResult):
    name = "result"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm


