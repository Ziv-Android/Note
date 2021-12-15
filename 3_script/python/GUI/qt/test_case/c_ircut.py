import time
from libutils.webclient import WEBClient

'''
# request
{
    "module":"AVS_REQUEST_MESSAGE",
    "type":"ircut_params",
    "body": {
        "ircut": 0
    }
}

字段名称:body.ircut:
字段含义:IR-CUT控制
取值范围:1:白天模式; 0:夜间模式
'''

cmd_tmp = '''{
            "module":"AVS_REQUEST_MESSAGE",
            "type":"ircut_params",
            "body": {
                "ircut":%d
            }
        }'''

def c_ircut(webc, value):
    cmd = cmd_tmp % (value)
    # print('c_lens %s' % cmd)
    if webc == None:
        print('webc none')
        return 404

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret
    # print(resp)


def c_ircut_day(webc):
    c_ircut(webc, 1)


def c_ircut_night(webc):
    c_ircut(webc, 0)


# webc = WEBClient("http://192.168.6.30", "admin", "admin")
# ret = webc.login()
# if ret:
#     c_itcut_night(webc)
#     time.sleep(1)
#     c_itcut_day(webc)
