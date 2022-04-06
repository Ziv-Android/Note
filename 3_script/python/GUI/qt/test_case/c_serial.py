#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import re

from c_rs485 import *
from c_led import *

cmd_tmp = '{"type":"get_another_device_ip","module":"SERIAL_COMM_MSG"}'


def c_serial_rs485(webc, num_serial, sdata):
    ret, _ = c_rs485_write(webc, 0, sdata)
    if ret != 200:
        return False, -1
    try:
        js = json.loads(_)
        if js['state'] != 200:
            return False, -1
    except:
        return False, -1

    if num_serial == 2:
        time.sleep(1)
        ret, rdata = c_rs485_read(webc, 0)
        if ret == 200:
            return True, rdata
        if sdata != rdata:
            return False, -1
    return True, 0


def c_serial_led(webc):
    return c_led(webc, value=13, mode=2)


def c_serial_another_ip(webc):
    if webc == None:
        print('webc none')
        return 404

    if webc.login():
        ret, resp = webc.posts(cmd_tmp)
        try:
            js = json.loads(resp)
            if js['state'] != 200:
                return False
            else:
                ip = js['body']['ip']
                return isLegalIp(ip)
        except:
            return False
    return False
    # print(resp)


def isLegalIp(ip):
    result = re.match(r'((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})(\.((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})){3}:?\d*',
                      ip) is not None
    return result
