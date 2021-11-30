#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import MySQLdb
import pandas

# 创建数据库
# db = MySQLdb.connect(host="localhost", user="root", passwd="123456", charset="utf8")
# 获取数据库游标
# cursor = db.cursor()
#
with open("city_cn.sql", "r", encoding="utf-8") as sql_file:
    lines = sql_file.readlines()
    for line in lines:
        line = line.strip()
        if line.startswith('('):
            line = line[1:-2].replace("'", "").split(",")
            print(line)

