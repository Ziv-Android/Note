## Flutter简介
开发效率高
开发阶段：基于JIT模式避免每次改动都要进行编译，极大的节省了开发时间  
发布阶段：基于AOT模式，保证应用性能

类型安全
由于Dart是类型安全的语言，支持静态类型检测，所以可以在编译前发现一些类型的错误

!(Framework)[pics/framework_flutter.png]
## Flutter基础
var、dynamic和Object、final和const  
var用于变量定义，赋值后类型便确定，后期不能改变
dynamic
Object

## Flutter单线程如何保证流畅性

Dart中是单isolate线程执行，包含两个事件队列，微任务事件队列和事件队列
微任务队列：包含Dart内部的微任务，主要由**scheduleMicrotask**调度，需要引入`import 'dart:async'`
事件队列：包含I/O，Timer，绘制事件等外部事件

事件执行优先级
mian > 微任务 > 事件任务

通过Isolate实现多线程`import 'dart:isolate'`，线程之间不共享内存，只能通过消息机制通信

## 

