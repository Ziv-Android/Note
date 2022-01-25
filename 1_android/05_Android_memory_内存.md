## 垃圾回收(GC)
虚拟机栈帧、类静态属性引用的变量、常量引用的对象、native方法引用的对象

WeakRef弱引用：触发GC就会回收
SoftRef软引用：内存紧张回收


## 内存优化5R法则
1. Reduce缩减：减少一次性大分配
2. Reuse复用：减少反复分配
3. Recycle回收：避免浪费
4. Refactor重构：合理的数据结构/程序架构
5. Revalue重审：谨慎多进程，Large Heap和第三方框架的使用