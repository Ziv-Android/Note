#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from pywinauto import application
from pywinauto import mouse

filePath_wxwork = r'D:\WXWork\WXWork.exe'
filePath_wechat = r'D:\WeChat\WeChat.exe'
fileName_wxwork = r'企业微信'
fileName_wechat = r'微信'


def get_element_postion(element):
    element_position = element.rectangle()
    center_position = (int((element_position.left + element_position.right) / 2),
                       int((element_position.top + element_position.bottom) / 2))
    return center_position


app = application.Application(backend='uia').start(filePath_wechat)
window = app.window(title=fileName_wechat, class_name="WeChatMainWndForPC")


