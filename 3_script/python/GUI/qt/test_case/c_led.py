
'''
{
    "module":"BUS_REQUEST_MSG",
    "type":"set_led_prm",
    "body": {
        "channel": [
            {
                "chan_id": 0,
                "time_ctrl": [
                    {
                        "time_begin": "00:00:00",
                        "time_end": "06:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 0
                    },
                    {
                        "time_begin": "06:00:00",
                        "time_end": "19:30:00",
                        "timectrl_enable": false,
                        "led_level": -1,
                        "id": 1
                    },
                    {
                        "time_begin": "19:30:00",
                        "time_end": "24:00:00",
                        "timectrl_enable": true,
                        "led_level": -1,
                        "id": 2
                    }
                ],
                "led_mode": 0,
                "led_sensitivity": 4
            }
        ]
    }
}
'''
import time

from libutils.webclient import WEBClient

cmd_tmp = '''{
                "module":"BUS_REQUEST_MSG",
                "type":"set_led_prm",
                "body": {
                    "channel": [
                        {
                            "chan_id": 0,
                            "time_ctrl": [
                                {
                                    "time_begin": "00:00:00",
                                    "time_end": "06:00:00",
                                    "timectrl_enable": true,
                                    "led_level": %d,
                                    "id": 0
                                },
                                {
                                    "time_begin": "06:00:00",
                                    "time_end": "19:30:00",
                                    "timectrl_enable": true,
                                    "led_level": %d,
                                    "id": 1
                                },
                                {
                                    "time_begin": "19:30:00",
                                    "time_end": "24:00:00",
                                    "timectrl_enable": true,
                                    "led_level": %d,
                                    "id": 2
                                }
                            ],
                            "led_mode": 3,
                            "led_sensitivity": 4
                        }
                    ]
                }
            }'''


def c_led(webc, value):
    cmd = cmd_tmp % (value, value, value)
    # print('c_lens %s' % cmd)
    if webc == None:
        print('webc none')
        return 404

    ret = False
    if webc.login():
        ret, resp = webc.posts(cmd)
    return ret
    # print(resp)

# webc = WEBClient('http://192.168.6.31', 'admin', 'admin')
# out_num = 1
# ret = c_led(webc, 10)
# time.sleep(1)
# ret = c_led(webc, 30)
# time.sleep(1)
# ret = c_led(webc, -1)
