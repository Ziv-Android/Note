#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import json
import time

from c_protocol import *
from c_rs485 import *
from oqc_tool import *
from libutils.webclient import WEBClient

# {"type":"get_platform","module":"BUS_REQUEST_MSG"}:
# {"body":{"lib_name":"libcustom_lifang.so","platform_name":"lifang"},"err_msg":"All Done","state":200,"type":"get_platform"}

# {"type": "set_platform", "module": "BUS_REQUEST_MSG","body": {"platform_name": "lifang", "lib_name": "libcustom_lifang.so"}}
# {"err_msg":"All Done","state":200,"type":"set_platform"}
# 设置定制协议


def cfg_factory_param_customer(webc, name, library):
    scmd = '''{
                "module": "BUS_REQUEST_MSG",
                "type": "set_platform", 
                "body": {"platform_name": "%s", "lib_name": "%s"}
        }''' % (name, library)
    if webc is None:
        print('webc none')
        return False

    ret = 404
    if not webc.login():
        print('webc.login failed')
        return False

    print('customer %s,library %s' % (name, library))
    ret, resp = webc.posts(scmd)
    if ret != 200:
        print('webc.posts scmd failed.')
        return False

    rcmd = '''{"module":"BUS_REQUEST_MSG","type":"get_platform"}'''
    ret, resp = webc.posts(rcmd)
    if ret != 200:
        print('webc.posts rcmd failed.')
        return False
    try:
        jl = json.loads(resp)
        pname = jl['body']['platform_name']
        libname = jl['body']['lib_name']
        if name != pname or library != libname:
            return False

        return True
    except:
        return False


# {"type":"set_lens_mode","module":"SERIAL_COMM_MSG","body":{"mode":0,"max_plate_num":3,"is_double":0}}:
# {"body":{"type":"set_lens_mode"},"err_msg":"All Done","state":200,"type":"set_lens_mode"}

# {"type": "get_lens_mode", "module": "SERIAL_COMM_MSG"}:
# {"body":{"is_double":0,"max_plate_num":3,"mode":0,"type":"get_lens_mode"},"err_msg":"All Done","state":200,"type":"get_lens_mode"}
# 设置镜头型号:镜头类型, 双目
def cfg_factory_param_product(webc, num_max_stop, lens, dlens):
    scmd = '''{
                "module":"SERIAL_COMM_MSG",
                "type":"set_lens_mode",
                "body":{"max_plate_num":%d,"mode":%d,"is_double":%d}
        }''' % (num_max_stop, lens, dlens)
    if webc is None:
        print('product webc none')
        return False

    ret = 404
    if not webc.login():
        print('product webc.login failed')
        return False

    print('product is double %d, lens %d' % (dlens, lens))
    ret, resp = webc.posts(scmd)
    if ret != 200:
        print('product webc.posts scmd failed.')
        return False

    rcmd = '''{"module": "SERIAL_COMM_MSG", "type": "get_lens_mode"}'''
    ret, resp = webc.posts(rcmd)
    if ret != 200:
        print('product webc.posts rcmd failed.')
        return False

    try:
        print(resp)
        jl = json.loads(resp)
        mode = int(jl['body']['mode'])
        is_double = int(jl['body']['is_double'])
        if mode != lens or dlens != is_double:
            print('mode != type or dlens != is_double')
            return False

        return True
    except:
        return False


# 双目，接了485的=1.100，未接485=1.101
def cfg_factory_param_dlens(cp, devs, username, password, callback=None):
    gateway = '192.168.1.11'
    netmask = '255.255.128.0'
    temp_host = ['192.168.1.98', '192.168.1.99']
    host_on_camera = ['192.168.1.100', '192.168.1.101']
    change_result = 0
    num_check_485_error = 0

    for time_index in range(30):
        time.sleep(1)
        if len(devs) >= 2:
            break

    if len(devs) < 2:
        if callback is not None:
            callback("修改失败", host_on_camera[0])
        return

    print('update %s host %s' % (devs[0]['s'], temp_host[0]))
    objdll.VzLPRClient_UpdateNetworkParam(devs[0]['sh'], devs[0]['sl'],
                                          temp_host[0].encode('utf-8'),
                                          gateway.encode('utf-8'),
                                          netmask.encode('utf-8'))
    print('update %s host %s' % (devs[1]['s'], temp_host[1]))
    objdll.VzLPRClient_UpdateNetworkParam(devs[1]['sh'], devs[1]['sl'],
                                          temp_host[1].encode('utf-8'),
                                          gateway.encode('utf-8'),
                                          netmask.encode('utf-8'))

    # 双目验证两路485是否都失败，并将485通过的一路设置为近端192.168.1.100
    dev = devs[0]
    if callback is not None:
        callback("正在检查485链接", host_on_camera[0])
    url = 'http://%s' % temp_host[0]
    webc = WEBClient(url, username, password)
    for time_index in range(30):
        time.sleep(1)
        if not webc.login():
            print("waiting", temp_host[0], "restart", time_index)
            continue

        data = c_rs485_test(webc, 0, 0)
        print("485检测1:", dev, data)
        if data == 0:
            if callback is not None:
                callback("正在修改", host_on_camera[0])
            # 近端1.100
            print('update %s host %s' % (dev['s'], host_on_camera[0]))
            objdll.VzLPRClient_UpdateNetworkParam(dev['sh'], dev['sl'],
                                                  host_on_camera[0].encode('utf-8'),
                                                  gateway.encode('utf-8'),
                                                  netmask.encode('utf-8'))
            num_max_stop = cp.get_capacity_num('num_max_stop')
            cfg_factory_param_product(webc, num_max_stop, 0, 1)  # 近端，双目，短焦
            change_result += 1
        else:
            num_check_485_error = 1
        break

    if num_check_485_error == 1:
        dev = devs[1]
        url = 'http://%s' % temp_host[1]
        webc = WEBClient(url, username, password)
        for time_index in range(30):
            time.sleep(1)
            if not webc.login():
                print("waiting", temp_host[1], "restart", time_index)
                continue

            data = c_rs485_test(webc, 0, 0)
            print("485检测2:", dev, data)
            if data == 0:
                if callback is not None:
                    callback("正在修改", host_on_camera[0])
                # 近端1.100
                print('update %s host %s' % (dev['s'], host_on_camera[0]))
                objdll.VzLPRClient_UpdateNetworkParam(dev['sh'], dev['sl'],
                                                      host_on_camera[0].encode('utf-8'),
                                                      gateway.encode('utf-8'),
                                                      netmask.encode('utf-8'))
                num_max_stop = cp.get_capacity_num('num_max_stop')
                cfg_factory_param_product(webc, num_max_stop, 0, 1)  # 近端，双目，短焦
                change_result += 1
            else:
                num_check_485_error = 2
            break

    # 两路485检测都失败，直接提示错误
    if num_check_485_error == 2 or change_result == 0:
        if callback is not None:
            callback("485未连接或485模块异常", host_on_camera[0])
        return

    if callback is not None:
        callback("正在修改", host_on_camera[0])
    # 不是两路485检测都失败的前提下，设置远端192.168.1.101
    if dev == devs[1]:
        dev = devs[0]
    else:
        dev = devs[1]
    print('update %s host %s' % (dev['s'], host_on_camera[1]))
    objdll.VzLPRClient_UpdateNetworkParam(dev['sh'], dev['sl'],
                                          host_on_camera[1].encode('utf-8'),
                                          gateway.encode('utf-8'),
                                          netmask.encode('utf-8'))
    url = 'http://%s' % host_on_camera[1]
    webc = WEBClient(url, username, password)
    for time_index in range(30):
        time.sleep(1)
        if not webc.login():
            print("waiting", host_on_camera[1], "restart", time_index)
            continue

        num_max_stop_long = cp.get_capacity_num('num_max_stop_long')
        cfg_factory_param_product(webc, num_max_stop_long, 1, 1)  # 远端，双目，长焦
        change_result += 1
        break

    if change_result == 2:
        if callback is not None:
            callback("修改成功", host_on_camera[0])
    else:
        if callback is not None:
            callback("修改失败", host_on_camera[0])
