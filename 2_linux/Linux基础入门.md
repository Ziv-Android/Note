# Linux基础入门

## 目录操作
### 创建目录
```bash
mkdir dir
```
### 切换目录
```bash
cd dir
```
### 移动目录
```bash
mv yuan mudi
```
### 删除目录
```bash
rm -rf dir
```
### 查看目录下的文件
```bash
ls dir
```
## 文件操作
### 创建文件
```bash
touch dir/fileName
```
### 复制文件
```bash
cp yuanFile mudiFile
```
### 删除文件
```bash
rm fileName
```
### 查看文件内容
```bash
cat dir/fileName
```
## 过滤、管道与重定向
### 过滤
过滤出 /etc/passwd 文件中包含 root 的记录
```bash
grep 'root' /etc/passwd
```
递归地过滤出 /var/log/ 目录中包含 linux 的记录
```bash
grep -r 'linux' /var/log/
```
### 管道
简单来说, Linux 中管道的作用是将上一个命令的输出作为下一个命令的输入, 像 pipe 一样将各个命令串联起来执行, 管道的操作符是 |
比如, 我们可以将 cat 和 grep 两个命令用管道组合在一起
```bash
cat /etc/passwd | grep 'root'
```
过滤出 /etc 目录中名字包含 ssh 的目录(不包括子目录)
```bash
ls /etc | grep 'ssh'
```
### 重定向
可以使用 > 或 < 将命令的输出重定向到一个文件中
```bash
echo 'Hello World' > ~/test.txt
```
## 运维常用命令
### ping命令
对 cloud.tencent.com 发送 4 个 ping 包, 检查与其是否联通
```bash
ping -c 4 cloud.tencent.com
```
### netstat命令
netstat 命令用于显示各种网络相关信息，如网络连接, 路由表, 接口状态等等
列出所有处于监听状态的tcp端口
```bash
netstat -lt
```
查看所有的端口信息, 包括 PID 和进程名称
```bash
netstat -tulpn
```
### ps命令
过滤得到当前系统中的 ssh 进程信息
```bash
ps -aux | grep 'ssh'
```

参考资料：
https://cloud.tencent.com/developer/labs/gallery?utm_source=portal&utm_medium=recommend&utm_campaign=recmd1