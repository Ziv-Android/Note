import logging
import random
import sys
import time

from PyQt5.QtWidgets import *


class MutilThreadDemo(QDialog):
    def __init__(self):
        super(MutilThreadDemo, self).__init__()

        self.setWindowTitle("线程异步测试实例")
        nameLb1 = QLabel('&Name', self)
        nameEd1 = QLineEdit(self)
        nameLb1.setBuddy(nameEd1)

        nameLb2 = QLabel('&Password', self)
        nameEd2 = QLineEdit(self)
        nameLb2.setBuddy(nameEd2)

        btnOk = QPushButton('&OK')
        btnCancel = QPushButton('&Cancel')

        mainLayout = QGridLayout(self)
        mainLayout.addWidget(nameLb1, 0, 0)
        mainLayout.addWidget(nameEd1, 0, 1, 1, 2)
        mainLayout.addWidget(nameLb2, 1, 0)
        mainLayout.addWidget(nameEd2, 1, 1, 1, 2)
        mainLayout.addWidget(btnOk, 2, 1)
        mainLayout.addWidget(btnCancel, 2, 2)

        btnOk.clicked.connect(self.startThread)

    def startThread(self):
        print("click")


def link_hovered():
    print("鼠标滑过标签，出发事件")


def link_clicked():
    print("鼠标点击标签，触发事件")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = MutilThreadDemo()
    win.show()
    sys.exit(app.exec())
