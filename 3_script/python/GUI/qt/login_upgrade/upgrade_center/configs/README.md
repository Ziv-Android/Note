# 配置说明
配置路径：configs -> customer.ini
配置模板：
```text
# 基本配置
[url]
pdns = 

[account]
username = 
password = 
access_key_id = 
access_key_secret = 

[path]
login = 
info = 
upgrade = 

[params]
user_info = 
device_info = 

[switch]
use_local = 0
use_access = 0
```

字段说明：

字段 | 含义 | 说明
--- | --- | ---
`[url]` | 地址关键字 | 不可变
`pdns` | 服务地址 | 必选，通过该地址将sn转换为对应的映射地址
`[account]` | 用户信息关键字 | 不可变
`username` | 用户名 | 可选，配置后自动填入
`password` | 密码 | 可选，配置后自动填入
`access_key_id` | 授权ID | 可选，use_access=1时，配置后自动填入
`access_key_secret` | 授权密钥 | 可选，use_access=1时，配置后自动填入
`[path]` | 相机请求地址 | 不可变
`login` | 相机登录路径 | 必选，注:login.php与request.php涉及不同的加密密钥和请求参数
`info` | 获取设备信息路径 | 必选，注:systemjson.php与request.php涉及不同的请求参数
`upgrade` | 升级路径 | 必选，注:upload.cgi与update.php具体需要通过抓包确认
`[params]` | 相机请求参数关键字 | 不可变
`user_info` | 登录请求参数 | 必选，抓包确认
`device_info` | 获取版本等信息请求参数 | 必选，抓包确认
`[switch]` | 控制开关关键字 | 不可变
`use_access` | 是否使用accessKey | 必选，0=关闭，1=开启；开启后界面显示access_key_id和access_key_secret输入框，且参考连接文档获取accessKeyId和accessKeySecret <br/> http://open.vzicloud.com/doc/
`use_local` | 新增保留，暂未启用 | 