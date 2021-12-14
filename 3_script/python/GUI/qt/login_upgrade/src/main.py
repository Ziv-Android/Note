#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
import time
import csv
import random
import re
import json

import requests
from PyQt5 import QtWidgets
from PyQt5.QtCore import Qt, QObject, QRunnable, QThread, QThreadPool, pyqtSignal, pyqtSlot
from PyQt5.QtGui import QBrush, QPalette, QStandardItemModel
from PyQt5.QtWidgets import QFileDialog

from upgrade.UpgradeWindow import Ui_MainWindow as Upgrade_Ui

from libutils.SessionClient import *

# 序列号list
temp = []
total_data = []
failed_data = []
success_data = []

url_sn_to_ip = "http://118.31.4.231:8000/pdns"

username = ""
password = ""
file_path = ""

count_active = 0


class WorkerSignal(QObject):
    finished = pyqtSignal()
    active_count = pyqtSignal(int)
    progress = pyqtSignal(int, dict)

    def __init__(self):
        super(WorkerSignal, self).__init__()


class Worker(QRunnable):
    def __init__(self, name, _signal=None):
        super().__init__()
        self.thread_name = "worker_thread_%s" % name
        self.signal = _signal
        self.setAutoDelete(True)
        print("Worker", "init", "创建Worker", self.thread_name)
        self.line = -1
        self.data = None

    def setData(self, i, _data):
        self.line = i
        self.data = _data
        print("Worker", "setData", self.line, self.data)

    def progress_change(self, monitor):
        _progress = round(monitor.bytes_read / monitor.len * 100, 2)
        # print("Worker", "progress_change", _progress)
        self.data['progress'] = str(_progress) + "%"
        self.signal.progress.emit(self.line, self.data)

    def run(self):
        self.signal.active_count.emit(1)
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
        info_json = client.login()
        json_obj = json.loads(info_json)
        state_code = json_obj['state']
        if state_code == 200:
            self.data['state'] = "在线"
        else:
            self.data['state'] = "离线"
        print("Worker", "run", "step(2)login:", state_code)

        info_json = client.info()
        json_obj = json.loads(info_json)
        version = json_obj['body']['soft_ver']
        print("Worker", "run", "step(3)info", "version:", version)
        self.data['version'] = version
        self.signal.progress.emit(self.line, self.data)
        time.sleep(0.5)

        state_code, content = client.update(file_path, self.progress_change)
        print("Worker", "run", "step(4)update:", state_code, content)
        client.close()

        if state_code == 200:
            self.data['state'] = "已升级"
            exist = False
            for _item in success_data:
                if _item['sn'] == self.data['sn']:
                    exist = True
            if not exist:
                success_data.append(self.data)
        else:
            self.data['state'] = "不可升级"
            exist = False
            for _item in failed_data:
                if _item['sn'] == self.data['sn']:
                    exist = True
            if not exist:
                failed_data.append(self.data)

        self.signal.progress.emit(self.line, self.data)
        self.signal.active_count.emit(-1)
        self.signal.finished.emit()
        print("Worker", "run", f"threadName: {self.thread_name}", "finish")


class UpgradeThread(QThread):
    update_message = pyqtSignal()
    update_active_count = pyqtSignal(int)
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
            _item = total_data[index]
            if isLegalSn(_item['sn']):
                workerSignal = WorkerSignal()
                workerSignal.progress.connect(self.update_data)
                workerSignal.finished.connect(self.update_message)
                workerSignal.active_count.connect(self.update_active_count)
                runnable = Worker(str(index), workerSignal)
                runnable.setData(index, total_data[index])
                self.pool.start(runnable)

        self.pool.waitForDone()


# 升级窗口
class UpgradeWindow(QtWidgets.QMainWindow, Upgrade_Ui):
    # 定义信号
    upgrade_data_signal = pyqtSignal(int, dict)
    message_data_signal = pyqtSignal(str)

    def __init__(self):
        super(UpgradeWindow, self).__init__()
        self.setup_ui()
        self.table_bind_signal_event()

    # 绑定UI事件
    def table_bind_signal_event(self):
        print("UpgradeWindow", "table_bind_signal_event", "绑定信号")
        self.upgrade_data_signal.connect(self.update_data)

    def setup_ui(self):
        self.setupUi(self)
        # 信息
        self.table_head_message_change_callback()
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
        self.upgrade_detail_TableWidget.cellChanged.connect(self.table_cell_edit_callback)
        # self.upgrade_detail_TableWidget.horizontalHeader().setSectionResizeMode(QtWidgets.QHeaderView.Stretch)

    # 更新message头信息
    def table_head_message_change_callback(self):
        msg = "升级总数：%d 成功升级：%d 失败数量：%d" % (len(temp), len(success_data), len(failed_data))
        print("UpgradeWindow", "table_head_message_change_callback", "更新头部信息", msg)
        self.message_lineEdit.setText(msg)

    # cell内容变化监听
    def table_cell_edit_callback(self, row, col):
        global total_data
        print("UpgradeWindow", "table_cell_edit_callback", row, col)
        if col == 1:
            # 只响应SN单元格列的变化
            item_sn = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(row, 1))
            if isLegalSn(item_sn):
                data = {'sn': item_sn, 'state': "", 'progress': "", 'version': ""}
                # 根据SN请求在线/离线
            else:
                data = {'sn': item_sn, 'state': "序列号错误", 'progress': "", 'version': ""}
            self.database_update(total_data, data, row)

    # 获取cell内容
    def get_item_data_safety(self, table_item):
        if table_item is None:
            return ""
        else:
            return table_item.text()

    def download_template_file(self):
        print("UpgradeWindow", "download_template_file", "下载模板文件")
        with open("template.csv", 'w', encoding='utf-8') as openf:
            csv_write = csv.writer(openf)
            csv_head = ["SN"]
            csv_write.writerow(csv_head)

    # 增
    def database_add(self, database, data, index=-1):
        print("UpgradeWindow", "database_add", data, index)
        if index >= 0:
            database.insert(index, data)
        else:
            database.append(data)

        # 记录SN，去重
        if data['sn'] not in temp:
            temp.append(data['sn'])

    # 删
    def database_remove(self, database, data, index=-1):
        print("UpgradeWindow", "database_remove", data)
        _sn = data['sn']
        if _sn in temp:
            temp.remove(_sn)
            database.remove(data)

        if index >= 0:
            del database[index]
            
    # 改
    def database_update(self, database, data, index=-1):
        print("UpgradeWindow", "database_update", data, index)
        _index_delete = -1
        for i in range(len(database)):
            item = database[i]
            if item['sn'] == data['sn']:
                _index_delete = i

        if _index_delete >= 0:
            database[_index_delete] = data
        else:
            self.database_remove(database, data)
            self.database_add(database, data, index)

        # 记录SN，去重
        if data['sn'] not in temp:
            temp.append(data['sn'])

        self.table_show_data(database)

    def remove_data(self, line_num):
        global total_data
        print("UpgradeWindow", "remove_data", "删除数据(行)", line_num)
        self.upgrade_detail_TableWidget.removeRow(line_num)
        del total_data[line_num - 1]

    def update_data(self, line_num, data):
        self.upgrade_detail_TableWidget.cellChanged.disconnect()
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
        self.upgrade_detail_TableWidget.cellChanged.connect(self.table_cell_edit_callback)

    # 数据初始化
    def read_data_from_init(self):
        global total_data
        print("UpgradeWindow", "read_data_from_init", "初始化数据")
        for i in range(0, 100):
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})

        self.table_show_data(total_data)

    # 数据全量更新
    def table_show_data(self, items):
        len_item = len(items)
        row = self.upgrade_detail_TableWidget.rowCount() - 1
        print("UpgradeWindow", "add_data", "添加数据", len_item, row)
        for i in range(len_item):
            each_item = items[i]
            # print(each_item)
            if i > row:
                self.upgrade_detail_TableWidget.insertRow(i)
            self.update_data(i, each_item)

    def read_data_from_csv(self, csv_iterator):
        global total_data
        print("UpgradeWindow", "read_data_from_cvs")
        print("UpgradeWindow", "read_data_from_cvs", "原有sn", temp)
        _temp = []
        # 添加文件数据
        for cvs_line in csv_iterator:
            print("UpgradeWindow", "read_data_from_cvs", 'sn:', cvs_line, type(cvs_line))
            sn = cvs_line[0].strip()
            # 判断SN是否合法, 检查去重
            if isLegalSn(sn):
                if sn not in temp:
                    temp.append(sn)
                    _temp.append({'sn': sn, 'state': "", 'progress': "", 'version': ""})

        print("UpgradeWindow", "read_data_from_csv", "数据文件导入：", len(_temp))

        for _i in range(len(total_data)):
            _item = total_data[_i]
            if not isLegalSn(_item['sn']):
                if len(_temp) > 0:
                    total_data[_i] = _temp[0]
                    _temp.remove(_temp[0])

        for _item in _temp:
            total_data.append(_item)

        # 更新message头
        self.table_head_message_change_callback()
        # 空白填充
        while len(total_data) < 100:
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': ""})
        print("UpgradeWindow", "read_data_from_csv", "数据补足：", len(total_data))

    # def read_data_from_table(self):
    #     global total_data
    #     print("UpgradeWindow", "read_data_from_table")
    #     # items = self.upgrade_detail_TableWidget.items()
    #     # print("UpgradeWindow", "read_data_from_table", "items", items)
    #     # items_find = self.upgrade_detail_TableWidget.findItems('-')
    #     # print("UpgradeWindow", "read_data_from_table", "findItems('-')", items_find)
    #     col_num = self.upgrade_detail_TableWidget.columnCount()
    #     print("UpgradeWindow", "read_data_from_table", "列col_num", col_num)
    #     row_num = self.upgrade_detail_TableWidget.rowCount()
    #     print("UpgradeWindow", "read_data_from_table", "行row_num", row_num)
    #     for i in range(1, row_num):
    #         item_sn = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(i, 1))
    #         item_state = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(i, 2))
    #         item_progress = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(i, 3))
    #         item_version = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(i, 4))
    #         if isLegalSn(item_sn):
    #             total_data.append({'sn': item_sn, 'state': item_state, 'progress': item_progress, 'version': item_version})

    ########################################################################################################
    def exec_upgrade(self):
        global total_data
        print("UpgradeWindow", "exec_upgrade", "执行升级")
        global file_path
        file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.bin)')
        print("UpgradeWindow", "exec_upgrade", file_path, file_format)
        if len(file_path) == 0:
            return

        self.username_lineEdit.setText('admin')
        self.password_lineEdit.setText('admin')

        self.get_username_password()
        if len(username) == 0 or len(password) == 0:
            print("UpgradeWindow", "exec_upgrade", "用户名/密码错误")
            return

        self.upgradeThread = UpgradeThread()
        self.upgradeThread.update_data.connect(self.update_data)
        self.upgradeThread.update_message.connect(self.table_head_message_change_callback)
        self.upgradeThread.update_active_count.connect(self.control_upgrade_btn_enable)
        self.upgradeThread.start()

    def control_upgrade_btn_enable(self, count):
        global count_active
        count_active += count
        print("UpgradeWindow", "control_upgrade_btn_enable", "当前执行任务数", count_active)
        if count_active > 0:
            self.upgrade_Button.setEnabled(False)
        else:
            self.upgrade_Button.setEnabled(True)
            self.update_finish()

    def exec_cancel(self):
        print("UpgradeWindow", "exec_cancel", "执行取消")
        self.close()

    def add_data_from_csv_file(self):
        global total_data
        print("UpgradeWindow", "add_data_from_csv_file")
        # file_path = self.lineEdit_filePath.text()
        cvs_file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.csv)')
        if cvs_file_path == '':
            pass
        else:
            print(cvs_file_path, file_format)
            self.lineEdit_filePath.setText(cvs_file_path)
            with open(cvs_file_path, "r", encoding='utf-8') as openf:
                sn_file = csv.reader(openf)
                # print("cvs文件数据：", list(sn_file))
                self.read_data_from_csv(sn_file)
                self.table_show_data(total_data)

    def update_finish(self):
        print("UpgradeWindow", "update_finish", "更新完成")

    def get_username_password(self):
        print("UpgradeWindow", "get_username_password", "获取用户名密码")
        # 用户名/密码
        global username
        username = self.username_lineEdit.text()
        global password
        password = self.password_lineEdit.text()
        print("用户名/密码：", username, password)


def isLegalSn(sn):
    result = re.match(r"^[0-9a-fA-F]{8}-[0-9a-fA-F]{8}", sn) is not None
    print("UpgradeWindow", "isLegalSn", sn, result)
    return result


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
