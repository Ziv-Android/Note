#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
from urllib.parse import urlparse

from log import Log

# print(__file__)
# print(os.path.abspath('../../temp'))
# print(os.path.join(os.path.abspath('../..'), 'log', "sss"))
# log = Log()
# log.i("测试logging封装")
# log.e(__file__)
# log.w("sanbian")
# url_parsed = urlparse("http://192.168.0.11:1234/library.php?username=111")
url_parsed = urlparse("https://open.vzpdns.com")
print(url_parsed)
print(type(url_parsed.path))
print(f"{url_parsed.scheme}://{url_parsed.netloc} {url_parsed.path}")

path = os.path.join(os.path.abspath('../..'), "assets", "Aes.js")
print(path)

