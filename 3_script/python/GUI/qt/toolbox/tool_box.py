#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("tool_box:", sys.modules)
import sys

from PyQt5.QtWidgets import QApplication
from tools.main_window import TMainWindow

if __name__ == '__main__':
    app = QApplication(sys.argv)

    window = TMainWindow()
    window.show()

    sys.exit(app.exec_())
