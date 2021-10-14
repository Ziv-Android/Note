#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import win32api
import win32gui

'''
HWND：指定父窗口句柄
Operation：指定动作， 譬如"edit",“explore”,“open”,“find”,“print”,“NULL”
FileName：指定要打开的文件或程序
Parameters：指定打开程序所需参数
Directory：缺省目录
ShowCmd：打开选项，可选值:
'''

filePath = r'D:\WXWork\WXWork.exe'
fileName = r'企业微信'

# 打开软件
result = win32api.ShellExecute(1, 'open', filePath, '', '', 1)
print("Open", filePath, result)

# 获取窗口句柄
para_hld = win32gui.FindWindow(None, fileName)
print(fileName, para_hld)

title = win32gui.GetWindowText(para_hld)
classname = win32gui.GetClassName(para_hld)
print("windows handler:{0}; title:{1}; classname:{2}".format(para_hld, title, classname))

# 枚举窗口所有句柄
# hWndList = []
# win32gui.EnumWindows(lambda hwnd, param: param.append(hwnd), hWndList)
# print(hWndList)
# for hwnd in hWndList:
#     title = win32gui.GetWindowText(hwnd)
#     print(title)

# 将指定窗体设置到最顶层，并且激活该窗口
win32api.keybd_event(13, 0, 0, 0) #
win32gui.SetForegroundWindow(para_hld)

msg = win32gui.FindWindowEx(para_hld, 0, None, "消息")
print(msg)
