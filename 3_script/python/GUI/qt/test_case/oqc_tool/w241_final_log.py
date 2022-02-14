#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# from oqc_tool import Ui_MainWindow

import webbrowser

from PyQt5 import QtWidgets

from oqc_tool.ui_w241_final_log import Ui_W241FinalLog


#
class W241FinalLog(QtWidgets.QWidget, Ui_W241FinalLog):
    name = "log"

    def __init__(self, pwm=None):
        super().__init__()
        self.setupUi(self)
        self.pwm = pwm
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.pFinishBtn = QtWidgets.QPushButton(self)
        self.pFinishBtn.setObjectName("pFinishBtn")
        self.pFinishBtn.setText("完成测试(Enter)")
        self.pFinishBtn.setShortcut('Return')
        self.horizontalLayout.addWidget(self.pFinishBtn)
        self.gridLayout.addLayout(self.horizontalLayout, 1, 0, 1, 1)
        # self.testResultText = QtWebEngineWidgets.QWebEngineView(self)
        self.testResultText = QtWidgets.QLabel(self)
        self.testResultText.setOpenExternalLinks(True) # 使其成为超链接
        self.testResultText.setObjectName("testResultText")
        self.gridLayout.addWidget(self.testResultText, 0, 0, 1, 1)

        self.pFinishBtn.clicked.connect(self.autotest_finish)

    def autotest_restart(self):
        print('log autotest_restart')
        return True

    def autotest_finish(self):
        # webc = self.pwm.http_client_handle()
        # ret, resp = c_log_sys(webc)
        # jl = json.loads(resp)
        # for log in jl['body']['logs']:
        #     ss = "%s\t%s" % (log['time'], log['data'])
        #     self.pLogEdit.appendPlainText(ss)
        print('log autotest_finish')
        self.pwm.pwm.pTestStackWidget.setCurrentIndex(0)
        return True

    def show_result_html(self, path):
        local_path_url = "file:///" + path.replace("\\", "/")
        print(local_path_url)
        # self.testResultText.load(QtCore.QUrl(local_path_url))
        webbrowser.open_new_tab(local_path_url)
        self.testResultText.setText(f'测试报告：<a href={local_path_url}>{local_path_url}</a> 浏览器打开查看详情<br/><br/>测试报告存档在doc路径下<br/>')
