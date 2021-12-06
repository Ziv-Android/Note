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

