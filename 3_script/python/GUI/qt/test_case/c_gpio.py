import json
import time
from libutils.webclient import WEBClient

'''
# 测试IO
# request
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_gpio_test_ctrl",
    "body":{
        "io_opera":2,
        "io_type":1,
        "io_number":0,
        "io_status":0
    }
}

字段名称:body.io_opera
字段含义:IO操作
取值范围:1=set,2=get

字段名称:body.io_number
字段含义:IO-IN\OUT序号
取值范围:0...n

字段名称:body.io_type
字段含义:IO类型
取值范围:1=IN;2=OUT;3=RESET

字段名称:body.io_status
字段含义:IO操作
取值范围:0=low,1=high,2=square

# response
{
    "module":"EVS_BUS_REQUEST",
    "type":"evs_gpio_test_ctrl"
    "state":200,
    "err_msg":"All done",
    "body":{
        "io_status":1
    }
}
字段名称:body.io_status
字段含义:操作返回.如果opera=set,返回io_status,否则无此字段
取值范围:0=low,1=high
'''

cmd_tmp = '''{
            "module":"EVS_BUS_REQUEST",
            "type":"evs_gpio_test_ctrl",
            "body":{
                "io_opera":%d,
                "io_type":%d,
                "io_number":%d,
                "io_status":%d
            }
        }'''


def c_gpio(webc, opera, type, number, status):
    cmd = cmd_tmp % (opera, type, number, status)
    # print('c_gpio %s' % cmd)
    if webc == None:
        print('webc none')
        return 404, None

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret, resp
    # print(resp)


def c_gpio_set(webc, number, status):
    ret, resp = c_gpio(webc, 1, 2, number, status)
    return ret


def c_gpio_get(webc, type, number):
    ret, resp = c_gpio(webc, 2, type, number, 0)
    if ret == 200:
        print(resp)
        jr = json.loads(resp)
        return int(jr['body']['io_status'])
    return -1


# webc = WEBClient('http://192.168.6.30', 'admin', 'admin')
# out_num = 1
# ret = c_gpio_set(webc, out_num, 1)
# time.sleep(0.2)
# ret = c_gpio_get(webc, 2, out_num)
# print("ret IO-OUT:%d" % ret)
# ret = c_gpio_get(webc, 1, 0)  # io-0
# print("ret IO-IN:%d" % ret)
# time.sleep(1)
# ret = c_gpio_set(webc, out_num, 0)
# time.sleep(0.2)
# ret = c_gpio_get(webc, 2, out_num)
# print("ret IO-OUT:%d" % ret)
# ret = c_gpio_get(webc, 1, 0)  # io-0
# print("ret IO-IN:%d" % ret)


