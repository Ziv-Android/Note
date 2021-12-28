#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.mainwindow import CMainWindow

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)

    mwin = CMainWindow()
    # mwin.showMaximized()
    mwin.resize(1280, 800)
    mwin.show()

    sys.exit(app.exec_())
