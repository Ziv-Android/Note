## 环境配置
### PyQt5及pyqt5-tools安装
```shell
pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple pyqt5
pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple pyqt5-tools
```

测试是否安装成功
```python
import sys
from PyQt5 import QtWidgets, QtCore

app = QtWidgets.QApplication(sys.argv)
widget = QtWidgets.QWidget()
widget.resize(360, 360)
widget.setWindowTitle("HelloQt")
widget.show()
sys.exit(app.exec_())
```

### PyCharm配置环境
为了加速开发过程，需要配置Qt Designer、pyuic、pyrcc工具，在Pycharm中，依次打开 File - Settings - Tools - External Tools，点击 + Create Tool，依次配置如下：
1. Qt Designer
Qt Designer 是通过拖拽的方式放置控件，并实时查看控件效果进行快速UI设计。 最终生成.ui文件（实质上是XML格式的文件），可以通过pyuic5工具转换成.py文件。
```text
Name: QtDisigner
Program : C:\Python38\Lib\site-packages\pyqt5_tools\Qt\bin\designer.exe # 当前designer目录，请根据实际修改
Working directory: $FileDir$
```
注意新版本工具更新在该目录下：**`D:\Python\Lib\site-packages\qt5_applications\Qt\bin\designer`**

2. pyuic
PyUIC主要是把Qt Designer生成的.ui文件换成.py文件。
```text
Name: QtDisigner
Program : C:\Python38\Lib\site-packages\pyqt5_tools\Qt\bin\designer.exe # 当前designer目录，请根据实际修改
Working directory: $FileDir$
```

3. pyrcc
PyRCC主要是把编写的.qrc资源文件换成.py文件。
```text
Name: QtDisigner
Program : C:\Python38\Lib\site-packages\pyqt5_tools\Qt\bin\designer.exe # 当前designer目录，请根据实际修改
Working directory: $FileDir$
```

## 实例
获取天气信息
### 设计UI界面

### 转换.ui为.py

### 填充执行逻辑

### 打包编译exe


## 参考资料
https://lovesoo.org/2020/03/14/pyqt-getting-started/
https://www.cnblogs.com/linyfeng/p/11223707.html