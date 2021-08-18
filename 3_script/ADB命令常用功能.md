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
7. broadcast
8. instrument
9. profile start
10. profile stop
11. dumpheap
12. set-debug-app
13. clear-debug-app
14. monitor
15. screen-compat
16. display-densoty
17. to-uri
18. to-intent-uri


## adb-shell-pm


https://blog.csdn.net/wang18323834864/article/details/78618748