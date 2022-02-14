#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import requests
import execjs

url = "http://www.iquanquanba.com/wp-content/themes/twentytwenty/assets/js/post.js"
# url = "http://tbfile.izuiyou.com/img/view/id/1660655354"

headers = {
    'user-agent': "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36",
    'referer': "http://www.iquanquanba.com/"
}

response = requests.request("GET", url, headers=headers)
print(response.url)
for key, value in response.cookies.items():
    print(key, value)

with open("post.js", "wb") as wf:
    wf.write(response.content)