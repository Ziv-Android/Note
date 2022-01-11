#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5.QtSql import *


class DataGrid(QDialog):
    delrow = -1

    def __init__(self):
        super(DataGrid, self).__init__()
        # 添加数据库
        self.db = QSqlDatabase.addDatabase('QSQLITE')
        # 设置数据库名称
        self.db.setDatabaseName('mytest.db')
        # 判断是否打开
        if not self.db.open():
            return False

        self.model = QSqlTableModel()  # MVC模式中的模型
        # 初始化将数据装载到模型当中
        self.initializeModel(self.model)
        view = self.createView("展示数据", self.model)
        view.clicked.connect(self.findrow)

        layout = QVBoxLayout()
        layout.addWidget(view)
        addBtn = QPushButton('添加一行')
        addBtn.clicked.connect(self.addrow)

        delBtn = QPushButton('删除一行')
        delBtn.clicked.connect(lambda: self.model.removeRow(view.currentIndex().row()))

        layout.addWidget(view)
        layout.addWidget(addBtn)
        layout.addWidget(delBtn)

        self.setLayout(layout)
        self.setWindowTitle("Database Demo")

    # 创建视图
    def createView(self, title, model):
        view = QTableView()
        view.setModel(model)
        view.setWindowTitle(title)
        return view

    # 初始化
    def initializeModel(self, model):
        model.setTable('students')
        # 当字段变化时会触发一些事件
        model.setEditStrategy(QSqlTableModel.OnFieldChange)
        # 将整个数据装载到model中
        model.select()
        # 设置字段头
        model.setHeaderData(0, Qt.Horizontal, 'ID')
        model.setHeaderData(1, Qt.Horizontal, '姓名')
        model.setHeaderData(2, Qt.Horizontal, '地址')

    def findrow(self, i):
        # 当前选中的行
        delrow = i.row()
        print('del row=%s' % str(delrow))

    def addrow(self):
        # 不是在QTableView上添加，而是在模型上添加,会自动将数据保存到数据库中！
        # 参数一：数据库共有几行数据  参数二：添加几行
        ret = self.model.insertRows(self.model.rowCount(), 1)  # 返回是否插入
        print('数据库共有%d行数据' % self.model.rowCount())
        print('insertRow=%s' % str(ret))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    dlg = DataGrid()
    dlg.resize(500, 400)
    dlg.show()
    sys.exit(app.exec())
