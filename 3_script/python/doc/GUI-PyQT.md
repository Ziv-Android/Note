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
Program : D:\Python\Lib\site-packages\qt5_applications\Qt\bin\designer.exe # 当前designer目录，请根据实际修改
Working directory: $FileDir$
```
注意新版本工具更新在该目录下：**`D:\Python\Lib\site-packages\qt5_applications\Qt\bin\designer`**

1. pyuic
PyUIC主要是把Qt Designer生成的.ui文件换成.py文件。
```text
Name: PyUIC
Program : D:\Python\Scripts\pyuic5.exe
Arguments: $FileName$ -o ui_$FileNameWithoutExtension$.py
Working directory: $FileDir$
```

3. pyrcc
PyRCC主要是把编写的.qrc资源文件换成.py文件。
```text
Name: QtDisigner
Program : D:\Python\Scripts\pyrcc5.exe
Arguments: $FileName$ -o rc_$FileNameWithoutExtension$.py
Working directory: $FileDir$
```

## 使用步骤速览
获取天气信息
### 设计UI界面
[Weather_UI](./../GUI/qt/weather/Weather.ui)

### 转换.ui为.py
`python -m PyQt5.uic.pyuic .\Weather.ui -o ui_Weather.py`  
或
`pyuic5 -o ui_Weathre.py Weather.ui`

### 转换资源文件
`pyrcc5 apprcc.qrc -o rc_apprcc.py`
```
import apprcc_cc
```

### 填充执行逻辑

### 打包编译exe
`pyinstaller -F -w -i Weather.icon Weather.py`

## PyQt5快速开发与实战（笔记）
GUI(Graphical User Interface)图形用户界面，是一种结合计算机科学、美学、心理学、行为学及商业领域需求分析的人机系统工程，强调人-机-环境三者作为一个系统进行总体设计。Python中常用的GUI控件集有PyQt、Tkinter、wxPython、Kivy、PyGUI和Libavg。PyQt是Qt为Python专门提供的GUI扩展

### Python基础
#### 数据类型
基本数据类型：Number（数字）、String（字符串）、List（列表）、Tuple（元组）、Dictionary（字典）
##### Number
int（有符号整型），long（长整型），float（浮点型），complex（复数）

计算符号 | + | - | * | / | // | % | **
--- | --- | --- | --- | --- | --- | --- | ---
含义 | 加 | 减 | 乘 | 除 | 整除 | 取模(求余) | 乘方

##### String
数字、字母、下划线，一般使用成对单引号或双引号包裹。

获取字符串长度：`len("abc")`
字符串截取：`"abcdefg"[1:-2]` **左从0数，右从-1数**
字符串运算：`+`字符串连接，`*`字符串重复

字符串常用方法  
字符串去除空格：strip(), lstrip(), rstrip()  
字符串连接：`,` `+` `join()`  
字符串查找：find()  
字符串替换：replace(), replaceAll()  
字符串分割：split()  
字符串大小写转换：upper(), lower(), swapcase(), capitalize()

##### List
列表操作包含以下函数：  
列表元素个数：len(list)  
列表最大值：max(list)  
列表最小值：min(list)  
元组转列表：list(seq)  

列表操作包含以下方法：
列表添加：`list.append(), list.insert(index, obj), list.extend()`  
列表删除：`list.pop(), list.remove(), list.clear()`  
列表修改：`list[index] = xxx`  
列表查找：`list.index(), list.count()`  
列表排序：`list.sort()`  
列表反转：`list.reverse()`  

##### Tuple-只读
用`(,)`表示，内部元素用`,`逗号隔开，不能二次赋值。

##### Dictionary
key-value结构，又称关联数组或哈希表  
字典内置函数：  
字典key的个数：len()

字典内置方法：  
字典添加：dict[key] = ""， dict.setdefault(key, default=None)  
字典删除：dict.pop(), dict.popItem(), dict.clear()  
字典修改：dict[key] = ""  
字典查找：dict.has_key(key), dict.items(), dict.keys(), dict.values(), dict.get(key, default=None)  
字典拷贝：dict.copy(), dict.fromkeys()  

##### 数据类型转换
int(), 转整数  
long(), 转长整数  
float(), 转浮点数  
complex(), 转复数  
hex(), 十六进制  
otc(), 八进制  
chr(), 整数转字符  
unichr(), 整数转unicode字符  
ord(), 字符串转整数  
str(), 转字符串  
tuple(), 转元组  
list(), 转列表  
repr(), 转表达式  
eval(), 计算字符串中有效的python表达式，并返回一个对象  

#### 流程控制
##### 判断
if...elif...else...
```
if x > y:
    print("True")
else:
    print("False")
```
##### 循环
while
```
while x > y:
    print(True)
```
for...in...
```
for index in range(len(list)):
    print(index, list[index])

for item in list:
    print(item)
```

#### 自定义函数
Python支持返回多个数据
```
def add(a, b):
    return a+b
```

函数拓展partial，参数延迟输入，语法糖，不会带来性能提升，只是为了简介代码
```
import functools

plus = functools.partial(add, 3)

print(plus(2) == add(2, 3))
```

lambda表达式
```
fun_add = lambda x,y: x + y
print(fun_add(1, 2))
```

#### 类和实例
类变量：class外共享，不管创建多少个实例，修改全局变化  
成员变量：self.aaa，class内使用，不同的实例使用各自的副本

类方法：包含self参数  
两条下划线`__`表示私有变量/私有方法函数

类的动态属性 property(get, set, del) / @property + @param.setter + @param.deleter

## 快速上手QtDesinger
ctrl + R 预览窗口

### 属性编辑器
objectName：控件对象名称  
geometry：相对坐标系  
sizePolicy：控件大小策略  
minimumSize：最小宽度，高度  
maximumSize：最大宽度，高度。如果下个让窗口或控件的大小固定，将minimumSize与maximumSize属性设置为相同值即可  
font：字体  
cousor，光标  
windowTitle：窗口标题  
windowIcon/icon：窗口图标/控件图标  
iconSize：图标大小  
toolTip：提示信息  
statusTip：任务栏提示信息  
text：控件文本  
shortcut：快捷键  

### 信号/槽编辑器
为控件添加信号和槽函数，编辑控件的信号和槽函数

### 资源浏览器
为控件添加图片，比如label，button的背景图片等

### ui文件及转py方法
ui文件是一个XML（可扩展标记语言）格式的文件，

[UI文件转Python文件](./../GUI/qt/ui_file_to_py.py)
另一种实现
[UI文件转Python文件2](./../GUI/qt/ui_file_to_py_2.py)

### 界面与逻辑分离
```python
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from ui_xxx import *

class XxWinodw(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super(Xxx, self).__init__()
        self.setupUi(self)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = XxWinodw()
    win.show()
    sys.exit(app.exec_())
```
至此，已经可以实现简单PyQt开发

### 布局管理
垂直，水平，栅格，表单

命名  
doubleSpinBox_returns_min  
doubleSpinBox_returns_max

水平/垂直策略（QtWidgets.QSizePolicy）  
Fixed：窗口控件具有其sizeHint所提示的尺寸且尺寸不会再发生改变，即固定尺寸  
Minimum:窗口控件的sizeHint所提示的尺寸就是它的最小尺寸:该窗口控件不能被压缩得比这个值小，但可以变得更大。  
Maximum:窗口控件的sizeHint所提示的尺寸就是它的最大尺寸:该窗口控件不能变得比这个值大，但它可以被压缩到mintsizeHint给定的尺寸大小。  
Preferred:窗口控件的sizeHint所提示的尺寸就是它的期望尺寸:该窗口控件可以缩小到minisizeHint所提示的尺寸，也可以变得比sizeHint所提示的尺寸还要大。  
Expanding:窗口控件可以缩小到minisizeHint所提示的尺寸，也可以变得比 sizeHint所提示的尺寸大，但它希望能够变得更大。  
MinimumExpanding:窗口控件的sizeHint所提示的尺寸就是它的最小尺寸:该窗口控件不能被压缩得比这个值还小，但它希望能够变得更大。  
Ignored:无视窗口控件的sizeHint和minisizeHint所提示的尺寸，按照默认来设置。  

参考百分比布局
```
sizePolicy = QtWidgets.QSizePolicy(QtWeights.QSizePolicy.Preferred, QtWeights.QSizePolicy.Preferred)
sizePolicy.setHorizontalStretch(0) #水平伸展0
sizePolicy.setVerticalStretch(0) #垂直伸展0
sizePolicy.setHeightForWidth(self.label_1.sizePolicy().hasHeightForWidth())
self.label_1.setSizePolicy(sizePolicy)
```

设置Tab键顺序：Edit -> 设置Tab键次序

### **信号（signal）和槽（slot）**-核心
所有从QObject类或其子类派生的类都能包含信号和槽。在创建事件循环之后，当对象状态改变时，信号通过emit函数发射，由QObject.signal.connect()连接的槽函数将自动执行，单个信号可以与多个槽进行连接。多个信号也可以与单个槽进行连接

### 打包资源
新建qrc资源文件
```
<rcc version="1.0">
    <qresource prefix="pic">
        <file>images/cartonn1.ico</file>
        <file>images/cartonn2.ico</file>
        <file>images/cartonn3.ico</file>
        <file>images/python.jpg</file>
    </qresource>
</rcc>
```
使用时：
```
import apprcc_rc

self.label.setPixmap(QtGui.QPixmap(":/pic/images/python.jpg"))
```

## PyQt5基本窗口控件
QMainWindow：窗口包含菜单栏，工具栏，状态栏和标题栏，常用于构成主窗口，不能设置布局（使用setLayout()方法），因为它有自己的布局  
QWidget：窗口不确定，需要动态嵌入  
QDialog：对话框，短期任务  

QMainWindow中比较重要的方法
方法 | 描述
--- | ---
addToolBar | 添加工具栏
centralWidget | 返回窗口中心的一个控件，未设置时返回NULL
menuBar | 返回主窗口的菜单栏
setCentralWidget | 设置窗口中心的控件
setStatusBar | 设置状态栏
statusBar | 获得状态栏对象后，调用状态栏showMessage(message, int timeout=0)方法，显示状态栏信息，停留时间，单位毫秒，默认0表示一直显示

### 案例
将窗口放置在屏幕中间位置
```
def center(self):
    screen = QDesktopWidget().screenGeometry()
    size = self.geometry()
    self.move((screen.width() - size.width()) / 2, (screen.height() - size.height()) / 2)
```

关闭主窗口
```
app = QApplication.instance()
app.quit()
```

设置图标
```
from PyQt5.QtGui import QIcon

self.setWindowIcon(QIcon('./images/xxx.ico'))
```

设置气泡提示：QToolTip

## QWidget
设置区域大小  
可改变：  
QWidget.resize(width, height)  
不可改变：  
QWidget.setFixedSize(width, height)  
QWidget.setFixedWidth(width)  
QWidget.setFixedHeight(height)  

获取区域大小  
Qwidget.size()  
Qwidget.width()  
Qwidget.height()

设置区域位置  
Qwidget.move(x, y)

获取左上角坐标  
Qwidget.pos()

同时改变大小和位置  
QWidget.setGeometry(x, y, width, height)  
获取窗口大小和位置  
QWidget.frameGeometry()

## QLabel

## 参考资料
https://lovesoo.org/2020/03/14/pyqt-getting-started/
https://www.cnblogs.com/linyfeng/p/11223707.html