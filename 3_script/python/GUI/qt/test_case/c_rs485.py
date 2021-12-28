#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import time
import base64
from libutils.webclient import WEBClient

'''
# 测试IO
# request
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_send_rs485",
    "body":{
        "source":0,
        "rs485_data":"MTIzNDU2"
    }
}

字段名称:body.source
字段含义:rs485序号
取值范围:0,1,2

字段名称:body.rs485_data
字段含义:发送数据,base64.encode
取值范围:2KByte以内

'''

from libutils.webclient import WEBClient

cmd_s_tmp = '''{
                "module":"EVS_BUS_REQUEST",
                "type":"evs_send_rs485",
                "body":{
                    "source":%d,
                    "rs485_data":"%s"
                }
            }'''

cmd_r_tmp = '''{
                "module":"EVS_BUS_REQUEST",
                "type":"evs_read_rs485",
                "body":{
                    "source":%d,
                    "rs485_data":"%s"
                }
            }'''


def c_rs485(webc, cmd_tmp, num, data):
    temp = base64.b64encode(data.encode()).decode()
    # print(temp.decode())
    cmd = cmd_tmp % (num, temp)
    # print('c_rs485 %s' % cmd)
    if webc is None:
        print('webc none')
        return 404, None

    ret = 404
    if webc.login():
        ret, resp = webc.posts(cmd)
        return ret, resp
    return ret, None
    # print(resp)


def c_rs485_write(webc, num, data):
    ret, resp = c_rs485(webc, cmd_s_tmp, num, data)
    return ret, resp
    # print(resp)


def c_rs485_read(webc, num):
    ret, resp = c_rs485(webc, cmd_r_tmp, num, 'tt')
    if ret == 200:
        jl = json.loads(resp)
        print(resp)
        temp = jl['body']['rs485_data']
        # print(temp)
        # data = temp
        data = base64.b64decode(temp).decode()
        print(data)
        return ret, data
    return ret, None
    # print(resp)


# webc = WEBClient('http://192.168.6.31', 'admin', 'admin')
# c_rs485_write(webc, 0, '$001,01&')
# time.sleep(1)
# ret, data = c_rs485_read(webc, 0)
# print(ret)
# print(data)
# if data == '':
#     print('data')

# st = 'hello world!'.encode()#默认以utf8编码
# res = base64.b64encode(st)
# print(res.decode())#默认以utf8解码
# res = base64.b64decode(res)
# print(res.decode())#默认以utf8解码