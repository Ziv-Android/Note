# 搭建Git服务器

## 什么是Git
Git是一款免费、开源的分布式版本控制系统，用于敏捷高效的进行项目管理。
以CentOS 7.2 x64为例，一步步搭建git服务器

## 安装依赖库和编译工具
依赖库
```shell
yum install curl-devel expat-devel gettext-devel openssl-devel zlib-devel
```
编译工具
```shell
yum install gcc perl-ExtUtils-MakeMaker
```

## 下载git
官网查看一个新版稳定的源码包下载 <https://www.kernel.org/pub/software/scm/git/>
```shell
cd /usr/local/src
wget https://www.kernel.org/pub/software/scm/git/git-2.14.1.tar.gz
```

## 解压编译和安装
解压
```shell
tar -zvxf git-2.14.1.tar.gz
```
编译
```shell
cd git-2.14.1
make all prefix=/usr/local/git
```
安装到 /usr/local/git 目录下
```shell
make install prefix=/usr/local/git
```

## 配置PATH环境变量
将git安装目录配置在PATH环境变量中
```shell
echo 'export PATH=$PATH:/usr/local/git/bin' >> /etc/bashrc
source /etc/bashrc
```
测试是否配置成功
```shell
git --version
```

至此git服务器的搭建已经完成，接下来创建一个git账号测试一下

## 测试git
### 创建git账号密码
```shell
useradd -m username
passwd username
```
> 密码长度8位，不能为简单的数字

### 初始化git仓库
```shell
mkdir -p /data/repositories
cd /data/repositories/
git init --bare test.git
```

### 配置用户权限
设置git仓库用户和用户组并设置权限
```shell
chown -R username:username /data/repositories
chmod 755 /data/repositories
```
编辑/ect/passwd文件，将username的登陆shell配置修改为git-shell目录
```shell
vim /etc/passwd
username:x:500:500::/home/username:/usr/local/git/bin/git-shell
```
> 出于安全目的，限制 git 账号的 ssh 连接只能是登录 git-shell
> 使用 which git-shell 命令查看本机 git-shell 路径

### 使用git clone服务
```shell
cd ~
git clone username@<服务器IP>:/data/repositories/test.git
···
```