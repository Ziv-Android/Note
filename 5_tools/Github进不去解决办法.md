## 梯子（emmm，你懂的...）
## 修改hosts
1. 访问一下两个网址，获取两个IP地址：
https://websites.ipaddress.com/github.com
https://websites.ipaddress.com/github.global.ssl.fastly.net
2. 打开本地hosts文件
Windows：C:\Windows\System32\drivers\etc
Mac/Ubuntu：/etc/hosts
3. 添加内容
```
140.82.114.3 github.com
199.232.69.194 github.global.ssl.fastly.net
```
4. 重启（解决85%以上的问题）
