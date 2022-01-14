#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import sys
# print("main_window:", sys.modules)
import base64
import os.path
import time

from PyQt5.QtGui import QPixmap
from PyQt5.QtWidgets import QWidget, QFileDialog, QMessageBox
from ui_tool_image_base64 import Ui_WidgetImageBase64


class WidgetImageBase64(QWidget, Ui_WidgetImageBase64):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.base64ToImgBtn.clicked.connect(self.base64_decode)
        self.imgToBase64Btn.clicked.connect(self.base64_encode)
        self.label_img.setScaledContents(True)
        self.cleanBtn.clicked.connect(self.clean_data)

    def base64_decode(self):
        print("decode")
        img_base64_str = self.text_result.toPlainText()
        if not img_base64_str.startswith("/9j"):
            QMessageBox.warning(self, "警告", "图片Base64信息有误")
            return
        image = base64.b64decode(img_base64_str)
        temp_file_path = os.path.join(os.getcwd(), "assets/img")
        if not os.path.exists(temp_file_path):
            os.makedirs(temp_file_path)
        file_name = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime((time.time()))) + '.png'
        temp_file = os.path.join(temp_file_path, file_name)
        with open(temp_file, "wb") as of:
            of.write(image)

        png = QPixmap(temp_file)
        self.label_img.setPixmap(png)

    def base64_encode(self):
        print("encode")
        file_path, file_format = QFileDialog.getOpenFileName(self, '选择文件', '', 'Excel files(*.png , *.jpg)')
        print("encode", file_path, file_format)
        if file_path == "":
            return
        png = QPixmap(file_path)
        self.label_img.setPixmap(png)
        with open(file_path, "rb") as rf:
            result = base64.b64encode(rf.read())
            self.text_result.setPlainText(str(result.decode("utf-8")))

    def clean_data(self):
        print("clean")
        self.text_result.clear()
        self.label_img.clear()
