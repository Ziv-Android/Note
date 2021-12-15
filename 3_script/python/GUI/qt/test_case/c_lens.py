import time
from libutils.webclient import WEBClient

'''
# request
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

自动名称:body.option:   
字段含义:操作类型
取值范围:0:复位
        1:设置超时时间
        2:开始运行对焦
        3:保持对焦
        4:停止对焦
        5:执行一次自动对焦

字段名称:body.motor:   
字段含义:动作电机
取值范围:0:变焦电机; 1:变倍电机

字段名称:body.runmode:   
字段含义:运行模式
取值范围:1:正向自由运行; 2:反向自由运行

字段名称:body.value:   
字段含义:参数值
取值范围:当option=1时,此字段表示超时时间，单位毫秒(ms)
        当option=2时,此字段表示步长
        当option=4且motor=1时,此字段表示变倍后是否自动聚焦（1:自动聚焦;0:不自动聚焦）

# response
{
    "state":200,
    "type":"avs_focus",
    "err_msg":"All done"
}
'''

cmd_tmp = '''{
            "type":"avs_focus",
            "module":"AVS_REQUEST_MESSAGE",
            "body":{
                "option":%d,
                "motor":%d,
                "runmode":%d,
                "value":%d
            }
        }'''


def c_lens(webc, option, motor, runmode, value):
    cmd = cmd_tmp % (option, motor, runmode, value)
    # print('c_lens %s' % cmd)
    if webc == None:
        print('webc none')
        return 404

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret
    # print(resp)


# 自动对焦
def c_lens_autofocus(webc):
    c_lens(webc, 5, 0, 0, 0)


# 保持运动
def c_lens_keep(webc, motor, runmode):
    c_lens(webc, 3, motor, runmode, 0)


# 停止运动
def c_lens_stop(webc, motor, runmode):
    c_lens(webc, 4, motor, runmode, 0)


# zoom-in
def c_lens_zoom_in(webc, value=25):
    motor = 1
    runmode = 2
    c_lens(webc, 2, motor, runmode, value)
    return motor, runmode


# zoom-out
def c_lens_zoom_out(webc, value=25):
    motor = 1
    runmode = 1
    c_lens(webc, 2, motor, runmode, value)
    return motor, runmode


# focus-in
def c_lens_focus_in(webc, value=25):
    motor = 0
    runmode = 2
    c_lens(webc, 2, motor, runmode, value)
    return motor, runmode


# focus-out
def c_lens_focus_out(webc, value=25):
    motor = 0
    runmode = 1
    c_lens(webc, 2, motor, runmode, value)
    return motor, runmode


# webc = WEBClient("http://192.168.6.30", "admin", "admin")
# ret = webc.login()
# if ret:
#     c_lens_autofocus(webc)
