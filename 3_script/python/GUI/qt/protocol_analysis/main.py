#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys

from PyQt5.QtWidgets import QApplication
from ui.home import HomeWindow


if __name__ == '__main__':
    app = QApplication(sys.argv)

    path = os.path.join(os.getcwd(), "config", "ziv.ini")

    window = HomeWindow(path)
    window.show()

    sys.exit(app.exec_())
