#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *


class Loading_Mask_Widget(QWidget):
    def __init__(self):
        super(Loading_Mask_Widget, self).__init__()
        # # 设置窗口无边框|对话框|置顶模式 |
        # self.setWindowFlags(Qt.FramelessWindowHint | Qt.QDialog |Qt.WindowStaysOnTopHint | Qt.CustomizeWindowHint)
        self.setWindowFlag(Qt.FramelessWindowHint)  # 隐藏边框
        self.setWindowFlags(Qt.WindowStaysOnTopHint)  # 置顶
        self.setWindowFlags(Qt.CustomizeWindowHint)  # 去标题栏
        # # 设置背景透明
        # self.setAttribute(Qt.WA_TranslucentBackground)
        # 设置窗口基础类型
        self.resize(800, 100)  # 设置加载界面的大小
        self.move(200, 200)  # 移动加载界面到主窗口的中心
        # self.setStyleSheet("background-color: write;")
        # self.setStyleSheet("background-color: transparent;")
        self.initUI()

    def initUI(self):
        # 加载动画画面
        self.loading_gif = QMovie('loading_e.gif')
        self.loading_label = QLabel(self)
        # self.loading_label.setStyleSheet("background-color: transparent;")
        self.loading_label.setMovie(self.loading_gif)
        self.loading_gif.start()


if __name__ == "__main__":
    # 创建一个 Application
    app = QApplication(sys.argv)
    # 展示界面
    view = Loading_Mask_Widget()
    view.show()
    # 执行 event loop
    sys.exit(app.exec_())
