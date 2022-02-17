#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys

from PyQt5.QtWidgets import QMainWindow, QListWidget, QListWidgetItem, QCheckBox, QVBoxLayout, QWidget, QApplication, \
    QPushButton


class PyCheckboxListViewUi(QMainWindow):
    def __init__(self):
        super(PyCheckboxListViewUi, self).__init__()
        self.setWindowTitle('PyCheckboxListView')
        self.setFixedSize(235, 235)  # 不可以缩放
        # Main Windows 必须要 Central Widget
        self.generalLayout = QVBoxLayout()
        self._centralWidget = QWidget()  # 这里可以放不同的 sub Widgets
        self.setCentralWidget(self._centralWidget)
        self._centralWidget.setLayout(self.generalLayout)
        self.listWidget = QListWidget()
        # 设置布局
        self.generalLayout.addWidget(self.listWidget)

        test_data = []
        for i in range(1, 5):
            test_data.append(f"测试数据 {i}")
        self.insert(test_data)

        self.startTasksBtn = QPushButton("获取数据", self)
        self.startTasksBtn.clicked.connect(self.getChoose)
        self.generalLayout.addWidget(self.startTasksBtn)

    def insert(self, data_list):
        for item in data_list:
            box = QCheckBox(item)
            qlistitem = QListWidgetItem()
            self.listWidget.addItem(qlistitem)
            self.listWidget.setItemWidget(qlistitem, box)

    def getChoose(self) -> [str]:
        count = self.listWidget.count()
        cb_list = []
        for i in range(count):
            item = self.listWidget.itemWidget(self.listWidget.item(i))
            cb_list.append(item)

        chooses = []  # 存放被选择的数据
        for cb in cb_list:  # type:QCheckBox
            if cb.isChecked():
                chooses.append(cb.text())
        print(chooses)
        return chooses


if __name__ == '__main__':
    print(sys.getdefaultencoding())
    # 创建一个 Application
    pycalc = QApplication(sys.argv)
    # 展示界面
    view = PyCheckboxListViewUi()
    view.show()
    # 执行 event loop
    sys.exit(pycalc.exec_())
