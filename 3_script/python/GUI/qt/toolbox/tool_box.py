#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

from PyQt5.QtWidgets import QApplication
from xtools.main_window import TMainWindow

if __name__ == '__main__':
    print("tool_box:", sys.path)

    app = QApplication(sys.argv)

    window = TMainWindow()
    window.show()

    sys.exit(app.exec_())
