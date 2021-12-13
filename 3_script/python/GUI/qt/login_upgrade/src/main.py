#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time
import csv
import random
import re

import requests
from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt, QObject, QRunnable, QThread, QThreadPool, pyqtSignal, pyqtSlot
from PyQt5.QtGui import QBrush, QPalette
from PyQt5.QtWidgets import QFileDialog

from upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui

from libutils.SessionClient import *

total_data = []
empty_data = []
success_data = []
failed_data = []

url_sn_to_ip = "http://118.31.4.231:8000/pdns"

username = ""
password = ""
file_path = ""


class WorkerSignal(QObject):
    finished = pyqtSignal()
    cancel = pyqtSignal()
    progress = pyqtSignal(int, dict)

    def __init__(self):
        super(WorkerSignal, self).__init__()


class Worker(QRunnable):
    def __init__(self, name, _signal=None):
        super().__init__()
        self.thread_name = name
        self.signal = _signal
        self.setAutoDelete(True)
        print("Worker", "init", "创建Worker", name)

    def setData(self, i, _data):
        self.line = i
        self.data = _data
        print("Worker", "setData", self.line, self.data)

    def run(self):
        # param = {'sn': self.data['sn'], 'port': 80}
        # resp = requests.get(url_sn_to_ip, params=param)
        # print("Worker", "run", "step(1):getHost", resp.text)
        # if resp.status_code == 200:
        #     self.session_host = "http://" + resp.text
        # else:
        #     self.data['state'] = "序列号错误"
        #     self.signal.progress.emit(self.line, self.data)

        self.session_host = "http://192.168.1.88"
        client = SessionClient(self.session_host, username, password)
        client.login()
        print("Worker", "run", "step(2)login:", client.ses)
        client.info()
        print("Worker", "run", "step(3)info:", )
        state_code, content = client.update(file_path)
        print("Worker", "run", "step(4)update:", state_code, content)
        # client.upload()
        # print("Worker", "run", "step(3)upload:", )

        # client.close()
        # print("Worker", "run", "step(5)close:", resp.text)
        # for i in range(10):
        #     print("Worker", "run", f"threadName: {self.thread_name}", i)
        #     self.data['progress'] = str(i + 1) + "%"
        #     try:
        #         self.signal.progress.emit(self.line, self.data)
        #     except Exception as e:
        #         print("操作取消或程序异常退出")
        #         self.signal.cancel.emit()
        #     time.sleep(random.randint(500, 1500) / 1000)
        if state_code == 200:
            success_data.append(self.data)
        else:
            failed_data.append(self.data)
        print("Worker", "run", f"threadName: {self.thread_name}", "finish")
        self.signal.finished.emit()


class UpgradeThread(QThread):
    update_message = pyqtSignal()
    update_cancel = pyqtSignal()
    update_data = pyqtSignal(int, dict)
    '''
    通过线程，创建线程池
    '''
    def __init__(self):
        super(UpgradeThread, self).__init__()
        print("UpgradeThread", "init", "创建QThread线程，防止界面卡死")
        self.pool = QThreadPool.globalInstance()
        self.pool.setMaxThreadCount(100)

    def run(self):
        print("UpgradeThread", "run", "启动线程池")
        for index in range(len(total_data)):
            workerSignal = WorkerSignal()
            workerSignal.progress.connect(self.update_data)
            workerSignal.cancel.connect(self.update_cancel)
            workerSignal.finished.connect(self.update_message)
            runnable = Worker(str(index), workerSignal)
            runnable.setData(index, total_data[index])
            self.pool.start(runnable)

        self.pool.waitForDone()


# 升级窗口
class UpgradeWindow(QtWidgets.QMainWindow, Upgrade_Ui):
    # 定义信号
    upgrade_data_signal = pyqtSignal(int, dict)
    message_data_signal = pyqtSignal(str)
    finish_signal = pyqtSignal()

    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setup_ui()
        self.bind_signal()

    def setup_ui(self):
        self.setupUi(self)
        # 信息
        self.update_message()
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

    def bind_signal(self):
        print("UpgradeWindow", "bind_signal", "绑定信号")
        self.upgrade_data_signal.connect(self.update_data)
        self.finish_signal.connect(self.update_finish)

    def update_message(self):
        msg = "升级总数：%d 成功升级：%d 失败数量：%d" % (len(total_data), len(success_data), len(failed_data))
        print("UpgradeWindow", "update_message", "更新头部信息", msg)
        self.message_lineEdit.setText(msg)

    def add_data(self, items):
        len_item = len(items)
        row = self.upgrade_detail_TableWidget.rowCount() - 1
        print("UpgradeWindow", "add_data", "添加数据", len_item, row)
        for i in range(len_item):
            each_item = items[i]
            # print(each_item)
            if i > row:
                self.upgrade_detail_TableWidget.insertRow(i)
            self.update_data(i, each_item)

    def remove_data(self, line_num):
        print("UpgradeWindow", "remove_data", "删除数据(行)", line_num)
        self.upgrade_detail_TableWidget.removeRow(line_num)

    def update_data(self, line_num, data):
        # print("UpgradeWindow", "update_data", "修改数据:", line_num, data)
        # 设置行号
        item_index = QtWidgets.QTableWidgetItem(str(line_num + 1))
        item_index.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_index.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 0, item_index)
        # 设置sn
        item_sn = QtWidgets.QTableWidgetItem(str(data['sn']))
        item_sn.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 1, item_sn)
        # 设置状态
        item_state = QtWidgets.QTableWidgetItem(str(data['state']))
        item_state.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_state.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 2, item_state)
        # 设置进度
        item_progress = QtWidgets.QTableWidgetItem(str(data['progress']))
        item_progress.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_progress.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 3, item_progress)
        # 设置版本号
        item_version = QtWidgets.QTableWidgetItem(str(data['version']))
        item_version.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_version.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 4, item_version)

    def update_finish(self):
        print("UpgradeWindow", "update_finish", "更新完成")
        self.upgrade_Button.setEnabled(True)

    def get_username_password(self):
        print("UpgradeWindow", "get_username_password", "获取用户名密码")
        # 用户名/密码
        global username
        username = self.username_lineEdit.text()
        global password
        password = self.password_lineEdit.text()
        print("用户名/密码：", username, password)

    def download_template_file(self):
        print("UpgradeWindow", "download_template_file", "下载模板文件")
        with open("template.csv", 'w', encoding='utf-8') as openf:
            csv_write = csv.writer(openf)
            csv_head = ["SN"]
            csv_write.writerow(csv_head)

    def isLegalSn(self, sn):
        result = re.match(r"^[0-9a-fA-F]{8}-[0-9a-fA-F]{8}", sn) is not None
        print("UpgradeWindow", "isLegalSn", sn, result)
        return result

    def exec_upgrade(self):
        global total_data
        print("UpgradeWindow", "exec_upgrade", "执行升级")
        global file_path
        file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.bin)')
        print("UpgradeWindow", "exec_upgrade", file_path, file_format)
        if len(file_path) == 0:
            return

        # 数据清洗
        total_data = list(filter(lambda _item: self.isLegalSn(_item['sn']) is True, total_data))
        print("UpgradeWindow", "exec_upgrade", "数据清洗：", len(total_data))

        if len(total_data) <= 0:
            print("UpgradeWindow", "exec_upgrade", "待升级SN列表为空")
            return

        self.username_lineEdit.setText('admin')
        self.password_lineEdit.setText('admin')

        self.get_username_password()
        if len(username) == 0 or len(password) == 0:
            print("UpgradeWindow", "exec_upgrade", "用户名/密码错误")
            return

        self.upgrade_Button.setEnabled(False)

        self.upgradeThread = UpgradeThread()
        self.upgradeThread.update_data.connect(self.update_data)
        self.upgradeThread.update_message.connect(self.update_message)
        # self.upgradeThread.update_cancel.connect(self.update_message)
        self.upgradeThread.start()

    def exec_cancel(self):
        print("UpgradeWindow", "exec_cancel", "执行取消")
        self.close()

    def add_data_from_csv_file(self):
        global total_data
        print("UpgradeWindow", "add_data_from_csv_file")
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
                self.add_data(total_data)

    def read_data_from_init(self):
        global total_data
        print("UpgradeWindow", "read_data_from_init", "初始化数据")
        for i in range(0, 100):
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})

        self.add_data(total_data)

    def read_data_from_table(self):
        global total_data
        print("UpgradeWindow", "read_data_from_table")
        items = self.upgrade_detail_TableWidget.findItems('-')
        print("UpgradeWindow", "read_data_from_table", items)
        col_num = self.upgrade_detail_TableWidget.columnCount()
        print("UpgradeWindow", "read_data_from_table", col_num)
        self.upgrade_detail_TableWidget.currentColumn()
        # for i in range(col_num):
        #     total_data.append()
        # self.upgrade_detail_TableWidget.items()

    def read_data_from_csv(self, csv_iterator):
        global total_data
        print("UpgradeWindow", "read_data_from_cvs")
        # 数据清洗
        total_data = list(filter(lambda _item: self.isLegalSn(_item['sn']) is True, total_data))
        print("UpgradeWindow", "read_data_from_cvs", "数据清洗：", len(total_data))

        # 获取序列号list
        temp = []
        for _item in total_data:
            temp.append(_item['sn'])
        print("UpgradeWindow", "read_data_from_cvs", "原有sn", temp)

        # print("csv_iterator", csv_iterator)
        # 添加文件数据
        for cvs_line in csv_iterator:
            print("UpgradeWindow", "read_data_from_cvs", 'sn:', cvs_line, type(cvs_line))
            sn = cvs_line[0].strip()
            # 判断SN是否合法, 检查去重
            if self.isLegalSn(sn):
                if sn not in temp:
                    temp.append(sn)
                    total_data.append({'sn': sn, 'state': "", 'progress': "", 'version': ""})
        print("UpgradeWindow", "read_data_from_cvs", "数据文件导入：", len(total_data))

        self.update_message()

        # 空白填充
        while len(total_data) < 100:
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})
        print("UpgradeWindow", "read_data_from_cvs", "数据补足：", len(total_data))


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)

    home = UpgradeWindow()
    # 初始化数据/读取svc模板文件
    home.read_data_from_init()
    # 显示表格
    home.show()

    sys.exit(app.exec_())

# 参考资料
# Qt线程池问题：https://blog.csdn.net/weixin_38587278/article/details/106430250
