# 抓图相关
## 抓图
### 1.抓拍图片
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

## 抓图配置
### 1.获取图片抓拍属性
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

### 2.获取图片抓拍
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

### 3.设置图片抓拍
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

## 抓图OSD叠加
### 1.获取抓图OSD叠加参数属性
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
      "osd_pos": {
      "default": 0,
      "enable": true,
      "types": [
          {
          "content": "5Zu+54mH5aSW5LiK6L6557yY",
          "type": 0
        },{
          "content": "5Zu+54mH5aSW5LiL6L6557yY",
          "type": 1
        },{
          "content": "5Zu+54mH5YaF5bem5LiK6KeS",
          "type": 2
        },{
          "content": "5Zu+54mH5YaF5bem5LiL6KeS",
          "type": 3
        },{
          "content": "5Zu+54mH5YaF5Y+z5LiK6KeS",
          "type": 4
        },{
          "content": "5Zu+54mH5YaF5Y+z5LiL6KeS",
          "type": 5
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
        },{
          "content": "5oql6K2m57G75Z6L",
          "type": 256
        }
      ]
    },
    "detect_region":{
        "default": 6,
      "enable": true,
      "types": [
          {
          "content": "6L2m5L2N57q/5ZyI",
          "type": 2
        },{
          "content": "6L2m5qOA546w5Ya1",
          "type": 4
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
color | OSD颜色 | object | 是 | 
osd_pos | 字体位置 | object | 是 | 0：图片外上边缘<br>1：图片外下边缘<br>2：图片内左上角<br>3：图片内左下角<br>4：图片内右上角<br>5：图片内右下角
font_size | OSD字体 | object | 是 | 
date_format | 日期格式 | object | 是 | 
time_format | 时间格式 | object | 是 | 
carplate_format | 车辆/车牌信息格式 | object | 是 | 1：车牌号<br>2：车牌类型<br>4：车位名称<br>8：停车状态<br>16：停车方向<br>32：置信度<br>64：车牌像素<br>128：车型/车款/车标<br>256：报警类型
detect_region | 检测框 | object | 是 | 2:车位线圈<br>4:车检现况
default | 默认值 | int | 是 | 
enable | 是否启用 | boolean | 是 | 
content | 对应类型的描述 | string | 是 | utf8 + base64
type | 对应类型的ID | int | 是 | 

### 2.获取单张图OSD叠加
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
          "osd_pos": 0,
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
              }
          ],
          "detect_region": 6
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
align | 对齐方式 | int | 是 | H1L有效<br>==H1M已弃用==
color | OSD颜色 | int | 是 | 
osd_pos | 字体位置 | int | 是 | 0：图片外上边缘<br>1：图片外下边缘<br>2：图片内左上角<br>3：图片内左下角<br>4：图片内右上角<br>5：图片内右下角
font_size | OSD字体 | int | 是 | 
date | 日期 | object | 是 | 
time | 时间 | object | 是 | 
date_format | 日期格式 | int | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆车牌信息格式 | int | 是 | 按位标识<br>0x0001：车牌号<br>0x0002：车牌类型<br>0x0004：车位名称<br>0x0008：停车状态<br>0x0010：停车方向<br>0x0020：置信度<br>0x0040：车牌像素<br>0x0080：车型/车款/车标<br>0x0100：报警类型
usr_text | 用户自定义数据 | array | 是 | H1L：8个<br>H1L：1个
enable | 是否开启 | int | 是 | 
pos | 位置 | int | 是 | 高4位：x坐标<br>低4位：y坐标<br>按1000*1000基准
context | OSD内容 | string | 是 | utf8 + base64
detect_region | 检测框 | int | 是 | 2:车位线圈<br>4:车检现况

### 3.设置单张图OSD叠加
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
          "align": 11,
          "color": 0,
          "osd_pos": 0,
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
              }
          ],
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
align | 对齐方式 | int | 是 | H1L有效<br>==H1M已弃用==
color | OSD颜色 | int | 是 | 
osd_pos | 字体位置 | int | 是 | 0：图片外上边缘<br>1：图片外下边缘<br>2：图片内左上角<br>3：图片内左下角<br>4：图片内右上角<br>5：图片内右下角
font_size | OSD字体 | int | 是 | 
date | 日期 | object | 是 | 
time | 时间 | object | 是 | 
date_format | 日期格式 | int | 是 | 
time_format | 时间格式 | int | 是 | 
carplate_format | 车辆车牌信息格式 | int | 是 | 按位标识<br>0x0001：车牌号<br>0x0002：车牌类型<br>0x0004：车位名称<br>0x0008：停车状态<br>0x0010：停车方向<br>0x0020：置信度<br>0x0040：车牌像素<br>0x0080：车型<br>0x0100：报警类型<br>0x0200：车标
usr_text | 用户自定义数据 | array | 是 | H1L：8个<br>H1L：1个
enable | 是否开启 | int | 是 | 
pos | 位置 | int | 是 | 高4位：x坐标<br>低4位：y坐标<br>按1000*1000基准
context | OSD内容 | string | 是 | utf8 + base64
detect_region | 检测框 | int | 是 | 2:车位线圈<br>4:车检现况

## 实时检测框
### 1.获取实时检测框参数
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
  "module": "ALG_REQUEST_MESSAGE",
  "type": "get_realtime_display_prm",
  "state": 200,
  "err_msg": "All Done",
  "body": {
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
detect_region | 实时检测框参数 | int | 是 | 2:车位线圈<br>4:车检现况

### 2.设置实时检测框参数
- Request
```
{
    "module":"ALG_REQUEST_MESSAGE",
    "type":"set_realtime_display_prm",
    "body": {
      "detect_region": 6
    }
}
```
- Response
```
{
  "module": "ALG_REQUEST_MESSAGE",
  "type": "set_realtime_display_prm",
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
detect_region | 实时检测框参数 | int | 是 | 2:车位线圈<br>4:车检现况


# 识别和车位相关配置
## 车位线圈
### 1.获取车位线圈配置
- request
```
{
  "type": "get_alg_road_rule_param",
  "chnlid": 0,
  "module": "ALG_REQUEST_MESSAGE"
}
```
- response
```
{
  "body": {
    "road_rule_param": {
      "reco_zone_rule": [
        {
          "enable": 1,
          "point": [
            {
              "x": 937,
              "y": 576
            },
            {
              "x": 1245,
              "y": 534
            },
            {
              "x": 1280,
              "y": 666
            },
            {
              "x": 954,
              "y": 704
            }
          ],
          "point_num": 4,
          "zone_id": 0,
          "zone_name": "MjIyMg==",
          "zone_type": 1
        },
        {
          "enable": 1,
          "point": [
            {
              "x": 942,
              "y": 717
            },
            {
              "x": 1285,
              "y": 675
            },
            {
              "x": 1326,
              "y": 867
            },
            {
              "x": 959,
              "y": 903
            }
          ],
          "point_num": 4,
          "zone_id": 1,
          "zone_name": "UEFSSzAwMDQ=",
          "zone_type": 1
        }
      ],
      "retention_zone_rule": [
        {
          "enable": 0,
          "point": [
            {
              "x": 10,
              "y": 10
            },
            {
              "x": 200,
              "y": 10
            },
            {
              "x": 200,
              "y": 200
            },
            {
              "x": 10,
              "y": 200
            }
          ],
          "point_num": 4,
          "zone_id": 0,
          "zone_name": "6L2m5L2N5biD6ZiyMQ==",
          "zone_type": 3,
          "decision_time": 60
        }
      ],
      "deploy_zone_rule_num": 1,
      "reco_zone_rule_num": 5,
      "reco_zone_size_factor": {
        "factor_h": 2048,
        "factor_w": 2048
      }
    }
  },
  "err_msg": "All done",
  "state": 200,
  "type": "get_alg_road_rule_param"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chnlid  | 通道ID | int | 是 | 单通道默认0
road_rule_param | 规则框参数 | object | 是 |
reco_zone_size_factor | 规则框参数坐标系数 | object | 是 | 
factor_h | 规则框参数坐标系数高度 | int | 是 | 默认填2048
factor_w | 规则框参数坐标系数宽度 | int | 是 |默认填2048
reco_zone_rule_num | 车位框个数 | int | 是 |
deploy_zone_rule_num | 布防线圈个数 | int | 是 |
enable | 是否启用 | int | 是 | 0：禁用；<br>1：启用
reco_zone_rule | 车位框参数 | object | 是 |
retention_zone_rule | 行人滞留线圈参数 | object | 否 |
zone_id | 线圈id | int | 是 | 从0开始
zone_name | 线圈名 | string | 是 | utf8 + base64编码
zone_type | 线圈类型 | int | 是 | 0:是识别区域<br>1:是虚拟线圈<br>2:车道布防线圈<br>3:行人滞留线圈
decision_time | 滞留判定时间 | int | 否 | 单位秒
point_num | 坐标点个数 | int | 是 | 
x | 坐标点x | int | 是 | 
y | 坐标点y | int | 是 | 

### 2.设置车位线圈配置
- request
```
{
  "body": {
    "road_rule_param": {
      "reco_zone_rule": [
        {
          "enable": 1,
          "point": [
            {
              "x": 937,
              "y": 576
            },
            {
              "x": 1245,
              "y": 534
            },
            {
              "x": 1280,
              "y": 666
            },
            {
              "x": 954,
              "y": 704
            }
          ],
          "point_num": 4,
          "zone_id": 0,
          "zone_name": "MjIyMg==",
          "zone_type": 1
        },
        {
          "enable": 1,
          "point": [
            {
              "x": 942,
              "y": 717
            },
            {
              "x": 1285,
              "y": 675
            },
            {
              "x": 1326,
              "y": 867
            },
            {
              "x": 959,
              "y": 903
            }
          ],
          "point_num": 4,
          "zone_id": 1,
          "zone_name": "UEFSSzAwMDQ=",
          "zone_type": 1
        }
      ],
      "retention_zone_rule": [
        {
          "enable": 0,
          "point": [
            {
              "x": 10,
              "y": 10
            },
            {
              "x": 200,
              "y": 10
            },
            {
              "x": 200,
              "y": 200
            },
            {
              "x": 10,
              "y": 200
            }
          ],
          "point_num": 4,
          "zone_id": 0,
          "zone_name": "6L2m5L2N5biD6ZiyMQ==",
          "zone_type": 3,
          "decision_time": 60
        }
      ],
      "deploy_zone_rule_num": 1,
      "reco_zone_rule_num": 5,
      "reco_zone_size_factor": {
        "factor_h": 2048,
        "factor_w": 2048
      }
    }
  },
  "type": "set_alg_road_rule_param",
  "chnlid": 0,
  "module": "ALG_REQUEST_MESSAGE"
}
```
- response
```
{
   "err_msg": "All done",
   "state": 200,
   "type" : "set_alg_road_rule_param"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
module | 处理模块对应的星形结构消息 | string(0,32] | 是 |
type | 消息类型 | string(0,32] | 是 |
state | 回复状态 | int[0, 1000] | 是 | 
err_msg | 错误信息 | string(0,32] | 是 | 
chnlid  | 通道ID | int | 是 | 单通道默认0
road_rule_param | 规则框参数 | object | 是 |
reco_zone_size_factor | 规则框参数坐标系数 | object | 是 | 
factor_h | 规则框参数坐标系数高度 | int | 是 | 默认填2048
factor_w | 规则框参数坐标系数宽度 | int | 是 |默认填2048
reco_zone_rule_num | 车位框个数 | int | 是 |
deploy_zone_rule_num | 布防线圈个数 | int | 是 |
enable | 是否启用 | int | 是 | 0：禁用；<br>1：启用
reco_zone_rule | 车位框参数 | object | 是 |
retention_zone_rule | 行人滞留线圈参数 | object | 否 |
zone_id | 线圈id | int | 是 | 从0开始
zone_name | 线圈名 | string | 是 | utf8 + base64编码
zone_type | 线圈类型 | int | 是 | 0:是识别区域<br>1:是虚拟线圈<br>2:车道布防线圈<br>3:行人滞留线圈
decision_time | 滞留判定时间 | int | 否 | 单位秒
point_num | 坐标点个数 | int | 是 | 
x | 坐标点x | int | 是 | 
y | 坐标点y | int | 是 | 

## 车位模式协议
### 1.获取车位模式属性
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

### 2.获取车位模式
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

### 3.设置车位模式
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

## 停车场编号
### 1.获取停车场编号
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

### 2.设置停车场编号
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

## 基础识别参数
### 1.获取基础识别设置属性
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

### 2.获取基础识别设置
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
    "recognition_type": -2139086849,
    "filtfakeplate": {
      "enable":1,
      "mode":0,
      "threshold":93
    },
    "car_type_support": 1,
    "car_brand_support": 1
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
recognition_type | 识别类型 | int | 是 | 0x00000001:蓝牌<br>0x00000002:黄牌<br>0x00000004:黑牌<br>0x00000008:新能源<br>0x00000010:教练车<br>0x00000020:警车<br>0x00000040:武警车<br>0x00000080:军车<br>0x00000100:港澳<br>0x00000200:领馆车<br>0x00000400:使馆车<br>0x00000800:民航<br>0x00001000:应急<br>0x00800000:非机动车<br>0x80000000:无牌车<br>
filtfakeplate | 车牌防伪 | object | 是 |
enable | 车牌防伪是否开启 | int[0,1] | 是 | 0：关闭；<br>1：开启
mode | 车牌防伪模式 | int[0,1] | 是 | 0：虚假车牌告警；<br>1：虚假车牌过滤
threshold | 车牌防伪匹配度 | int[0,100] | 是 | 53：低；<br>73：中；<br>93：高
car_type_support | 车型支持 | int[0,1] | 是 | 0：关闭；<br>1：开启
car_brand_support | 车标支持 | int[0,1] | 是 | 0：关闭；<br>1：开启

### 3.设置基础识别设置
- Request
```
{
  "module": "ALG_REQUEST_MESSAGE",
  "type": "set_alg_road_reco_param",
  "chnlid": 0,
  "body": {
    "default_initial": 26,
    "default_province": 255,
    "recognition_pixel": {
      "max": 600,
      "min": 80
    },
    "recognition_type": -2139086849,
    "filtfakeplate": {
      "enable": 1,
      "mode": 0,
      "threshold": 93
    },
    "car_type_support": 1,
    "car_brand_support": 1
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
recognition_type | 识别类型 | int | 是 | 0x00000001:蓝牌<br>0x00000002:黄牌<br>0x00000004:黑牌<br>0x00000008:新能源<br>0x00000010:教练车<br>0x00000020:警车<br>0x00000040:武警车<br>0x00000080:军车<br>0x00000100:港澳<br>0x00000200:领馆车<br>0x00000400:使馆车<br>0x00000800:民航<br>0x00001000:应急<br>0x00800000:非机动车<br>0x80000000:无牌车<br>
filtfakeplate | 车牌防伪 | object | 是 |
enable | 车牌防伪是否开启 | int[0,1] | 是 | 0：关闭；<br>1：开启
mode | 车牌防伪模式 | int[0,1] | 是 | 0：虚假车牌告警；<br>1：虚假车牌过滤
threshold | 车牌防伪匹配度 | int[0,100] | 是 | 53：低；<br>73：中；<br>93：高
car_type_support | 车型支持 | int[0,1] | 是 | 0：关闭；<br>1：开启
car_brand_support | 车标支持 | int[0,1] | 是 | 0：关闭；<br>1：开启

## 高级识别参数
### 1.获取高级识别参数属性
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

### 2.获取高级识别参数
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

### 3.设置高级识别参数
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

## 识别结果
### 1.实时/稳定结果（算法库->应用层）
- request
```
{
  "body": {
    "road_trigger_result": {
      "result": [
        {
          "alarm_info": {
            "alarm_status": 0
          },
          "car_series": "",
          "group_id": -1,
          "head_loc": {
            "bottom": 0,
            "left": 0,
            "right": 0,
            "top": 0
          },
          "nonmotor_id": -1,
          "nonMotor_loc": {
            "bottom": 0,
            "left": 0,
            "right": 0,
            "top": 0
          },
          "out_video_start": 0,
          "parking_state": 8,
          "plate_color": 0,
          "plate_loc": {
            "bottom": 0,
            "left": 0,
            "right": 0,
            "top": 0
          },
          "plate_str": "",
          "plate_type": 0,
          "reco_flag": 1,
          "tail_loc": {
            "bottom": 0,
            "left": 0,
            "right": 0,
            "top": 0
          },
          "time_pts": 164260457,
          "time_s": 1617943145,
          "zone_id": 0,          
          "zone_name": "WUItMDAx"
        }
      ],
      "result_num": 1,
      "trigger_extend": {
        "user_data": "",
        "zone_id": -1
      },
      "trigger_type": 8
    }
  },
  "chnlid": 0,
  "type": "road_trigger_result"
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
chnlid | 适配通道 | int | 是 | 0
type | 消息类型 | string(0,32] | 是 | 固定为"road_trigger_result"
body | 消息体 | object | 是 | 
road_trigger_result | 触发结果数据 | object | 是 | 
trigger_type | 触发类型 | int | 是 | 5:虚拟线圈触发;<br>6:稳定触发;<br>7:IO强制触发;<br>8:手动触发;<br>9:SDK抓拍;<br>10:实时结果（车辆实时入场事件）<br>12:单帧识别结果;<br>13:定时触发;
trigger_extend | 抓拍扩展信息 | object | 否 | 
zone_id | 抓拍扩展指定车位id | int | 否 | 
user_data | 用户数据 | string | 否 | 
result_num | 结果个数 | int | 是 | 
result | 结果数据 | array | 是 | 
alarm_info | 报警信息 | object | 是 |
alarm_status | 报警状态 | int | 是 | 0：正常停车<br>1:视频遮挡<br>2:视频丢失<br>3：跨车位停车<br>4：非机动车占位<br>5：车头/车尾方向不一致<br>6：车牌遮挡<br>7：无牌车<br>8：非准入停车<br>9：行人滞留
car_series | 车辆结构化信息 | string | 否 | 
group_id | 组id | int | 是 |
nonmotor_id | 非机动车id | int | -1:无非机动车
out_video_start | 离场开始录像标识 | int | 是 | 
parking_state | 车位状态 | int | 是 | 0x01：入场；<br>0x02：在场；<br>0x04：出场；<br>0x08：空场；<br>0x10：车位异常；<br>0x20：延迟上报出场；<br>0x40：合并出入场；<br>0x80：预入场；<br>0x100：预出场；<br>0x200：入场修正
plate_color | 车牌颜色 | int | 是 |
plate_str | 车牌 | int | 是 |
plate_type | 车牌类型 | int | 是 |
reco_flag | 识别标识 | int | 是 |
time_pts | pts时间 | int | 是 |
time_s | utc时间 | int | 是 |
zone_id | 车位ID | int | 是 | 
zone_name | 车位名 | string | 是 | utf8 + base64
plate_loc | 车牌位置 | object | 否 | 
nonMotor_loc | 车牌位置 | object | 否 | 
head_loc | 车头位置 | object | 否 | 
tail_loc | 车尾位置 | object | 否 | 
left | 位置left坐标 | int | 是 |
right | 位置right坐标 | int | 是 |
top | 位置top坐标 | int | 是 |
bottom | 位置bottom坐标 | int | 是 |

### 2.稳定结果（应用层->other）
- request
```
{
  "type": "IVS_RESULT_NOTIFY",
  "body": {
    "reco_id": 16,
    "serial": 931149,
    "time_s": 1584081641,
    "trigger_type": 8,
    "chnlid": 0,
    "device_info": {
      "dev_name": "SVZT",
      "ip": "192.168.114.35",
      "sn": "f12a31b2-6c35db17"
    },
    "alarm_info": {
      "alarm_status": 3
    },
    "bg_img": [
      {
        "image": "base64_data of background jpg",
        "image_length": 0,
        "image_send_flag": 1,
        "key": 8,
        "path": "VnpJUENDYXAvMjAyMF8xMV8yNi8xNjA1MDk5OTA2X1I4X2ZldHVyZV9fX+aXoF9fLmpwZw==",
        "resolution": {
          "height": 1080,
          "width": 1920
        }
      }
    ],
    "feture_img": [
      {
        "type": 0,
        "image": "base64_data of feture jpg",
        "image_length": 0,
        "image_send_flag": 1,
        "key": 16,
        "path": "VnpJUENDYXAvMjAyMF8xMV8yNi8xNjA1MDk5OTA2X1I4X2ZldHVyZV9fX+aXoF9fLmpwZw==",
        "resolution": {
          "height": 36,
          "width": 91
        }
      }
    ],
    "product_h": {
      "car_pos": {
        "loc": {
          "bottom": 0,
          "left": 0,
          "right": 0,
          "top": 0
        },
        "pos": 0
      },
      "parking": {
        "loc": {
          "point": [
            {
              "x": 59,
              "y": 1072
            },
            {
              "x": 800,
              "y": 1328
            },
            {
              "x": 781,
              "y": 1980
            },
            {
              "x": 50,
              "y": 1917
            }
          ],
          "point_num": 4,
          "reco_zone_size_factor": {
            "factor_h": 2048,
            "factor_w": 2048
          }
        },
        "parking_state": 16,
        "zone_id": 0,
        "zone_name": "WUItMDAx"
      },
      "plate": {
        "color": 0,
        "confidence": 100,
        "loc": {
          "bottom": 5,
          "left": 8,
          "right": 1912,
          "top": 1072
        },
        "plate": "X1/ml6BfXw==",
        "type": 0
      },
      "reco": {
        "group_id": -1,
        "reco_flag": 1,
        "reco_id": 16,
        "reco_time": "2020-03-13 14:40:41"
      }
    }
  }
}
```
- 参数释义

字段名称 | 字段含义 | 取值范围 | 是否必须 | 备注
---|---|---|---|---
chnlid | 适配通道 | int | 是 | 0
type | 消息类型 | string(0,32] | 是 | 固定为"road_trigger_result"
body | 消息体 | object | 是 | 
reco_id | 识别id | int | 是 |
serial | 结果序列号 | int | 是 | 
time_s | UTC时间 | int | 是 |
trigger_type | 触发类型 | int | 是 | 5:虚拟线圈触发;<br>6:稳定触发;<br>7:IO强制触发;<br>8:手动触发;<br>9:SDK抓拍;<br>10:实时结果（车辆实时入场事件）<br>12:单帧识别结果;<br>13:定时触发;
chnlid | 视频通道号 | int | 是 | 单通道时为0
device_info | 设备信息对象 | object | 是 |
dev_name | 设备名 | string | 是 | UTF8+BASE64编码
ip | 设备ip地址 | string | 是 |
sn | 设备sn编号 | string | 是 |
alarm_info | 报警信息对象 | object | 是 |
alarm_status | 报警状态 | int | 是 | 0:无报警,默认值(取消报警)<br>1:视频遮挡<br>2:视频丢失<br>3:占用双车位/压线停车<br>4:非机动车/摩托车<br>5:车头/车尾方向不一致<br>6:车牌遮挡<br>7:无牌车<br>8：非准入停车<br>9：行人滞留（10-99:保留）<br>100:FLASH分区损坏<br>101:SD卡不可用<br> ==只有“占用双车位/压线停车”和“车头/车尾方向不一致”,报警属于证据链，其他报警不能合并到证据链中==
bg_img | 背景图信息对象(数组)  | array | 否 |
feture_img  | 特征图信息对象(数组) | array | 否 |
image | 图片数据 | string | 是 | base64格式的数据
image_length | 图片原始大小| int | 是 | 字节数
image_send_flag | 图片发送标志 | int | 是 |
key | 图片的索引id | int | 是 |
path | 图片缓存的路径名 | string | 是 | UTF8+BASE64编码
resolution | 图片分辨率 | object | 是 |
height | 图片高 | int | 是 | 
width | 图片宽 | int | 是 |
product_h | 路内产品信息 | object | 是 |
car_pos | 辆信息对象 | object | 是 |
loc | 位置坐标对象 | object | 是 | 按照背景图的分辨率
bottom | 下 | int | 是 |
left | 左 | int | 是 |
right | 右 | int | 是 |
top | 上 | int | 是 |
pos | 车头车尾信息 | int | 是 | 0:无效;<br>1:车头;<br>2:车尾
parking | 车位信息对象 | object | 是 |
parking_state | 车位状态 | int | 是 | 0x01：入场；<br>0x02：在场；<br>0x04：出场；<br>0x08：空场；<br>0x10：车位异常；<br>0x20：延迟上报出场；<br>0x40：合并出入场；<br>0x80：预入场；<br>0x100：预出场；<br>0x200：入场修正
zone_id | 车位id | int | 是 |
zone_name | 车位名 | string | 是 | UTF8+BASE64编码
point_num | 坐标点个数 | int | 是 |
reco_zone_size_factor | 标点坐标系尺寸 | object | 是 |
factor_h | 坐标点坐标系尺寸高度 | int | 是 |
factor_w | 坐标点坐标系尺寸宽度 | int | 是 |
point | 坐标点 | array | 是 |
x | 点x坐标 | int | 是 |
y | 点y坐标 | int | 是 |
plate | 车牌信息对象 | object | 是 |
color | 车牌颜色 | int | 是 |0:未知;<br>1:蓝色;<br>2:黄色;<br>3:白色;<br>4:黑色;<br>5:绿色;
confidence | 车牌置信度 | int | 是 |
plate | 车牌 | string | 是 | UTF8后再BASE64编码<br>如果有车牌:真实车牌号<br>如果有车无牌:无牌车<br>如果无车无牌:无<br>非机动车:非机动车
type | 车牌类型 | int | 是 | 1:蓝牌<br>2:黄牌<br>3:黑牌<br>4:新能源<br>5:教练车<br>6:警车<br>7:武警车<br>8:军车<br>9:港澳<br>10:领馆车<br>11:使馆车<br>12:民航<br>13:应急<br>24:非机动车
reco | 识别信息对象 | object | 是 |
group_id | 识别组id | int | 是 |
reco_flag | 识别标志 | int | 是 |
reco_time | 识别时间(字符串格式时间) | string | 是 |

# 其他

