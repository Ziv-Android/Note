## 什么是ANR？
Application Not Responding，应用无响应是Android系统对应用程序主线程的限制，要求在限定时间范围内处理完成操作。ANR由消息处理机制保证，核心原理是消息调度（由system_server进程调度派发，应用进程处理）和超时处理（Activity-5s、BroadCastReceiver-10s、Service-20s）

主线程中常见的耗时操作：
密集CPU计算，如复杂布局，复杂科学计算
IO阻塞，频繁复杂SQL查询
网络阻塞，如Socket.read
错误线程方法调用，主线程调用Thread.wait/Thread.sleep等

## ANR日志分析
`/data/anr/traces.txt`

## 改善策略
尽可能将耗时操作转移至非UI线程
### AsyncTask
AsyncTask是一个抽象的泛型类，提供Params，Progress，Result三个泛型参数，不需要时传Void
Params：参数类型
Progress：后台任务执行进度
Result：后台返回的结果类型

AsyncTask默认的线程池是进程范围共享，当线程数超过线程池的最大容量，线程池会爆掉（3.0以后改为串行，避免该问题）
AsyncTask内默认线程池
核心线程数为CPU + 1
最大线程数CPU * 2 + 1


### Thread、HandlerThread + Process.setThreadPoiority(Process.THREAD_PRIORITY_BACKGROUND)


### ThreadPool

## 可以异步更新UI的方法
### AsyncTask

### Handler.sendMessage

### runOnUIThread

### RxJava

