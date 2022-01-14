#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import requests

sn = "e836b543-73d43be1"
url_sn_to_ip = "http://119.3.146.99/webapi/v1/pdns"

param = {'sn': sn, 'port': 80}
resp = requests.get(url_sn_to_ip, params=param)
print(resp.status_code, resp.text)
