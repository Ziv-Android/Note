1 # H bus模块协议
1.1 ## 授权时间
1.1.1	### 1.获取设备激活状态
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_device_active_status",
}
```
- Response
```
{
	"type": "get_device_active_status",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "active_status": 0,
        "active_time": 0,
        "signature": "ux6pZ3qhrnpn5FmF"
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
active_status | 激活状态 | int | 是 | 0:不启用授权<br> 1:启用授权
active_time | 剩余时间(s) | int | 是 | 
signature | 签名 | string | 是 | 
1.1.2	### 2.设置设备激活状态
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_device_active_status",
    "body": {
        "authentication": "0t7gdigbqp0ESU5yRp+87wddanY=",
        "active_status": 1,
        "active_time": 86375
    }
}
```
- Response
```
{
	"type": "set_device_active_status",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
active_status | 激活状态 | int | 是 | 0:不启用授权<br> 1:启用授权
active_time | 剩余时间(s) | int | 是 | 
authentication | 认证 | string | 是 | 
1.1.3	### 3.获取设备授权状态
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_dev_undelegated",
}
```
- Response
```
{
	"type": "get_dev_undelegated",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "active_status": 0
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
active_status | 激活状态 | int | 是 | 
1.1.4	### 4.设置设备授权状态号
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_dev_undelegated",
    "body": {
        "active_status": 1
    }
}
```
- Response
```
{
	"type": "set_dev_undelegated",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
active_status | 激活状态 | int | 是 | 
1.2 ## 证据链数据
1.2.1	### 1.获取证据链数据
- Request
```
{
    "module":"BUS_EVIDENCE_CHAIN_REQUEST",
    "type":"get_evidence_chain_info"
}
```
- Response
```
{
	"type": "get_evidence_chain_info",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "evidence":[
	        {
	            "zone_id": 0,
	            "enable": 1,
	            "chain": [
	                {
	                    "parking_state": 1,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 2,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                }
	            ]
	        },{
	            "zone_id": 1,
	            "enable": 0,
	            "chain":[]
	        },{
	            "zone_id": 2,
	            "enable": 1,
	            "chain":[
	                {
	                    "parking_state": 1,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 2,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 4,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 8,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                }
	            ]
	        },{
	            "zone_id": 3,
	            "enable": 1,
	            "chain":[]
	        }
	    ]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
zone_id | 车位ID | int[0, 1000] | 是 | 
enable | 车位开关使能 | int[0, 1] | 是 | 
chain | 证据链对象 | array | 否 | 可能为空数组
parking_state | 车位状态 | int | 是 | 证据链状态
time_s | 时间 | string | 是 | 字符串时间
plate_str | 车牌号 | string(0,32] | 是 | UTF8后再BASE64编码
plate_color | 车牌颜色 | int | 是 | 0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
image_path | 图片缓存的路径名 
 | string(0,128] | 是 | UTF8后再BASE64编码)
plateimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
carimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
loc | 车牌/车位置信息 | object | 是 |
left | 车牌/车位置left坐标 | int | 是 |
right | 车牌/车位置right坐标 | int | 是 |
top | 车牌/车位置top坐标 | int | 是 |
bottom | 车牌/车位置bottom坐标 | int | 是 |
1.2.2	### 2.广播证据链更新
- broadcast
```
{
	"module": "EVIDENCE_CHAIN_BROADCAST",
	"type": "broadcast_evidence_chain_info",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "zone_id": 0,
        "enable": 1,
        "chain":[
            {
                "parking_state": 1,
                "time_s": "2020-10-10 00:22:34",
                "plate_str": "X1/ml6BfXw==",
                "plate_color": 0,
                "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
								"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "loc": {
                    "left": 100,
                    "right": 100,
                    "top": 200,
                    "bottom": 200
                }
            },{
                "parking_state": 2,
                "time_s": "2020-10-10 00:22:34",
                "plate_str": "X1/ml6BfXw==",
                "plate_color": 0,
                "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
								"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "loc": {
                    "left": 100,
                    "right": 100,
                    "top": 200,
                    "bottom": 200
                }
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
zone_id | 车位ID | int[0, 1000] | 是 | 
parking_state | 车位状态 | int | 是 | 证据链状态
enable | 车位开关使能 | int[0, 1] | 是 | 
time_s | 时间 | string | 是 | 字符串时间
plate_str | 车牌号 | string(0,32] | 是 | UTF8后再BASE64编码
plate_color | 车牌颜色 | int | 是 | 0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
image_path | 图片缓存的路径名 
 | string(0,128] | 是 | UTF8后再BASE64编码)
plateimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
carimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
loc | 车牌/车位置信息 | object | 是 |
left | 车牌/车位置left坐标 | int | 是 |
right | 车牌/车位置right坐标 | int | 是 |
top | 车牌/车位置top坐标 | int | 是 |
bottom | 车牌/车位置bottom坐标 | int | 是 |
1.3 ## 补光灯控制协议
1.3.1	### 1.获取状态灯参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_led_prop"
}
```
- Response
```
{
    "module": "BUS_REQUEST_MSG",
    "type": "get_led_prop",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "led_level": {
            "default": 0,
            "max": 0,
            "min": -1,
            "types": [
                {
                    "content": "5YWz6Zet",
                    "type": -1
                },
                {
                    "content": "Muexsw==",
                    "type": 0
                }
            ]
        },
        "led_mode": [
            {
                "content": "5pm66IO9",
                "type": 0
            },
            {
                "content": "5bi45Lqu",
                "type": 1
            },
            {
                "content": "5bi454Gt",
                "type": 2
            },
            {
                "content": "5pe26Ze05q61",
                "type": 3
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
content | 当前类型描述 | string | 是 | utf8 + base64编码
1.3.2	### 2.获取补光灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_led_prm"
}
```
- Response
```
{
    "module": "BUS_REQUEST_MSG",
    "type": "get_led_prm",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "time_ctrl": [
                    {
                        "time_begin": "00:00:00",
                        "time_end": "06:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 0
                    },
                    {
                        "time_begin": "06:00:00",
                        "time_end": "19:30:00",
                        "timectrl_enable": false,
                        "led_level": -1,
                        "id": 1
                    },
                    {
                        "time_begin": "19:30:00",
                        "time_end": "24:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 2
                    }
                ],
                "led_mode": 0,
                "led_sensitivity": 4
            }
        ]
    }
}
```
- 参数释

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
led_level | 亮度 | int | 是 | H1M亮度统一相同值
led_mode | 模式 | int | 是 | 0：智能补光<br>1：常开补光<br>2：关闭补光<br>3：手动补光
led_sensitivity | 补光灯灵敏度 | int[0-7] | 是 | 默认4，值越高灵敏度越高
1.3.3	### 3.设置补光灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_led_prm",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "time_ctrl": [
                    {
                        "time_begin": "00:00:00",
                        "time_end": "06:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 0
                    },
                    {
                        "time_begin": "06:00:00",
                        "time_end": "19:30:00",
                        "timectrl_enable": false,
                        "led_level": -1,
                        "id": 1
                    },
                    {
                        "time_begin": "19:30:00",
                        "time_end": "24:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 2
                    }
                ],
                "led_mode": 0,
                "led_sensitivity": 4
            }
        ]
    }
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_led_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
led_level | 亮度 | int | 是 | H1M亮度统一相同值
led_mode | 模式 | int | 是 | 0：智能补光<br>1：常开补光<br>2：关闭补光<br>3：手动补光
led_sensitivity | 补光灯灵敏度 | int[0-7] | 是 | 默认4，值越高灵敏度越高
1.4 ## 流控协议
1.4.1	### 1.流控识别结果
- broadcast
```
{
    "module": "IVS_RESULT_NOTIFY_FLOWCTRL",
    "type": "recognition_result",
    "body": {
        "push_type": 6,
        "push_mode": 0,
		"trigger_type": 5,
        "result": [
            {
                "alarm_info": {...},
                "bg_img": [...],
                "feture_img": [...],
                "product_h": {...},
                "times_s": ...,
                "trigger_type": ...,
                "reco_id": ...,
                "serial": ...
            },
            {
                "alarm_info": {...},
                "bg_img": [...],
                "feture_img": [...],
                "product_h": {...},
                "times_s": ...,
                "trigger_type": ...,
                "reco_id": ...,
                "serial": ...
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
push_type | 推送对象 | int | 是 | 或<br> 1:客户定制<br> 2：HTTP推送<br> 4:STP推送中台
push_mode | 推送模式 | int | 是 | 0：单张推送<br> 1：组合推送
result | 算法结果 | array | 是 | 
1.4.2	### 2.订单查询
- Request
```
{
    "module":"BUS_FLOWCTRL_MESSAGE",
    "type":"search_group_result",
    "body": {
        "push_type": 2,
        "group_id": 1234
    }
}
```
- Response
```
{
	"type": "search_group_result",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
push_type | 推送对象 | int | 是 | 1:客户定制<br> 2：HTTP推送<br> 4:STP推送中台
group_id | 订单id | int | 是 | 
1.4.3	### 3.注册协议
- Request
```
{
    "module":"BUS_FLOWCTRL_MESSAGE",
    "type":"register_push_type",
    "body": {
        "push_type": 2,
        "register_flag": 1,
        "push_mode": 1
    }
}
```
- Response
```
{
	"type": "register_push_type",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
push_type | 推送对象 | int | 是 | 1:客户定制<br> 2：HTTP推送<br> 4:STP推送中台
register_flag | 注册注销 | int | 是 | 0:注销<br> 1：注册
push_mode | 推送模式 | int | 是 | 0：单张推送<br> 1：组合推送
1.4.4	### 4.推送响应
- Request
```
{
    "module":"BUS_FLOWCTRL_MESSAGE",
    "type":"update_push_status",
    "body": {
        "push_type": 2,
        "push_status": 1,
        "reco_id": 12345
    }
}
```
- Response
```
{
	"type": "update_push_status",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
push_type | 推送对象 | int | 是 | 1:客户定制<br> 2：HTTP推送<br> 4:STP推送中台
push_status | 推送状态 | int | 是 | 0:推送失败<br> 1：推送成功
reco_id | 识别结果id | int | 是 | 
1.4.5	### 5.订单锁定解锁
- Request
```
{
    "module":"DP_ALG_MESSAGE",
    "type":"lock_image_shm",
    "body": {
        "reco_id": 12345,
        "lock_flag": 1
    }
}
```
- Response
```
{
	"type": "lock_image_shm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
reco_id | 识别结果id | int | 是 | 
lock_flag | 锁定标志 | int | 是 | 0:解锁<br> 1：锁定
1.5 ## FTP推送
1.5.1	### 1.获取FTP配置
- Request
```
{
    "module":"BUS_HTTP_REQUEST",
    "type":"get_ftp_cfg"
}
```
- Response
```
{
	"type": "get_ftp_cfg",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "enable": 0,
        "enable_resume": 0,
        "folder": {
            "archive": 0,
            "detail_level": 0,
            "folder_level": 0,
            "folder_one": {
                "folder_name": "",
                "folder_type": 0
            },
            "folder_two": {
                "folder_name": "",
                "folder_type": 0
            },
            "img_prefix": "",
            "update_time": 1593429386
        },
        "password": "admin",
        "port": 21,
        "server_ip": "192.168.1.106",
        "username": "YWRtaW4="
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0:关闭<br>1:开启<br>
enable_resume | enable_resume | int | 是 | 
folder | folder | object | 是 | 
archive | archive | int | 是 | 
detail_level | detail_level | int | 是 | 
folder_level | folder_level | int | 是 | 
folder_one | folder_one | object | 是 | 
folder_name | folder_name | string | 是 | 
folder_type | folder_type | int | 是 | 
folder_two | folder_two | object | 是 | 
img_prefix | 图片名前缀 | string | 是 | 传参需要经过base64加密
update_time | update_time | int | 是 | 
password | 密码 | string | 是 | 
port | 端口号 | short | 是 | 
server_ip | 服务ip | string | 是 | 
username | 用户名 | string | 是 | base64
1.5.2	### 2.设置FTP配置
- Request
```
{
    "module": "BUS_HTTP_REQUEST",
    "type": "set_ftp_cfg",
    "body": {
        "enable": 1,
        "server_ip": "192.168.1.106",
        "port": 21,
        "username": "YWRtaW4: ",
        "password": "admin",
        "folder": {
            "img_prefix": "MTE=",
            "archive": 1,
            "folder_level": 1,
            "folder_one": {
                "folder_type": 1,
                "folder_name": ""
            },
            "folder_two": {
                "folder_type": 0,
                "folder_name": ""
            },
            "detail_level": 3
        }
    }
}
```
- Response
```
{
	"type": "set_ftp_cfg",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0:关闭<br>1:开启<br>
enable_resume | enable_resume | int | 是 | 
folder | folder | object | 是 | 
archive | archive | int | 是 | 
detail_level | detail_level | int | 是 | 
folder_level | folder_level | int | 是 | 
folder_one | folder_one | object | 是 | 
folder_name | folder_name | string | 是 | 
folder_type | folder_type | int | 是 | 
folder_two | folder_two | object | 是 | 
img_prefix | img_prefix | string | 是 | 
update_time | update_time | int | 是 | 
password | 密码 | string | 是 | 
port | 端口号 | ushort | 是 | 
server_ip | 服务ip | string | 是 | 
username | 用户名 | string | 是 | base64
1.5.3	### 3.FTP发送测试
- Request
```
{
    "module": "BUS_HTTP_REQUEST",
    "type": "send_ftp_test_file",
}
```
- Response
```
{
	"type": "send_ftp_test_file",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
1.6 ## 推送配置协议
1.6.1	###获取HTTP基础配置
- Request
```
{    
"module": "BUS_HTTP_REQUEST",
"type": "get_base_cfg"
 }
```
- Response
```
{
  "body": {
    "delay_time": 5,
    "mserver_status": 0,
    "offline_check": 0,
    "resend_times": 3,
    "server_ip": "192.168.1.106",
    "server_ip_ext": [
      "192.168.1.15"
    ],
    "server_port": 8080,
    "ssl_para": {
      "ca_enable": 1,
      "ssl_enable": 1,
      "ssl_port": 443
    },
    "timeout": 5,
    "type": "get_base_cfg"
  },
  "err_msg": "All Done",
  "state": 200,
  "type": "get_base_cfg"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mserver_status | 主服务器优先 | Object | 是 | 
server_ip | 服务器地址 | string | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
server_port | 端口 | int| 是 | 
timeout | 超时时间 | int | 是 |心跳时间
delay_time | 推送间隔 | int | 是 | 
server_ip_ext | 备选服务器 | list| 是 | 传列表，如：['192.168.1.15']
ca_enable | CA证书| int | 是 | 0：匿名<br> 1：CA证书<br>
ssl_enable | SSL连接| int | 是 | 0：关闭<br> 1：开启<br>
ssl_port | SSL端口 | int | 是 | 
offline_check | HTTP脱机检查 | int | 是 | 0：关闭<br> 1：开启<br>
resend_times | 重发次数 | int | 是 |
1.6.2	###设置HTTP基础配置
- Request
```
{
  "type": "set_base_cfg",
  "module": "BUS_HTTP_REQUEST",
  "body": {
    "mserver_status": 0,
    "server_ip": "192.168.1.106",
    "server_port": 8080,
    "timeout": 5,
    "delay_time": 5,
    "server_ip_ext": [],
    "ssl_para": {
      "ssl_enable": 0,
      "ssl_port": 443,
      "ca_enable": 0
    },
    "offline_check": 0,
    "resend_times": 3
  }
}
```
- Response
```
{
	"body": {
		"type": "set_base_cfg"
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "set_base_cfg"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mserver_status | 主服务器优先 | Object | 是 | 
server_ip | 服务器地址 | string | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
server_port | 端口 | int| 是 | 
timeout | 超时时间 | int | 是 |心跳时间
delay_time | 推送间隔 | int | 是 | 
server_ip_ext | 备选服务器 | list| 是 | 传列表，如：['192.168.1.15']
ca_enable | CA证书| int | 是 | 0：匿名<br> 1：CA证书<br>
ssl_enable | SSL连接| int | 是 | 0：关闭<br> 1：开启<br>
ssl_port | SSL端口 | int | 是 | 
offline_check | HTTP脱机检查 | int | 是 | 0：关闭<br> 1：开启<br>
resend_times | 重发次数 | int | 是 | 

1.6.3	### 1.获取HTTP推送配置
- Request
```
{
    "module":"BUS_HTTP_REQUEST",
    "type":"get_push_cfg"
}
```
- Response
```
{
	"type": "get_push_cfg",
	"state": 200,
	"err_msg": "All Done",
    "body": {
        "dev_reg": {
            "heart_mode": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA: =",
            "time": 20
        },
        "ivs_rlt": {
            "enable": 1,
            "url": "L3Z6L2l2cy5qc3A=",
            "detail_level": 0,
            "big_img": 1,
            "small_img": 1,
            "mode": 0,
            "car_img": 0
        },
        "mqtt_rlt": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL21xdHRyZXN1bHRpbmZvLnBocA=="
        },
        "retran": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JldHJhbi5waHA="
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
dev_reg | 设备注册 | Object | 是 | 
heart_mode | 心跳模式 | int | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
url | 推送地址 | string | 是 | utf8的base64字符串
time |心跳时间| int | 是 |
ivs_rlt | 推送识别结果 | Object | 是 | 
enable | 使能开关 | int | 是 | 0：关闭<br> 1：开启<br>
big_img | 全景图 | int | 是 | 0：推送<br> 1：不推送<br>
small_img | 车牌特写图 | int | 是 | 0：推送<br> 1：不推送<br>
car_img | 车辆特写图 | int | 是 | 0：推送<br> 1：不推送<br>
mode | 推送模式 | int | 是 | 0：识别结果推送<br> 1：事件推送<br>
mqtt_rlt | mqtt结果推送 | Object | 是 |
retran | 数据重传结果 | Object | 是 |
1.6.4	### 2.设置HTTP推送配置
- Request
```
{
    "module":"BUS_HTTP_REQUEST",
    "type":"set_push_cfg",
    "body": {
        "dev_reg": {
            "heart_mode": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA: =",
            "time": 20
        },
        "ivs_rlt": {
            "enable": 1,
            "url": "L3Z6L2l2cy5qc3A=",
            "detail_level": 0,
            "big_img": 1,
            "small_img": 1,
            "mode": 0,
            "car_img": 0
        },
        "mqtt_rlt": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL21xdHRyZXN1bHRpbmZvLnBocA=="
        },
        "retran": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JldHJhbi5waHA="
        }
    }
}
```
- Response
```
{
	"type": "set_push_cfg",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
dev_reg | 设备注册 | Object | 是 | 
heart_mode | 心跳模式 | int | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
url | 推送地址 | string | 是 | utf8的base64字符串
time | 推送地址 | int | 是 |心跳时间
ivs_rlt | 推送识别结果 | Object | 是 | 
enable | 使能开关 | int | 是 | 0：关闭<br> 1：开启<br>
big_img | 全景图 | int | 是 | 0：推送<br> 1：不推送<br>
small_img | 车牌特写图 | int | 是 | 0：推送<br> 1：不推送<br>
car_img | 车辆特写图 | int | 是 | 0：推送<br> 1：不推送<br>
mode | 推送模式 | int | 是 | 0：识别结果推送<br> 1：事件推送<br>
mqtt_rlt | mqtt结果推送 | Object | 是 | 
retran | 数据重传结果 | Object | 是 |
1.6.5	### 3.获取MQTT连接状态
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"get_mqtt_connect_status"
}
```
- Response
```
{
	"type": "get_mqtt_connect_status",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "status": 0
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
status | 连接状态 | int | 是 | 0：未连接<br> 1：正在连接<br>2：已连接<br>3：连接失败<br>
1.6.6	### 4.获取接入MQTT配置
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"get_mqtt_cfg"
}
```
- Response
```
{
	"type": "get_mqtt_cfg",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "enable": 0,
	    "host": "122.112.244.245",
	    "port": 1883,
	    "client_id": "bf562e01-514d7b39",
      "username": "server",
      "password": "Vzenith5449",
      "keep_alive": 60,
      "subscription": [
            {
                "topic": "device/bf562e01-514d7b39/message/down/+"
            }
      ]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
host | 地域 | string | 是 | 服务地址
username | 用户名 | string | 否 | 
password | 密码 | string | 是 |
port | 端口号 | int(0,65535] | 否 | 默认1883
client_id | client_id | string | 是 | 
keep_alive | 心跳 | int | 是 | 
subscription | 订阅 | array | 是 | 可在高级选项进行修改
topic | 订阅topic | string | 是 | 
1.6.7	### 5.设置接入MQTT配置
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"set_mqtt_cfg",
    "body": {
	    "enable": 0,
	    "host": "122.112.244.245",
	    "port": 1883,
	    "client_id": "bf562e01-514d7b39",
      "username": "server",
      "password": "Vzenith5449",
      "keep_alive": 60,
      "subscription": [
            {
                "topic": "device/bf562e01-514d7b39/message/down/+"
            }
      ]
	}
}
```
- Response
```
{
	"type": "set_mqtt_cfg",
	"state": 200,
	"err_msg": "All Done",
	
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
host | 地域 | string | 是 | 服务地址
username | 用户名 | string | 否 | 
password | 密码 | string | 是 |
port | 端口号 | int(0,65535] | 否 | 默认1883
client_id | client_id | string | 是 | 
keep_alive | 心跳 | int | 是 | 
subscription | 订阅 | array | 是 | 
topic | 订阅topic | string | 是 | 
1.6.8	### 6.MQTT发送HTTP透传数据
- Request
```
{
    "module":"BUS_MQTT_RESPONSE",
    "type":"push_mqtt_resp",
    "body": {
	    
	}
}
```
- Response
```
{
	"type": "push_mqtt_resp",
	"state": 200,
	"err_msg": "All Done",
	
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
body | 透传数据内容 | object | 是 | 
1.7 ## 协作相机
1.7.1	### 1.获取协作相机信息
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_another_device_ip"
}
```
- Response
```
{
    "module": "SERIAL_COMM_MSG"
    "type": "get_another_device_ip",
    "body": {
        "enable_extern":1,
        "http_port":80,
        "https_en":0,
        "rtsp_port":8557,
        "tcp_port":8132,
        "ip": "192.168.114.210",
				"sn": 8db33777-f1da8164,
        "accounts": [
            {
              "admin":{
                  "authority":0,
                  "password":"admin"
            },
            {
              "test":{
                  "authority":0,
                  "password":"test"
            }
        ],
        "lens_mode": {
            "mode":0,   // 0:近端短焦;1:远端长焦
            "max_plate_num":3
        }
    },
    "state":200,
    "error_msg":"All done"
}  
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable_extern | 是否有协作相机 | int[0, 1] | 是 |  0:没有协作相机<br>1:有协作相机
ip | 协作相机IP | string | 是 | 
https_en | 协作相机是否开启https | int[0, 1] | 是 | 0:http<br>1:https
http_port | 协作相机http端口 | int[0, 65535] | 是 | 
rtsp_port | 协作相机rtsp端口 | int[0, 65535] | 是 | 
tcp_port | 协作相机tcp端口 | int[0, 65535] | 是 | 
sn | 协作相机sn | string | 是 | 
accounts | 协作相机账号信息 | object | 是 | 
lens_mode | 协作相机镜头模式 | object | 是 | 
mode | 协作相机镜头模式 | int[0, 1] | 是 | 0:近端短焦<br>1:远端长焦
max_plate_num | 协作相机最大支持车位数 | int | 是 | 近端短焦:3<br>远端长焦:5
1.7.2	### 2.获取本机长短焦配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_lens_mode"
}
```
- Response
```
{
	"type": "get_lens_mode",
	"state":200,
	"err_msg":"All Done",
	"body": {
        "mode":0,
        "max_plate_num":3,
        "is_double":0
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 长短焦 | int | 是 | 0：近端短焦<br>1：远端长焦<br>2：超广角
max_plate_num | 数量 | int | 是 | 3：近端短焦默认数量<br>5：远端长焦默认数量
is_double | 是否是双目相机 | int | 是 | 0：单目<br>1：双目
1.7.3	### 3.设置本机长短焦配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "set_lens_mode",
    "body": {
        "mode":0,
        "max_plate_num":3,
        "is_double":0
	}
}
```
- Response
```
{
	"type": "set_lens_mode",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 长短焦 | int | 是 | 0：近端短焦<br>1：远端长焦<br>2：超广角
max_plate_num | 数量 | int | 是 | 3：近端短焦默认数量<br>5：远端长焦默认数量
is_double | 是否是双目相机 | int | 是 | 0：单目<br>1：双目
### 4.获取对端上云映射IP端口号
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_another_device_pdns",
    "body": {
        "port":80
	  }
}
```
- Response
```
{
	"type": "get_another_device_pdns",
	"state":200,
	"err_msg":"All Done",
	"body" : {
      "host" : "119.3.44.91",
      "port" : 10760
   }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
host | 映射ip | int | 是 | 
port | 映射端口 | int | 是 | 
1.8 ## 定时抓拍
1.8.1	### 获取定时抓拍属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_timer_snap_prop"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_timer_snap_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "times":[
            {
                "type":0,
                "content":"5LiN5ZCv55So"
            },{
                "type":1,
                "content":"5LiA5YiG6ZKf"
            },{
                "type":3,
                "content":"5LiJ5YiG6ZKf"
            },{
                "type":5,
                "content":"5LqU5YiG6ZKf"
            },{
                "type":10,
                "content":"5Y2B5YiG6ZKf"
            }
	    ],
	    "pushs":[
	        {
	            "type":1,
	            "content":"SFRUUA=="
	        },
	        {
	            "type":2,
	            "content":"5Lit6Ze05Lu2"
	        },
	        {
	            "type":4,
	            "content":"5a6a5Yi2"
	        }
	    ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
times | 定时时间间隔定义 | object | 是 | 
pushs | 定时抓图推送类型 | object | 是 | 
type | 当前类型 | int | 是 |
content | 当前类型描述 | string | 是 | utf8 + base64编码
1.8.2	### 获取定时抓图参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_timer_snap_prm"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_timer_snap_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
      "time": 0,
      "push": 2 
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time | 定时抓拍时间 | int | 是 | 0：关闭定时抓拍；否则是抓拍的时间间隔，单位秒
push | 定时抓图推送配置 | int | 是 | 按位标识（默认只开启中台推送）：<br>0x01:HTTP推送<br>0x02:中间件推送<br>0x04:定制协议

1.8.3	### 设置定时抓图
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_timer_snap_prm",
    "body": {
      "time": 0,
      "push": 2 
    }
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_timer_snap_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time | 定时抓拍时间 | int | 是 | 0：关闭定时抓拍；否则是抓拍的时间间隔，单位秒
push | 定时抓图推送配置 | int | 是 | 按位标识：<br>0x01:HTTP推送<br>0x02:中间件推送<br>0x04:定制协议
1.9 ## 语音播报（RF）
1.9.1	### 1.获取语音播报配置
- Request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_voice_broadcast"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_voice_broadcast",
	"body": {
		"time_ctrl": [
			{
				"time_begin": "00:00:00",
				"time_end": "06:00:00",
				"volume": 50,
				"id": 0
			}, {
				"time_begin": "06:00:00",
				"time_end": "19:30:00",
				"volume": 100,
				"id": 1
			}, {
				"time_begin": "19:30:00",
				"time_end": "24:00:00",
				"volume": 50,
				"id": 2
			}
		],
		"male":0,
		"speed":0,
		"voice": [
			{
				"id":0,
				"note":"5YWl5Zy66ZmN6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiL6ZmN77yM6K+35YGc6L2m",
				"length":40
			},{
				"id":1,
				"note":"56a75Zy65Y2H6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiK5Y2H77yM5qyi6L+O5YaN5qyh5YWJ5Li0"
				"length":52
			},{
				"id":2,
				"note":"6ZmQ5Yi26L2m54mM",
				"msg":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA"
				"length":44
			}
		]
	},
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time_ctrl | 时间段音量控制 | object | 是 |  
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
male | 声音选择 | int | 是 |  0:女声;<br>1:男声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice | 语音 | object | 是 |  
note | 语音类型 | string | 是 |  UTF8 + BASE64
msg | 语音内容 | string | 是 |  UTF8 + BASE64
1.9.2	### 2.设置语音播报配置
- Request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_voice_broadcast",
	"body": {
		"time_ctrl": [
			{
				"time_begin": "00:00:00",
				"time_end": "06:00:00",
				"volume": 50,
				"id": 0
			}, {
				"time_begin": "06:00:00",
				"time_end": "19:30:00",
				"volume": 100,
				"id": 1
			}, {
				"time_begin": "19:30:00",
				"time_end": "24:00:00",
				"volume": 50,
				"id": 2
			}
		],
		"male":0,
		"speed":100,
		"voice": [
			{
				"id":0,
				"note":"5YWl5Zy66ZmN6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiL6ZmN77yM6K+35YGc6L2m",
				"length":40
			},{
				"id":1,
				"note":"56a75Zy65Y2H6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiK5Y2H77yM5qyi6L+O5YaN5qyh5YWJ5Li0",
				"length":52
			},{
				"id":2,
				"note":"6ZmQ5Yi26L2m54mM",
				"msg":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA",
				"length":44
			}
		]
	}
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_voice_broadcast",	
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time_ctrl | 时间段音量控制 | object | 是 |  
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
male | 声音选择 | int | 是 |  0:女声;<br>1:男声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice | 语音 | object | 是 |  
note | 语音类型 | string | 是 |  UTF8 + BASE64
msg | 语音内容 | string | 是 |  UTF8 + BASE64
length | 语音内容长度 | int | 是 |  加密后的长度
1.9.3	### 3.语音试听
- Request
```
{
	"module": "PS_BUS_REQUEST",
	"type": "play_voice",
	"body": {
		"voice_speed":100,
		"voice_male":0,
		"voice_data":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA",
		"data_len":44,
		"voice_volume":100
	}
}
```
- Response
```
{
	"module": "PS_BUS_REQUEST",
	"type": "play_voice",	
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
voice_volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
voice_male | 声音选择 | int | 是 |  0:女声;<br>1:男声
voice_speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice_data | 语音内容 | string | 是 |  UTF8 + BASE64
data_len | 语音内容长度 | int | 是 |  加密后的长度
1.10 ## 参数管理
1.10.1	### 1.恢复默认
- request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "reset_default_param",
	"body": {
		"key": "dev_name"
	}
}
```
- response
```
{
    "type":"reset_default_param",
    "err_msg":"All done",
    "state":200
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
key | 需要恢复默认的关键字 | string | 是 |  road_rule：车位设置<br>dev_name：设备名<br>road_reco：识别设置<br>timer_snap：定时抓图<br>road_snap：截图配置<br>pic_merge：图片合成<br>park_no：停车场编号<br>park_mode：车位模式

1.10.2	### 2.获取配置同步属性
- request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_synchronize_param_prop"
}
```
- response
```
{
	"body": {
		"params": [
		    {
		        "id": 0,
		        "param": "platform_param",
		        "notes": "5bmz5Y+w6K6+572u",
		        "select": true
		    },{
		        "id": 1,
		        "param": "picture_param",
		        "notes": "5Zu+54mH6YWN572u",
		        "select": true
		    },{
		        "id": 2,
		        "param": "reco_param",
		        "notes": "6K+G5Yir6YWN572u",
		        "select": true
		    },{
		        "id": 3,
		        "param": "time_param",
		        "notes": "5pe26Ze05Y+C5pWw",
		        "select": true
		    },{
		        "id": 4,
		        "param": "http_param",
		        "notes": "SFRUUOaOqOmAgQ==",
		        "select": true
		    },{
		        "id": 5,
		        "param": "ftp_param",
		        "notes": "RlRQ",
		        "select": true
		    },{
		        "id": 6,
		        "param": "stp_param",
		        "notes": "5LiK5LqR",
		        "select": true
		    }
		]
	},
    "err_msg":"All done",
    "state":200,
    "type":"get_synchronize_param_prop"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
params | 需要同步的参数 | array | 是 | 
id | id | int | 是 | 
param | 参数 | string | 是 | 
notes | 描述 | string | 是 | utf8 + base64
select | 是否默认选中 | bool | 否 | 

1.10.3	### 3.配置同步
- request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_synchronize_param",
	"body": {
		"params": ["platform_param", "picture_param"]
	}
}
```
- response
```
{
    "err_msg":"All done",
    "state":200,
    "type":"set_synchronize_param"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
params | 需要同步的参数 | string-array | 是 | 
1.11 ## 定制协议管理
1.11.1	### 1.获取定制版本列表
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_platform_prop",
    "body" : {
      "custom_list": [
          {
            "platform_name": "",
            "lib_name": ""
          },
          {
            "platform_name": "lifang",
            "lib_name": "libcustom_lifang.so"
          },
          {
            "platform_name": "songli",
            "lib_name": "libcustom_songli.so"
          }
      ]
    }
}
```
- Response
```
{
	"type": "get_platform_prop",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
custom_list | 平台列表 | array | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 
1.11.2	### 2.获取当前定制协议
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_platform"
}
```
- Response
```
{
	"type": "get_platform_prop",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
        "platform_name": "songli",
        "lib_name": "libcustom_songli.so"
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 
1.11.3	### 3.设置定制协议
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_platform",
	"body" : {
        "platform_name": "songli",
        "lib_name": "libcustom_songli.so"
    }
}
```
- Response
```
{
	"type": "set_platform",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 
1.12 ## 云台控制
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_cloud_ctrl",
	"body" : {
        "cmd": 8,
        "value": -1
    }
}
```
- Response
```
{
	"type": "set_cloud_ctrl",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cmd | 方向 | int | 是 | 0：设置超时时间<br> 1：保持继续移动<br> 2：向上移动<br> 4：向下移动<br> 8：停止上下移动<br> 16：向左移动<br> 32：向右移动<br> 64：停止左右移动<br> cmd为1时需要指定保持的方向，比如保持向上移动时cmd填3，保持向下移动时cmd填5......
value | 值 | int | 否 | 当cmd是0(设置超时时间)时，此字段表示超时时间，单位毫秒；
其他情况时，可以不传或者填-1
1.13 ## 调焦
1.13.1	### 1.调焦和镜头复位
- request
```
{
    "type":"avs_focus",
    "module":"AVS_REQUEST_MESSAGE",
    "body":{
        "option":0,
        "motor":0,
        "runmode":1,
        "value":1
    }
}
```
- response
```
{
    "err_msg":"All done",
    "state":200,
    "type":"avs_focus"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
option | 操作类型 | int | 是 | 0:复位<br>1:设置超时时间<br>2:开始运行对焦<br>3:保持对焦<br>4:停止对焦<br>5:执行一次自动对焦
motor | 动作电机 | int | 是 | 0:对焦电机<br>1:变焦电机
runmode | 运行模式 | int | 是 | 1:正向自由运行<br>2:反向自由运行
value | 参数值 | int | 是 | 当option=1时,此字段表示超时时间，单位毫秒(ms)<br>当option=2时,此字段表示步长<br>当option=4且motor=1时,此字段表示变倍后是否自动聚焦（1:自动聚焦;0:不自动聚焦）<br>当option=0时,此字段表示超时时间，单位秒(s)
1.13.2	### 2.获取镜头复位状态
- request
```
{
    "type":"get_focus_resert_status",
    "module":"AVS_REQUEST_MESSAGE"
}
```
- response
```
{
    "err_msg":"All done",
    "state":200,
    "type":"get_focus_resert_status",
		"body":{
        "status":1
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
status | 复位状态 | int | 是 | 1:未复位<br>2:已复位<br>3:正在复位<br>4:复位失败<br>
1.14 ## 录像配置
1.14.1	### 1.获取录像配置参数
- Request
```
{
    "module":"BUS_RECORD_VIDEO_REQUEST",
    "type":"get_bus_record_prm"
}
```
- Response
```
{
	"module": "BUS_RECORD_VIDEO_REQUEST",
	"type": "get_bus_record_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"storage_mode": 0,
		"camera_storage_param": {
			"videotape_mode": 2,
			"stream_channel": 1,
			"record_param": {
				"time": [
					{
						"count": 1,
						"id": 0,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 1,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 2,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 3,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 4,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 5,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 6,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					}
				]
			},
			"event_param": {
				"event_mode": 0,
				"period": 180
			}
		},
		"cloud_storage_param": {
			"videotape_mode": 2,
			"stream_channel": 1,
			"record_param": {
				"time": [
					{
						"count": 1,
						"id": 0,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 1,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 2,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 3,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 4,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 5,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 6,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					}
				]
			},
			"event_param": {
				"event_mode": 0,
				"period": 180
			}
		}
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
storage_mode | 存储类型 | int | 是 | 0x01:相机存储<br>0x02:云端存储
camera_storage_param | 相机存储参数 | object | 是
cloud_storage_param | 云端存储参数 | object | 是
videotape_mode | 录像模式 | int | 是 | 0x01:定时录像<br>0x02:事件录像
stream_channel | 录像码流 | int | 是 | 1:主码流<br>2:子码流
record_param | 定时录像参数配置 | object | 是
event_param | 事件录像参数配置 | object | 是
time | 时间配置 | array | 是
count | 时间段个数 | int | 是
id | 星期几 | int | 是 | time对象下的id<br>0:星期日<br>1:星期一<br>2:星期二<br>3:星期三<br>4:星期四<br>5:星期五<br>6:星期六
period | 时间段 | array | 是
id | 时间段id | int | 是 | period对象下的id
start_hour | 开始的小时数 | int[0,23] | 是
start_minute | 开始的分钟数 | int[0,59] | 是
end_hour | 结束的小时数 | int[0,23] | 是
end_minute | 结束的分钟数 | int[0,59] | 是
event_mode | 事件类型 | int | 是 | 0:不录象<br>1:车辆入场录,车辆出场停<br>2:检测到车辆录
period | 录像时间 | int | 否 | 单位秒(s)，只有在检测到车辆录(event_mode=2)时有效
1.14.2	### 2.设置录像配置参数
- Request
```
{
    "module":"BUS_RECORD_VIDEO_REQUEST",
    "type":"set_bus_record_prm",
	"body": {
		"storage_mode": 0,
		"camera_storage_param": {
			"videotape_mode": 2,
			"stream_channel": 1,
			"record_param": {
				"time": [
					{
						"count": 1,
						"id": 0,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 1,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 2,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 3,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 4,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 5,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 6,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					}
				]
			},
			"event_param": {
				"event_mode": 0,
				"period": 180
			}
		},
		"cloud_storage_param": {
			"videotape_mode": 2,
			"stream_channel": 1,
			"record_param": {
				"time": [
					{
						"count": 1,
						"id": 0,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 1,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 2,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 3,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 4,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 5,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					},{
						"count": 1,
						"id": 6,
						"period": [
							{
								"end_hour": 23,
								"end_minute": 59,
								"id": 0,
								"start_hour": 0,
								"start_minute": 8
							}
						]
					}
				]
			},
			"event_param": {
				"event_mode": 0,
				"period": 180
			}
		}
	}
}
```
- Response
```
{
	"module": "BUS_RECORD_VIDEO_REQUEST",
	"type": "set_bus_record_prm",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
storage_mode | 存储类型 | int | 是 | 0x01:相机存储<br>0x02:云端存储
camera_storage_param | 相机存储参数 | object | 是
cloud_storage_param | 云端存储参数 | object | 是
videotape_mode | 录像模式 | int | 是 | 0x01:定时录像<br>0x02:事件录像
stream_channel | 录像码流 | int | 是 | 1:主码流<br>2:子码流
record_param | 定时录像参数配置 | object | 是
event_param | 事件录像参数配置 | object | 是
time | 时间配置 | array | 是
count | 时间段个数 | int | 是
id | 星期几 | int | 是 | time对象下的id<br>0:星期日<br>1:星期一<br>2:星期二<br>3:星期三<br>4:星期四<br>5:星期五<br>6:星期六
period | 时间段 | array | 是
id | 时间段id | int | 是 | period对象下的id
start_hour | 开始的小时数 | int[0,23] | 是
start_minute | 开始的分钟数 | int[0,59] | 是
end_hour | 结束的小时数 | int[0,23] | 是
end_minute | 结束的分钟数 | int[0,59] | 是
event_mode | 事件类型 | int | 是 | 0:不录象<br>1:车辆入场录,车辆出场停<br>2:检测到车辆录
period | 录像时间 | int | 否 | 单位秒(s)，只有在检测到车辆录(event_mode=2)时有效
1.14.3	### 3.获取短视频配置参数
- Request
```
{
    "module":"BUS_RECORD_VIDEO_REQUEST",
    "type":"get_short_video_prm"
}
```
- Response
```
{
	"type": "get_short_video_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"enable": 0,
		"url": "http://192.168.30.16:8060/upload",
		"reco_format": 1
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 启用使能 | int | 是 | 0:不启用<br>1:启用
url | 推送地址 | string | 是 | 
reco_format | 推送类型 | int | 是 | 0:不启用<br>其他:各类型按位或，目前只有1停车事件短视频
### 4.设置短视频配置参数
- Request
```
{
    "module":"BUS_RECORD_VIDEO_REQUEST",
    "type":"set_short_video_prm",
	"body": {
		"enable": 0,
		"url": "http://192.168.30.16:8060/upload",
		"reco_format": 1
	}
}
```
- Response
```
{
	"type": "set_short_video_prm",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 启用使能 | int | 是 | 0:不启用<br>1:启用
url | 推送地址 | string | 是 | 
reco_format | 推送类型 | int | 是 | 0:不启用<br>其他:各类型按位或，目前只有1停车事件短视频
1.15 ## 状态灯控制协议
1.15.1	### 1.获取状态灯参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_state_light_prop"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_state_light_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "control_type": [
	        {
	            "id": 0,
	            "content": "6ISx5py65o6n5Yi2"
	        },
	        {
	            "id": 1,
	            "content": "5bmz5Y+w5o6n5Yi2"
	        }
	    ],
		"event_type": [
			{
				"id": 0,
				"content": "5oql6K2m"
			},
			{
				"id": 1,
				"content": "5YWl5Zy6"
			},
			{
				"id": 2,
				"content": "5Zyo5Zy6"
			},
			{
				"id": 3,
				"content": "5Ye65Zy6"
			},
			{
				"id": 4,
				"content": "56m65Zy6"
			},
			{
				"id": 5,
				"content": "5byC5bi4"
			}
		],
		"light_type": [
			{
				"id": 0,
				"content": "5bi45Lqu"
			},
			{
				"id": 1,
				"content": "6Zeq54OB"
			}
		],
		"color_type": [
			{
				"id": 1,
				"content": "57qi6Imy"
			},
			{
				"id": 2,
				"content": "57u/6Imy"
			},
			{
				"id": 4,
				"content": "6JOd6Imy"
			},
			{
				"id": 8,
				"content": "6buE6Imy"
			},
			{
				"id": 16,
				"content": "55m96Imy"
			},
			{
				"id": 32,
				"content": "57Sr6Imy"
			}
		]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | Array | 是 | 0：脱机控制<br>1：平台控制
event_type | 事件类型 | Array | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
light_type | 状态类型 | Array | 是 | 0：常亮<br>1：闪烁
color_type | 颜色类型 | Array | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
id | 当前类型的ID | int | 是 | 
content | 当前类型描述 | string | 是 | utf8 + base64编码
1.15.2	### 2.获取状态灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_state_light_prm"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_state_light_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "control_type": 0,
		"light_ctrl": [
			{
				"id": 0,
				"enable": 1,
				"color": 8,
				"state": 0
			},
			{
				"id": 1,
				"enable": 1,
				"color": 2,
				"state": 1
			},
			{
				"id": 2,
				"enable": 1,
				"color": 1,
				"state": 0
			},
			{
				"id": 3,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 4,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 5,
				"enable": 1,
				"color": 8,
				"state": 0
			}
		]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | int[0, 1] | 是 | 0：脱机控制<br>1：平台控制
id | 事件类型ID | int | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
enable | 是否开启 | int | 是 |
color | 状态灯颜色 | int | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
state | 展示状态 | int | 是 | 0：常亮<br>1：闪烁
1.15.3	### 3.设置状态灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_state_light_prm",
    "body": {
        "control_type": 0,
		"light_ctrl": [
			{
				"id": 0,
				"enable": 1,
				"color": 8,
				"state": 0
			},
			{
				"id": 1,
				"enable": 1,
				"color": 2,
				"state": 1
			},
			{
				"id": 2,
				"enable": 1,
				"color": 1,
				"state": 0
			},
			{
				"id": 3,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 4,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 5,
				"enable": 1,
				"color": 8,
				"state": 0
			}
		]
	}
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_state_light_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | int[0, 1] | 是 | 0：脱机控制<br>1：平台控制
id | 事件类型ID | int | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
enable | 是否开启 | int | 是 |
color | 状态灯颜色 | int | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
state | 展示状态 | int | 是 | 0：常亮<br>1：闪烁
1.16 ## 升级/更新
1.16.1	### 1.获取升级/更新状态
- request
```
{
	"body": {
		"handle": "upgrade"
	},
	"module": "BATCH_UPDATE_SOFTWARE",
	"type": "get_task_run"
}
```
- response
```
{
    "body":{
        "status": true
    }
    "err_msg":"All done",
    "state":200,
    "type":"get_task_run"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
handle | 升级/更新模块 | string | 是 | 
status | 升级/更新 | bool | 是 | true:正在升级/更新<br>false:没有升级/更新
1.16.2	### 2.升级/更新请求
- request
```
{
	"body": {
		"handle": "upgrade",
		"type":1,
		"url": "http://47.96.182.57:10024/download/VZ_H1M_7.6.1.1625657073_u10k5r17a1625657073.bin",
		"username":"admin",
		"password":"admin",
		"filesize": 59461968,
		"md5":"da3838bd352b1647ab08d1cc58385d6e"
	},
	"module": "BATCH_UPDATE_SOFTWARE",
	"type": "update_software"
}
```
- response
```
{
    "err_msg":"All done",
    "state":200,
    "type":"update_software"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
handle | 升级/更新模块 | string | 是 | 
type | 升级类型 | int | 是 | 1:网络地址<br>2:本地文件（暂未实现）
url | 地址 | string(0, 256] | 是 | 连接地址或路径
username | 用户名 | string[0,32] | 否 | 
password | 密码 | string[0,32] | 否 | 
filesize | 文件大小 | int | 否 |
md5 | 文件md5校验值 | string | 否 | md5值，可以不区分大小写
2 # 业务相关指令
2.1 ## 状态灯控制协议
2.1.1	### 1.获取状态灯参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_state_light_prop"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_state_light_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "control_type": [
	        {
	            "id": 0,
	            "content": "6ISx5py65o6n5Yi2"
	        },
	        {
	            "id": 1,
	            "content": "5bmz5Y+w5o6n5Yi2"
	        }
	    ],
		"event_type": [
			{
				"id": 0,
				"content": "5oql6K2m"
			},
			{
				"id": 1,
				"content": "5YWl5Zy6"
			},
			{
				"id": 2,
				"content": "5Zyo5Zy6"
			},
			{
				"id": 3,
				"content": "5Ye65Zy6"
			},
			{
				"id": 4,
				"content": "56m65Zy6"
			},
			{
				"id": 5,
				"content": "5byC5bi4"
			}
		],
		"light_type": [
			{
				"id": 0,
				"content": "5bi45Lqu"
			},
			{
				"id": 1,
				"content": "6Zeq54OB"
			}
		],
		"color_type": [
			{
				"id": 1,
				"content": "57qi6Imy"
			},
			{
				"id": 2,
				"content": "57u/6Imy"
			},
			{
				"id": 4,
				"content": "6JOd6Imy"
			},
			{
				"id": 8,
				"content": "6buE6Imy"
			},
			{
				"id": 16,
				"content": "55m96Imy"
			},
			{
				"id": 32,
				"content": "57Sr6Imy"
			}
		]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | Array | 是 | 0：脱机控制<br>1：平台控制
event_type | 事件类型 | Array | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
light_type | 状态类型 | Array | 是 | 0：常亮<br>1：闪烁
color_type | 颜色类型 | Array | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
id | 当前类型的ID | int | 是 | 
content | 当前类型描述 | string | 是 | utf8 + base64编码
2.1.2	### 2.获取状态灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_state_light_prm"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_state_light_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "control_type": 0,
		"light_ctrl": [
			{
				"id": 0,
				"enable": 1,
				"color": 8,
				"state": 0
			},
			{
				"id": 1,
				"enable": 1,
				"color": 2,
				"state": 1
			},
			{
				"id": 2,
				"enable": 1,
				"color": 1,
				"state": 0
			},
			{
				"id": 3,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 4,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 5,
				"enable": 1,
				"color": 8,
				"state": 0
			}
		]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | int[0, 1] | 是 | 0：脱机控制<br>1：平台控制
id | 事件类型ID | int | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
enable | 是否开启 | int | 是 |
color | 状态灯颜色 | int | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
state | 展示状态 | int | 是 | 0：常亮<br>1：闪烁
2.1.3	### 3.设置状态灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_state_light_prm",
    "body": {
        "control_type": 0,
		"light_ctrl": [
			{
				"id": 0,
				"enable": 1,
				"color": 8,
				"state": 0
			},
			{
				"id": 1,
				"enable": 1,
				"color": 2,
				"state": 1
			},
			{
				"id": 2,
				"enable": 1,
				"color": 1,
				"state": 0
			},
			{
				"id": 3,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 4,
				"enable": 1,
				"color": 2,
				"state": 0
			},
			{
				"id": 5,
				"enable": 1,
				"color": 8,
				"state": 0
			}
		]
	}
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_state_light_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
control_type | 控制类型 | int[0, 1] | 是 | 0：脱机控制<br>1：平台控制
id | 事件类型ID | int | 是 | 0：报警<br>1：入场<br>2：在场<br>3：出场<br>4：空闲<br>5：异常
enable | 是否开启 | int | 是 |
color | 状态灯颜色 | int | 是 | 1：红色<br>2：绿色<br>4：蓝色<br>8：黄色<br>16：白色<br>32：紫色
state | 展示状态 | int | 是 | 0：常亮<br>1：闪烁
2.2 ## 补光灯控制协议
2.2.1	### 1.获取状态灯参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_led_prop"
}
```
- Response
```
{
    "module": "BUS_REQUEST_MSG",
    "type": "get_led_prop",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "led_level": {
            "default": 0,
            "max": 0,
            "min": -1,
            "types": [
                {
                    "content": "5YWz6Zet",
                    "type": -1
                },
                {
                    "content": "Muexsw==",
                    "type": 0
                }
            ]
        },
        "led_mode": [
            {
                "content": "5pm66IO9",
                "type": 0
            },
            {
                "content": "5bi45Lqu",
                "type": 1
            },
            {
                "content": "5bi454Gt",
                "type": 2
            },
            {
                "content": "5pe26Ze05q61",
                "type": 3
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
content | 当前类型描述 | string | 是 | utf8 + base64编码
2.2.2	### 2.获取补光灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_led_prm"
}
```
- Response
```
{
    "module": "BUS_REQUEST_MSG",
    "type": "get_led_prm",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "time_ctrl": [
                    {
                        "time_begin": "00:00:00",
                        "time_end": "06:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 0
                    },
                    {
                        "time_begin": "06:00:00",
                        "time_end": "19:30:00",
                        "timectrl_enable": false,
                        "led_level": -1,
                        "id": 1
                    },
                    {
                        "time_begin": "19:30:00",
                        "time_end": "24:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 2
                    }
                ],
                "led_mode": 0,
                "led_sensitivity": 4
            }
        ]
    }
}
```
- 参数释

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
led_level | 亮度 | int | 是 | H1M亮度统一相同值
led_mode | 模式 | int | 是 | 0：智能补光<br>1：常开补光<br>2：关闭补光<br>3：手动补光
led_sensitivity | 补光灯灵敏度 | int[0-7] | 是 | 默认4，值越高灵敏度越高
2.2.3	### 3.设置补光灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_led_prm",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "time_ctrl": [
                    {
                        "time_begin": "00:00:00",
                        "time_end": "06:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 0
                    },
                    {
                        "time_begin": "06:00:00",
                        "time_end": "19:30:00",
                        "timectrl_enable": false,
                        "led_level": -1,
                        "id": 1
                    },
                    {
                        "time_begin": "19:30:00",
                        "time_end": "24:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 2
                    }
                ],
                "led_mode": 0,
                "led_sensitivity": 4
            }
        ]
    }
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_led_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
led_level | 亮度 | int | 是 | H1M亮度统一相同值
led_mode | 模式 | int | 是 | 0：智能补光<br>1：常开补光<br>2：关闭补光<br>3：手动补光
led_sensitivity | 补光灯灵敏度 | int[0-7] | 是 | 默认4，值越高灵敏度越高
2.3 ## 连续抓拍
2.3.1	### 1.获取连续抓拍参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_continuity_snap_prop"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_continuity_snap_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "occlusion_time":{
	        "min":60,
	        "max":600
	    },
	    "novideo_time":{
	        "min":60,
	        "max":600
	    },
	    "occlusion_area":{
	        "min":10,
	        "max":100
	    },
	    "alarm_time":{
	        "types":[
	            {
	                "id":0,
	                "content":"5LiN5ZCv55So"
	            },
	            {
	                "id":1,
	                "content":"5LiA5YiG6ZKf"
	            },
	            {
	                "id":3,
	                "content":"5LiJ5YiG6ZKf"
	            },
	            {
	                "id":5,
	                "content":"5LqU5YiG6ZKf"
	            },
	            {
	                "id":10,
	                "content":"5Y2B5YiG6ZKf"
	            }
	        ]
	    }
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion_time | 触发遮挡报警时间 | object | 是 | 
occlusion_area | 触发遮挡报警面积 | object | 是 | 
novideo_time | 视频丢失报警时间 | object | 是 | 
alarm_time | 报警间隔时间 | object | 是 | 
min | 最小值 | int | 是 | 
max | 最大值 | int | 是 | 
id | 当前类型的ID | int | 是 |
content | 当前类型描述 | string | 是 | utf8 + base64编码
2.3.2	### 2.获取连续抓拍参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_continuity_snap_prm"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_continuity_snap_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
      "trigger_ctrl": {
          "stop_steady":{
              "alarm_time":0
          },
          "occlusion":{
              "occlusion_type":3,
              "occlusion_time":1,
              "occlusion_area":80,
              "alarm_time":0
          },
          "parking":{
              "parking_type":15,
              "car_pos":1,
              "alarm_time":0
          },
          "fault":{
              "fault_type":15,
              "novideo_time":60,
              "alarm_time":0
          }
      }
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
trigger_ctrl | 触发控制 | object | 是 | 
stop_steady | 停稳 | object | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0x01：镜头遮挡<br>0x02：车牌遮挡
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  |0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：车头/车尾
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 
2.3.3	### 3.设置连续抓拍参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_continuity_snap_prm",
    "body": {
      "trigger_ctrl": {
          "stop_steady":{
              "alarm_time":3
          },
          "occlusion":{
              "occlusion_type":3,
              "occlusion_time":1,
              "occlusion_area":80,
              "alarm_time":3
          },
          "parking":{
              "parking_type":15,
              "car_pos":1,
              "alarm_time":3
          },
          "fault":{
              "fault_type":15,
              "novideo_time":60,
              "alarm_time":3
          }
      }
    }
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_continuity_snap_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
trigger_ctrl | 触发控制 | object | 是 | 
stop_steady | 停稳 | object | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0x01：镜头遮挡<br>0x02：车牌遮挡
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  |0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：车头/车尾
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 
2.4 ## 合成图片配置
2.4.1	### 1.获取图片拼接模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_prm"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_prm",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
      "enable" : 1,
      "merge_type" : 1,
      "merge_mode" : 1,
      "resolution" : 5
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
merge_type | 合成类型 | int | 是 | 0：两张图片合成<br> 1：三张图片合成<br> 2：四张图片合成<br>
merge_mode | 合成样式 | int | 是 | 0：田字格<br> 1：一字型<br>2：田字格二<br> 3：一字型二<br>
resolution | 特写图分辨率 | int | 是 | 和抓图处分辨率可选项一致
2.4.2	### 2.设置图片拼接模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_pic_merge_prm",
    "body" : {
      "enable" : 1,
      "merge_type" : 1,
      "merge_mode" : 1,
      "resolution": 9
    }
}
```
- Response
```
{
	"type": "set_alg_pic_merge_prm",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
merge_type | 合成类型 | int | 是 | 0：两张图片合成<br> 1：三张图片合成<br> 2：四张图片合成<br>
merge_mode | 合成样式 | int | 是 | 0：田字格<br> 1：一字型<br>2：田字格二<br> 3：一字型二<br>
resolution | 分辨率 | int | 是 | 下拉框和图片配置处可选分辨率一致
2.4.3	### 3.获取合成图片OSD叠加参数属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_osd_prop"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_osd_prop",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
      "position": {
            "default": 0,
            "types": [
                {
                    "content": "5Zyo5Zu+54mH5LiK6L6557yY5aSW5Y+g5Yqg5a2X56ym",
                    "type": 0
                },{
                    "content": "5Zyo5Zu+54mH5LiL6L6557yY5aSW5Y+g5Yqg5a2X56ym",
                    "type": 1
                }
            ]
      },
      "date_format": {
            "default": 0,
            "enable": 1,
            "types": [
                {
                    "content": "WVlZWU1NREQ=",
                    "type": 0
                },{
                    "content": "TU1ERFlZWVk=",
                    "type": 1
                },{
                    "content": "RERNTVlZWVk=",
                    "type": 2
                }
            ]
      },
      "time_format": {
            "default": 1,
            "enable": 1,
            "types": [
                {
                    "content": "MTLlsI/ml7Y=",
                    "type": 0
                },{
                    "content": "MjTlsI/ml7Y=",
                    "type": 1
                }
            ]
      },
      "carplate_format": {
            "default": 39,
            "types": [
                {
                    "content": "6L2m54mM5Y+356CB", // 车牌号码
                    "type": 1
                },{
                    "content": "6L2m54mM57G75Z6L", // 车牌类型
                    "type": 2
                },{
                    "content": "5rOK5L2N5Y+3", // 泊位号
                    "type": 4
                },{
                    "content": "5YGc6L2m54q25oCB", // 停车状态
                    "type": 8
                },{
                    "content": "5YGc6L2m5pa55ZCR", // 停车方向
                    "type": 16
                },{
                    "content": "6L2m54mM572u5L+h5bqm", // 车牌置信度
                    "type": 32
                },{
                    "content": "6L2m54mM5YOP57Sg", // 车牌像素
                    "type": 64
                },{
                    "content": "6L2m5Z6LL+i9puasvi/ovabmoIc=", // 车型/车款/车标
                    "type": 128
                }
            ]
      }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date_format | 日期格式 | object | 是 | 
time_format | 时间格式 | object | 是 | 
carplate_format | 车辆/车牌信息格式 | object | 是 | 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
default | 默认值 | int | 是 | 
enable | 是否启用 | int | 是 | 
content | 对应类型的描述 | string | 是 | utf8 + base64
type | 对应类型的ID | int | 是 | 
2.4.4	### 4.获取合成图片OSD配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_osd"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_osd",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
      "position": 0,
      "date": {
            "enable": 1,
            "date_format": 0
      },
      "time": {
            "enable": 1,
            "time_format": 1
      },
      "carplate_format": 39
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date | 日期格式 | object | 是 | 
enable | 是否启用 | int | 是 |
date_format | 日期格式 | int | 是 | 
time | 时间格式 | object | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆/车牌信息格式 | int | 是 | 0：都不启用<br> 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
2.4.5	### 5.设置合成图片OSD配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_pic_merge_osd",
    "body" : {
      "position": 0,
      "date": {
            "enable": 1,
            "date_format": 0
      },
      "time": {
            "enable": 1,
            "time_format": 1
      },
      "carplate_format": 39
    }
}
```
- Response
```
{
	"type": "set_alg_pic_merge_osd",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date | 日期格式 | object | 是 | 
enable | 是否启用 | int | 是 |
date_format | 日期格式 | int | 是 | 
time | 时间格式 | object | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆/车牌信息格式 | int | 是 | 0：都不启用<br> 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
2.5 ## FLASH图片
2.5.1	### 1.获取是否开启FLASH存图
- Request
```
{
"module":"BUS_FLASH_RECORD_REQUEST",
"type":"get_flash_enable"
}
```
- Response
```
{
"module": "BUS_FLASH_RECORD_REQUEST",
"type": "get_flash_enable",
"state": 200,
"err_msg": "All Done",
"body": {
"enable": 1
}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 开启状态 | int | 否 | 1:开启<br>否则未开启
2.5.2	### 2.获取FLASH文件夹
- Request
```
{
    "module":"BUS_FLASH_RECORD_REQUEST",
    "type":"get_flash_folder",
    "body": {
      "start_time": "1970-01-01 08:00:00",
      "end_time": "2038-01-19 03:14:00"
    }
}
```
- Response
```
{
	"module": "BUS_FLASH_RECORD_REQUEST",
	"type": "get_flash_folder",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	  "folder_num":4,
      "folder_names" : [
         {
            "folder_name" : "2020_06_10"
         },{
            "folder_name" : "2020_06_11"
         },{
            "folder_name" : "2020_06_12"
         },{
            "folder_name" : "2020_06_15"
         }
      ]
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
start_time | 开始时间 | string | 否 | 开始时间，可不填，默认为“1970-01-01 08:00:00”
end_time | 结束时间 | string | 否 | 结束时间，可不填，默认为“2038-01-19 03:14:00”
folder_num | 文件夹个数 | int | 是 | 
folder_names | 文件夹数组 | array | 是 | 
folder_name | 文件夹名 | string | 是 | 
2.5.3	### 3.获取FLASH文件图片文件
- Request
```
{
    "module":"BUS_FLASH_RECORD_REQUEST",
    "type":"get_flash_images",
    "body": {
      "folder_name": "2020_06_10",
      "plate":"无",
      "start_time": "1970-01-01 08:00:00",
      "end_time": "2038-01-19 03:14:00"
    }
}
```
- Response
```
{
	"module": "BUS_FLASH_RECORD_REQUEST",
	"type": "get_flash_images",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	  "img_num":3,
      "img_names" : [
         {
            "img_name" : "135859008_R2_YB-001___无__.jpg"
         }, {
            "img_name" : "135945008_R4_YB-001___无__.jpg"
         }, {
            "img_name" : "142545005_R6_YB-001___无__.jpg"
         }
      ]
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
folder_name | 文件夹名 | string | 是 | 
plate | 筛选车牌号 | string | 否 | 如果为空后者无改字段，默认查所有
start_time | 开始时间 | string | 否 | 开始时间，可不填，默认为“1970-01-01 08:00:00”
end_time | 结束时间 | string | 否 | 结束时间，可不填，默认为“2038-01-19 03:14:00”
img_num | 文件个数 | int | 是 | 
img_names | 图片文件数组 | array | 是 | 
img_name | 图片文件名 | string | 是 | utf8格式<br>取图时，需要组装url：/download.php/VzIPCCap/2020_06_10/135859008_R2_YB-001___无__.jpg
2.5.4	### 4.清空FLASH图片
- Request
```
{
    "module":"BUS_FLASH_RECORD_REQUEST",
    "type":"del_flash_all_image"
}
```
- Response
```
{
	"module": "BUS_FLASH_RECORD_REQUEST",
	"type": "del_flash_all_image",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
2.6 ## 证据链数据
2.6.1	### 1.获取证据链数据
- Request
```
{
    "module":"BUS_EVIDENCE_CHAIN_REQUEST",
    "type":"get_evidence_chain_info"
}
```
- Response
```
{
	"module": "BUS_EVIDENCE_CHAIN_REQUEST",
	"type": "get_evidence_chain_info",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "evidence":[
	        {
	            "zone_id": 0,
	            "enable": 1,
	            "chain": [
	                {
	                    "parking_state": 1,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 2,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                }
	            ]
	        },{
	            "zone_id": 1,
	            "enable": 0,
	            "chain":[]
	        },{
	            "zone_id": 2,
	            "enable": 1,
	            "chain":[
	                {
	                    "parking_state": 1,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 2,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 4,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                },{
	                    "parking_state": 8,
	                    "time_s": "2020-10-10 00:22:34",
	                    "plate_str": "X1/ml6BfXw==",
	                    "plate_color": 0,
	                    "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
											"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
	                    "loc": {
	                        "left": 100,
	                        "right": 100,
	                        "top": 200,
	                        "bottom": 200
	                    }
	                }
	            ]
	        },{
	            "zone_id": 3,
	            "enable": 1,
	            "chain":[]
	        }
	    ]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
zone_id | 车位ID | int[0, 1000] | 是 | 
enable | 车位开关使能 | int[0, 1] | 是 | 
chain | 证据链对象 | array | 否 | 可能为空数组
parking_state | 车位状态 | int | 是 | 证据链状态
time_s | 时间 | string | 是 | 字符串时间
plate_str | 车牌号 | string(0,32] | 是 | UTF8后再BASE64编码
plate_color | 车牌颜色 | int | 是 | 0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
image_path | 图片缓存的路径名 
 | string(0,128] | 是 | UTF8后再BASE64编码)
plateimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
carimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
loc | 车牌/车位置信息 | object | 是 |
left | 车牌/车位置left坐标 | int | 是 |
right | 车牌/车位置right坐标 | int | 是 |
top | 车牌/车位置top坐标 | int | 是 |
bottom | 车牌/车位置bottom坐标 | int | 是 |
2.6.2	### 2.广播证据链更新
- broadcast
```
{
	"module": "EVIDENCE_CHAIN_BROADCAST",
	"type": "broadcast_evidence_chain_info",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "zone_id": 0,
        "enable": 1,
        "chain":[
            {
                "parking_state": 1,
                "time_s": "2020-10-10 00:22:34",
                "plate_str": "X1/ml6BfXw==",
                "plate_color": 0,
                "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
								"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "loc": {
                    "left": 100,
                    "right": 100,
                    "top": 200,
                    "bottom": 200
                }
            },{
                "parking_state": 2,
                "time_s": "2020-10-10 00:22:34",
                "plate_str": "X1/ml6BfXw==",
                "plate_color": 0,
                "image_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "plateimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
								"carimage_path": "VnpJUENDYXAvMjAyMF8xMF8xNi8xNTMwMDUwMDhfUjE0ODY2MV9ZQi0wMDFfX1/ml6BfXy5qcGc=",
                "loc": {
                    "left": 100,
                    "right": 100,
                    "top": 200,
                    "bottom": 200
                }
            }
        ]
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
zone_id | 车位ID | int[0, 1000] | 是 | 
parking_state | 车位状态 | int | 是 | 证据链状态
enable | 车位开关使能 | int[0, 1] | 是 | 
time_s | 时间 | string | 是 | 字符串时间
plate_str | 车牌号 | string(0,32] | 是 | UTF8后再BASE64编码
plate_color | 车牌颜色 | int | 是 | 0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
image_path | 图片缓存的路径名 
 | string(0,128] | 是 | UTF8后再BASE64编码)
plateimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
carimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
loc | 车牌/车位置信息 | object | 是 |
left | 车牌/车位置left坐标 | int | 是 |
right | 车牌/车位置right坐标 | int | 是 |
top | 车牌/车位置top坐标 | int | 是 |
bottom | 车牌/车位置bottom坐标 | int | 是 |
2.7 ## 语音播报（RF）
2.7.1	### 获取语音播报配置
- Request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_voice_broadcast"
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "get_voice_broadcast",
	"body": {
		"time_ctrl": [
			{
				"time_begin": "00:00:00",
				"time_end": "06:00:00",
				"volume": 50,
				"id": 0
			}, {
				"time_begin": "06:00:00",
				"time_end": "19:30:00",
				"volume": 100,
				"id": 1
			}, {
				"time_begin": "19:30:00",
				"time_end": "24:00:00",
				"volume": 50,
				"id": 2
			}
		],
		"male":0,
		"speed":0,
		"voice": [
			{
				"id":0,
				"note":"5YWl5Zy66ZmN6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiL6ZmN77yM6K+35YGc6L2m",
				"length":40
			},{
				"id":1,
				"note":"56a75Zy65Y2H6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiK5Y2H77yM5qyi6L+O5YaN5qyh5YWJ5Li0"
				"length":52
			},{
				"id":2,
				"note":"6ZmQ5Yi26L2m54mM",
				"msg":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA"
				"length":44
			}
		]
	},
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time_ctrl | 时间段音量控制 | object | 是 |  
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
male | 声音选择 | int | 是 |  0:女声;<br>1:男声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice | 语音 | object | 是 |  
note | 语音类型 | string | 是 |  UTF8 + BASE64
msg | 语音内容 | string | 是 |  UTF8 + BASE64
2.7.2	### 设置语音播报配置
- Request
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_voice_broadcast",
	"body": {
		"time_ctrl": [
			{
				"time_begin": "00:00:00",
				"time_end": "06:00:00",
				"volume": 50,
				"id": 0
			}, {
				"time_begin": "06:00:00",
				"time_end": "19:30:00",
				"volume": 100,
				"id": 1
			}, {
				"time_begin": "19:30:00",
				"time_end": "24:00:00",
				"volume": 50,
				"id": 2
			}
		],
		"male":0,
		"speed":100,
		"voice": [
			{
				"id":0,
				"note":"5YWl5Zy66ZmN6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiL6ZmN77yM6K+35YGc6L2m",
				"length":40
			},{
				"id":1,
				"note":"56a75Zy65Y2H6ZSB",
				"msg":"6L2m5L2N6ZSB5bey5LiK5Y2H77yM5qyi6L+O5YaN5qyh5YWJ5Li0",
				"length":52
			},{
				"id":2,
				"note":"6ZmQ5Yi26L2m54mM",
				"msg":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA",
				"length":44
			}
		]
	}
}
```
- Response
```
{
	"module": "BUS_REQUEST_MSG",
	"type": "set_voice_broadcast",	
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
time_ctrl | 时间段音量控制 | object | 是 |  
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
male | 声音选择 | int | 是 |  0:女声;<br>1:男声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice | 语音 | object | 是 |  
note | 语音类型 | string | 是 |  UTF8 + BASE64
msg | 语音内容 | string | 是 |  UTF8 + BASE64
length | 语音内容长度 | int | 是 |  加密后的长度
2.7.3	### 语音试听
- Request
```
{
	"module": "PS_BUS_REQUEST",
	"type": "play_voice",
	"body": {
		"voice_speed":100,
		"voice_male":0,
		"voice_data":"5paw6IO95rqQ6L2m5L2N54eD5rK56L2m6K+356a75byA",
		"data_len":44,
		"voice_volume":100
	}
}
```
- Response
```
{
	"module": "PS_BUS_REQUEST",
	"type": "play_voice",	
	"state":200,
	"error_msg":"All done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
voice_volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
voice_male | 声音选择 | int | 是 |  0:女声;<br>1:男声
voice_speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice_data | 语音内容 | string | 是 |  UTF8 + BASE64
data_len | 语音内容长度 | int | 是 |  加密后的长度
2.8 ## 协作相机
2.8.1	### 获取协作相机信息
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_another_device_ip"
}
```
- Response
```
{
    "module": "SERIAL_COMM_MSG"
    "type": "get_another_device_ip",
    "body": {
        "enable_extern":1,
        "http_port":80,
        "https_en":0,
        "rtsp_port":8557,
        "tcp_port":8132,
        "ip": "192.168.114.210",
				"sn": 8db33777-f1da8164,
        "accounts": [
            {
              "admin":{
                  "authority":0,
                  "password":"admin"
            },
            {
              "test":{
                  "authority":0,
                  "password":"test"
            }
        ],
        "lens_mode": {
            "mode":0,   // 0:近端短焦;1:远端长焦
            "max_plate_num":3
        }
    },
    "state":200,
    "error_msg":"All done"
}  
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable_extern | 是否有协作相机 | int[0, 1] | 是 |  0:没有协作相机<br>1:有协作相机
ip | 协作相机IP | string | 是 | 
https_en | 协作相机是否开启https | int[0, 1] | 是 | 0:http<br>1:https
http_port | 协作相机http端口 | int[0, 65535] | 是 | 
rtsp_port | 协作相机rtsp端口 | int[0, 65535] | 是 | 
tcp_port | 协作相机tcp端口 | int[0, 65535] | 是 | 
sn | 协作相机sn | string | 是 | 
accounts | 协作相机账号信息 | object | 是 | 
lens_mode | 协作相机镜头模式 | object | 是 | 
mode | 协作相机镜头模式 | int[0, 1] | 是 | 0:近端短焦<br>1:远端长焦
max_plate_num | 协作相机最大支持车位数 | int | 是 | 近端短焦:3<br>远端长焦:5
2.8.2	### 获取本机长短焦配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_lens_mode"
}
```
- Response
```
{
	"type": "get_lens_mode",
	"state":200,
	"err_msg":"All Done",
	"body": {
        "mode":0,
        "max_plate_num":3,
        "is_double":0
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 长短焦 | int | 是 | 0：近端短焦<br>1：远端长焦<br>2：超广角
max_plate_num | 数量 | int | 是 | 3：近端短焦默认数量<br>5：远端长焦默认数量
is_double | 是否是双目相机 | int | 是 | 0：单目<br>1：双目
2.8.3	### 设置本机长短焦配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "set_lens_mode",
    "body": {
        "mode":0,
        "max_plate_num":3,
        "is_double":0
	}
}
```
- Response
```
{
	"type": "set_lens_mode",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 长短焦 | int | 是 | 0：近端短焦<br>1：远端长焦<br>2：超广角
max_plate_num | 数量 | int | 是 | 3：近端短焦默认数量<br>5：远端长焦默认数量
is_double | 是否是双目相机 | int | 是 | 0：单目<br>1：双目
2.8.4	### 获取本机镜头配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_zoomlens_mode"
}
```
- Response
```
{
	"type": "get_zoomlens_mode",
	"state":200,
	"err_msg":"All Done",
	"body": {
        "zoomlens_mode" :[]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
2.8.5	### 设置本机镜头配置
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "set_zoomlens_mode",
    "body": {
        "zoomlens_mode" :[
					 {
					   "lensId":0,
						 "type":1,
						 "focus":1320,
						 "f_dp": 252,
						 "zoom":1320，
						 "z_dp":252
					 }
				]
	}
}
```
- Response
```
{
	"type": "set_zoomlens_mode",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
lensId | 镜头ID | int | 是 | 按数组从零开始，H1M都是一块板一个镜头，填0
type | 镜头类型 | int | 是 | 0：定焦<br>1：变焦
focus | focus总行程 | int | 是 | 1320：总行程<br>252：中间零点值
f_dp | focus中间零点值 | int | 是 | 
zoom | zoom总行程 | int | 是 | 1320：总行程<br>252：中间零点值
z_dp | zoom中间零点值 | int | 是 | 
2.8.6	### 获取对端上云映射IP端口号
- Request
```
{
    "module": "SERIAL_COMM_MSG",
    "type": "get_another_device_pdns",
    "body": {
        "port":80
	  }
}
```
- Response
```
{
	"type": "get_another_device_pdns",
	"state":200,
	"err_msg":"All Done",
	"body" : {
      "host" : "119.3.44.91",
      "port" : 10760
   }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
host | 映射ip | int | 是 | 
port | 映射端口 | int | 是 | 

2.9 ## 云台
2.9.1	### 1.控制云台
- Request
```
{
  "type":"set_cloud_ctrl",
  "module":"BUS_REQUEST_MSG",
  "body":{
    "dir":8,
    "degree":0
  }
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_reco_osd_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
dir | 方向 | int | 是 | 2:向上移动<br>4:向下移动<br>8:停止上下移动<br>16:向左移动<br>32:向右移动<br>64:停止左右移动<br>128:还原
degree | 最大角度 | int | 是 | 默认-1，驱动自己判断最大角度角度

3 # 算法相关指令
3.1 ## 抓图OSD叠加
3.1.1	### 1.获取抓图OSD叠加参数属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_reco_osd_prop"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_reco_osd_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "align": {
			"default": 0,
			"enable": true,
			"types": [
				{
					"content": "6Ieq5a6a5LmJ",
					"type": 0
				},{
					"content": "5bGF5bem5a+56b2Q",
					"type": 1
				},{
					"content": "5bGF5Y+z5a+56b2Q",
					"type": 2
				},{
					"content": "5Zu95qCH",
					"type": 3
				}
			]
		},
		"color": {
			"default": 0,
			"enable": true,
			"types": [
				{
					"content": "55m96Imy",
					"type": 0
				},{
					"content": "57qi6Imy",
					"type": 1
				},{
					"content": "6JOd6Imy",
					"type": 2
				},{
					"content": "57u/6Imy",
					"type": 3
				}
			]
		},
		"date_format": {
			"default": 0,
			"enable": true,
			"types": [
				{
					"content": "WVlZWU1NREQ=",
					"type": 0
				},{
					"content": "TU1ERFlZWVk=",
					"type": 1
				},{
					"content": "RERNTVlZWVk=",
					"type": 2
				}
			]
		},
		"font_size": {
			"default": 3,
			"enable": true,
			"types": [
				{
					"content": "MTZYMTY=",
					"type": 0
				},{
					"content": "MjRYMjQ=",
					"type": 1
				},{
					"content": "MzJYMzI=",
					"type": 2
				},{
					"content": "NDhYNDg=",
					"type": 3
				}
			]
		},
		"time_format": {
			"default": 1,
			"enable": true,
			"types": [
				{
					"content": "MTLlsI/ml7Y=",
					"type": 0
				},{
					"content": "MjTlsI/ml7Y=",
					"type": 1
				}
			]
		},
		"carplate_format": {
		    "default": 31,
			"enable": true,
			"types": [
			    {
					"content": "6L2m54mM5Y+356CB",
					"type": 1
				},{
					"content": "6L2m54mM57G75Z6L",
					"type": 2
				},{
					"content": "6L2m5L2N5ZCN56ew",
					"type": 4
				},{
					"content": "5YGc6L2m54q25oCB",
					"type": 8
				},{
					"content": "5YGc6L2m5pa55ZCR",
					"type": 16
				},{
					"content": "572u5L+h5bqm",
					"type": 32
				},{
					"content": "6L2m54mM5YOP57Sg",
					"type": 64
				},{
					"content": "6L2m5Z6LL+i9puasvi/ovabmoIc=",
					"type": 128
				}
			]
		}
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chan_id  | 通道ID | int | 是 | 
align | 对齐方式 | object | 是 | 
color | OSD颜色 | object | 是 | 
font_size | OSD字体 | object | 是 | 
date_format | 日期格式 | object | 是 | 
time_format | 时间格式 | object | 是 | 
carplate_format | 车辆/车牌信息格式 | object | 是 | 1：车牌号<br>2：车牌类型<br>4：车位名称<br>8：停车状态<br>16：停车方向<br>32：置信度<br>64：车牌像素<br>128：车型/车款/车标
default | 默认值 | int | 是 | 
enable | 是否启用 | boolean | 是 | 
content | 对应类型的描述 | string | 是 | utf8 + base64
type | 对应类型的ID | int | 是 | 
3.1.2	### 2.获取抓图OSD叠加
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_reco_osd_prm"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_reco_osd_prm",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"channel": [
			{
				"chan_id": 0,
				"osd_param": {
					"align": 11,
					"color": 0,
					"font_size": 3,
					"date": {
						"date_format": 0,
						"enable": 1,
						"pos": 0
					},
					"datetime": {
						"enable": 1,
						"pos": 10420224,
						"time_format": 1
					},
					"carplate": {
						"carplate_format": 15,
						"enable": 0,
						"pos": 0
					},
					"usr_text": [
					    {
					        "context":"b3Nk",
					        "enable":0,
					        "pos":100
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":200
					    },{
					       "context":"b3Nk",
					        "enable":0,
					        "pos":300
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":400
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":500
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":600
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":700
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":800
					    }
					]
				}
			}
		]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chan_id  | 通道ID | int | 是 | 
align | 对齐方式 | int | 是 | 
color | OSD颜色 | int | 是 | 
font_size | OSD字体 | int | 是 | 
date | 日期 | object | 是 | 
time | 时间 | object | 是 | 
date_format | 日期格式 | int | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆车牌信息格式 | int | 是 | 1：车牌号<br>2：车牌类型<br>4：车位名称<br>8：停车状态<br>16：停车方向<br>32：置信度<br>64：车牌像素<br>128：车型/车款/车标
enable | 是否开启 | int | 是 | 
pos | 位置 | int | 是 | 高4位：x坐标<br>低4位：y坐标<br>按1000*1000基准
context | OSD内容 | string | 是 | utf8 + base64
3.1.3	### 3.设置抓图OSD叠加
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_reco_osd_prm",
    "body": {
		"channel": [
			{
				"chan_id": 0,
				"osd_param": {
					"align": 2,
					"color": 0,
					"font_size": 3,
					"date": {
						"date_format": 0,
						"enable": 1,
						"pos": 0
					},
					"datetime": {
						"enable": 1,
						"pos": 10420224,
						"time_format": 1
					},
					"carplate": {
						"carplate_format": 31,
						"enable": 0,
						"pos": 655408
					},
					"usr_text": [
					    {
					        "context":"b3Nk",
					        "enable":0,
					        "pos":100
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":200
					    },{
					       "context":"b3Nk",
					        "enable":0,
					        "pos":300
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":400
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":500
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":600
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":700
					    },{
					        "context":"b3Nk",
					        "enable":0,
					        "pos":800
					    }
					]
				}
			}
		]
	}
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "set_alg_reco_osd_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chan_id  | 通道ID | int | 是 | 
align | 对齐方式 | int | 是 | 
color | OSD颜色 | int | 是 | 0：白色，
font_size | OSD字体 | int | 是 | 0：16*16
date | 日期 | object | 是 | 
time | 时间 | object | 是 | 
date_format | 日期格式 | int | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆车牌信息格式 | int | 是 | 1：车牌号<br>2：车牌类型<br>4：车位名称<br>8：停车状态<br>16：停车方向<br>32：置信度<br>64：车牌像素<br>128：车型/车款/车标
enable | 是否开启 | int | 是 | 
pos | 位置 | int | 是 | 高4位：x坐标<br>低4位：y坐标
context | OSD内容 | string | 是 | utf8 + base64
3.2 ## 报警参数
3.2.1	### 2.获取报警参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_alarm_prm"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_reco_osd_prm",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"car_alarm": {
		    "car_pos":0
		}
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
car_pos  | 车头车尾报警 | int | 是 | 0:不报警<br>1:车头报警<br>2:车尾报警
3.2.2	### 3.设置报警参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_alarm_prm",
    "body": {
		"car_alarm": {
		    "car_pos":0
		}
	}
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "set_alg_alarm_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
car_pos  | 车头车尾报警 | int | 是 | 0:不报警<br>1:车头报警<br>2:车尾报警
3.2.3	### 4.获取H1M报警参数属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_alarm_param_prop"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_road_alarm_param_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "occlusion_time":{
	        "min":60,
	        "max":600
	    },
	    "novideo_time":{
	        "min":60,
	        "max":600
	    },
	    "occlusion_area":{
	        "min":10,
	        "max":100
	    },
	    "out_park_time":{
	        "min":60,
	        "max":600
	    }
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion_time | 触发遮挡报警时间 | object | 是 | 
occlusion_area | 触发遮挡报警面积 | object | 是 | 
novideo_time | 视频丢失报警时间 | object | 是 | 
out_park_time | 泊位外停车时间 | object | 是 | 
alarm_time | 报警间隔时间 | object | 是 | 
min | 最小值 | int | 是 | 
max | 最大值 | int | 是 | 
id | 当前类型的ID | int | 是 |
content | 当前类型描述 | string | 是 | utf8 + base64编码
3.2.4	### 5.获取H1M报警参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_alarm_param"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_road_alarm_param",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "occlusion":{
          "occlusion_type":3,
          "occlusion_time":1,
          "occlusion_area":80,
          "alarm_time":0
        },
        "parking":{
          "parking_type":15,
          "car_pos":1,
          "out_park_time":300,
          "alarm_time":0
        },
        "fault":{
          "fault_type":15,
          "novideo_time":60,
          "alarm_time":0
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0x01：镜头遮挡<br>0x02：车牌遮挡<br>0x04：镜头偏移<br>0x08：镜头虚焦
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车<br>0x80：斜向停车
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 
3.2.5	### 6.设置H1M报警参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_road_alarm_param",
    "body": {
        "occlusion":{
          "occlusion_type":3,
          "occlusion_time":1,
          "occlusion_area":80,
          "alarm_time":0
        },
        "parking":{
          "parking_type":15,
          "car_pos":1,
          "out_park_time":300,
          "alarm_time":0
        },
        "fault":{
          "fault_type":15,
          "novideo_time":60,
          "alarm_time":0
        }
    }
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "set_alg_road_alarm_param",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0x01：镜头遮挡<br>0x02：车牌遮挡<br>0x04：镜头偏移<br>0x08：镜头虚焦
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车<br>0x80：斜向停车
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 
3.3 ## 车位模式协议
3.3.1	### 1.获取车位模式属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_park_mode_prop"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_park_mode_prop",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"modes":[
    		{
    		    "mode":0,
    		    "content":"5bmz6KGM6L2m5L2N"
    		},
    		{
    		    "mode":1,
    		    "content":"5Z6C55u06L2m5L2N"
    		},
    		{
    		    "mode":2,
    		    "content":"5pac5ZCR6L2m5L2N"
    		}
		]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
modes | 模式类型 | object | 是 | 
mode | 车位模式 | int | 是 | 0：平行车位<br>1：垂直车位<br>2：斜向车位
content | 模式描述 | string | 是 | utf8 + base64
3.3.2	### 2.获取车位模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_park_mode_prm"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_park_mode_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"mode":0
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 车位模式 | int | 是 | 0：平行车位<br>1：垂直车位<br>2：斜向车位
3.3.3	### 3.设置车位模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_park_mode_prm",
    "body": {
		"mode":0
	}
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "set_alg_park_mode_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 车位模式 | int | 是 | 0：平行车位<br>1：垂直车位<br>2：斜向车位
3.4 ## 高级识别参数协议
3.4.1	### 1.获取高级识别参数属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_senior_reco_prop"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_senior_reco_prop",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"cardetect": {
			"car_width": {
				"min": 80,
				"max": 600
			}
		},
		"plate": {
			"confidence": {
				"min": 50,
				"max": 100
			},
			"max_number": {
				"min": 1,
				"max": 10
			},
			"pixel": {
				"min": 80,
				"max": 600
			}
		},
		"coil": {
			"outspread": {
				"min": 0,
				"max": 30
			},
			"sensitivity": {
				"min": 0,
				"max": 100
			}
		},
		"pic_select": {
			"in_time": {
				"min": 1,
				"max": 1000
			},
			"on_time": {
				"min": 1,
				"max": 1000
			},
			"out_time": {
				"min": 1,
				"max": 1000
			},
			"empty_time": {
				"min": 1,
				"max": 1000
			},
			"rule": {
				"types": [
					{
						"type": 0,
						"content": "5Ye65Zy66YCJ5Zu+",
						"tips": "56m66Zey5Zu+54mH6L2m6L6G5a6M5YWo56a75byA6L2m5L2N"
					},
					{
						"type": 1,
						"content": "5pyA5L2z6YCJ5Zu+",
						"tips": "5YWl5Zy65Ye65Zy65ZCE5LiA5byg55yL5b6X6KeB6L2m54mM55qE5Zu+54mH"
					}
				]
			}
		}
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 |
car_width | 目标最小宽度 | object | 是 |
plate | 车牌参数 | object | 是 |
confidence | 车牌置信度阈值 | object| 是 |
max_number | 最大车牌数 | object | 是 |
pixel | 车牌像素限制最小值 | object | 是 |
coil | 线圈参数 | object | 是 |
outspread | 边缘线外扩比例 | object | 是 |
sensitivity | 边缘线灵敏度 | object | 是 |
pic_select | 选图参数 | object | 是 |
in_time | 入场时间阈值 | object | 是 | 单位秒
on_time | 停留时间阈值 | object | 是 | 单位秒
out_time | 出场时间阈值 | object | 是 | 单位秒
empty_time | 空闲时间阈值 | object | 是 | 单位秒
min | 最小值 | int | 是 |
max | 最大值 | int | 是 |
rule | 选图规则 | object | 是 | 
types | 选图规则类型 | array | 是 | 
type | 选图规则 | int | 是 |
content | 描述 | string | 是 | utf8 + base64
tips | 提示 | string | 是 | utf8 + base64
3.4.2	### 2.获取高级识别参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_senior_reco_prm"
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "get_alg_senior_reco_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"cardetect":{
		    "min_width":100
		},
		"plate":{
		    "confidence":80,
		    "max_number":4,
		    "min_pixel":80,
		    "max_pixel":600
		},
		"coil":{
		    "outspread":0,
		    "sensitivity":50
		},
		"pic_select":{
		    "in_time":60,
		    "on_time":10,
		    "out_time":60,
		    "empty_time":5,
		    "rule":0
		}
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 |
min_width | 目标最小宽度 | int[80, 600] | 是 |
plate | 车牌参数 | object | 是 |
confidence | 车牌置信度阈值 | int[80, 100] | 是 |
max_number | 最大车牌数 | int[1, 10] | 是 |
min_pixel | 车牌像素限制最小值 | int[80, 600) | 是 |
max_pixel | 车牌像素限制最大值 | int(80, 600] | 是 |
coil | 线圈参数 | object | 是 |
outspread | 边缘线外扩比例 | int[0, 30] | 是 |
sensitivity | 边缘线灵敏度 | int[0, 100] | 是 |
pic_select | 选图参数 | object | 是 |
in_time | 入场时间阈值 | int[1, 1000] | 是 | 单位秒
on_time | 停留时间阈值 | int[1, 1000] | 是 | 单位秒
out_time | 出场时间阈值 | int[1, 1000] | 是 | 单位秒
empty_time | 空闲时间阈值 | int[1, 1000] | 是 | 单位秒
rule | 选图规则 | int[0, 1] | 是 | 0：出场选图（空闲图片车辆完全离开车位）<br>1：最佳选图（入场出场各一张看得见车牌的图片）
3.4.3	### 3.设置高级识别参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_senior_reco_prm",
    "body": {
		"cardetect":{
		    "min_width":100
		},
		"plate":{
		    "confidence":80,
		    "max_number":4,
		    "min_pixel":80,
		    "max_pixel":600
		},
		"coil":{
		    "outspread":0,
		    "sensitivity":50
		},
		"pic_select":{
		    "in_time":60,
		    "on_time":10,
		    "out_time":60,
		    "empty_time":5,
		    "rule":0
		}
	}
}
```
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "set_alg_senior_reco_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 |
min_width | 目标最小宽度 | int[80, 600] | 是 |
plate | 车牌参数 | object | 是 |
confidence | 车牌置信度阈值 | int[80, 100] | 是 |
max_number | 最大车牌数 | int[1, 10] | 是 |
min_pixel | 车牌像素限制最小值 | int[80, 600) | 是 |
max_pixel | 车牌像素限制最大值 | int(80, 600] | 是 |
coil | 线圈参数 | object | 是 |
outspread | 边缘线外扩比例 | int[0, 30] | 是 |
sensitivity | 边缘线灵敏度 | int[0, 100] | 是 |
pic_select | 选图参数 | object | 是 |
in_time | 入场时间阈值 | int[1, 1000] | 是 | 单位秒
on_time | 停留时间阈值 | int[1, 1000] | 是 | 单位秒
out_time | 出场时间阈值 | int[1, 1000] | 是 | 单位秒
empty_time | 空闲时间阈值 | int[1, 1000] | 是 | 单位秒
rule | 选图规则 | int[0, 1] | 是 | 0：出场选图（空闲图片车辆完全离开车位）<br>1：最佳选图（入场出场各一张看得见车牌的图片）
3.5 ## 单帧识别
3.5.1	###  1.上传用于单帧识别的图片文件
延用全智能2.0通用的上传接口，图片大小800K以内
- 接口
```
/upload.php
```
3.5.2	### 2.请求单帧识别
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"roadside_single_rec",
    "body":{
        "path":"xxxxxxxxxx"
    }
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
file_name | 文件名 | string(0,128] | 是 | 上传是指定的文件名
- Response
```
{
	"module": "ALG_REQUEST_MESSAGE",
	"type": "roadside_single_rec",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"path": "xxxxxxxx",
		"plate_result_num": 1,
		"car_result_num": 1,
		"head_result_num": 1,
		"tail_result_num": 1,
		"nonMotor_result_num": 1,
		"human_result_num": 1,
		"plate_result": [
			{
				"plate_str": "川A12345",
				"plate_type": 0,
				"plate_color": 0,
				"plate_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		],
		"car_result": [
			{
				"car_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		],
		"head_result": [
			{
				"head_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		],
		"tail_result": [
			{
				"tail_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		],
		"nonMotor_result": [
			{
				"nonMotor_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		],
		"human_result": [
			{
				"human_loc": {
					"left": 0,
					"right": 123,
					"top": 0,
					"bottom": 123
				}
			}
		]
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
plate_result_num | 车牌结果数量 | int | 是 | 
car_result_num | 车辆结果数量 | int | 是 | 
head_result_num | 车头结果数量 | int | 是 | 
tail_result_num | 车尾结果数量 | int | 是 | 
nonMotor_result_num | 非机动车结果数量 | int | 是 | 
human_result_num | 行人结果数量 | int | 是 | 
plate_result | 车牌结果数组 | array | 否 | 
car_result | 车辆结果数组 | array | 否 | 
head_result | 车头结果数组 | array | 否 | 
tail_result | 车尾结果数组 | array | 否 | 
nonMotor_result | 非机动车结果数组 | array | 否 | 
human_result | 行人结果数组 | array | 否 | 
plate_loc | 车牌坐标 | object | 否 | 
car_loc | 车辆坐标 | object | 否 | 
head_loc | 车头坐标 | object | 否 | 
tail_loc| 车尾坐标 | object | 否 | 
nonMotor_loc | 非机动车坐标 | object | 否 | 
human_loc | 行人坐标 | object | 否 | 
left | 位置left坐标 | int | 是 |
right | 位置right坐标 | int | 是 |
top | 位置top坐标 | int | 是 |
bottom | 位置bottom坐标 | int | 是 |
4 # 系统相关指令
4.1 ## 校时控制协议
4.1.1	### 1.获取校时控制
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_get_timing_type"
}
```
- Response
```
{
	"module": "SS_BUS_REQUEST",
	"type": "ss_get_timing_type",
	"state": 200,
	"err_msg": "All Done",
	"body": {
		"mode":0
	}
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 控制 | int | 是 | 按位控制<br> 0：不校时<br>1：NTP校时<br>2：onvif校时<br>4：http校时
4.1.2	### 2.设置校时控制
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_set_timing_type",
    "body": {
		"mode":0
	}
}
```
- Response
```
{
	"module": "SS_BUS_REQUEST",
	"type": "ss_set_timing_type",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 控制 | int | 是 | 按位控制<br> 0：不校时<br>1：NTP校时<br>2：onvif校时<br>4：http校时
4.2 ## VPN配置协议
4.2.1	### 1.获取vpn配置
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_get_vpn_net"
}
```
- Response
```
{
    "type": "ss_get_vpn_net",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "enable": 1,
        "cfg_data": "client\ndev tun\nproto udp\nremote 121.43.255.196 1194\nresolv-retry infinite\nnobind\npersist-key\npersist-tun\nca ca.crt\ncert vsc-bp15ff6xf8n5o00mgpw80.crt\nkey vsc-bp15ff6xf8n5o00mgpw80.key\ncipher AES-128-CBC\n;comp-lzo\nverb 4", 
        "check_file": [
            "ca.crt",
            "vsc-bp15ff6xf8n5o00mgpw80.crt",
            "vsc-bp15ff6xf8n5o00mgpw80.key"
        ]
    }
}
```
- 参数释义
- 配置文件名字固定死的config.ovpn
- 文件上传路径/mnt/usr/openvpn

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | vpn开关 | int | 是 | 0：不启用<br>1：启用<br>
cfg_data | 配置文件数据 | string | 是 | 
check_file | 校验文件列表 | array(string) | 是 | 
4.2.2	### 2.设置vpn配置
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_set_vpn_net",
    "body" : {
      "enable" : 1
    }
}
```
- Response
```
{
	"type": "ss_set_vpn_net",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | vpn开关 | int | 是 | 0：不启用<br>1：启用<br>
cfg_data | 配置文件数据 | string | 是 | 
check_file | 校验文件列表 | array(string) | 是 | 
4.2.3	### 3.获取vpn连接状态
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_get_vpn_status"
}
```
- Response
```
{
	"type": "ss_get_vpn_status",
	"state":200,
	"err_msg":"All Done",
	"body" : {
        "status":0
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
status | 连接状态 | int | 是 | 0：未连接<br>1：已连接<br>
4.2.4	### 4.清除校验文件
- Request
```
{
    "module":"SS_BUS_REQUEST",
    "type":"ss_clear_vpn_file",
    "body" : {
        "files":[
        "ca.crt"
        ]
    }
}
```
- Response
```
{
	"type": "ss_clear_vpn_file",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
files | 清除文件 | array(string) | 是 | []：全部清除<br>["ca.crt"]：清除指定文件<br>
5 # 推送相关指令
5.1 ## 推送配置协议
5.1.1	### 1.获取HTTP推送配置
- Request
```
{
    "module":"BUS_HTTP_REQUEST",
    "type":"get_push_cfg"
}
```
- Response
```
{
	"type": "get_push_cfg",
	"state": 200,
	"err_msg": "All Done",
    "body": {
        "dev_reg": {
            "heart_mode": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA: =",
            "time": 20
        },
        "ivs_rlt": {
            "enable": 1,
            "url": "L3Z6L2l2cy5qc3A=",
            "detail_level": 0,
            "big_img": 1,
            "small_img": 1,
            "mode": 0,
            "car_img": 0
        },
        "mqtt_rlt": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL21xdHRyZXN1bHRpbmZvLnBocA=="
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
dev_reg | 设备注册 | Object | 是 | 
heart_mode | 心跳模式 | int | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
url | 推送地址 | string | 是 | utf8的base64字符串
time | 推送地址 | int | 是 |心跳时间
ivs_rlt | 推送识别结果 | Object | 是 | 
enable | 使能开关 | int | 是 | 0：关闭<br> 1：开启<br>
big_img | 全景图 | int | 是 | 0：推送<br> 1：不推送<br>
small_img | 车牌特写图 | int | 是 | 0：推送<br> 1：不推送<br>
car_img | 车辆特写图 | int | 是 | 0：推送<br> 1：不推送<br>
mode | 推送模式 | int | 是 | 0：识别结果推送<br> 1：事件推送<br>
mqtt_rlt | mqtt结果推送 | Object | 是 | 
5.1.2	### 2.设置HTTP推送配置
- Request
```
{
    "module":"BUS_HTTP_REQUEST",
    "type":"set_push_cfg",
    "body": {
        "dev_reg": {
            "heart_mode": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA: =",
            "time": 20
        },
        "ivs_rlt": {
            "enable": 1,
            "url": "L3Z6L2l2cy5qc3A=",
            "detail_level": 0,
            "big_img": 1,
            "small_img": 1,
            "mode": 0,
            "car_img": 0
        },
        "mqtt_rlt": {
            "enable": 0,
            "url": "L2RldmljZW1hbmFnZW1lbnQvcGhwL21xdHRyZXN1bHRpbmZvLnBocA=="
        }
    }
}
```
- Response
```
{
	"type": "set_push_cfg",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
dev_reg | 设备注册 | Object | 是 | 
heart_mode | 心跳模式 | int | 是 | 0：取消心跳<br> 1：普通心跳<br>2：comet轮询<br>
url | 推送地址 | string | 是 | utf8的base64字符串
time | 推送地址 | int | 是 |心跳时间
ivs_rlt | 推送识别结果 | Object | 是 | 
enable | 使能开关 | int | 是 | 0：关闭<br> 1：开启<br>
big_img | 全景图 | int | 是 | 0：推送<br> 1：不推送<br>
small_img | 车牌特写图 | int | 是 | 0：推送<br> 1：不推送<br>
car_img | 车辆特写图 | int | 是 | 0：推送<br> 1：不推送<br>
mode | 推送模式 | int | 是 | 0：识别结果推送<br> 1：事件推送<br>
mqtt_rlt | mqtt结果推送 | Object | 是 | 
5.1.3	### 3.获取MQTT连接状态
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"get_mqtt_connect_status"
}
```
- Response
```
{
	"type": "get_mqtt_connect_status",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "status": 0
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
status | 连接状态 | int | 是 | 0：未连接<br> 1：正在连接<br>2：已连接<br>3：连接失败<br>
5.1.4	### 4.获取接入MQTT配置
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"get_mqtt_cfg"
}
```
- Response
```
{
	"type": "get_mqtt_cfg",
	"state": 200,
	"err_msg": "All Done",
	"body": {
	    "enable": 0,
	    "host": "122.112.244.245",
	    "port": 1883,
	    "client_id": "bf562e01-514d7b39",
      "username": "server",
      "password": "Vzenith5449",
      "keep_alive": 60,
      "subscription": [
            {
                "topic": "device/bf562e01-514d7b39/message/down/+"
            }
      ]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
host | 地域 | string | 是 | 服务地址
username | 用户名 | string | 否 | 
password | 密码 | string | 是 |
port | 端口号 | int(0,65535] | 否 | 默认1883
client_id | client_id | string | 是 | 
keep_alive | 心跳 | int | 是 | 
subscription | 订阅 | array | 是 | 可在高级选项进行修改
topic | 订阅topic | string | 是 | 
5.1.5	### 5.设置接入MQTT配置
- Request
```
{
    "module":"BUS_MQTT_REQUEST",
    "type":"set_mqtt_cfg",
    "body": {
	    "enable": 0,
	    "host": "122.112.244.245",
	    "port": 1883,
	    "client_id": "bf562e01-514d7b39",
      "username": "server",
      "password": "Vzenith5449",
      "keep_alive": 60,
      "subscription": [
            {
                "topic": "device/bf562e01-514d7b39/message/down/+"
            }
      ]
	}
}
```
- Response
```
{
	"type": "set_mqtt_cfg",
	"state": 200,
	"err_msg": "All Done",
	
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：关闭<br> 1：开启<br>
host | 地域 | string | 是 | 服务地址
username | 用户名 | string | 否 | 
password | 密码 | string | 是 |
port | 端口号 | int(0,65535] | 否 | 默认1883
client_id | client_id | string | 是 | 
keep_alive | 心跳 | int | 是 | 
subscription | 订阅 | array | 是 | 可在高级选项进行修改
topic | 订阅topic | string | 是 | 

6 # 定制协议网页配置
6.1 ## H1M松立配置
6.1.1	### 1.获取平台ID
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_custom_info"
}
```
- Response
```
{
	"type": "get_custom_info",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"custom_id":1
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
custom_id | 平台ID | int | 是 | 0：臻识<br>1：松立<br>
6.1.2	### 2.获取设备信息
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_custom_dev_info"
}
```
- Response
```
{
	"type": "get_custom_dev_info",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"authcode":"370202001123",
        "longitude": "104.07",
        "latitude": "30.67",
        "remark": "6L+c56uv55u45py6",
        "zone_num": 4,
        "zone_name": [
        {
            "id" : 0,
            "name": "MQ=="
        },
        {
            "id" : 1,
            "name": "Mg=="
        },
        {
            "id" : 2,
            "name": "Mw=="
        },
        {
            "id" : 3,
            "name": "NA=="
        }
        ]
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
authcode | 授权码 | string | 是 | 
longitude | 经度 | string | 是 |
latitude | 纬度 | string | 是 |
remark | 备注 | string | 是 | Base64编码
zone_num | 泊位数量 | int | 是 |
zone_name | 泊位名称 | object | 是 |
id | zone_id | int | 是 |
name | 泊位名称 | string | 是 | Base64编码
6.1.3	### 3.设置设备信息
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"set_custom_dev_info",
    "body": {
		"authcode":"370202001123",
        "longitude": "104.07",
        "latitude": "30.67",
        "remark": "6L+c56uv55u45py6",
        "zone_num": 4,
        "zone_name": [
        {
            "id" : 0,
            "name": "MQ=="
        },
        {
            "id" : 1,
            "name": "Mg=="
        },
        {
            "id" : 2,
            "name": "Mw=="
        },
        {
            "id" : 3,
            "name": "NA=="
        }
        ]
	}
}
```
- Response
```
{
	"type": "set_custom_dev_info",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
authcode | 授权码 | string | 是 | 
longitude | 经度 | string | 是 |
latitude | 纬度 | string | 是 |
remark | 备注 | string | 是 | Base64编码
zone_num | 泊位数量 | int | 是 |
zone_name | 泊位名称 | object | 是 |
id | zone_id | int | 是 |
name | 泊位名称 | string | 是 | Base64编码
6.1.4	### 4.获取服务配置
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_sl_server_cfg"
}
```
- Response
```
{
	"type": "get_sl_server_cfg",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"server_ip":"192.168.1.2",
		"server_port":8081,
		"timeout":20,
		"resend_times": 3
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
server_ip | 平台地址 | string | 是 | 
server_port | 平台端口 | int | 是 |
timeout | 超时时间 | int | 是 |
resend_times | 重传次数 | int | 是 | 
6.1.5	### 5.设置服务配置
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"set_sl_server_cfg",
    "body": {
		"server_ip":"192.168.1.2",
		"server_port":8081,
		"timeout":20,
		"resend_times": 3
	}
}
```
- Response
```
{
	"type": "set_sl_server_cfg",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
server_ip | 平台地址 | string | 是 | 
server_port | 平台端口 | int | 是 |
timeout | 超时时间 | int | 是 | 秒
resend_times | 重传次数 | int | 是 | 
6.1.6	### 6.获取相机注册状态
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_reg_status"
}
```
- Response
```
{
	"type": "get_reg_status",
	"state":200,
	"err_msg":"All Done",
	"body": {
		"status": 0
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
status | 注册状态 | int | 是 | 0：未注册<br>1：注册失败<br>2：注册成功<br>

6.1.7	### 7.相机注册上线
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"set_reg_status",
    "body": {
		"status": 0
	}
}
```
- Response
```
{
	"type": "set_reg_status",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
status | 当前注册状态 | int | 是 | 0：未注册<br>1：注册失败<br>2：注册成功<br>
6.2 ## 捷顺和立方配置
6.2.1	### 1.获取平台类型
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_custom_info"
}
```
- Response
```
{
	"type": "get_custom_info",
	"state":200,
	"err_msg":"All Done",
	"body" : {
      "custom_id" : 4
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
custom_id | 平台id | int | 是 | 0：臻识<br>1：松立<br>4：捷顺<br>5：立方<br>7：漳州，立方没有心跳时间,也可以把心跳时间写成设备状态上报时间<br>
6.2.2	### 2.获取平台配置
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_custom_server_cfg"
}
```
- Response
```
{
	"type": "get_custom_server_cfg",
	"state":200,
	"err_msg":"All Done",
	"body" : {
      "enable" : 1,
			"https_en": 0,
      "heartbeat" : 5,
      "resend_times" : 3,
      "server_ip" : "192.168.6.90",
      "server_port" : 8082,
      "time_out" : 10
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 开关 | int | 是 | 0：不启用<br>1：启用<br>
https_en | https开关 | int | 是 | 0：不启用<br>1：启用<br> 立方才使用
server_ip | 服务器地址 | string | 是 | 
server_port | 端口 | int | 是 | 
heartbeat | 心跳时间 | int | 是 | 
time_out | 超时时间 | int | 是 | 
resend_times | 重试次数 | int | 是 | 
6.2.3	### 3.设置平台配置
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"set_custom_server_cfg",
    "body" : {
      "enable" : 1,
			"https_en": 0,
      "heartbeat" : 5,
      "resend_times" : 3,
      "server_ip" : "192.168.6.90",
      "server_port" : 8082,
      "time_out" : 10
    }
}
```
- Response
```
{
	"type": "set_custom_server_cfg",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 开关 | int | 是 | 0：不启用<br>1：启用<br>
https_en | https开关 | int | 是 | 0：不启用<br>1：启用<br> 立方才使用
server_ip | 服务器地址 | string | 是 | 
server_port | 端口 | int | 是 | 
heartbeat | 心跳时间 | int | 是 | 
time_out | 超时时间 | int | 是 | 
resend_times | 重试次数 | int | 是 | 
6.2.4	### 4.获取立方用户数据
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"get_usr_data"
}
```
- Response
```
{
	"type": "get_usr_data",
	"state":200,
	"err_msg":"All Done",
	"body" : {
        "sn":"RF_50_0000001",
        "secret_key":"25B1CA679B7C2283"
    }
}
```
- 参数释义
- 定制的用户数据，消息都为同一条，不同定制协议body内容不同

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
sn | 设备序列号 | string | 是 | 
secret_key | 加密数据 | string | 是 | 
6.2.5	### 5.设置立方用户数据
- Request
```
{
    "module":"DP_CUSTOM_CFG_REQ",
    "type":"set_usr_data",
    "body" : {
        "sn":"RF_50_0000001",
        "secret_key":"25B1CA679B7C2283"
    }
}
```
- Response
```
{
	"type": "set_usr_data",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
sn | 设备序列号 | string | 是 | 
secret_key | 加密数据 | string | 是 | 

6.2.6	### 6.获取定制版本列表
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_platform_prop",
    "body" : {
      "custom_list": [
          {
            "platform_name": "",
            "lib_name": ""
          },
          {
            "platform_name": "lifang",
            "lib_name": "libcustom_lifang.so"
          },
          {
            "platform_name": "songli",
            "lib_name": "libcustom_songli.so"
          }
      ]
    }
}
```
- Response
```
{
	"type": "get_platform_prop",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
custom_list | 平台列表 | array | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 
6.2.7	### 7.获取当前定制协议
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_platform"
}
```
- Response
```
{
	"type": "get_platform_prop",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
        "platform_name": "songli",
        "lib_name": "libcustom_songli.so"
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 
6.2.8	### 8.设置定制协议
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_platform",
	"body" : {
        "platform_name": "songli",
        "lib_name": "libcustom_songli.so"
    }
}
```
- Response
```
{
	"type": "set_platform",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
platform_name | 平台名称 | string | 是 | 可以选择为""，表示不启用定制协议
lib_name | 协议库 | string | 是 | 

6.3 ## 漳州配置
6.3.1	### 1.获取漳州协议配置
- Request
```
{
    "module": "DP_CUSTOM_CFG_REQ",
    "type": "get_zhangzhou_cfg"
}
```
- Response
```
{
	"type": "get_zhangzhou_cfg",
	"state":200,
	"err_msg":"All Done",
	"body": {
	    "enable" : 1,
        "appid": "88888888",
        "secret": "abcdefgh12345678",
        "server_ip" : "192.168.1.106",
        "server_port" : 8080,
        "resend_times" : 5,
        "heartbeat": 30
	}
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 开关 | int | 是 | 0：不启用<br>1：启用<br>
appid | appId | string | 是 | 8 位字符串，第三方用户唯一凭证，产品决定网页是否要显示*
secret | appSecret | string | 是 | 16 位字符串，第三方用户唯一凭证密钥，产品决定网页是否要显示*
server_ip | 域名 | string | 是 | 
server_port | 端口 | int(0, 65535] | 是 | 
resend_times | 重试次数 | int | 是 | 
heartbeat | 心跳 | int[5, 300] | 是 |
6.3.2	### 2.设置漳州协议配置
- Request
```
{
    "module": "DP_CUSTOM_CFG_REQ",
    "type": "set_zhangzhou_cfg",
	"body": {
	    "enable" : 1,
        "appid": "88888888",
        "secret": "abcdefgh12345678",
        "server_ip" : "192.168.1.106",
        "server_port" : 8080,
        "resend_times" : 5,
        "heartbeat": 30
	}
}
```
- Response
```
{
	"type": "set_zhangzhou_cfg",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 开关 | int | 是 | 0：不启用<br>1：启用<br>
appid | appId | string | 是 | 8 位字符串，第三方用户唯一凭证，产品决定网页是否要显示*
secret | appSecret | string | 是 | 16 位字符串，第三方用户唯一凭证密钥，产品决定网页是否要显示*
server_ip | 域名 | string | 是 | 
server_port | 端口 | int(0, 65535] | 是 | 
resend_times | 重试次数 | int | 是 | 
heartbeat | 心跳 | int[5, 300] | 是 |


7 # H alg模块协议
7.1 ## 车位配置
7.1.1	### 1.获取停车场编号
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_parking_identifier",
    "chnlid":0
}
```
- Response
```
{
	"type": "get_alg_parking_identifier",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "identifier":"MTEw"
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
identifier | 停车场编号 | string | 是 | utf8 + base64编码
7.1.2	### 2.设置停车场编号
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_parking_identifier",
    "body": {
        "identifier":"MTEw"
    }
}
```
- Response
```
{
	"type": "set_alg_parking_identifier",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
identifier | 停车场编号 | string | 是 | utf8 + base64编码 
7.1.3	### 3.获取车位模式属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_park_mode_prop"
}
```
- Response
```
{
	"type": "get_alg_park_mode_prop",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "modes": [
            {
                "mode": 0,
                "content": "5bmz6KGM6L2m5L2N"
            },
            {
                "mode": 1,
                "content": "5Z6C55u06L2m5L2N"
            },
            {
                "mode": 2,
                "content": "5pac5ZCR6L2m5L2N"
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
modes | 车位模式选项 | array | 是 | 
mode | 车位模式 | int | 是 | 
content | 描述 | int | 是 | utf8 + base64编码 
7.1.4	### 4.获取车位模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_park_mode_prm"
}
```
- Response
```
{
	"type": "get_alg_park_mode_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "mode": 0,
        "park_num": 3
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 车位模式 | int | 是 | 0：一字型车位<br> 1：垂直车位<br> 2：斜向车位<br>
park_num | 支持车位数量 | int | 否 | 
7.1.5	### 5.设置车位模式
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_park_mode_prm",
    "body": {
        "mode": 0,
        "park_num": 3
    }
}
```
- Response
```
{
	"type": "set_alg_park_mode_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
mode | 车位模式 | int | 是 | 0：一字型车位<br> 1：垂直车位<br> 2：斜向车位<br>
park_num | 支持车位数量 | int | 否 | 
7.1.6	### 6.获取车位配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_rule_param",
}
```
- Response
```
{
	"type": "get_alg_road_rule_param",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "road_rule_param": {
            "deploy_zone_rule": [
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 1128,
                            "y": 292
                        },
                        {
                            "x": 1678,
                            "y": 292
                        },
                        {
                            "x": 1678,
                            "y": 1730
                        },
                        {
                            "x": 1128,
                            "y": 1730
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 0,
                    "zone_name": "6L2m6YGT5biD6Ziy57q/5ZyI",
                    "zone_type": 2
                }
            ],
            "deploy_zone_rule_num": 1,
            "reco_zone_rule": [
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 1460
                        },
                        {
                            "x": 876,
                            "y": 1460
                        },
                        {
                            "x": 876,
                            "y": 1730
                        },
                        {
                            "x": 584,
                            "y": 1730
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 0,
                    "zone_name": "UEFSSzAwMDE=",
                    "zone_type": 1
                },
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 1168
                        },
                        {
                            "x": 876,
                            "y": 1168
                        },
                        {
                            "x": 876,
                            "y": 1438
                        },
                        {
                            "x": 584,
                            "y": 1438
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 1,
                    "zone_name": "UEFSSzAwMDI=",
                    "zone_type": 1
                },
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 876
                        },
                        {
                            "x": 876,
                            "y": 876
                        },
                        {
                            "x": 876,
                            "y": 1146
                        },
                        {
                            "x": 584,
                            "y": 1146
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 2,
                    "zone_name": "UEFSSzAwMDM=",
                    "zone_type": 1
                },
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 584,
                            "y": 584
                        },
                        {
                            "x": 876,
                            "y": 584
                        },
                        {
                            "x": 876,
                            "y": 854
                        },
                        {
                            "x": 584,
                            "y": 854
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 3,
                    "zone_name": "UEFSSzAwMDQ=",
                    "zone_type": 1
                },
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 584,
                            "y": 292
                        },
                        {
                            "x": 876,
                            "y": 292
                        },
                        {
                            "x": 876,
                            "y": 562
                        },
                        {
                            "x": 584,
                            "y": 562
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 4,
                    "zone_name": "UEFSSzAwMDU=",
                    "zone_type": 1
                }
            ],
            "reco_zone_rule_num": 5,
            "reco_zone_size_factor": {
                "factor_h": 2048,
                "factor_w": 2048
            }
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
road_rule_param | 线圈规则参数 | int | 是 | 
deploy_zone_rule | 车道布防线圈 | array | 是 | 
enable | 启用使能 | int[0, 1] | 是 | 0：不启用<br> 1：启用
point | 点 | array | 是 | 
x | 横坐标 | int | 是 | 
y | 纵坐标 | int | 是 | 
point_num | 点数量 | int | 否 | 
zone_id | 线圈id | int | 是 | 
zone_name | 线圈名称 | string | 是 | utf8 + base64编码 
zone_type | 线圈类型 | int | 是 | 1：车位线圈<br> 2：布防线圈
deploy_zone_rule_num | 布防线圈数量 | int | 是 | 
reco_zone_rule | 车位线圈规则 | array | 是 | 
reco_zone_rule_num | 车位线圈数量 | int | 是 | 
reco_zone_size_factor | 坐标对应分辨率 | object | 是 | 
factor_w | 宽 | int | 是 | 
factor_h | 高 | int | 是 | 
7.1.7	### 7.设置车位配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_road_rule_param",
    "body": {
        "road_rule_param": {
            "deploy_zone_rule": [
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 1128,
                            "y": 292
                        },
                        {
                            "x": 1678,
                            "y": 292
                        },
                        {
                            "x": 1678,
                            "y": 1730
                        },
                        {
                            "x": 1128,
                            "y": 1730
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 0,
                    "zone_name": "6L2m6YGT5biD6Ziy57q/5ZyI",
                    "zone_type": 2
                }
            ],
            "deploy_zone_rule_num": 1,
            "reco_zone_rule": [
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 1460
                        },
                        {
                            "x": 876,
                            "y": 1460
                        },
                        {
                            "x": 876,
                            "y": 1730
                        },
                        {
                            "x": 584,
                            "y": 1730
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 0,
                    "zone_name": "UEFSSzAwMDE=",
                    "zone_type": 1
                },
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 1168
                        },
                        {
                            "x": 876,
                            "y": 1168
                        },
                        {
                            "x": 876,
                            "y": 1438
                        },
                        {
                            "x": 584,
                            "y": 1438
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 1,
                    "zone_name": "UEFSSzAwMDI=",
                    "zone_type": 1
                },
                {
                    "enable": 1,
                    "point": [
                        {
                            "x": 584,
                            "y": 876
                        },
                        {
                            "x": 876,
                            "y": 876
                        },
                        {
                            "x": 876,
                            "y": 1146
                        },
                        {
                            "x": 584,
                            "y": 1146
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 2,
                    "zone_name": "UEFSSzAwMDM=",
                    "zone_type": 1
                },
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 584,
                            "y": 584
                        },
                        {
                            "x": 876,
                            "y": 584
                        },
                        {
                            "x": 876,
                            "y": 854
                        },
                        {
                            "x": 584,
                            "y": 854
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 3,
                    "zone_name": "UEFSSzAwMDQ=",
                    "zone_type": 1
                },
                {
                    "enable": 0,
                    "point": [
                        {
                            "x": 584,
                            "y": 292
                        },
                        {
                            "x": 876,
                            "y": 292
                        },
                        {
                            "x": 876,
                            "y": 562
                        },
                        {
                            "x": 584,
                            "y": 562
                        }
                    ],
                    "point_num": 4,
                    "zone_id": 4,
                    "zone_name": "UEFSSzAwMDU=",
                    "zone_type": 1
                }
            ],
            "reco_zone_rule_num": 5,
            "reco_zone_size_factor": {
                "factor_h": 2048,
                "factor_w": 2048
            }
        }
    }
}
```
- Response
```
{
	"type": "set_alg_road_rule_param",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
road_rule_param | 线圈规则参数 | int | 是 | 
deploy_zone_rule | 车道布防线圈 | array | 是 | 
enable | 启用使能 | int[0, 1] | 是 | 0：不启用<br> 1：启用
point | 点 | array | 是 | 
x | 横坐标 | int | 是 | 
y | 纵坐标 | int | 是 | 
point_num | 点数量 | int | 否 | 
zone_id | 线圈id | int | 是 | 
zone_name | 线圈名称 | string | 是 | utf8 + base64编码 
zone_type | 线圈类型 | int | 是 | 1：车位线圈<br> 2：布防线圈
deploy_zone_rule_num | 布防线圈数量 | int | 是 | 
reco_zone_rule | 车位线圈规则 | array | 是 | 
reco_zone_rule_num | 车位线圈数量 | int | 是 | 
reco_zone_size_factor | 坐标对应分辨率 | object | 是 | 
factor_w | 宽 | int | 是 | 
factor_h | 高 | int | 是 | 
7.2 ## 识别配置
7.2.1	### 1.获取基础识别设置属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_reco_prop",
    "chnlid":0
}
```
- Response
```
{
	"type": "get_alg_road_reco_prop",
	"state":200,
	"err_msg":"All Done",
	"body": {
        "default_initial": {
            "default": 26,
            "types": [
                {
                    "content": "A",
                    "type": 0
                },
                {
                    "content": "B",
                    "type": 1
                },
                {
                    "content": "C",
                    "type": 2
                },
                {
                    "content": "D",
                    "type": 3
                },
                {
                    "content": "E",
                    "type": 4
                },
                {
                    "content": "F",
                    "type": 5
                },
                {
                    "content": "G",
                    "type": 6
                },
                {
                    "content": "H",
                    "type": 7
                },
                {
                    "content": "I",
                    "type": 8
                },
                {
                    "content": "J",
                    "type": 9
                },
                {
                    "content": "K",
                    "type": 10
                },
                {
                    "content": "L",
                    "type": 11
                },
                {
                    "content": "M",
                    "type": 12
                },
                {
                    "content": "N",
                    "type": 13
                },
                {
                    "content": "O",
                    "type": 14
                },
                {
                    "content": "P",
                    "type": 15
                },
                {
                    "content": "Q",
                    "type": 16
                },
                {
                    "content": "R",
                    "type": 17
                },
                {
                    "content": "S",
                    "type": 18
                },
                {
                    "content": "T",
                    "type": 19
                },
                {
                    "content": "U",
                    "type": 20
                },
                {
                    "content": "V",
                    "type": 21
                },
                {
                    "content": "W",
                    "type": 22
                },
                {
                    "content": "X",
                    "type": 23
                },
                {
                    "content": "Y",
                    "type": 24
                },
                {
                    "content": "Z",
                    "type": 25
                },
                {
                    "content": "无",
                    "type": 26
                }
            ]
        },
        "province": {
            "default": 255,
            "types": [
                {
                    "content": "5Lqs",
                    "type": 0
                },
                {
                    "content": "5rSl",
                    "type": 1
                },
                {
                    "content": "5YaA",
                    "type": 2
                },
                {
                    "content": "5pmL",
                    "type": 3
                },
                {
                    "content": "6JKZ",
                    "type": 4
                },
                {
                    "content": "6L69",
                    "type": 5
                },
                {
                    "content": "5ZCJ",
                    "type": 6
                },
                {
                    "content": "6buR",
                    "type": 7
                },
                {
                    "content": "5rKq",
                    "type": 8
                },
                {
                    "content": "6IuP",
                    "type": 9
                },
                {
                    "content": "5rWZ",
                    "type": 10
                },
                {
                    "content": "55qW",
                    "type": 11
                },
                {
                    "content": "6Ze9",
                    "type": 12
                },
                {
                    "content": "6LWj",
                    "type": 13
                },
                {
                    "content": "6bKB",
                    "type": 14
                },
                {
                    "content": "6LGr",
                    "type": 15
                },
                {
                    "content": "6YSC",
                    "type": 16
                },
                {
                    "content": "5rmY",
                    "type": 17
                },
                {
                    "content": "57Kk",
                    "type": 18
                },
                {
                    "content": "5qGC",
                    "type": 19
                },
                {
                    "content": "55C8",
                    "type": 20
                },
                {
                    "content": "5rid",
                    "type": 21
                },
                {
                    "content": "5bed",
                    "type": 22
                },
                {
                    "content": "6LS1",
                    "type": 23
                },
                {
                    "content": "5LqR",
                    "type": 24
                },
                {
                    "content": "6JeP",
                    "type": 25
                },
                {
                    "content": "6ZmV",
                    "type": 26
                },
                {
                    "content": "55SY",
                    "type": 27
                },
                {
                    "content": "6Z2S",
                    "type": 28
                },
                {
                    "content": "5a6B",
                    "type": 29
                },
                {
                    "content": "5paw",
                    "type": 30
                },
                {
                    "content": "5riv",
                    "type": 31
                },
                {
                    "content": "5r6z",
                    "type": 32
                },
                {
                    "content": "5Y+w",
                    "type": 33
                },
                {
                    "content": "6K2m",
                    "type": 34
                },
                {
                    "content": "5L2/",
                    "type": 35
                },
                {
                    "content": "V0o=",
                    "type": 36
                },
                {
                    "content": "6aKG",
                    "type": 37
                },
                {
                    "content": "5a2m",
                    "type": 38
                },
                {
                    "content": "5peg",
                    "type": 255
                }
            ]
        },
        "recognition_pixel": {
            "default_max": 600,
            "default_min": 80,
            "max": 600,
            "min": 80
        },
        "recognition_type": {
            "default": -2147483621,
            "types": [
                {
                    "content": "6JOd54mM",
                    "type": 1
                },
                {
                    "content": "6buE54mM",
                    "type": 2
                },
                {
                    "content": "6buR54mM",
                    "type": 4
                },
                {
                    "content": "5paw6IO95rqQ",
                    "type": 8
                },
                {
                    "content": "5pWZ57uD6L2m",
                    "type": 16
                },
                {
                    "content": "6K2m6L2m",
                    "type": 32
                },
                {
                    "content": "5q2m6K2m6L2m",
                    "type": 64
                },
                {
                    "content": "5Yab6L2m",
                    "type": 128
                },
                {
                    "content": "5riv5r6z",
                    "type": 256
                },
                {
                    "content": "5L2/6aaG6L2m",
                    "type": 512
                },
                {
                    "content": "6aKG6aaG6L2m",
                    "type": 1024
                },
                {
                    "content": "5rCR6Iiq",
                    "type": 2048
                },
                {
                    "content": "5bqU5oCl",
                    "type": 4096
                }
            ]
        },
        "snap_image_quality": {
            "default": 70,
            "max": 100,
            "min": 10
        },
        "snap_resolution": {
            "default": 10,
            "types": [
                {
                    "content": "640*360",
                    "type": 3
                },
                {
                    "content": "704*576",
                    "type": 5
                },
                {
                    "content": "1280*720",
                    "type": 9
                },
                {
                    "content": "1920*1080",
                    "type": 10
                },
                {
                    "content": "3840*2160",
                    "type": 13
                },
                {
                    "content": "2160*3840",
                    "type": 14
                },
                {
                    "content": "2688*1512",
                    "type": 20
                },
                {
                    "content": "1512*2688",
                    "type": 21
                }
            ]
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chnlid | 通道id | int | 否 | 
default_initial | 默认首字母 | object | 是 | 
default | 默认值 | int | 是 | 
types | 下拉选项 | array | 是 | 
content | 描述 | string | 是 | 默认首字母时为普通英文字符串，其余都是utf8 + base64编码
type | 选项 | int | 是 | 
province | 默认省份 | object | 是 | 
recognition_pixel | 车牌像素限制(px) | object | 是 | 
default_max | 默认最大值 | int | 是 | 
default_min | 默认最小值 | int | 是 | 
max | 最大值 | int | 是 | 
min | 最小值 | int | 是 | 
recognition_type | 识别类型 | object | 是 | 
snap_image_quality | 抓图质量 | object | 是 | 
snap_resolution | 抓图分辨率 | object | 是 | 
7.2.2	### 2.获取基础识别设置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_reco_param",
    "chnlid":0
}
```
- Response
```
{
	"type": "get_alg_road_reco_param",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "default_initial": 26,
        "default_province": 255,
        "recognition_pixel": {
            "max": 600,
            "min": 80
        },
        "recognition_type": -2139086849
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
default_initial | 默认首字母 | int | 是 | 
default_province | 默认省份 | int | 是 | 
recognition_pixel | 车牌像素限制(px) | object | 是 | 
max | 最大值 | int | 是 | 
min | 最小值 | int | 是 | 
recognition_type | 识别类型 | int | 是 | 
7.2.3	### 3.设置基础识别设置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_road_reco_param",
    "chnlid": 0,
    "body": {
        "default_initial": 26,
        "default_province": 255,
        "recognition_pixel": {
            "max": 600,
            "min": 80
        },
        "recognition_type": -2139086849
    }
}
```
- Response
```
{
	"type": "set_alg_road_reco_param",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
default_initial | 默认首字母 | int | 是 | 
default_province | 默认省份 | int | 是 | 
recognition_pixel | 车牌像素限制(px) | int[80, 600] | 是 | 
max | 最大值 | int | 是 | 
min | 最小值 | int | 是 | 
recognition_type | 识别类型 | int | 是 | 
7.2.4	### 4.获取高级识别设置属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_senior_reco_prop"
}
```
- Response
```
{
    "type": "get_alg_senior_reco_prop",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "cardetect": {
            "car_width": {
                "max": 640,
                "min": 80
            }
        },
        "coil": {
            "outspread": {
                "max": 50,
                "min": 0
            },
            "sensitivity": {
                "default": 0,
                "max": 100,
                "min": 0
            }
        },
        "pic_select": {
            "empty_time": {
                "max": 300,
                "min": 5
            },
            "in_time": {
                "max": 600,
                "min": 60
            },
            "on_time": {
                "max": 300,
                "min": 5
            },
            "out_time": {
                "max": 600,
                "min": 60
            }
        },
        "plate": {
            "confidence": {
                "max": 100,
                "min": 32
            },
            "max_number": {
                "max": 10,
                "min": 1
            }
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 | 
car_width | 目标最小宽度 | object | 是 | 
max | 最大值 | int | 是 | 
min | 最小值 | int | 是 | 
coil | 线圈参数 | object | 是 | 
outspread | 向外范围 | object | 否 | 
sensitivity | 边缘线灵敏度 | object | 是 | 
pic_select | 选图参数 | object | 是 | 
in_time | 入场时间阀值(s) | object | 是 | 
on_time | 入停稳时间阀值(s) | object | 否 | 
out_time | 出场时间阀值(s) | object | 是 | 
empty_time | 空闲时间阀值(s) | object | 否 | 
plate | 车牌参数 | object | 是 | 
confidence | 车牌置信度阀值 | object | 是 | 
max_number | 最大车牌数 | object | 是 | 
7.2.5	### 5.获取高级识别设置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_senior_reco_prm"
}
```
- Response
```
{
    "type": "get_alg_senior_reco_prm",
    "state": 200,
    "err_msg": "All Done",
    "body": {
        "cardetect": {
            "min_width": 173
        },
        "coil": {
            "sensitivity": 0
        },
        "pic_select": {
            "in_time": 71,
            "out_time": 60
        },
        "plate": {
            "confidence": 80,
            "max_number": 4
        }
    }
}
```
- 参数释

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 | 
car_width | 目标最小宽度 | int[80, 640] | 是 | 
coil | 线圈参数 | object | 是 | 
sensitivity | 边缘线灵敏度 | int[0, 100] | 是 | 
pic_select | 选图参数 | object | 是 | 
in_time | 入场时间阀值(s) | int[60, 600] | 是 | 
out_time | 出场时间阀值(s) | int[60, 600] | 是 | 
plate | 车牌参数 | object | 是 | 
confidence | 车牌置信度阀值 | int[32, 100] | 是 | 
max_number | 最大车牌数 | int[1, 10] | 是 | 
7.2.6	### 6.设置取高级识别设置
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_senior_reco_prm",
    "chnlid":0,
    "body": {
        "cardetect": {
            "min_width": 173
        },
        "coil": {
            "sensitivity": 0
        },
        "pic_select": {
            "in_time": 71,
            "out_time": 60
        },
        "plate": {
            "confidence": 80,
            "max_number": 4
        }
    }
}
```
- Response
```
{
	"type": "set_alg_senior_reco_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
cardetect | 车检参数 | object | 是 | 
car_width | 目标最小宽度 | int[80, 640] | 是 | 
coil | 线圈参数 | object | 是 | 
sensitivity | 边缘线灵敏度 | int[0, 100] | 是 | 
pic_select | 选图参数 | object | 是 | 
in_time | 入场时间阀值(s) | int[60, 600] | 是 | 
out_time | 出场时间阀值(s) | int[60, 600] | 是 | 
plate | 车牌参数 | object | 是 | 
confidence | 车牌置信度阀值 | int[32, 100] | 是 | 
max_number | 最大车牌数 | int[1, 10] | 是 | 
7.3 ## 图片配置
7.3.1	### 1.获取图片抓拍属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_snap_prop"
}
```
- Response
```
{
	"type": "get_alg_road_snap_prop",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "pic_file_size": {
            "default": 800,
            "enable": true,
            "max": 2048,
            "min": 128
        },
        "pic_quality": {
            "default": 90,
            "enable": true,
            "max": 100,
            "min": 1
        },
        "pic_resolution": {
            "default": 20,
            "enable": true,
            "types": [
                {
                    "content": "640*360",
                    "type": 3
                },
                {
                    "content": "704*576",
                    "type": 5
                },
                {
                    "content": "1280*720",
                    "type": 9
                },
                {
                    "content": "1920*1080",
                    "type": 10
                },
                {
                    "content": "2688*1512",
                    "type": 20
                }
            ]
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
pic_file_size | 图片大小限制(kb) | object | 是 | 
default | 默认值 | int | 是 | 
enable | 使能 | bool | 是 |  false：不启用<br> true：启用
min | 最小值 | int | 是 | 
max | 最大值 | int | 是 | 
pic_quality | 图片质量 | object | 否 | 
pic_resolution | 图片分辨率 | object | 是 | 
types | 分辨率选项 | array | 是 | 
content | 分辨率描述 | string | 是 | 
7.3.2	### 2.获取图片抓拍
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_road_snap_prm"
}
```
- Response
```
{
	"type": "get_alg_road_snap_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "channel": [
            {
                "chan_id": 0,
                "pic_file_size": 800,
                "pic_resolution": 20
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
channel | 通道 | array | 是 | 
chan_id | 通道id | int | 是 | 
pic_file_size  | 图片大小限制(kb) | int | 是 | 
pic_resolution  | 图片分辨率 | int | 是 | 
7.3.3	### 3.设置图片抓拍
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_road_snap_prm",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "pic_file_size": 800,
                "pic_resolution": 20
            }
        ]
    }
}
```
- Response
```
{
	"type": "set_alg_road_snap_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
channel | 通道 | array | 是 | 
chan_id | 通道id | int | 是 | 
pic_file_size  | 图片大小限制(kb) | int | 是 | 
pic_resolution  | 图片分辨率 | int | 是 | 
7.3.4	### 4.获取图片合成配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_prm"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "enable": 0,
        "merge_mode": 0,
        "merge_type": 1,
        "resolution": 9
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：不启用<br> 1：启用
merge_mode | 合成样式 | int[0, 3] | 是 |  0：田字格1<br> 1：一字型1<br> 2：田字格2<br> 3：一字型2
merge_type  | 抓拍数量 | int[0, 2] | 是 | 0：2张<br> 1：3张<br> 2：4张
resolution  | 车辆特写图分辨率 | int | 是 | 和抓图配置的分辨率选项保持一致
7.3.5	### 5.设置图片合成配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_pic_merge_prm",
    "body": {
        "enable": 0,
        "merge_mode": 0,
        "merge_type": 1,
        "resolution": 9
    }
}
```
- Response
```
{
	"type": "set_alg_pic_merge_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
enable | 使能 | int | 是 | 0：不启用<br> 1：启用
merge_mode | 合成样式 | int[0, 3] | 是 |  0：田字格1<br> 1：一字型1<br> 2：田字格2<br> 3：一字型2
merge_type  | 抓拍数量 | int[0, 2] | 是 | 0：2张<br> 1：3张<br> 2：4张
resolution  | 车辆特写图分辨率 | int | 是 | 和抓图配置的分辨率选项保持一致
7.3.6	### 6.获单张图OSD属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_reco_osd_prop"
}
```
- Response
```
{
	"type": "get_alg_reco_osd_prop",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "carplate_format": {
            "default": 31,
            "enable": true,
            "types": [
                {
                    "content": "6L2m54mM5Y+356CB",
                    "type": 1
                },
                {
                    "content": "6L2m54mM57G75Z6L",
                    "type": 2
                },
                {
                    "content": "6L2m5L2N5ZCN56ew",
                    "type": 4
                },
                {
                    "content": "5YGc6L2m54q25oCB",
                    "type": 8
                },
                {
                    "content": "5YGc6L2m5pa55ZCR",
                    "type": 16
                },
                {
                    "content": "572u5L+h5bqm",
                    "type": 32
                },
                {
                    "content": "6L2m54mM5YOP57Sg",
                    "type": 64
                },
                {
                    "content": "6L2m5Z6LL+i9puasvi/ovabmoIc=",
                    "type": 128
                },
                {
                    "content": "5oql6K2m57G75Z6L",
                    "type": 256
                }
            ]
        },
        "color": {
            "default": 0,
            "enable": true,
            "types": [
                {
                    "content": "55m96Imy",
                    "type": 0
                },
                {
                    "content": "57qi6Imy",
                    "type": 1
                },
                {
                    "content": "6JOd6Imy",
                    "type": 2
                },
                {
                    "content": "57u/6Imy",
                    "type": 3
                }
            ]
        },
        "date_format": {
            "default": 0,
            "enable": true,
            "types": [
                {
                    "content": "WVlZWU1NREQ=",
                    "type": 0
                },
                {
                    "content": "TU1ERFlZWVk=",
                    "type": 1
                },
                {
                    "content": "RERNTVlZWVk=",
                    "type": 2
                }
            ]
        },
        "detect_region": {
            "default": 6,
            "enable": true,
            "types": [
                {
                    "content": "6L2m5L2N57q/5ZyI",
                    "type": 2
                },
                {
                    "content": "6L2m5qOA546w5Ya1",
                    "type": 4
                }
            ]
        },
        "font_size": {
            "default": 3,
            "enable": true,
            "types": [
                {
                    "content": "MTZYMTY=",
                    "type": 0
                },
                {
                    "content": "MjRYMjQ=",
                    "type": 1
                },
                {
                    "content": "MzJYMzI=",
                    "type": 2
                },
                {
                    "content": "NDhYNDg=",
                    "type": 3
                }
            ]
        },
        "osd_pos": {
            "default": 0,
            "enable": true,
            "types": [
                {
                    "content": "5Zu+54mH5aSW5LiK6L6557yY",
                    "type": 0
                },
                {
                    "content": "5Zu+54mH5aSW5LiL6L6557yY",
                    "type": 1
                },
                {
                    "content": "5Zu+54mH5YaF5bem5LiK6KeS",
                    "type": 2
                },
                {
                    "content": "5Zu+54mH5YaF5bem5LiL6KeS",
                    "type": 3
                },
                {
                    "content": "5Zu+54mH5YaF5Y+z5LiK6KeS",
                    "type": 4
                },
                {
                    "content": "5Zu+54mH5YaF5Y+z5LiL6KeS",
                    "type": 5
                }
            ]
        },
        "time_format": {
            "default": 1,
            "enable": true,
            "types": [
                {
                    "content": "MTLlsI/ml7Y=",
                    "type": 0
                },
                {
                    "content": "MjTlsI/ml7Y=",
                    "type": 1
                }
            ]
        }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
carplate_format | 算法检测参数 | object | 是 | 
default | 默认值 | int | 是 | 
enable | 使能 | bool | 是 | false：不启用<br> true：启用
types | 选项集 | array | 是 | 
content | 描述 | string | 是 | utf8 + base64编码 
type | 选项 | int | 是 | 
color | OSD颜色 | object | 是 | 
date_format | 日期格式 | object | 是 | 
detect_region | 叠加线圈线框 | object | 是 | 
font_size | OSD字体 | object | 是 | 
osd_pos | OSD位置 | object | 是 | 
time_format | 时间格式 | object | 是 | 
7.3.7	### 7.获取单张图OSD
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_reco_osd_prm"
}
```
- Response
```
{
	"type": "get_alg_reco_osd_prm",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "channel": [
            {
                "chan_id": 0,
                "osd_param": {
                    "align": 11,
                    "carplate": {
                        "carplate_format": 7,
                        "enable": 1,
                        "pos": 655408
                    },
                    "color": 0,
                    "date": {
                        "date_format": 0,
                        "enable": 1,
                        "pos": 0
                    },
                    "datetime": {
                        "enable": 1,
                        "pos": 10420224,
                        "time_format": 1
                    },
                    "detect_region": 6,
                    "font_size": 3,
                    "osd_pos": 0,
                    "usr_text": [
                        {
                            "context": "b3Nk",
                            "enable": 0,
                            "pos": 100
                        }
                    ]
                }
            }
        ]
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
channel | 通道 | array | 是 | 
chan_id | 通道id | int | 是 | 
osd_param  | OSD参数 | object | 是 | 
align | 叠加格式 | int | 是 | 
carplate | 算法识别参数 | object | 是 | 
carplate_format | 算法识别参数 | int | 是 | 或的集
enable | 使能 | int | 是 | 0：不启用<br> 1：启用
pos | 位置 | int | 是 | 
color | OSD颜色 | int | 是 | 
date | 日期 | object | 是 | 
date_format | 日期格式 | int | 是 | 
datetime | 时间 | object | 是 | 
time_format | 时间格式 | int | 是 | 
detect_region | 线圈线框叠加 | int | 是 | 
font_size | OSD字体 | int | 是 | 
osd_pos | OSD位置 | int | 是 | 
usr_text | 自定义OSD | array | 是 | 
7.3.8	### 8.设置单张图OSD
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_reco_osd_prm",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "osd_param": {
                    "osd_pos": 0,
                    "date": {
                        "enable": 1,
                        "pos": 0,
                        "date_format": 0
                    },
                    "datetime": {
                        "enable": 1,
                        "pos": 10420224,
                        "time_format": 1
                    },
                    "carplate": {
                        "carplate_format": 7,
                        "enable": 1,
                        "pos": 655408
                    },
                    "usr_text": [
                        {
                            "enable": 0,
                            "context": "b3Nk",
                            "pos": 100
                        }
                    ],
                    "font_size": 3,
                    "color": 0,
                    "align": 11,
                    "detect_region": 6
                }
            }
        ]
    }
}
```
- Response
```
{
	"type": "set_alg_reco_osd_prm",
	"state":200,
	"err_msg":"All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
channel | 通道 | array | 是 | 
chan_id | 通道id | int | 是 | 
osd_param  | OSD参数 | object | 是 | 
align | 叠加格式 | int | 是 | 
carplate | 算法识别参数 | object | 是 | 
carplate_format | 算法识别参数 | int | 是 | 或的集
enable | 使能 | int | 是 | 0：不启用<br> 1：启用
pos | 位置 | int | 是 | 
color | OSD颜色 | int | 是 | 0：白色，1：红色，2：蓝色，3：绿色
date | 日期 | object | 是 | 
date_format | 日期格式 | int | 是 | 0：YYYYMMDD，1：MMDDYYYY，2：DDMMYYYY
datetime | 时间 | object | 是 | 
time_format | 时间格式 | int | 是 | 0：12小时，1：24小时
detect_region | 线圈线框叠加 | int | 是 | 0：都不选，2：泊位线圈，4：车检线圈，6：全选
font_size | OSD字体 | int | 是 | 0：16*16，1：24*24，2：32*32，3：48*48，4：64*64，5：96*96，6：128*128
osd_pos | OSD位置 | int | 是 | 0：图片外上边缘，1：图片外下边缘，2：图片内左上角，3：图片内左下角，4：图片内右上角，5：图片内右下角
usr_text | 自定义OSD | array | 是 | 
7.3.9	### 9.获取合成图片OSD叠加参数属性
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_osd_prop"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_osd_prop",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
      "position": {
            "default": 0,
            "types": [
                {
                    "content": "5Zyo5Zu+54mH5LiK6L6557yY5aSW5Y+g5Yqg5a2X56ym",
                    "type": 0
                },{
                    "content": "5Zyo5Zu+54mH5LiL6L6557yY5aSW5Y+g5Yqg5a2X56ym",
                    "type": 1
                }
            ]
      },
      "date_format": {
            "default": 0,
            "enable": 1,
            "types": [
                {
                    "content": "WVlZWU1NREQ=",
                    "type": 0
                },{
                    "content": "TU1ERFlZWVk=",
                    "type": 1
                },{
                    "content": "RERNTVlZWVk=",
                    "type": 2
                }
            ]
      },
      "time_format": {
            "default": 1,
            "enable": 1,
            "types": [
                {
                    "content": "MTLlsI/ml7Y=",
                    "type": 0
                },{
                    "content": "MjTlsI/ml7Y=",
                    "type": 1
                }
            ]
      },
      "carplate_format": {
            "default": 39,
            "types": [
                {
                    "content": "6L2m54mM5Y+356CB", 
                    "type": 1
                },{
                    "content": "6L2m54mM57G75Z6L", 
                    "type": 2
                },{
                    "content": "5rOK5L2N5Y+3", 
                    "type": 4
                },{
                    "content": "5YGc6L2m54q25oCB", 
                    "type": 8
                },{
                    "content": "5YGc6L2m5pa55ZCR", 
                    "type": 16
                },{
                    "content": "6L2m54mM572u5L+h5bqm", 
                    "type": 32
                },{
                    "content": "6L2m54mM5YOP57Sg", 
                    "type": 64
                },{
                    "content": "6L2m5Z6LL+i9puasvi/ovabmoIc=", 
                    "type": 128
                }
            ]
      }
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date_format | 日期格式 | object | 是 | 
time_format | 时间格式 | object | 是 | 
carplate_format | 车辆/车牌信息格式 | object | 是 | 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
default | 默认值 | int | 是 | 
enable | 是否启用 | int | 是 | 
content | 对应类型的描述 | string | 是 | utf8 + base64
type | 对应类型的ID | int | 是 | 
7.3.10	### 10.获取合成图片OSD配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_alg_pic_merge_osd"
}
```
- Response
```
{
	"type": "get_alg_pic_merge_osd",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
      "position": 0,
      "date": {
            "enable": 1,
            "date_format": 0
      },
      "time": {
            "enable": 1,
            "time_format": 1
      },
      "carplate_format": 39
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date | 日期格式 | object | 是 | 
enable | 是否启用 | int | 是 |
date_format | 日期格式 | int | 是 | 
time | 时间格式 | object | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆/车牌信息格式 | int | 是 | 0：都不启用<br> 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
7.3.11	### 11.设置合成图片OSD配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_alg_pic_merge_osd",
    "body" : {
      "position": 0,
      "date": {
            "enable": 1,
            "date_format": 0
      },
      "time": {
            "enable": 1,
            "time_format": 1
      },
      "carplate_format": 39
    }
}
```
- Response
```
{
	"type": "set_alg_pic_merge_osd",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
position | OSD叠加位置 | int | 是 | 0：在图片上边缘外叠加字符<br> 1：在图片下边缘外叠加字符<br>
date | 日期格式 | object | 是 | 
enable | 是否启用 | int | 是 |
date_format | 日期格式 | int | 是 | 
time | 时间格式 | object | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆/车牌信息格式 | int | 是 | 0：都不启用<br> 1：车牌号码<br>2：车牌类型<br>4：泊位号<br>8：停车状态<br>16：停车方向<br>32：车牌置信度<br>64：车牌像素<br>128：车型/车款/车标
7.3.12	### 12.获取视频叠加检测框配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"get_realtime_display_prm"
}
```
- Response
```
{
	"type": "get_realtime_display_prm",
	"state": 200,
	"err_msg": "All Done",
	"body" : {
        "detect_region": 6
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
detect_region | 线圈线框叠加 | int | 是 | 按位或<br> 0x02:车位线圈<br> 0x04:车检线圈
7.3.13	### 13.设置视频叠加检测框配置
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_realtime_display_prm",
    "body" : {
        "detect_region": 6
    }
}
```
- Response
```
{
	"type": "set_realtime_display_prm",
	"state": 200,
	"err_msg": "All Done"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
detect_region | 线圈线框叠加 | int | 是 | 
7.3.14	### 14.抓拍图片
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"avs_trigger",
    "body" : {
        "trigger_result": 1,
        "trigger_type": 9,
        "trigger_extend": {
            "zone_id": 0,
            "user_data": "...",
            "snap_mode": 0,
            "zone_list": [
                0,
                1,
                2
            ]
        }
    }
}
```
- Response
```
{
	"type": "avs_trigger",
	"state": 200,
	"err_msg": "All Done",
	"body": {
        "file_name": "VzIPCCap/2021_08_17/140940-104_R150994946____无__.jpg",
        "img_len": 802552
    }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
trigger_result | 抓拍结果 | int | 否 | 
trigger_type | 抓拍类型 | ing | 是 | 8：手动抓拍<br> 9：SDK抓拍，会返回路径<br> 13：定时抓拍
trigger_extend | 扩展数据 | object | 否 |
zone_id | 车位id | int | 否 | -1:所有车位<br> 否则是指定车位id，当有zone_list字段时，此字段无意义
user_data | 用户自定义数据 | string | 否 | 最长128字节
snap_mode | 抓拍模式 | int | 否 | 0: 每个车位独立出结果+图片<br>1：出一张图片+一次结果（包含指定的多个车位结果信息）
zone_list | 抓拍车位列表 | array | 否 | 
file_name | 图片共享内存路径 | string | 否 | SDK抓拍时必填
img_len | 图片长度 | int | 否 | SDK抓拍时必填
7.4 ## 报警配置
7.4.1	### H1L获取报警参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_alarm_linkage_prm"
}
```
- Response
```
{
	"body": {
		"trigger_ctrl": {
			"fault": {
				"alarm_time": 0,
				"fault_type": 15,
				"novideo_time": 398
			},
			"occlusion": {
				"alarm_time": 0,
				"occlusion_area": 100,
				"occlusion_time": 387,
				"occlusion_type": 1
			},
			"parking": {
				"alarm_time": 0,
				"car_pos": 1,
				"parking_type": 8
			}
		}
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "get_alarm_linkage_prm"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0x01：镜头遮挡<br>0x02：车牌遮挡<br>0x04：镜头偏移<br>0x08：镜头虚焦
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车<br>0x80：斜向停车
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 
7.4.2	### H1L设置报警参数
- Request
```
{
  "type": "set_alarm_linkage_prm",
  "module": "BUS_REQUEST_MSG",
  "body": {
    "trigger_ctrl": {
      "occlusion": {
        "occlusion_type": 1,
        "occlusion_time": 387,
        "occlusion_area": 100,
        "alarm_time": 0
      },
      "parking": {
        "parking_type": 8,
        "car_pos": 1,
        "alarm_time": 0
      },
      "fault": {
        "fault_type": 15,
        "novideo_time": 398,
        "alarm_time": 0
      }
    }
  }
}
```
- Response
```
{
	"err_msg": "All Done",
	"state": 200,
	"type": "set_alarm_linkage_prm"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
occlusion | 遮挡 | object | 是 | 
parking | 违停 | object | 是 | 
fault | 故障 | object | 是 | 
alarm_time | 间隔报警时间 | int | 是 | 0:不报警；否则为报警时间（单位分钟）
occlusion_type | 遮挡类型 | int | 是 | 0：不勾选 <br>1：勾选<br>
occlusion_time | 触发遮挡报警时间 | int | 是 | 单位秒
occlusion_area | 触发遮挡报警面积 | int(0,100] | 是 | 
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车<br>0x80：斜向停车
car_pos | 车头车位方向 | int | 是 | 1:车尾报警;<br>2:车头报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  1：断网<br>2：心跳超时 <br>4：分区损坏<br>8：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 |
