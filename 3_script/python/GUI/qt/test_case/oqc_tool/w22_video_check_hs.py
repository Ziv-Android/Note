# from oqc_tool import Ui_MainWindow
import ctypes
import time
import _thread
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt, QThread, pyqtSignal

from oqc_tool import *
from oqc_tool.cfg_factory_param_hs import *
from oqc_tool.ui_w22_video_check_hs import Ui_W22VideoCheck


#
from oqc_tool.w221_video_ircut import W221VideoIRCUT
from oqc_tool.w222_video_led import W222VideoLed
from oqc_tool.w223_video_lens import W223VideoLens
from oqc_tool.w224_video_ptz import W224VideoPTZ


class W22VideoCheck(QtWidgets.QWidget, Ui_W22VideoCheck):
    name = 'video'
    auto_test_signal = pyqtSignal(str, str)  # 自定义信号对象。参数str就代表这个信号可以传一个字符串

    # config:需要测试的内容; hs=high side
    def __init__(self, pwm, config="hs_lens_ircut_ptz"):
        super().__init__()
        self.setupUi(self)

        self.pwm = pwm
        self.sdk_hdl = 0
        self.vdo_hdl = 0
        self.autotest_state = 0    # 0=未开始,1=开始,5=停止,8=完成

        self.usercase = {}
        self.config = config
        self.auto_test_signal.connect(self.test_case_update_state)

        self.vdo_ircut = W221VideoIRCUT(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ircut)

        self.vdo_led = W222VideoLed(self)
        self.pTestCaseVLayout.addWidget(self.vdo_led)

        self.vdo_lens = W223VideoLens(self)
        self.pTestCaseVLayout.addWidget(self.vdo_lens)

        self.vdo_ptz = W224VideoPTZ(self)
        self.pTestCaseVLayout.addWidget(self.vdo_ptz)

        self.pTestCaseLWdg.itemDoubleClicked.connect(self.testcase_item_doubleclick)

    #
    def close_sdk_hdl(self):
        print('close_sdk_hdl')
        if self.sdk_hdl != 0:
            print("objdll.VzLPRClient_StopRealPlay %d vdo_hdl %d" % (self.sdk_hdl, self.vdo_hdl))
            if self.vdo_hdl:
                objdll.VzLPRClient_StopRealPlay(self.vdo_hdl)
                self.vdo_hdl = 0
            objdll.VzLPRClient_Close(self.sdk_hdl)
            self.pShowVideoLabel.clear()
            self.sdk_hdl = 0

    #
    def show_video(self, host, username, password):
        print('set_dev_host entry %s %s %s' % (host, username, password))

        try:
            self.close_sdk_hdl()
            self.sdk_hdl = objdll.VzLPRClient_Open(host.encode('utf-8'), 80,
                                                   username.encode('utf-8'),
                                                   password.encode('utf-8'))
            print("objdll.VzLPRClient_OpenV3 %d" % self.sdk_hdl)
            if self.sdk_hdl != 0:
                self.vdo_hdl = objdll.VzLPRClient_StartRealPlay(self.sdk_hdl, int(self.pShowVideoLabel.winId()))
                print("objdll.VzLPRClient_StartRealPlay %d vdo_hdl %d" % (self.sdk_hdl, self.vdo_hdl))
        except:
            print("can't show video")

    def http_client_handle(self):
        return self.pwm.http_client_handle();

    # 自动测试
    def widget_init(self):
        self.pTestCaseLWdg.clear()
        self.testcase = [
            '镜头配置',
            '定制协议',
            '云台复位1',
            '镜头最小焦1',
            '镜头最大焦',
            'IRCUT夜间',
            'IRCUT白天',
            '云台-上',
            '云台-下',
            '云台复位2',
            '云台-左',
            '云台-右',
            '云台复位3',
            '镜头最小焦2',
            '补光灯'
        ]
        for tt in self.testcase:
            self.pTestCaseLWdg.addItem(tt)

    def testcase_item_doubleclick(self, item):
        tt = item.text()
        if tt == '镜头配置':
            self.lens_config()
        elif tt == '定制协议':
            self.protocol_config()

    # 产品
    # 定制协议
    def protocol_config(self):
        print('protocol_config')
        cc, cus = self.pwm.get_customer()
        pname = cc.get_conf_pname(cus)
        if pname == '':
            print("don't need set protocol")
            return
        webc = self.http_client_handle()
        cfg_factory_param_customer(webc,
                                   cc.get_conf_pname(cus),
                                   cc.get_conf_library(cus))

    # 镜头
    # 镜头配置
    def lens_config(self):
        print("lens_config")
        cp, pro = self.pwm.get_product()
        print(cp.get_desc())
        webc = self.http_client_handle()
        cfg_factory_param_product(webc,
                                  cp.get_capacity_num('lens'),
                                  cp.get_capacity_num('dlens'))

    def autotest_stop(self):
        print('video autotest_stop')
        self.autotest_state = 5

    #
    def autotest_start(self, host, username, password):
        self.widget_init()
        print('video start_autotest %s %s %s' % (host, username, password))
        if self.autotest_state == 1:
            print('has been in the test')
            self.autotest_state = 5
            return

        self.autotest_state = 1
        try:
            self.show_video(host, username, password)
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
        print("video autotest_usercase_traversal %s %s %s %s " % (tname, host, username, password))

        # '镜头配置'
        i = 0
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.lens_config()
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '定制协议'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.protocol_config()
        self.auto_test_signal.emit(self.testcase[i], '成功')
        time.sleep(1)

        # '云台复位'
        i = i+1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ptz.ptz_reset()
        time.sleep(15)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头最小焦'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_lens.lens_zoom_out()
        time.sleep(5)
        self.vdo_lens.lens_zoom_out()
        self.vdo_lens.lens_auto_focus()
        time.sleep(30)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头最大焦'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_lens.lens_zoom_in()
        time.sleep(3)
        self.vdo_lens.lens_zoom_in()
        self.vdo_lens.lens_auto_focus()
        time.sleep(30)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IRCUT夜间'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ircut.ircut_night()
        time.sleep(1)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # 'IRCUT白天'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ircut.ircut_day()
        time.sleep(1)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-上'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        time.sleep(1)
        self.vdo_ptz.ptz_up()
        time.sleep(8)
        self.vdo_ptz.ptz_up()
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-下'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        time.sleep(2)
        self.vdo_ptz.ptz_down()
        time.sleep(16)
        self.vdo_ptz.ptz_down()
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台复位1'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        time.sleep(1)
        self.vdo_ptz.ptz_reset()
        time.sleep(15)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-左'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ptz.ptz_left()
        time.sleep(8)
        self.vdo_ptz.ptz_left()
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台-右'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ptz.ptz_right()
        time.sleep(16)
        self.vdo_ptz.ptz_right()
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '云台复位2'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_ptz.ptz_reset()
        time.sleep(15)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '镜头最小焦1'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_lens.lens_zoom_out()
        time.sleep(5)
        self.vdo_lens.lens_zoom_out()
        self.vdo_lens.lens_auto_focus()
        time.sleep(30)
        self.auto_test_signal.emit(self.testcase[i], '成功')

        # '补光灯'
        i = i + 1
        self.auto_test_signal.emit(self.testcase[i], '开始')
        self.vdo_led.led_ctrl(10)
        time.sleep(1)
        self.vdo_led.led_ctrl(50)
        time.sleep(1)
        self.vdo_led.led_ctrl(100)
        time.sleep(1)
        self.vdo_led.led_ctrl(-1)
        time.sleep(1)
        self.auto_test_signal.emit(self.testcase[i], '成功')
        self.autotest_state = 0


