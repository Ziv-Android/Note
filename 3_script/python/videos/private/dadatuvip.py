#!/usr/bin/env python3
# -*- encoding:utf-8 -*-

"""
@license:   (C) Copyright 2013-2017, Node Supply Chain Manager Corporation Limited.
@software:  PyCharm
@file:      python_dadatuvip.py
@author:    ziv
@time:      2022/2/21
@version:   v1.0.0
@desc:      脚本功能描述
"""

import requests

URL_HOME = "https://dadatutv.vip/"
URL_NEW = URL_HOME + "new.php"
URL_HOT = URL_HOME + "hot.php"
URL_VOD = URL_HOME + "vod/%s.html"

headers = {
    'user-agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36",
}

session = requests.session()

result_home = session.get(URL_HOME, headers=headers)
if result_home.status_code == 200:
    with open("home_page.html", "w") as wf:
        wf.write(result_home.content.decode())

# 1， 5， 6， 7， 8，10， 2， 13， 14， 15， 16， 3， 4， new， hot
print("finish:", "home")

result_hot = session.get(URL_HOT, headers=headers)
if result_hot.status_code == 200:
    with open("hot_page.html", "w") as wf:
        wf.write(result_hot.content.decode())
print("finish:", "hot")

result_new = session.get(URL_NEW, headers=headers)
if result_new.status_code == 200:
    with open("new_page.html", "w") as wf:
        wf.write(result_new.content.decode())
print("finish:", "new")

for i in range(1, 17):
    result_vod = session.get(URL_VOD % str(i), headers=headers)
    if result_vod.status_code == 200:
        with open(f"vod_{i}_page.html", "w") as wf:
            wf.write(result_vod.content.decode())
    print("finish:", "vod", i)

