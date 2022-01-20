#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QWidget
from ui_tool_text_aes import Ui_WidgetAES

from Cryptodome.Cipher import AES, DES, Blowfish, DES3, CAST, ChaCha20, ARC2, ARC4
from Cryptodome.PublicKey import RSA
from Cryptodome.Util.Padding import pad, unpad  # 填充方式
from binascii import b2a_hex, a2b_hex
import base64


class WidgetAES(QWidget, Ui_WidgetAES):
    algorithm_list = ["AES", "DES", "Blowfish", "CAST", "DES3", "RC2"]
    mode_base = ["ECB", "CBC", "CFB", "OFB", "CTR", "OPENPGP"]
    mode_aes = [*mode_base, "CCM", "EAX", "SIV", "GCM", "OCB"]
    mode_other = [*mode_base, "EAX"]

    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.cryptos = None
        self.mode = None

        self.comboBox_algorithm.addItems(WidgetAES.algorithm_list)
        self.comboBox_padding.addItems(["noPadding", "pkcs5/7Padding", "zeroPadding", "iso7816", "ansix923"])
        self.comboBox_block_length.addItems(["128位", "192位", "256位"])
        self.comboBox_output.addItems(["base64", "hex"])
        self.comboBox_charset.addItems(["GB2312(简体)", "GBK(简繁体)", "GB18030(中日韩)", "UTF-8(Unicode)", "ISO-8859-1(单字节)"])

        self.comboBox_algorithm.currentIndexChanged.connect(self.algorithm_changed)
        self.comboBox_mode.currentIndexChanged.connect(self.mode_changed)
        self.comboBox_padding.currentIndexChanged.connect(self.mode_changed)
        self.comboBox_block_length.currentIndexChanged.connect(self.mode_changed)

        self.algorithm_changed()

        self.pushButton_encrypt.clicked.connect(self.encrypt)
        self.pushButton_decrypt.clicked.connect(self.decrypt)

    # 算法变化
    def algorithm_changed(self):
        print("algorithm_changed")
        current_algorithm = self.comboBox_algorithm.currentText()
        self.comboBox_mode.clear()
        if current_algorithm == "AES":
            self.comboBox_mode.addItems(WidgetAES.mode_aes)
            self.cryptos = AES
        else:
            self.comboBox_mode.addItems(WidgetAES.mode_other)
            if current_algorithm == "DES":
                self.cryptos = DES
            elif current_algorithm == "Blowfish":
                self.cryptos = Blowfish
            elif current_algorithm == "CAST":
                self.cryptos = CAST
            elif current_algorithm == "DES3":
                self.cryptos = DES3
            elif current_algorithm == "RC2":
                self.cryptos = ARC2

    # 模式变化
    def mode_changed(self):
        print("algorithm_changed")
        current_mode = self.comboBox_mode.currentText()


    # 加密
    def encrypt(self):

        pass

    # 解密
    def decrypt(self):
        pass
