"""
实现多线程但执行耗时操作会卡住主线程，导致程序未响应
"""
# coding:utf-8

from PyQt5.Qt import QThread, QThreadPool, QRunnable, QObject, QWidget, QApplication, QPushButton, QGridLayout, QTextEdit, pyqtSignal, QTextCursor
import sys
import time


# 这里执行核心代码
class Thread(QRunnable):
    communication = None

    def __init__(self):
        super(Thread, self).__init__()
        self.thread_logo = None

    def run(self):
        progress = 0
        while progress <= 100:
            print("TaskThread", "run", "执行实际任务", "progress", progress)
            progress += 1
            # self.data['state'] = "升级中"
            # 模拟耗时操作
            time.sleep(1)
        self.communication.log_signal.emit('{}线程已经执行'.format(self.thread_logo))

    # 自定义函数，用来初始化一些变量
    def transfer(self, thread_logo, communication):
        """
        :param thread_logo:线程标识，方便识别。
        :param communication:信号
        :return:
        """

        self.thread_logo = thread_logo
        self.communication = communication


# 定义任务，在这里主要创建线程
class Tasks(QObject):
    communication = None
    max_thread_number = 0

    def __init__(self, communication, max_thread_number):
        """
        :param communication:通讯
        :param max_thread_number:最大线程数
        """
        super(Tasks, self).__init__()

        self.max_thread_number = max_thread_number
        self.communication = communication

        self.pool = QThreadPool()
        self.pool.globalInstance()

    def start(self):
        # 设置最大线程数

        self.pool.setMaxThreadCount(self.max_thread_number)
        for i in range(10):
            task_thread = Thread()
            task_thread.transfer(thread_logo=i, communication=self.communication)
            task_thread.setAutoDelete(True)  # 是否自动删除
            self.pool.start(task_thread)

        self.pool.waitForDone()  # 等待任务执行完毕
        self.communication.log_signal.emit('线程全部执行完毕')


# 重写QThread类
class NowThread(QThread):
    def __init__(self, communication, max_thread_number):
        """
        :param communication:通讯
        :param max_thread_number:最大线程数
        """
        super(NowThread, self).__init__()
        self.task = Tasks(
            communication=communication,
            max_thread_number=max_thread_number
        )

    def run(self):
        self.task.start()


class Window(QWidget):
    # 定义信号
    log_signal = pyqtSignal(str)

    def __init__(self):
        super().__init__()
        self.resize(1280, 800)
        self.setWindowTitle('QThreadPool实例')
        self.setup_ui()
        self.show()

    def setup_ui(self):
        # 初始化信号关联槽函数
        self.log_signal.connect(self.log_signal_event)

        layout = QGridLayout(self)  # 创建布局

        button = QPushButton('测试按钮', self)
        button.clicked.connect(self.button_event)
        text_edit = QTextEdit()
        text_edit.setObjectName('text_edit')

        layout.addWidget(button, 0, 0)
        layout.addWidget(text_edit, 0, 1)
        self.setLayout(layout)

    def button_event(self):
        thread = NowThread(
            communication=self,
            max_thread_number=5
        )
        thread.start()  # 开始线程
        thread.wait()  # 等待线程

    def log_signal_event(self, p_str):
        text_edit = self.findChild(QTextEdit, 'text_edit')
        text_cursor = QTextCursor(text_edit.textCursor())
        text_cursor.setPosition(0, QTextCursor.MoveAnchor)  # 移动光标
        text_cursor.insertHtml('<p style="font-size:20px;color:red;">{}</p>'.format(p_str))
        text_cursor.insertHtml('<br>')
        text_edit.setTextCursor(text_cursor)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = Window()
    sys.exit(app.exec())
