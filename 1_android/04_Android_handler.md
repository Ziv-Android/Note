## 非UI线程为什么不能更新UI
1. 线程安全问题，UI操作无法接受线程同步导致的性能开销，为了正确显示赋值和显示都必须控制
2. handler.postMessage或view.postInvalidate通知UI更新（间接更新）
3. SurfaceView，TextureView，GLSurfaceView独立线程，均不使用UI线程提高UI响应效率lockCanvas->draw->unlockCanvasAndPost，GLThread->run->guardedRun->view.mRenderer.OnDrawFrame(gl)

## Looper,Message,MessageQueue
Looper::pollInner
epoll_create
```
mEpollFd = epoll_create(EPOLL_SIZE_HINT);
```
epoll_ctl
```
int result = epoll_ctl(mEpollFd, EPOLL_CTL_ADD, mWeakEvnetFd, &eventItem);
```
epoll_wait
```
struct epoll_event eventItems[EPOLL_MAX_EVENTS];
int eventCount = epoll_wait(mEpollFd, eventItems, EPOLL_MAX_EVENTS, timeoutMillis);
```
IO多路复用：1. 监控红黑树rbtree 2. 事件就序列表rdlist 3. 通过管道唤醒
拓展阅读《Unix环境高级编程》

## 实现简单Handler-looper框架
Handler核心能力：MessageQueeu，sendMessage，sendMessageDelayed，post，postDelayed

msg.when = delay
sendMessage => messageQueeu.enqueueMessage(msg)

