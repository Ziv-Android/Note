# coding: utf-8
import time

from signature import Signature
from base import request
# from vap import all_access_key, all_access_key_secret, all_sn_list
# from vap import single_access_key, single_access_key_secret, single_sn_list
# from vap import several_access_key, several_access_key_secret, several_sn_list


class Device:
    """
    设备服务，功能包含：绑定设备、远程访问设备、获取视频地址
    """

    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        """
        初始化设备服务对象

        :param base_host: 请服务地址,需带上http/https://请求浅醉
        :param access_key_id:
        :param access_key_secret:
        :param invalid_timer: 接口有效时间
        """

        self.content = {'headers': {'Content-Type': 'application/json'}}
        self.sign = Signature(base_host, access_key_id, access_key_secret, invalid_timer)

    def bind_devices(self, device_info_list, timeout=60):
        """
        绑定设备

        :param device_info_list: list 格式如下
        [{
            "sn": "12345678-87654321",
            "group_id": 0,
            "username": "admin",
            "password": "admin",
            "remark": ""
        },
        {
            "sn": "12345678-87654322",
            "group_id": 0,
            "username": "admin",
            "password": "admin",
            "remark": ""
        }]
        :param timeout: 请求超时事件
        :return:
        """

        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices'
        content['method'] = 'POST'
        content['json'] = device_info_list
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_devices(self, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices'
        content['method'] = 'GET'
        content['params'] = {'wheres': 'W3siayI6Imdyb3VwX2lkIiwibyI6ImVxIiwidiI6MX1d'}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def unbind_devices(self, sn_list, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices'
        content['method'] = 'DELETE'
        content['json'] = sn_list
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_device_remote_url(self, sn, return_type='text', timeout=60):
        content = {'headers': {'Content-Type': 'application/json'}, 'path': '/openapi/v1/stp/user/devices/pdns/web',
                   'method': 'GET', 'params': {'sn': sn, 'type': 'text'}}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_device_video_url(self, sn, return_type, timeout=60):
        content = {'headers': {'Content-Type': 'application/json'}}
        content['path'] = '/openapi/v1/stp/user/devices/vurl'
        content['method'] = 'GET'
        content['params'] = {'sn': sn, 'type': return_type}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_video_detail(self, test_sn_list, timeout=60):
        content = {'headers': {'Content-Type': 'application/json'}}
        content['path'] = '/openapi/v1/stp/user/devices/video/detail'
        content['method'] = 'POST'
        content['json'] = test_sn_list
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def break_video_stream(self, test_sn_list, timeout=60):
        content = {'headers': {'Content-Type': 'application/json'}}
        content['path'] = '/openapi/v1/stp/user/devices/video'
        content['method'] = 'DELETE'
        content['json'] = test_sn_list
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)


if __name__ == '__main__':
    test_base_host = 'http://nopen.vzpdns.com'
    test_access_key_id = 'Ceu8lKlf6125Rq0wSh8hyLwz5xWt0EBm'
    test_access_key_secret = 'iwn5D8v4HJ6mKquO7PJla90HWOg7twtC'
    device = Device(test_base_host, test_access_key_id, test_access_key_secret)
    print(device.get_device_remote_url(sn='02880771-fce36ba5'))

    # test_access_key_idcess_key_id = single_access_key
    # test_access_key_secret = single_access_key_secret
    # device = Device(test_base_host, test_access_key_id, test_access_key_secret)
    # for test_sn in single_sn_list:
    #     test_sn_list = [{'sn': test_sn}]
    #     print(device.get_device_remote_url(test_sn, 'text'))
    #     print(device.get_device_video_url(test_sn, 'flv'))
    #     print(device.get_video_detail(test_sn_list))
    #     print(device.break_video_stream(test_sn_list))
    #     print('-' * 50)

    # test_access_key_id = several_access_key
    # test_access_key_secret = several_access_key_secret
    # device = Device(test_base_host, test_access_key_id, test_access_key_secret)
    # for test_sn in several_sn_list:
    #     test_sn_list = [{'sn': test_sn}]
    #     print(device.get_device_remote_url(test_sn, 'text'))
    #     print(device.get_device_video_url(test_sn, 'flv'))
    #     print(device.get_video_detail(test_sn_list))
    #     print(device.break_video_stream(test_sn_list))
    #     print('-' * 50)
