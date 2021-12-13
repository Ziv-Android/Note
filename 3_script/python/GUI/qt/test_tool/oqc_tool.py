import os
import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from oqc_tool.mainwindow import CMainWindow

#
if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    global gpath
    gpath = os.path.join(os.getcwd())
    print(gpath)

    mwin = CMainWindow()
    mwin.showMaximized()

    sys.exit(app.exec_())
