#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import cgitb
import csv
import re
import socket
import struct

from PyQt5.QtCore import Qt, QObject, QRunnable, QThread, QThreadPool, pyqtSignal, QSettings
from PyQt5.QtWidgets import QApplication, QFileDialog, QTableWidgetItem, QMessageBox, QMainWindow

from ui.ui_upgrade import *
from libutils.ConfigManager import *
from libutils.NormalClient import *
from libutils.SessionClient import *
from libutils.Zlog import *

# 序列号list
temp = []
total_data = []
failed_data = []
success_data = []

# 旧臻云接口（已废弃）
# url_pdns = "http://118.31.4.231:8000/pdns"
# 中台接口
# url_pdns = "http://119.3.146.99/webapi/v1/pdns"
# 新臻云测试接口
# url_pdns = 'http://nopen.vzpdns.com'
url_pdns = ""

access_switch = 0
access_key_id = ''
access_key_secret = ''
username = ''
password = ''

config_file_path = None
file_path = ''
file_version = ''

count_active = 0
shouldUpdateInfo = True


# 升级窗口
class UpgradeWindow(QMainWindow, Ui_MainWindow):
    # 定义信号
    upgrade_data_signal = pyqtSignal(int, dict)
    message_data_signal = pyqtSignal(str)

    def __init__(self):
        global config_file_path
        super(UpgradeWindow, self).__init__()
        self.upgradeThread = None
        self.loading_widget = None
        self.config = None
        self.log = ZLog()
        self.setup_ui()
        self.read_config(config_file_path)

    def read_config(self, path):
        global url_pdns, access_switch, access_key_id, access_key_secret, username, password
        print("UpgradeWindow", "read_config", path)
        self.config = ConfigManager(path)
        try:
            url_pdns = self.config.get_url_pdns()
            access_switch = int(self.config.get_switch_use_access())
            if access_switch == 1:
                access_key_id = self.config.get_account_access_key_id()
                access_key_secret = self.config.get_account_access_key_secret()
            username = self.config.get_account_username()
            password = self.config.get_account_password()
            self.update_setting()
        except Exception as e:
            pass
        finally:
            del self.config

    # 绑定UI事件
    def update_setting(self):
        global access_switch, access_key_id, access_key_secret, username, password
        if access_switch != 1:
            self.access_key_id_label.setVisible(False)
            self.access_key_id_lineEdit.setVisible(False)
            self.access_key_secret_label.setVisible(False)
            self.access_key_secret_lineEdit.setVisible(False)
        else:
            self.access_key_id_label.setVisible(True)
            self.access_key_id_lineEdit.setVisible(True)
            self.access_key_secret_label.setVisible(True)
            self.access_key_secret_lineEdit.setVisible(True)
            self.access_key_id_lineEdit.setText(access_key_id)
            self.access_key_secret_lineEdit.setText(access_key_secret)
        self.username_lineEdit.setText(username)
        self.password_lineEdit.setText(password)

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
        self.setting_Button.clicked.connect(self.exec_setting)
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
        self.upgrade_data_signal.connect(self.update_data)

    # 更新message头信息
    def table_head_message_change_callback(self):
        msg = "升级总数：%d 成功升级：%d 失败数量：%d" % (len(temp), len(success_data), len(failed_data))
        print("UpgradeWindow", "table_head_message_change_callback", "更新头部信息", msg)
        self.log.log_debug(f"UpgradeWindow update head msg {msg}")
        self.message_lineEdit.setText(msg)
        QApplication.processEvents()

    # cell内容变化监听
    def table_cell_edit_callback(self, row, col):
        global total_data
        print("UpgradeWindow", "table_cell_edit_callback", row, col)
        if col == 1:
            # 只响应SN单元格列的变化
            item_sn = self.get_item_data_safety(self.upgrade_detail_TableWidget.item(row, 1))
            item_sn = item_sn.replace('\n', '').replace('\r', '').replace(' ', '').strip()
            if isLegalSn(item_sn):
                data = {'sn': item_sn, 'state': "", 'progress': "", 'version': "", "host": "", "priority": 8}
            else:
                data = {'sn': item_sn, 'state': "序列号错误", 'progress': "", 'version': "", "host": "", "priority": 4}
            self.database_update(total_data, data, row)
            self.log.log_debug(f"UpgradeWindow table item changed {row}, {data['sn']}")
            self.table_head_message_change_callback()

    # 获取cell内容
    def get_item_data_safety(self, table_item):
        if table_item is None:
            return ""
        else:
            return table_item.text()

    def request_device_online_state(self, data):
        global username, password, config_file_path
        net_state = isNetOk()
        print("GetInfoWorker", "net state", net_state)
        self.log.log_debug(f"UpgradeWindow get online info, net state: {net_state}, {data['sn']}")
        # data['host'] = "http://192.168.30.127:18008/02880771-fce36ba5"
        if data['host'] == "":
            self.get_access_key_id_secret()
            host = requestSnToHost(data['sn'])
            host = host.replace('\n', '').replace('\r', '').replace(' ', '').strip()
            self.log.log_debug(f"UpgradeWindow get online info, request: {host}")
            if host.startswith("http"):
                data['state'] = "在线"
                data['host'] = host
            elif host.startswith("access_error"):
                data['state'] = "access异常"
            else:
                data['state'] = "离线"
                data['priority'] = 5

        if data['state'] == "access异常":
            self.log.log_debug("UpgradeWindow get online info, access异常")
            return

        self.get_username_password()
        if len(username) == 0 or len(password) == 0:
            print("GetInfoWorker", "check username/password", "用户名/密码错误")
            self.log.log_debug(f"UpgradeWindow get online info, username or password is Empty, {data['sn']}")
            return

        # host = "http://192.168.1.88"
        print("GetInfoWorker", "host", data['host'])
        client = SessionClient(data['host'], username, password, config_file_path)
        info_json = client.login()
        self.log.log_debug(f"GetInfoWorker login：{info_json}")

        if not info_json:
            data['state'] = "登陆失败"
            data['priority'] = 3
        else:
            data['state'] = "在线"

            version = client.info()
            self.log.log_debug(f"GetInfoWorker info：{version}")

            if version is None or len(version) == 0:
                data['state'] = "离线"
                data['priority'] = 3
            else:
                data['priority'] = 6
                print("GetInfoWorker", "info version:", version)
                data['version'] = version

    def download_template_file(self):
        print("UpgradeWindow", "download_template_file", "下载模板文件")
        self.log.log_debug(f"UpgradeWindow create template file.")
        QApplication.processEvents()
        global total_data
        with open("template.csv", 'w', encoding='utf-8', newline="") as openf:
            csv_write = csv.writer(openf)
            csv_head = ['序列号', '状态', '升级进度', '固件版本']
            csv_write.writerow(csv_head)

            for _item in total_data:
                if isLegalSn(_item['sn']):
                    row = [_item['sn'], _item['state'], _item['progress'], _item['version']]
                    csv_write.writerow(row)

    # 增
    def database_add(self, database, data, index=-1):
        global shouldUpdateInfo, temp
        if isLegalSn(data['sn']):
            self.request_device_online_state(data)
        print("UpgradeWindow", "database_add", data, index)
        if index >= 0:
            # 根据SN请求在线/离线
            database.insert(index, data)
        else:
            database.append(data)

        record_sn_list()

    # 删
    def database_remove(self, database, data, index=-1):
        _sn = data['sn']
        if _sn in temp:
            if data in database:
                print("UpgradeWindow", "database_remove", data)
                database.remove(data)

        if index >= 0:
            print("UpgradeWindow", "database_remove", index, database[index])
            del database[index]

        record_sn_list()

    # 改
    def database_update(self, database, data, index=-1):
        print("UpgradeWindow", "database_update", data, index)
        _index_delete = -1
        for i in range(len(database)):
            item = database[i]
            if item['sn'] == data['sn']:
                _index_delete = i

        if _index_delete >= 0:
            if isLegalSn(data['sn']):
                self.request_device_online_state(data)
            database[_index_delete] = data
        else:
            self.database_remove(database, data, index)
            self.database_add(database, data, index)

        # 记录SN，去重
        record_sn_list()
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
        item_index = QTableWidgetItem(str(line_num + 1))
        item_index.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_index.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 0, item_index)
        # 设置sn
        item_sn = QTableWidgetItem(str(data['sn']))
        item_sn.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.upgrade_detail_TableWidget.setItem(line_num, 1, item_sn)
        # 设置状态
        item_state = QTableWidgetItem(str(data['state']))
        item_state.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_state.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 2, item_state)
        # 设置进度
        item_progress = QTableWidgetItem(str(data['progress']))
        item_progress.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_progress.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 3, item_progress)
        # 设置版本号
        item_version = QTableWidgetItem(str(data['version']))
        item_version.setTextAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        item_version.setFlags(Qt.ItemIsEnabled | Qt.ItemIsSelectable)
        self.upgrade_detail_TableWidget.setItem(line_num, 4, item_version)
        self.upgrade_detail_TableWidget.cellChanged.connect(self.table_cell_edit_callback)
        QApplication.processEvents()

    # 数据初始化
    def read_data_from_init(self):
        global total_data
        print("UpgradeWindow", "read_data_from_init", "初始化数据")
        for i in range(0, 100):
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 10})

        self.table_show_data(total_data)
        QApplication.processEvents()

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
            QApplication.processEvents()

    def read_data_from_csv(self, csv_iterator):
        global total_data, password, username
        print("UpgradeWindow", "read_data_from_cvs")
        print("UpgradeWindow", "read_data_from_cvs", "原有sn", temp)
        _temp = []

        # 添加文件数据
        for cvs_line in csv_iterator:
            print("UpgradeWindow", "read_data_from_cvs", 'sn:', cvs_line, type(cvs_line))
            if len(cvs_line) <= 0:
                continue
            sn = cvs_line[0].replace('\n', '').replace('\r', '').replace(' ', '').strip()
            # 判断SN是否合法, 检查去重
            if isLegalSn(sn):
                if sn not in temp:
                    temp.append(sn)
                    _temp.append({'sn': sn, 'state': "", 'progress': "", 'version': "", "host": "", "priority": 6})
                else:
                    index = temp.index(sn)
                    self.database_update(total_data, total_data[index], index)
            QApplication.processEvents()

        print("UpgradeWindow", "read_data_from_csv", "数据文件导入：", len(_temp))

        for _i in range(len(total_data)):
            _item = total_data[_i]
            if not isLegalSn(_item['sn']):
                if len(_temp) > 0:
                    self.database_update(total_data, _temp[0], _i)
                    _temp.remove(_temp[0])
            QApplication.processEvents()

        for _item in _temp:
            self.database_add(total_data, _item)

        # 更新message头
        self.table_head_message_change_callback()
        # 空白填充
        while len(total_data) < 100:
            total_data.append({'sn': "请输入序列号", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 10})
        print("UpgradeWindow", "read_data_from_csv", "数据补足：", len(total_data))
        QApplication.processEvents()

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
        global total_data, file_path, file_version
        print("UpgradeWindow", "exec_upgrade", "执行升级")

        file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.bin)')
        self.log.log_debug(f"UpgradeWindow exec upgrade, {file_path}")
        print("UpgradeWindow", "exec_upgrade", file_path, file_format)
        if len(file_path) == 0:
            return

        file_version = get_local_upgrade_file_version(file_path)
        self.get_access_key_id_secret()
        self.get_username_password()

        if len(username) == 0 or len(password) == 0:
            QMessageBox.warning(self, "错误", "用户名/密码错误")
            print("UpgradeWindow", "exec_upgrade", "用户名/密码错误")
            return

        if not isNetOk():
            QMessageBox.warning(self, "错误", "网络连接异常")
            print("UpgradeWindow", "exec_upgrade", "网络异常")
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

    def exec_setting(self):
        global config_file_path
        print("UpgradeWindow", "exec_setting", "执行设置")
        config_file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.ini)')
        if config_file_path is None or config_file_path == '':
            config_file_path = None
        else:
            self.read_config(config_file_path)

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
        QApplication.processEvents()

    def update_finish(self):
        global total_data, success_data, failed_data
        print("UpgradeWindow", "update_finish", "更新完成")
        # 排序显示
        total_data = sorted(total_data, key=lambda _item: _item['priority'])
        self.table_show_data(total_data)

    def get_username_password(self):
        print("UpgradeWindow", "get_username_password", "获取用户名密码")
        # 用户名/密码
        global username, password
        username = self.username_lineEdit.text()
        password = self.password_lineEdit.text()
        print("用户名/密码：", username, password)

    def get_access_key_id_secret(self):
        print("UpgradeWindow", "get_access_key_id_secret", "获取Access信息")
        global access_key_id, access_key_secret
        access_key_id = self.access_key_id_lineEdit.text()
        access_key_secret = self.access_key_secret_lineEdit.text()
        print("access key id/secret：", access_key_id, access_key_secret)


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
        self.log = ZLog()

    def setData(self, i, _data):
        self.line = i
        self.data = _data
        print("Worker", "setData", self.line, self.data)
        self.log.log_debug(f"Worker {self.thread_name} set data：{self.line} {self.data}")

    def progress_change(self, monitor):
        _progress = round(monitor.bytes_read / monitor.len * 100, 2)
        # print("Worker", "progress_change", _progress)
        self.data['progress'] = str(_progress) + "%"
        self.signal.progress.emit(self.line, self.data)

    def run(self):
        global username, password, file_version, config_file_path
        self.signal.active_count.emit(1)
        # self.data["host"] = "http://192.168.30.127:18008/02880771-fce36ba5"
        # 获取地址
        if self.data["host"] == "":
            host = requestSnToHost(self.data['sn'])
            host = host.replace('\n', '').replace('\r', '').replace(' ', '').strip()
            if host.startswith("http"):
                self.data['host'] = host
                self.signal.progress.emit(self.line, self.data)
            elif host.startswith("access_error"):
                self.data['state'] = "access异常"
                self.signal.progress.emit(self.line, self.data)
                self.signal.active_count.emit(-1)
                return
            else:
                self.data['state'] = "序列号错误"
                self.signal.progress.emit(self.line, self.data)
                self.signal.active_count.emit(-1)
                return
        print("Worker", self.thread_name, "getHost", self.data["host"])
        self.log.log_debug(f"Worker {self.thread_name} get host：{self.data['sn']} -> {self.data['host']}")
        if self.data["host"] == "":
            self.data['state'] = "离线"
            self.signal.progress.emit(self.line, self.data)
            self.signal.active_count.emit(-1)
            return
        # 创建请求并登录
        client = SessionClient(self.data["host"], username, password, config_file_path)
        info_json = client.login()
        self.log.log_debug(f"Worker {self.thread_name} login：{info_json}")
        if not info_json:
            self.data['state'] = "登陆失败"
            self.signal.progress.emit(self.line, self.data)
            self.signal.active_count.emit(-1)
            return
        self.data['state'] = "在线"
        self.signal.progress.emit(self.line, self.data)
        # 获取版本
        version = client.info()
        self.log.log_debug(f"Worker {self.thread_name} info：{version}")
        if info_json is None:
            self.data['state'] = "离线"
            self.signal.progress.emit(self.line, self.data)
            self.signal.active_count.emit(-1)
            return
        self.data['version'] = version
        self.signal.progress.emit(self.line, self.data)
        time.sleep(0.5)
        # 检查版本
        print("Worker", self.thread_name, "update:", self.data['version'], file_version)
        if self.data['version'] != "" and file_version == self.data['version']:
            self.data['state'] = "已是当前版本"
            self.log.log_debug(f"Worker {self.thread_name} 已经是当前版本")
            self.signal.progress.emit(self.line, self.data)
            return
        # 升级
        state = client.update(file_path, self.progress_change)
        self.log.log_debug(f"Worker {self.thread_name} update：{state}")
        print("Worker", self.thread_name, "update:", state)
        if state:
            self.data['state'] = "已升级"
            self.data['version'] = file_version
            self.data['priority'] = 9
            exist = False
            for _item in success_data:
                if _item['sn'] == self.data['sn']:
                    exist = True
            if not exist:
                success_data.append(self.data)
        else:
            self.data['state'] = "升级失败"
            self.data['priority'] = 0
            exist = False
            for _item in failed_data:
                if _item['sn'] == self.data['sn']:
                    exist = True
            if not exist:
                failed_data.append(self.data)
        client.close()

        try:
            self.signal.progress.emit(self.line, self.data)
            self.signal.active_count.emit(-1)
            self.signal.finished.emit()
        except Exception as e:
            print("exit")
        self.log.log_debug(f"Worker {self.thread_name} finish：{self.data['sn']}")
        print("Worker", self.thread_name, "finish")


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
        self.pool.setMaxThreadCount(5)
        self.log = ZLog()

    def run(self):
        print("UpgradeThread", "run", "启动线程池")
        self.log.log_debug(f"UpgradeThread thread pool started")
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
        self.log.log_debug(f"UpgradeThread thread pool finished")


class GetInfoWorker(QObject):
    finished = pyqtSignal(str)  # 结束的信号
    progress = pyqtSignal(int, dict)  # 更新表格

    def __init__(self, line, data):
        super(GetInfoWorker, self).__init__()
        self.line = line
        self.data = data
        self.log = ZLog()

    def run(self):
        global username, password, config_file_path
        net_state = isNetOk()
        print("GetInfoWorker", "net state", net_state)
        # self.data["host"] = "http://192.168.30.127:18008/02880771-fce36ba5"
        if self.data["host"] == "":
            host = requestSnToHost(self.data['sn'])
            host = host.replace('\n', '').replace('\r', '').replace(' ', '').strip()
            if host.startswith("http"):
                self.data['state'] = "在线"
                self.data['host'] = host
            elif host.startswith("access_error"):
                self.data['state'] = "access异常"
            else:
                self.data['state'] = "离线"
                self.data['priority'] = 5
            self.progress.emit(self.line, self.data)

        if len(username) == 0 or len(password) == 0:
            print("GetInfoWorker", "check username/password", "用户名/密码错误")
            return

        print("GetInfoWorker", "host", host)
        client = SessionClient(self.data['host'], username, password, config_file_path)
        version = client.info()
        if version is None:
            version = ""

        if len(version) == 0:
            self.data['state'] = "离线"
            self.data['priority'] = 3
        else:
            self.data['priority'] = 6
            print("GetInfoWorker", "info version:", version)
            self.data['version'] = version
        self.progress.emit(self.line, self.data)
        self.finished.emit(version)  # 发出结束的信号


def isLegalSn(sn):
    if len(sn) != 17:
        return False
    result = re.match(r"^[0-9a-fA-F]{8}-[0-9a-fA-F]{8}", sn) is not None
    print("UpgradeWindow", "isLegalSn", sn, result)
    return result


def isLegalIp(ip):
    result = re.match(r'((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})(\.((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})){3}:?\d*',
                      ip) is not None
    print("UpgradeWindow", "isLegalIp", ip, result)
    return result


def check_json_format(raw_msg):
    """
    用于判断一个字符串是否符合Json格式
    :param self:
    :return:
    """
    if isinstance(raw_msg, str):  # 首先判断变量是否为字符串
        try:
            json.loads(raw_msg, encoding='utf-8')
        except ValueError:
            return False
        return True
    else:
        return False


def isNetOk(server=("www.baidu.com", 443)):
    s = socket.socket()
    s.settimeout(3)
    try:
        status = s.connect_ex(server)
        if status == 0:
            s.close()
            return True
        else:
            return False
    except Exception as e:
        return False


def requestSnToHost(sn):
    if access_switch == 0:
        param = {'sn': sn, 'port': 80}
        resp = requests.get(url_pdns, params=param)
        print("Worker", "requestSnToHost", "getHost", resp.status_code, resp.text)
        return resp.text
    if access_switch == 1:
        if access_key_id == "" or access_key_secret == "":
            return "access_error"
        # client = NormalClient(test_base_host, test_access_key_id, test_access_key_secret)
        url_parsed = urlparse(url_pdns)
        url_host = f"{url_parsed.scheme}://{url_parsed.netloc}"
        url_path = url_parsed.path
        client = NormalClient(url_host, access_key_id, access_key_secret)
        # rx - http://192.168.30.127:32287/02880771-fce36ba5/?userdata=pdns
        if url_path == "":
            resp = client.get_device_remote_url(sn)
        else:
            resp = client.get_device_remote_url(sn, url_path)
        print("Worker", "requestSnToHost", "getHost", resp)
        return resp


def get_local_upgrade_file_version(path):
    version_bin = ""
    with open(path, "rb") as of:
        data = of.read(64)
        num = struct.unpack("<H", data[62:64])
        if num[0] == 0:
            for index in range(20, 36, 4):
                num = struct.unpack("<I", data[index:index + 4])
                version_bin += f"{num[0]}."
        elif num[0] == 160:
            version_bin += f'{struct.unpack("B", data[24:25])[0]}.{struct.unpack("B", data[25:26])[0]}.{struct.unpack("<H", data[26:28])[0]}.{struct.unpack("<I", data[28:32])[0]}.'
        else:
            version_bin += "."
    return version_bin[:-1]


def record_sn_list():
    global temp
    temp.clear()
    # 记录SN，去重
    for item in total_data:
        if isLegalSn(item['sn']):
            temp.append(item['sn'])

# 参考资料
# Qt线程池问题：https://blog.csdn.net/weixin_38587278/article/details/106430250
# 懒人图库（gif进度条）：https://www.lanrentuku.com/gif/a/loading_3.html
# QApplication.processEvents()