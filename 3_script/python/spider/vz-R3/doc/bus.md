# 灯控制
## 补光灯
### 1.获取补光灯参数属性
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
  "body": {
    "led_level": {
      "default": 2,
      "max": 4,
      "min": -1,
      "types": [
        {
          "content": "5YWz6Zet",
          "type": -1
        },
        {
          "content": "Muexsw==",
          "type": 0
        },
        {
          "content": "NOexsw==",
          "type": 1
        },
        {
          "content": "Nuexsw==",
          "type": 2
        },
        {
          "content": "N+exsw==",
          "type": 3
        },
        {
          "content": "OOexsw==",
          "type": 4
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
  },
  "err_msg": "All Done",
  "state": 200,
  "type": "get_led_prop"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
types | 补光灯等级 | Array | 是 | -1：关闭<br>0：2米<br>1：4米<br>2：6米<br>3：7米<br>4：8米
led_mode | 模式 | Array | 是 | 0：智能<br>1：常亮<br>2：常灭<br>3：时间段
type | 当前类型的ID | int | 是 | 
content | 当前类型描述 | string | 是 | utf8 + base64编码

### 2.获取补光灯参数
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
  "body": {
    "channel": [
      {
        "chan_id": 0,
        "led_mode": 0,
        "led_sensitivity": 4,
        "time_ctrl": [
          {
            "id": 0,
            "led_level": -1,
            "time_begin": "00:00:00",
            "time_end": "06:00:00",
            "timectrl_enable": false
          },
          {
            "id": 1,
            "led_level": -1,
            "time_begin": "06:00:00",
            "time_end": "19:30:00",
            "timectrl_enable": false
          },
          {
            "id": 2,
            "led_level": -1,
            "time_begin": "19:30:00",
            "time_end": "24:00:00",
            "timectrl_enable": false
          }
        ]
      }
    ]
  },
  "err_msg": "All Done",
  "state": 200,
  "type": "get_led_prm"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
channel | 视频通道 | array | 是 | 
chan_id | 视频通道ID | int | 是 |
led_mode | 模式 | int | 是 | 0：智能<br>1：常亮<br>2：常灭<br>3：时间段
led_sensitivity | 敏感度| int | 是 | ==（该字段现已改为亮度，范围1~100）==
time_ctrl | 控制时间段 | array | 是 |
id | ID | int | 是 | 
led_level | 补光灯等级 | int | 是 | -1：关闭<br>0：2米<br>1：4米<br>2：6米<br>3：7米<br>4：8米
time_begin | 开始时间 | string | 是 | 格式hh:mm:ss，如"06:00:00"
time_end | 结束时间 | string | 是 | 格式hh:mm:ss，如"19:30:00"
timectrl_enable | 是否启用 | bool | 是 | 

### 3.设置补光灯参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_led_prm",
    "body": {
    "channel": [
      {
        "chan_id": 0,
        "led_mode": 0,
        "led_sensitivity": 4,
        "time_ctrl": [
          {
            "id": 0,
            "led_level": -1,
            "time_begin": "00:00:00",
            "time_end": "06:00:00",
            "timectrl_enable": false
          },
          {
            "id": 1,
            "led_level": -1,
            "time_begin": "06:00:00",
            "time_end": "19:30:00",
            "timectrl_enable": false
          },
          {
            "id": 2,
            "led_level": -1,
            "time_begin": "19:30:00",
            "time_end": "24:00:00",
            "timectrl_enable": false
          }
        ]
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
channel | 视频通道 | array | 是 | 
chan_id | 视频通道ID | int | 是 |
led_mode | 模式 | int | 是 | 0：智能<br>1：常亮<br>2：常灭<br>3：时间段
led_sensitivity | 敏感度| int | 是 | ==（该字段现已改为亮度，范围1~100）==
time_ctrl | 控制时间段 | array | 是 |
id | ID | int | 是 | 
led_level | 补光灯等级 | int | 是 | -1：关闭<br>0：2米<br>1：4米<br>2：6米<br>3：7米<br>4：8米
time_begin | 开始时间 | string | 是 | 格式hh:mm:ss，如"06:00:00"
time_end | 结束时间 | string | 是 | 格式hh:mm:ss，如"19:30:00"
timectrl_enable | 是否启用 | bool | 是 | 

## 状态灯
无


# 设备授权
## 授权时间
### 1.获取设备激活状态
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

### 2.设置设备激活状态
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

### 3.获取设备授权状态
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

### 4.设置设备授权状态号
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


# 联动
## 报警联动
### 1.获取报警联动参数属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_alarm_linkage_prop"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_alarm_linkage_prop",
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

### 2.获取报警联动参数
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
  "module": "BUS_REQUEST_MSG",
  "type": "get_alarm_linkage_prm",
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
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 

### 3.设置报警联动参数
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_alarm_linkage_prm",
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
  "module": "BUS_REQUEST_MSG",
  "type": "set_alarm_linkage_prm",
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
parking_type | 违停类型 | int | 是  | 0x01：无牌车<br>0x02：非机动车<br>0x04：跨车位<br>0x08：逆向停车<br>0x10：压车位边线停车<br>0x20：泊位大车报警<br>0x40：车位外停车
car_pos | 车头车位方向 | int | 是 | 1:车头报警;<br>2:车尾报警
out_park_time | 车位外停车时间阈值 | int | 是 | 单位秒(s)，默认300s
fault_type | 故障类型 | int | 是 |  0x01：断网<br>0x02：心跳超时<br>0x04：分区损坏<br>0x08：视频丢失
novideo_time | 视频丢失报警时间 | int | 是 | 

## 定时抓拍
### 1.获取定时抓拍属性
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

### 2.获取定时抓图参数
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

### 3.设置定时抓图
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_timer_snap_prm",
    "body": {
      "time": 0,
      "push": 7
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

## 事件联动
### 语音配置
#### 1.获取语音配置属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_event_linkage_voice_prop"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_voice_prop",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "volume_mode":{
      "max": 80,
      "min": 50,
      "types": [
        {
          "content": "57uG6K+t5qih5byP",
          "type": 50
        },{
          "content": "5ZON5Lqu5qih5byP",
          "type": 80
        }
      ]
    },
    "male_mode":{
      "max": 1,
      "min": 0,
      "types": [
        {
          "content": "55S35aOw",
          "type": 0
        },{
          "content": "5aWz5aOw",
          "type": 1
        }
      ]
    },
    "speed_mode":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "57yT5oWi",
          "type": 0
        },{
          "content": "5q2j5bi4",
          "type": 1
        },{
          "content": "5b+r6YCf",
          "type": 2
        }
      ]
    }
  }
}
```
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
voicecfg | 语音配置 | object | 是 |
time_ctrl | 时间段音量控制 | object | 是 |  
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume_mode | 音量 | int | 是 |  80:响亮模式<br>50:细语模式
male_mode | 声音选择 | int | 是 |  0:男声;<br>1:女声
speed_mode | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;

#### 2.获取语音配置
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_event_linkage_voice_prm"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_voice_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "time_ctrl": [
      {
        "time_begin": "00:00:00",
        "time_end": "06:00:00",
        "volume": 50,
        "id": 0
      },
      {
        "time_begin": "06:00:00",
        "time_end": "19:30:00",
        "volume": 80,
        "id": 1
      },
      {
        "time_begin": "19:30:00",
        "time_end": "24:00:00",
        "volume": 50,
        "id": 2
      }
    ],
    "male": 0,
    "speed": 100
  }
}
```
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
male | 声音选择 | int | 是 |  0:男声;<br>1:女声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;

#### 3.设置语音配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_event_linkage_voice_prm",
  "body": {
    "time_ctrl": [
      {
        "time_begin": "00:00:00",
        "time_end": "06:00:00",
        "volume": 50,
        "id": 0
      },
      {
        "time_begin": "06:00:00",
        "time_end": "19:30:00",
        "volume": 80,
        "id": 1
      },
      {
        "time_begin": "19:30:00",
        "time_end": "24:00:00",
        "volume": 50,
        "id": 2
      }
    ],
    "male": 0,
    "speed": 100
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "set_event_linkage_voice_prm",
  "state": 200,
  "err_msg": "All Done"
}
```
字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
voicecfg | 语音配置 | object | 是 |
id | ID | int | 是 |  
time_begin | 开始时间 | string | 是 |  
time_end | 结束时间 | string | 是 |  
volume | 音量 | int | 是 |  100:响亮模式<br>50:细语模式
male | 声音选择 | int | 是 |  0:男声;<br>1:女声
speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;

### 指示灯配置
#### 1.获取指示灯配置属性
- Request
```
{
    "module":"BUS_REQUEST_MSG",
    "type":"get_event_linkage_light_prop"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_light_prop",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "light_mode":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "55u45py66Ieq5bim5oyH56S654Gv",
          "type": 1
        },{
          "content": "5aSW5o6l5oyH56S654Gv",
          "type": 2
        },{
          "content": "5LiN5ZCv55So5aSW5o6l54Gv",
          "type": 3
        }
      ]
    },
    "externlight_select":{
      "max": 1,
      "min": 0,
      "types": [
        {
          "content": "5LiA54Gv5LiA6L2m5L2N",
          "type": 0
        },{
          "content": "5LiA54Gv5Lik6L2m5L2N77yI5LiA6LevSU/vvIk=",
          "type": 1
        },{
          "content": "5LiA54Gv5Lik6L2m5L2N77yI5Lik6LevSU/vvIk=",
          "type": 2
        }
      ]
    },
    "parkingstate_light_type":{
      "max": 1,
      "min": 0,
      "types": [
        {
          "content": "6L2m5L2N56m66Zey77yM5oyH56S654Gv5oyB57ut5Lqu54Gv77yI5Y2g55So54q25oCB5LiN5Lqu77yJ",
          "type": 0
        },{
          "content": "6L2m5L2N5Y2g55So77yM5oyH56S654Gv5oyB57ut5Lqu54Gv77yI56m66Zey54q25oCB5LiN5Lqu77yJ",
          "type": 1
        }
      ]
    },
    "flicker_mode":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "5LiN6Zeq54OB",
          "type": 0
        },{
          "content": "6Zeq54OB",
          "type": 1
        }
      ]
    },
    "flicker_continue_time":{
      "max": 10,
      "min": 4,
      "types": [
        {
          "content": "5oyB57utNOenkg==",
          "type": 4
        },{
          "content": "5oyB57utNuenkg==",
          "type": 6
        },{
          "content": "5oyB57utOOenkg==",
          "type": 8
        },{
          "content": "5oyB57utMTDnp5I=",
          "type": 10
        }
      ]
    },
    "io_control_output":{
      "max": 3,
      "min": 0,
      "types": [
        {
          "content": "5LiN6L6T5Ye6",
          "type": 0
        },{
          "content": "5oyB57utNuenkg==",
          "type": 1
        },{
          "content": "5oyB57utOOenkg==",
          "type": 2
        },{
          "content": "5oyB57utMTDnp5I=",
          "type": 3
        }
      ]
    },
    "color_type":{
      "max": 8,
      "min": 1,
      "types": [
        {
          "content": "57qi6Imy",
          "type": 1
        },{
          "content": "57u/6Imy",
          "type": 2
        },{
          "content": "6buE6Imy",
          "type": 8
        }
      ]
    },
    "flicker_type":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "5LiN6Zeq54OB",
          "type": 1
        },{
          "content": "5Zu65a6a6aKR546H6Zeq54OB",
          "type": 2
        },{
          "content": "5qC55o2u6L2m6L6G6Led56a76Zeq54OB",
          "type": 8
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
light_mode | 外接灯设置 | int | 是 | 0：相机自带指示灯；<br>1：外接指示灯；<br>2：不启用外接灯
externlight_select | 外接灯类型 | int | 是 | 0：一灯一车位；<br>1：一灯两车位（一路IO）；<br>2：一灯两车位（两路IO）
parkingstate_light_type | 外接灯类型 | int | 是 | 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）
flicker_mode | 亮度类型 | object | 是 | 0：不闪烁；<br>1：闪烁
flicker_continue_time | 闪烁持续时间 | object | 是 | 4/6/8/10秒
io_control_output | IO控制输出 | object | 是 | 0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
color_type | 颜色类型 | object | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
flicker_type | 闪烁类型 | object | 是 | 0：不闪烁；<br>1：固定频率闪烁；<br>2：根据车辆距离闪烁；
types | 类型 | object | 是 |
default | 默认值 | int | 否 |
min | 最小值 | int | 是 | 
max | 最大值 | int | 是 | 
type | 当前类型的ID | int | 是 |
content | 当前类型描述 | string | 是 | utf8 + base64编码

#### 2.获取指示灯配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_event_linkage_light_prm"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_light_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "light_mode": 0,
    "selflight": {
      "empty_color":2,
      "occupy_color":1,
      "lock_color":1,
      "lock_flicker":0,
      "alarm_color":8,
      "alarm_flicker":1,
      "alarm_continue": 10
    },
    "externlight": {
      "light_select":0,
      "io_select":1,
      "empty_io":0,
      "occupy_io":1,
      "lock_io":0,
      "lock_flicker":0,
      "lock_continue":0,
      "alarm_io":0,
      "alarm_flicker":0,
      "alarm_continue":0
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
light_mode | 外接灯设置 | int | 是 | 0：相机自带指示灯；<br>1：外接指示灯；<br>2：不启用外接灯
selflight | 相机自带指示灯配置 | object | 否 | 只有light_mode等于0（选择相机自带指示灯）时有效
empty_color | 空车位颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
occupy_color | 车位占用颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_color | 地锁升降锁事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；<br>2：根据车辆距离闪烁；
alarm_color | 报警事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
externlight | 外接指示灯配置 | object | 否 | 只有light_mode等于1（外接指示灯）时有效
light_select | 外接灯类型 | int | 是 | 0：一灯一车位；<br>1：一灯两车位（一路IO）；<br>2：一灯两车位（两路IO）
io_select | IO选择 | int | 否 | ==一灯一车位时：== 0x0100:左车位IO1右车位IO2;<br>0x0001:左车位IO2右车位IO1<br> ==一灯两车位（一路IO）时：== <br>0:IO1;<br>1:IO2<br> ==一灯两车位（两路IO）时：该字段无意义==
empty_io | 空车位IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
occupy_io | 车位占用IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_io | 地锁升降锁事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
lock_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
alarm_io | 报警事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒

#### 3.设置指示灯配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_event_linkage_light_prm",
  "body": {
    "light_mode": 0,
    "selflight": {
      "empty_color":2,
      "occupy_color":1,
      "lock_color":1,
      "lock_flicker":0,
      "alarm_color":8,
      "alarm_flicker":1,
      "alarm_continue": 10
    },
    "externlight": {
      "light_select":0,
      "io_select":1,
      "empty_io":0,
      "occupy_io":1,
      "lock_io":0,
      "lock_flicker":0,
      "lock_continue":0,
      "alarm_io":0,
      "alarm_flicker":0,
      "alarm_continue":0
    }
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "set_event_linkage_light_prm",
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
light_mode | 外接灯设置 | int | 是 | 0：相机自带指示灯；<br>1：外接指示灯；<br>2：不启用外接灯
selflight | 相机自带指示灯配置 | object | 否 | 只有light_mode等于0（选择相机自带指示灯）时有效
empty_color | 空车位颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
occupy_color | 车位占用颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_color | 地锁升降锁事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；<br>2：根据车辆距离闪烁；
alarm_color | 报警事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
externlight | 外接指示灯配置 | object | 否 | 只有light_mode等于1（外接指示灯）时有效
light_select | 外接灯类型 | int | 是 | 0：一灯一车位；<br>1：一灯两车位（一路IO）；<br>2：一灯两车位（两路IO）
io_select | IO选择 | int | 否 | ==一灯一车位时：== 0x0100:左车位IO1右车位IO2;<br>0x0001:左车位IO2右车位IO1<br> ==一灯两车位（一路IO）时：== <br>0:IO1;<br>1:IO2<br> ==一灯两车位（两路IO）时：该字段无意义==
empty_io | 空车位IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
occupy_io | 车位占用IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_io | 地锁升降锁事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
lock_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
alarm_io | 报警事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒

#### 4.测试指示灯
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"test_event_linkage_light_prm",
  "body": {
    "light_mode": 0,
    "test_type": 0,
    "selflight": {
      "empty_color":2,
      "occupy_color":1,
      "lock_color":1,
      "lock_flicker":0,
      "alarm_color":8,
      "alarm_flicker":1,
      "alarm_continue": 10
    },
    "externlight": {
      "light_select":0,
      "io_select":1,
      "empty_io":0,
      "occupy_io":1,
      "lock_io":0,
      "lock_flicker":0,
      "lock_continue":0,
      "alarm_io":0,
      "alarm_flicker":0,
      "alarm_continue":0
    }
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "test_event_linkage_light_prm",
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
light_mode | 外接灯设置 | int | 是 | 0：相机自带指示灯；<br>1：外接指示灯；<br>2：不启用外接灯
test_type | 测试类型 | int | 是 | 0：车位空闲；<br>1：车位占用；<br>2：地锁升降锁事件；<br>3：报警事件
selflight | 相机自带指示灯配置 | object | 否 | 只有light_mode等于0（选择相机自带指示灯）时有效
empty_color | 空车位颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
occupy_color | 车位占用颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_color | 地锁升降锁事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；<br>2：根据车辆距离闪烁；
alarm_color | 报警事件颜色 | int | 是 | 1：红色；<br>2：绿色；<br>8：黄色；
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：固定频率闪烁；
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
externlight | 外接指示灯配置 | object | 否 | 只有light_mode等于1（外接指示灯）时有效
light_select | 外接灯类型 | int | 是 | 0：一灯一车位；<br>1：一灯两车位（一路IO）；<br>2：一灯两车位（两路IO）
io_select | IO选择 | int | 否 | ==一灯一车位时：== 0x0100:左车位IO1右车位IO2;<br>0x0001:左车位IO2右车位IO1 ==一灯两车位（一路IO）时：== <br>1:IO1;<br>2:IO2<br> ==一灯两车位（两路IO）时：该字段无意义==
empty_io | 空车位IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
occupy_io | 车位占用IO类型 | int | 是 | ==一灯一车位或一灯两车位（一路IO）时：== 0：车位空闲，指示灯持续亮灯（占用状态不亮）；<br>1：车位占用，指示灯持续亮灯（空闲状态不亮）<br>==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_io | 地锁升降锁事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
lock_flicker | 地锁升降锁事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
lock_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒
alarm_io | 报警事件IO类型 | int | 否 | ==一灯两车位（两路IO）时：==<br>0：不输出；<br>1：由IO-1控制输出；<br>2：由IO-2控制输出；<br>3：由IO-1和IO-2同时输出
alarm_flicker | 报警事件闪烁类型 | int | 是 | 0：不闪烁；<br>1：指示灯闪烁<br>2：补光灯闪烁
alarm_continue | 报警事件闪烁持续时间 | int | 是 | 4/6/8/10秒

### 报警配置
#### 1.获取报警配置属性
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_event_linkage_event_prop"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_event_prop",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "audio_list": [
      {
        "id": 0,
        "name": "MQ==",
        "size": 55374
      },
      {
        "id": 1,
        "name": "MTE=",
        "size": 55374
      }
    ],    
    "down_lock_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "6L2m5L2N6ZSB5bey5LiL6ZmN",
          "type": 0
        },{
          "content": "6L2m5L2N6ZSB5bey5LiL6ZmN77yM5Y+v6L+b5YWl",
          "type": 1
        },{
          "content": "6L2m5L2N6ZSB5bey5LiL6ZmN77yM6K+35YGc6L2m",
          "type": 2
        }
      ]
    },
    "up_lock_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "6L2m5L2N6ZSB5Y2z5bCG5LiK5Y2H77yM6K+35rOo5oSP",
          "type": 0
        },{
          "content": "6L2m5L2N6ZSB5Y2z5bCG5LiK5Y2H77yM6K+356uL5Y2z56a75byA",
          "type": 1
        },{
          "content": "6L2m5L2N6ZSB5Y2z5bCG5LiK5Y2H77yM56aB5q2i6YCX55WZ",
          "type": 2
        }
      ]
    },
    "forbid_in_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "56aB5q2i6L+b5YWl6K+l6L2m5L2N77yM6K+35bC95b+r56a75byA",
          "type": 0
        },{
          "content": "5LiT55So6L2m5L2N56aB5q2i5Y2g55So77yM6K+35bC95b+r56a75byA",
          "type": 1
        },{
          "content": "6K+l6L2m5L2N5LiN5YWB6K645YGc5pS+77yM6K+35bC95b+r56a75byA",
          "type": 2
        }
      ]
    },
    "cross_parking_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "6K+35Yu/5Y2g55So5aSa5Liq6L2m5L2N",
          "type": 0
        },{
          "content": "5LiA6L2m5LiA5L2N77yM6K+35oyJ6KeE6IyD5YGc6L2m",
          "type": 1
        },{
          "content": "56aB5q2i6Leo6L2m5L2N5YGc5pS+77yM6K+35bC95b+r56a75byA",
          "type": 2
        }
      ]
    },
    "nonmotor_seize_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "6K+35Yu/5YGc6Z2g6Z2e5py65Yqo6L2m6L6G",
          "type": 0
        },{
          "content": "5LiT55So6L2m5L2N77yM6Z2e5py65Yqo6L2m56aB5q2i5YGc5pS+",
          "type": 1
        },{
          "content": "56aB5q2i6Z2e5py65Yqo6L2m5YGc5pS+77yM6K+35bC95b+r56a75byA",
          "type": 2
        }
      ]
    },
    "human_retention_voice":{
      "max": 2,
      "min": 0,
      "types": [
        {
          "content": "6L2m6L6G5YGc5pS+5Yy65Z+f77yM6KGM5Lq66K+35Yu/5rue55WZ",
          "type": 0
        },{
          "content": "6KGM5Lq66K+35Yu/5Zyo6K+l5Yy65Z+f5rue55WZ",
          "type": 1
        },{
          "content": "6K+l5Yy65Z+f56aB5q2i5rue55WZ77yM6K+35bC95b+r56a75byA",
          "type": 2
        }
      ]
    },
    "play_times":{
      "max": 5,
      "min": 1,
      "types": [
        {
          "content": "MQ==",
          "type": 1
        },{
          "content": "Mg==",
          "type": 2
        },{
          "content": "Mw==",
          "type": 3
        },{
          "content": "NA==",
          "type": 4
        },{
          "content": "NQ==",
          "type": 5
        }
      ]
    },
    "play_interval":{
      "max": 5,
      "min": 1,
      "types": [
        {
          "content": "MQ==",
          "type": 1
        },{
          "content": "Mg==",
          "type": 2
        },{
          "content": "Mw==",
          "type": 3
        },{
          "content": "NA==",
          "type": 4
        },{
          "content": "NQ==",
          "type": 5
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
audio_list | 自定义语音文件 | object | 是 | 
down_lock_voice | 降锁事件语音 | object | 是 | 0：车位锁已下降；<br>1：车位锁已下降，可进入；<br>2：车位锁已下降，请停车
up_lock_voice | 升锁事件语音 | object | 是 | 0：车位锁即将上升，请注意；<br>1：车位锁即将上升，请立即离开；<br>2：车位锁已下降，禁止逗留
forbid_in_voice | 非准入事件语音 | object | 是 | 0：禁止进入该车位，请尽快离开；<br>1：专用车位禁止占用，请尽快离开；<br>2：该车位不允许停放，请尽快离开
cross_parking_voice | 跨车位停放语音 | object | 是 | 0：请勿占用多个车位；<br>1：一车一位，请按规范停车；<br>2：禁止跨车位停放，请尽快离开
nonmotor_seize_voice | 非机动车占位语音 | object | 是 | 0：请勿停靠非机动车辆；<br>1：专用车位，非机动车禁止停放；<br>2：禁止非机动车停放，请尽快离开
human_retention_voice | 非机动车占位语音 | object | 是 | 0：车辆停放区域，行人请勿滞留；<br>1：行人请勿在该区域滞留；<br>2：该区域禁止滞留，请尽快离开
play_times | 声光次数 | object | 是 | 1~5次
play_interval | 声光间隔 | object | 是 | 1~5秒
types | 类型 | object | 是 |
default | 默认值 | int | 否 |
min | 最小值 | int | 是 | 
max | 最大值 | int | 是 | 
type | 当前类型的ID | int | 是 |
content | 当前类型描述 | string | 是 | utf8 + base64编码

#### 2.获取事件配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_event_linkage_event_prm"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_event_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "events": [
      {
        "event": 0,
        "enable": 0,
        "voice": {
          "msg": "6L2m5L2N6ZSB5bey5LiL6ZmN",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 1,
        "enable": 0,
        "voice": {
          "msg": "6L2m5L2N6ZSB5Y2z5bCG5LiK5Y2H77yM6K+35rOo5oSP",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 2,
        "enable": 0,
        "voice": {
          "msg": "56aB5q2i6L+b5YWl6K+l6L2m5L2N77yM6K+35bC95b+r56a75byA",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 3,
        "enable": 0,
        "voice": {
          "msg": "6K+35Yu/5Y2g55So5aSa5Liq6L2m5L2N",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 4,
        "enable": 0,
        "voice": {
          "msg": "6K+35Yu/5YGc6Z2g6Z2e5py65Yqo6L2m6L6G",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 5,
        "enable": 0,
        "voice": {
          "msg": "6L2m6L6G5YGc5pS+5Yy65Z+f77yM6KGM5Lq66K+35Yu/5rue55WZ",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
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
event | 事件类型 | int | 是 | 0：降锁事件；<br>1：升锁事件；<br>2：非准入事件；<br>3：跨车位停放；<br>4：非机动车占位；<br>5：行人滞留
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
voice | 播报提示 | object | 否 | 空闲和占用状态时不需要该字段
msg | 语音播报内容 | string | 是 | utf8 + base64
length | 语音播报内容原始长度 | int | 是
times | 提示次数 | int | 是
interval | 提示间隔 | int | 是
light_enable |  是否联动报警灯 | int | 是 |0：不联动；<br>1：联动

#### 3.设置事件配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_event_linkage_event_prm",
  "body": {
    "events": [
      {
        "event": 0,
        "enable": 0,
        "voice": {
          "msg": "6L2m5L2N6ZSB5bey5LiL6ZmN",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 1,
        "enable": 0,
        "voice": {
          "msg": "6L2m5L2N6ZSB5Y2z5bCG5LiK5Y2H77yM6K+35rOo5oSP",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 2,
        "enable": 0,
        "voice": {
          "msg": "56aB5q2i6L+b5YWl6K+l6L2m5L2N77yM6K+35bC95b+r56a75byA",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 3,
        "enable": 0,
        "voice": {
          "msg": "6K+35Yu/5Y2g55So5aSa5Liq6L2m5L2N",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 4,
        "enable": 0,
        "voice": {
          "msg": "6K+35Yu/5YGc6Z2g6Z2e5py65Yqo6L2m6L6G",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      },{
        "event": 5,
        "enable": 0,
        "voice": {
          "msg": "6L2m6L6G5YGc5pS+5Yy65Z+f77yM6KGM5Lq66K+35Yu/5rue55WZ",
          "length": 18,
          "times": 3,
          "interval": 2
        },
        "light_enable": 0
      }
    ]
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "set_event_linkage_event_prm",
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
event | 事件类型 | int | 是 | 0：降锁事件；<br>1：升锁事件；<br>2：非准入事件；<br>3：跨车位停放；<br>4：非机动车占位；<br>5：行人滞留
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
voice | 播报提示 | object | 否 | 空闲和占用状态时不需要该字段
msg | 语音播报内容 | string | 是 | utf8 + base64
length | 语音播报内容原始长度 | int | 是
times | 提示次数 | int | 是
interval | 提示间隔 | int | 是
light_enable |  是否联动报警灯 | int | 是 |0：不联动；<br>1：联动

#### 4.测试事件配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"test_event_linkage_event_prm",
  "body": {
    "event": 0,
    "voice": {
      "msg": "6L2m5L2N6ZSB5bey5LiL6ZmN",
      "length": 18,
      "times": 3,
      "interval": 2
    },
    "light_enable": 0
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "test_event_linkage_event_prm",
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
event | 事件类型 | int | 是 | 0：降锁事件；<br>1：升锁事件；<br>2：非准入事件；<br>3：跨车位停放；<br>4：非机动车占位；<br>5：行人滞留
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
voice | 播报提示 | object | 否 | 空闲和占用状态时不需要该字段
msg | 语音播报内容 | string | 是 | utf8 + base64
length | 语音播报内容原始长度 | int | 是
times | 提示次数 | int | 是
interval | 提示间隔 | int | 是
light_enable |  是否联动报警灯 | int | 是 |0：不联动；<br>1：联动

## IO状态查询
### IO状态查询
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_event_linkage_io_status"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_event_linkage_io_status",
  "state": 200,
  "err_msg": "All Done",
  "body":{
    "io_status":[
      {
        "id":0,
        "enable":1,
        "status":1,
        "flicker":0
      },{
        "id":1,
        "enable":1,
        "status":1,
        "flicker":0
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
io_status | IO状态 | array | 是 |
id | io的id | int | 是 | 0：IO1；<br>1：IO2
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
status |  是否联动报警灯 | int | 是 |0：IO不输出；<br>1：IO输出<br> ==相机自带指示灯时== <br>IO1输出IO2不输出：绿色<br>IO1不输出IO2输出：红色<br>IO1输出IO2输出：黄色
flicker |  是否闪烁 | int | 是 |0：不闪烁；<br>1：闪烁


# 存储
## 图片
### 1.图片查询
- Request
```
{
  "type": "STORE_SEARCH_IMG_REQUEST",
  "module": "STORE_BUSINESS_REQUEST",
  "body": {
    "page_size": 50,
    "page_num": 1,
    "condition": {
      "zone_id": -1,
      "park_state": -1,
      "plate": "",
      "alarm": [1,2,3]
      "start_time": "2021-10-10 13:43:14",
      "end_time": "2021-10-11 13:43:14"
    }
  }
}
```
- Response
```
{
  "module": "STORE_BUSINESS_REQUEST",
  "type": "STORE_SEARCH_IMG_REQUEST",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "pics_cnt": 1,
    "pics_total": 1,
    "rows": [
      {
        "alarm": 0,
        "carinfo":"",
        "confidence": 0,
        "group_id": -1,
        "id": 244,
        "image_path":"",
        "image_size": 203545,
        "park_state": 8,
        "plate": "X1/ml6BfXw==",
        "plate_color": 0,
        "plate_type": 0,
        "recg_time": 1633931107,
        "recg_time_ms": 0,
        "reco_flag": 1,
        "reco_time": "2021-10-11 13:45:07",
        "trigger": 3,
        "zone_id": 0
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
page_size | 每次查询返回最多条数 | int | 是 | 默认50
page_num | 查询第几页数据 | int | 是 | 
condition | 查询条件 | object | 是 |
zone_id | 车位ID | int | 是 | -1：所有车位；否则是指定车位
park_state | 停车状态 | int | 是 | -1：所有状态；<br>0x01：入场；<br>0x02：在场；<br>0x04：出场；<br>0x08：空场；<br>0x10：车位异常；<br>0x20：延迟上报出场；<br>0x40：合并出入场；<br>0x80：预入场；<br>0x100：预出场；<br>0x200：入场修正
plate | 车牌 | string | 否 | 模糊匹配，空查所有
alarm | 报警类型 | int-array | 否 | -1：全部；<br>0：正常停车<br>3：跨车位停车<br>4：非机动车占位<br>5：车头/车尾方向不一致<br>6：车牌遮挡<br>7：无牌车<br>8：非准入停车<br>9：行人滞留
start_time | 开始时间 | string | 是 |
end_time | 开始时间 | string | 是 |
carinfo | 车标&车型 | string | 是 |
confidence | 置信度 | int | 是 |
group_id | 证据链ID | int | 是 |
id | 图片id | int | 是 |
image_path | 图片路径 | string | 是 | utf8 + base64
image_size | 图片大小 | int | 是 |
plate_color | 车牌颜色 | int | 是 |
plate_type | 车牌类型 | int | 是 |
recg_time | 识别时间 | int | 是 | utc+8
reco_flag | 识别标识 | int | 是 |
reco_time | 识别时间 | string | 是 | 字符串时间
trigger | 触发类型 | int | 是 | 5:虚拟线圈触发;<br>6:稳定触发;<br>7:IO强制触发;<br>8:手动触发;<br>9:SDK抓拍;<br>10:实时结果（车辆实时入场事件）<br>12:单帧识别结果;<br>13:定时触发;

### 2.删除所有图片
- Request
```
{
    "module":"STORE_BUSINESS_REQUEST",
    "type":"STORE_FORMAT_FLASH_REQUEST"
}
```
- Response
```
{
  "module": "BUS_RECORD_VIDEO_REQUEST",
  "type": "get_bus_record_prm",
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

## 录像配置
### 1.获取录像配置参数
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
stream_channel | 录像码流 | int | 是 | 0:主码流<br>1:子码流
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
event_mode | 事件类型 | int | 是 | 0:不录像<br>1:车辆入场录,车辆出场停<br>2:检测到车辆录
period | 录像时间 | int | 否 | 单位秒(s)，只有在检测到车辆录(event_mode=2)时有效

### 2.设置录像配置参数
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
stream_channel | 录像码流 | int | 是 | 0:主码流<br>1:子码流
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
event_mode | 事件类型 | int | 是 | 0:不录像<br>1:车辆入场录,车辆出场停<br>2:检测到车辆录
period | 录像时间 | int | 否 | 单位秒(s)，只有在检测到车辆录(event_mode=2)时有效


# 证据链
## 证据链数据
### 1.获取证据链数据
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
    "evidence": [
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
          },
          {
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
        "chain": []
      },{
        "zone_id": 2,
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
      },
      {
        "zone_id": 3,
        "enable": 1,
        "chain": []
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
zone_id | 车位ID | int | 是 | 
enable | 车位开关使能 | int[0, 1] | 是 | 
chain | 证据链对象 | array | 否 | 可能为空数组
parking_state | 车位状态 | int | 是 | 证据链状态
time_s | 时间 | string | 是 | 字符串时间
plate_str | 车牌号 | string(0,32] | 是 | UTF8后再BASE64编码
plate_color | 车牌颜色 | int | 是 | 0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
image_path | 图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
plateimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
carimage_path | 车牌图片缓存的路径名 | string(0,128] | 是 | UTF8后再BASE64编码)
loc | 车牌/车位置信息 | object | 是 |
left | 车牌/车位置left坐标 | int | 是 |
right | 车牌/车位置right坐标 | int | 是 |
top | 车牌/车位置top坐标 | int | 是 |
bottom | 车牌/车位置bottom坐标 | int | 是 |

### 2.广播证据链更新
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
      },
      {
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


# 推送
## FTP推送
### 1.获取FTP配置
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
img_prefix | img_prefix | string | 是 | 
update_time | update_time | int | 是 | 
password | 密码 | string | 是 | 
port | 端口号 | short | 是 | 
server_ip | 服务ip | string | 是 | 
username | 用户名 | string | 是 | base64

### 2.设置FTP配置
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

### 3.FTP发送测试
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

## HTTP推送
### 1.获取HTTP推送配置
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

### 2.设置HTTP推送配置
- Request
```
{
  "module": "BUS_HTTP_REQUEST",
  "type": "set_push_cfg",
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

## MQTT
### 1.获取MQTT配置
- Request
```
{
  "module":"BUS_MQTT_REQUEST",
  "type":"get_self_mqtt_prm"
}
```
- Response
```
{
  "module": "BUS_MQTT_REQUEST",
  "type": "get_self_mqtt_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "host": "192.168.6.2",
    "port": 61613,
    "client": "mqttx_71327712",
    "username": "admin",
    "password": "password",
    "sign":1,
    "down": {
      "enable": 1,
      "alive": 1,
      "resp": 1,
      "topic": "down"
    },
    "up": {
      "enable": 1,
      "ivs": 1,
      "rs485": 1,
      "topic": "up"
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
io_status | IO状态 | array | 是 |
host | 服务端地址 | string | 是 | 
port | 服务端端口 | int | 是 | 
client | client_id | string | 是 | 
username | 用户名 | string | 是 | 
password | 密码 | string | 是 | 
sign | 签名开关 | int | 是 | 1：开启<br>0:关闭
down | 上行对象 | object | 是 | 
up | 下行对象 | object | 是 | 
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
alive | 保持链路 | int | 是 | 0：不保持；<br>1：保持
resp | 回复 | int | 是 | 0：不回复；<br>1：回复
topic | TOPIC | string | 是 |
ivs | 推送识别结构 | int | 是 | 0：不启用；<br>1：启用
rs485 | 推送串口数据 | int | 是 | 0：不启用；<br>1：启用

### 2.设置MQTT配置
- Request
```
{
  "module":"BUS_MQTT_REQUEST",
  "type":"set_self_mqtt_prm",
  "body": {
    "host": "192.168.6.2",
    "port": 61613,
    "client": "mqttx_71327712",
    "username": "admin",
    "password": "password",
    "sign":1,
    "down": {
      "enable": 1,
      "alive": 1,
      "resp": 1,
      "topic": "down"
    },
    "up": {
      "enable": 1,
      "ivs": 1,
      "rs485": 1,
      "topic": "up"
    }
  }
}
```
- Response
```
{
  "module": "BUS_MQTT_REQUEST",
  "type": "set_self_mqtt_prm",
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
io_status | IO状态 | array | 是 |
host | 服务端地址 | string | 是 | 
port | 服务端端口 | int | 是 | 
client | client_id | string | 是 | 
username | 用户名 | string | 是 | 
password | 密码 | string | 是 | 
sign | 签名开关 | int | 是 | 1：开启<br>0:关闭
down | 上行对象 | object | 是 | 
up | 下行对象 | object | 是 | 
enable | 启用状态 | int | 是 | 0：不启用；<br>1：启用
alive | 保持链路 | int | 是 | 0：不保持；<br>1：保持
resp | 回复 | int | 是 | 0：不回复；<br>1：回复
topic | TOPIC | string | 是 |
ivs | 推送识别结构 | int | 是 | 0：不启用；<br>1：启用
rs485 | 推送串口数据 | int | 是 | 0：不启用；<br>1：启用


# 参数管理
## 默认参数
### 1.恢复默认
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
key | 需要恢复默认的关键字 | string | 是 |  road_rule：车位设置<br>dev_name：设备名<br>road_reco：识别设置<br>timer_snap：定时抓图<br>road_snap：截图配置<br>pic_merge：图片合成<br>park_no：停车场编号<br>park_mode：车位模式<br>event_linkage：事件联动


# 声光
## 语音播报（老RF）
### 1.获取语音播报配置
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

### 2.设置语音播报配置
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

### 3.语音试听
- Request
```
{
  "module": "AVS_REQUEST_MESSAGE",
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
  "module": "AVS_REQUEST_MESSAGE",
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
voice_male | 声音选择 | int | 是 |  0:男声<br>1:女声;
voice_speed | 声速 | int | 是 |  80:缓慢;<br>100:正常;<br>120:快速;
voice_data | 语音内容 | string | 是 |  UTF8 + BASE64
data_len | 语音内容长度 | int | 是 |  加密后的长度


# 自定义语音
### 1.语音文件列表查询
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_audio_file_list"
}
```
- Response
```
{
  "body": {
    "female": [
      {
        "name": "0.wav",
        "size": 17964,
        "id": 0
      },
      {
        "name": "1.wav",
        "size": 17324,
        "id": 1
      }
    ],
    "male": [
      {
        "name": "0.wav",
        "size": 15404,
        "id": 0
      },
      {
        "name": "1.wav",
        "size": 14764,
        "id": 1
      }
    ]
  },
  "err_msg": "All Done",
  "state": 200,
  "type": "get_audio_file_list"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
female | 女声 | object | 是 | 
male | 男声 | object | 是 | 
id | 当前类型的ID | int | 是 |
name | 当前类型描述 | string | 是 | 
size | 文件的尺寸 | int | 是 |


### 2.语音文件删除
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "del_audio_files",
  "body": {
    "male":[
      {
        "name":"000.wav"
      },{
        "name":"111.wav"
      }
    ],
    "female":[
      {
        "name":"000.wav"
      },{
        "name":"111.wav"
      }
    ]
  }
}
```
- Response
```
{
  "type": "del_audio_files",
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
female | 女声 | object | 是 | 
male | 男声 | object | 是 | 
name | 文件名 | string | 是 | 


### 3.语音文件下载
- Request
```
{
  "module": "AVS_REQUEST_MESSAGE",
  "type": "down_audio_file",
  "body": {
    "gender": 0,
    "filename": "xxxxxxx.wav",
    "username": "root",
    "password": "xxxxxxx",
    "file_url": "http://download.vzicloud.com/xxxxxxx.wav",
    "url_md5":  "F961DAEB59BFE749B7F961DAEB59BFEA",
    "file_md5": "F961DAEB59BFE749B757E3F9AC95A3EB"
  }
}
```
- Response
```
{
  "module": "AVS_REQUEST_MESSAGE",
  "type": "down_audio_file",
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
gender | 男声女声 | int | 是 | 0：男声 1 女声
filename | 文件名 | string | 是 | 音频文件保存的名称
username | 用户名 | string | 是 | 
password | 密码 | string | 是 |
file_url | 文件url | string | 是 | 
url_md5  | url的md5值 | string | 是 | 
file_md5 | 文件md5值 | string | 是 | 全大写


# 地锁
## 车位地锁选择
### 1.获取车位地锁选择
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_parking_lock_select_prm"
}
```
- Response
```
{
  "type": "get_parking_lock_select_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "parking_lock_select": [
      {
        "zone_id":0,
        "lock_id":-1,
        "lock_enable":0,
        "source":0,
        "lock_no":"xxx"
      },{
        "zone_id":1,
        "lock_id":-1,
        "lock_enable":0,
        "source":1,
        "lock_no":"xxx"
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
parking_lock_select | 车位地锁选择 | object | 是 | 
zone_id | 车位id | int | 是 | 0：左车位；<br>1：右车位
lock_id | 地锁编号 | int | 是 | -1：未选择；<br>0：地锁1；<br>1：地锁2
lock_enable | 地锁使能（选择后默认启用） | int | 是 | 0：不启用；<br>1：启用
source | 串口选择 | int | 是 | 0：串口1；<br>1：串口2
lock_no | 地锁唯一标识 | string | 是 | 蓝牙地锁：地锁的mac<br>有线地锁：地锁的id

### 2.设置车位地锁选择
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_parking_lock_select_prm",
  "body": {
    "parking_lock_select": [
      {
        "zone_id":0,
        "lock_id":-1,
        "lock_enable":0,
        "source":0,
        "lock_no":"xxx"
      },{
        "zone_id":1,
        "lock_id":-1,
        "lock_enable":0,
        "source":1,
        "lock_no":"xxx"
      }
    ]
  }
}
```
- Response
```
{
  "type": "set_parking_lock_select_prm",
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
parking_lock_select | 车位地锁选择 | object | 是 | 
zone_id | 车位id | int | 是 | 0：左车位；<br>1：右车位
lock_id | 地锁编号 | int | 是 | -1：未选择；<br>0：地锁1；<br>1：地锁2
lock_enable | 地锁使能（选择后默认启用） | int | 是 | 0：不启用；<br>1：启用
source | 串口选择 | int | 是 | 0：串口1；<br>1：串口2
lock_no | 地锁唯一标识 | string | 是 | 蓝牙地锁：地锁的mac<br>有线地锁：地锁的id

## 地锁搜索
### 1.地锁搜索
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_list",
  "body": {
    "mode":0
  }
}
```
- Response
```
{
  "module": "PS_BUS_REQUEST",
  "type": "get_parking_lock_list",	
  "state":200,
  "error_msg":"All done",
  "body":{
    "locks":[
      {
        "id":0,
        "rssi":-70,
        "status":1,
        "normal":1
        "name":"xxx",
        "lock_no":"xxx",
        "source":0
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
mode | 地锁连接模式 | int[0,1] | 是 |  0:有线<br>1:蓝牙
locks | 地锁信息 | object | 是 |
id | 记录id | int | 是 |
rssi | 蓝牙信号强度 | int | 否 | 只对蓝牙地锁有效
status | 连接状态 | int | 是 | 蓝牙地锁：连接状态（0：未连接；1：已连接）<br>有线地锁：升降状态（0:升起;1:升起中;2:降下;3:降下中）
normal | 是否正常 | int | 否 | 0：不正常；1：正常
name | 地锁名字 | string | 否 | 蓝牙地锁：地锁名字；
lock_no | 地锁唯一标识 | string | 是 | 蓝牙地锁：地锁的mac<br>有线地锁：地锁的id
source | 串口选择 | int | 是 | 0：串口1；<br>1：串口2

## 地锁配对设置
### 1.获取地锁配对设置
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_prm"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_prm",	
  "state":200,
  "error_msg":"All done",
  "body":{
    "mode":0,
    "control":0,
    "delay":5,
    "telecontrol":1,
    "ultrasonic":1,
    "selfcheck":1
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
mode | 地锁连接模式 | int[0,1] | 是 |  0:有线<br>1:蓝牙
control | 控制类型 | int[0,1] | 是 | 0:相机控制；1:平台控制
delay | 升锁延迟 | int | 是 | 单位秒
telecontrol | 遥控器控制升降 | int | 是 | 0：不启用；<br>1：启用
ultrasonic | 地锁超声波识别自动升锁 | int | 是 | 0：不启用；<br>1：启用
selfcheck | 地锁自检 | int | 是 | 0：不启用；<br>1：启用

### 2.设置地锁配对设置
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "set_parking_lock_prm",
  "body":{
    "mode":0,
    "control":0,
    "delay":5,
    "telecontrol":1,
    "ultrasonic":1,
    "selfcheck":1
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "set_parking_lock_prm",	
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
mode | 地锁连接模式 | int[0,1] | 是 |  0:有线<br>1:蓝牙
control | 控制类型 | int[0,1] | 是 | 0:相机控制；1:平台控制
delay | 升锁延迟 | int | 是 | 单位秒
telecontrol | 遥控器控制升降 | int | 是 | 0：不启用；<br>1：启用
ultrasonic | 地锁超声波识别自动升锁 | int | 是 | 0：不启用；<br>1：启用
selfcheck | 地锁自检 | int | 是 | 0：不启用；<br>1：启用

## 地锁版本号
### 1.获取地锁版本号
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_version"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_version",	
  "state":200,
  "error_msg":"All done",
  "body":{
    "versions": [
      {
        "id":0,
        "zone_id": 0,
        "lock_id": 0,
        "version": "1.0"
      },{
        "id":0,
        "zone_id": 0,
        "lock_id": 0,
        "version": "1.0"
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
id | id | int | 是 |
zone_id | 车位id | int | 是 | 0：左车位；<br>1：右车位
lock_id | 地锁编号 | int | 是 | 0：地锁1；<br>1：地锁2

## 地锁操作
### 1.地锁操作指令
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "test_parking_lock",
  "body":{
    "option":1,
    "zone_id": 0,
    "lock_id": 0,
    "lock_no": "",
    "source": 0
  }
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "test_parking_lock",	
  "state":200,
  "error_msg":"All done",
  "action_rst":0
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
option | 操作 | int | 是 | 0:测试连接;<br>1:升锁;<br>2:降锁
zone_id | 车位id | int | 是 | -1:;0：左车位；<br>1：右车位
lock_id | 地锁编号 | int | 是 | 0：左车位地锁；<br>1：右车位地锁
lock_no | 地锁唯一标识 | string | 是 | 蓝牙地锁：地锁的mac<br>有线地锁：地锁的id
source | 串口选择 | int | 是 | 0：串口1；<br>1：串口2
action_rst | 地锁执行结果返回 | int | 是 | 0：成功

## 地锁自检结果
### 1.地锁自检结果
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_selfcheck_result"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "test_parking_lock",	
  "state":200,
  "error_msg":"All done",
  "body":{
    "selfcheck":1,
    "results":[
      {
        "id":0,
        "parking_enable":1,
        "lock_enable":1,
        "zone_id":0,
        "lock_id":0,
        "errcode":0,
        "time":"2021-01-01 02:00:00",
        "retry":0
      },{
        "id":1,
        "parking_enable":1,
        "lock_enable":1,
        "zone_id":1,
        "lock_id":1,
        "errcode":0,
        "time":"2021-01-01 02:00:00",
        "retry":0
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
selfcheck | 地锁自检 | int | 是 | 0：不启用；<br>1：启用
results | 自检结果 | array | 是 |
id | 记录id | int | 是 |
parking_enable | 车位使能 | 是 | 0：不启用；<br>1：启用
lock_enable | 地锁使能 | 是 | 0：不启用；<br>1：启用
zone_id | 车位id | int | 是 | 0：左车位；<br>1：右车位
lock_id | 地锁编号 | int | 是 | 0：地锁1；<br>1：地锁2
errcode | 自检错误码 | int | 是 | 0：成功
time | 最后一次自检时间 | string | 是 | 字符串时间"2021-01-01 02:00:00"
retry | 自检重试次数 | int | 是 |

## 获取地锁状态
### 1.获取地锁状态
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_status"
}
```
- Response
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "get_parking_lock_status",	
  "state":200,
  "error_msg":"All done",
  "body":{
    "statuses": [
      {
        "zone_id": 0,
        "status": 0,
        "version": "1.0"
      },{
        "zone_id": 1,
        "status": 0,
        "version": "1.0"
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
zone_id | 车位id | int | 是 | 0：左车位；<br>1：右车位
version | 地锁版本 | int | 是 | 获取失败时返回-1
status | 地锁状态 | int | 是 | 4：初始化<br>3:正在落下<br>2:落下<br>1:正在抬升<br>0:竖起<br>-1:发送失败<br>-2:接收失败<br>-3:回复命令不匹配

# 白名单
## 白名单配置
### 1.获取白名单配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_whitelist_prm"
}
```
- Response
```
{
  "type": "get_whitelist_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "filter_enable": 2,
    "fuzzy_query_type":0,
    "fuzzy_query_len":0,
    "fuzzy_ignore_cc":0    
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
filter_enable | 白名单启用条件 | int | 是 | 0:脱机自动启用；<br>1：启用；<br>2：不启用
fuzzy_query_type | 白名单模糊匹配 | int | 是 | 0:精确匹配；<br>1：相似字符匹配；<br>2：普通字符模糊匹配
fuzzy_query_len | 允许误识别长度 | int[0,3] | 是 | 
fuzzy_ignore_cc | 忽略汉字 | int | 是 | 0:不忽略；<br>1：忽略

### 2.设置白名单配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_whitelist_prm",
  "body": {
    "filter_enable": 0,
    "fuzzy_query_type":1,
    "fuzzy_query_len":0,
    "fuzzy_ignore_cc":0    
  }
}
```
- Response
```
{
  "type": "set_whitelist_prm",
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
filter_enable | 白名单启用条件 | int | 是 | 0:脱机自动启用；<br>1：启用；<br>2：不启用
fuzzy_query_type | 白名单模糊匹配 | int | 是 | 0:精确匹配；<br>1：相似字符匹配；<br>2：普通字符模糊匹配
fuzzy_query_len | 允许误识别长度 | int[0,3] | 是 | 
fuzzy_ignore_cc | 忽略汉字 | int | 是 | 0:不忽略；<br>1：忽略

## 白名单管理
### 1.查询白名单
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "select_whitelist_prm",
  "body": {
    "plate": "",
    "park_id": 1
  }
}
```
- Response
```
{
  "type": "select_whitelist_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "list": [
      {
        "park_id": 1,
        "plate": "京A12345",
        "enable_time": "2021-05-25 10:00:00",
        "overdue_time": "2021-05-25 10:00:00",
        "seg_start_time": "10:00:00",
        "seg_end_time": "20:00:00",
        "comment": "hello world",
        "save_id": 55,
        "black": 0
      },{
        "park_id": 1,
        "plate": "京A54321",
        "enable_time": "2021-05-25 10:00:00",
        "overdue_time": "2021-05-25 10:00:00",
        "seg_start_time": "10:00:00",
        "seg_end_time": "20:00:00",
        "comment": "hello world",
        "save_id": 66,
        "black": 0
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
valid_cnt | 需要添加白名单数量 | int | 是 | 超过60条，只添加前60条
park_id	| 车位ID | int[1,6] | 是 | 请求指令时：-1或没有该字段，查询所有；否则指定车位id
plate	| 车牌 | string(0,32] | 是 | 请求指令时：空或没有该字段，查询所有；否则指定车牌模糊搜索
enable_time | 生效日期 | int | 是 |
overdue_time | 失效日期 | int | 是 |
seg_start_time | 有效的起始时间段 | int | 是 |
seg_end_time | 有效的结束时间段 | int | 是 |
comment | 备注 | string(0,32] | 是 |
success_data | 导入成功的白名单数据 | Object | 是 |
fail_data | 导入失败的白名单数据 | Object | 是 |
save_id | 存储id | int | 是 |
black | 黑名单标识 | int | 是 | 0:白名单;<br>1:黑名单
### 2.增加白名单
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "add_whitelist_prm",
  "body": {
    "valid_cnt": 2,
    "list": [
      {
        "park_id": 1,
        "plate": "京 A12345",
        "enable_time": "2021-05-25 10:00:00",
        "overdue_time": "2021-05-25 10:00:00",
        "seg_start_time": "10:00:00",
        "seg_end_time": "20:00:00",
        "comment": "hello world",
        "black": 0
      },{
        "park_id": 1,
        "plate": "京 A54321",
        "enable_time": "2021-05-25 10:00:00",
        "overdue_time": "2021-05-25 10:00:00",
        "seg_start_time": "10:00:00",
        "seg_end_time": "20:00:00",
        "comment": "hello world",
        "black": 0
      }
    ]
  }
}
```
- Response
```
{
  "type": "add_whitelist_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "success_data": {
      "list": [
        {
          "comment": "hello world",
          "enable_time": "2021-05-25 10:00:00",
          "overdue_time": "2021-10-25 10:00:00",
          "park_id": 1,
          "plate": "京 A12345",
          "save_id": 50,
          "seg_end_time": "20:00:00",
          "seg_start_time": "10:00:00",
          "black": 0
        },{
          "comment": "hello world",
          "enable_time": "2021-05-25 10:00:00",
          "overdue_time": "2021-10-25 10:00:00",
          "park_id": 2,
          "plate": "京 A54321",
          "save_id": 13,
          "seg_end_time": "20:00:00",
          "seg_start_time": "10:00:00",
          "black": 0
        }
      ],
      "valid_cnt": 2
    },
    "fail_data": {
      "count": 0,
      "list": null
    },
    "save_id": [
      50,
      13
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
valid_cnt | 需要添加白名单数量 | int | 是 | 超过60条，只添加前60条
park_id	| 车位ID | int[0,1] | 是 |
plate	| 车牌 | string(0,32] | 是 |
enable_time | 生效日期 | int | 是 |
overdue_time | 失效日期 | int | 是 |
seg_start_time | 有效的起始时间段 | int | 是 |
seg_end_time | 有效的结束时间段 | int | 是 |
comment | 备注 | string(0,32] | 是 |
success_data | 导入成功的白名单数据 | Object | 是 |
fail_data | 导入失败的白名单数据 | Object | 是 |
save_id | 添加成功的save_id | int-array | 否 |
black | 黑名单标识 | int | 是 | 0:白名单;<br>1:黑名单
### 3.删除白名单
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "delete_whitelist_prm",
  "body": {
    "delete_type":1
    "delete_param":{
      "delete_cnt":3,
      "delete_id":[
          55,56,57
       ]
    }
  }
}
```
- Response
```
{
  "type": "delete_whitelist_prm",
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
delete_type	| 删除的类型 | int | 是 |1：删除全部<br>2：根据传入参数删除
delete_param	| 删除的参数 | object | 是 |
delete_cnt | 删除的数量 | int | 否 |
delete_id | 存在相机中的ID | int-array | 否 |

### 4.修改白名单
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "edit_whitelist_prm",
  "body": {
    "park_id": 1,
    "plate": "京 A12345",
    "enable_time": "2021-05-25 10:00:00",
    "overdue_time": "2021-05-25 10:00:00",
    "seg_start_time": "10:00:00",
    "seg_end_time": "20:00:00",
    "comment": "hello world",
    "save_id":55,
    "black": 0
  }
}
```
- Response
```
{
  "type": "edit_whitelist_prm",
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
park_id	| 车位ID | Int[1,6] | 是 |
plate	| 车牌 | string(0,32] | 是 |
enable_time | 生效日期 | int | 是 |
overdue_time | 失效日期 | int | 是 |
seg_start_time | 有效的起始时间段 | int | 是 |
seg_end_time | 有效的结束时间段 | int | 是 |
comment | 备注 | string(0,32] | 是 |
save_id | 添加成功的save_id | int-array | 否 |
black | 黑名单标识 | int | 是 | 0:白名单;<br>1:黑名单

## 准入车型
### 1.获取准入车型配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_admittance_plate_prm",
}
```
- Response
```
{
  "type": "get_admittance_plate_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "plate_support": 8
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
plate_support | 识别类型 | int | 是 | 0x00000001:蓝牌<br>0x00000002:黄牌<br>0x00000004:黑牌<br>0x00000008:新能源<br>0x00000010:教练车<br>0x00000020:警车<br>0x00000040:武警车<br>0x00000080:军车<br>0x00000100:港澳<br>0x00000200:领馆车<br>0x00000400:使馆车<br>0x00000800:民航<br>0x00001000:应急<br>0x00800000:非机动车<br>0x80000000:无牌车<br>

### 2.设置准入车型配置
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"set_admittance_plate_prm",
  "body": {
    "plate_support": 8
  }
}
```
- Response
```
{
  "type": "get_admittance_plate_prm",
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
plate_support | 识别类型 | int | 是 | 0x00000001:蓝牌<br>0x00000002:黄牌<br>0x00000004:黑牌<br>0x00000008:新能源<br>0x00000010:教练车<br>0x00000020:警车<br>0x00000040:武警车<br>0x00000080:军车<br>0x00000100:港澳<br>0x00000200:领馆车<br>0x00000400:使馆车<br>0x00000800:民航<br>0x00001000:应急<br>0x00800000:非机动车<br>0x80000000:无牌车<br>

## 车辆预约
### 1.获取车辆预约
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"select_appointment_prm",
  "body": {
    "zone_id": -1,
    "plate": "",
    "status": -1,
    "start_time": "2021-01-01 01:00:00",
    "end_time":"2021-12-01 23:59:00"
  }
}
```
- Response
```
{
  "type": "select_appointment_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "lists":[
      {
        "id": 0,
        "zone_id":0,
        "plate":"川A11111",
        "start_time": "2021-01-01 01:00:00",
        "end_time":"2021-01-01 23:59:00",
        "status": 0,
        "notes":""
      },{
        "id": 1,
        "zone_id":0,
        "plate":"川A22222",
        "start_time": "2021-01-02 01:00:00",
        "end_time":"2021-01-02 23:59:00",
        "status": 0,
        "notes":""
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
zone_id | 车位id | int | 是 | 查询时，该字段可无或者值为-1
plate | 车牌号 | string | 是 | 查询时，该字段可无或者值为空
status | 预约状态 | int | 是 | 0:已过期;<br>1:生效中;<br>2:待生效<br>查询时，该字段可无或者值为-1
start_time | 开始时间 | string | 是 | 查询时，该字段可无或者值为空
end_time | 结束时间 | string | 是 | 查询时，该字段可无或者值为空
notes | 备注 | string[0,20] | 是 | 查询时，该字段可无或者值为空

### 2.添加车辆预约
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"add_appointment_prm",
  "body": {
    "valid_cnt": 2,
    "lists":[
      {
        "id":0,
        "zone_id":0,
        "plate":"川A11111",
        "start_time": "2021-01-01 01:00:00",
        "end_time":"2021-01-01 23:59:00",
        "notes":""
      },{
        "id":1,
        "zone_id":0,
        "plate":"川A22222",
        "start_time": "2021-01-02 01:00:00",
        "end_time": "2021-01-02 23:59:00",
        "notes":""
      }
    ]
  }
}
```
- Response
```
{
  "type": "add_appointment_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "success_data": {
      "lists": [
        {
          "id": 0,
          "zone_id":0,
          "plate":"川A11111",
          "start_time": "2021-01-01 01:00:00",
          "end_time":"2021-01-01 23:59:00",
          "notes":""
        },{
          "id": 1,
          "zone_id":0,
          "plate":"川A22222",
          "start_time": "2021-01-02 01:00:00",
          "end_time":"2021-01-02 23:59:00",
          "notes":""
        }
      ],
      "valid_cnt": 2
    },
    "fail_data": {
      "count": 0,
      "lists": null
    },
    "save_id": [
      0,
      1
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
zone_id | 车位id | int | 是 | 查询时，该字段可无或者值为-1
plate | 车牌号 | string | 是 | 查询时，该字段可无或者值为空
status | 预约状态 | int | 是 | 0:已过期;<br>1:生效中;<br>2:待生效<br>查询时，该字段可无或者值为-1
start_time | 开始时间 | string | 是 | 查询时，该字段可无或者值为空
end_time | 开始时间 | string | 是 | 查询时，该字段可无或者值为空
notes | 备注 | string[0,20] | 是 | 查询时，该字段可无或者值为空
valid_cnt | 数量 | int | 是 | 超过100条，只添加前100条
success_data | 导入成功的白名单数据 | Object | 是 |
fail_data | 导入失败的白名单数据 | Object | 是 |
save_id | 添加成功的id | int-array | 否 |

### 3.删除车辆预约
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "delete_appointment_prm",
  "body": {
    "delete_type":1,
    "delete_param":{
      "delete_cnt":3,
      "delete_id":[
          55,56,57
       ]
    }
  }
}
```
- Response
```
{
  "type": "delete_appointment_prm",
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
delete_type	| 删除的类型 | int | 是 |1：删除全部<br>2：根据传入参数删除
delete_param	| 删除的参数 | object | 是 |
delete_cnt | 删除的数量 | int | 否 |
delete_id | 存在相机中的ID | int-array | 否 |

### 4.修改车辆预约
- Request
```
{
  "module": "BUS_REQUEST_MSG",
  "type": "edit_appointment_prm",
  "body": {
    "id": 1,
    "zone_id":0,
    "plate":"川A22222",
    "start_time": "2021-01-02 01:00:00",
    "end_time":"2021-01-02 23:59:00",
    "notes":""
  }
}
```
- Response
```
{
  "type": "edit_appointment_prm",
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
park_id	| 车位ID | Int[1,6] | 是 |
plate	| 车牌 | string(0,32] | 是 |
enable_time | 生效日期 | int | 是 |
overdue_time | 失效日期 | int | 是 |
seg_start_time | 有效的起始时间段 | int | 是 |
seg_end_time | 有效的结束时间段 | int | 是 |
comment | 备注 | string(0,32] | 是 |
save_id | 添加成功的save_id | int-array | 否 |


# 其他
## 设备脱机状态
### 1.获取设备脱机状态
- Request
```
{
  "module":"BUS_REQUEST_MSG",
  "type":"get_offline_status",
}
```
- Response
```
{
  "type": "get_offline_status",
  "state": 200,
  "err_msg": "All Done",
  "body": {
    "offline_status": 0,
    "offline_time": 2
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
offline_status | 脱机状态 | int | 是 | 0:离线<br>1:在线
offline_time | 脱机检查时间 | int | 是 | 