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