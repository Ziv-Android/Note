#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
import pandas as pd
from sqlalchemy import create_engine

from PyQt5.QtCore import Qt, QAbstractTableModel, pyqtSignal
from PyQt5.QtWidgets import QWidget, QHeaderView, QTableView, QItemDelegate
from PyQt5.QtSql import QSqlDatabase, QSqlQuery, QSqlTableModel
from .ui.ui_widget_upgrade import Ui_UpgradeWidget


class UpgradeWidget(QWidget, Ui_UpgradeWidget):
    headers = ['序号', '序列号', '状态', '升级进度', '固件版本']
    # headers = ['id', "姓名", "地址"]
    table_name = "upgrade"

    # table_name = "students"
    # table_cell_change = pyqtSignal()
    # table_double_clicked = pyqtSignal()

    def __init__(self, ui_parent=None):
        super().__init__()
        self.pwd = ui_parent
        self.setupUi(self)
        # 声明数据库连接
        self.db = None
        # 查询模型
        self.tableModel = None

        self.initModel()
        self.initUi()
        self.initSignal()

    def initUi(self):
        self.tableView.horizontalHeader().setStretchLastSection(True)
        self.tableView.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.tableView.setModel(self.tableModel)
        self.tableView.setColumnHidden(0, True)
        self.tableView.setSortingEnabled(True)
        # for index in range(1, len(UpgradeWidget.headers) - 1):
        #     self.tableView.setItemDelegateForColumn(index, ReadOnlyDelegate())

    def initSignal(self):
        # 导入文件
        self.input_file_Button.clicked.connect(self.onImportCsvFile)
        # 下载模板
        self.download_file_Button.clicked.connect(self.onDownloadTemplateFile)
        # 升级/取消
        self.upgrade_Button.clicked.connect(self.onUpgradeAction)
        self.cancel_Button.clicked.connect(self.onCancelAction)
        # 表单cell变化
        # self.tableView.doubleClicked.connect(self.table_double_clicked)
        # self.tableView.cellChanged.connect(self.table_cell_change)

    def initModel(self):
        # 数据库
        self.db = QSqlDatabase.addDatabase("QSQLITE")
        path_db = os.path.join(os.path.abspath(".."), "config", "db")
        print(path_db)
        if not os.path.exists(path_db):
            os.makedirs(path_db)
        self.db_sn_path = os.path.join(path_db, "sn.db")
        self.db.setDatabaseName(self.db_sn_path)
        # self.db.setDatabaseName('./models/mytest.db')
        dbIsOpen = self.db.open()
        print(f"db is open: {dbIsOpen}")
        if not dbIsOpen:
            return False

        self.tableModel = QSqlTableModel()
        self.tableModel.setTable(UpgradeWidget.table_name)
        # 当字段变化时会触发一些事件
        self.tableModel.setEditStrategy(QSqlTableModel.OnFieldChange)
        # 将整个数据装载到model中
        self.tableModel.select()
        # 设置字段头
        for index_header in range(len(UpgradeWidget.headers)):
            self.tableModel.setHeaderData(index_header, Qt.Horizontal, UpgradeWidget.headers[index_header])
        # # 获取表的所有记录数
        # self.recodeQuery(UpgradeWidget.table_name)

    def onImportCsvFile(self):
        print("import cvs file")
        path_config = os.path.join(os.path.abspath('..'), "config")
        if not os.path.exists(path_config):
            os.makedirs(path_config)
        filename = os.path.join(path_config, "template.csv")

        df = pd.read_csv(filename)
        print(df)
        engine = create_engine(f"sqlite:///{self.db_sn_path}")
        df.to_sql(UpgradeWidget.table_name, engine)
        pass

    def onDownloadTemplateFile(self):
        print("download template file")
        pass

    def onUpgradeAction(self):
        print("upgrade action")
        pass

    def onCancelAction(self):
        print("cancel action")
        pass

    def recodeInsert(self, table, value):
        sql = f"INSERT INTO {table}, VALUES({value})"
        self.query.exec_(sql)

    def recodeDelete(self, table):
        sql = f""
        self.query.exec_(sql)

    def recodeUpdate(self, table):
        sql = f""
        self.query.exec_(sql)

    def recodeQuery(self, table, start=0, count=0):
        if start == 0 or count == 0:
            sql = f"SELECT * FROM {table}"
        else:
            sql = f"SELECT * FROM {table} limit {start},{count}"

        self.queryModel.setQuery(sql, self.db)

    def closeEvent(self, event):
        if self.db is not None:
            self.db.close()


class ReadOnlyDelegate(QItemDelegate):
    def __init__(self):
        super().__init__()

    def createEditor(self, parent, item, index):
        return None
# class UpgradeTableModel(QAbstractTableModel):
#     def __init__(self, data):
#         QAbstractTableModel.__init__(self)
#         self._data = data
#
#     # 列
#     def rowCount(self, parent=None):
#         return self._data.shape[0]
#
#     # 行
#     def columnCount(self, parent=None):
#         return self._data.shape[1]
#
#     # 显示数据
#     def data(self, index, role=Qt.DisplayRole):
#         if index.isValid():
#             if role == Qt.DisplayRole:
#                 return str(self._data.iloc[index.row(), index.column()])
#         return None
#
#     # 显示行和列头
#     def headerData(self, col, orientation, role):
#         if orientation == Qt.Horizontal and role == Qt.DisplayRole:
#             return self._data.columns[col]
#         elif orientation == Qt.Vertical and role == Qt.DisplayRole:
#             return self._data.axes[0][col]
#         return None


# https://blog.csdn.net/islinyoubiao/article/details/105577081
