#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# https://zhuanlan.zhihu.com/p/302592540

import win32gui
import pyautogui

size_x, size_y = pyautogui.size()
print(size_x, size_y)
position = pyautogui.position()
print(position)
pyautogui.moveTo(size_x/2, size_y/2, duration=1)
pyautogui.moveRel(100, -200, duration=0.5)
pyautogui.click(button="right")
pyautogui.click(size_x/2, size_y/2, clicks=1, interval=0.2, duration=0.5)
pyautogui.dragTo(size_x/2, size_y/2)
pyautogui.locateCenterOnScreen("pic/")































