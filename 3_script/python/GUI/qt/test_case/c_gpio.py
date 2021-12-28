#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import time
from libutils.webclient import WEBClient

'''
# 测试IO
# request
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_gpio_test_ctrl",
    "body":{
        "io_opera":2,
        "io_type":1,
        "io_number":0,
        "io_status":0
    }
}

字段名称:body.io_opera
字段含义:IO操作
取值范围:1=set,2=get

字段名称:body.io_number
字段含义:IO-IN\OUT序号
取值范围:0...n

字段名称:body.io_type
字段含义:IO类型
取值范围:1=IN;2=OUT;3=RESET

字段名称:body.io_status
字段含义:IO操作
取值范围:0=low,1=high,2=square

# response
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_gpio_test_ctrl"
    "state":200,
    "err_msg":"All done",
    "body":{
        "io_status":1
    }
}
字段名称:body.io_status
字段含义:操作返回.如果opera=set,返回io_status,否则无此字段
取值范围:0=low,1=high
'''

cmd_tmp = '''{
            "module":"EVS_BUS_REQUEST",
            "type":"evs_gpio_test_ctrl",
            "body":{
                "io_opera":%d,
                "io_type":%d,
                "io_number":%d,
                "io_status":%d
            }
        }'''

cmd_io_out_tmp = '''{
            "module":"EVS_BUS_REQUEST",
            "type":"evs_ctrl_gpioout",
            "body":{
                "source":%d,
                "gpio_out_status":%d,
                "out_delay_times":1000
            }
        }'''

cmd_io_out_value = '''{
            "module":"EVS_BUS_REQUEST",
            "type":"evs_get_gpioout",
            "body":{
                "source":%d
            }
        }'''

cmd_io_in_value = '''{
            "module":"EVS_BUS_REQUEST",
            "type":"evs_get_gpioin",
            "body":{
                "source":%d
            }
        }'''

def c_gpio(webc, opera, type, number, status):
    cmd = cmd_tmp % (opera, type, number, status)
    # print('c_gpio %s' % cmd)
    if webc == None:
        print('webc none')
        return 404, None

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret, resp
    # print(resp)


def c_gpio_set(webc, number, status):
    ret, resp = c_gpio(webc, 1, 2, number, status)
    print("c_gpio_set", ret, resp)
    return ret


def c_gpio_get(webc, type, number):
    ret, resp = c_gpio(webc, 2, type, number, 0)
    print("c_gpio_get", ret, resp)
    if ret == 200:
        print(resp)
        jr = json.loads(resp)
        return int(jr['body']['io_status'])
    return -1

def c_gpio_out(webc,source, status):
    cmd = cmd_io_out_tmp % (source, status)
    if webc == None:
        print('webc none')
        return 404, None

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    if ret == 200:
        print(resp)
        jr = json.loads(resp)
        return int(jr['state'])
    return -1

def c_io_out_get(webc, source):
    cmd = cmd_io_out_value % (source)
    if webc == None:
        print('webc none')
        return 404, None

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)

    if ret == 200:
        print(resp)
        jr = json.loads(resp)
        return int(jr['body']['gpio_out_status'])
    return -1


def c_io_in_get(webc, source):
    cmd = cmd_io_in_value % (source)
    if webc == None:
        print('webc none')
        return 404, None

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)

    if ret == 200:
        print(resp)
        jr = json.loads(resp)
        return int(jr['body']['gpio_in_status'])
    return -1


