#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sqlite3


conn = sqlite3.connect("mytest.db")
cursor = conn.cursor()

sql_create = '''CREATE TABLE students (name text,username text, id int)'''
sql_insert = '''INSERT INTO students (name, username, id) VALUES (:st_name, :st_username, :id_num)'''
sql_select = '''SELECT * FROM students'''

cursor.execute(sql_create)
# rows = cursor.fetchall()
conn.commit()


cursor.close()
# class Upgrade:
#     def __init__(self):
#         pass
#
#     def create_db(self):
#         sqlite3.connect()