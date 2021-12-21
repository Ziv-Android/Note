#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import time

from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

import sys
import requests

import Weather

# from ui_waiting import Ui_QWaiting
import resource_rc


class QWaiting(QWidget):
    def __init__(self):
        super(QWaiting, self).__init__()
        self.setFixedSize(126, 22)
        # 设置透明度
        self.setWindowOpacity(0.8)
        # 对话框风格，无边框
        self.setWindowFlags(Qt.Dialog | Qt.FramelessWindowHint)
        self.label = QLabel(self)
        self.label.setStyleSheet("background-color: transparent;")
        self.movie = QMovie(":/loading_e.gif")
        self.label.setMovie(self.movie)
        self.label.setScaledContents(True)
        self.movie.start()

    def __del__(self):
        self.movie.stop()


class ClickThread(QThread):
    def __init__(self, parent, func, on_finish, *args, **kwargs):
        super(ClickThread, self).__init__(parent)
        self.on_finished = on_finish
        self.func = func
        self.args = args
        self.kwargs = kwargs
        self.start()

    def run(self):
        try:
            result = self.func(*self.args, **self.kwargs)
        except Exception as e:
            print("e is %s" % e)
            result = e
        finally:
            print(self.parent(), self.on_finished, result)


class MainDialog(QMainWindow):
    def __init__(self, parent=None):
        super(QMainWindow, self).__init__(parent)
        self.ui = Weather.Ui_MainWindow()
        self.ui.setupUi(self)
        self.center()
        self.initCityComboBox()

    def initCityComboBox(self):
        self.ui.comboBox.addItems(["北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功",])

    def worker(self, msg):
        for i in range(10):
            print("worker", str(i), msg)
            time.sleep(1)

    def end_send(self):
        print("send end return")

    def queryWeather(self):
        cityName = self.ui.comboBox.currentText()
        # cityCode = self.getCode(cityName)

        wait = QWaiting()
        wait.show()
        # r = requests.get("https://tianqiapi.com/free/day?appid=23035354&appsecret=8YvlPNrz&unescape=1&city={}".format(cityName))
        # r.encoding = 'utf-8'
        # weatherMsg = r.json()

        # print(weatherMsg)
        t = ClickThread(self, self.worker, self.end_send, "some long task")
        # for i in range(10):
        #     time.sleep(1)
        #     QCoreApplication.processEvents()
        # if r.json() == 200:
        #     weatherMsg = '城市：{}\n日期：{}\n天气：{}\nPM 2.5：{} {}\n温度：{}\n湿度：{}\n风力：{}\n\n{}'.format(
        #         r.json()['cityInfo']['city'],
        #         r.json()['data']['forecast'][0]['ymd'],
        #         r.json()['data']['forecast'][0]['type'],
        #         int(r.json()['data']['pm25']),
        #         r.json()['data']['quality'],I
        #         r.json()['data']['wendu'],
        #         r.json()['data']['shidu'],
        #         r.json()['data']['forecast'][0]['fl'],
        #         r.json()['data']['forecast'][0]['notice'],
        #     )
        # else:
        #     weatherMsg = '天气查询失败，请稍后再试！'
        weatherMsg = f'{cityName} 天气查询失败，请稍后再试！{t}'

        # wait.close()

        self.ui.textEdit.setText(str(weatherMsg))

    def getCode(self, cityName):
        cityDict = {"北京": "101010100",
                    "上海": "101020100",
                    "天津": "101030100"}

        return cityDict.get(cityName, '101010100')

    def clearText(self):
        self.ui.textEdit.clear()

    def center(self):
        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width() - size.width()) / 2, (screen.height() - size.height()) / 2)


if __name__ == '__main__':
    myapp = QApplication(sys.argv)
    myDlg = MainDialog()
    myDlg.show()
    sys.exit(myapp.exec_())
