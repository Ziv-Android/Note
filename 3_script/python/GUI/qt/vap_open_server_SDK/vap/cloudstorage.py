import json

from signature import Signature
from base import request


class CloudStorage:
    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.content = {'headers': {'Content-Type': 'application/json'}}
        self.sign = Signature(base_host, access_key_id, access_key_secret, invalid_timer)

    def get_video_list(self, sn, begin_time, end_time, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices/cloudstorage/search'
        content['method'] = 'GET'
        content['params'] = {'sn': sn, 'begin_time': begin_time, 'end_time': end_time, 'page': 0, 'page_size': 500}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_video_file(self, sn, filename, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices/cloudstorage/play.m3u8'
        content['method'] = 'GET'
        content['params'] = {'sn': sn, 'filename': filename}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def download_video(self, sn, filename, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices/cloudstorage/download'
        content['method'] = 'GET'
        content['params'] = {'sn': sn, 'filename': filename}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def get_video_by_mouth_info(self, sn, month, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/stp/user/devices/cloudstorage/search_month'
        content['method'] = 'GET'
        content['params'] = {'sn': sn, 'month': month}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)


if __name__ == '__main__':
    test_base_host = 'https://open.vzicloud.com/'
    test_access_key_id = '8fEMTyg921352h0q9i6uT1iQ5HU1ohCR'
    test_access_key_secret = '9wkQ1MIly0l0rdr318RFDn9svBFGQsml'
    cloud_storage = CloudStorage(test_base_host, test_access_key_id, test_access_key_secret)

    test_sn = '089528a5-007d179c'
    file_name = '1639626956_iq_i4it43zW9ng6GlX4qai0ITATx7pBzkRKubR121G0_0/bb22892a-634d-4619-9951-d89d7b1076e7'
    print(cloud_storage.get_video_file(test_sn, file_name))
    print(cloud_storage.get_video_list(test_sn, 1639616400, 1639627200))
    print(cloud_storage.download_video(test_sn, file_name))
    print(cloud_storage.get_video_by_mouth_info(test_sn, '202112'))
