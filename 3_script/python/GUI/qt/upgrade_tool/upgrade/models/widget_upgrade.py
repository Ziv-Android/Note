#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtCore import Qt, QAbstractTableModel, pyqtSignal
from PyQt5.QtWidgets import QWidget
from .ui.ui_widget_upgrade import Ui_UpgradeWidget


class UpgradeWidget(QWidget, Ui_UpgradeWidget):
    input_file_signal = pyqtSignal()
    download_file_signal = pyqtSignal()
    upgrade_signal = pyqtSignal()
    cancel_signal = pyqtSignal()
    # table_cell_change = pyqtSignal()
    # table_double_clicked = pyqtSignal()

    def __init__(self, ui_parent=None):
        super().__init__()
        self.pwd = ui_parent
        self.setupUi(self)
        # self.initUiConfig()
        self.bindSignal()

    def bindSignal(self):
        # 导入文件
        self.input_file_Button.clicked.connect(self.input_file_signal)
        # 下载模板
        self.download_file_Button.clicked.connect(self.download_file_signal)
        # 升级/取消
        self.upgrade_Button.clicked.connect(self.upgrade_signal)
        self.cancel_Button.clicked.connect(self.cancel_signal)
        # 表单cell变化
        # self.tableView.doubleClicked.connect(self.table_double_clicked)
        # self.tableView.cellChanged.connect(self.table_cell_change)

    #
    # def initUiConfig(self):
    #     pass
    #     # 总体信息
    #     self.table_head_message_change_callback()
    #     # 表头设置
    #     self.upgrade_detail_TableWidget.setHorizontalHeaderLabels(['序号', '序列号', '状态', '升级进度', '固件版本'])
    #     # 表单属性
    #     font = self.upgrade_detail_TableWidget.horizontalHeader().font()
    #     font.setBold(True)
    #     self.upgrade_detail_TableWidget.horizontalHeader().setFont(font)
    #     # self.upgrade_detail_TableWidget.horizontalHeader().setStyleSheet("QHeaderView::section{background:skyblue;}")
    #     self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(0, 40)
    #     self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(1, 200)
    #     self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(2, 200)
    #     self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(3, 200)
    #     self.upgrade_detail_TableWidget.horizontalHeader().resizeSection(4, 200)
    #     # self.upgrade_detail_TableWidget.horizontalHeader().setHighlightSections(False)
    #     self.upgrade_detail_TableWidget.setRowCount(101)
    #
    #     # self.upgrade_detail_TableWidget.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.Stretch)


class UpgradeTableModel(QAbstractTableModel):
    def __init__(self, data):
        QAbstractTableModel.__init__(self)
        self._data = data

    # 列
    def rowCount(self, parent=None):
        return self._data.shape[0]

    # 行
    def columnCount(self, parent=None):
        return self._data.shape[1]

    # 显示数据
    def data(self, index, role=Qt.DisplayRole):
        if index.isValid():
            if role == Qt.DisplayRole:
                return str(self._data.iloc[index.row(), index.column()])
        return None

    # 显示行和列头
    def headerData(self, col, orientation, role):
        if orientation == Qt.Horizontal and role == Qt.DisplayRole:
            return self._data.columns[col]
        elif orientation == Qt.Vertical and role == Qt.DisplayRole:
            return self._data.axes[0][col]
        return None

# https://blog.csdn.net/islinyoubiao/article/details/105577081

import pandas
import os

path_config = os.path.join(os.path.abspath('..'), "config")
if not os.path.exists(path_config):
    os.makedirs(path_config)
filename = os.path.join(path_config, "template.csv")

df = pandas.read_csv(filename)
print(df)
