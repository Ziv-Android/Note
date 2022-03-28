#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import ctypes


class Ui(QMainWindow):
    def __init__(self):
        super(Ui, self).__init__()
        self.setWindowTitle("测试显示")
        self.setFixedSize(800, 600)
        self.centralWidget = QWidget()
        self.setCentralWidget(self.centralWidget)
        # Set the layout
        layout = QVBoxLayout()
        # layout.addWidget(self.textBrowser)
        # layout.addStretch()
        self.centralWidget.setLayout(layout)

        path = os.path.realpath(os.path.join(os.getcwd(), "vzsdk"))
        print(path)
        os.environ['path'] += f';{path}'
        objdll = ctypes.cdll.LoadLibrary('./vzsdk/VzLPRSDK.dll')
        ret = objdll.VzLPRClient_Setup()
        print('load dll:', ret)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = Ui()
    win.show()
    sys.exit(app.exec())
