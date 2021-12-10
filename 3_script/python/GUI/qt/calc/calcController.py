from functools import partial


class PyCalcCtrl(object):
    def __init__(self, model, view) -> None:
        super().__init__()
        self._view = view  # UI 界面对应的类
        self._model = model  # 用于计算
        # connect signal and slots
        self._connectSignals()  # 初始化

    def _calculateResult(self):
        """调用 model, 来计算结果并更新 DisplayText
        """
        result = self._model(expression=self._view.getdisplayText())  # 得到计算结果
        self._view.setDisplayText(result)  # 将计算结果用于显示

    def _buildExpression(self, sub_exp):
        """修改计算器显示界面
        Args:
            sub_exp (str): 输入的运算符
        """
        expression = self._view.getdisplayText() + sub_exp
        self._view.setDisplayText(expression)

    def _connectSignals(self):
        """对每一个按键进行功能函数的绑定
        """
        for btnText, btn in self._view.buttons.items():
            if btnText not in ('=', 'C'):
                btn.clicked.connect(partial(self._buildExpression, sub_exp=btnText))
        self._view.buttons['C'].clicked.connect(self._view.clearDisplay)
        self._view.buttons['='].clicked.connect(self._calculateResult)
