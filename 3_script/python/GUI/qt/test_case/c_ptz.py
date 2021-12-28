#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from libutils.webclient import WEBClient

'''
# 云台:上\下\左\右\复位控制
# request
{
    "type":"set_cloud_ctrl",
    "module":"BUS_REQUEST_MSG",
    "body":{
        "cmd":2, 
        "value":-1
    }
}
自动名称:body.cmd:   
字段含义:方向 
取值范围:0，设置超时时间
       1，保持继续移动
       2，向上移动
       4，向下移动
       8，停止上下移动
       16，向左移动
       32，向右移动
       64，停止左右移动
       128，还原
备   注:cmd为1时们需要指定保持的方向，比如保持向上移动时cmd填3，保持向下移动时cmd填5......

自动名称:body.value
字段含义:角度
取值范围:Int[0~65535] 
备   注:当cmd是0(设置超时时间)时，此字段表示超时时间，单位毫秒；其他情况时，可以不传或者填-1

# response
{
    "state":200,
    "type":"set_cloud_ctrl",
    "error_msg":"All done"
}

'''

cmd_tmp = '''{
            "type":"set_cloud_ctrl",
            "module":"BUS_REQUEST_MSG",
            "body":{
                "cmd":%d,
                "value":%d
            }
        }'''


def c_ptz(webc, ctrl, value):
    cmd = cmd_tmp % (ctrl, value)
    # print('c_ptz %s' % cmd)
    if webc == None:
        print('webc none')
        return 404

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret
    # print(resp)


# 保持运动;
# ctrl: 上下左右动作返回值+1
# 例如: ret = c_ptz_up(webc)
#      c_ptz_keep(webc, ret+1)
def c_ptz_keep(webc, ctrl):
    ret = c_ptz(webc, ctrl, -1)
    print('c_ptz_keep %d ctrl=%d' % (ret, ctrl))


# 上
def c_ptz_up(webc):
    ret = c_ptz(webc, 2, -1)
    print('c_ptz_up %d' % ret)
    return 2


# 下
def c_ptz_down(webc):
    ret = c_ptz(webc, 4, -1)
    print('c_ptz_down %d' % ret)
    return 4


# 停止上下
def c_ptz_stop_ud(webc):
    ret = c_ptz(webc, 8, -1)
    print('c_ptz_stop_ud %d' % ret)


# 左
def c_ptz_left(webc):
    ret = c_ptz(webc, 16, -1)
    print('c_ptz_left %d' % ret)
    return 16


# 右
def c_ptz_right(webc):
    ret = c_ptz(webc, 32, -1)
    print('c_ptz_right %d' % ret)
    return 32


# 停止左右
def c_ptz_stop_lr(webc):
    ret = c_ptz(webc, 64, -1)
    print('c_ptz_stop_lr %d' % ret)


# 复位
def c_ptz_reset(webc):
    ret = c_ptz(webc, 128, -1)
    print('c_ptz_reset %d' % ret)
    return ret == 200
