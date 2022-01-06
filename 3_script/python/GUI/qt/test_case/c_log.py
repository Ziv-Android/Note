#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
{
    "module":"BUS_WEB_REQUEST",
    "type":"log_search",
    "body":{
        "type_mask":28,
        "start_time":{
            "sec":1637650130,
            "usec":0
        },
        "end_time":{
            "sec":1637736530,
            "usec":0
        },
        "limit":100,
        "qnode":{
            "qtype":1,
            "is_first":0,
            "max_id":0,
            "min_id":0,
            "start_id":0
        }
    }
}
'''
import json
import time

from libutils.webclient import WEBClient

cmd_tmp = '''{
                "module":"BUS_WEB_REQUEST",
                "type":"log_search",
                "body":{
                    "type_mask":%d,
                    "start_time":{
                        "sec":%d,
                        "usec":0
                    },
                    "end_time":{
                        "sec":%d,
                        "usec":0
                    },
                    "limit":100,
                    "qnode":{
                        "qtype":1,
                        "is_first":1,
                        "max_id":0,
                        "min_id":0,
                        "start_id":0
                    }
                }
            }'''

def c_log_sys(webc):
    cmd = cmd_tmp % (12, time.time()-24*60*60, time.time())
    # print('c_rs485 %s' % cmd)
    if webc is None:
        print('webc none')
        return 404, None

    ret = 404
    if webc.login():
        ret, resp = webc.posts(cmd)
        return ret, resp
    return ret, None

# webc = WEBClient('http://192.168.1.100', 'admin', 'admin')
# ret, resp = c_log_sys(webc)
# print(ret)
# print(resp)
# jl = json.loads(resp)
# for nn in jl['body']['logs']:
#     print(nn)
