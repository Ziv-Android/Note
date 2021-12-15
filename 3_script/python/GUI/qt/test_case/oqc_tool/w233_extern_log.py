# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets

from c_log import *
from oqc_tool.ui_w233_extern_log import Ui_W233ExternLog


#
class W233ExternLog(QtWidgets.QWidget, Ui_W233ExternLog):
    name = "log"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.pLogBtn.clicked.connect(self.autotest_usercase)

    def autotest_usercase(self):
        webc = self.pwm.http_client_handle()
        ret, resp = c_log_sys(webc)
        jl = json.loads(resp)
        for log in jl['body']['logs']:
            ss = "%s\t%s" % (log['time'], log['data'])
            self.pLogEdit.appendPlainText(ss)
        print('log autotest_usercase')
        return True
