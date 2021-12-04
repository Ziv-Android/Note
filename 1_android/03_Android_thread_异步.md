## 什么是ANR？
Application Not Responding，应用无响应是Android系统对应用程序主线程的限制，要求在限定时间范围内处理完成操作。ANR由消息处理机制保证，核心原理是消息调度（由system_server进程调度派发，应用进程处理）和超时处理（Activity/InputDispatching-5s、ContentProvider-10s、BroadCastReceiver-10s、Service-20s、后台广播BroadcastQueue-60s、后台服务Service-200s）

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

AsyncTask内默认线程池THREAD_POOL_EXECUTOR参数
核心线程数为CPU + 1
最大线程数CPU * 2 + 1
工作队列长度128
线程等待队列长度28

使用AsyncTask的常见问题：
1. AsyncTask默认的线程池是进程范围共享，当线程数超过线程池的最大容量，线程池会爆掉和并发数据一致性问题，新数据被老数据覆盖（3.0以后改为串行，避免该问题）
2. AsyncTask的生命周期问题，AsyncTask并不会随着启动他的Activity的销毁而终止，耗时任务在界面销毁之后回调onPostExecute(Result result)引起应用crash。因此需要注意在页面销毁前主动执行cancel方法，取消AsyncTask
3. AsyncTask被声明为非静态内部类时，AsyncTask会持有外部Activity的引用，当AsyncTask在界面销毁后保持后台运行时，导致Activity无法回收造成内存泄漏
4. Acticity由于旋转屏幕或被系统kill后重建，则此时的AsyncTask内吃鱼的销毁前的Activity引用，因此无法更新UI界面，造成结果丢失
5. 启动AsyncTask的线程必须是主线程
6. 一定要注意使用的AsyncTask版本：AsyncTask首次引入时异步任务是在一个独立的线程中顺序执行，Android 1.6开始引入线程池，同时支持5个异步任务，超过5个任务后，后面的任务等待。Android 3.0之后限制为每次只启动一个任务，执行完成后在执行第二个任务。

AsyncTask原理
AsyncTask内有两个线程池（ SerialExecutor 和 THREAD_POOL_EXECUTOR ）和一个Handler（ InternalHandler ）其中SerialExecutor用于任务排队，THREAD_POOL_EXECUTOR用于真正的执行任务，InternalHandler用于向主线程发送消息更新UI

### Thread、HandlerThread + Process.setThreadPoiority(Process.THREAD_PRIORITY_BACKGROUND)


### ThreadPool

## 可以异步更新UI的方法
### AsyncTask

### Handler.sendMessage

### runOnUIThread

### RxJava


## Android优雅实现异步
Why：提高CPU利用率，提升GUI响应速度
RxJava
```java
.subscribeOn(Schedulers.io())
.observerOn(AndroidSchedulers.mainThread())
.onErrorReturnItem(t -> mapThrowableToResponse(t))
.as(AutoDispose.autoDisposable(ViewScopeProvider.from(view)))
.subscribe(response -> updateUI(response))
```

RxJava使用注意点：
1. 不处理异常会crash（标准可定义在0.5%以下）**OnErrorNotImplementedRException**，onErrorReturnItem，全局异常处理RxjavaPlugins.setErrorHandler(e -> {// 上报异常})
2. 取消操作，创建List存储Rx对象任务，在onDestory统一遍历执行dispose取消处理，或使用AutoDispose.autoDisposable(ViewScopeProvider.from(xxx))，监听View状态自动取消订阅


Kotlin协程
```kotlin
suspend fun sendRequest(req: Request) = suspendCoroutine<Response> {
    continuation ->
    sendRequest(req, continuation::resume)
}

button.onClick {
    val req = Request()
    val resp = async { sendRequest(req) }.await()
    updateUI(resp)
}

fun View.onClickAutoDisposable (
    context: CorountineContext = Despatchers.Main,
    handler: suspend CoroutineScpoe(v: View?) -> Unit
) {
    setOnClickListener { v -> 
        GlobalScope.launch(context, CoroutineStart.DEFAULT) {
            handler(v)
        }.asAutoDisposable(v)
    }
}
```

Kotlin协程使用注意：
1. 异常处理与同步代码一致，直接try...catch...
2. 协程取消：asAutoDisposable
