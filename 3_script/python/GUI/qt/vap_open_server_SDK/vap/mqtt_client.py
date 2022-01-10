# coding: utf-8
import base64
import time
import datetime
import requests
import json
from signature import Signature
from paho.mqtt import client as mqtt

from vap.base import request


def on_connect(client, userdata, flags, rc):
    """
    paho.mqtt 连接broker函数，勿修改
    :param client:
    :param userdata:
    :param flags:
    :param rc:
    :return:
    """
    if rc == 0:
        print("Connection success")
    else:
        print('Connection fail')


def on_message(client, userdata, message):
    """
    paho.mqtt 订阅的主题上接收到消息时调用, 勿修改
    :param client:
    :param userdata:
    :param message:
    :return:
    """
    print("%s %s" % (message.topic, str(message.payload, 'utf-8').replace('\n', '')))


class MqttClient:
    def __init__(self, sid, base_host, access_key_id, access_key_secret, invalid_timer=6):
        self.content = {'headers': {'Content-Type': 'application/json'}}
        self.sign = Signature(base_host, access_key_id, access_key_secret, invalid_timer)

        mqtt_info = self.get_mqtt_info(sid)['data']
        print(mqtt_info)
        self.client = mqtt.Client(mqtt_info['clientid'])
        self.client.username_pw_set(mqtt_info['username'], mqtt_info['password'])
        self.client.connect(mqtt_info['host'], mqtt_info['port'], 30)
        self.client.on_connect = on_connect
        self.client.on_message = on_message

    def get_mqtt_info(self, sid: str, timeout=60):
        """
        获取MQTT连接信息
        :param sid: str 会话ID， 自定义字符串，只能是1到16位的数字和字母组合
        :param timeout:
        :return: json 会话信息
        """
        content = {
            'path': '/openapi/v1/stp/clients/route',
            'method': 'GET',
            'params': {'sid': sid}
        }
        sign_result = self.sign.cal_signature(**content)
        return request(timeout, **sign_result)

    def download_pic(self, pic_path_base64, timeout=60):
        path = base64.b64decode(pic_path_base64).decode('utf-8')
        content = {'path': '/openapi/v1/' + path, 'method': 'GET'}

        sign_result = self.sign.cal_signature(**content)
        result = requests.get(url=sign_result['url'], params=sign_result['params'], timeout=timeout)

        print(path.split('/')[-1])
        if result.status_code == 200:
            # 保存文件路径
            with open(path.split('/')[-1], "wb") as code:
                code.write(result.content)
            return {'code': 0, 'message': 'success', 'data': path.split('/')[-1]}
        else:
            return {'error': 1007, 'message': "%s" % result.text}

    def sub_device_state(self, sn: str):
        """
        订阅设备状态
        :param sn: str 设备序列号
        :return:
        """
        topic = 'device/%s/event/state' % sn
        self.client.subscribe(topic)

    def sub_device_message(self, sn: str, name: str):
        """
        订阅设备消息
        :param sn: str 设备序列号
        :param name: str 消息名称，参考设备提供的协议文档
        :return:
        """
        topic = 'device/%s/message/up/%s' % (sn, name)
        self.client.subscribe(topic)

    def pub_to_device_message(self, sn: str, name: str, payload):
        """
        发送消息到设备， 单独调用无法收到回执，若需要收到回执，先订阅回执topic
        :param sn: str 设备序列号
        :param name: str 消息名称
        :param payload: json 消息内容
        :return:
        """
        topic = 'device/%s/message/down/%s' % (sn, name)
        self.client.publish(topic, payload=json.dumps(payload), qos=0)

    def sub_pub_to_device_reply(self, sn: str, name: str):
        """
        订阅发送到设备端的消息回执
        :param sn: str 设备序列号
        :param name: str 消息名称
        :return:
        """
        topic = 'device/%s/message/down/%s/reply' % (sn, name)
        self.client.subscribe(topic)

    def loop_forever(self):
        self.client.loop_forever()


if __name__ == '__main__':
    test_sid = 'yz1list'
    test_base_host = 'https://open.vzicloud.com'
    test_access_key_id = '8fOo7IYJ2135TePa9OtItjcrFrE12l22'
    test_access_key_secret = 'nWtpiMxoGChscg9dtTRFgHzsePLRPYLv'

    # test_base_host = 'http://open.vzpdns.com'
    # test_access_key_id = '8fToRrty2135qCjV9awMKKfPK0A10hzs'
    # test_access_key_secret = 'QmJo0MMSbsBSStbv4fRFvQdss1mZEAaN'
    mq = MqttClient(test_sid, test_base_host, test_access_key_id, test_access_key_secret, 60)

    base_pic = 'aW1ncy84OTFjMGE5ZC0zMzUwMDFjZS8yMDIxMTIxNy8xNjM5NjcyMjU0Xzg5MWMwYTlkLTMzNTAwMWNlXzE4MDM3XzE4X2Z1bGwuanBn'
    print(mq.download_pic(base_pic, timeout=60))
    # mq.loop_forever()
