#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QMainWindow
from .ui.ui_window_main import Ui_MainWindow
from .widget_upgrade import UpgradeWidget


class MainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        # 升级主窗口
        self.upgrade_widget = UpgradeWidget(self)
        self.stackedWidget.addWidget(self.upgrade_widget)

        # if result:
        #     query = QSqlQuery()
        #     query.exec_("create table student(id int primary key, name varchar(20), sex varchar(8), age int);")
        #
        #     query.exec_("insert into student values(1, 'Bauer', 'Man', 25)")
        #     query.exec_("insert into student values(2, 'Alex', 'Man', 24)")
        #     query.exec_("insert into student values(3, 'Mary', 'Female', 23)")
        #     query.exec_("insert into student values(4, 'Jack', 'Man', 25)")
        #     query.exec_("insert into student values(5, 'xiaoming', 'Man', 24)")
        #     query.exec_("insert into student values(6, 'xiaohong', 'Female', 23)")
        #     query.exec_("insert into student values(7, 'xiaowang', 'Man', 25)")
        #     query.exec_("insert into student values(8, 'xiaozhang', 'Man', 25)")
        #     query.exec_("insert into student values(9, 'xiaoli', 'Man', 25)")
        #     query.exec_("insert into student values(10, 'xiaohan', 'Man', 25)")

    def closeEvent(self, event):
        print("MainWindow closeEvent.")
        pass

"""
数据库驱动类型
QDB2 -> IBM DB2驱动程序
QMYSQL -> MySQL驱动程序
QOCI -> Oracle调用接口驱动程序
QODBC -> ODBC驱动程序（包括MS SQL Server）
QPSQL -> PostgreSQL驱动程序
QSQLITE -> SQLite3驱动程序
QSQLITE2 -> SQLite2驱动程序

QSqlDatabase常用方法如下：
addDataBase:设置连接数据库的数据库驱动类型
setDatabaseName：设置所连接的数据库名称
setHostName：设置数据库所在的主机名称
setUserName：指定连接的用户名
setPassword：设置连接对象的密码
commit：提交事务，如果执行成功返回True。
rollback：回滚数据库事务
close：关闭数据库连接

SQLite常用操作
创建数据库文件，创建后进行入SQLite命令行模式。
sqlite3 DatabaseName.db
查看已经存在的数据库文件，在SQLite命令行模式执行：
.databases
打开已经存在的数据库文件，如果数据库文件不存在，则创建。
sqlite3 DatabaseName.db
查看帮助信息，在SQLite命令行模式执行：
.help
创建表，在SQLite命令行模式执行：
create table person(id integer primary key, name text);
插入数据到表：
insert into person(id, name) values(1, "zhangsan");
查询操作：
select * from person;
查询表的结构：
.schema person

SQLiteStudio下载：https://sqlitestudio.pl/index.rvt?act=download
"""