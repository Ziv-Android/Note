#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
讯飞配音
"""

'''
Accept: */*
Accept-Encoding: identity;q=1, *;q=0
Accept-Language: zh-CN,zh;q=0.9
Cache-Control: no-cache
Host: proxyweb.peiyinge.com
Pragma: no-cache
Proxy-Connection: keep-alive
Range: bytes=0-
Referer: http://peiyin.xunfei.cn/
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36
'''

url = 'http://proxyweb.peiyinge.com/synth?uid=&ts=1634522283&sign=264b54a5576928d081936235fd644f59&vid=20068&f=v2&cc=1432&sid=80725E1CAA2758C25E44954E69E02594&volume=20&speed=0&content=%5Bte50%5D%E6%B5%8B%E8%AF%95%E6%96%87%E6%9C%AC%E9%98%85%E8%AF%BB%E8%83%BD%E5%8A%9B&listen=0'

'''
http://proxyweb.peiyinge.com/synth?uid=&ts=1634544919&sign=73bfbda3927d6f96f38cc3540a8bbd39&vid=20068&f=v2&cc=1432&sid=80725E1CAA2758C25E44954E69E02594&volume=20&speed=0&content=%5Bte50%5D%E6%B5%8B%E8%AF%95%E6%96%87%E6%9C%AC%E9%98%85%E8%AF%BB%E8%83%BD%E5%8A%9B&listen=1
uid: 
ts: 1634522283
sign: 264b54a5576928d081936235fd644f59
vid: 20068
f: v2
cc: 1432
sid: 80725E1CAA2758C25E44954E69E02594
volume: 20
speed: 0
content: [te50]测试文本阅读能力
listen: 0
'''

# 千雪
'''
uid: 
ts: 1634523657
sign: 34233671493d6d2392602c8791e952f0
vid: 20068
f: v2
cc: 0000
sid: 80725E1CAA2758C25E44954E69E02594
volume: 20
speed: 0
content: [te50]试文本阅读能力
listen: 0
'''

import requests
import time

HOST = 'http://proxyweb.peiyinge.com/synth'
HEADERS = {
    'Host': 'proxyweb.peiyinge.com',
    'Range': 'bytes=0-',
    'Referer': 'http://peiyin.xunfei.cn/',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.81 Safari/537.36',
}


def get_params(sign, cc, text):
    query_params = {
        'uid': '',
        'ts': int(time.time()),
        'sign': sign,
        'vid': 20068,
        'f': 'v2',
        'cc': cc,
        'sid': '80725E1CAA2758C25E44954E69E02594',
        'volume': 20,
        'speed': 0,
        'content': '[te50]' + text,
        'listen': 1
    }
    print(query_params)
    return query_params


def write_to_file(text, r):
    with open(text + '.mp3', 'wb') as wf:
        for chunk in r.iter_content(chunk_size=1024):
            if chunk:
                wf.write(chunk)


def get_voice(text):
    params = get_params("73bfbda3927d6f96f38cc3540a8bbd39", 1432, text)
    r = requests.get(HOST, headers=HEADERS, params=params, stream=True)
    print(r.url)
    write_to_file(text, r)


get_voice("测试数据")
