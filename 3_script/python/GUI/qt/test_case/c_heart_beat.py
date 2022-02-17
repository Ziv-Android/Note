#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from libutils.webclient import WEBClient

'''
# 心跳
# request
{"type":"is_login_timeout","module":"BUS_WEB_REQUEST","body":{}}

# response
{"body":{"current_datetime":"2022-02-15 17:16:35"},"err_msg":"All done","state":200,"type":"is_login_timeout"}

'''

cmd = '''{"type":"is_login_timeout","module":"BUS_WEB_REQUEST","body":{}}'''


def c_heart(webc):
    if webc == None:
        print('webc none')
        return 404

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret
