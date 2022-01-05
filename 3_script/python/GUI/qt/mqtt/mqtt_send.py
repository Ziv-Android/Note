import paho.mqtt.client as mqtt
import json
import random

HOST = "106.52.198.107"
PORT = 1884
client_id = f'python-mqtt-{random.randint(100000000, 999999999)}'  # 客户端的唯一标识，全局唯一
client = mqtt.Client(client_id)  # 定义client，可不用指定client_id，系统自动分配


def on_connect(client, userdata, flags, rc):
    '''连接成功后回调，0表示成功'''
    if rc != 0:
        #     print("Connected with result code "+str(rc))
        # else:
        print("Unexpected disconnection %s" % rc)
    client.subscribe("face/response", qos=1)  # 订阅消息，abcde为消息主题，必须写在这里
    client.subscribe("return/msg", qos=1)  # 订阅消息，abcde为消息主题，必须写在这里


def on_message(client, userdata, msg):
    '''订阅消息，接收到消息后回调'''
    # print(client_id+" 主题:"+msg.topic+" 消息:"+str(msg.payload.decode('utf-8')))
    print(str(msg.payload.decode('utf-8')))
    print('\t')


def on_subscribe(client, userdata, mid, granted_qos):
    '''订阅消息成功后回调'''
    print("On Subscribed: qos = %d" % granted_qos)


data = {
    "cmd": "create_face",
    "apikey": "Publish",
    "messageId": "10010",
    "user": {
        "id": "109",
        "mobile": "13520036110",
        "username": "罗兵",
        "sex": "0",
        "idcard": "55665555",
        "address": "四川省成都市",
        "nation": "汉",
        "tailRootId": "1010101010",
        "faceimg": "https://dqfile-1251895221.cos.ap-guangzhou.myqcloud.com/img/4B4A44BC569F44AF63674A38D0EC2F2A1341CEAE.jpg",
        "icDisabledTime": "2021-12-21 15:52:00",
        "icNum": "1233299",
        "faceFailure": "2022-12-21 00:00:00"
    }
}

param = json.dumps(data)
client.username_pw_set(username="thirdPartyAccount", password="147258")  # 定义连接mqtt服务器的用户名和密码
client.on_connect = on_connect  # 回调连接
client.on_message = on_message  # 回调订阅消息
client.on_subscribe = on_subscribe
print(client_id)  # 打印出clintid
client.connect(HOST, PORT, 60)  # 连接mqtt
client.publish("face/0106004824/request", payload=param, qos=0)  # 发送消息
# client.loop_forever() #保持连接，阻塞程序，实时监听订阅消息
