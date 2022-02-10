## 登录页
### 操作接口
登录：
Request URL: http://192.168.13.202/login.php
Request Method: POST

Set-Cookie: sessionID=209192407


### 数据获取接口

## 设置页
### 操作接口

### 数据获取接口




## 实时视频页
### 操作接口
保存规则
Request URL: http://192.168.13.202/avsjson.php
Request Method: POST
{"type":"AVS_SET_VIRLOOP_PRM","body":{"virtualloop":{"max_plate_width":400,"min_plate_width":45,"dir":0,"trigger_gap":10,"loop":[{"enable":true,"point_num":4,"point":[{"x":2398,"y":12005},{"x":13985,"y":12005},{"x":15975,"y":13982},{"x":408,"y":13982}]}],"virtualloop_num":1}}}

{"type":"AVS_SET_RECO_PRM","body":{"recognition_area":{"polygon":[{"enable":false,"point_num":0,"point":[]}],"polygon_num":0}}}

{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"02:00:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"02:00:00","time_end":"09:00:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"09:00:00","time_end":"24:00:00","timectrl_enable":true,"led_level":1,"id":2}],"led_mode":2}}

手动触发
Request URL: http://192.168.13.202/avstrigger.php?_=1644478969151
Request Method: GET


Request URL: http://192.168.13.202/request.php
Request Method: POST
云台控制
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":8,"degree":0}}
电子变倍
{"type":"set_avs_focus_prm","module":"AVS_REQUEST_MESSAGE","body":{"auto_focus":0,"digital_ptz_enable":false,"digital_zoom":1.1,"focus_step":0,"focus_type":0,"digital_ptz_window_size":{"height":0,"width":0,"x":0,"y":0}}}
### 数据获取接口

## 登录页
### 操作接口

### 数据获取接口

## 登录页
### 操作接口

### 数据获取接口

## 登录页
### 操作接口

### 数据获取接口

