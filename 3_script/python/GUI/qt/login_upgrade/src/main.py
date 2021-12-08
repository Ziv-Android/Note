#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time
import csv
import queue

from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt, QThread, pyqtSignal, pyqtSlot
from PyQt5.QtGui import QBrush, QPalette
from PyQt5.QtWidgets import QFileDialog

from upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui


# 升级线程
class UpgradeThread(QThread):
    # upgrade_data = pyqtSignal(int, dict)
    upgrade_data = pyqtSignal()

    def run(self):
        count = 0
        while True:
            # currentSn = self.queue.get()
            print("线程更新数据", count)
            # self.upgrade_data.emit(1, {'sn': "1h1gstav-qu12oj3g", 'state': "升级中", 'progress': ("%d %" % count), 'version': "1.0"})
            self.upgrade_data.emit()
            count += 1
            # if self.queue.empty():
            #     break
            # self.queue.task_down()
            time.sleep(1)


# 升级窗口
class UpgradeWindow(QtWidgets.QMainWindow, Upgrade_Ui):
    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setupUi(self)
        # 信息
        self.message_lineEdit.setText("升级总数：0 成功升级：0 失败数量：0")
        # 导入文件
        self.input_file_Button.clicked.connect(self.add_data_from_csv_file)
        # 下载模板
        self.download_file_Button.clicked.connect(self.download_template_file)
        # 升级/取消
        self.upgrade_Button.clicked.connect(self.exec_upgrade)
        self.cancel_Button.clicked.connect(self.exec_cancel)
        # 表头设置
        self.upgrade_detail_TableWidget.setHorizontalHeaderLabels(['序号', '序列号', '状态', '升级进度', '固件版本'])
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
        self.total_data = []
        self.queue_sn = queue.Queue()

    def get_username_password(self):
        # 用户名/密码
        self.username = self.username_lineEdit.text()
        self.password = self.password_lineEdit.text()
        print("用户名/密码：", self.username, self.password)

    def download_template_file(self):
        print("下载模板文件")
        with open("template.csv", 'w', encoding='utf-8') as openf:
            csv_write = csv.writer(openf)
            csv_head = ["序列号"]
            csv_write.writerow(csv_head)

    def exec_upgrade(self):
        print("执行升级")
        # 数据清洗
        self.total_data = list(filter(lambda _item: _item['sn'].isnumeric() == True, self.total_data))
        print("read_data_from_cvs", "数据清洗：", len(self.total_data))
        # 获取数据
        # for _item in self.total_data:
        #     self.queue_sn.put(_item['sn'])
        # print(self.queue_sn)

        # update_data_thread = UpgradeThread()
        # update_data_thread.upgrade_data.connect(self.update_data)
        # update_data_thread.start()
        # for i in range(4):
        #     # 启动更新线程
        #     update_data_thread = UpgradeThread(self.queue_sn)
        #     update_data_thread.upgrade_data.connect(self.update_data)
        #     update_data_thread.start()

    def exec_cancel(self):
        print("执行取消")
        self.close()

    def add_data_from_csv_file(self):
        file_path = self.lineEdit_filePath.text()
        file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', file_path, 'Excel files(*.csv)')
        if file_path == '':
            pass
        else:
            print(file_path, file_format)
            self.lineEdit_filePath.setText(file_path)
            with open(file_path, "r", encoding='utf-8') as openf:
                sn_file = csv.reader(openf)
                # print("cvs文件数据：", list(sn_file))
                self.read_data_from_csv(sn_file)
                self.add_data(self.total_data)

    def read_data_from_init(self):
        print("初始化数据", "read_data_from_init")
        for i in range(0, 100):
            self.total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})

        self.add_data(self.total_data)

    def read_data_from_csv(self, csv_iterator):
        print("read_data_from_cvs")
        # 数据清洗
        self.total_data = list(filter(lambda _item: _item['sn'].isnumeric()==True, self.total_data))
        print("read_data_from_cvs", "数据清洗：", len(self.total_data))

        # 获取序列号list
        temp = []
        for _item in self.total_data:
            temp.append(_item['sn'])
        print("原有sn", temp)

        # print("csv_iterator", csv_iterator)
        # 添加文件数据
        for cvs_line in csv_iterator:
            print('sn:', cvs_line, type(cvs_line))
            sn = cvs_line[0].strip()
            # 判断SN是否合法, 检查去重
            if sn.isnumeric() and sn not in temp:
                temp.append(sn)
                self.total_data.append({'sn': sn, 'state': "", 'progress': "", 'version': ""})
        print("read_data_from_cvs", "数据文件导入：", len(self.total_data))

        # 空白填充
        while len(self.total_data) < 100:
            self.total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})
        print("read_data_from_cvs", "数据补足：", len(self.total_data))

    def add_data(self, items):
        len_item = len(items)
        row = self.upgrade_detail_TableWidget.rowCount() - 1
        print("添加数据", len_item, row)
        for i in range(len_item):
            each_item = items[i]
            # print(each_item)
            if i > row:
                self.upgrade_detail_TableWidget.insertRow(i)
            self.update_data(i, each_item)

    def remove_data(self, line_num):
        print("删除数据(行)", line_num)
        self.upgrade_detail_TableWidget.removeRow(line_num)

    def update_data(self, line_num, data):
        # print("修改数据:", line_num, data)
        # 设置行号
        item_index = QtWidgets.QTableWidgetItem(str(line_num + 1))
        item_index.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 0, item_index)
        # 设置sn
        item_sn = QtWidgets.QTableWidgetItem(str(data['sn']))
        item_sn.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 1, item_sn)
        item_sn.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        # 设置状态
        item_state = QtWidgets.QTableWidgetItem(str(data['state']))
        item_state.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 2, item_state)
        # 设置进度
        item_progress = QtWidgets.QTableWidgetItem(str(data['progress']))
        item_progress.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 3, item_progress)
        # 设置版本号
        item_version = QtWidgets.QTableWidgetItem(str(data['version']))
        item_version.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 4, item_version)


def main():
    app = QtWidgets.QApplication(sys.argv)
    home = UpgradeWindow()

    # 初始化数据/读取svc模板文件
    home.read_data_from_init()

    update_data_thread = UpgradeThread()
    update_data_thread.start()

    # 显示表格
    home.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
