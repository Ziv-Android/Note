#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import logging

def isNetOk(server):
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


print(isNetOk(("www.baidu.com", 443)))


list=[
    {'sn': "1", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 10},
    {'sn': "2", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 9},
    {'sn': "3", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 8},
    {'sn': "4", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 7},
    {'sn': "5", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 6},
    {'sn': "6", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 5},
    {'sn': "7", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 4},
    {'sn': "8", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 3},
    {'sn': "9", 'state': "", 'progress': "", 'version': "", "host": "", "priority": 2},
]

list2 = sorted(list, key=lambda _item: _item['priority'])
print(list2)