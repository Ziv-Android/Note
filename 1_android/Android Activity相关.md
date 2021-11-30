## Activity的OnActivityResult使用场景
页面跳转传值时使用，通过Boundle传值，处理逻辑分离，需要开发者自己保证类型安全，和处理逻辑一致问题，实现臃肿

### 使用回调会有什么问题
原Activity不是100%可信，由于内存或策略会被销毁，存在引用需要变换的问题

Activity内的Fragment会持有外部activity的引用，用过这里反射获取新的Activity后刷新在回调接口中


### RxPermission

### kotlin中新增Activity Results API方案



## Activity启动流程
### Activity启动过程（AMS）
进程A => startActivity , 通过ActivityManagerProxy(AMP) => 调用到system_service进程的ActivityManagerService(AMS)， AMS => 经过解析Activity信息，处理启动参数，启动目标进程：由Zygote孵化fock出一个新的进程，锁定新进程 => 调用ApplicationThreadProxy(ATP)调用scheduleLaunchActivity执行到进程B的ActivityThread的startActivity，进入目标Activity的生命周期

插件化的逻辑就可以从startActivity后开始Hock到ActivityThread调用实际Activity之前再次Hock

Activity参数传递：
1. 使用Bundle：binder缓冲区对数据的限制 -> 大小受限制，必须可以序列化。(少量数据可以输用，大量数据不可使用)
2. 同一进程Model共享，不同进程时使用ContentProvider等类似的跨进程共享数据手段完成数据传递(解耦Data和UI)

Instrumentation启动Activity的原理是通过反射newInstance()的方式创建实例，因此Activity不能包含有参数的构造方法，fragment也不推荐实现一个含有参数的构造方法，当Activity销毁重建时FragmentManager负责通过类似的newInstance的方式重建被销毁的Fragment，因此最好不要实现有参数fragment构造方法，如果不能避免一定要有，需要提供默认参数

### Binder通信机制


### 插件化HockActivity


### Activity窗口显示流程
ActivityThread接收到handleLaunchActivity后
newActivity
activity：attach            ->          createPhoneWindow
activity：create            ->          
activity：start             ->          installDector
activity：restoreState      ->          addContentView
activity：postCreate        ->          setContentView
activity：resume            ->          getDecorView
activity：makeVisable       ->          DecorView(显示)：statusBar -> actionBar -> contentView

### 获取View宽高
getWidth/getHeight与getMeasureWidth/getMeasureHeight

### Activity转场动画实现原理
共享元素，记录起始和终止两个位置的坐标和属性，然后通过动画播放

## 跨App启动Activity有哪些注意点
1. 设置sharedUserId后可用包名 + 类名直接启动
2. 使用exported暴漏本身，需要添加权限验证，以及拒绝服务漏洞（intent.getExtras()）
3. 通过InterFilter隐式调用

## 如何解决Activity参数传递的类型安全及接口复杂问题（人工永远都会出错）
类型安全：Bundle的K-V不能在编译期保证类型
接口复杂：启动Activity时参数和结果传递都要依赖Intent

通过注解处理器生成参数处理Builder

## 代码任意位置给当前Activity添加View
如何在任意位置获取当前Activity，在生命周期LifecycleCallBacks中的onActivityCreate回调下使用`private static WeakReference<Activity> currentActivityRef = new WeakReference<>(activity)`即可获取当前Activity

Activity窗口认知

潜在的内存泄漏以及内存回收机制

如何评估技术方案合理性

## 微信右滑效果


Kotlin相关
空安全
与Java怎么互通