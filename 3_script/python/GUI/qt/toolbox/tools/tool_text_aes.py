#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget
from ui_tool_text_aes import Ui_WidgetAES


class WidgetAES(QWidget, Ui_WidgetAES):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.comboBox_algorithm.addItems(["AES", "DES", "Blowfish", "CAST", "ChaCha20", "DES3", "RC2", "RC4"])
        self.comboBox_mode.addItems(["ECB", "CBC", "CTR", "CFB", "OFB"])
        self.comboBox_padding.addItems(["noPadding", "pkcs5/7Padding", "zeroPadding", "iso10126", "ansix923"])
        self.comboBox_block_length.addItems(["128位", "192位", "256位"])
        self.comboBox_output.addItems(["base64", "hex"])
        self.comboBox_charset.addItems(["GB2312(简体)", "GBK(简繁体)", "GB18030(中日韩)", "UTF-8(Unicode)", "ISO-8859-1(单字节)"])

        self.pushButton_encrypt.clicked.connect(self.encrypt)
        self.pushButton_decrypt.clicked.connect(self.decrypt)

    # 加密
    def encrypt(self):
        pass

    # 解密
    def decrypt(self):
        pass
