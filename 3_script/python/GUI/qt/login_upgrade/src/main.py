#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time
import csv
import queue

from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt, QObject, QRunnable, QThread, QThreadPool, pyqtSignal, pyqtSlot
from PyQt5.QtGui import QBrush, QPalette
from PyQt5.QtWidgets import QFileDialog

from upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui

total_size = 0
success_size = 0
failed_size = 0


class TaskThread(QRunnable):
    '''
    实际任务执行的核心，结果发送至槽
    '''
    communication = None
    line = 0
    data = None

    def __init__(self):
        super(TaskThread, self).__init__()

    def run(self):
        print("TaskThread", "run", "执行实际任务", self.data['sn'])
        progress = 0
        while progress <= 100:
            print("TaskThread", "run", "执行实际任务", "progress", progress)
            progress += 1
            # self.data['state'] = "升级中"
            # 模拟耗时操作
            time.sleep(1)

            # self.data['progress'] = str(progress) + "%"
            # self.communication.upgrade_data_signal.emit(self.line, self.data)

        # message = "升级总数：%d 成功升级：%d 失败数量：%d" % (total_size, success_size, failed_size)
        # self.communication.message_data_signal.emit(message)

    def transfer(self, total_size, line, data, communication):
        print("TaskThread", "transfer", "初始化线程数据", line)
        self.communication = communication
        self.total_size = total_size
        self.line = line
        self.data = data
        # 初始化数据
        self.data['state'] = "在线"
        self.data['progress'] = "0%"
        self.data['version'] = "1.0.1.202112091514"
        print("TaskThread", "transfer", "data type: ", type(self.data))
        self.communication.upgrade_data_signal.emit(self.line, self.data)


class ThreadPoolHelper(QObject):
    '''
    线程池帮助类，定义任务，绑定线程
    '''
    communication = None

    def __init__(self, communication):
        super().__init__()
        print("ThreadPoolHelper", "init", "创建QThreadPool")
        self.threadpool = QThreadPool()
        self.threadpool.globalInstance()
        self.threadpool.setMaxThreadCount(20)
        self.communication = communication

    def startPool(self):
        print("ThreadPoolHelper", "startPool", "启动TaskThread")
        total_size = len(self.communication.total_data)
        for line in range(total_size):
            data_item = self.communication.total_data[line]
            task_thread = TaskThread()
            task_thread.transfer(total_size, line, data_item, self.communication)
            task_thread.setAutoDelete(True)
            self.threadpool.start(task_thread)

        self.threadpool.waitForDone()
        self.communication.finish_signal.emit()

class WorkerThread(QThread):
    '''
    线程池管理线程
    '''
    def __init__(self, communication):
        super(WorkerThread, self).__init__()
        print("WorkerThread", "init", "创建ThreadPoolHelper")
        self.threadPoolHelper = ThreadPoolHelper(communication)

    def run(self):
        print("WorkerThread", "run", "启动QThread")
        '''
        启动线程池
        '''
        self.threadPoolHelper.startPool()


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
        self.total_data = []
        # self.queue_sn = queue.Queue()

    def setup_ui(self):
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

    def bind_signal(self):
        print("UpgradeWindow", "bind_signal", "绑定信号")
        self.upgrade_data_signal.connect(self.update_data)
        self.message_data_signal.connect(self.update_message)
        self.finish_signal.connect(self.update_finish)

    def update_message(self, msg):
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
        self.username = self.username_lineEdit.text()
        self.password = self.password_lineEdit.text()
        print("用户名/密码：", self.username, self.password)

    def download_template_file(self):
        print("UpgradeWindow", "download_template_file", "下载模板文件")
        with open("template.csv", 'w', encoding='utf-8') as openf:
            csv_write = csv.writer(openf)
            csv_head = ["SN"]
            csv_write.writerow(csv_head)

    def exec_upgrade(self):
        print("UpgradeWindow", "exec_upgrade", "执行升级")
        self.upgrade_Button.setEnabled(False)
        # 数据清洗
        self.total_data = list(filter(lambda _item: _item['sn'].isnumeric() == True, self.total_data))
        print("UpgradeWindow", "exec_upgrade", "数据清洗：", len(self.total_data))
        # 获取数据
        # for _item in self.total_data:
        #     self.queue_sn.put(_item['sn'])
        # print(self.queue_sn)

        workerThread = WorkerThread(self)
        workerThread.start()
        workerThread.wait()

    def exec_cancel(self):
        print("UpgradeWindow", "exec_cancel", "执行取消")
        self.close()

    def add_data_from_csv_file(self):
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
                self.add_data(self.total_data)

    def read_data_from_init(self):
        print("UpgradeWindow", "read_data_from_init", "初始化数据")
        for i in range(0, 100):
            self.total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})

        self.add_data(self.total_data)

    def read_data_from_csv(self, csv_iterator):
        print("UpgradeWindow", "read_data_from_cvs")
        # 数据清洗
        self.total_data = list(filter(lambda _item: _item['sn'].isnumeric()==True, self.total_data))
        print("UpgradeWindow", "read_data_from_cvs", "数据清洗：", len(self.total_data))

        # 获取序列号list
        temp = []
        for _item in self.total_data:
            temp.append(_item['sn'])
        print("UpgradeWindow", "read_data_from_cvs", "原有sn", temp)

        # print("csv_iterator", csv_iterator)
        # 添加文件数据
        for cvs_line in csv_iterator:
            print('sn:', cvs_line, type(cvs_line))
            sn = cvs_line[0].strip()
            # 判断SN是否合法, 检查去重
            if sn.isnumeric() and sn not in temp:
                temp.append(sn)
                self.total_data.append({'sn': sn, 'state': "", 'progress': "", 'version': ""})
        print("UpgradeWindow", "read_data_from_cvs", "数据文件导入：", len(self.total_data))

        global total_size
        total_size = len(self.total_data)
        message = "升级总数：%d 成功升级：%d 失败数量：%d" % (total_size, success_size, failed_size)
        self.message_data_signal.emit(message)

        # 空白填充
        while len(self.total_data) < 100:
            self.total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})
        print("UpgradeWindow", "read_data_from_cvs", "数据补足：", len(self.total_data))


def main():
    app = QtWidgets.QApplication(sys.argv)

    home = UpgradeWindow()
    # 初始化数据/读取svc模板文件
    home.read_data_from_init()
    # 显示表格
    home.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

# 参考资料
# Qt线程池问题：https://blog.csdn.net/weixin_38587278/article/details/106430250
