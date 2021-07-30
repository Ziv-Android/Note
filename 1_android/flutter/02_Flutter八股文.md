## Flutter基础


## Flutter单线程如何保证流畅性

Dart中是单isolate线程执行，包含两个事件队列，微任务事件队列和事件队列
微任务队列：包含Dart内部的微任务，主要由**scheduleMicrotask**调度，需要引入`import 'dart:async'`
事件队列：包含I/O，Timer，绘制事件等外部事件

事件执行优先级
mian > 微任务 > 事件任务

通过Isolate实现多线程`import 'dart:isolate'`，线程之间不共享内存，只能通过消息机制通信

## 

