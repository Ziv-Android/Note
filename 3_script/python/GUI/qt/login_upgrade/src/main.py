#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time

from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt, QThread, pyqtSignal
from PyQt5.QtGui import QBrush, QPalette
from upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui


# 升级窗口
class UpgradeWindow(QtWidgets.QMainWindow, Upgrade_Ui):
    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setupUi(self)
        self.upgradeDetail.setHorizontalHeaderLabels(['序号', '序列号', '状态', '升级进度', '固件版本'])
        font = self.upgradeDetail.horizontalHeader().font()
        font.setBold(True)
        self.upgradeDetail.horizontalHeader().setFont(font)
        # self.upgradeDetail.horizontalHeader().setBackgroundRole(QPalette.ColorRole)
        self.upgradeDetail.horizontalHeader().resizeSection(0, 40)
        self.upgradeDetail.horizontalHeader().resizeSection(1, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(2, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(3, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(4, 200)
        self.upgradeDetail.setRowCount(101)
        # self.upgradeDetail.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.Stretch)

    def add_data(self, items):
        len_item = len(items)
        row = self.upgradeDetail.rowCount() - 1
        print("添加数据", len_item, row)
        for i in range(len_item):
            each_item = items[i]
            print(each_item)
            if i > row:
                self.upgradeDetail.insertRow(i)
            self.update_data(i, each_item)

    def remove_data(self, line_num):
        print("删除数据(行)", line_num)
        self.upgradeDetail.removeRow(line_num)

    def update_data(self, line_num, data):
        print("修改数据:", line_num, data)
        for j in range(len(data)):
            item = QtWidgets.QTableWidgetItem(str(data[j]))
            item.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
            self.upgradeDetail.setItem(line_num, j, item)
            if j != 1:
                item.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)


class UpgradeThread(QThread):
    upgrade_data = pyqtSignal(int, list)

    def run(self):
        self.read_data_from_cvs()
        line_index = 0
        while True:
            print("线程更新数据")
            for data in total_data:
                self.upgrade_data.emit(line_index, data)
                if 

            time.sleep(1)


total_data = []


def read_data_from_cvs():
    print("初始化数据")
    for i in range(1, 101):
        total_data.append([str(i), str(101010000 + i), "在线", "10%", "13.1.0.20211110401"])


def main():
    app = QtWidgets.QApplication(sys.argv)
    home = UpgradeWindow()
    # 初始化数据/读取svc模板文件
    read_data_from_cvs()
    home.add_data(total_data)
    # 启动更新线程
    update_data_thread = UpgradeThread()
    update_data_thread.upgrade_data.connect(home.update_data)
    update_data_thread.start()
    # 显示表格
    home.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
