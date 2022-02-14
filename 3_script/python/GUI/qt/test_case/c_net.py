#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
# set
{"type":"ss_set_rj45_net","module":"SS_BUS_REQUEST","body":{"dhcp":0,"ip":"192.168.1.100","netmask":"255.255.128.0","gateway":"192.168.1.1","dns":"114.114.114.114","dns2":"8.8.8.8","https_en":0,"http_port":80,"rtsp_port":8557}}
{"err_msg":"All done","state":200,"type":"ss_set_rj45_net"}

# get
{"type":"ss_get_rj45_net","module":"SS_BUS_REQUEST"}:
{"body":{"dhcp":0,"dns":"114.114.114.114","dns2":"8.8.8.8","gateway":"192.168.1.1","http_port":80,"https_en":0,"ip":"192.168.1.100","netmask":"255.255.128.0","rtsp_port":8557},"err_msg":"All done","state":200,"type":"ss_get_rj45_net"}
'''
from libutils.webclient import WEBClient

cmd_s_tmp = '''{
                "type":"ss_set_rj45_net",
                "module":"SS_BUS_REQUEST",
                "body":{
                    "dhcp":0,
                    "ip":"%s",
                    "netmask":"%s",
                    "gateway":"%s",
                    "dns":"%s",
                    "dns2":"%s",
                    "https_en":0,
                    "http_port":80,
                    "rtsp_port":8557
                    }
                }'''


def c_net_set(webc, host, netmask, gateway, dns1='114.114.114.114', dns2='8.8.8.8'):
    cmd = cmd_s_tmp % (host, netmask, gateway, dns1, dns2)
    # print('c_rs485 %s' % cmd)
    if webc is None:
        print('webc none')
        return 404, None

    ret = 404
    if webc.login():
        ret, resp = webc.posts(cmd)
        return ret, resp
    return ret, None
    # print(resp)


# webc = WEBClient('http://192.168.6.32', 'admin', 'admin')
# ret, resp = c_net_set(webc, '192.168.6.31', '255.255.255.0', '192.168.1.1')
# print(ret)
# print(resp)
