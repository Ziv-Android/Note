#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.mainwindow import CMainWindow
import sys
import cgitb

if __name__ == "__main__":
    # 记录崩溃信息
    log_dir = os.path.join(os.getcwd(), 'crash')
    if not os.path.exists(log_dir):
        os.mkdir(log_dir)
    cgitb.enable(format='text', logdir=log_dir)

    app = QtWidgets.QApplication(sys.argv)

    mwin = CMainWindow()
    # mwin.showMaximized()
    mwin.resize(1280, 800)
    mwin.show()

    sys.exit(app.exec_())
