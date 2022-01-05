#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

from ui_main_window import Ui_MainWindow


class TMainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(TMainWindow, self).__init__()
        self.setupUi(self)

