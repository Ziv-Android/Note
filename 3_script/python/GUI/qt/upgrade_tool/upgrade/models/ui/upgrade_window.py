#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

from ui_upgrade_window import Ui_MainWindow


class UpgradeWindow(QMainWindow, Ui_MainWindow):
    input_file_signal = pyqtSignal()
    download_file_signal = pyqtSignal()
    upgrade_signal = pyqtSignal()
    cancel_signal = pyqtSignal()
    table_cell_change = pyqtSignal()

    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setupUi(self)
        self.bindSignal()
        self.initData()

    def initData(self):
        # 总体信息
        self.table_head_message_change_callback()
        # 表头设置
        self.upgrade_detail_TableWidget.setHorizontalHeaderLabels(['序号', '序列号', '状态', '升级进度', '固件版本'])
        # 表单属性
        font = self.upgrade_detail_TableWidget.horizontalHeader().font()
        font.setBold(True)
        self.upgrade_detail_TableWidget.horizontalHeader().setFont(font)
        # self.upgrade_detail_TableWidget.horizontalHeader().setStyleSheet("QHeaderView::section{background:skyblue;}")
        self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(0, 40)
        self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(1, 200)
        self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(2, 200)
        self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(3, 200)
        self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(4, 200)
        # self.upgrade_detail_TableWidget.horizontalHeader().setHighlightSections(False)
        self.upgrade_detail_TableWidget.setRowCount(101)

        # self.upgrade_detail_TableWidget.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.Stretch)

    def bindSingle(self):
        # 导入文件
        self.input_file_Button.clicked.connect(self.input_file_signal)
        # 下载模板
        self.download_file_Button.clicked.connect(self.download_file_signal)
        # 升级/取消
        self.upgrade_Button.clicked.connect(self.upgrade_signal)
        self.cancel_Button.clicked.connect(self.cancel_signal)
        # 表单cell变化
        self.upgrade_detail_TableWidget.cellChanged.connect(self.table_cell_change)

