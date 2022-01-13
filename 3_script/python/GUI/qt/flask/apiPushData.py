import sys
from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QWidget

from api import *
import os
import cgitb
from flask import Flask, request
import json
import _thread
import time

# from test_tools.apiPush import *
app_ = Flask(__name__)
get_data_list = []


class apiWindow(QWidget, Ui_Form):
    get_Data = ""
    update = pyqtSignal(str)

    def __init__(self):
        super(apiWindow, self).__init__()
        self.setupUi(self)
        self.iptext.setText(HOST)
        self.portText.setText(str(PORT))
        self.urlText.setText(URL)
        self.startBtn.clicked.connect(self.startApi)
        self.endBtn.clicked.connect(self.stopApi)
        self.update.connect(self.setText)
        self.result = ""

    def startApi(self):
        _thread.start_new_thread(self.runFlask, ())

    def stopApi(self):
        # _thread.exit()
        self.textBrowser.clear()

    # @app_.route("/callBack", methods=["POST"])
    def check(self):
        # 默认返回内容
        return_dict = {'return_code': '200', 'return_info': '连接成功', 'result': True}
        # 获取传入的参数
        self.get_Data = request.get_data()
        # 传入的参数为bytes类型，需要转化成json
        self.get_Data = json.loads(self.get_Data)
        self.get_Data = json.dumps(self.get_Data, ensure_ascii=False)
        print('传入的参数：' + self.get_Data)
        self.update.emit(self.get_Data)
        return json.dumps(return_dict, ensure_ascii=False)

    def runFlask(self):
        app_.add_url_rule(URL, methods=["POST"], view_func=self.check)
        app_.run(host=HOST, port=PORT, debug=False)

    def setText(self, msg):
        self.result = self.result + msg + "\n"
        self.textBrowser.setText(self.result)


if __name__ == '__main__':
    # # 记录崩溃信息
    # log_dir = os.path.join(os.getcwd(), 'crash')
    # if not os.path.exists(log_dir):
    #     os.mkdir(log_dir)
    # cgitb.enable(format='text', logdir=log_dir)

    HOST = "0.0.0.0"
    PORT = 5000
    URL = "/callBack"

    app = QtWidgets.QApplication(sys.argv)
    window = apiWindow()
    window.show()
    sys.exit(app.exec_())
