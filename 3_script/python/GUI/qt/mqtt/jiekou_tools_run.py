
import sys
#PyQt5中使用的基本控件都在PyQt5.QtWidgets模块中
from PyQt5.QtWidgets import QApplication, QMainWindow,QFileDialog
# from PyQt5 import QtGui #上传图片用
from jiekou_tools import Ui_Form
from flask import Flask, request
import json
import _thread
app = Flask(__name__)
@app.route("/callBack", methods=["get"])
def check():
    f = open("pic.txt", "a")
    # 默认返回内容
    return_dict = {'return_code': '200', 'return_info': '连接成功', 'result': True}
    # 获取传入的参数
    get_Data = request.get_data()
    print(get_Data)
    print(type(get_Data))
    # 传入的参数为bytes类型
    get_Data = bytes.decode(get_Data) #转化为python的字符串数据
    print(get_Data)
    print(type(get_Data))
    f.write(get_Data)
    f.write(",")
    return json.dumps(return_dict, ensure_ascii=False)

@app.route("/callBacks", methods=["post"])
def checks():
    # 获取传入的参数
    i = 1 #后面判断参数是否存在使用
    get_Data = request.get_data()
    # 传入的参数为bytes类型
    get_Data = bytes.decode(get_Data)#转化为python的字符串数据
    print(get_Data)
    print(type(get_Data))
    get_Data = json.loads(get_Data) #序列化为字典
    try:
        if get_Data["name"] :
            i = 2
        if get_Data["age"] :
            i = 3
        if get_Data["sex"] :
            i = 4
        if get_Data["type"] :
            i = 5
            if get_Data["type"] not in (1,2,3):
                return {"code": "1002", "msg": "type类型错误"}
        return {"code":"1","msg":"请求成功","name":"王四","age":18}
    except:
        if i == 1:
            return  {"code":"1001","msg":"name参数缺失"}
        if i == 2:
            return  {"code":"1001","msg":"age参数缺失"}
        if i == 3:
            return  {"code":"1001","msg":"sex参数缺失"}
        if i == 4:
            return  {"code":"1001","msg":"type参数缺失"}

@app.route("/callBackss", methods=["put"])
def check_put():
    # 获取传入的参数
    get_Data = request.get_data()
    # 传入的参数为bytes类型
    get_Data = bytes.decode(get_Data)#转化为python的字符串数据
    print(get_Data)
    print(type(get_Data))
    return {"code":"1"}



class MyMainForm(QMainWindow, Ui_Form):
    basimg = ''
    def __init__(self, parent=None):
        super(MyMainForm, self).__init__(parent)
        self.setupUi(self)
        #添加信号和槽。注意要执行的函数不加小括号()，必须在这里写了事件才会触发页面流程，
        #clicked信号一定要记住。clicked信号就是指鼠标左键按下然后释放时会发送信号，从而触发相应操作
        self.ks.clicked.connect(self.displayss)

    def displayss(self):
        ''''''
        print(333333333)
        app.run(host="0.0.0.0", port=9665, debug=True)


if __name__ == "__main__":
    #固定的，PyQt5程序都需要QApplication对象。sys.argv是命令行参数列表，确保程序可以双击运行
    apps = QApplication(sys.argv)
    #初始化
    myWin = MyMainForm()
    #将窗口控件显示在屏幕上
    myWin.show()
    #程序运行，sys.exit方法确保程序完整退出。
    sys.exit(apps.exec_())




