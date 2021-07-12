# ADB命令常用功能
1. 查看ADB版本信息
```bash
adb version
```
2. 查看多有设备连接信息
```bash
adb devices
```
3. 将本地（PC）文件推送至远程（手机）
```bash
adb push [源地址] [目的地址]
```
4. 将手机（手机）文件取回本地（PC）
```bash
adb pull [源地址] [目的地址]
```
5. 重启ADB服务
```shell
transfer error: Invalid argument
Adb connection Error:远程主机强迫关闭了一个连接
Connection attempts:1
Connection attempts:2
···
```
使用ADB命令
```bash
adb kill-server
adb start-server
```
6. 安装卸载手机应用
```shell
Failure [INSTALL_FAILED_ALREADY_EXISTS]
```
安装应用到手机
```bash
adb install FileName.apk
```
卸载应用
```bash
adb uninstall [packageName]
```
7. 进入设备控制台
```bash
adb shell
```
**进入控制台后可以使用**
查看目录信息
```shell
ls
```
查看进程信息
```shell
ps
```
杀死进程
```shell
kill pid
```
