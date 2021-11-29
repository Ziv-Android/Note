天气数据：https://tianqiapi.com/user/index QQ邮箱，姓名  
文档地址：https://tianqiapi.com/index/doc?version=day

请求示例  
https://tianqiapi.com/free/day?appid=23035354&appsecret=8YvlPNrz&unescape=1&city=%E5%8C%97%E4%BA%AC   
https://tianqiapi.com/api?unescape=1&version=v6&appid=63222614&appsecret=ibfDl6WX&city=%E5%8C%97%E4%BA%AC   
请求参数说明
参数名 | 必选 | 类型 | 说明 | 备注（示例）
--- | --- | --- | --- | ---
appid | 是 | string | 用户appid | 注册开发账号
appsecret | 是 | string | 用户appsecret | 
cityid | 否 | string | 城市ID | 请参考 城市ID列表
city | 否 | string | 城市名称 | 不要带市和区, 支持市区县, 不支持乡镇级别; 如: 青岛、铁西
ip | 否 | string | IP地址 | 查询IP所在城市天气
callback | 否 | string | jsonp参数 | 如: jQuery.Callbacks
vue | 否 | string | 跨域参数 | 如果您使用的是react、vue、angular请填写值: 1
unescape | 否 | Int | 是否转义中文 | 如果您希望json不被unicode, 直接输出中文, 请传此参数: 1

备注  
cityid、city和ip参数3选一提交，如果不传，默认返回当前ip城市天气，cityid优先级最高。  

响应参数说明
参数名 | 类型 | 说明 | 备注
--- | --- | --- | ---
cityid | String | 城市ID 
city | String | 城市名称 
update_time | String | 更新时间 
wea | String | 天气情况 
wea_img | String | 天气对应图标 | 固定9种类型(您也可以根据wea字段自己处理): xue、lei、shachen、wu、bingbao、yun、yu、yin、qing
tem | String | 实时温度 
tem_day | String | 白天温度(高温) 
tem_night | String | 白天温度(低温) 
win | String | 风向 
win_speed | String | 风力等级 
win_meter | String | 风速 
air | String | 空气质量