# 使用VSFTPD搭建FTP服务器

## 安装vsftpd
```shell
sudo apt-get install vsftpd -y
```

## 启动vsftpd
安装完成后vsftpd会默认使用21端口自动启动，通过netstat命令查看状态
```shell
sudo netstat -nltp | grep 21
```
如果没有启动，则手动启动vsftpd服务
```shell
sudo systemctl start vsftpd.service
```

## 创建欢迎信息（可选）
方便用户登录后可以看到欢迎信息，并且确定用户确实登录到了主目录上。
```shell
sudo mkdir /home/uftp
sudo touch /home/uftp/welcome.txt
```

## 新建用户uftp并设置密码
```shell
sudo useradd -d /home/uftp -s /bin/bash uftp
sudo passwd uftp
sudo rm /etc/pam.d/vsftpd
```
> 重要：第三步该文件必须被删除，否则会出现无法登陆的情况

## 修改vsftpd配置
### 修改限制仅通过FTP访问
```shell
sudo usermod -s /sbin/nologin uftp
```
### 修改vsftpd配置文件
```shell
sudo chmod a+w /etc/vsftpd.conf
```
将如下配置添加到 /etc/vsftpd.conf 配置文件最下方
```txt
# 限制用户对主目录以外目录访问
chroot_local_user=YES

# 指定一个 userlist 存放允许访问 ftp 的用户列表
userlist_deny=NO
userlist_enable=YES

# 记录允许访问 ftp 用户列表
userlist_file=/etc/vsftpd.user_list

# 不配置可能导致莫名的530问题
seccomp_sandbox=NO

# 允许文件上传
write_enable=YES

# 使用utf8编码
utf8_filesystem=YES
```
新建文件/etc/vsftpd.user_list
```shell
sudo touch /etc/vsftpd.user_list
sudo chmod a+w /etc/vsftpd.user_list
```
添加用户在user_list中，如`uftp`

### 设置访问权限
设置主目录访问权限(只读):
```shell
sudo chmod a-w /home/uftp
```
新建公共目录，并设置权限（读写）：
```shell
sudo mkdir /home/uftp/public && sudo chmod 777 -R /home/uftp/public
```
重启vsftpd 服务：
```shell
sudo systemctl restart vsftpd.service
```
至此ftp服务器搭建完毕