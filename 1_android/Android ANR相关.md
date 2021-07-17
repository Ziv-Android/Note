## 什么是ANR？
Application Not Responding，应用无响应是Android系统对应用程序主线程的限制，要求在限定时间范围内处理完成操作。ANR由消息处理机制保证，核心原理是消息调度（由system_server进程调度派发，应用进程处理）和超时处理（Activity-5s、BroadCastReceiver-10s、Service-20s）

主线程中的耗时操作：密集CPU计算，大量IO，复杂界面布局，访问网络，Socket 通信，查询大 量 SQL 语句，复杂逻
辑计算等，其中在Android 4.0版本之后被禁止主线程访问网络

## ANR日志分析
`/data/anr/traces.txt`