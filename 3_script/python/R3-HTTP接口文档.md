## 登录页
### 操作接口
登录：
Request URL: http://192.168.13.202/login.php
Request Method: POST

Set-Cookie: sessionID=209192407

body:
rJIMYtjY2NgYtbky3tuwOy27rg: =


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

http://192.168.13.202/login.php
rJIMYtjY2NgYtbky3tuwOy27rg: =

http://192.168.13.202/getauth.php
{"type":"get_user_auth"}

http://192.168.13.202/genvictetc.php
{"type":"etc_get_enable"}

http://192.168.13.202/request.php
{"type":"get_device_capacity","module":"SS_BUS_REQUEST"}
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}
{"type":"get_avs_focus_prm","module":"AVS_REQUEST_MESSAGE"}
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}

http://192.168.13.202/getivsctrl.php
8:1:MA: =

http://192.168.13.202/systemjson.php
{"type":"get_net_and_port"}
{"type":"ss_get_devname"}
{"type":"get_device_info"}
{"type":"ss_get_ntp_cfg"}

http://192.168.13.202/dgjson.php
{"type":"get_group_cfg"}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_LED_PROP"}
{"type":"AVS_GET_ALG_RESULT_PROP"}
{"type":"AVS_GET_LED_CTRL"}
{"type":"AVS_GET_ALG_RESULT_PARAM"}
{"type":"AVS_GET_CAPTURE_PRM"}
{"type":"get_new_energy_plate_support"}
{"type":"get_car_info_support"}

http://192.168.13.202/geteventruleexhtm.php
0

http://192.168.13.202/dboprnew.php
{"type":"get_wl_check_status"}




