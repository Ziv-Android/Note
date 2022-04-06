#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import time

from c_rs485 import *
from oqc_tool import *
from libutils.webclient import WEBClient

# {"type":"get_device_info", "module":"SS_BUS_REQUEST"}
# 获取设备信息，如：sn等


def get_device_info(webc):
    cmd_info = '''{"type":"get_device_info", "module":"SS_BUS_REQUEST"}'''

    if webc is None:
        print('webc none')
        return "", ""

    ret = 404
    if not webc.login():
        print('webc.login failed')
        return "", ""

    ret, resp = webc.posts(cmd_info)
    if ret != 200:
        print('webc.posts scmd failed.')
        return "", ""

    try:
        print(resp)
        jl = json.loads(resp)
        sn = jl['body']['serial_num']
        soft_version = jl['body']['soft_ver']
    except Exception as e:
        print(e)
        sn = "SN获取失败"
        soft_version = ""

    if sn is None:
        sn = ""

    if soft_version is None:
        soft_version = ""

    return sn, soft_version

