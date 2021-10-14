#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tkinter import *
import time


class WindowConfig:
    def __init__(self, window):
        self.window = window

    def init_window(self):
        self.window.title("Android设备控制器_v1.0_By:ziv")
        self.window.geometry('640x320+10+10')

    def adb_root(self):
        print("deb root")
        # 获取已连接设备

    def adb_devices(self):
        print("adb devices")


    def adb_shell_input_keyevent(self, keycode):
        print("", keycode)

    # 获取当前时间
    def get_current_time(self):
        current_time = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time()))
        return current_time


def gui_start():
    window = Tk()

    config = WindowConfig(window)
    config.init_window()

    window.mainloop()


gui_start()
