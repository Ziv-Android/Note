import cgitb
import os
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QFileDialog  # 工具常用的包
from PyQt5.Qt import QThread, pyqtSignal
from PyQt5 import QtGui, QtWidgets  # 上传图片用
from mqtt import Ui_Form
import paho.mqtt.client as mqtt
import json
import random
import _thread


class mqtt_tools(QMainWindow, Ui_Form):
    """
    万能工具
    """
    signal_jtxx = pyqtSignal(str)

    def __init__(self, parent=None):
        super(mqtt_tools, self).__init__(parent)
        self.setupUi(self)

        HOST = "106.52.198.107"
        PORT = 1884
        client_id = f'python-mqtt-{random.randint(100000000, 999999999)}'  # 客户端的唯一标识，全局唯一
        client = mqtt.Client(client_id)  # 定义client，可不用指定client_id，系统自动分配
        client.username_pw_set(username="thirdPartyAccount", password="147258")  # 定义连接mqtt服务器的用户名和密码
        client.connect(HOST, PORT, 60)  # 连接mqtt
        client.on_connect = self.on_connect  # 回调连接
        client.on_message = self.on_message  # 回调订阅消息
        client.on_subscribe = self.on_subscribe

        self.th = None
        self.client = client
        # 添加信号和槽。注意要执行的函数不加小括号()，必须在这里写了事件才会触发页面流程，
        # clicked信号一定要记住。clicked信号就是指鼠标左键按下然后释放时会发送信号，从而触发相应操作
        self.jtxx.setText('666')
        self.ljan.clicked.connect(self.connect_mqtt)
        self.jtks.clicked.connect(self.fhxxmqtt)
        self.signal_jtxx.connect(self.update_jtxxui)

    def on_connect(self, client, userdata, flags, rc):
        """
        连接成功后回调，0表示成功
        """
        print("on_connect result code =", rc)
        if rc != 0:
            print("Unexpected disconnection %s" % rc)
        client.subscribe('face/response', qos=1)  # 订阅消息，abcde为消息主题，必须写在这里
        client.subscribe("return/msg", qos=1)  # 订阅消息，abcde为消息主题，必须写在这里

    def on_message(self, client, userdata, msg):
        """
        接收到消息后回调
        """
        print("on_message topic:", msg.topic, "msg:", str(msg.payload.decode('utf-8')))
        with open('mqjtxx.txt', 'a', encoding="utf-8") as f:
            f.write(str(msg.payload.decode('utf-8')))

        self.signal_jtxx.emit(str(msg.payload.decode('utf-8')))
        print('结束')

    def on_subscribe(self, client, userdata, mid, granted_qos):
        """
        订阅消息成功后回调
        """
        print("on_subscribe: qos =", granted_qos)

    def fhxxmqtt(self):
        '''mqtt返回消息'''
        # while 1 < 2:
        # print(Runthread.clients)
        # self.t1 = self.jtzt.text()
        #
        #
        # txts = open('mqjtxx.txt')
        # txts = txts.read()
        # self.jtxx.setText(txts)
        print(self.clients)
        mqtt_tools.clients.loop_forever()
        QApplication.processEvents()

    def connect_mqtt(self):
        ''''''
        pass
        self.th = MqttClient(self)
        self.th.signal.connect(self.signal_jtxx)
        self.th.start()

    def push_msg(self):
        data = self.tsxx.toPlainText()
        param = json.dumps(data)

    #     self.clients.publish(self.tszt.text(), payload=param, qos=0)  # 发送消息

    def update_jtxxui(self, msg):
        self.jtxx.setText(msg)


class MqttClient(QThread):
    signal = pyqtSignal(str)

    def __init__(self, client):
        super().__init__()
        self.client = client.client

    def run(self):
        # 开始自动化执行接口
        print("MqttClient run")
        self.signal.emit("888888")
        self.client.loop_forever()


if __name__ == "__main__":
    # 记录崩溃信息
    log_dir = os.path.join(os.getcwd(), 'crash')
    if not os.path.exists(log_dir):
        os.mkdir(log_dir)
    cgitb.enable(format='text', logdir=log_dir)

    # 固定的，PyQt5程序都需要QApplication对象。sys.argv是命令行参数列表，确保程序可以双击运行
    app = QApplication(sys.argv)
    # 初始化
    myWin = mqtt_tools()
    # 将窗口控件显示在屏幕上
    myWin.show()
    # 程序运行，sys.exit方法确保程序完整退出。
    sys.exit(app.exec_())
