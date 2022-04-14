# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'home.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(855, 532)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_2.addWidget(self.label_4)
        self.lineEdit_sn = QtWidgets.QLineEdit(self.centralwidget)
        self.lineEdit_sn.setObjectName("lineEdit_sn")
        self.horizontalLayout_2.addWidget(self.lineEdit_sn)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem)
        self.verticalLayout_3.addLayout(self.horizontalLayout_2)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setObjectName("label_2")
        self.verticalLayout.addWidget(self.label_2)
        self.textEdit_origin_data = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_origin_data.setObjectName("textEdit_origin_data")
        self.verticalLayout.addWidget(self.textEdit_origin_data)
        self.verticalLayout_3.addLayout(self.verticalLayout)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.comboBox = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox.setObjectName("comboBox")
        self.horizontalLayout.addWidget(self.comboBox)
        self.checkBox_base64 = QtWidgets.QCheckBox(self.centralwidget)
        self.checkBox_base64.setObjectName("checkBox_base64")
        self.horizontalLayout.addWidget(self.checkBox_base64)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem1)
        self.pushButton_analysis = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_analysis.setObjectName("pushButton_analysis")
        self.horizontalLayout.addWidget(self.pushButton_analysis)
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem2)
        self.pushButton_data_maker = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_data_maker.setObjectName("pushButton_data_maker")
        self.horizontalLayout.addWidget(self.pushButton_data_maker)
        self.pushButton_clean = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton_clean.setObjectName("pushButton_clean")
        self.horizontalLayout.addWidget(self.pushButton_clean)
        self.verticalLayout_3.addLayout(self.horizontalLayout)
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_2.addWidget(self.label_3)
        self.textEdit_result = QtWidgets.QTextEdit(self.centralwidget)
        self.textEdit_result.setObjectName("textEdit_result")
        self.verticalLayout_2.addWidget(self.textEdit_result)
        self.verticalLayout_3.addLayout(self.verticalLayout_2)
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "rs485协议解析"))
        self.label_4.setText(_translate("MainWindow", "SN："))
        self.label_2.setText(_translate("MainWindow", "原始数据"))
        self.label.setText(_translate("MainWindow", "业务类型"))
        self.checkBox_base64.setText(_translate("MainWindow", "Base64"))
        self.pushButton_analysis.setText(_translate("MainWindow", "数据解析"))
        self.pushButton_data_maker.setText(_translate("MainWindow", "数据拼装"))
        self.pushButton_clean.setText(_translate("MainWindow", "清空结果"))
        self.label_3.setText(_translate("MainWindow", "解析结果"))
