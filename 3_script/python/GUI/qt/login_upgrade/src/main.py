#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time

from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt
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
        self.upgradeDetail.horizontalHeader().resizeSection(0, 40)
        self.upgradeDetail.horizontalHeader().resizeSection(1, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(2, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(3, 200)
        self.upgradeDetail.horizontalHeader().resizeSection(4, 200)
        # self.upgradeDetail.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.Stretch)

    def add_data(self, items):
        len_item = len(items)
        print("添加数据", len_item)
        for i in range(len_item):
            each_item = items[i]
            row = self.upgradeDetail.rowCount()
            # print(row, len_item)
            # if row < len_item:
            self.upgradeDetail.insertRow(len_item - row)

            for j in range(len(each_item)):
                item = QtWidgets.QTableWidgetItem(str(items[i][j]))
                item.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
                self.upgradeDetail.setItem(row, j, item)

    def update_data(self):
        print("修改数据")

    def remove_data(self):
        print("删除数据")


def create_data():
    data = []
    for i in range(20):
        data.append([i + 1, str(101010001 + i), "在线", "10%", "13.1.0.20211110401"])
    return data


def main():
    app = QtWidgets.QApplication(sys.argv)
    home = UpgradeWindow()
    home.show()

    table = create_data()
    home.add_data(table)
    time.sleep(2)
    for i in range(len(table)):
        table[i][3] = "20%"
    home.add_data(table)

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
