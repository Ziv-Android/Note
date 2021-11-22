## Activity启动过程（AMS）
进程A => startActivity , 通过ActivityManagerProxy(AMP) => 调用到system_service进程的ActivityManagerService(AMS)， AMS => 经过解析Activity信息，处理启动参数，启动目标进程：由Zygote孵化fock出一个新的进程，锁定新进程 => 调用ApplicationThreadProxy(ATP)调用scheduleLaunchActivity执行到进程B的ActivityThread的startActivity，进入目标Activity的生命周期

插件化的逻辑就可以从startActivity后开始Hock到ActivityThread调用实际Activity之前再次Hock

Activity参数传递：
1. 使用Bundle：binder缓冲区对数据的限制 -> 大小受限制，必须可以序列化。(少量数据可以输用，大量数据不可使用)
2. 同一进程Model共享，不同进程时使用ContentProvider等类似的跨进程共享数据手段完成数据传递(解耦Data和UI)

Instrumentation启动Activity的原理是通过反射newInstance()的方式创建实例，因此Activity不能包含有参数的构造方法，fragment也不推荐实现一个含有参数的构造方法，当Activity销毁重建时FragmentManager负责通过类似的newInstance的方式重建被销毁的Fragment，因此最好不要实现有参数fragment构造方法，如果不能避免一定要有，需要提供默认参数

## Binder通信机制


## 插件化HockActivity


## Activity窗口显示流程
ActivityThread接收到handleLaunchActivity后
newActivity
activity：attach            ->          createPhoneWindow
activity：create            ->          
activity：start             ->          installDector
activity：restoreState      ->          addContentView
activity：postCreate        ->          setContentView
activity：resume            ->          getDecorView
activity：makeVisable       ->          DecorView(显示)：statusBar -> actionBar -> contentView

## 获取View宽高
getWidth/getHeight与getMeasureWidth/getMeasureHeight

## Activity转场动画实现原理
共享元素，记录起始和终止两个位置的坐标和属性，然后通过动画播放