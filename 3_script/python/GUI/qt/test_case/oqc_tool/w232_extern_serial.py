# from oqc_tool import Ui_MainWindow
import _thread

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal

from c_rs485 import *
from oqc_tool.ui_w232_extern_serial import Ui_W232ExternSerial


#
class W232ExternSerial(QtWidgets.QWidget, Ui_W232ExternSerial):
    name = "serial"
    test_signal = pyqtSignal(int, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.num_serial = 0

        self.rs_gbox = [
            self.pRS0GBox,
            self.pRS1GBox,
            self.pRS2GBox
        ]
        self.rs_label = [
            self.pRS1Label,
            self.pRS2Label
        ]
        self.test_signal.connect(self.update_state)
        self.pRS0Btn.clicked.connect(self.autotest_usercase)

    def widget_init(self, rsnum=1):
        # print('serial %d' % rsnum)
        self.num_serial = rsnum
        for i in range(3):
            if i < self.num_serial:
                self.rs_gbox[i].setVisible(True)
            else:
                self.rs_gbox[i].setVisible(False)

    # 自动测试
    def autotest_usercase(self):
        ret = False
        webc = self.pwm.http_client_handle()
        sdata = self.pRS0Edit.text()
        ret, _ = c_rs485_write(webc, 1, sdata)
        if ret != 200:
            return False

        if self.num_serial == 2:
            time.sleep(1)
            ret, rdata = c_rs485_read(webc, 0)
            if ret == 200:
                self.test_signal.emit(0, rdata)
            if sdata != rdata:
                return False
        return True

    # 更新state显示
    def update_state(self, num, state):
        if 0 <= num < self.num_serial:
            self.rs_label[num].setText(state)