import cv2
import threading
import time
import sys
import time
from PyQt5 import QtCore
from PyQt5.QtCore import QThread, pyqtSignal
from PyQt5.QtGui import QPixmap, QImage


# 线程类：
class RtspClient(QThread):
    # 定义信号,定义参数为str类型
    breakSignal = pyqtSignal(QPixmap)

    def __init__(self, parent=None):
        super().__init__(parent)
        self.stoped = False
        self.mutex = QtCore.QMutex()

    def run(self):
        with QtCore.QMutexLocker(self.mutex):
            self.stoped = False

        if self.url_rtsp == None:
            return

        cap = cv2.VideoCapture(self.url_rtsp)
        cap.set(cv2.CAP_PROP_BUFFERSIZE, 3)
        print(cap.isOpened())

        while cap.isOpened():
            if self.stoped:
                return
            ret, frame = cap.read()

            height, width, bytesPerComponent = frame.shape
            bytesPerLine = bytesPerComponent * width
            # 变换彩色空间顺序
            cv2.cvtColor(frame, cv2.COLOR_BGR2RGB, frame)

            image = QImage(frame.data, width, height, bytesPerLine, QImage.Format_RGB888)

            self.breakSignal.emit(QPixmap.fromImage(image.scaled(self.width, self.height)))
            #10毫秒发送一次信号
            time.sleep(0.01)

    def begin(self, url, width, height):
        # with QtCore.QMutexLocker(self.mutex):
        self.width = width
        self.height = height
        self.url_rtsp = url
        self.stop()
        self.start()

    def stop(self):
        with QtCore.QMutexLocker(self.mutex):
            self.stoped= True

    def isStoped(self):
        with QtCore.QMutexLocker(self.mutex):
            return self.stoped