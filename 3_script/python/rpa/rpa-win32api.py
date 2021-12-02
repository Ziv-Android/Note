#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from ctypes import windll

import win32api
import win32con
import win32gui
import win32clipboard

import time

import xlrd
import xlwt

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


# 1 鼠标
# 1.1 获取当前鼠标所在屏幕坐标
def get_mouse_location():
    pos = win32gui.GetCursorPos()
    print("当前鼠标坐标", pos)
    return pos


# 1.2 鼠标移动至(x, y)处
def mouse_move(x, y):
    # 鼠标移动到坐标(x,y)处
    # windll.user32.SetCursorPos(x, y)
    win32api.SetCursorPos((x, y))


# 1.3 点击鼠标左键
def mouse_click_left(count=1, t=0.5):
    for i in range(count):
        win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN | win32con.MOUSEEVENTF_LEFTUP, 0, 0, 0, 0)
        time.sleep(t)


# 1.4 点击鼠标右键键
def mouse_click_right(count=1, t=0.5):
    for i in range(count):
        win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN | win32con.MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0)
        time.sleep(t)


# 2 键盘
# 2.1 键盘单独按键
def keyboard(key):
    win32api.keybd_event(key, 0, 0, 0)
    time.sleep(0.02)
    win32api.keybd_event(key, 0, win32con.KEYEVENTF_KEYUP, 0)


# 2.2 键盘组合按键
# 2.2.1 全选 ctrl + a
def keyboard_ctrl_a():
    win32api.keybd_event(17, 0, 0, 0)
    win32api.keybd_event(65, 0, 0, 0)
    win32api.keybd_event(65, 0, win32con.KEYEVENTF_KEYUP, 0)
    win32api.keybd_event(17, 0, win32con.KEYEVENTF_KEYUP, 0)


# 2.2.2 复制 ctrl + c
def keyboard_ctrl_c():
    win32api.keybd_event(17, 0, 0, 0)
    win32api.keybd_event(67, 0, 0, 0)
    win32api.keybd_event(67, 0, win32con.KEYEVENTF_KEYUP, 0)
    win32api.keybd_event(17, 0, win32con.KEYEVENTF_KEYUP, 0)


# 2.2.3 粘贴 ctrl + v
def keyboard_ctrl_v():
    win32api.keybd_event(17, 0, 0, 0)
    win32api.keybd_event(86, 0, 0, 0)
    win32api.keybd_event(86, 0, win32con.KEYEVENTF_KEYUP, 0)
    win32api.keybd_event(17, 0, win32con.KEYEVENTF_KEYUP, 0)


# 3 剪贴板
# 3.1 设置剪贴板内容
def clipboard_set_text(msg):
    win32clipboard.OpenClipboard()
    win32clipboard.EmptyClipboard()
    print("剪贴板内容", "set", msg)
    win32clipboard.SetClipboardText(msg)
    win32clipboard.CloseClipboard()
    time.sleep(1)


# 3.2 获取剪贴板内容
def clipboard_get_data():
    win32clipboard.OpenClipboard()
    msg = win32clipboard.GetClipboardData()
    win32clipboard.CloseClipboard()
    print("剪贴板内容", "get", msg)
    return msg


# 4 依赖剪贴板输入内容
def input_msg(msg):
    keyboard_ctrl_a()
    clipboard_set_text(msg)
    keyboard_ctrl_v()
    time.sleep(0.5)


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

# 点击左上角人员搜索框
mouse_move(left + 110, top + 40)
mouse_click_left()

input_msg("文件传输助手")

# 点击第一个搜索结果
mouse_move(left + 110, top + 110)
mouse_click_left()
time.sleep(1)
# 点击输入区域
mouse_move(right - 50, bottom - 50)
mouse_click_left()

input_msg("这是一条测试消息 + #……*%￥2 = HelloWorld http://  ^!``?><<>--")
# 点击发送
mouse_move(right - 30, bottom - 20)
mouse_click_left()

# 枚举窗口所有句柄
# hWndList = []
# win32gui.EnumWindows(lambda hwnd, param: param.append(hwnd), hWndList)
# print(hWndList)
# for hwnd in hWndList:
#     title = win32gui.GetWindowText(hwnd)
#     print(title)

# msg = win32gui.FindWindowEx(para_hld, 0, None, "消息")
# print(msg)
