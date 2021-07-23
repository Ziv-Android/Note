---
title: Create The Blog For Free
---
# 使用Node.js + Hexo + GitHub搭建个人免费Blog

## Node.js

首先[官网](https://nodejs.org/zh-cn/)安装Node.js这是一切的根本，我们要使用npm命令安装Hexo以及需要依赖的插件。

## Hexo
同样访问[官网](https://hexo.io/zh-cn/)获取最新的Hexo框架
执行命令
``` bash
$ npm install hexo-cli -g
$ hexo init blog
$ cd blog
$ npm install
$ hexo server
```
恭喜你已经可以可通过 http://localhost:4000/ 查看本地静态Blog

## GitHub相关
注册帐号
创建代码仓库 **用户名**.github.io 注意一定要使用用户名创建
开启GitHub Pages功能

## 安装插件
`npm install hexo-deployer-git --save`

## 配置插件
在``_config.yml``中查找到"deploy"添加如下配置信息
``` _config
# You can use this:
deploy:
  type: git
  repo: <repository url>
  branch: [branch]
  message: [message]
  name: [git user]
  email: [git email]
  extend_dirs: [extend directory]
  ignore_hidden: false # default is true

# or this:
deploy:
  type: git
  message: [message]
  repo:
    github: <repository url>,[branch]
    coding: <repository url>,[branch]
  extend_dirs:
    - [extend directory]
    - [another extend directory]
  ignore_hidden:
    public: false
    [extend directory]: true
    [another extend directory]: false
```
一般只写type，repo和branch信息即可，message使用默认日期信息

## Blog更新
只需在Bash下执行以下命令即可，插件会帮助我们同步到我们对应的Git下
``` bash
$ hexo g #hexo generate
$ hexo d #hexo deploy
```

## 主题替换
下载喜欢的主题保存在Hexo目录下的themes文件夹下，修改``_config.yml``文件中的"theme"为你下载的文件目录名，执行
``` bash
$ hexo clean
$ hexo g
$ hexo d
```
注意：主题的替换有可能会导致需要安装新的hexo插件，详情可以参考对应主题的README信息安装即可，[官方主题地址](https://hexo.io/themes/)

## 域名的注册
由于我只是个人笔记的整理记录与分享，并未考虑注册域名，所以之后的步骤本人并未尝试，想玩的玩家请参考致谢中的步骤即可，谢谢……

## 致谢
https://xuanwo.org/2015/03/26/hexo-intor/
http://www.jianshu.com/p/f4cc5866946b
http://blog.liuxianan.com/build-blog-website-by-hexo-github.html#shi-yong-hexo-xie-bo-ke