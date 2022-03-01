## 登录页
### 请求
请求系统参数 Post
URL 
http://192.168.13.202/avsjson.php
Params
{"type":"AVS_GET_SYS_PRM"}	
Response
{
	"body": {
		"alg_block": false,
		"language": "zh-cn"
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_SYS_PRM"
}

### 操作
登录：Post
URL
http://192.168.13.202/login.php
Params
加密username和password参数，rJIMYtjY2NgYtbky3tuwOy27rg:==加密规则见下
Response
OK
Set-Cookie: sessionID=209192407

## 实时视频页
### 请求
Post
http://192.168.13.202/getauth.php

{"type":"get_user_auth"}

{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}

Post
http://192.168.13.202/genvictetc.php

{"type":"etc_get_enable"}

{
	"state": 401
}

Post
http://192.168.13.202/request.php

{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}	

{
	"body": "",
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}

Post
http://192.168.13.202/request.php

{"type":"get_device_capacity","module":"SS_BUS_REQUEST"}	

{
	"body": {
		"ado_enable": 1,
		"e4g_num": 1,
		"fan_num": 0,
		"img_reset_num": 0,
		"io_in_num": 2,
		"io_out_num": 2,
		"key_reset_num": 1,
		"led_num": 0,
		"mcu_num": 0,
		"moto_num": 0,
		"onenet_enable": 1,
		"opensdk_en": 1,
		"stp_enable": 1,
		"ttl_num": 0,
		"tty_num": 1,
		"wifi_num": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_capacity"
}

Post
http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:MA==

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}

Post
http://192.168.13.202/request.php

{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}	

{
	"body": {
		"enable_auth": true,
		"live_stream_type": "flv",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FDNGFXNDUzVEFqdnFsQXlwTTluQUFPNTFZTwpuQk1iQ1ovUEpZekNUR0l1WFBWTzFIM0tSdTBIOWJRUlRWY2VFMUtKNVM5ZVg3UmppSGZWektEaWlVR2NDU0dpCkdIOEtoUEdaR0hHbDhXVFVsczVER3dvRVEybVBmTmROREdVRldOMzRkcVN2VlpBWVRjTE5tMVM0YXlJeElncXUKVVJhbDN2SDBtbHpkKzdoVVJ3SURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "17abed60-9180-2eb7-e72b-609f6d96c0da",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}

Get
http://192.168.13.202/ivs_result.php?_=1646033471027

{
	"body": {
		"PlateResult": {
			"car_head_bottom": 0,
			"car_head_left": 0,
			"car_head_right": 0,
			"car_head_top": 0,
			"color": 0,
			"image_path": "L21lZGlhL21tY2JsazBwMS9WeklQQ0NhcC8yMDE4XzA4XzIwLzEzNTMyMTYxMDRfX+aXoF8uanBn",
			"is_fake_plate": 0,
			"license": "X+aXoF8=",
			"nType": 0,
			"plate_bottom": 0,
			"plate_distance": 0,
			"plate_left": 0,
			"plate_right": 0,
			"plate_top": 0,
			"plate_true_width": 0,
			"trigger_time": "2018-08-20 13:53:21",
			"uBitsTrigType": 4,
			"uId": 0
		}
	},
	"error_msg": "success",
	"state": 200,
	"type": "GET_LAST_IVS_RECORD"
}

Post
http://192.168.13.202/systemjson.php

{"type":"get_net_and_port"}	

{
	"body": {
		"dhcp": 0,
		"dns": "114.114.114.114",
		"dns2": "8.8.8.8",
		"gateway": "192.168.1.11",
		"http_port": 80,
		"https_en": 0,
		"ip": "192.168.13.202",
		"netmask": "255.255.128.0",
		"rtsp_port": 8557
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_and_port"
}

Post
http://192.168.13.202/dgjson.php

{"type":"get_group_cfg"}	

{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "input"
	}
}

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_LED_PROP"}	

{
	"body": {
		"led_level": {
			"default": 2,
			"max": 4,
			"min": -1,
			"types": [{
				"content": "5YWz6Zet",
				"type": -1
			}, {
				"content": "Muexsw==",
				"type": 0
			}, {
				"content": "NOexsw==",
				"type": 1
			}, {
				"content": "Nuexsw==",
				"type": 2
			}, {
				"content": "N+exsw==",
				"type": 3
			}, {
				"content": "OOexsw==",
				"type": 4
			}]
		},
		"led_mode": [{
			"content": "5pm66IO9",
			"type": 0
		}, {
			"content": "5bi45Lqu",
			"type": 1
		}, {
			"content": "5bi454Gt",
			"type": 2
		}, {
			"content": "5pe26Ze05q61",
			"type": 3
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_PROP"
}

Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=0:0:45:400:10:0


Post
http://192.168.13.202/systemjson.php

{"type":"ss_get_devname"}	

{
	"body": {
		"title": "SVZT"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}

Post
http://192.168.13.202/systemjson.php

{"type":"get_device_info"}	

{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}

Post
http://192.168.13.202/dboprnew.php

{"type":"get_wl_check_status"}	

{
	"body": {
		"dev_time": {
			"time_day": 28,
			"time_hour": 15,
			"time_min": 32,
			"time_mon": 2,
			"time_sec": 42,
			"time_year": 2022
		},
		"filter_enable": 0,
		"offline_status": 0,
		"white_list_flag": 1
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_check_status"
}

Post
http://192.168.13.202/systemjson.php

{"type":"ss_get_ntp_cfg"}	

{
	"body": {
		"cycle": 600,
		"enable": 1,
		"server": "ntp.ntsc.ac.cn"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ntp_cfg"
}

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ENCODE_PROP"}	

{
	"body": {
		"encode_param": [{
			"data_rate": {
				"default": 3072000,
				"enable": true,
				"max": 5000000,
				"min": 512000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "H264",
					"type": 0
				}, {
					"content": "H265",
					"type": 3
				}]
			},
			"frame_rate": {
				"default": 25,
				"enable": true,
				"max": 25,
				"min": 1
			},
			"rate_type": {
				"default": 1,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}, {
					"content": "5Y+Y56CB5rWB",
					"type": 1
				}]
			},
			"resolution": {
				"default": 10,
				"enable": true,
				"types": [{
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}, {
					"content": "1280*720",
					"type": 9
				}, {
					"content": "1920*1080",
					"type": 10
				}, {
					"content": "2304*1296",
					"type": 11
				}]
			},
			"stream_id": 0,
			"video_quality": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}, {
			"data_rate": {
				"default": 512000,
				"enable": true,
				"max": 1800000,
				"min": 512000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "H264",
					"type": 0
				}, {
					"content": "H265",
					"type": 3
				}]
			},
			"frame_rate": {
				"default": 15,
				"enable": true,
				"max": 25,
				"min": 1
			},
			"rate_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}, {
					"content": "5Y+Y56CB5rWB",
					"type": 1
				}]
			},
			"resolution": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "352*288",
					"type": 2
				}, {
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}]
			},
			"stream_id": 1,
			"video_quality": {
				"default": 3,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}, {
			"data_rate": {
				"default": 512000,
				"enable": true,
				"max": 2400000,
				"min": 120000
			},
			"encode_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "MJPEG",
					"type": 1
				}]
			},
			"frame_rate": {
				"default": 15,
				"enable": true,
				"max": 15,
				"min": 1
			},
			"rate_type": {
				"default": 0,
				"enable": true,
				"types": [{
					"content": "5a6a56CB5rWB",
					"type": 0
				}]
			},
			"resolution": {
				"default": 5,
				"enable": true,
				"types": [{
					"content": "640*360",
					"type": 3
				}, {
					"content": "704*576",
					"type": 5
				}, {
					"content": "1280*720",
					"type": 9
				}, {
					"content": "1920*1080",
					"type": 10
				}]
			},
			"stream_id": 2,
			"video_quality": {
				"default": 3,
				"enable": true,
				"types": [{
					"content": "5pyA5rWB55WF",
					"type": 0
				}, {
					"content": "6L6D5rWB55WF",
					"type": 1
				}, {
					"content": "5rWB55WF",
					"type": 2
				}, {
					"content": "5Lit562J",
					"type": 3
				}, {
					"content": "5riF5pmw",
					"type": 4
				}, {
					"content": "6L6D5riF5pmw",
					"type": 5
				}, {
					"content": "5pyA5riF5pmw",
					"type": 6
				}]
			}
		}],
		"encode_stream": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5Li756CB5rWB",
				"type": 0
			}, {
				"content": "5a2Q56CB5rWBKEZMVik=",
				"type": 1
			}, {
				"content": "56ys5LiJ56CB5rWBKE1KUEVHKQ==",
				"type": 2
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PROP"
}

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}

Post
http://192.168.13.202/request.php

{"type":"get_avs_focus_prm","module":"AVS_REQUEST_MESSAGE"}	

{
	"body": {
		"auto_focus": 0,
		"digital_ptz_enable": false,
		"digital_ptz_window_size": {
			"height": 0,
			"width": 0,
			"x": 0,
			"y": 0
		},
		"digital_zoom": 1.399999976158142,
		"focus_step": 0,
		"focus_type": 0
	},
	"error_msg": "",
	"state": 200,
	"type": "get_avs_focus_prm"
}

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 1,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}

http://192.168.13.202/avsjson.php

{"type":"AVS_GET_LED_CTRL"}	

{
	"body": {
		"led_level": 2,
		"led_mode": 3,
		"time_ctrl": [{
			"id": 0,
			"led_level": 2,
			"time_begin": "00:00:00",
			"time_end": "02:03:34",
			"timectrl_enable": true
		}, {
			"id": 1,
			"led_level": 6,
			"time_begin": "02:03:34",
			"time_end": "09:02:23",
			"timectrl_enable": true
		}, {
			"id": 2,
			"led_level": 1,
			"time_begin": "18:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": true
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_CTRL"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ENCODE_PARAM"}	

{
	"body": {
		"default_stream": 0,
		"encode_param": [{
			"data_rate": 3072000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 10,
			"stream_id": 0,
			"video_quality": 5
		}, {
			"data_rate": 512000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 5,
			"stream_id": 1,
			"video_quality": 3
		}, {
			"data_rate": 1024000,
			"encode_type": 1,
			"frame_rate": 15,
			"rate_type": 0,
			"resolution": 9,
			"stream_id": 2,
			"video_quality": 3
		}]
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PARAM"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 1,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_VIRLOOP_PRM"}	

{
	"body": {
		"virtualloop": {
			"dir": 0,
			"loop": [{
				"enable": false,
				"point": [],
				"point_num": 0
			}],
			"max_plate_width": 400,
			"min_plate_width": 45,
			"trigger_gap": 10,
			"virtualloop_num": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_VIRLOOP_PRM"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_RECO_PRM"}	

{
	"body": {
		"recognition_area": {
			"polygon": [{
				"enable": false,
				"point": [],
				"point_num": 0
			}],
			"polygon_num": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_RECO_PRM"
}

Get
ws://192.168.13.202:9080/ws.flv?token=17abed60-9180-2eb7-e72b-609f6d96c0da

Post
http://192.168.13.202/webpage_relogin.php

{
	"state": 401
}

http://192.168.13.202/getauth.php
{"type":"get_user_auth"}	
{
	"body": {
		"authority": 0
	},
	"state": 200,
	"type": "get_user_auth"
}

### 操作
创建虚拟线圈 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_VIRLOOP_PRM","body":{"virtualloop":{"max_plate_width":400,"min_plate_width":45,"dir":0,"trigger_gap":10,"loop":[{"enable":true,"point_num":4,"point":[{"x":2395,"y":11987},{"x":13988,"y":11987},{"x":15981,"y":14013},{"x":402,"y":14013}]}],"virtualloop_num":1}}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_VIRLOOP_PRM"
}

创建识别区域 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_RECO_PRM","body":{"recognition_area":{"polygon":[{"enable":true,"point_num":4,"point":[{"x":1276,"y":2404},{"x":15055,"y":2404},{"x":16139,"y":15937},{"x":209,"y":15937}]}],"polygon_num":1}}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_RECO_PRM"
}

手动触发 Get
http://192.168.13.202/avstrigger.php?_=1646033475057

手动触发截图 Get
http://192.168.13.202/snapshot/last_ivs_result.jpg?1646035490999

出入口 Post
http://192.168.13.202/dgjson.php

{"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"bHk=&MTkyLjE2OC43LjIy","sn":"c806ca86-8de9c3f4","type":"output"}}

{
	"state": 200,
	"type": "set_group_cfg"
}

运动方向 Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:45:400:10:1

http://192.168.13.202/seteventruleexhtm.php

1:1:45:400:10:2

OK seteventrule1

补光模式 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_LED_CTRL","body":{"led_mode":0}}
{"type":"AVS_SET_LED_CTRL","body":{"time_ctrl":[{"time_begin":"00:00:00","time_end":"02:00:00","timectrl_enable":true,"led_level":2,"id":0},{"time_begin":"02:00:00","time_end":"09:00:00","timectrl_enable":false,"led_level":-1,"id":1},{"time_begin":"09:00:00","time_end":"24:00:00","timectrl_enable":true,"led_level":1,"id":2}],"led_mode":3}}

{
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_LED_CTRL"
}

预设省份 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"province":22}}

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

云台控制 Post
http://192.168.13.202/request.php

上
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":2,"degree":2}}

下
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":4,"degree":2}}

左
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":32,"degree":2}}

右
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":16,"degree":2}}

停
{"type":"set_cloud_ctrl","module":"BUS_REQUEST_MESSAGE","body":{"dir":8,"degree":0}}

{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_cloud_ctrl"
}

电子变倍 Post

http://192.168.13.202/request.php

{"type":"set_avs_focus_prm","module":"AVS_REQUEST_MESSAGE","body":{"auto_focus":0,"digital_ptz_enable":false,"digital_zoom":1.6,"focus_step":0,"focus_type":0,"digital_ptz_window_size":{"height":0,"width":0,"x":0,"y":0}}}

{
	"error_msg": "",
	"state": 200,
	"type": "set_avs_focus_prm"
}

## 数据查询页
图片预览查询 Post
http://192.168.13.202/request.php

{"type":"STORE_SEARCH_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"page_size":100,"page_num":1,"condition":{"plate":"","start_time":"2022-02-28 00:00:00","end_time":"2022-02-28 16:20:45","trigger":0}}}

{
	"body": {
		"pics_cnt": 1,
		"pics_total": 1,
		"rows": [{
			"alarm": 0,
			"block_index": 2,
			"channel": 0,
			"event_rec_time": 0,
			"id": 5,
			"image_size": 323384,
			"page_index": 17,
			"plate": "_无_",
			"recg_time": 1646035581,
			"retry": 0,
			"struct_size": 152,
			"trigger": 4
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_SEARCH_IMG_REQUEST"
}

双击图片日志条目 Post
http://192.168.13.202/request.php

{"type":"STORE_READ_IMG_REQUEST","module":"STORE_BUSINESS_REQUEST","body":{"id":"5"}}

{
	"body": {
		"image_path": "/htmldata/picdata02.pic",
		"image_size": 323384,
		"struct_size": 152
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_READ_IMG_REQUEST"
}

图片数据
http://192.168.13.202/htmldata/picdata02.pic?1646036565157

## 高级设置页
### 识别设置
#### 请求
Post
http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:MA==

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_CAPTURE_PRM"}	

{
	"body": {
		"duration": 10,
		"max_duration": 60,
		"mode": 0,
		"none_duration": 10
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_CAPTURE_PRM"
}

Post
http://192.168.13.202/request.php

{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}	

{
	"body": [{
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}

Post
http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MQ==

Post
http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:45:400:10:2

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PROP"}	

{
	"body": {
		"fake_threshold": {
			"default": 0,
			"types": [{
				"content": "5L2O",
				"type": 0
			}, {
				"content": "5Lit",
				"type": 1
			}, {
				"content": "6auY",
				"type": 2
			}]
		},
		"out_result_type": {
			"default": 18,
			"types": [{
				"content": "56iz5a6a6K+G5Yir6Kem5Y+R",
				"type": 1
			}, {
				"content": "6Jma5ouf57q/5ZyI",
				"type": 2
			}, {
				"content": "SU8x6Kem5Y+R",
				"type": 16
			}, {
				"content": "SU8y6Kem5Y+R",
				"type": 32
			}, {
				"content": "SU8z6Kem5Y+R",
				"type": 64
			}, {
				"content": "SU806Kem5Y+R",
				"type": 128
			}]
		},
		"province": {
			"default": 255,
			"types": [{
				"content": "5Lqs",
				"type": 0
			}, {
				"content": "5rSl",
				"type": 1
			}, {
				"content": "5YaA",
				"type": 2
			}, {
				"content": "5pmL",
				"type": 3
			}, {
				"content": "6JKZ",
				"type": 4
			}, {
				"content": "6L69",
				"type": 5
			}, {
				"content": "5ZCJ",
				"type": 6
			}, {
				"content": "6buR",
				"type": 7
			}, {
				"content": "5rKq",
				"type": 8
			}, {
				"content": "6IuP",
				"type": 9
			}, {
				"content": "5rWZ",
				"type": 10
			}, {
				"content": "55qW",
				"type": 11
			}, {
				"content": "6Ze9",
				"type": 12
			}, {
				"content": "6LWj",
				"type": 13
			}, {
				"content": "6bKB",
				"type": 14
			}, {
				"content": "6LGr",
				"type": 15
			}, {
				"content": "6YSC",
				"type": 16
			}, {
				"content": "5rmY",
				"type": 17
			}, {
				"content": "57Kk",
				"type": 18
			}, {
				"content": "5qGC",
				"type": 19
			}, {
				"content": "55C8",
				"type": 20
			}, {
				"content": "5rid",
				"type": 21
			}, {
				"content": "5bed",
				"type": 22
			}, {
				"content": "6LS1",
				"type": 23
			}, {
				"content": "5LqR",
				"type": 24
			}, {
				"content": "6JeP",
				"type": 25
			}, {
				"content": "6ZmV",
				"type": 26
			}, {
				"content": "55SY",
				"type": 27
			}, {
				"content": "6Z2S",
				"type": 28
			}, {
				"content": "5a6B",
				"type": 29
			}, {
				"content": "5paw",
				"type": 30
			}]
		},
		"reco_dis": {
			"default": 0,
			"types": [{
				"content": "2-4m",
				"type": 0
			}, {
				"content": "6-8m",
				"type": 1
			}, {
				"content": "4-6m",
				"type": 2
			}]
		},
		"recognition_type": {
			"default": 550970,
			"types": [{
				"content": "6JOd54mM",
				"type": 1
			}, {
				"content": "6buE54mM",
				"type": 24
			}, {
				"content": "5pWZ57uD6L2m",
				"type": 8192
			}, {
				"content": "6K2m6L2m",
				"type": 32
			}, {
				"content": "5q2m6K2m6L2m",
				"type": 229440
			}, {
				"content": "5Yab6L2m",
				"type": 768
			}, {
				"content": "5riv5r6z",
				"type": 18432
			}, {
				"content": "5L2/6aaG6L2m",
				"type": 1024
			}, {
				"content": "5rCR6Iiq",
				"type": 262144
			}, {
				"content": "5paw6IO95rqQ",
				"type": 1572864
			}, {
				"content": "5bqU5oCl6L2m",
				"type": 2097152
			}, {
				"content": "6aKG5LqL6aaG",
				"type": 4194304
			}, {
				"content": "5peg",
				"type": 8388608
			}]
		},
		"run_mode": {
			"default": 0,
			"types": [{
				"content": "6buY6K6k",
				"type": 0
			}, {
				"content": "5YGc6L2m5Zy6",
				"type": 1
			}, {
				"content": "5Y2h5Y+j",
				"type": 2
			}]
		},
		"snap_image_quality": {
			"default": 70,
			"max": 100,
			"min": 0
		},
		"snap_resolution": {
			"default": 10,
			"types": [{
				"content": "640*360",
				"type": 3
			}, {
				"content": "704*576",
				"type": 5
			}, {
				"content": "1280*720",
				"type": 9
			}, {
				"content": "1920*1080",
				"type": 10
			}, {
				"content": "2304*1296",
				"type": 11
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PROP"
}

Post
http://192.168.13.202/avsjson.php

{"type":"get_new_energy_plate_support"}	

{
	"body": {
		"support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_new_energy_plate_support"
}


Post
http://192.168.13.202/avsjson.php

{"type":"get_car_info_support"}	

{
	"body": {
		"car_brand_support": 0,
		"car_color_support": 0,
		"car_type_support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_car_info_support"
}

Post
http://192.168.13.202/avsjson.php

{"type":"AVS_GET_ALG_RESULT_PARAM"}	

{
	"body": {
		"alg_version": "2016LPRALG",
		"fake_threshold": 0,
		"out_result_type": 1,
		"province": 22,
		"reco_dis": 0,
		"recognition_type": 0,
		"run_mode": 0,
		"snap_image_quality": 100,
		"snap_resolution": 0,
		"time_zone": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_ALG_RESULT_PARAM"
}

#### 操作
触发模式 - 勾选虚拟线圈 Post

http://192.168.13.202/ivsctrl.php

5:1:Mw==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:Mw==

触发模式 - 取消勾选虚拟线圈 Post

http://192.168.13.202/ivsctrl.php

5:1:MQ==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MQ==


触发模式 - 勾选稳定识别 Post

http://192.168.13.202/ivsctrl.php

5:1:MQ==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MQ==

触发模式 - 取消勾选稳定识别 Post

http://192.168.13.202/ivsctrl.php

5:1:MA==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MA==

触发模式 - 勾选电平输入1 Post

http://192.168.13.202/ivsctrl.php

5:2:MTY	

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:2:MTY=

触发模式 - 取消勾选电平输入1 Post

http://192.168.13.202/ivsctrl.php

5:1:MA==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MA==

触发模式 - 勾选电平输入2 Post

http://192.168.13.202/ivsctrl.php

5:2:MzI	

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:2:MzI=

触发模式 - 取消勾选电平输入2 Post

http://192.168.13.202/ivsctrl.php

5:1:MA==

OK

http://192.168.13.202/getivsctrl.php

4:1:MA==

OK ivsctrl=4:1:MA==

识别参数 - 图片分辨率 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":5,"snap_image_quality":100,"fake_threshold":53}}	

640 -> 3
704 -> 5
1280 -> 9
1920 -> 10
2304 -> 11

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 图片质量 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":5,"snap_image_quality":100,"fake_threshold":53}}	

10% ~ 100%

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 连续抓拍模式 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_CAPTURE_PRM","body":{"mode":1,"duration":10,"none_duration":10,"max_duration":60}}	

mode：0-关闭 1-车牌触发 2-定时触发 3-线圈触发
duration：连续触发间隔（秒）
none_duration：无车牌抓拍间隔（秒）
max_duration：最长抓拍时间(秒)

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_CAPTURE_PRM"
}


http://192.168.13.202/avsjson.php

{"type":"AVS_GET_CAPTURE_PRM"}	
{
	"body": {
		"duration": 10,
		"max_duration": 60,
		"mode": 1,
		"none_duration": 10
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_CAPTURE_PRM"
}

识别参数 - 车牌像素限制 Post
http://192.168.13.202/seteventruleexhtm.php

1:1:50:400:10:2	

车牌像素限制(像素)：50~400
相同车牌触发间隔(秒)：10

OK seteventrule1

http://192.168.13.202/geteventruleexhtm.php

0

OK geteventruleex=1:1:50:400:10:2

识别参数 - 无车牌触发 - 勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:11:LTIxNDc0ODM2NDg	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:10:MjE0NzQ4MzY0OA==

识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:1:MA==	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:MA==

识别参数 - 无车牌触发 - 勾选车牌防伪 Post
http://192.168.13.202/ivsctrl.php

7:9:NTM2ODcwOTEy	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:9:NTM2ODcwOTEy

http://192.168.13.202/vb.htm?filtfakeplate=1&_=1646036087952 虚假车牌告警 Get
http://192.168.13.202/vb.htm?filtfakeplate=0&_=1646036087953 虚假车牌过滤 Get

识别参数 - 无车牌触发 - 勾选车牌防伪 - 防伪匹配度 Post
http://192.168.13.202/avsjson.php

{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"snap_resolution":11,"snap_image_quality":90,"fake_threshold":73}}	
低-53 中-73 高-93

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

识别参数 - 无车牌触发 - 取消勾选输出无车牌信息 Post
http://192.168.13.202/ivsctrl.php

7:1:MA==	

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:MA==

识别参数 - 输出车辆信息 - 勾选输出车标信息 Post
http://192.168.13.202/avsjson.php

{"type":"set_car_info_support","body":{"car_brand_support":1,"car_type_support":0,"car_color_support":0}}	
输出车标信息 car_brand_support 1
识别车辆类型 car_type_support 1
识别车身颜色 car_color_support 1
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_car_info_support"
}


http://192.168.13.202/avsjson.php

{"type":"get_car_info_support"}	

{
	"body": {
		"car_brand_support": 1,
		"car_color_support": 0,
		"car_type_support": 0
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_car_info_support"
}

识别参数 - 新能源车牌字段限制 - 支持D与F Post
http://192.168.13.202/avsjson.php

{"type":"set_new_energy_plate_support","body":{"support":1}}	

{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_new_energy_plate_support"
}

http://192.168.13.202/avsjson.php

{"type":"get_new_energy_plate_support"}	

{
	"body": {
		"support": 1
	},
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_new_energy_plate_support"
}

识别车牌 - 蓝牌（勾选）
http://192.168.13.202/ivsctrl.php

7:1:Mg==

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:Mg==

识别车牌 - 蓝牌（取消勾选）
http://192.168.13.202/ivsctrl.php

7:1:MA==

OK

http://192.168.13.202/getivsctrl.php

8:1:MA==

OK ivsctrl=8:1:Mg==


http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php
http://192.168.13.202/avsjson.php


### 音视频
#### 请求
http://192.168.13.202/request.php

{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}

{
	"body": {
		"enable_auth": true,
		"live_stream_type": "flv",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FEQkphZ3JZMmcvYjVkbDJoS2x5WEs4bXBjdwpxeWZVRDYwK09tZmVxdFUvOHkyaE5NL1pnbStiM05MS3ZvbE0yZ3VZUU9tS2M4cWNlVm84WGVLMTJHQmk0QUNBClF2WUlBbGVVUHZqbkZCM1J3Y01SVlhwUUVxQ2lnWnRtbFE3U1ZadTZneC8zdm9MKzFPaXBmN3lZM3pGOS91UjgKNXFTNlFKdmRGeFN6QWg3aVBRSURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "d088a2e4-7087-56b4-8e92-c8322519d523",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}

http://192.168.13.202/dgjson.php

{"type":"get_group_shared_io"}	

{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 0
}

Get
http://192.168.13.202/vb.htm?boa_eventjsonreq={%22type%22:%22get_addition_gpio%22}&_=1646102553605

OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}

http://192.168.13.202/request.php
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}	
{
	"body": [{
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}

http://192.168.13.202/getvoiceinfo.php
{"type":"AVS_GET_AUDIO_PROP"}	
{
	"body": {
		"audio_input": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "TGluZSBpbg==",
				"type": 0
			}, {
				"content": "TWljIGlu",
				"type": 1
			}]
		},
		"audio_level": {
			"default": 20,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"audio_out_level": {
			"default": 20,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"noise_filter": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5YWz6Zet",
				"type": 0
			}, {
				"content": "5omT5byA",
				"type": 1
			}]
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_AUDIO_PROP"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_ENCODE_PROP"}	

http://192.168.13.202/request.php
{"type":"get_ws_stream_cfg","module":"BUS_WEB_REQUEST"}	
{
	"body": {
		"flv_enable": true,
		"flv_enable_auth": true,
		"mjpeg_enable": false,
		"mjpeg_enable_auth": false
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_ws_stream_cfg"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_OSD_USER_PRM"}	
{
	"body": {
		"user_osd": {
			"user_osd_param": [{
				"color": 0,
				"display": 1,
				"front_size": 3,
				"id": 0,
				"text": "56ys5LiA6KGM"
			}, {
				"color": 1,
				"display": 1,
				"front_size": 3,
				"id": 1,
				"text": "c2Vjb25kIGxpbmU="
			}, {
				"color": 2,
				"display": 1,
				"front_size": 3,
				"id": 2,
				"text": "dGjkuInooYw="
			}, {
				"color": 3,
				"display": 1,
				"front_size": 3,
				"id": 3,
				"text": "56ys5Zub6KGMT1NEIFRDUCA="
			}],
			"x_pos": 10,
			"y_pos": 10
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_USER_PRM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_OSD_PARAM"}	
{
	"body": {
		"osd_param": {
			"date": {
				"date_format": 1,
				"enable": 1,
				"pos": 1310736
			},
			"datetime": {
				"enable": 1,
				"pos": 35913750,
				"time_format": 1
			},
			"text": {
				"context": "T1NEIFRleHQ=",
				"enable": 1,
				"pos": 34603537
			}
		},
		"realtime_show": {
			"car_info": 0,
			"distance": null,
			"extend_on_bottom": 1,
			"plate_pos": true,
			"realtime_result": 1,
			"virtualloop_area": 1
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_PARAM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_VIDEO_PARAM_PROPERTY"}	

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_ENCODE_PROP"}	
{
	"body": {
		"brightness": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"contrast": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"flip": {
			"default": 0,
			"enable": true,
			"types": [{
				"content": "5Y6f5aeL5Zu+5YOP",
				"type": 0
			}, {
				"content": "5LiK5LiL57+76L2s",
				"type": 1
			}, {
				"content": "5bem5Y+z57+76L2s",
				"type": 2
			}, {
				"content": "5Lit5b+D57+76L2s",
				"type": 3
			}]
		},
		"max_exposure": {
			"default": 3,
			"types": [{
				"content": "0~1ms",
				"type": 1
			}, {
				"content": "0~2ms",
				"type": 2
			}, {
				"content": "0~3ms",
				"type": 3
			}, {
				"content": "0~4ms",
				"type": 4
			}]
		},
		"max_gain": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		},
		"saturation": {
			"default": 50,
			"enable": true,
			"max": 100,
			"min": 0
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM_PROPERTY"
}

http://192.168.13.202/getvoiceinfo.php
{"type":"AVS_GET_AUDIO_PRM"}	
{
	"body": {
		"audio_input": 0,
		"audio_level": 100,
		"audio_out_level": 100,
		"noise_filter": 0
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_AUDIO_PRM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_VIDEO_PARAM"}	

{
	"body": {
		"video_param": {
			"brightness": 50,
			"contrast": 50,
			"flip": 0,
			"max_exposure": 3,
			"max_exposure_ms": null,
			"max_gain": 50,
			"saturation": 50
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM"
}

#### 操作
图像参数
http://192.168.13.202/avsjson.php
亮度 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"brightness":80}}}	
对比度 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"contrast":25}}}	
饱和度 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"saturation":39}}}	
最大增益 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"max_gain":62}}}	
曝光时间 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"max_exposure":1}}}	
图像翻转 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"flip":1}}}	0 原始 1 上下 2 左右 3 中心
恢复默认 - {"type":"AVS_SET_VIDEO_PARAM","body":{"video_param":{"brightness":50,"contrast":50,"saturation":50,"max_gain":50,"max_exposure":3,"flip":0}}}	
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_VIDEO_PARAM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_VIDEO_PARAM"}	
{
	"body": {
		"video_param": {
			"brightness": 80,
			"contrast": 50,
			"flip": 0,
			"max_exposure": 3,
			"max_exposure_ms": 3.33299994468689,
			"max_gain": 50,
			"saturation": 50
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_VIDEO_PARAM"
}

OSD参数
http://192.168.13.202/avsjson.php
{"type":"AVS_SET_OSD_USER_PRM","body":{"user_osd":{"user_osd_param":[{"id":0,"display":1,"color":0,"front_size":3,"text":"56ys5LiA6KGM"},{"id":1,"display":1,"color":1,"front_size":3,"text":"c2Vjb25kIGxpbmU="},{"id":2,"display":1,"color":2,"front_size":3,"text":"dGjkuInooYw="},{"id":3,"display":1,"color":3,"front_size":3,"text":"56ys5Zub6KGMT1NEIFRDUCA="}],"x_pos":10,"y_pos":10}}}
{"type":"AVS_SET_OSD_USER_PRM","body":{"user_osd":{"user_osd_param":[{"id":0,"display":1,"color":0,"front_size":3,"text":"56ys5LiA6KGM"},{"id":1,"display":1,"color":1,"front_size":3,"text":"c2Vjb25kIGxpbmU="},{"id":2,"display":1,"color":2,"front_size":3,"text":"dGjkuInooYw="},{"id":3,"display":1,"color":3,"front_size":3,"text":"56ys5Zub6KGMT1NEIFRDUCA="}],"x_pos":10,"y_pos":10}}}
{"type":"AVS_SET_OSD_USER_PRM","body":{"user_osd":{"user_osd_param":[{"id":0,"display":1,"color":0,"front_size":3,"text":"56ys5LiA6KGM"},{"id":1,"display":1,"color":1,"front_size":3,"text":"c2Vjb25kIGxpbmU="},{"id":2,"display":1,"color":2,"front_size":3,"text":"dGjkuInooYw="},{"id":3,"display":1,"color":3,"front_size":3,"text":"56ys5Zub6KGMT1NEIFRDUCA="}],"x_pos":3,"y_pos":27}}}
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_OSD_USER_PRM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_SET_OSD_PARAM","body":{"realtime_show":{"realtime_result":0,"virtualloop_area":1,"car_info":0,"extend_on_bottom":1},"osd_param":{"date":{"enable":1,"pos":1376273,"date_format":1},"datetime":{"enable":1,"pos":35979287,"time_format":1},"text":{"enable":1,"pos":34603538,"context":"T1NEIFRleHQ="}}}}
{"type":"AVS_SET_OSD_PARAM","body":{"realtime_show":{"realtime_result":1,"virtualloop_area":1,"car_info":1,"extend_on_bottom":1},"osd_param":{"date":{"enable":1,"pos":1376273,"date_format":1},"datetime":{"enable":1,"pos":35979287,"time_format":1},"text":{"enable":1,"pos":34603538,"context":"T1NEIFRleHQ="}}}}
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_OSD_PARAM"
}
http://192.168.13.202/avsjson.php
{"type":"AVS_GET_OSD_USER_PRM"}	
{
	"body": {
		"user_osd": {
			"user_osd_param": [{
				"color": 0,
				"display": 1,
				"front_size": 3,
				"id": 0,
				"text": "56ys5LiA6KGM"
			}, {
				"color": 1,
				"display": 1,
				"front_size": 3,
				"id": 1,
				"text": "c2Vjb25kIGxpbmU="
			}, {
				"color": 2,
				"display": 1,
				"front_size": 3,
				"id": 2,
				"text": "dGjkuInooYw="
			}, {
				"color": 3,
				"display": 1,
				"front_size": 3,
				"id": 3,
				"text": "56ys5Zub6KGMT1NEIFRDUCA="
			}],
			"x_pos": 10,
			"y_pos": 10
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_USER_PRM"
}
http://192.168.13.202/avsjson.php
{"type":"AVS_GET_OSD_PARAM"}	
{
	"body": {
		"osd_param": {
			"date": {
				"date_format": 1,
				"enable": 1,
				"pos": 1376273
			},
			"datetime": {
				"enable": 1,
				"pos": 35979287,
				"time_format": 1
			},
			"text": {
				"context": "T1NEIFRleHQ=",
				"enable": 1,
				"pos": 34603538
			}
		},
		"realtime_show": {
			"car_info": 0,
			"distance": null,
			"extend_on_bottom": 1,
			"plate_pos": true,
			"realtime_result": 0,
			"virtualloop_area": 1
		}
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_OSD_PARAM"
}

编码参数
FLV
http://192.168.13.202/avsjson.php
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":0,"encode_param":[{"stream_id":0,"data_rate":3072000,"frame_rate":25,"resolution":10,"encode_type":0,"rate_type":1,"video_quality":5}]}}
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":1,"encode_param":[{"stream_id":1,"data_rate":512000,"frame_rate":25,"resolution":5,"encode_type":0,"rate_type":1,"video_quality":3}]}}
{"type":"AVS_SET_ENCODE_PARAM","body":{"default_stream":2,"encode_param":[{"stream_id":2,"data_rate":1024000,"frame_rate":15,"resolution":9,"encode_type":1,"rate_type":0,"video_quality":3}]}}
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_ENCODE_PARAM"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_ENCODE_PARAM"}
{
	"body": {
		"default_stream": 0,
		"encode_param": [{
			"data_rate": 3072000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 10,
			"stream_id": 0,
			"video_quality": 5
		}, {
			"data_rate": 512000,
			"encode_type": 0,
			"frame_rate": 25,
			"rate_type": 1,
			"resolution": 5,
			"stream_id": 1,
			"video_quality": 3
		}, {
			"data_rate": 1024000,
			"encode_type": 1,
			"frame_rate": 15,
			"rate_type": 0,
			"resolution": 9,
			"stream_id": 2,
			"video_quality": 3
		}]
	},
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_GET_ENCODE_PARAM"
}

语音对讲
http://192.168.13.202/request.php
{"type":"evs_set_gpioin_func","module":"EVS_BUS_REQUEST","body":[{"is_enable":1,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":0,"tri_state":0},{"is_enable":0,"msg_module":"","msg_type":"","source":1,"tri_state":0}]}
{"type":"evs_set_gpioin_func","module":"EVS_BUS_REQUEST","body":[{"is_enable":0,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":0,"tri_state":0},{"is_enable":1,"msg_module":"PS_TALK_REQUESTION","msg_type":{"type":"AVS_TALK_REQUEST"},"source":1,"tri_state":0}]}
{
	"err_msg": "All done",
	"state": 200,
	"type": "evs_set_gpioin_func"
}

http://192.168.13.202/request.php
{"type":"evs_get_gpioin_func","module":"EVS_BUS_REQUEST"}
{
	"body": [{
		"is_enable": 1,
		"msg_module": "PS_TALK_REQUESTION",
		"msg_type": {
			"type": "AVS_TALK_REQUEST"
		},
		"source": 0,
		"tri_state": 0
	}, {
		"is_enable": 0,
		"msg_module": "",
		"msg_type": "",
		"source": 1,
		"tri_state": 0
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "evs_get_gpioin_func"
}

http://192.168.13.202/getvoiceinfo.php
{"type":"AVS_SET_AUDIO_PRM","body":{"audio_level":100,"audio_out_level":100,"audio_input":1,"noise_filter":0}}
{"type":"AVS_SET_AUDIO_PRM","body":{"audio_level":100,"audio_out_level":30,"audio_input":1,"noise_filter":1}}
{
	"error_msg": "OK",
	"state": 200,
	"type": "AVS_SET_AUDIO_PRM"
}

http://192.168.13.202/request.php
{"type":"set_ws_stream_cfg","module":"BUS_WEB_REQUEST","body":{"flv_enable":false,"flv_enable_auth":true,"mjpeg_enable":true,"mjpeg_enable_auth":false}}
{
	"err_msg": "OK",
	"state": 200,
	"type": "set_ws_stream_cfg"
}
http://192.168.13.202/request.php
{"type":"get_ws_stream_cfg","module":"BUS_WEB_REQUEST"}
{
	"body": {
		"flv_enable": false,
		"flv_enable_auth": true,
		"mjpeg_enable": true,
		"mjpeg_enable_auth": false
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_ws_stream_cfg"
}
http://192.168.13.202/request.php
{"type":"get_live_stream_type","module":"BUS_WEB_REQUEST"}
{
	"body": {
		"enable_auth": false,
		"live_stream_type": "mjpeg",
		"port": 9080,
		"pubkey": "LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FESEJMelV0blFkYlVYZVZRNHc2WVJqSW14aQpwdENBOWk0WTJ5d0tsazJ0K1lUeGlKM3R5N2FRN3laVE93VHJXZU5Kb1lHODZWUTBURi8xUzlpUERRQUsrRnpvCmxjNVpPMDY1VW1yTElxbVZTTTZ0bHhQRWs3QlUrM3JRSzJTVFRmQy9LK2U3UzBiQmN2VDYwTFRUczJxTHV3UVAKRU1Sb2dWdS81bWJ1WW9ZR0ZRSURBUDdWCi0tLS0tRU5EIFBVQkxJQyBLRVktLS0tLQo=",
		"token": "039258ae-3a87-42f2-1248-9def7a849a6c",
		"transport_type": {
			"0": "ws",
			"1": "http"
		}
	},
	"err_msg": "OK",
	"state": 200,
	"type": "get_live_stream_type"
}

### 基础网络
#### 请求
http://192.168.13.202/systemjson.php
{"type":"get_net_and_port"}	
{
	"body": {
		"dhcp": 0,
		"dns": "114.114.114.114",
		"dns2": "8.8.8.8",
		"gateway": "192.168.1.11",
		"http_port": 80,
		"https_en": 0,
		"ip": "192.168.13.202",
		"netmask": "255.255.128.0",
		"rtsp_port": 8557
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_and_port"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_upnp_net"}	
{
	"body": {
		"enable": 0,
		"http_port": 30001,
		"rtsp_port": 30002,
		"status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_upnp_net"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_ddns_net"}	
{
	"body": {
		"brandurl": "www.3322.net",
		"enable": 0,
		"name": "",
		"password": "123456",
		"status": 0,
		"username": "root"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ddns_net"
}

http://192.168.13.202/systemjson.php
{"type":"get_discover"}	
{
	"body": {
		"discover_mode": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_discover"
}

http://192.168.13.202/mtujson.php
{"type":"get_net_mtu"}	
{
	"body": {
		"mtu": 1500
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_net_mtu"
}

http://192.168.13.202/systemjson.php
{"type":"get_apn_config"}	
{
	"body": {
		"apnaddr": "192.168.1.12",
		"authentication": 0,
		"passwd": "apn_pass",
		"username": "apn_user"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_apn_config"
}

http://192.168.13.202/systemjson.php
{"type":"get_4g_cur_state"}	
{
	"body": {
		"4g_iccid": "",
		"call_way": 1,
		"imei": "",
		"ip": "",
		"link_company": 0,
		"link_state": 0,
		"net_state": 0,
		"net_type": 0,
		"singal_state": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_4g_cur_state"
}

http://192.168.13.202/request.php
{"type":"get_onenet_prm","module":"ONENET_REQUEST_MSG"}	
{
	"body": {
		"onenet": {
			"enable": 0,
			"key": "",
			"mqttport": 1883,
			"mqttserver": "",
			"productid": ""
		},
		"push_property": {
			"location": {
				"altitude": 0,
				"coordinate": 1,
				"enable": 0,
				"latitude": 0,
				"longitude": 0
			},
			"sn": {
				"enable": 0
			},
			"software": {
				"enable": 0
			},
			"time_span": 0
		}
	},
	"state": 200,
	"type": "get_onenet_prm"
}


#### 操作

### 白名单
#### 请求
http://192.168.13.202/dboprnew.php
{"type":"get_wl_fuzzy"}	
{
	"body": {
		"fuzzy_ignore_cc": 0,
		"fuzzy_query_len": 0,
		"fuzzy_query_type": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_fuzzy"
}

http://192.168.13.202/dboprnew.php
{"type":"get_wl_check_status"}	
{
	"body": {
		"dev_time": {
			"time_day": 1,
			"time_hour": 13,
			"time_min": 59,
			"time_mon": 3,
			"time_sec": 26,
			"time_year": 2022
		},
		"filter_enable": 0,
		"offline_status": 0,
		"white_list_flag": 1
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_wl_check_status"
}

http://192.168.13.202/dbopr.php
{"cmd":"white_list_operator","id":"999999","operator_type":"select_count_by_plate","plate":""}	
{
	"cmd": "white_list_operator",
	"id": "999999",
	"operator_type": "select_count_by_plate",
	"state_code": 200,
	"total_count": 2
}

http://192.168.13.202/dbopr.php
{"cmd":"white_list_operator","id":"999999","operator_type":"select_fuzzy","plate":"","start_pos":0,"select_count":50}	
{
	"cmd": "white_list_operator",
	"dldb_rec": [{
		"context": "",
		"enable": 1,
		"enable_time": "2021-12-31 09:46:00",
		"need_alarm": 0,
		"overdue_time": "2022-01-02 09:46:00",
		"plate": "粤BF47625",
		"seg_time_end": "00:00:00",
		"seg_time_start": "00:00:00",
		"time_seg_enable": 0
	}, {
		"context": "",
		"enable": 1,
		"enable_time": "2021-12-31 09:43:00",
		"need_alarm": 0,
		"overdue_time": "2022-01-02 09:43:00",
		"plate": "粤BU55S6",
		"seg_time_end": "00:00:00",
		"seg_time_start": "00:00:00",
		"time_seg_enable": 0
	}],
	"id": "999999",
	"operator_type": "select_fuzzy",
	"state_code": 200
}

#### 操作

### 高级网络
#### 请求
http://192.168.13.202/vb.htm?gethttpconfigall={%22type%22:%22get_http_cfg%22}&_=1646113962019
OK={"body":{"centerserver":{"enable_ssl":0,"hostname":"MTkyLjE2OC4xLjEwNg==","http_timeout":5,"port":80,"ssl_port":443},"cs_alarm_gioin":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL2dpby5waHA="},"cs_alarm_plate":{"big_img":0,"enable":0,"plate_rlt_level":0,"retransmission":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"cs_dev_reg":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3JlY2VpdmVkZXZpY2VpbmZvLnBocA=="},"cs_serial":{"enable":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3NlcmlhbC5waHA="},"http_ip_ext":{"IpExt":[]},"offline_status":0,"proxy_http":{"big_img":0,"enable":0,"small_img":0,"uri":"L2RldmljZW1hbmFnZW1lbnQvcGhwL3BsYXRlcmVzdWx0LnBocA=="},"repush_nums":0,"serv_poll_status":0,"ssl_ca":{"ca_enable":0,"ca_file_exist":0}},"err_msg":"OK","state":200,"state_code":200,"type":"get_http_cfg"}

http://192.168.13.202/systemjson.php
{"type":"ss_get_vpn_net"}	
{
	"body": {
		"cfg_data": "",
		"check_file": [],
		"enable": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_vpn_net"
}

http://192.168.13.202/vb.htm?gethttpconfigall={%22type%22:%22get_ftp_cfg%22}&_=1646113962020
OK={"body":{"enable":0,"foldername":"default_name","password":"ftpuser","port":21,"server_ip":"192.168.1.16","username":"ftpuser"},"err_msg":"OK","state":200,"state_code":200,"type":"get_ftp_cfg"}

http://192.168.13.202/stp.php
{"type":"get_stp_conf"}	
{
	"body": {
		"addr": "https://device.pdns.cloud",
		"connected": 0,
		"enabled": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_stp_conf"
}

http://192.168.13.202/request.php
{"type":"get_http_t1400_cfg","module":"HTTPSENDER_GAT1400_CONFIG_ALL"}	
{
	"body": {
		"connected": 0,
		"device_id": "MzIwNTA1MDAwMDEzMjAwMDAwMDc=",
		"enable": 0,
		"heartbeat_uri": "L1ZJSUQvU3lzdGVtL0tlZXBhbGl2ZQ==",
		"motor_vehicles_uri": "L1ZJSUQvTW90b3JWZWhpY2xlcw==",
		"register_uri": "L1ZJSUQvU3lzdGVtL1JlZ2lzdGVy",
		"server_auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"server_ip": "MTkyLjE2OC4xLjE2",
		"server_port": 8080,
		"timeout": 5,
		"unregister_uri": "L1ZJSUQvU3lzdGVtL1VuUmVnaXN0ZXI="
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_http_t1400_cfg"
}

#### 操作

### 外设管理
#### 请求
http://192.168.13.202/avsjson.php
{"type":"ps_get_voice_config"}	
{
	"error_msg": "OK",
	"state": 200,
	"talk_io": 0,
	"type": "ps_get_voice_config",
	"voice_defalut_interval": 100,
	"voice_defalut_male": 1,
	"voice_defalut_volume": 100
}

http://192.168.13.202/vb.htm?getlinkagecfg&_=1646113962022
OK getlinkagecfg={
   "black_list" : [],
   "device_capacity" : {
      "ado_enable" : 1,
      "e4g_num" : 1,
      "fan_num" : 0,
      "img_reset_num" : 0,
      "io_in_num" : 2,
      "io_out_num" : 2,
      "key_reset_num" : 1,
      "led_num" : 0,
      "mcu_num" : 0,
      "moto_num" : 0,
      "opensdk_en" : 1,
      "stp_enable" : 1,
      "ttl_num" : 0,
      "tty_num" : 2,
      "wifi_num" : 0
   },
   "enable_fake_plate" : 1,
   "ext_ioctl1" : [],
   "ext_ioctl2" : [],
   "ext_ioctl3" : [],
   "ext_ioctl4" : [],
   "no_licence" : [],
   "not_white_list" : [],
   "special_plates" : [],
   "white_list" : [ 56 ]
}

http://192.168.13.202/vb.htm?boa_busjsonreq={%22type%22:%22get_def_out_time%22}&_=1646113962023
OK={"body":{"def_out_time":500},"err_msg":"OK","state":200,"state_code":200,"type":"get_def_out_time"}

http://192.168.13.202/vb.htm?boa_eventjsonreq={%22type%22:%22get_addition_gpio%22}&_=1646113962024
OK={"body":{"delay_stop_time":0,"enable":0,"frequency_time":1000,"input_gpio":0,"output_gpio":0},"err_msg":"All done","state":200,"type":"get_addition_gpio"}

http://192.168.13.202/vb.htm?getwebspesialplates={%22type%22:%22get_special_plates%22}&_=1646113962025
OK={"body":{"plates":[{"index":0,"name":"5pyq55+l6L2m54mM","status":0},{"index":1,"name":"6JOd54mM","status":0},{"index":2,"name":"6buR54mM","status":0},{"index":3,"name":"5Y2V5o6S6buE54mM","status":0},{"index":4,"name":"5Y+M5o6S6buE54mM","status":0},{"index":5,"name":"6K2m6L2m6L2m54mM","status":0},{"index":6,"name":"5q2m6K2m6L2m54mM","status":0},{"index":7,"name":"5Liq5oCn5YyW6L2m54mM","status":0},{"index":8,"name":"5Y2V5o6S5Yab6L2m54mM","status":0},{"index":9,"name":"5Y+M5o6S5Yab6L2m54mM","status":0},{"index":10,"name":"5L2/6aaG6L2m54mM","status":0},{"index":11,"name":"6aaZ5riv6L+b5Ye65Lit5Zu95aSn6ZmG6L2m54mM","status":0},{"index":12,"name":"5Yac55So6L2m54mM","status":0},{"index":13,"name":"5pWZ57uD6L2m54mM","status":0},{"index":14,"name":"5r6z6Zeo6L+b5Ye65Lit5Zu95aSn6ZmG6L2m54mM","status":0},{"index":15,"name":"5Y+M5bGC5q2m6K2m6L2m54mM","status":0},{"index":16,"name":"5q2m6K2m5oC76Zif6L2m54mM","status":1},{"index":17,"name":"5Y+M5bGC5q2m6K2m5oC76Zif6L2m54mM","status":0},{"index":18,"name":"5rCR6Iiq6L2m54mM","status":0},{"index":19,"name":"5paw6IO95rqQ6L2m54mM","status":0},{"index":20,"name":"5paw6IO95rqQ6buE54mM","status":0},{"index":21,"name":"5bqU5oCl6L2m54mM","status":0},{"index":22,"name":"6aKG5LqL6aaG6L2m54mM","status":0}]},"err_msg":"OK","state":200,"state_code":200,"type":"get_special_plates"}

http://192.168.13.202/vb.htm?paratest=uart.0&_=1646113962026
OK uart.0=OTYwMDowOjg6MQ==

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_LED_PROP"}	
{
	"body": {
		"led_level": {
			"default": 2,
			"max": 4,
			"min": -1,
			"types": [{
				"content": "5YWz6Zet",
				"type": -1
			}, {
				"content": "Muexsw==",
				"type": 0
			}, {
				"content": "NOexsw==",
				"type": 1
			}, {
				"content": "Nuexsw==",
				"type": 2
			}, {
				"content": "N+exsw==",
				"type": 3
			}, {
				"content": "OOexsw==",
				"type": 4
			}]
		},
		"led_mode": [{
			"content": "5pm66IO9",
			"type": 0
		}, {
			"content": "5bi45Lqu",
			"type": 1
		}, {
			"content": "5bi454Gt",
			"type": 2
		}, {
			"content": "5pe26Ze05q61",
			"type": 3
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_PROP"
}

http://192.168.13.202/request.php
{"type":"get_flashlamp_info","module":"EVS_BUS_REQUEST"}	
{
	"body": {
		"flash_info": {
			"delay_time": 50,
			"light_time": 3000
		},
		"input_gpio": 0,
		"light_mode": 4,
		"output_gpio": 0,
		"time_ctrl": [{
			"id": 0,
			"time_begin": "00:00:00",
			"time_end": "09:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "09:00:00",
			"time_end": "18:00:00",
			"timectrl_enable": 0
		}, {
			"id": 0,
			"time_begin": "18:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": 0
		}]
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_flashlamp_info"
}

http://192.168.13.202/evtjson.php
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":1}}	
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}

http://192.168.13.202/evtjson.php
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":1}}	
{
	"body": {
		"io_status": 1
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}

http://192.168.13.202/evtjson.php
{"type":"evs_gpio_test_ctrl","body":{"io_number":0,"io_opera":2,"io_type":2}}	
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}

http://192.168.13.202/evtjson.php
{"type":"evs_gpio_test_ctrl","body":{"io_number":1,"io_opera":2,"io_type":2}}	
{
	"body": {
		"io_status": 0
	},
	"err_msg": "All done",
	"state": 200,
	"type": "evs_gpio_test_ctrl"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_GET_LED_CTRL"}	
{
	"body": {
		"led_level": -1,
		"led_mode": 3,
		"time_ctrl": [{
			"id": 0,
			"led_level": 2,
			"time_begin": "00:00:00",
			"time_end": "04:30:00",
			"timectrl_enable": true
		}, {
			"id": 1,
			"led_level": -1,
			"time_begin": "04:30:00",
			"time_end": "09:00:00",
			"timectrl_enable": false
		}, {
			"id": 2,
			"led_level": 1,
			"time_begin": "09:00:00",
			"time_end": "24:00:00",
			"timectrl_enable": true
		}]
	},
	"err_msg": "OK",
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_GET_LED_CTRL"
}


#### 操作

### 屏显语音
#### 请求
http://192.168.13.202/avsjson.php
{"type":"ps_get_voice_config"}	
{
	"error_msg": "OK",
	"state": 200,
	"talk_io": 0,
	"type": "ps_get_voice_config",
	"voice_defalut_interval": 100,
	"voice_defalut_male": 1,
	"voice_defalut_volume": 100
}

http://192.168.13.202/dgjson.php
{"type":"get_group_cfg"}	
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "output"
	}
}

http://192.168.13.202/bbjson.php
{"type":"get_rs485_push"}	
{
	"body": {
		"comm_push_cfg": [{
			"header": "BB88"
		}, {
			"enable": ""
		}, {
			"licensecolor": ""
		}, {
			"license": ""
		}, {
			"confidence": ""
		}, {
			"wlresult": ""
		}, {
			"direction": ""
		}, {
			"checkbegin": "2"
		}, {
			"checkend": "14"
		}, {
			"checksum": "xor"
		}, {
			"end": ""
		}]
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_rs485_push"
}

http://192.168.13.202/bbjson.php
{"type":"get_led_ctrl_cfg"}	
{
	"body": {
		"led_status": 0,
		"line_num": 4,
		"muticast_ip": "",
		"screen_ctrl_pro_type": 0,
		"screen_isopen": 0,
		"use_serial_port": 1,
		"voice_sync_screen": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_led_ctrl_cfg"
}

http://192.168.13.202/dgjson.php
{"type":"get_total_parking"}	
{
	"current_parking": 0,
	"state": 200,
	"total_parking": 0,
	"type": "get_total_parking"
}

http://192.168.13.202/voicecfg.php
{"type":"get_voice_cfg"}	
{
	"body": {
		"greetings": "xPq6ww==",
		"start_mode": 1,
		"tag": "0rvCt8uzt+c=",
		"voice_interval": 100,
		"voice_male": 1,
		"voice_time_inv_level": [{
			"end_time": "07:00:00",
			"start_time": "00:00:00",
			"voice_volume": 0
		}, {
			"end_time": "20:00:00",
			"start_time": "07:00:00",
			"voice_volume": 0
		}, {
			"end_time": "24:00:00",
			"start_time": "24:00:00",
			"voice_volume": 0
		}],
		"voice_type": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_voice_cfg"
}

#### 操作
http://192.168.13.202/bbjson.php
{"type":"set_led_ctrl_cfg","body":{"screen_ctrl_pro_type":0}}	
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_led_ctrl_cfg"
}

http://192.168.13.202/bbjson.php
{"type":"set_rs485_push","body":{"comm_push_cfg":[{"header":"BB88"},{"enable":"0"},{"licensecolor":"0"},{"license":"0"},{"confidence":"0"},{"wlresult":"0"},{"direction":"0"},{"checkbegin":"2"},{"checkend":"14"},{"checksum":"xor"},{"end":""},{"encode":"1"},{"edian":"little"},{"ne_compatible":"0"}]}}	
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_rs485_push"
}

http://192.168.13.202/bbjson.php
{"type":"get_led_ctrl_cfg"}	
{
	"body": {
		"led_status": 0,
		"line_num": 4,
		"muticast_ip": "",
		"screen_ctrl_pro_type": 0,
		"screen_isopen": 0,
		"use_serial_port": 0,
		"voice_sync_screen": 0
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_led_ctrl_cfg"
}

### 出入口配置
#### 请求
http://192.168.13.202/avsjson.php
{"type":"ps_get_voice_config"}	
{
	"error_msg": "OK",
	"state": 200,
	"talk_io": 0,
	"type": "ps_get_voice_config",
	"voice_defalut_interval": 100,
	"voice_defalut_male": 1,
	"voice_defalut_volume": 100
}

http://192.168.13.202/dgjson.php
{"type":"get_ast_mode"}	
{
	"dealy_time": "faster",
	"state": 200,
	"type": "get_ast_mode"
}

http://192.168.13.202/dgjson.php
{"type":"get_ast_dealy_time"}	
{
	"dealy_time": 500,
	"state": 200,
	"type": "get_ast_dealy_time"
}

http://192.168.13.202/dgjson.php
{"type":"get_device_match_mode"}	
{
	"mode": "exact_mode",
	"state": 200,
	"type": "get_device_match_mode"
}

http://192.168.13.202/dgjson.php
{"type":"get_group_shared_io"}	
{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 0
}

http://192.168.13.202/dgjson.php
{"type":"get_total_parking"}	
{
	"current_parking": 0,
	"state": 200,
	"total_parking": 0,
	"type": "get_total_parking"
}

http://192.168.13.202/dgjson.php
{"type":"get_group_model"}	
{
	"enable": 0,
	"state": 200,
	"type": "get_group_model"
}

http://192.168.13.202/dgjson.php
{"type":"get_group_switch"}	
{
	"enable": 0,
	"state": 200,
	"type": "get_group_switch"
}

http://192.168.13.202/dgjson.php
{"type":"get_group_cfg"}	
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "output"
	}
}


http://192.168.13.202/dgjson.php
{"type":"get_group_cfg"}	
{
	"group_cfg": {
		"group_vzids": []
	},
	"state": 200,
	"type": "get_group_cfg",
	"vzid": {
		"ast_type": 0,
		"enable_group": true,
		"ip_addr": "192.168.13.202",
		"name": "bHk=&MTkyLjE2OC43LjIy",
		"sn": "c806ca86-8de9c3f4",
		"type": "output"
	}
}

#### 操作
开启主辅相机模式（设备重启）
http://192.168.13.202/dgjson.php
关闭 - {"type":"set_group_model","enable":0}	
开启 - {"type":"set_group_model","enable":1}	
{
	"state": 200,
	"type": "set_group_model"
}

http://192.168.13.202/dgjson.php
{"type":"get_group_model"}	
{
	"enable": 1,
	"state": 200,
	"type": "get_group_model"
}

http://192.168.13.202/dgjson.php
{"group_cfg":{"group_vzids":[]},"state":200,"type":"set_group_cfg","vzid":{"ast_type":0,"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"output"}}	
{
	"state": 200,
	"type": "set_group_cfg"
}

触发模式 
http://192.168.13.202/dgjson.php
延迟等待模式 - {"type":"set_ast_mode","mode":"aggregated"}
多结果模式 - {"type":"set_ast_mode","mode":"direct"}	
{
	"state": 200,
	"type": "set_ast_mode"
}

http://192.168.13.202/dgjson.php
{"type":"get_ast_mode"}	
{
	"mode": "direct",
	"state": 200,
	"type": "get_ast_mode"
}

延迟等待
http://192.168.13.202/dgjson.php
{"type":"set_ast_dealy_time","dealy_time":550}	
{
	"state": 200,
	"type": "set_ast_dealy_time"
}

http://192.168.13.202/dgjson.php
{"type":"get_ast_dealy_time"}	
{
	"dealy_time": 550,
	"state": 200,
	"type": "get_ast_dealy_time"
}

匹配规则
http://192.168.13.202/dgjson.php
精准匹配 - {"type":"set_device_match_mode","mode":"exact_mode"}	
相似字符 - {"type":"set_device_match_mode","mode":"fuzzy_mode"}
{
	"state": 200,
	"type": "set_device_match_mode"
}

http://192.168.13.202/dgjson.php
{"type":"get_device_match_mode"}
{
	"mode": "fuzzy_mode",
	"state": 200,
	"type": "get_device_match_mode"
}

相辅相机IO 
http://192.168.13.202/dgjson.php
开关量1 - {"type":"set_group_shared_io","value":65536}	
开关量2 - {"type":"set_group_shared_io","value":131073}
开关量输出1 - {"type":"set_group_shared_io","value":1}
开关量输出2 - {"type":"set_group_shared_io","value":2}
{
	"state": 200,
	"type": "set_group_shared_io"
}


http://192.168.13.202/dgjson.php
{"type":"get_group_shared_io"}	
{
	"state": 200,
	"type": "get_group_shared_io",
	"value": 131073
}

停车场配置 - 开启停车场组网
http://192.168.13.202/dgjson.php
开启 - {"type":"set_group_switch","enable":1}	
关闭 - {"type":"set_group_switch","enable":1}	
{
	"state": 200,
	"type": "set_group_switch"
}

停车场配置 - 修改出入口
http://192.168.13.202/dgjson.php
{"type":"set_group_cfg","state":200,"group_cfg":{"group_vzids":[]},"vzid":{"enable_group":true,"ip_addr":"192.168.13.202","name":"","sn":"c806ca86-8de9c3f4","type":"input","ast_type":0}}	
{"type":"set_group_cfg","state":200,"group_cfg":{"group_vzids":[]},"vzid":{"enable_group":true,"ip_addr":"192.168.13.202","name":"6L2m5bqTNzE=&MTkyLjE2OC4xMy4yMDI=#","sn":"c806ca86-8de9c3f4","type":"input"}}
{
	"state": 200,
	"type": "set_group_cfg"
}
### 联动管理
#### 请求
http://192.168.13.202/request.php
{"type":"get_all_mate","module":"PM_WEB_REQUEST"}
{
	"body": "",
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": ""
}
#### 操作
联动管理 - 查找设备
http://192.168.13.202/request.php
{"type":"search_all_mate","module":"PM_WEB_REQUEST"}	
{
	"state": 400,
	"state_code": 400,
	"type": ""
}

## 设备维护页
### 设备信息
#### 请求
http://192.168.13.202/request.php
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}	
{
	"body": "",
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}

http://192.168.13.202/systemjson.php
{"type":"get_device_info"}	
{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_devname"}	
{
	"body": {
		"title": "SVZT"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}
#### 操作
修改设备名称
http://192.168.13.202/systemjson.php
{"type":"ss_set_devname","body":{"title":"SVZTMQ=="}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_devname"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_devname"}	
{
	"body": {
		"title": "SVZTMQ=="
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_devname"
}

http://192.168.13.202/request.php
{"type":"set_web_saved_value","module":"WEB_SELF_REQUEST","body":{"device_type":"300万高清车牌识别一体机1"}}
{
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "set_web_saved_value"
}

http://192.168.13.202/request.php
{"type":"get_web_saved_value","module":"WEB_SELF_REQUEST"}
{
	"body": {
		"device_type": "300万高清车牌识别一体机1"
	},
	"module": "WEB_SELF_REQUEST",
	"state": 200,
	"type": "get_web_saved_value"
}
### 用户管理
#### 请求
http://192.168.13.202/systemjson.php
{"type":"ss_get_accounts","body":{"remote_id":""}}	
{
	"body": [{
		"auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_accounts"
}


#### 操作
用户管理 - 添加
http://192.168.13.202/systemjson.php
{"type":"ss_set_account","body":{"remote_id":"","auth":"yMgdYh8fHx/VU2eJ4cEp","authority":0,"control":"add"}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_accounts","body":{"remote_id":""}}
{
	"body": [{
		"auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}, {
		"auth": "HWIAAAAAHWIyBGTL3dPR",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_accounts"
}
用户管理 - 编辑
http://192.168.13.202/systemjson.php
{"type":"ss_set_account","body":{"remote_id":"","auth":"QMkdYpGRkZGRmEY/Zk09","authority":1,"control":"add"}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_accounts","body":{"remote_id":""}}	
{
	"body": [{
		"auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}, {
		"auth": "HWIAAAAAHWIyBGTL3YOB",
		"authority": 1,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_accounts"
}

用户管理 - 删除
http://192.168.13.202/systemjson.php
{"type":"ss_set_account","body":{"remote_id":"","auth":"k8kdYoqKioqt6LPVCw==","authority":"","control":"del"}}
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}

http://192.168.13.202/systemjson.php
{"type":"ss_get_accounts","body":{"remote_id":""}}	
{
	"body": [{
		"auth": "HWIAAAAAHWIyAWjDiYjRsVbxlw==",
		"authority": 0,
		"encrypt_level": 1,
		"heartbeat_timeout": 20,
		"sign_in_timeout": 15
	}],
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_accounts"
}

登陆超时
http://192.168.13.202/systemjson.php
{"type":"ss_set_account","body":{"sign_in_timeout":15,"control":"add"}}	
15分钟
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_account"
}

### 时间设置
#### 请求
http://192.168.13.202/systemjson.php
{"type":"ss_get_ntp_cfg"}	
{
	"body": {
		"cycle": 600,
		"enable": 1,
		"server": "ntp.ntsc.ac.cn"
	},
	"err_msg": "All done",
	"state": 200,
	"type": "ss_get_ntp_cfg"
}

http://192.168.13.202/vb.htm?getdate=&gettime=&_=1646113962033
OK getdate=2022-03-01 Tue
OK gettime=14:28:20

http://192.168.13.202/systemjson.php
{"type":"get_timezone"}	
{
	"body": {
		"timezone": 480
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_timezone"
}

http://192.168.13.202/systemjson.php
{"type":"get_DST"}	
{
	"body": {
		"CurrentZONE": 480,
		"DST_enable": 0,
		"DST_offset": 30,
		"EndTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		},
		"StartTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		}
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_DST"
}
#### 操作
时区设置
http://192.168.13.202/systemjson.php
{"type":"set_timezone","body":{"timezone":540}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_timezone"
}

http://192.168.13.202/avsjson.php
{"type":"AVS_SET_ALG_RESULT_PARAM","body":{"time_zone":540}}	
{
	"error_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "AVS_SET_ALG_RESULT_PARAM"
}

http://192.168.13.202/systemjson.php
{"type":"get_timezone"}	
{
	"body": {
		"timezone": 540
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_timezone"
}

夏令时
http://192.168.13.202/systemjson.php
{"type":"set_DST","body":{"CurrentZONE":540,"DST_enable":1,"DST_offset":30,"StartTime":{"dmon":1,"dweek":1,"dday":1,"dhour":0},"EndTime":{"dmon":2,"dweek":1,"dday":1,"dhour":0}}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_DST"
}

http://192.168.13.202/systemjson.php
{"type":"get_DST"}	
{
	"body": {
		"CurrentZONE": 540,
		"DST_enable": 1,
		"DST_offset": 30,
		"EndTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 2,
			"dweek": 1
		},
		"StartTime": {
			"dday": 1,
			"dhour": 0,
			"dmon": 1,
			"dweek": 1
		}
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_DST"
}

手动设置时间
http://192.168.13.202/systemjson.php
{"type":"ss_set_timing","body":{"datetime":"2022-03-02 00:00:00"}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_timing"
}

同步本地时间
http://192.168.13.202/systemjson.php
{"type":"ss_set_timing","body":{"datetime":"2022-03-01 15:15:56"}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_timing"
}

NTP校时
http://192.168.13.202/systemjson.php
{"type":"ss_set_ntp_cfg","body":{"enable":1,"server":"ntp.ntsc.ac.cn","cycle":600}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "ss_set_ntp_cfg"
}

### 存储管理
#### 请求
http://192.168.13.202/request.php
{"type":"STORE_STAT_REQUEST","module":"STORE_BUSINESS_REQUEST"}	
{
	"body": {
		"vzfs": [{
			"dev_infos": [{
				"path": "/dev/mtdblock17",
				"size": 16777216
			}, {
				"path": "/dev/mtdblock18",
				"size": 16777216
			}],
			"fmt_seconds": 0,
			"pic_size": 18874368,
			"pic_used": 6291456,
			"rec_size": 0,
			"rec_used": 0,
			"size": 18874368,
			"state": 0,
			"type": "flash",
			"used": 6291456
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_STAT_REQUEST"
}

http://192.168.13.202/request.php
{"type":"STORE_GET_RECORD_PARA_REQUEST","module":"STORE_BUSINESS_REQUEST"}	
{
	"body": {
		"channel": [{
			"chan_id": 0,
			"event_param": {
				"event_mode": 1,
				"period": 180
			},
			"mode": 0,
			"rec_type": 1,
			"record_param": {
				"time": [{
					"id": 0,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 1,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 2,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 3,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 4,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 5,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}, {
					"id": 6,
					"period": [{
						"end_hour": 23,
						"end_minute": 59,
						"id": 0,
						"start_hour": 0,
						"start_minute": 0
					}]
				}]
			}
		}]
	},
	"err_msg": "All Done",
	"state": 200,
	"type": "STORE_GET_RECORD_PARA_REQUEST"
}

#### 操作
存储管理 - 格式化

录像计划

### 日志检测
#### 请求

#### 操作
http://192.168.13.202/logsearch.php
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":1,"max_id":0,"min_id":0,"start_id":0}}}
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17184}}}	
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17084}}}	
{"type":"log_search","module":"BUS_WEB_REQUEST","body":{"type_mask":30,"start_time":{"sec":1646064000,"usec":0},"end_time":{"sec":1646150399,"usec":0},"limit":100,"qnode":{"qtype":1,"is_first":0,"max_id":17284,"min_id":17081,"start_id":17081}}}	
{
	"body": {
		"logs": [{
			"data": "163,24,Etern device write GPIO OUT, source[1], value 0, clock time:15844 ms",
			"level": 5,
			"time": "2022-03-01 15:00:50",
			"type": 2
		}, {
			"data": "163,24,Etern device write GPIO OUT, source[0], value 0, clock time:15844 ms",
			"level": 5,
			"time": "2022-03-01 15:00:50",
			"type": 2
		}, {
			"data": "1220 system start. (12.1.1.202112230)app compile Dec 23 2021 17:56:09",
			"level": 5,
			"time": "2022-03-01 15:00:49",
			"type": 4
		}, {
			"data": "2420 Web Server Start Reboot Dev.",
			"level": 5,
			"time": "2022-03-01 15:00:26",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:59:55",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:54:55",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:49:54",
			"type": 2
		}, {
			"data": "1206 user config reboot time {\"enable\":0,\"minute\":0,\"wday\":\"1,3\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:35",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:35",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"1,3\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:13",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:13",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"1\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:47:00",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:47:00",
			"type": 16
		}, {
			"data": "1206 user config reboot time {\"enable\":1,\"minute\":0,\"wday\":\"\"}\n.",
			"level": 5,
			"time": "2022-03-01 14:46:09",
			"type": 16
		}, {
			"data": "1206 config reboot param.",
			"level": 5,
			"time": "2022-03-01 14:46:09",
			"type": 16
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:44:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:39:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:34:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:29:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:24:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:19:54",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:14:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:09:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 14:04:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:59:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:54:53",
			"type": 2
		}, {
			"data": "1213 user manual timing {\"datetime\":\"2022-03-01 13:52:41\",\"type\":\"login\"}.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1213 usr set time.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1228 login set time.",
			"level": 5,
			"time": "2022-03-01 13:52:42",
			"type": 16
		}, {
			"data": "1218 link is up.",
			"level": 5,
			"time": "2022-03-01 13:50:58",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:49:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:44:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:39:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:34:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:29:53",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:24:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:19:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:14:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:09:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 13:04:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:59:52",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:54:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:49:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:44:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:39:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:34:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:29:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:24:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:19:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:14:51",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:09:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 12:04:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:59:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:54:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:49:49",
			"type": 2
		}, {
			"data": "1217 link is down.",
			"level": 5,
			"time": "2022-03-01 11:45:41",
			"type": 8
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:44:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:39:50",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:34:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:29:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:24:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:19:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:14:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:09:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 11:04:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:59:49",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:54:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:49:48",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:44:48",
			"type": 2
		}, {
			"data": "1213 user manual timing {\"datetime\":\"2022-03-01 10:41:33\",\"type\":\"login\"}.",
			"level": 5,
			"time": "2022-03-01 10:41:33",
			"type": 16
		}, {
			"data": "165,62,the time is changed: 2022-3-1 10:41:33.\n",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 2
		}, {
			"data": "1213 usr set time.",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 16
		}, {
			"data": "1228 login set time.",
			"level": 5,
			"time": "2022-03-01 10:43:07",
			"type": 16
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:41:22",
			"type": 2
		}, {
			"data": "1218 link is up.",
			"level": 5,
			"time": "2022-03-01 10:40:17",
			"type": 4
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:36:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:31:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:26:22",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:21:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:16:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:11:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:06:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 10:01:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:56:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:51:21",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:46:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:41:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:36:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:31:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:26:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:21:20",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:16:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:11:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:06:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 09:01:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:56:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:51:18",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:46:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:41:19",
			"type": 2
		}, {
			"data": "167,11,ForceTransaction Ivs Db.",
			"level": 5,
			"time": "2022-03-01 08:36:19",
			"type": 2
		}],
		"qnode": {
			"is_first": true,
			"last_id": 17184,
			"max_id": 17284,
			"min_id": 17081,
			"qtype": 1,
			"start_id": 4294967295
		},
		"rec_size": 100
	},
	"err_msg": "ok",
	"module": "BUS_WEB_REQUEST",
	"state": 200,
	"type": "log_search"
}


### 配置管理
#### 请求
http://192.168.13.202/request.php
{"type":"get_module_app_cfg","module":"MODULE_CONFIG_INFO"}	
{
	"body": {
		"app": [{
			"alias": "5YWs5YWx5o6o6YCB5qih5Z2X",
			"enable": 1,
			"name": "xtp_push_app",
			"rss": 5
		}, {
			"alias": "b252aWbmqKHlnZc=",
			"enable": 1,
			"name": "onvif_server_app",
			"rss": 5
		}, {
			"alias": "6Ie75LqR5qih5Z2X",
			"enable": 1,
			"name": "stp_server_app",
			"rss": 5
		}, {
			"alias": "bGluayB2aXN1YWzmqKHlnZc=",
			"enable": 1,
			"name": "link_visual_app",
			"rss": 6
		}, {
			"alias": "b25lbmV0eOWNj+iuruaooeWdlw==",
			"enable": 1,
			"name": "onenet_server_app",
			"rss": 4
		}, {
			"alias": "T0VN5a6a5Yi25Y2P6K6u5qih5Z2X",
			"enable": 1,
			"name": "oem_multicast_app",
			"rss": 0
		}, {
			"alias": "6IGU5Yqo566h55CG5qih5Z2X",
			"enable": 1,
			"name": "interact_device_app",
			"rss": 4
		}]
	},
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "get_module_app_cfg"
}

#### 操作
参数导出
http://192.168.13.202/configbackup.php
{"type":"config_backup","body":{"general":1,"system":1,"security":1}}	
通用 系统 安全
{
	"body": {
		"data": "ZG93bmxvYWQucGhwL1Z6Q29uZmlnL2NvbmZpZ2JhY2t1cDAwLmNmZw=="
	},
	"err_msg": "All done",
	"state": 200,
	"type": "config_backup"
}

http://192.168.13.202/download.php/VzConfig/configbackup00.cfg

参数导入（会导致重启）
http://192.168.13.202/configrestore.cgi

http://192.168.13.202/vb.htm?ipcamrestartcmd=&_=1646113962239

模块管理
http://192.168.13.202/request.php
{"type":"set_module_app_cfg","module":"MODULE_CONFIG_INFO","body":{"app":[{"name":"xtp_push_app","enable":1},{"name":"onvif_server_app","enable":1},{"name":"stp_server_app","enable":1},{"name":"link_visual_app","enable":1},{"name":"onenet_server_app","enable":1},{"name":"oem_multicast_app","enable":1},{"name":"interact_device_app","enable":0}]}}	
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "set_module_app_cfg"
}

模块管理 - 恢复默认
http://192.168.13.202/request.php
{"type":"reset_module_app_cfg","module":"MODULE_CONFIG_INFO"}	
{
	"err_msg": "OK",
	"state": 200,
	"state_code": 200,
	"type": "reset_module_app_cfg"
}

### LOGO
#### 请求

#### 操作
删除logo
http://192.168.13.202/vb.htm?paratest=removelogofile&_=1646113962236
OK removelogofile=0

上传Logo
http://192.168.13.202/cgi-bin/upload.cgi


### 系统维护
#### 请求
http://192.168.13.202/systemjson.php
{"type":"get_device_info"}	
{
	"body": {
		"alg_ver": "3.1.2021120815",
		"batch_number": "504949505056494948",
		"board_version": 12378,
		"dev_type": 13,
		"drv_ver": "C3R3_3.0.111301722",
		"exdataSize": 2852128853,
		"exdata_checker": 46,
		"ext_info": {
			"monitor_numbers": 0,
			"product_code": "VTC820A",
			"product_name": "5pm66IO96L2m54mM6K+G5Yir55u45py6",
			"product_type": "R3-V1.0"
		},
		"hw_flag": 13,
		"hw_version": "09.00.00.0d",
		"isp_ver": "ISP_3510.0.20211105",
		"mac_addr": "48:a2:b8:10:71:b2",
		"oem_info": "00.00.03.78.78.78.78",
		"oem_serial_num": "1234-5689",
		"profocus_flag": 2,
		"serial_num": "c806ca86-8de9c3f4",
		"soft_ver": "12.1.1.202112230",
		"system_ver": "x029.u029.k015.r083",
		"title": "SVZT",
		"write_status": 654647313
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_device_info"
}

http://192.168.13.202/vb.htm?getdate=&gettime=&_=1646113962069
OK getdate=2022-03-01 Tue
OK gettime=14:36:06

http://192.168.13.202/systemjson.php
{"type":"get_reboot_timing"}	
{
	"body": {
		"enable": 0,
		"minute": 0,
		"wday": ""
	},
	"err_msg": "All done",
	"state": 200,
	"type": "get_reboot_timing"
}

#### 操作
重启设备 - 立即重启


重启设备 - 自动重启
http://192.168.13.202/systemjson.php
{"type":"set_reboot_timing","body":{"enable":1,"wday":"1,3","minute":0}}	
{
	"err_msg": "All done",
	"state": 200,
	"type": "set_reboot_timing"
}

恢复出厂 - 完全恢复

恢复出厂 - 部分恢复

升级设备

