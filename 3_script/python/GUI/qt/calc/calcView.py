from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QMainWindow, QWidget, QGridLayout, QLineEdit, QPushButton, QVBoxLayout


class PyCalcUi(QMainWindow):
    """计算器的主界面
    """

    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle('PyCalc')
        self.setFixedSize(235, 235)  # 不可以缩放
        # Main Windows 必须要 Central Widget
        self.generalLayout = QVBoxLayout()
        self._centralWidget = QWidget()  # 这里可以放不同的 sub Widgets
        self.setCentralWidget(self._centralWidget)
        self._centralWidget.setLayout(self.generalLayout)
        # 创建 按钮 和 显示
        self._createDisplay()
        self._createButtons()

    def _createDisplay(self):
        """用来显示计算器顶部的数字
        """
        self.display = QLineEdit()
        # 设置 display 的属性
        self.display.setFixedHeight(35)
        self.display.setAlignment(Qt.AlignRight)  # 右对齐
        self.display.setReadOnly(True)
        # 设置布局
        self.generalLayout.addWidget(self.display)

    def _createButtons(self):
        """显示计算器的按键
        """
        self.buttons = {}
        buttonLayout = QGridLayout()  # 按钮的布局
        # 记录按钮的文字和坐标
        buttons = {'7': (0, 0),
                   '8': (0, 1),
                   '9': (0, 2),
                   '/': (0, 3),
                   'C': (0, 4),
                   '4': (1, 0),
                   '5': (1, 1),
                   '6': (1, 2),
                   '*': (1, 3),
                   '(': (1, 4),
                   '1': (2, 0),
                   '2': (2, 1),
                   '3': (2, 2),
                   '-': (2, 3),
                   ')': (2, 4),
                   '0': (3, 0),
                   '00': (3, 1),
                   '.': (3, 2),
                   '+': (3, 3),
                   '=': (3, 4),
                   }
        for binText, pos in buttons.items():
            self.buttons[binText] = QPushButton(binText)
            self.buttons[binText].setFixedSize(40, 40)
            buttonLayout.addWidget(self.buttons[binText], pos[0], pos[1])
        # 将 button layout 添加到 general layout
        self.generalLayout.addLayout(buttonLayout)

    def setDisplayText(self, text):
        """设置 计算器显示器显示的内容
        """
        self.display.setText(text)
        self.display.setFocus()  # 将光标聚焦在显示屏上

    def getdisplayText(self):
        """返回显示器中现在的内容
        """
        return self.display.text()

    def clearDisplay(self):
        """将显示器的内容设置为空
        """
        self.setDisplayText('')
