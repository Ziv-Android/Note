# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\upgrade.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(917, 755)
        MainWindow.setMinimumSize(QtCore.QSize(917, 755))
        MainWindow.setMaximumSize(QtCore.QSize(917, 755))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.upgrade_detail_TableWidget = QtWidgets.QTableWidget(self.centralwidget)
        self.upgrade_detail_TableWidget.setGeometry(QtCore.QRect(10, 50, 901, 631))
        self.upgrade_detail_TableWidget.setRowCount(21)
        self.upgrade_detail_TableWidget.setColumnCount(5)
        self.upgrade_detail_TableWidget.setObjectName("upgrade_detail_TableWidget")
        self.upgrade_detail_TableWidget.horizontalHeader().setVisible(True)
        self.upgrade_detail_TableWidget.horizontalHeader().setCascadingSectionResizes(True)
        self.upgrade_detail_TableWidget.horizontalHeader().setHighlightSections(True)
        self.upgrade_detail_TableWidget.horizontalHeader().setSortIndicatorShown(True)
        self.upgrade_detail_TableWidget.horizontalHeader().setStretchLastSection(True)
        self.upgrade_detail_TableWidget.verticalHeader().setVisible(False)
        self.upgrade_detail_TableWidget.verticalHeader().setHighlightSections(True)
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(750, 720, 158, 25))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout_Bottom = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout_Bottom.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_Bottom.setObjectName("horizontalLayout_Bottom")
        self.cancel_Button = QtWidgets.QPushButton(self.layoutWidget)
        self.cancel_Button.setObjectName("cancel_Button")
        self.horizontalLayout_Bottom.addWidget(self.cancel_Button)
        self.upgrade_Button = QtWidgets.QPushButton(self.layoutWidget)
        self.upgrade_Button.setObjectName("upgrade_Button")
        self.horizontalLayout_Bottom.addWidget(self.upgrade_Button)
        self.layoutWidget1 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(10, 690, 297, 25))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.horizontalLayout_File = QtWidgets.QHBoxLayout(self.layoutWidget1)
        self.horizontalLayout_File.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_File.setSpacing(0)
        self.horizontalLayout_File.setObjectName("horizontalLayout_File")
        self.input_file_Button = QtWidgets.QPushButton(self.layoutWidget1)
        self.input_file_Button.setObjectName("input_file_Button")
        self.horizontalLayout_File.addWidget(self.input_file_Button)
        self.lineEdit_filePath = QtWidgets.QLineEdit(self.layoutWidget1)
        self.lineEdit_filePath.setObjectName("lineEdit_filePath")
        self.horizontalLayout_File.addWidget(self.lineEdit_filePath)
        self.download_file_Button = QtWidgets.QPushButton(self.layoutWidget1)
        self.download_file_Button.setObjectName("download_file_Button")
        self.horizontalLayout_File.addWidget(self.download_file_Button)
        self.layoutWidget2 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget2.setGeometry(QtCore.QRect(10, 10, 381, 22))
        self.layoutWidget2.setObjectName("layoutWidget2")
        self.horizontalLayout_number = QtWidgets.QHBoxLayout(self.layoutWidget2)
        self.horizontalLayout_number.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_number.setObjectName("horizontalLayout_number")
        self.username_label = QtWidgets.QLabel(self.layoutWidget2)
        self.username_label.setObjectName("username_label")
        self.horizontalLayout_number.addWidget(self.username_label)
        self.username_lineEdit = QtWidgets.QLineEdit(self.layoutWidget2)
        self.username_lineEdit.setObjectName("username_lineEdit")
        self.horizontalLayout_number.addWidget(self.username_lineEdit)
        self.password_label = QtWidgets.QLabel(self.layoutWidget2)
        self.password_label.setObjectName("password_label")
        self.horizontalLayout_number.addWidget(self.password_label)
        self.password_lineEdit = QtWidgets.QLineEdit(self.layoutWidget2)
        self.password_lineEdit.setObjectName("password_lineEdit")
        self.horizontalLayout_number.addWidget(self.password_lineEdit)
        self.message_lineEdit = QtWidgets.QLineEdit(self.centralwidget)
        self.message_lineEdit.setGeometry(QtCore.QRect(10, 30, 901, 20))
        self.message_lineEdit.setFocusPolicy(QtCore.Qt.NoFocus)
        self.message_lineEdit.setObjectName("message_lineEdit")
        MainWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "云升级"))
        self.cancel_Button.setText(_translate("MainWindow", "取消"))
        self.upgrade_Button.setText(_translate("MainWindow", "升级"))
        self.input_file_Button.setText(_translate("MainWindow", "导入文件"))
        self.download_file_Button.setText(_translate("MainWindow", "下载模板"))
        self.username_label.setText(_translate("MainWindow", "用户名"))
        self.password_label.setText(_translate("MainWindow", "密码"))
