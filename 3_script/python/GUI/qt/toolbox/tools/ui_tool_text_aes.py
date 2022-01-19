# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '.\tool_text_aes.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_WidgetAES(object):
    def setupUi(self, WidgetAES):
        WidgetAES.setObjectName("WidgetAES")
        WidgetAES.resize(1103, 648)
        self.verticalLayout = QtWidgets.QVBoxLayout(WidgetAES)
        self.verticalLayout.setObjectName("verticalLayout")
        self.textEdit = QtWidgets.QTextEdit(WidgetAES)
        self.textEdit.setObjectName("textEdit")
        self.verticalLayout.addWidget(self.textEdit)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.label_algorithm = QtWidgets.QLabel(WidgetAES)
        self.label_algorithm.setObjectName("label_algorithm")
        self.horizontalLayout.addWidget(self.label_algorithm)
        self.comboBox_algorithm = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_algorithm.setObjectName("comboBox_algorithm")
        self.horizontalLayout.addWidget(self.comboBox_algorithm)
        self.label_mode = QtWidgets.QLabel(WidgetAES)
        self.label_mode.setObjectName("label_mode")
        self.horizontalLayout.addWidget(self.label_mode)
        self.comboBox_mode = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_mode.setObjectName("comboBox_mode")
        self.horizontalLayout.addWidget(self.comboBox_mode)
        self.label_padding = QtWidgets.QLabel(WidgetAES)
        self.label_padding.setObjectName("label_padding")
        self.horizontalLayout.addWidget(self.label_padding)
        self.comboBox_padding = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_padding.setObjectName("comboBox_padding")
        self.horizontalLayout.addWidget(self.comboBox_padding)
        self.label_block_length = QtWidgets.QLabel(WidgetAES)
        self.label_block_length.setObjectName("label_block_length")
        self.horizontalLayout.addWidget(self.label_block_length)
        self.comboBox_block_length = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_block_length.setObjectName("comboBox_block_length")
        self.horizontalLayout.addWidget(self.comboBox_block_length)
        self.label_password = QtWidgets.QLabel(WidgetAES)
        self.label_password.setObjectName("label_password")
        self.horizontalLayout.addWidget(self.label_password)
        self.lineEdit_password = QtWidgets.QLineEdit(WidgetAES)
        self.lineEdit_password.setObjectName("lineEdit_password")
        self.horizontalLayout.addWidget(self.lineEdit_password)
        self.label_iv_offset = QtWidgets.QLabel(WidgetAES)
        self.label_iv_offset.setObjectName("label_iv_offset")
        self.horizontalLayout.addWidget(self.label_iv_offset)
        self.lineEdit_iv_offset = QtWidgets.QLineEdit(WidgetAES)
        self.lineEdit_iv_offset.setObjectName("lineEdit_iv_offset")
        self.horizontalLayout.addWidget(self.lineEdit_iv_offset)
        self.label_output = QtWidgets.QLabel(WidgetAES)
        self.label_output.setObjectName("label_output")
        self.horizontalLayout.addWidget(self.label_output)
        self.comboBox_output = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_output.setObjectName("comboBox_output")
        self.horizontalLayout.addWidget(self.comboBox_output)
        self.label_char_set = QtWidgets.QLabel(WidgetAES)
        self.label_char_set.setObjectName("label_char_set")
        self.horizontalLayout.addWidget(self.label_char_set)
        self.comboBox_charset = QtWidgets.QComboBox(WidgetAES)
        self.comboBox_charset.setObjectName("comboBox_charset")
        self.horizontalLayout.addWidget(self.comboBox_charset)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem1)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.textBrowser = QtWidgets.QTextBrowser(WidgetAES)
        self.textBrowser.setObjectName("textBrowser")
        self.verticalLayout.addWidget(self.textBrowser)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem2 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem2)
        self.pushButton_encrypt = QtWidgets.QPushButton(WidgetAES)
        self.pushButton_encrypt.setObjectName("pushButton_encrypt")
        self.horizontalLayout_2.addWidget(self.pushButton_encrypt)
        spacerItem3 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem3)
        self.pushButton_decrypt = QtWidgets.QPushButton(WidgetAES)
        self.pushButton_decrypt.setObjectName("pushButton_decrypt")
        self.horizontalLayout_2.addWidget(self.pushButton_decrypt)
        spacerItem4 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem4)
        self.verticalLayout.addLayout(self.horizontalLayout_2)

        self.retranslateUi(WidgetAES)
        QtCore.QMetaObject.connectSlotsByName(WidgetAES)

    def retranslateUi(self, WidgetAES):
        _translate = QtCore.QCoreApplication.translate
        WidgetAES.setWindowTitle(_translate("WidgetAES", "Form"))
        self.label_algorithm.setText(_translate("WidgetAES", "加密算法"))
        self.label_mode.setText(_translate("WidgetAES", "算法模式"))
        self.label_padding.setText(_translate("WidgetAES", "填充"))
        self.label_block_length.setText(_translate("WidgetAES", "数据块"))
        self.label_password.setText(_translate("WidgetAES", "密码"))
        self.label_iv_offset.setText(_translate("WidgetAES", "偏移量"))
        self.label_output.setText(_translate("WidgetAES", "输出"))
        self.label_char_set.setText(_translate("WidgetAES", "字符集"))
        self.pushButton_encrypt.setText(_translate("WidgetAES", "加密"))
        self.pushButton_decrypt.setText(_translate("WidgetAES", "解密"))
