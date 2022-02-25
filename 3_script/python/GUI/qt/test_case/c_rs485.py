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
'''
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_send_rs485",
    "id":123,
    "body":{
        "source":0,
        "rs485_data":"JDAwMSwwMSY="
        }
    }
}
           
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_read_rs485",
    "id":111,
    "body":{
        "source":0,
        "rs485_data":"dHQ="
        }
    }
}

{"type":"register_listen_msg","id":1,"module":"TCP_BUS_REQUEST","block_flag":1,"body":{"register_flag":1,"listen_msg":["EVS_RS485_READ"]}}
'''
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
    print('c_rs485 %s' % cmd)
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
    print("485 send:", num, data, "result:", ret, resp)
    return ret, resp
    # print(resp)


def c_rs485_read(webc, num):
    ret, resp = c_rs485(webc, cmd_r_tmp, num, 'tt')
    print("485 reci:", ret, resp)
    if ret == 200:
        print(resp)
        if resp is None or len(resp) == 0:
            return 404, None
        try:
            jl = json.loads(resp)
            if int(jl['state']) != 200:
                return jl['state'], None
            temp = jl['body']['rs485_data']
            # print(temp)
            # data = temp
            data = base64.b64decode(temp).decode()
            print("485 reci:", temp, "decode:", data)
            return ret, data
        except:
            return 404, None
    return ret, None
    # print(resp)


# 'JDAwMSwwMSY=', 'JDAwMSwwMiY='
def c_rs485_test(webc, num1, num2, data1='$001,01&', data2='$001,02&'):
    c_rs485_write(webc, num1, data1)
    time.sleep(0.5)
    ret_1, data_read_1 = c_rs485_read(webc, num2)
    if ret_1 != 200:
        return -2
    time.sleep(0.5)
    c_rs485_write(webc, num1, data2)
    time.sleep(0.5)
    ret_2, data_read_2 = c_rs485_read(webc, num2)
    if ret_2 != 200:
        return -2
    if data_read_1 != data_read_2:
        return 0
    return -1


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