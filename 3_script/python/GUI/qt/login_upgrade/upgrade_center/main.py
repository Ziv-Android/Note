#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# import cgitb
# import os
import sys

from upgrade import UpgradeWindow
from PyQt5.QtWidgets import QApplication

if __name__ == "__main__":
    # 记录崩溃信息
    # log_dir = os.path.join(os.getcwd(), 'crash')
    # if not os.path.exists(log_dir):
    #     os.mkdir(log_dir)
    # cgitb.enable(format='text', logdir=log_dir)

    app = QApplication(sys.argv)

    home = UpgradeWindow()
    # 初始化数据/读取svc模板文件
    home.read_data_from_init()
    # 显示表格
    home.show()

    sys.exit(app.exec_())

# 参考资料
# Qt线程池问题：https://blog.csdn.net/weixin_38587278/article/details/106430250
# 懒人图库（gif进度条）：https://www.lanrentuku.com/gif/a/loading_3.html
# QApplication.processEvents()
