# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets

from c_ircut import *
from oqc_tool.ui_w221_video_ircut import Ui_W221VideoIRCUT

#
class W221VideoIRCUT(QtWidgets.QWidget, Ui_W221VideoIRCUT):
    name = "ircut"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm

        # IR-CUT
        self.pIRCUTDayBtn.clicked.connect(self.ircut_day)
        self.pIRCUTNightBtn.clicked.connect(self.ircut_night)

    # IR-CUT
    def ircut_day(self):
        webc = self.pwm.http_client_handle()
        c_ircut_day(webc)

    def ircut_night(self):
        webc = self.pwm.http_client_handle()
        c_ircut_night(webc)
