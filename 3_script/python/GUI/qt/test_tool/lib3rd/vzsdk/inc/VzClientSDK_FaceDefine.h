#ifndef _VZ_CLIENT_SDK_FACE_DEFINE_H_
#define _VZ_CLIENT_SDK_FACE_DEFINE_H_
#include <VzClientSDK_CommonDefine.h>

// 一张图片最大人脸个数
#define MAX_FACE_COUNT 108

/**矩形区域信息*/
typedef struct tagTH_FaceRect
{
	unsigned short left;	// 左
	unsigned short top;		// 上
	unsigned short right;	// 右
	unsigned short bottom;	// 下
}TH_FaceRect;

typedef struct tagTH_FaceImg
{
	char imt_type[12];		// 图像类型 如：bmp,jpg,jpeg
	unsigned char* img_buf; // 图像buf
	unsigned int img_len;	// 图像长度
}TH_FaceImg;

typedef struct tagTH_FaceItem
{
	unsigned int face_id;		// 人脸ID
	short confidence;			// 置信度
	short eye_dist;				// 瞳距
	short yaw;					// 水平转角，真实度量的左负右正[-180.0, 180.0]
	short pitch;				// 俯仰角，真实度量的上负下正[-180.0, 180.0]
	char roll;					// 旋转角，真实度量的左负右正[-180.0, 180.0]
	unsigned char data_type;	//  1 人脸 2 背脸 4人形
	TH_FaceRect face_rect; 		// 人脸区域
}TH_FaceItem;

// 人脸抓拍结果信息
typedef struct tagTH_FaceResult 
{
	unsigned char trigger;  					// 触发类型，1：自动抓拍，2：手动抓拍
	char datetime[20];							// 时间，格式：yyyy-MM-dd HH:mm:ss
	unsigned int msec;							// 时间戳，毫秒
	unsigned char num;							// 人脸个数
	TH_FaceItem face_items[MAX_FACE_COUNT];     // 人脸信息
	TH_FaceImg face_imgs[MAX_FACE_COUNT];		// 人脸区域图像
	TH_FaceImg snap_img;						// 全图图像
	char serialno[32];							// 设备序列号
	unsigned char person_num;					// 人脸个数
	unsigned char sex;							// 0:男，1:女，2:未知
	unsigned char age;							// 1:少年 2:青年 3:中年 4:老年，5:未知
	unsigned char have_hat;                     // 0:没，1:有，2:未知
	unsigned char have_glasses;                 // 0:没，1:有，2:未知
	unsigned char have_mask;                    // 0:没，1:有，2:未知
	char reserved[122];							// 保留数据
}TH_FaceResult;

// 人脸抓拍规则区域
#define MAX_POLYGON_PT_COUNT 10
#define MAX_RULE_POLYGON_COUNT 1
typedef struct tagTH_FacePoint
{
	unsigned short x;
	unsigned short y;
}TH_FacePoint;

typedef struct tagTH_FacePolygon
{
	unsigned char id;
	unsigned char enable;
	unsigned char point_num;
	TH_FacePoint  polygon_points[MAX_POLYGON_PT_COUNT];
}TH_FacePolygon;

typedef struct tagTH_FaceRuleArea
{
	unsigned char polygon_num; // 识别区域个数
	TH_FacePolygon area_polygons[MAX_RULE_POLYGON_COUNT];
}TH_FaceRuleArea;

// 人脸屏蔽规则区域
#define MAX_SHIELD_POLYGON_COUNT 4
typedef struct tagTH_FaceShieldArea
{
	unsigned char polygon_num; // 屏蔽区域个数
	TH_FacePolygon area_polygons[MAX_SHIELD_POLYGON_COUNT];
}TH_FaceShieldArea;


// 人脸SD卡信息
typedef struct tagTH_FaceSDInfo
{
	int sector_size;		// 设备扇区大小
	int state;				// 设备状态（5.正常 8.异常）
	long long used;			// 单位字节，设备使用大小
	long long total_size;	// 单位字节，设备总大小（虚拟）
}TH_FaceSDInfo;

// 视频参数
typedef struct tagTH_FaceVideoParam
{
	short brightness;		// 亮度，默认值50
	short contrast;			// 对比度，默认值50
	short saturation;		// 饱和度，默认值50
	short sharpness;		// 锐度，默认值50
	short max_gain;			// 最大增益，默认值50
	short max_exposure;		// 曝光时间
	short flip;				// 图像翻转，0：原始图像，1：上下翻转，2：左右翻转，3：中心翻转，默认值0
}TH_FaceVideoParam;

#define MAX_FACE_TIME_LEN 16

typedef struct tagTH_FaceDaynightParam
{
	short daynight_type;			// 日夜转换，0：夜间，1：定时切换，2：白天，3：自动，4：报警输入触发
	short distance_level;			// 距离等级，默认值50
	short sensitivity;				// 自动转换的灵敏度，默认值3
	short filter_time;				// 自动转换的过滤时间，默认值60
	char begin_time[MAX_FACE_TIME_LEN];	// 定时切换的开始时间，格式：HH:mm:ss，默认值07:00:00
	char end_time[MAX_FACE_TIME_LEN];	// 定时切换的结束时间，格式：HH:mm:ss，默认值18:00:00
	short alarm_status;				// 报警触发状态，0：白天，1：夜晚，默认值1
}TH_FaceDaynightParam;

typedef struct tagTH_FaceVideoDaynightParam
{
	TH_FaceVideoParam video_param;			// 视频参数
	TH_FaceDaynightParam daynight_param;	// 日夜转换参数
}TH_FaceVideoDaynightParam;

// 人员区域流动统计规则
#define MAX_FLOW_POINT_COUNT 8
typedef struct tagTH_FaceFlowStatistic
{
	unsigned char is_open;     // 是否开启人员区域统计
	unsigned char is_area1;    // 是否开启向区域1流动人员统计
	unsigned char is_area2;    // 是否开启向区域2流动人员统计
	unsigned char point_count; // 点的个数
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];

}TH_FaceFlowStatistic;

typedef struct tagTH_FaceCvbsParam
{
	int cvbs;             // 1：开 0:关
	int cvbs_signal_sys;  // 开启模式 0：PAL, 1:NTSC
}TH_FaceCvbsParam;

// 区域计数结果
typedef struct 
{
	char datetime[20];						// 时间，格式：yyyy-MM-dd HH:mm:ss
	unsigned int people_num;				// 当前用户配置区域统计出的人员数量
	TH_FaceImg snap_img;					// 全图图像
	char reserved[128];						// 保留数据
}TH_AreaCountResult;

typedef struct tagTH_FaceGuideData
{
	short definition;			// 人脸清晰度
	short confidence;			// 置信度（人脸角度）
	int face_count;				// 人脸个数
	TH_FaceRect face_rect; 		// 人脸区域

}TH_FaceGuideData;

#endif