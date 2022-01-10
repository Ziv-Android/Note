# coding: utf-8
import hmac
import base64
import hashlib
from hashlib import sha1
import json
import datetime
import time
import base


def cal_hash_hmac(code, key):
    hmac_code = hmac.new(key.encode(), code.encode("utf-8"), sha1).digest()
    return base64.b64encode(hmac_code).decode()


def cal_md5(body):
    data = json.dumps(body).encode('utf8')
    md5_val = hashlib.md5(data)
    md5_base64 = base64.b64encode(md5_val.digest())
    return md5_base64.decode('utf-8')


def cal_file_base64(file_path):
    with open(file_path, 'rb') as f:
        return base64.b64encode(f.read()).decode('utf-8')


def packaging_param(params):
    param = '?'
    if params:
        params = json.loads(json.dumps(params, sort_keys=True))
        for key in params:
            param = param + key + '=' + str(params[key]) + '&'
        return param[:-1]
    else:
        return ''


class Signature(object):

    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.base_host = base_host
        self.access_key_id = access_key_id
        self.access_key_secret = access_key_secret
        self.invalid_timer = invalid_timer

    def cal_signature(self, **kwargs):
        """
        计算signature，添加accesskey_id,expires,signature至原有params返回
        :param kwargs:
        :return:
        """

        if 'params' in kwargs.keys():
            if 'accesskey_id' in kwargs['params']:
                del kwargs['params']['accesskey_id']
            if 'expires' in kwargs['params']:
                del kwargs['params']['expires']
            if 'signature' in kwargs['params']:
                del kwargs['params']['signature']

        # 初始化计算signature条件
        content_type = 'application/json'
        kwargs['url'] = self.base_host + kwargs.get('path')
        path = kwargs.get('path') + packaging_param(kwargs.get('params'))
        method = kwargs.get('method').upper()
        request_json = kwargs.get('json')
        expire = int(time.mktime(datetime.datetime.now().timetuple())) + self.invalid_timer * 1000

        if request_json:
            # 有body情况，计算signature
            canonical_string = "%s\n%s\n%s\n%d\n%s" % (
                method, cal_md5(request_json), content_type, expire, path)
            sign = cal_hash_hmac(canonical_string, self.access_key_secret)
        else:
            # 无body情况，计算signature
            canonical_string = "%s\n\n\n%d\n%s" % (method, expire, path)
            sign = cal_hash_hmac(canonical_string, self.access_key_secret)

        if kwargs.get('params') is None:
            kwargs['params'] = {}
        kwargs['params']['accesskey_id'] = self.access_key_id
        kwargs['params']['expires'] = expire
        kwargs['params']['signature'] = sign
        del kwargs['path']
        return kwargs


if __name__ == '__main__':
    open_base_host = 'http://nopen.vzpdns.com'
    access_key = '8dlP5tsD2115Q2ec9fCkX2wHSIIlhCO8'
    access_secret = 'y1nSm6Th6VAtWAN0dGBFwiEq0c02Sb57'
    kw = {'path': '/openapi/v1/stp/user/devices/vurl',
          'method': 'GET',
          'params': {'sn': '6593d05e-34c85fbd', 'type': 'flv'}
          }
    signature = Signature(open_base_host, access_key, access_secret, 6)
    result = signature.cal_signature(**kw)
    req = base
    print(req.request(timeout=60, **result))
