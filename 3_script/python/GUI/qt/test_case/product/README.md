# 产品配置说明
## 订单客户配置
配置路径：product -> h -> customer.ini
配置模板：
```text
[c01]
name=自研
info=通用协议
pname=
library=
```

字段说明：

字段 | 含义 | 注意
--- | --- | ---
`[c01]` | 配置序号关键字 | 不可使用中文，不能添加已有重复项，建议按顺序递增
`name` | 订单客户名称 | 
`info` | 使用协议 | 
`pname` | 自定义协议名 |
`library` | 使用的so库名称 |

## 产品型号配置
配置路径：product -> h -> 协议名(使用通用协议时，忽略此路径) -> `[产品型号]`.ini 注意：**文件名对应产品型号**    
配置模板：
```text
[info]
desc=自研15寸形态,单目:变焦3.6-11mm
bv=12319
path=153611.png

[capacity]
# lens: 0=短焦,1=长焦,2=广角
lens=2	
# dlens: 1=双目,0=单目
dlens=0
num_max_stop=4
num_max_stop_long=6
# video: 视频相关测试
video=hs_lens_ircut_ptz_led
# io_in: 1=1个;2=2个
io_in=1
io_out=2
serial=2
io_reset=1
# net_type: 网卡类型 100=百兆，1000=千兆
net_type=1000
```

字段说明：

字段 | 含义 | 注意
--- | --- | ---
`[info]` | 产品信息关键字 | 不可变
`desc` | 产品描述，简略描述产品配置 | 用于界面显示
`bv` | 硬件版本（board version） | 
`path` | 产品图像文件名称 | 填写后需要在image目录下添加对应的产品图像文件
`[capacity]` | 产品配置信息关键字 | 不可变
`lens` | 镜头类型 | 0=短焦,1=长焦,2=广角
`dlens` | 镜头数量 | 1=双目,0=单目
`num_max_stop` | 最大泊车数 | 
`num_max_stop_long` | 双目长焦最大泊车数 |
`num_485` | 485模块数 |
`video` | 视频相关测试 | hs_lens_ircut_ptz_led，lens=镜头，ircut=白天/夜间，ptz=云台，led=补光灯
`io_in` | IO输入 | 1=1个; 2=2个
`io_out` | IO输出 | 
`serial` | 串口 | 
`io_reset` | IO复位 | 
`net_type` | 网卡类型 | 100=百兆，1000=千兆