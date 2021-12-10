import logging
import random
import sys
import time

from PyQt5.QtCore import QObject, QThread, QRunnable, QThreadPool, pyqtSignal  # 需要导入这些库
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QApplication,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class HnQtPoolThread(QThread):
    '''
    线程池线程，用于管理线程池
    '''

    def __init__(self):
        super().__init__()
        self.threadpool = HnQTThreadPool()

    def run(self):
        '''
        启动线程池
        '''
        self.threadpool.Start()

    def addThread(self, _thread):
        self.threadpool.addThread(_thread)


class HnQTThreadPool():
    '''
        线程池
    '''
    thread_list = []

    def __init__(self):
        super().__init__()
        self.threadpool = QThreadPool()
        self.threadpool.globalInstance()
        # poolnum = tool.loadJsons(tool.setting_address)[0]['pool_num']
        self.threadpool.setMaxThreadCount(3)

    def addThread(self, _thread):
        self.thread_list.append(_thread)

    def Start(self):
        for i in self.thread_list:
            self.threadpool.start(i)
        self.threadpool.waitForDone()
        self.thread_list.clear()


class HnSignal(QObject):
    progress_signal = pyqtSignal(int)
    result_signal = pyqtSignal(str)

    def __init__(self):
        super().__init__()


logging.basicConfig(format="%(message)s", level=logging.INFO)


class Runnable(QRunnable):
    def __init__(self, n):
        super().__init__()
        self.n = n

    def run(self):
        # Your long-running task goes here ... (需要放在 run 这个函数里)
        for i in range(5):
            logging.info(f"Working in thread {self.n}, step {i + 1}/5")
            time.sleep(random.randint(700, 2500) / 1000)


# Step 1: Create a worker class
class Worker(QObject):
    finished = pyqtSignal()  # 结束的信号
    progress = pyqtSignal(int)

    def run(self):
        """Long-running task."""
        print("Worker", "run")
        for i in range(5):
            time.sleep(1)
            self.progress.emit(i + 1)  # 发出表示进度的信号
        self.finished.emit()  # 发出结束的信号


class Window(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.clicksCount = 0
        self.setupUi()
        self.threads = []

    def setupUi(self):
        """创建主界面
        """
        self.setWindowTitle("Freezing GUI")
        self.resize(300, 180)
        self.centralWidget = QWidget()
        self.setCentralWidget(self.centralWidget)
        # Create and connect widgets
        self.clicksLabel = QLabel("Counting: 0 clicks", self)
        self.clicksLabel.setAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.stepLabel = QLabel("Long-Running Step: 0")
        self.stepLabel.setAlignment(Qt.AlignHCenter | Qt.AlignVCenter)
        self.countBtn = QPushButton("Click me!", self)
        self.countBtn.clicked.connect(self.countClicks)
        self.longRunningBtn = QPushButton("Long-Running Task!", self)
        self.longRunningBtn.clicked.connect(self.runLongTask)
        self.startThreadsBtn = QPushButton("QThread list!", self)
        self.startThreadsBtn.clicked.connect(self.startThreads)
        self.startTasksBtn = QPushButton("QThreadPool!", self)
        self.startTasksBtn.clicked.connect(self.runTasks)
        self.startHnQtTasksBtn = QPushButton("HnQThreadPool!", self)
        self.startHnQtTasksBtn.clicked.connect(self.runHnQtTasks)
        # Set the layout
        layout = QVBoxLayout()
        layout.addWidget(self.clicksLabel)
        layout.addWidget(self.countBtn)
        layout.addStretch()
        layout.addWidget(self.stepLabel)
        layout.addWidget(self.longRunningBtn)
        layout.addWidget(self.startThreadsBtn)
        layout.addWidget(self.startTasksBtn)
        layout.addStretch()
        layout.addWidget(self.startHnQtTasksBtn)
        self.centralWidget.setLayout(layout)

    def countClicks(self):
        self.clicksCount += 1
        self.clicksLabel.setText(f"Counting: {self.clicksCount} clicks")

    def reportProgress(self, n):
        self.stepLabel.setText(f"Long-Running Step: {n}")

    def runLongTask(self):
        """修改复杂任务的函数
        """
        # Step 2: Create a QThread object
        self.thread = QThread()
        # Step 3: Create a worker object
        self.worker = Worker()
        # Step 4: Move worker to the thread
        self.worker.moveToThread(self.thread)
        # Step 5: Connect signals and slots
        self.thread.started.connect(self.worker.run)  # 通知开始
        self.worker.finished.connect(self.thread.quit)  # 结束后通知结束
        self.worker.finished.connect(self.worker.deleteLater)  # 完成后删除对象
        self.thread.finished.connect(self.thread.deleteLater)  # 完成后删除对象
        self.worker.progress.connect(self.reportProgress)  # 绑定 progress 的信号
        # Step 6: Start the thread
        self.thread.start()
        # Final resets (结束的时候做的事)
        self.longRunningBtn.setEnabled(False)  # 将按钮设置为不可点击
        self.thread.finished.connect(
            lambda: self.longRunningBtn.setEnabled(True)
        )
        self.thread.finished.connect(
            lambda: self.stepLabel.setText("Long-Running Step: 0")
        )

    def createThread(self):
        thread = QThread()
        worker = Worker()
        worker.moveToThread(thread)
        thread.started.connect(worker.run)  # 通知开始
        worker.finished.connect(thread.quit)  # 结束后通知结束
        worker.finished.connect(worker.deleteLater)  # 完成后删除对象
        thread.finished.connect(thread.deleteLater)  # 完成后删除对象
        worker.progress.connect(self.reportProgress)  # 绑定 progress 的信号
        return thread

    def startThreads(self):
        self.startThreadsBtn.setEnabled(False)  # 将按钮设置为不可点击
        self.threads.clear()
        for i in range(4):
            self.threads.append(self.createThread())

        for thread in self.threads:
            print(thread)
            thread.start()

    def runTasks(self):
        threadCount = QThreadPool.globalInstance().maxThreadCount()  # 设置最大线程数
        # self.label.setText(f"Running {threadCount} Threads")  # 更新 label 有多少线程
        pool = QThreadPool.globalInstance()
        for i in range(threadCount):
            # 2. Instantiate the subclass of QRunnable
            runnable = Runnable(i)  # 实例化 Runnable, 使用 i 来标识当前的线程,
            # 3. Call start()
            pool.start(runnable)  # 在线程池中进行 start

    def runHnQtTasks(self):
        print("runHnQtTasks")
        hnQtPoolThread = HnQtPoolThread()
        for i in range(10):
            runnable = Runnable(i)
            hnQtPoolThread.threadpool.addThread(runnable)

        hnQtPoolThread.start()


app = QApplication(sys.argv)
win = Window()
win.show()
sys.exit(app.exec())
