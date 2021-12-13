# from oqc_tool import Ui_MainWindow
import os
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.ui_w1_product_change import Ui_W01_ProductChange


#
class W1ProductChange(QtWidgets.QWidget, Ui_W01_ProductChange):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.init_productlist()
        # self.pLoginButton.clicked.connect(self.LoginClickedSlot)

        # self.cfg = CProTypeCfg()
        # self.pTestTreeView

    # 初始化产品列表
    def init_productlist(self):
        # filelist = self.get_filelist(os.curdir.expandtabs(), [])
        filelist = self.get_filelist("./product/h1m/", [])
        print(filelist)

    # 遍历文件夹及其子文件夹中的文件，并存储在一个列表中
    # 输入文件夹路径、空文件列表[]
    # 返回 文件列表Filelist,包含文件名（完整路径）
    def get_filelist(self, dir, file_list):
        new_dir = dir
        if os.path.isfile(dir):
            filename = os.path.basename(dir)    # 文件名
            if filename.endswith(".ini"):
                file_list.append(filename.split(".")[0])

        elif os.path.isdir(dir):
            for s in os.listdir(dir):
                # 如果需要忽略某些文件夹，使用以下代码
                # if s == "xxx":
                #   continue
                new_dir = os.path.join(dir, s)
                self.get_filelist(new_dir, file_list)

        return file_list

    #
    def LoginClickedSlot(self):
        self.pQCEdit.setText("hello worlds")
