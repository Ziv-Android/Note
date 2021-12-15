import json
import time

from c_rs485 import *
from oqc_tool import *
from libutils.webclient import WEBClient

# {"type":"get_platform","module":"BUS_REQUEST_MSG"}:
# {"body":{"lib_name":"libcustom_lifang.so","platform_name":"lifang"},"err_msg":"All Done","state":200,"type":"get_platform"}

# {"type": "set_platform", "module": "BUS_REQUEST_MSG","body": {"platform_name": "lifang", "lib_name": "libcustom_lifang.so"}}
# {"err_msg":"All Done","state":200,"type":"set_platform"}
# 设置定制协议


def cfg_factory_param_customer(webc, name, library):
    scmd = '''{
                "module": "BUS_REQUEST_MSG",
                "type": "set_platform", 
                "body": {"platform_name": "%s", "lib_name": "%s"}
        }''' % (name, library)
    if webc is None:
        print('webc none')
        return False

    ret = 404
    if not webc.login():
        print('webc.login failed')
        return False

    print('customer %s,library %s' % (name, library))
    ret, resp = webc.posts(scmd)
    if ret != 200:
        print('webc.posts scmd failed.')
        return False

    rcmd = '''{"module":"BUS_REQUEST_MSG","type":"get_platform"}'''
    ret, resp = webc.posts(rcmd)
    if ret != 200:
        print('webc.posts rcmd failed.')
        return False

    jl = json.loads(resp)
    pname = jl['body']['platform_name']
    libname = jl['body']['lib_name']
    if name != pname or library != libname:
        return False

    return True


# {"type":"set_lens_mode","module":"SERIAL_COMM_MSG","body":{"mode":0,"max_plate_num":3,"is_double":0}}:
# {"body":{"type":"set_lens_mode"},"err_msg":"All Done","state":200,"type":"set_lens_mode"}

# {"type": "get_lens_mode", "module": "SERIAL_COMM_MSG"}:
# {"body":{"is_double":0,"max_plate_num":3,"mode":0,"type":"get_lens_mode"},"err_msg":"All Done","state":200,"type":"get_lens_mode"}
# 设置镜头型号:镜头类型, 双目
def cfg_factory_param_product(webc, lens, dlens):
    scmd = '''{
                "module":"SERIAL_COMM_MSG",
                "type":"set_lens_mode",
                "body":{"max_plate_num":3,"mode":%d,"is_double":%d}
        }''' % (lens, dlens)
    if webc is None:
        print('product webc none')
        return False

    ret = 404
    if not webc.login():
        print('product webc.login failed')
        return False

    print('product is double %d, lens %d' % (dlens, lens))
    ret, resp = webc.posts(scmd)
    if ret != 200:
        print('product webc.posts scmd failed.')
        return False

    rcmd = '''{"module": "SERIAL_COMM_MSG", "type": "get_lens_mode"}'''
    ret, resp = webc.posts(rcmd)
    if ret != 200:
        print('product webc.posts rcmd failed.')
        return False

    print(resp)
    jl = json.loads(resp)
    mode = int(jl['body']['mode'])
    is_double = int(jl['body']['is_double'])
    if mode != lens or dlens != is_double:
        print('mode != type or dlens != is_double')
        return False

    return True


# 双目，接了485的=1.100，未接485=1.101
def cfg_factory_param_dlens(devs, username, password):
    gateway = '255.255.255.0'
    netmask = '192.168.111.1'
    temp_host = ['192.168.111.34', '192.168.111.32', '192.168.111.33']

    i = 0

    dev = devs[0]
    print('update %s host %s' % (dev['s'], temp_host[i]))
    objdll.VzLPRClient_UpdateNetworkParam(dev['sl'], dev['sh'],
                                          temp_host[i].encode('utf-8'),
                                          gateway.encode('utf-8'),
                                          netmask.encode('utf-8'))

    url = 'http://%s' % temp_host[0]
    webc = WEBClient(url, username, password)
    for i in range(20):
        time.sleep(1)

        if not webc.login():
            continue
        c_rs485_write(webc, 0, '$001,01&')
        time.sleep(1)
        ret, data = c_rs485_read(webc, 0)
        if data == 'OK':
            print('update %s host %s' % (dev['s'], temp_host[1]))
            objdll.VzLPRClient_UpdateNetworkParam(dev['sl'], dev['sh'],
                                                  temp_host[1].encode('utf-8'),
                                                  gateway.encode('utf-8'),
                                                  netmask.encode('utf-8'))
            cfg_factory_param_product(webc, 0, 1)   # 近端，双目
            i = 2   # 另一台是远端1.101
        else:
            print('update %s host %s' % (dev['s'], temp_host[2]))
            objdll.VzLPRClient_UpdateNetworkParam(dev['sl'], dev['sh'],
                                                  temp_host[2].encode('utf-8'),
                                                  gateway.encode('utf-8'),
                                                  netmask.encode('utf-8'))
            cfg_factory_param_product(webc, 1, 1)   # 远端，双目
            i = 1   # 另一台是近端1.100
        break

    # 另一台设置
    dev = devs[1]
    print('update %s host[%d] %s' % (dev['s'], i, temp_host[i]))
    objdll.VzLPRClient_UpdateNetworkParam(dev['sl'], dev['sh'],
                                          temp_host[i].encode('utf-8'),
                                          gateway.encode('utf-8'),
                                          netmask.encode('utf-8'))
    if i == 2:
        cfg_factory_param_product(webc, 1, 1)  # 远端，双目
    else:
        cfg_factory_param_product(webc, 0, 1)  # 近端，双目
