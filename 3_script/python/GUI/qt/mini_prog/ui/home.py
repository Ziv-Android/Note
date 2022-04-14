#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QMainWindow, QApplication
from ui_home import Ui_MainWindow


class HomeWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(HomeWindow, self).__init__()
        self.setupUi(self)


if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = HomeWindow()
    window.show()

    sys.exit(app.exec_())
