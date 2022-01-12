#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import datetime
import hmac
import base64
import time
from hashlib import sha1, md5

import requests


def create_signature_content(method, path, content_md5="", content_type="", expires=0):
    method = method.upper()
    if expires == 0:
        expires = create_expires()
    return f"{method}\n{content_md5}\n{content_type}\n{expires}\n{path}"


def create_path(path, params=None):
    path += "?"
    if params is not None:
        for key in params.keys():
            path += f"{key}={params[f'{key}']}&"
    return path[:-1]


def create_content_md5(content):
    data_md5 = md5(content.encode("utf-8"))
    data_md5_base64 = base64.b64encode(data_md5.digest())
    return data_md5_base64.decode("utf-8")


def create_expires(expires=6):
    return int(time.mktime(datetime.datetime.now().timetuple())) + expires * 1000


def create_signature(key, content):
    hmac_code = hmac.new(key.encode(), content.encode("utf-8"), sha1).digest()
    return base64.b64encode(hmac_code).decode()


class Client:
    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.base_host = base_host
        self.access_key_id = access_key_id
        self.access_key_secret = access_key_secret
        self.invalid_timer = invalid_timer

    def get_device_remote_url(self, sn):
        method = "GET"
        sign_path_url = "/openapi/v1/stp/user/devices/pdns/web"
        sign_path_params = {'sn': sn, 'type': "text"}
        sign_path = create_path(sign_path_url, sign_path_params)
        sign_expires = create_expires(self.invalid_timer)
        sign_content = create_signature_content(method, sign_path, expires=sign_expires)
        sign = create_signature(self.access_key_secret, sign_content)
        url = self.base_host + sign_path_url
        params = {"accesskey_id": self.access_key_id, "expires": sign_expires, "signature": sign}
        params = {**params, **sign_path_params}
        print(params)
        result = requests.get(url, params, timeout=60)
        print("result:", result.status_code, result.text)


if __name__ == '__main__':
    open_base_host = 'http://nopen.vzpdns.com'
    # access_key_id = '7e9peQ8C1125A7Cz4LVFJl61jxFtHs0F'
    # access_key_secret = 'ZfATtI0jK9uclIEwcHJ7JLAj7rRX1mgY'
    #
    # content_type = "application/json"
    # create_path("/openapi/v1/stp/user/devices")
    # expires = 1600689938
    # signature_content_1 = create_signature_content(
    #     "post", create_path("/openapi/v1/stp/user/devices"),
    #     create_content_md5('[{"sn":"12345678-87654321","group_id":0,"username":"admin","password":"admin","remark":""}]'),
    #     content_type,
    #     expires
    # )
    # print(signature_content_1)
    # sign = create_signature(access_key_secret, signature_content_1)
    # print("sign:", sign)
    #
    # signature_content_2 = "POST\nvrjt79DVzdoDc55z64BrhA==\napplication/json\n1600689938\n/openapi/v1/stp/user/devices"
    # print(signature_content_1 == signature_content_2)
    # sign = create_signature(access_key_secret, signature_content_2)
    # print("sign:", sign)

    # access_key_id = 'Ceu8lKlf6125Rq0wSh8hyLwz5xWt0EBm'
    # access_key_secret = 'iwn5D8v4HJ6mKquO7PJla90HWOg7twtC'
    access_key_id = 'KihoeTFJ62d755z5xSoK5AGGeygPWX7P'
    access_key_secret = 'JJAs0qJAOeazJtXpbhnmEODNzj3kmwja'
    # # signature_content = create_signature_content("get", "path", "json_data", "application/json", 10)
    # signature_content = create_signature_content("get", create_path("check", {"age": 18, "sex": "女"}))
    # sign = create_signature(access_key_secret, signature_content)
    # print("signature_content:", signature_content)
    # print("sign", sign)

    client = Client(open_base_host, access_key_id, access_key_secret)
    client.get_device_remote_url(sn='02880771-fce36ba5')

    # signature = Signature(open_base_host, access_key_id, access_key_secret, 6)
    # result = signature.cal_signature(**kw)
    # req = base
    # print(req.request(timeout=60, **result))
