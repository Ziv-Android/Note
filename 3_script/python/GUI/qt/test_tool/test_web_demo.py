import json
import sys

from libutils.zlog import ZLog
from libutils.webclient import WEBClient

url = "http://192.168.17.203:80"


# 登录
wc = WEBClient(url, "admin", "admin")


# 获取网络参数
def get_net_cfg():
    cmd = '''{
        "module": "SS_BUS_REQUEST",
        "type": "ss_get_rj45_net"
    }'''
    status, resp = wc.posts(cmd)
    print(status)
    print(resp)


# 获取设备信息
def get_dev_info():
    cmd = '''{
        "module":"BUS_WEB_REQUEST",
        "type":"get_device_info"
    }'''
    status, resp = wc.posts(cmd)
    print(status)
    print(resp)


# 手动触发: H需要body内容
def avs_trigger():
    cmd = '''{
        "module":"ALG_REQUEST_MESSAGE",
        "type":"avs_trigger",
        "body":{
            "trigger_result":1,
            "trigger_type":0
        }
    }'''

    status, resp = wc.posts(cmd)
    print(status)
    print(resp)


# 升级文件:完整路径
def update_system(filename):
    status, resp = wc.update(filename)
    print(status)
    print(resp)


# avs_trigger()
# update_system("E:/2021VZENITH/PROJ-H1M/image/VZ_H1S_13.1.0.2021091503_u913211951k914211840r913211958a2021091503.bin")

# get_net_cfg()
get_dev_info()

