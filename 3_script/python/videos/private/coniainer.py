#!/usr/bin/env python3
# -*- encoding:utf-8 -*-

"""
@license:   (C) Copyright 2013-2017, Node Supply Chain Manager Corporation Limited.
@software:  PyCharm
@file:      python_coniainer.py
@author:    ziv
@time:      2022/2/24
@version:   v1.0.0
@desc:      脚本功能描述
"""

from lxml import etree


def load_html(path):
    with open(path, "r") as rf:
        return rf.read()


def html_to_dom(html):
    return etree.HTML(html)


def get_xpath_elements(dom, rule):
    elements = dom.xpath(rule)
    print(len(elements), elements)
    return elements


def get_container(dom):
    xpath_container = '//div[@class="container"]//div[@class="myui-panel-box clearfix"]'
    return get_xpath_elements(dom, xpath_container)


def get_item(element):
    title = element.xpath('.//h3/text()')
    boxs = element.xpath('.//div[@class="myui-vodlist__box"]')
    if len(title) == 1 and len(boxs) > 0:
        title = title[0].strip()
        print("item title:", title)
        for item in boxs:
            item_title = item.xpath('./a/@title')[0].strip()
            item_tag = item.xpath('./a/span[@class="pic-tag pic-tag-top"]/text()')[0].strip()
            item_text = item.xpath('./a/span[@class="pic-text text-right"]/text()')[0].strip()
            item_href = item.xpath('./a/@href')[0].strip()
            item_image = item.xpath('./a/@data-original')[0].strip()
            item_actor = item.xpath('.//p/text()')[0].strip()
            print(item_title, item_tag, item_text, item_href, item_image, item_actor)
            # result = zip(item_title, item_href, item_image, item_actor)
            # print(result)


if __name__ == "__main__":
    html = load_html("vod_15_page.html")
    dom = html_to_dom(html)
    dom_container = get_container(dom)
    print(dom_container)
    for row in dom_container:
        get_item(row)


    # dom_container_raw = get_container_row(dom)
    # print(dom_container_raw)

