# ADB命令释义 v31.0.3-7562133
## adb
adb devices  
adb help  
adb version  

## 网络相关  
adb connect HOST[:PORT]  
adb disconnect  
adb pair  
adb forward --list  
adb forward [--no-rebind] LOCAL REMOTE  
adb forwoad --remote LOCAL  
adb forwoad --remove-all  
ppTTY  
reverse --list  
reverse [--no-rebind] LOCAL REMOTE  
reverse --remove REMOTE  
reverse --remove-all  
mdns check  
mdns services  

## 文件传输  
adb push LOCAL... REMOTE  
adb pull REMOTE... LOCAL  
adb sync  

## 应用安装/卸载  
adb install PACKAGE  
adb install-multiple PACKAGE...  
adb install-multi-package PACKAGES...  
adb uninstall [-k] PACKAGE  

## 日志调试
adb bugreport [PATH]  
adb jdwp  
adb logcat -v time  

## 脚本支持  
adb wait-for-[-TRANSPORT]-STATE..  
TRANSPORT: usb, local, any  
STATE: device, recovery, rescue, sideload, bootloader, disconnect  
adb get-state  
adb get-serialno  
adb get-devpath  
adb remount [-R]  
adb reboot [bootloader|recovery|sideload|sideload-auto-reboot]  
adb sideload OTAPACKAGE  
adb root  
adb unroot  
adb usb  
adb tcpip PORT

## 连接关系
adb start-server
adb kill-server
adb reconnect  
adb reconnect device
adb reconnect offline

## USB操作  
adb attach  
adb detach  

## 环境变量  
adb $ADB_TRACE  
adb $ADB_VENOR_KEYS  
adb $ANDROID_SERIAL  
adb $ANDROID_LOG_TAGS  
adb $ADB_LOCAL_TRANSPORT_MAX_PORT  
adb $ADB_MDNS_AUTO_CONNECT  

## 命令行
adb shell  
adb emu COMMAND  

### adb-shell
1. 查看目录信息：`ls`
2. 切换目录：`cd`
3. 查看进程信息：`ps`或`top`
4. 杀死进程：`kill -9 pid`
5. 移动/重命名文件：`mv [] []`
6. 复制文件：`cp [] []`
7. 删除文件：`rm -rf xxx`(危)
8. 创建文件：``
9. 创建目录：`mkdir xxx`

### adb-shell-am
1. adb shell am start

2. adb shell am startservice
3. adb shell am stopservice
4. adb shell am force-stop
5. adb shell am kill
6. adb shell am kill-all
7. adb shell am broadcast
8. adb shell am instrument
9. adb shell am profile start
10. adb shell am profile stop
11. adb shell am dumpheap
12. adb shell am set-debug-app
13. adb shell am clear-debug-app
14. adb shell am monitor
15. adb shell am screen-compat
16. adb shell am display-densoty
17. adb shell am to-uri
18. adb shell am to-intent-uri


## adb-shell-pm


## 日志
分类 | 说明 | 命令 | 注意
--- | --- | --- | ---
kernel log | 属于Linux内核的log ，可以通过读取/proc/kmsg或者通过串口来抓取。 | `adb shell cat /proc/kmsg > kernel.log` | 需要root权限
radio log | Android RIL层log，常用于调试Android通信方面的代码 | `adb logcat -b radio -v time` |
main log | 默认输出 | `adb logcat -b main -v time` | 默认`-b main`可以省略
event log | event log属于system log，平时可以跟在main log之后 | `adb logcat -b event -v time` |

V(明细:verbose) -> D(调试:debug) -> I(信息:info) -> W(警告:warn) -> E(错误:error) -> F(严重错误:fatal) -> S(无记载:silent)

日志级别过滤
显示V及以上的日志信息：`adb logcat *:V`

日志分类显示
adb logcat -s aaa 指定设备aaa
adb logcat -v tag 指定标签tag
adb logcat -v time
adb logcat -v thread


日志grep过滤（windows使用find代替）
adb logcat | grep PID
adb logcat | grep -i "忽略大小写"

https://blog.csdn.net/wang18323834864/article/details/78618748
https://www.jianshu.com/p/1c9106dd8284