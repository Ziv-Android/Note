#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from ctypes import windll

import win32api
import win32con
import win32gui

import time

import pyautogui as pag
import pyperclip as ppc

# m = pymouse.PyMouse()
# k = pykeyboard.PyKeyboard()

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

# 将指定窗体设置到最顶层，并且激活该窗口
win32gui.ShowWindow(para_hld, win32con.SW_RESTORE)
win32gui.SetForegroundWindow(para_hld)

title = win32gui.GetWindowText(para_hld)
classname = win32gui.GetClassName(para_hld)
print("windows handler:{0}; title:{1}; classname:{2}".format(para_hld, title, classname))

# 获取窗口左上角和右下角坐标
left, top, right, bottom = win32gui.GetWindowRect(para_hld)
print(left, top, right, bottom)

# 鼠标移动到坐标(x,y)处
windll.user32.SetCursorPos(left + 110, top + 40)
# 单机鼠标左键
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, left + 110, top + 40)
time.sleep(0.25)
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, left + 110, top + 40)

# 不支持中文
# pag.typewrite("")

ppc.copy('郑')
# ppc.paste()
win32api.keybd_event(17, 0, 0, 0)
win32api.keybd_event(86, 0, 0, 0)
win32api.keybd_event(86, 0, win32con.KEYEVENTF_KEYUP, 0)
win32api.keybd_event(17, 0, win32con.KEYEVENTF_KEYUP, 0)

# 鼠标移动到坐标(x,y)处
windll.user32.SetCursorPos(left + 110, top + 110)
# 单机鼠标左键
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, left + 110, top + 110)
time.sleep(0.25)
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, left + 110, top + 110)

# 鼠标移动到坐标(x,y)处
windll.user32.SetCursorPos(right - 50, bottom - 50)
# 单机鼠标左键
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, right - 50, bottom - 50)
time.sleep(0.25)
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, right - 50, bottom - 50)

pag.typewrite("Hello world")
time.sleep(1)

# 鼠标移动到坐标(x,y)处
windll.user32.SetCursorPos(right - 30, bottom - 20)
# 单机鼠标左键
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, right - 30, bottom - 20)
time.sleep(0.25)
win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, right - 30, bottom - 20)

# time.sleep(0.5)
# win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, left + 130, top + 60)
# time.sleep(0.25)
# win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, left + 130, top + 60)
# time.sleep(5)
# # 鼠标点击，x,y是坐标位置 button 1表示左键，2表示点击右键 n是点击次数，默认是1次，2表示双击
# m.click(left + 110, top + 40, 1)
# m.click(left + 110, top + 40, 1)
#
# # 获取当前的鼠标位置
# nowP = m.position()

# 枚举窗口所有句柄
# hWndList = []
# win32gui.EnumWindows(lambda hwnd, param: param.append(hwnd), hWndList)
# print(hWndList)
# for hwnd in hWndList:
#     title = win32gui.GetWindowText(hwnd)
#     print(title)


# win32api.keybd_event(13, 0, 0, 0)

# msg = win32gui.FindWindowEx(para_hld, 0, None, "消息")
# print(msg)
