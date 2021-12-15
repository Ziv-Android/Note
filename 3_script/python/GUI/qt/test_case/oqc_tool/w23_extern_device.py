# from oqc_tool import Ui_MainWindow
import _thread
import time

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QMessageBox

from c_factory import *
from oqc_tool.w233_extern_log import W233ExternLog
from oqc_tool.w231_extern_gpio import W231ExternGPIO
from oqc_tool.w232_extern_serial import W232ExternSerial
from oqc_tool.ui_w23_extern_device import Ui_W23ExternDevice


#
class W23ExternDevice(QtWidgets.QWidget, Ui_W23ExternDevice):
    name = "interface"
    auto_test_signal = pyqtSignal(str, str)

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm

        self.autotest_state = 0

        self.ext_gpio = W231ExternGPIO(self)
        self.pWidgetVLayout.addWidget(self.ext_gpio)

        self.ext_serial = W232ExternSerial(self)
        self.pWidgetVLayout.addWidget(self.ext_serial)

        self.ext_log = W233ExternLog(self)
        self.pWidgetVLayout.addWidget(self.ext_log)
        self.auto_test_signal.connect(self.test_case_update_state)

    def http_client_handle(self):
        return self.pwm.http_client_handle()

    def widget_init(self):
        # 产品相关
        cp, pro = self.pwm.get_product()
        self.ext_gpio.widget_init(cp.get_capacity_num(self.ext_gpio.name_reset),
                                  cp.get_capacity_num(self.ext_gpio.name_ioin),
                                  cp.get_capacity_num(self.ext_gpio.name_ioout))
        self.ext_serial.widget_init(cp.get_capacity_num(self.ext_serial.name))

        self.pTestCaseLWdg.clear()
        self.testcase = [
            'IO-测试',
            '复位按键',
            '串口通信',
            # '网口信息',
            '日志读取',
            '恢复出厂'
        ]
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)

    def autotest_stop(self):
        print('video autotest_stop')
        self.autotest_state = 5

    #
    def autotest_start(self, host, username, password):
        self.widget_init()
        print('extern start_autotest %s %s %s' % (host, username, password))
        if self.autotest_state == 1:
            print('has been in the test')
            return

        self.host = host
        self.username = username
        self.password = password


        try:
            self.autotest_state = 1
            _thread.start_new_thread(self.autotest_usercase_traversal,
                                     ("autotest", host, username, password,))
        except:
            print("can't start thread")

    # 更新QListWidget item显示
    def test_case_update_state(self, text, suc):
        print(text, suc)
        count = self.pTestCaseLWdg.count()
        for i in range(count):
            tt = self.pTestCaseLWdg.item(i).text()
            if tt.find(text) != -1:
                self.pTestCaseLWdg.item(i).setText(text + '\t\t' + suc)
                break

    # 自动
    def autotest_usercase_traversal(self, tname, host, username, password):
        print("extern autotest_usercase_traversal %s %s %s %s " % (tname, host, username, password))
        # 'IO-测试'
        i = 0
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_gpio.autotest_usercase_gpio()
        if not ret:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_state = 0
            return False
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '复位按键'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_gpio.autotest_usercase_reset()
        if not ret:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_state = 0
            return False
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '串口通信'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_serial.autotest_usercase()
        if not ret:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_state = 0
            return False
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '网口信息'
        # i = i+1
        # self.auto_test_signal.emit(self.testcase[i], '开始')
        # # ret = self.ext_serial.autotest_usercase(self.webc)
        # time.sleep(1)
        # if not ret:
        #     self.auto_test_signal.emit(self.testcase[i], '失败')
        #     self.autotest_state = 0
        #     return False
        # self.auto_test_signal.emit(self.testcase[i], '成功')

        # '日志读取'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        ret = self.ext_log.autotest_usercase()
        time.sleep(1)
        if not ret:
            self.auto_test_signal.emit(self.testcase[i], '失败')
            self.autotest_state = 0
            return False
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '恢复出厂'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        webc = self.http_client_handle()
        ret = c_factory(webc, 2)
        time.sleep(0.5)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        self.autotest_state = 0
