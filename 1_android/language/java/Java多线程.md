## 线程
线程被强制stop后，会导致内存中的状态没有处理，文件未关闭等种种异常
线程不能stop，但线程任务可以停止。线程是协作的任务执行模式。Interrupt和boolean标志位，常用boolean

interrupt能处理到系统方法，如sleep，boolean不行
interrupt使用JNI和锁，因此在性能上稍微弱一点点

Interrupt后抛出`InterruptedException`异常，捕获后处理线程操作的文件、释放资源。在连续多次的任务进行中，该方法需要在每次循环中主动判断`interrupted()`方法，来决定是否退出线程任务

使用boolean标志位，需要注意使用volatile关键字保证标志位可见性

### interrupted()与isInterrupted()
interrupted()是静态方法，获取JNIEnv绑定`(env)->self->Interrupted()`**当前线程**的中断状态，并清空，重复调用首次true，后续返回false

isInterrupted()是非静态方法，获取`Thread::FromManagedThread()`**Java线程对象对应的底层线程对象**的中断状态，不清空，重复调用中断清空前一直是true

底层使用MutexLock加锁

## 多线程
final、volatile，ThreadLocal使用注意事项

线程安全：产生于可变资源（内存）的线程间共享

ThreadLocal
绑定到线程上的ThreadLocalMap

ThreadLocalMap与WeakHashMap：ReferenceQueue
开放定址法 - 单链表法

使用时，声明全局静态final成员，避免存储大量对象，用完后及时移除

非final成员被移至构造方法之外


### synchronized原理

### volatile与synchronized区别和联系
hanppens-before原则

### 锁
### 原子性、可见性、指令重排 