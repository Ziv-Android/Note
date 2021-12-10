import sys
from PyQt5.QtWidgets import QApplication
from calcView import PyCalcUi
from calcController import PyCalcCtrl
from calcModel import evaluateExpression


def main():
    # 创建一个 Application
    pycalc = QApplication(sys.argv)
    # 展示界面
    view = PyCalcUi()
    view.show()
    # 创建 model 和 controller
    model = evaluateExpression
    PyCalcCtrl(view=view, model=model)
    # 执行 event loop
    sys.exit(pycalc.exec_())


if __name__ == '__main__':
    main()
