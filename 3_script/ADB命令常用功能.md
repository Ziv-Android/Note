# ADB命令常用功能
## adb-base
1. 查看ADB版本信息：`adb version`
2. 重启ADB服务：`adb kill-server & adb start-server`
3. 查看多有设备连接信息：`adb devices`
4. 指定设备：`adb -s [设备号] [后续命令]`
5. 将本地（PC）文件推送至远程（手机）：`adb push [源地址] [目的地址]`
6. 将手机（手机）文件取回本地（PC）：`adb pull [源地址] [目的地址]`
7. 安装应用到手机：`adb install -r FileName.apk`
8. 卸载应用：`adb uninstall [packageName]`
9. 进入设备控制台：`adb shell`

## adb-shell-base
1. 查看目录信息：`ls`
2. 切换目录：`cd`
3. 查看进程信息：`ps`或`top`
4. 杀死进程：`kill -9 pid`
5. 移动/重命名文件：`mv [] []`
6. 复制文件：`cp [] []`
7. 删除文件：`rm -rf xxx`(危)
8. 创建文件：``
9. 创建目录：`mkdir xxx`

## adb-shell-am
1. start
2. startservice
3. force-stop
4. kill
5. kill-all
6. broadcast
7. instrument
8. profile start
9. profile stop
10. dumpheap
11. set-debug-app
12. clear-debug-app
13. monitor
14. screen-compat
15. display-densoty
16. to-uri
17. to-intent-uri


## adb-shell-pm


https://blog.csdn.net/wang18323834864/article/details/78618748