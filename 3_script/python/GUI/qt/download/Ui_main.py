# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:\Users\czl\Documents\GitHub\BaiduImageDownloader\main.ui'
#
# Created by: PyQt5 UI code generator 5.5
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.setEnabled(True)
        Dialog.resize(432, 129)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(Dialog.sizePolicy().hasHeightForWidth())
        Dialog.setSizePolicy(sizePolicy)
        Dialog.setMaximumSize(QtCore.QSize(432, 129))
        Dialog.setSizeGripEnabled(False)
        self.gridLayout = QtWidgets.QGridLayout(Dialog)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.word_label = QtWidgets.QLabel(Dialog)
        self.word_label.setObjectName("word_label")
        self.horizontalLayout.addWidget(self.word_label)
        self.word_lineEdit = QtWidgets.QLineEdit(Dialog)
        self.word_lineEdit.setObjectName("word_lineEdit")
        self.horizontalLayout.addWidget(self.word_lineEdit)
        self.num_label = QtWidgets.QLabel(Dialog)
        self.num_label.setObjectName("num_label")
        self.horizontalLayout.addWidget(self.num_label)
        self.num_spinBox = QtWidgets.QSpinBox(Dialog)
        self.num_spinBox.setMinimum(1)
        self.num_spinBox.setMaximum(999)
        self.num_spinBox.setProperty("value", 60)
        self.num_spinBox.setObjectName("num_spinBox")
        self.horizontalLayout.addWidget(self.num_spinBox)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.size_label = QtWidgets.QLabel(Dialog)
        self.size_label.setObjectName("size_label")
        self.horizontalLayout_2.addWidget(self.size_label)
        self.total_radioButton = QtWidgets.QRadioButton(Dialog)
        self.total_radioButton.setChecked(True)
        self.total_radioButton.setObjectName("total_radioButton")
        self.horizontalLayout_2.addWidget(self.total_radioButton)
        self.XL_radioButton = QtWidgets.QRadioButton(Dialog)
        self.XL_radioButton.setObjectName("XL_radioButton")
        self.horizontalLayout_2.addWidget(self.XL_radioButton)
        self.L_radioButton = QtWidgets.QRadioButton(Dialog)
        self.L_radioButton.setObjectName("L_radioButton")
        self.horizontalLayout_2.addWidget(self.L_radioButton)
        self.M_radioButton = QtWidgets.QRadioButton(Dialog)
        self.M_radioButton.setObjectName("M_radioButton")
        self.horizontalLayout_2.addWidget(self.M_radioButton)
        self.S_radioButton = QtWidgets.QRadioButton(Dialog)
        self.S_radioButton.setObjectName("S_radioButton")
        self.horizontalLayout_2.addWidget(self.S_radioButton)
        self.thread_label = QtWidgets.QLabel(Dialog)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.thread_label.sizePolicy().hasHeightForWidth())
        self.thread_label.setSizePolicy(sizePolicy)
        self.thread_label.setObjectName("thread_label")
        self.horizontalLayout_2.addWidget(self.thread_label)
        self.thread_spinBox = QtWidgets.QSpinBox(Dialog)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.thread_spinBox.sizePolicy().hasHeightForWidth())
        self.thread_spinBox.setSizePolicy(sizePolicy)
        self.thread_spinBox.setMinimum(1)
        self.thread_spinBox.setObjectName("thread_spinBox")
        self.horizontalLayout_2.addWidget(self.thread_spinBox)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.dir_label = QtWidgets.QLabel(Dialog)
        self.dir_label.setObjectName("dir_label")
        self.horizontalLayout_3.addWidget(self.dir_label)
        self.dir_lineEdit = QtWidgets.QLineEdit(Dialog)
        self.dir_lineEdit.setReadOnly(True)
        self.dir_lineEdit.setObjectName("dir_lineEdit")
        self.horizontalLayout_3.addWidget(self.dir_lineEdit)
        self.dir_pushButton = QtWidgets.QPushButton(Dialog)
        self.dir_pushButton.setObjectName("dir_pushButton")
        self.horizontalLayout_3.addWidget(self.dir_pushButton)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.status_label = QtWidgets.QLabel(Dialog)
        self.status_label.setObjectName("status_label")
        self.horizontalLayout_4.addWidget(self.status_label)
        self.progressBar = QtWidgets.QProgressBar(Dialog)
        self.progressBar.setProperty("value", 0)
        self.progressBar.setObjectName("progressBar")
        self.horizontalLayout_4.addWidget(self.progressBar)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 2, 1)
        self.download_pushButton = QtWidgets.QPushButton(Dialog)
        font = QtGui.QFont()
        font.setPointSize(20)
        self.download_pushButton.setFont(font)
        self.download_pushButton.setDefault(True)
        self.download_pushButton.setObjectName("download_pushButton")
        self.gridLayout.addWidget(self.download_pushButton, 0, 1, 1, 1)
        self.src_pushButton = QtWidgets.QPushButton(Dialog)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.src_pushButton.sizePolicy().hasHeightForWidth())
        self.src_pushButton.setSizePolicy(sizePolicy)
        font = QtGui.QFont()
        font.setPointSize(20)
        self.src_pushButton.setFont(font)
        self.src_pushButton.setObjectName("src_pushButton")
        self.gridLayout.addWidget(self.src_pushButton, 1, 1, 1, 1)

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "百度图片批量下载器"))
        self.word_label.setText(_translate("Dialog", "关键词"))
        self.num_label.setText(_translate("Dialog", "数量"))
        self.size_label.setText(_translate("Dialog", "尺寸"))
        self.total_radioButton.setText(_translate("Dialog", "全部"))
        self.XL_radioButton.setText(_translate("Dialog", "特大"))
        self.L_radioButton.setText(_translate("Dialog", "大"))
        self.M_radioButton.setText(_translate("Dialog", "中"))
        self.S_radioButton.setText(_translate("Dialog", "小"))
        self.thread_label.setText(_translate("Dialog", "线程"))
        self.dir_label.setText(_translate("Dialog", "存储目录"))
        self.dir_pushButton.setText(_translate("Dialog", "浏览"))
        self.status_label.setText(_translate("Dialog", "状态空闲"))
        self.download_pushButton.setText(_translate("Dialog", "下载"))
        self.src_pushButton.setText(_translate("Dialog", "源码"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())

