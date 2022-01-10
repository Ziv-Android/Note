# coding: utf-8
import json

from base import request
from signature import Signature
from signature import cal_file_base64


class PlateCNDetect:
    def __init__(self, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.base_host = base_host
        self.content = {'headers': {'Content-Type': 'application/json'}}
        self.sign = Signature(base_host, access_key_id, access_key_secret, invalid_timer)

    def plate_cn_detect_max_count(self, app_id, file_path, max_count=1, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/prs_cn/user/apps/' + app_id + '/plates/detect'
        content['method'] = 'POST'
        content['json'] = {"image_type": "BASE64", "image": cal_file_base64(file_path), "max_count": max_count}
        sign_result = self.sign.cal_signature(**content)
        print(json.dumps(sign_result, ensure_ascii=False))
        return request(timeout, **sign_result)

    def plate_cn_detect_rect_list(self, app_id, file_path, rect_list, timeout=60):
        content = self.content
        content['path'] = '/openapi/v1/prs_cn/user/apps/' + app_id + '/plates/detect'
        content['method'] = 'POST'
        content['json'] = {"image_type": "BASE64", "image": cal_file_base64(file_path), "rect_list": rect_list}
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)


if __name__ == '__main__':
    test_base_host = 'https://open.vzicloud.com'
    test_access_key_id = '8fOo7IYJ2135TePa9OtItjcrFrE12l22'
    test_access_key_secret = 'nWtpiMxoGChscg9dtTRFgHzsePLRPYLv'

    pcd = PlateCNDetect(test_base_host, test_access_key_id, test_access_key_secret, 6)
    result = pcd.plate_cn_detect_max_count(app_id='2', file_path=r'E:/4.jpg', max_count=1, timeout=6)
    print(json.dumps(result, indent=4, ensure_ascii=False))
