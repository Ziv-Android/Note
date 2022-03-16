# -*- ecoding: utf-8 -*-
# @ModuleName: StudentSystem
# @Author: Sail
# @Time: 2021/10/11 22:08
# Python骚操作之海量性感妹子图爬虫实战精讲
# 爬虫技术 : 获取数据的程序
# 确定网站 相互了解  筛选功能 保存数据
# BS4 xpath json  re pyquery
import os

import requests  # Python向服务器发起网络请求
from lxml import etree
from urllib import request

# 1.到网站里面确定一个网址
url = 'https://www.huya.com/g/4079'
my_header = {'User-Agent': 'Mozilla/5.0'}
# 2.用Python跟这个网址先做一个了解
result = requests.get(url=url, headers=my_header).text
# 3.在网站源码内筛选我们需要的数据  json xpath re bs4 pyquery
data = etree.HTML(result)
demo = data.xpath('//img[@class="pic"]')

path_dir = os.path.join(os.getcwd(), "meizi")
if not os.path.exists(path_dir):
    os.makedirs(path_dir)

# 4.保存数据
for i in demo:
    newUrl = i.xpath('./@data-original')[0]
    newName = i.xpath('./@alt')[0]
    path = os.path.join(path_dir, f"{newName}.jpg")
    # print(newUrl, path)
    request.urlretrieve(newUrl, path)
    print("<%s>下载完毕!" % newName)
