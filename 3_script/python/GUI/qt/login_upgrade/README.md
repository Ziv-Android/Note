## 批量升级工具设计

### 技术点

#### 多线程异步更新UI
使用QThread开启线程池后，添加Runnable执行任务，任务执行完成后通过pyqtSignal信号/槽进行UI更新
```python
from PyQt5.QtCore import Qt, QObject, QRunnable, QThread, QThreadPool, pyqtSignal

"""
定义
"""
class WorkerSignal(QObject):
    progress = pyqtSignal(int, dict)
    finished = pyqtSignal()
    active_count = pyqtSignal(int)

    def __init__(self):
        super(WorkerSignal, self).__init__()


class Worker(QRunnable):
    def __init__(self, name, _signal=None):
        super().__init__()
        
class UpgradeThread(QThread):

```

