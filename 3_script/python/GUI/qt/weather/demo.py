#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5.QtWidgets import QApplication, QMainWindow, QDesktopWidget

import sys
import requests

import Weather


class MainDialog(QMainWindow):
    def __init__(self, parent=None):
        super(QMainWindow, self).__init__(parent)
        self.ui = Weather.Ui_MainWindow()
        self.ui.setupUi(self)
        self.center()
        self.initCityComboBox()

    def initCityComboBox(self):
        self.ui.comboBox.addItems(["北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功", "北1", "北1", "北京", "成都", "成华", "成功",])

    def queryWeather(self):
        cityName = self.ui.comboBox.currentText()
        # cityCode = self.getCode(cityName)

        r = requests.get("https://tianqiapi.com/free/day?appid=23035354&appsecret=8YvlPNrz&unescape=1&city={}".format(cityName))
        r.encoding = 'utf-8'
        weatherMsg = r.json()

        print(weatherMsg)

        # if r.json() == 200:
        #     weatherMsg = '城市：{}\n日期：{}\n天气：{}\nPM 2.5：{} {}\n温度：{}\n湿度：{}\n风力：{}\n\n{}'.format(
        #         r.json()['cityInfo']['city'],
        #         r.json()['data']['forecast'][0]['ymd'],
        #         r.json()['data']['forecast'][0]['type'],
        #         int(r.json()['data']['pm25']),
        #         r.json()['data']['quality'],
        #         r.json()['data']['wendu'],
        #         r.json()['data']['shidu'],
        #         r.json()['data']['forecast'][0]['fl'],
        #         r.json()['data']['forecast'][0]['notice'],
        #     )
        # else:
        #     weatherMsg = '天气查询失败，请稍后再试！'

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
