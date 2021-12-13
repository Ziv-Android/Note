## 基础
### 常用布局
约束布局ConstraintLayout，线性布局LinearLayout，相对布局RelativeLayout，表格布局TableLayout，帧布局FrameLayout，绝对布局Absolutelayout

### 布局优化
1. 使用include标签加载重复布局
2. 使用merge标签减少布局嵌套
3. 使用ViewStub动态控制布局显示

### 动画

### 自定义View

## 深入
### View的工作原理
#### Vsync机制
Vertical Synchronization垂直同步，Android系统自4.1版本引入每16ms发出一次用来同步SurfaceFlinger向硬件渲染
Vsync机制分为两步：
1. Vsync同步：CPU/GPU接收VSYNC信号提前准备下一帧要显示的内容，保证画面流畅性
2. 多级缓冲：三级缓冲buffer，当数据准备时间过长时，使用第三级缓冲减少同步间的空白间隙，减少Display的Jank产生
3. Vsync虚拟化（4.4）：即把硬件/软件创建的**VsyncThread**产生的VSync信号（Hardware VSync）先同步到一个本地VSync模型（Hardware-based VSync Model）中，由**DispSyncThread**处理vsync将其虚拟化为**vsync-app和vsync-sf**，vsync-app和vsync-sf（Vsync for AppUI 和VSync for SurfaceFlinger)按需产生，如果App和SurfaceFlinger都没有更新请求，则休眠省电。即**SurfaceFlingerThread、DispSyncThread、EventThead-App、EventThead-SF、VsyncThread**都属于SurfaceFlinger线程，相互协作完成同步，EventControlThread是用来向真实的VSync硬件发命令。

![Android_VSync_框架](./Android%20VsyncThread.png)

拓展[代码分析](https://www.cnblogs.com/blogs-of-lxl/p/11443693.html)

![Android_VSync_时序图](./Android%20Vsync时序图.png)
1. 启动SurfaceFlinger主线程:mian_surfaceflingger.cpp
2. sp<SurfaceFlinger> flinger = new SurfaceFlinger()创建DispSync，DispSync构造函数启动DispSyncThread线程
3. SurfaceFlinger对象是一个strong point，引用时onFirstRef()方法执行mEventQueue.init()初始化消息队列，创建loop和handle
4. flinger->init()：创建EGLDisplay并初始化，创建两条EventThread，设置MessageQueeu的EventThread（获取了Thread的fd用于通信），创建RenderEngine
5. flinger->run()调用mEventQueue.waitMessage()等待EventThread-SF发送数据
6. 

### 

### Window和WindowManager

### DocerView


## 拓展
### Flutter


## 参考资料
[Android View绘制原理](https://juejin.cn/post/6844903903926960142)
[Android View工作原理](https://tom510230.gitbooks.io/android_ka_fa_yi_shu_tan_suo/content/chapter4.html)
[Flutter](https://juejin.cn/post/6844903901641048077)
[Handler](https://juejin.cn/post/6860842594885173262#heading-1)