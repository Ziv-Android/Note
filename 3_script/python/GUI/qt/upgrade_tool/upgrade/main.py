#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PyQt5.QtWidgets import QApplication
from models.window_main import MainWindow

if __name__ == "__main__":
    # 记录崩溃信息
    # log_dir = os.path.join(os.getcwd(), 'crash')
    # if not os.path.exists(log_dir):
    #     os.mkdir(log_dir)
    # cgitb.enable(format='text', logdir=log_dir)

    app = QApplication(sys.argv)

    home = MainWindow()
    home.show()

    sys.exit(app.exec_())
