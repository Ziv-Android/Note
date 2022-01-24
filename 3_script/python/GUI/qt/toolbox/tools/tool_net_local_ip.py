#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
import base64
import os.path
import time

import netifaces
import socket
import threading
from PyQt5.QtWidgets import QWidget, QFileDialog, QMessageBox
from ui_tool_net_local_ip import Ui_WidgetLocalDevice


class WidgetLocalDevice(QWidget, Ui_WidgetLocalDevice):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.comboBox.addItem(get_ip())
        self.searchBtn.clicked.connect(self.start_search)

    def start_search(self):
        pass



def get_ip():
    addrs = []
    try:
        for interface in netifaces.interfaces():
            if netifaces.AF_INET in netifaces.ifaddresses(interface).keys():
                host = netifaces.ifaddresses(interface)[netifaces.AF_INET][0]['addr']
                if host == '127.0.0.1':
                    continue
                addrs.append(host)
        return addrs
    except Exception as e:
        print("get local IP exception", e)
        return addrs


if __name__ == "__main__":
    print(get_ip())
