#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import datetime
import hmac
import base64
import json
import time
from hashlib import sha1, md5

import requests
from urllib.parse import urlparse


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


def get_path(url):
    try:
        if url.startswith("http"):
            url_parsed = urlparse(url)
            path = f"{url_parsed.scheme}://{url_parsed.netloc}{url_parsed.path}"
            print(path[:-1])
            return path[:-1]
        return ""
    except Exception as e:
        print("get_path exception", e)
        return ""


class NormalClient:
    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.base_host = base_host
        self.access_key_id = access_key_id
        self.access_key_secret = access_key_secret
        self.invalid_timer = invalid_timer

    def get_device_remote_url(self, sn, path="/openapi/v1/stp/user/devices/pdns/web"):
        try:
            method = "GET"
            sign_path_url = path
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
            if result is None:
                return ""
            if result.status_code != 200 or len(result.text) <= 0:
                return ""
            return get_path(result.text)
        except Exception as e:
            print("get_device_remote_url exception", e)
            return ""
