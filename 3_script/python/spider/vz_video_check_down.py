#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import threading
import time
import sys

import requests
from lxml import etree


def request_video_list():
    resp = requests.get(url_host)
    resp.encoding = "utf-8"
    root = etree.HTML(resp.text)
    return root.xpath('//a/text()')


def download_video_list():
    while True:
        if len(download_urls) > 0:
            url = download_urls.pop(0)
            sn_url = url.split("_")[0]
            if sn_url in sn:
                with open(url, "wb") as f:
                    resp = requests.get(url_host + url)
                    f.write(resp.content)
                print("下载：", url)
        else:
            time.sleep(1)


if __name__ == "__main__":
    url_host = "http://192.168.30.16:8050/318/"
    list_old = request_video_list()
    sn = sys.argv[1:]
    download_urls = []
    t_download = threading.Thread(target=download_video_list)
    t_download.start()
    while True:
        time.sleep(3)
        list_new = request_video_list()
        diff = list(set(list_new).difference(set(list_old)))
        list_old = list_new
        if len(diff) > 0:
            download_urls = list(set(download_urls).union(set(diff)))

