#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QWidget, QPushButton, QApplication, QGridLayout, QLabel
from PyQt5.QtCore import QTimer
import sys


class WinForm(QWidget):

    def __init__(self, parent=None):
        super(WinForm, self).__init__(parent)

        self.setWindowTitle("QTimer demo")
        self.label = QLabel('测试')
        self.startBtn = QPushButton('开始')
        self.endBtn = QPushButton('结束')

        layout = QGridLayout(self)

        # 初始化一个定时器
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.myFunction)  # 到达设定的时间后，执行槽函数代码

        layout.addWidget(self.label, 0, 0, 1, 2)
        layout.addWidget(self.startBtn, 1, 0)
        layout.addWidget(self.endBtn, 1, 1)

        # 连接按键操作和槽函数
        self.startBtn.clicked.connect(self.startTimer)
        self.endBtn.clicked.connect(self.endTimer)

        self.setLayout(layout)

    def startTimer(self):
        self.timer.start(5000)  # 5000 单位是毫秒， 即 5 秒
        self.label.setText('开始执行了-----')

    def endTimer(self):
        self.timer.stop()

    def myFunction(self):
        #         for i in range(10):
        #             self.label.setText(str(i) + ',')
        # 如果执行该代码的时间远远超过 5 秒的话： 使用下面的方法
        self.timer.stop()
        for i in range(100000000):  # 此代码远远超过 5 秒
            if i % 100 == 0:
                print(i)
        self.label.setText('这是很长的代码')
        self.timer.start()  # 此时， start 中不要加任何的时间


if __name__ == "__main__":
    app = QApplication(sys.argv)
    form = WinForm()
    form.show()
    sys.exit(app.exec_())