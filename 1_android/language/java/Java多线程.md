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

非final成员指令重排会被优化至构造方法之外

### ThreadLocal
绑定到线程上的ThreadLocalMap，ThreadLocalMap（开放定址法）与WeakHashMap（单链表法）：ReferenceQueue

使用时，声明全局静态final成员，避免存储大量对象，用完后及时移除

### ConcurrentHashMap
HashMap为什么不是线程安全的

HashTable有什么缺陷
直接对HashTable对象加锁，读写一把锁，从头加到尾

#### 发展历程
1. JDK5：分段锁，必要时加锁，由于分段segment策略问题，当Key为三万到五十万的整数时，hash后基本在14~15之间导致退化为HashTable，效率大大降低
2. JDK6：优化二次Hash算法，优化Key的Hash均匀分布，16个segment
3. JDK7：段懒加载，volatile + cas，getObjectVolatile
4. JDK8：摒弃段，基于HashMap原理的并发实现，锁转移至table操作上

#### CurrentHashMap如何计数
JDK5~7：基于段元素个数求和，两次计算结果不一样则加锁再求一次
JDK8：引入CounterCell，本质上还是分段计数

#### CurrentHashMap是弱一致性
添加元素后不一定马上能读到，清空之后可能仍然后元素，遍历之前的段元素的变化会读到，遍历之后的段元素变化读不到，遍历时元素发生变化不抛异常


### synchronized原理
执行控制的目的是控制代码执行（顺序）及是否可以并发执行。

内存可见控制的是线程执行结果在内存中对其它线程的可见性。根据Java内存模型的实现，线程在具体执行时，会先拷贝主存数据到线程本地（CPU缓存），操作完成后再把结果从线程本地刷到主存。

synchronized关键字解决的是**执行控制**的问题，它会阻止其它线程获取当前对象的监控锁，这样就使得当前对象中被synchronized关键字保护的代码块无法被其它线程访问，也就无法并发执行。更重要的是，synchronized还会创建一个内存屏障，内存屏障指令保证了所有CPU操作结果都会直接刷到主存中，从而保证了操作的内存可见性，同时也使得先获得这个锁的线程的所有操作，都happens-before于随后获得这个锁的线程的操作。
volatile关键字解决的是**内存可见性**的问题，会使得所有对volatile变量的读写都会直接刷到主存，即保证了变量的可见性。这样就能满足一些对变量可见性有要求而对读取顺序没有要求的需求。

### volatile与synchronized区别和联系
hanppens-before原则
volatile本质是在告诉jvm当前变量在寄存器（工作内存）中的值是不确定的，需要从主存中读取； synchronized则是锁定当前变量，只有当前线程可以访问该变量，其他线程被阻塞住。
volatile仅能使用在变量级别；synchronized则可以使用在变量、方法、和类级别的
volatile仅能实现变量的修改可见性，不能保证原子性；而synchronized则可以保证变量的修改可见性和原子性
volatile不会造成线程的阻塞；synchronized可能会造成线程的阻塞。
volatile标记的变量不会被编译器优化；synchronized标记的变量可以被编译器优化

### 锁
长锁不如短锁：尽可能只锁必要的部分
大锁不如小锁：尽可能对加锁对象进行拆分
公锁不如私锁：尽可能将锁的逻辑放到私有代码中
嵌套锁不如扁平锁：尽可能在代码设计时避免嵌套锁
分离读写锁：尽可能将读锁和写锁分离
粗化高频锁：尽可能合并处理调用频繁且过短的锁
消除无用锁：尽可能不加锁或使用volatile代替锁

### 原子性、可见性、指令重排 