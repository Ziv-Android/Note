//一些公有的符号定义
#ifndef _VZ_CLIENT_SDK_COMMON_DEFINE_H_
#define _VZ_CLIENT_SDK_COMMON_DEFINE_H_

/* common constants */
#ifndef  SUCCESS
	#define SUCCESS         0
#endif

#ifndef FAILURE
	#define FAILURE        -1
#endif

#define VZ_API_SUCCESS			0
#define VZ_API_FAILED			-1

#ifndef CIF4_WIDTH
#define CIF4_WIDTH	704
#define CIF4_HEIGHT   576
#define CIF_WIDTH	352
#define CIF_HEIGHT  288
#endif

#ifndef DWORD
#ifdef _WIN32
typedef unsigned long       DWORD;
#else
typedef unsigned int       DWORD;
#include <stdbool.h>
#endif
typedef int                 BOOL;
typedef unsigned short      WORD;
typedef unsigned char       BYTE;
typedef unsigned char uchar;
typedef unsigned short uint16;
typedef unsigned int uint32;
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

/************************************************************************

ERROR define

************************************************************************/
#define  E_SUCCESS   0		//Success
#define  E_INVAL     1		//Invalid parameters
#define  E_NOENT     2		//No such file or directory
#define  E_IO        3		//I/O Error
#define  E_NOMEM     4		//Out of memory
#define  E_NETERR    5      //Network error
#define  E_NEEDINIT  6      //Need call some initial function first
#define  E_OUTOFMAX  7      //Beyond the maxinum
#define  E_NOTLOGIN  8      //Not login  
#define  E_SREJECT   9      //Server reject the request
#define  E_MULTICASTNOTSUPPORT  10 //Multicast not support
#define  E_TALKNOTSUPPORT       11 //Talk not support
#define  E_AUDIOERR  12     //Audio can not operatioin
#define  E_BUFSMALL  13     //Buffer too small
#define  E_UNDEFINED   14

//实时流数据类型
typedef enum
{
	vHeadData = 1,	//视频编码头数据
	vStreamData,	//
	aStreamData		//	
}RealDataType;

//解码数据的作用模式
typedef enum VZC_DEC_DATA_MODE
{
	VZC_DEC_DATA_INSTANCE,	//实际解码数据，并将绘制到内部绘图（默认）。用户不能修改图像，否则影响图像质量
	VZC_DEC_DATA_REFERENCE,	//拷贝解码数据，如果用户修改了图像，将显示到内部绘图。
	VZC_DEC_DATA_COPY,		//拷贝解码数据，如果用户修改了图像，但不显示到内部绘图。
}
VZC_DEC_DATA_MODE;

/**YUV420P的帧结构体*/
typedef struct VzYUV420P
{
	unsigned char *pY;
	unsigned char *pU;
	unsigned char *pV;
	int widthStepY;
	int widthStepU;
	int widthStepV;
	int width;
	int height;
}
VzYUV420P;

/**带时间、序列号信息的视频帧*/
typedef struct VzFrameBuffer
{
	VzYUV420P yuv;
	unsigned int uTimeStamp;	//当前帧的时间参数
	unsigned int uSerialNum;    //当前帧的编号
}
VzFrameBuffer;

/**分解时间*/
typedef struct
{
    unsigned char   bdt_sec;    /**<秒，取值范围[0,59]*/
    unsigned char   bdt_min;    /**<分，取值范围[0,59]*/
    unsigned char   bdt_hour;   /**<时，取值范围[0,23]*/
    unsigned char   bdt_mday;   /**<一个月中的日期，取值范围[1,31]*/
    unsigned char   bdt_mon;    /**<月份，取值范围[1,12]*/
    unsigned char   res1[3];    /**<预留*/
    unsigned        bdt_year;   /**<年份*/
    unsigned char   res2[4];    /**<预留*/
}
VzBDTime;   //broken-down time

/**图像信息*/
typedef struct
{
	unsigned		uWidth;			/**<宽度*/
	unsigned		uHeight;		/**<高度*/
	unsigned		uPitch;			/**<图像宽度的一行像素所占内存字节数*/
	unsigned		uPixFmt;		/**<图像像素格式，参考枚举定义图像格式（ImageFormatXXX）*/
	unsigned char	*pBuffer;	/**<图像内存的首地址*/
}
VzImageInfo;

typedef enum DeviceHwType {	
	HW_TYPE_AT2201A=0,     
	HW_TYPE_VZ101,
	HW_TYPE_X6446,
	HW_TYPE_VZ2,
	HW_TYPE_AT2201_INIVS,
	HW_TYPE_AT2202,
	HW_TYPE_VZ_201D,
	HW_TYPE_AT2201D,
	HW_TYPE_ZVAN_IIA_01,
	HW_TYPE_TXCLZD_1,
	HW_TYPE_TXCLZD_3,
	HW_TYPE_X47B,           
	HW_TYPE_VAN_IIA_01D,    
	HW_TYPE_VZ_E2A,         
	HW_TYPE_VZ206_OD,       
	HW_TYPE_VZ_2032220SV,   
	HW_TYPE_VZ_2032221SV,   
	HW_TYPE_AFSXJ_NC_B_CDVZ, 
	HW_TYPE_IVZ_206_UW,
	HW_TYPE_AT2201G,
	HW_TYPE_VZ_FACE,
    HW_TYPE_VZ_FIC,
	HW_TYPE_NUM
}DeviceHwType;

#define FACE_HW_FLAG 20

typedef enum{
	VZC_WATCHDOG_LOG
}
VZC_LogType;

/**图像信息*/
typedef struct {
	char dev_ip[16];		// 设备的IP地址
	int  dev_port;			// 设备的端口号
	char username[32];      // 访问设备所需用户名
	char password[32];      // 访问设备所需密码
	int  timeout;           // 超时时间(单位毫秒，如超时时间为5秒时，填5000)
	int protocol_type;      // 网络协议(0:http, 1:https)
	int network_type;       // 网络类型(0:局域网,1:外网-PDNS方式, 2:外网-BIND方式)
	//外网参数
	int http_port;          // 外网端口
	char sn[20];            // 设备序列号
	int tcp_port;			// tcp端口
	BYTE dwRes[60];         // 保留
}VZ_LPRC_LOGIN_PARAM;

//回调函数、消息等定义信息
#define VZC_MSG_STAT 					0x0100
#define VZC_MSG_ONLINE 					(VZC_MSG_STAT+0x01)
#define VZC_MSG_NOTONLINE 		        (VZC_MSG_STAT+0x02)
#define VZC_MSG_VALID 					(VZC_MSG_STAT+0x03)
#define VZC_MSG_NOTVALID 		        (VZC_MSG_STAT+0x04)
#define VZC_MSG_ACTIVE 					(VZC_MSG_STAT+0x05)
#define VZC_MSG_DEACTIVE 		        (VZC_MSG_STAT+0x06)
#define VZC_MSG_TALK_ERROR 		        (VZC_MSG_STAT+0x07)
#define VZC_MSG_STREAM_ERROR			(VZC_MSG_STAT+0x08)

#define VZC_MSG_ALARM 		        0x0200
#define VZC_MSG_ALARM_VIDEO_LOST 		(VZC_MSG_ALARM+0x01)
#define VZC_MSG_ALARM_IO 		        (VZC_MSG_ALARM+0x02)
#define VZC_MSG_ALARM_MD 		        (VZC_MSG_ALARM+0x03)
#define VZC_MSG_ALARM_IV_TRACK 	        (VZC_MSG_ALARM+0x04)
#define VZC_MSG_ALARM_IV_CROSS 	        (VZC_MSG_ALARM+0x05)

#define VZC_MSG_TALK 		        0x0300
#define VZC_MSG_TALK_SNEDFILE_END 		(VZC_MSG_TALK+0x01)


//常用参数定义
#define VZDEV_SERIALNO_LEN 					7
#define VZDEV_MAX_MDNUM						8

#define VZDEV_DATATYPE_AV					0x01    //音视频同步数据
#define VZDEV_DATATYPE_USVIDEO		        0x02    //自定义视频数据
#define VZDEV_DATATYPE_SOUND		        0x04    //语音对讲数据

#define VZDEV_STREAM_TYPE_AV		        0	/* 复合流*/
#define VZDEV_STREAM_TYPE_VIDEO				1	/* 视频流*/

#define VZDEV_FRAMESIZE_CIF4				0	/* CIF4 704*576*/
#define VZDEV_FRAMESIZE_CIF					1	/* CIF 352*288*/
#define VZDEV_FRAMESIZE_720P				2	/* 1280 * 720*/
#define VZDEV_FRAMESIZE_1080P				3	/* 1920 * 1080*/

#define VZDEV_VIDEO_COMPRESS_FIX_RATE		0	/* 固定码流 */
#define VZDEV_VIDEO_COMPRESS_VAR_RATE		1	/* 可变码流 */

#define VZDEV_TALK_STAT_OPENED		        0x01	//语音对讲打开
#define VZDEV_TALK_WAVEIN_INSIDE			0x01	//采用内部语音设备
#define VZDEV_TALK_WAVEIN_OUTSIDE			0x02	//采用外部语音数据


#define MAX_STORAGE_DEVICE_NUM	4
#define MAX_STORAGE_DEVICE_PARTED_NUM   4

#define    PUSH_ADDR_BUFFER_MAX_SIZE 200

//触发输入的类型
typedef enum
{
	WhiteList = 0,	//通过
	NotWhiteList,	//不通过
	NoLicence,		//无车牌
	BlackList,		//黑名单
	ExtIoctl1,		//开关量/电平输入 1
	ExtIoctl2,		//开关量/电平输入 2
	ExtIoctl3,		//开关量/电平输入 3
	SpecialPlates,	//特殊车牌
	ExtIoctl4,		//开关量/电平输入 4
	InputTypeLen 
}DeviceInputType;

//输出配置
typedef struct
{
	int switchout1;					//开关量输出 1
	int switchout2;					//开关量输出 2
	int switchout3;					//开关量输出 3
	int switchout4;					//开关量输出 4
	int levelout1;					//电平输出 1 
	int levelout2;					//电平输出 2
	int rs485out1;					//RS485-1
	int rs485out2;					//RS485-2
	DeviceInputType oInputType;		//触发输入的类型
}VZDEV_OutputConfig;

#define MAX_OutputConfig_Len 9

//输出配置信息
typedef struct
{
	VZDEV_OutputConfig oConfigInfo[MAX_OutputConfig_Len];	//多个输出配置输出的消息
}VZDEV_OutputConfigInfo;

//白名单验证模式
typedef enum
{
	AutoEnable = 0, //脱机自动启用
	Enable,		 //启用
	Disable		 //不启用
}DeviceWLCheckMethod;

//白名单模糊匹配
typedef enum
{
	Accurate  = 0,		 //精确匹配
	Similar,			 //相似字符匹配
	Normal				 //普通字符模糊匹配
}DeviceWLFuzzy;

//RS-485推送配置类型
typedef enum
{
	RS485_NOTYPE = 0,			
	RS485_LICENSEENABLE,	//有无车牌
	RS485_LICENSECOLOR,		//车牌颜色
	RS485_LICENSE,			//车牌号
	RS485_LICENSETYPE,		//车牌类型
	RS485_CONFIDENCE,		//可信度
	RS485_DIRECTION,		//运动方向
	RS485_RECT,				//车牌区域
	RS485_TRIGGER,			//触发类型
	RS485_CARCOLOR,			//车辆颜色
	RS485_TIME,				//识别时间
	RS485_DUETIME,			//白名单过期时间 值类型：RS485_TIME_FORMAT
	RS485_WLRESULT,			//白名单验证结果 值类型：RS485_TIME_FORMAT
	RS485_OUT,				//输出IO
	RS485_SN,				//序列号
	RS485_CIPHERTEXT,		//密文
	RS485_ID,				//识别记录ID
	RS485_CHECKBEGIN,		//校验起始位
	RS485_CHECKEND,			//校验结束位
	RS485_CHECKSUM,			//校验位
	RS485_ENCODE,			//车牌编码
	RS485_EDIAN,			//大小端

	RS485_TYPELEN			//推送项长度
}RS485_PUSH_TYPE;

//RS-485推送配置项
typedef struct 
{
	int item_type;				//推送字段类型
	int  val;					//值
}VZDEV_RS485_ITEM;

//校验位
typedef enum
{
	CHECK_NO = 0,	//无校验
	CHECK_SUM,		//和校验
	CHECK_XOR		//异或校验
}RS485_ITEM_CHECKSUM;

//大小端
typedef enum
{
	EDIAN_LITTLE = 0,	//小端
	EDIAN_BIG			//大端
}RS485_ITEM_EDIAN;

//时间类型
typedef enum 
{
	TIME_FOUR_STAMP = 0,//4字节 时间戳
	TIME_SEVEN_YYMDHMS,	//7字节 YYYYTTMMDDHHmmss
	TIME_SIX_YMDHMS,	//6字节 YYMMDDHHmmss
	TIME_SEVEN_HMSDMYY,	//7字节	HHmmssDDMMYYYY
	TIME_SIX_HMSDMY,	//6字节 HHmmssDDMMYY
	TIME_FOUR_YYMD,		//4字节 YYYYMMDD
	TIME_THREE_YMD		//3字节	YYMMDD
}RS485_TIME_FORMAT;

//语音信息状态
typedef enum
{
	VOICE_NOTYPE = 0,
	VOICE_IN,	//有效期内白名单
	VOICE_OUT,		//已过期
	VOICE_NA,		//不在白名单
	VOICE_IW,		//白名单属于天数

	VOICE_STATUELEN	//状态数
}VZDEV_RS485_VOICE_STATUE;

//语音信息-白名单
typedef struct
{
	int status;			//语音信息状态VZDEV_RS485_VOICE_STATUE
	int remain;			//剩余天数
	bool license;		//包含语音信息
	char prefix[36];	//语音前缀
	char suffix[36];	//语音后缀		
}VZDEV_RS485_VOICE_WL;

#define VZDEV_RS485_VOICE_LEN 4
//语音信息
typedef struct
{
	VZDEV_RS485_VOICE_WL voiceWL[VZDEV_RS485_VOICE_LEN];
}VZDEV_RS485_VOICE;

#define RE485_PUSH_TYPE_LEN 22
//RS-485推送配置
typedef struct
{
	VZDEV_RS485_ITEM configItem[RE485_PUSH_TYPE_LEN];	//推送项
	VZDEV_RS485_VOICE voice;
	char header[64];	//协议头
	char end[64];		//协议尾	
	bool voiceEnable;	//语音信息可用	
}VZDEV_RS485_Config;


//智能视频相关参数
//---------------------------------------------------------------------------
///-------------------vz alarm------------------------
#ifndef _VZ_CLIENT_SDK_IVS_DEFINE_H_
#define _VZ_CLIENT_SDK_IVS_DEFINE_H_

#define VZ_IVS_MAX_RELATIVE_SHORT 0x4000

//绝对坐标和相对的互转
typedef short VZ_FIXPOINT_SHORT;
//FIXPOINT_SHORT类型为 相对坐标的定点数表示，对于需要输入相对坐标的结构体，可以通过下面的IVS_I2S宏进行转换
/*例如：
窗口分辨率为640*480，坐标点（320，240）
用宏IVS_I2S，我们可以直接得到
VZ_FIXPOINT_SHORT x = IVS_I2S(320，640);
VZ_FIXPOINT_SHORT y = IVS_I2S(240，480);
*/
#define IVS_I2S(int_val,total) ((short)(((int)(int_val)<<14)/((int)(total))))
#define IVS_S2I(short_val,total) (((int)(short_val)*(total)+(1<<13))>>14)

//
typedef struct _VZ_IVS_POINT{
	VZ_FIXPOINT_SHORT  X;//相对坐标范围[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_FIXPOINT_SHORT  Y;
}VZ_IVS_POINT;//点坐标参数

typedef struct _VZ_IVS_LINE{
	VZ_IVS_POINT   struStart;
	VZ_IVS_POINT   struEnd;
}VZ_IVS_LINE;//线结构参数

#define IVS_MAX_BROKEN_LINE_POINT_NUM 10
typedef struct _VZ_IVS_BROKEN_LINE{
	DWORD           dwPointNum;
	VZ_IVS_POINT   struPos[IVS_MAX_BROKEN_LINE_POINT_NUM];
}VZ_IVS_BROKEN_LINE;//线结构参数

typedef struct _VZ_IVS_RECT{
	VZ_FIXPOINT_SHORT   X;//相对坐标范围[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_FIXPOINT_SHORT   Y;
	VZ_FIXPOINT_SHORT   Width;
	VZ_FIXPOINT_SHORT   Height;
}VZ_IVS_RECT;//区域

#define VZ_IVS_LPR_OBJSIZE_MIN 45
#define VZ_IVS_LPR_OBJSIZE_MAX 400

typedef struct _VZ_IVS_OBJSIZE_RANGE{
	WORD   Min;
	WORD   Max;
}VZ_IVS_OBJSIZE_RANGE;//区域

//sizeof POLYGON	2*sizeof(float)*IVS_MAX_POLYGON_POINT_NUM+4 = 84
#define IVS_MAX_POLYGON_POINT_NUM 15
typedef struct _VZ_IVS_POLYGON{
	DWORD           dwPointNum;
	VZ_IVS_POINT   struPos[IVS_MAX_POLYGON_POINT_NUM];
}VZ_IVS_POLYGON;//多边形

typedef enum _IVS_CROSS_DIRECTION{
	IVS_BOTH_DIRECTION  = 0,
	IVS_LEFT_GO_RIGHT   = 1,
	IVS_RIGHT_GO_LEFT   = 2
}IVS_CROSS_DIRECTION;//穿越方向

typedef struct _VZ_IVS_TRAVERSE_PLANE{
	VZ_IVS_BROKEN_LINE	  struPlaneBottom;
	IVS_CROSS_DIRECTION   dwCrossDirection;
	BYTE                  byRes1;
	BYTE                  byPlaneHeight;
	BYTE                  byRes2[38];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_TRAVERSE_PLANE;//穿越警戒面参数


typedef struct _VZ_IVS_TRAVERSE_PLANE_EXT{
	VZ_IVS_BROKEN_LINE	  struPlaneBottom;
	IVS_CROSS_DIRECTION   dwCrossDirection;
	BYTE				  byIsCalibed[IVS_MAX_BROKEN_LINE_POINT_NUM-1];
	VZ_IVS_LINE			  CalibLine[IVS_MAX_BROKEN_LINE_POINT_NUM-1];
}VZ_IVS_TRAVERSE_PLANE_EXT;//穿越警戒面扩展
/////////////////////////////////////////

typedef struct _VZ_IVS_ENTER_OUT{
	BYTE			  byEnable;
	BYTE			  byEnter;	// 0离开 1进入 2（进入、离开）同时检测
	BYTE              byRes[2];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_ENTER_OUT;//进入/离开区域参数

typedef struct _VZ_IVS_INTRUSION{
	BYTE			  byEnable;
	BYTE              byRes[1];
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_INTRUSION;//入侵参数

typedef struct _VZ_IVS_LOITER{
	BYTE			    byEnable;
	BYTE				byRes[1];
	WORD				wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_LOITER;//徘徊参数

typedef struct _VZ_IVS_TAKE_LEFT{
	BYTE			  byEnable;
	BYTE			  byTake; // 0丢包 1捡包 2（捡包、丢包）同时检测
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_TAKE_LEFT;//丢包/捡包参数

typedef struct _VZ_IVS_PARKING{
	BYTE			  byEnable;
	BYTE              byRes[1];
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_PARKING;//停车参数

typedef struct _VZ_IVS_RUN{
	BYTE			  byEnable;
	BYTE              byRes[1];
	VZ_FIXPOINT_SHORT              RunDistance;//相对坐标范围[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_RUN;//奔跑参数

typedef struct _VZ_IVS_HIGH_DENSITY{
	BYTE			  byEnable;
	BYTE              byRes[3];
	float             fDensity;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_HIGH_DENSITY;	// 人员聚集参数

typedef struct _VZ_IVS_OIL_INTRUSION{
	BYTE			  byEnable;
	BYTE              byRes[7];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_OIL_INTRUSION; // 油井入侵参数

//车牌识别参数
typedef struct _VZ_IVS_LPR{
	BYTE					byEnable;
	BYTE					byTrigTimeout;	//触发超时时间（时间段内相同车牌不会重复触发）[1-255]秒
	BYTE					byCrossDirection;	//触发方向
	BYTE					byRes[5];
	VZ_IVS_OBJSIZE_RANGE	struObjSize;
}VZ_IVS_LPR;

typedef struct _VZ_IVS_PSD{
	uint32		nParkId;			//车位号
	uint32		nIsOrderd;			//是否预订车位
	BYTE		byOrderLicense[12];	//预订车牌号
}VZ_IVS_PSD;


//环境监测类型
typedef enum _HJ_DETECT_TYPE
{
	PIPE_WATER = 1,	//废水排放
	BUBBLE,			//气泡
	EXHAUST_GAS,	//废气
	HJ_DETECT_NUM
}
HJ_DETECT_TYPE;

typedef struct _VZ_IVS_HJ
{
	BYTE			byEnable;
	BYTE			byRes[1];
	HJ_DETECT_TYPE	dwDetectType;
}
VZ_IVS_HJ;	//环境检测参数

// 区域规则
typedef struct _VZ_IVS_AREA{
	VZ_IVS_POLYGON			struRegion;
	BYTE					byRes[8];
	VZ_IVS_ENTER_OUT		struEnterOut;
	VZ_IVS_INTRUSION		struIntrusion;
	VZ_IVS_LOITER			struLoiter;
	VZ_IVS_TAKE_LEFT		struTakeLeft;
	VZ_IVS_PARKING			struParking;
	VZ_IVS_RUN				struRun;
	VZ_IVS_HIGH_DENSITY		struDensity;
	VZ_IVS_OIL_INTRUSION    struOilIntrusion;
}VZ_IVS_AREA;

typedef struct _VZ_IVS_AREA_EXT{
	VZ_IVS_POLYGON			struRegion;
	BYTE					byRes[8];
	VZ_IVS_HJ				struHJ;
	VZ_IVS_LPR				struLPR;
}VZ_IVS_AREA_EXT;

typedef union _VZ_IVS_ALG_PARA{	
	VZ_IVS_PSD				struPSD;
}VZ_IVS_ALG_PARA;

typedef struct _VZ_IVS_AREA_EXT2{
	VZ_IVS_POLYGON			struRegion;
	BYTE					byRes[8];
	VZ_IVS_ALG_PARA			uAlgPara;
}VZ_IVS_AREA_EXT2;

//区域掩膜，用于设置智能分析的感兴趣区域
typedef struct _VZ_IVS_AREA_MASK
{
	VZ_IVS_POLYGON			struRegion;
	BYTE					byRes[6];
	BYTE                    bEnable;
	BYTE                    bInvert;    //反向选中，如果置为1，说明该区域无效，而其他区域有效
}VZ_IVS_AREA_MASK;

typedef union _VZ_IVS_EVENT_UNION{
	DWORD                   uLen[36];
	VZ_IVS_TRAVERSE_PLANE   struTraversePlane;
	VZ_IVS_TRAVERSE_PLANE_EXT struTraversePlaneExt;
	VZ_IVS_AREA             struArea;
	VZ_IVS_AREA_EXT			struAreaExt;
	VZ_IVS_AREA_EXT2		struAreaExt2;
	VZ_IVS_AREA_MASK        struAreaMask;
}VZ_IVS_EVENT_UNION;

typedef enum _IVS_RULE_TYPE{
	IVS_RULE_LINE = 0x1,	// 绊线规则
	IVS_RULE_AREA = 0x2,	// 区域规则
	IVS_RULE_LINE_EX,		//扩展的绊线规则
	IVS_RULE_AREA_EX,		//扩展的区域规则
	IVS_RULE_MASK,          //规则的区域掩膜
}IVS_RULE_TYPE;

#define MAX_EVENT_NUM 32

enum
{
	OFFSET_TRAVERSE_PLANE = 0,	//穿越警戒面
	OFFSET_ENTER_AREA,			//目标进入区域，支持区域规则 
	OFFSET_EXIT_AREA,			//目标离开区域，支持区域规则
	OFFSET_INTRUSION,			//周界入侵，支持区域规则 
	OFFSET_LOITER,				//徘徊，支持区域规则 
	OFFSET_LEFT_TAKE,			//丢包捡包，支持区域规则
	OFFSET_PARKING,				//停车，支持区域规则 
	OFFSET_RUN,					//奔跑，支持区域规则 
	OFFSET_HIGH_DENSITY,		//区域内人员密度，支持区域规则 
	OFFSET_OIL_INTRUSION,		//油井入侵
	OFFSET_FIRE_SMOKE,			//烟火事件
	OFFSET_PEOPLE_COUNT,		//人数统计
	OFFSET_PLATE_R,				//车牌识别
	OFFSET_CAM_HEALTH,			//摄像机健康状况检测
	OFFSET_CAR_COUNT,			//车流统计
	OFFSET_PLATE_R_SERVER,		//车牌识别服务器版
	OFFSET_AUTO_PTZ,			//PTZ自动跟踪事件
	OFFSET_HJ_PIPE_WATER,		//环境废水
	OFFSET_HJ_BUBBLE,			//环境气泡
	OFFSET_HJ_EXHAUST_GAS		//环境废气
};

typedef enum _IVS_EVENT_TYPE{
	IVS_TRAVERSE_PLANE	= 1<<OFFSET_TRAVERSE_PLANE,	//穿越警戒面 
	IVS_ENTER_AREA		= 1<<OFFSET_ENTER_AREA,		//目标进入区域，支持区域规则 
	IVS_EXIT_AREA		= 1<<OFFSET_EXIT_AREA,		//目标离开区域，支持区域规则 
	IVS_INTRUSION		= 1<<OFFSET_INTRUSION,		//周界入侵，支持区域规则 
	IVS_LOITER			= 1<<OFFSET_LOITER,			//徘徊，支持区域规则 
	IVS_LEFT_TAKE		= 1<<OFFSET_LEFT_TAKE,		//丢包捡包，支持区域规则 
	IVS_PARKING			= 1<<OFFSET_PARKING,		//停车，支持区域规则 
	IVS_RUN				= 1<<OFFSET_RUN,			//奔跑，支持区域规则 
	IVS_HIGH_DENSITY	= 1<<OFFSET_HIGH_DENSITY,	//区域内人员密度，支持区域规则 
	IVS_OIL_INTRUSION	= 1<<OFFSET_OIL_INTRUSION,	//油井入侵
	IVS_FIRE_SMOKE		= 1<<OFFSET_FIRE_SMOKE,		//烟火事件
	IVS_PEOPLE_COUNT	= 1<<OFFSET_PEOPLE_COUNT,	//人数统计
	IVS_PLATE_R			= 1<<OFFSET_PLATE_R,		//车牌识别
	IVS_CAM_HEALTH		= 1<<OFFSET_CAM_HEALTH,		//摄像机健康状况检测
	IVS_CAR_COUNT 		= 1<<OFFSET_CAR_COUNT,		//车流统计
	IVS_PLATE_R_SERVER	= 1<<OFFSET_PLATE_R_SERVER,	//车牌识别服务器
	IVS_AUTO_PTZ		= 1<<OFFSET_AUTO_PTZ,		//PTZ自动跟踪事件
	IVS_HJ_PIPE_WATER	= 1<<OFFSET_HJ_PIPE_WATER,	//环境废水
	IVS_HJ_BUBBLE	    = 1<<OFFSET_HJ_BUBBLE,		//环境气泡
	IVS_HJ_EXHAUST_GAS	= 1<<OFFSET_HJ_EXHAUST_GAS	//环境废气
}IVS_EVENT_TYPE;

#define NAME_LEN 32
typedef struct _VZ_IVS_RULE_INFO{
	BYTE                  byRuleID;
	BYTE				  byEnable;
	BYTE				  byDrawbyDSP;
	BYTE                  byRes;
	char                  byRuleName[NAME_LEN];
	IVS_RULE_TYPE         dwRuleType;
	VZ_IVS_EVENT_UNION    uEventParam;
}VZ_IVS_RULE_INFO;//事件规则信息

/////////////////////////////////////////

#define MAX_RULE_NUM	8
typedef struct _VZ_IVS_RULE_CFG{
	DWORD			 dwRuleNum;
	VZ_IVS_RULE_INFO struRules[MAX_RULE_NUM];
}VZ_IVS_RULE_CFG;


#define	VZ_IVS_DAY_MON  0x01
#define	VZ_IVS_DAY_TUE  0x02
#define	VZ_IVS_DAY_WED  0x04
#define	VZ_IVS_DAY_THU  0x08
#define	VZ_IVS_DAY_FRI  0x10
#define	VZ_IVS_DAY_SAT  0x20
#define	VZ_IVS_DAY_SUN  0x40
#define VZ_IVS_DAY_ALLTIME (VZ_IVS_DAY_MON | VZ_IVS_DAY_TUE | VZ_IVS_DAY_WED | VZ_IVS_DAY_THU | VZ_IVS_DAY_FRI | VZ_IVS_DAY_SAT | VZ_IVS_DAY_SUN)
#define VZ_IVS_DAY_NULL	0x80	//表示使用每帧输入的时间戳来评估规则时间有效

typedef struct _VZ_IVS_TIME_PERIOD{
	BYTE byEnable;
	BYTE uStartHour;
	BYTE uStartMinute;
	BYTE uEndHour;
	BYTE uEndMinute;
	BYTE byRes[3];
}VZ_IVS_TIME_PERIOD;

#define MAX_TIME_PERIOD_NUM	4
#define MAX_WEEK_DAY 7
typedef struct _VZ_IVS_RULE_TIME_INFO{
	VZ_IVS_TIME_PERIOD struPeriod[MAX_WEEK_DAY][MAX_TIME_PERIOD_NUM];
}VZ_IVS_RULE_TIME_INFO;

typedef struct _VZ_IVS_RULE_TIME_CFG{
	VZ_IVS_RULE_TIME_INFO struRuleTimes[MAX_RULE_NUM];
}VZ_IVS_RULE_TIME_CFG;

typedef struct _VZ_IVS_RULE_CFG_EX{
	DWORD			 dwRuleNum;
	VZ_IVS_RULE_INFO struRules[MAX_RULE_NUM];
	VZ_IVS_RULE_TIME_INFO struRuleTimes[MAX_RULE_NUM];
}VZ_IVS_RULE_CFG_EX;

typedef struct{
	DWORD          dwID;
	VZ_IVS_RECT   struRect;
	BYTE           byRes[4];
}VZ_IVS_TARGET_INFO;//报警目标信息


#define VZ_MAX_TARGET_NUM	320
//blob类型
#define VZ_BLOB_HUMAN	0
#define VZ_BLOB_CAR		1
#define VZ_BLOB_TRUCK	2
#define VZ_BLOB_ANIMAL	3
#define VZ_BLOB_WATER	4
#define VZ_BLOB_BUBBLE	5
#define VZ_BLOB_GAS		6


typedef struct VZ_IVS_TARGET
{
	int id;		//目标ID
	int kind;	//目标种类
	unsigned short x;	//矩形起点X值
	unsigned short y;	//矩形起点Y值
	unsigned short w;	//矩形宽度
	unsigned short h;	//矩形高度
	unsigned int dwBitsRules;		//按位对应ruleID，违规该为置1
	unsigned int dwBitsEvent;		//由IVS_EVENT_TYPE求或
	//判断该目标是否违规，就用dwBitsEvente而不用rulesFlag
}
VZ_IVS_TARGET;	//单个报警目标 size= 8+8+8 = 24

//报警信息
typedef struct VzTargetsInfo
{
	unsigned int num;
	VZ_IVS_TARGET tags[VZ_MAX_TARGET_NUM];
}
VzTargetsInfo;	//size = 24*32 + 4 = 772

#ifndef MAX_HIS_NUM
#define MAX_HIS_NUM		24
#endif

typedef struct VZ_IVS_TARGET_EXT
{
	VZ_IVS_TARGET ivsTarget;
	int motionKind;							//0为闯入，1为滞留
	int contrailLen;						//轨迹实际长度	//*/
	unsigned short contrailX[MAX_HIS_NUM];	//轨迹X
	unsigned short contrailY[MAX_HIS_NUM];	//轨迹Y
}
VZ_IVS_TARGET_EXT;	//size = 24 + 8 + 4*24*2 = 224

typedef struct VzTargetExtsInfo
{
	unsigned int num;
	VZ_IVS_TARGET_EXT tags[VZ_MAX_TARGET_NUM];
}
VzTargetExtsInfo;	//size = 4 + 224*32 = 

typedef enum VZ_ALARM_TYPE{
	VZ_ALARM_TYPE_NO_INFO,
	VZ_ALARM_TYPE_RULE,		//由报警规则触发的
	VZ_ALARM_TYPE_INPUT,	//由输入报警返回的
	VZ_ALARM_TYPE_PROTOCOL,	//由输入的协议数据触发的
	VZ_ALARM_TYPE_PLATE_RESULT,		//车牌识别结果
	VZ_ALARM_TYPE_MAX
} VZ_ALARM_TYPE;

//智能视频
typedef struct _VZ_IVS_DRAWMODE{
	BYTE byDspAddTarget;		//dsp叠加报警目标
	BYTE byDspAddRule;			//dsp叠加设置规则
	BYTE byDspAddTrajectory;	//dsp叠加轨迹	
	BYTE dwRes[2];
}VZ_IVS_DRAWMODE;

#define IVS_MAX_MODE 4	//设备运行的最大模式数	
typedef struct _IVS_Ability_INFO_{
	int ModeNum;//模式数量
	int AbilityMask[IVS_MAX_MODE];//模式能力
}IVS_Ability_INFO;

typedef struct _VZ_IVS_EVENT_ABILITY{
	IVS_Ability_INFO ability_info;
	BYTE  byMaxRuleNum;		//最大规则数	
	BYTE  byMaxTargetNum;	//最大目标数
}VZ_IVS_EVENT_ABILITY;

//智能设备类型 
typedef enum _IVS_TYPE_{		
	IVS_NO				= 0,	//无智能视频版本
	IVS_OIL_BASE		= 1,	//油田基本版
	IVS_OIL_FULL		= 2,	//油田全功能版
	IVS_BEHAVIOR_BASE   = 3,	//行为分析基本版
	IVS_BEHAVIOR_FULL   = 4,    //行为分析全功能版
	IVS_ITS				= 5,	//智能交通设备
	IVS_FIRE			= 6,    //烟火识别
	IVS_ENHANCE			= 7,    //视频增强器
	IVS_ATM				= 8,	//ATM 智能设备
	IVS_CARCOUNT		= 9,	//车流统计设备
	IVS_CAMHEALTH_SERVER= 10,	//摄像机健康状况检测
	IVS_PLATER_CLIENT   = 11,	//车牌识别客户端
	IVS_PLATER_SERVER   = 12,	//车牌识别服务器
	IVS_PTZ				= 13,	//ptz跟踪器
	IVS_HJ_T212			= 14,	//环境监测智能设备
	IVS_PTZ_TA			= 15,	//PTZ跟踪器（十所（天奥））
	IVS_PCOUNT_SERVER	= 16,	//人数统计器
	IVS_BEHAVIOR_BASE_HELMET = 17,	//安全帽检测
	IVS_PACK_DETECTION	= 18,	//车位检测
	IVS_TYPE_NUM
}IVS_TYPE;


#endif

//--------------------end of vz alarm config-----------------------

//=======================通用智能规则命令======================


//由命令名称（必须）+智能类型（用于区分不同智能能力，如果需要）+编号（用于区分多次发出的相同命令，如果需要）
#define MAKE_IVS_CMD(CMD_NAME, IVS_TYPE, CMD_SN) ((((CMD_SN)&0xFF)<<16)|(((IVS_TYPE)&0xFF)<<8)|((CMD_NAME)&0xFF))

#define GET_IVS_CMD_NAME(CMD) ((CMD)&0xFF)

#define GET_IVS_CMD_IVS_TYPE(CMD) (((CMD)>>8)&0xFF)

#define GET_IVS_CMD_SN(CMD) (((CMD)>>16)&0xFF)

#define MAX_VZIVS_CTRL_CMD_BUF_LEN	1016
typedef struct
{
	unsigned int uCMD;		//IVS通用命令
	unsigned int uLenCMD;	//命令buf的长度
	unsigned char buf[MAX_VZIVS_CTRL_CMD_BUF_LEN];	//IVS通用命令的内容
}
VZ_IVS_CTRL;	//用于控制智能设备的通用命令结构体

//==================VS信息额外====================s
#define MAXNUM_CLIENT_INFO	256
//已连接的客户端信息
typedef struct VzClientInfo
{
	unsigned char ip[4];	//IP地址
}
VzClientInfo;

//信息表
typedef struct VzConnectedClients
{
	VzClientInfo clientInfo[MAXNUM_CLIENT_INFO];
	int count;
}
VzConnectedClients;

typedef struct IVSAlarmBuffer
{
	long tv_sec;
	long tv_usec;
	VzTargetsInfo targetsInfo;
}
IVSAlarmBuffer;		//size = 8+900 = 908

typedef struct IVSAlarmBufferExt
{
	long tv_sec;
	long tv_usec;
	int bTSTimeout;	//时间戳导致的规则无效
	VzTargetExtsInfo targetsInfo;
}
IVSAlarmBufferExt;

typedef struct RuleCountStatisInfo
{
	int ruleID;
	int L2RCount;
	int R2LCount;
}RuleCountStatisInfo;

typedef struct IVSCountStatisInfo
{
	long tv_sec_begin;
	long tv_usec_begin;
	int infoNum;
	RuleCountStatisInfo RuleStatisInfo[MAX_RULE_NUM];
}
IVSCountStatisInfo;


#define MAX_STRLEN_PROTOCOL_DETAIL	32
#define MAX_STRING_LEN 256
//基于协议数据的报警(VZ_ALARM_TYPE_PROTOCOL)返回的结构体
typedef struct _IVSProtocolInput
{
	char strDetail[MAX_STRLEN_PROTOCOL_DETAIL];		//详细的数据结构描述
	int sizeParam;	//数据结构尺寸（可作为校验）
	void *pParam;	//数据结构指针，参考与strDetail对应的头文件中定义的
}
IVSProtocolInput;

typedef struct _IVSProtocolInputEx
{
	char strDetail[MAX_STRLEN_PROTOCOL_DETAIL];		//详细的数据结构描述
	int sizeParam;	//数据结构尺寸（可作为校验）
	void *pParam;	//数据结构指针，参考与strDetail对应的头文件中定义的

	int RS485Chn;
}
IVSProtocolInputEx;



//==============黑白名单用的数据结构及宏定义 start=============

#define VZ_LPR_WLIST_DATETIME_LEN	32
#define VZ_LPR_WLIST_TIME_SEG_LEN	128

#define VZ_LPR_WLIST_LP_MAX_LEN			32
#define VZ_LPR_WLIST_TIME_SEG_MAX_NUM	8

#define VZ_LPR_WLIST_MAX_KEY_LEN 32
#define	VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN 128

#define VZ_LPR_WLIST_VEHICLE_CODE_LEN		32
#define VZ_LPR_WLIST_VEHICLE_COMMENT_LEN	64
#define VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN		32

/**日期时间描述*/
typedef struct
{
	short nYear;	/**<年*/
	short nMonth;	/**<月*/
	short nMDay;	/**<日*/
	short nHour;	/**<时*/
	short nMin;		/**<分*/
	short nSec;		/**<秒*/
}
VZ_TM;

/**一周七天的选择掩膜*/
typedef struct
{
	char bSun;		/**<周日*/
	char bMon;		/**<周一*/
	char bTue;		/**<周二*/
	char bWed;		/**<周三*/
	char bThur;		/**<周四*/
	char bFri;		/**<周五*/
	char bSat;		/**<周六*/
	char reserved;
}
VZ_TM_WEEK_DAY;

/**一天中的时间表达*/
typedef struct
{
	short nHour;
	short nMin;
	short nSec;
	short reserved;
}
VZ_TM_DAY;

/**时间段信息*/
typedef struct
{
	unsigned		uEnable;
	VZ_TM_WEEK_DAY	struDaySelect;		/**<一周内的天数选择*/
	VZ_TM_DAY		struDayTimeStart;	/**每天的时间起点*/
	VZ_TM_DAY		struDayTimeEnd;		/**每天的时间终点*/
}
VZ_TM_WEEK_SEGMENT;

typedef struct
{
	VZ_TM		struTimeStart;		/**每天的时间起点*/
	VZ_TM		struTimeEnd;		/**每天的时间终点*/
}
VZ_TM_RANGE;

typedef struct
{
	unsigned			uEnable;										/**是否开启*/
	VZ_TM_WEEK_SEGMENT  struWeekSeg[VZ_LPR_WLIST_TIME_SEG_MAX_NUM];		/**周期时间段设置*/
}
VZ_TM_PERIOD;

typedef enum
{
	VZ_LPR_WLIST_ERROR_NO_ERROR=0,
	VZ_LPR_WLIST_ERROR_PLATEID_EXISTS,
	VZ_LPR_WLIST_ERROR_INSERT_CUSTOMERINFO_FAILED,
	VZ_LPR_WLIST_ERROR_INSERT_VEHICLEINFO_FAILED,
	VZ_LPR_WLIST_ERROR_UPDATE_CUSTOMERINFO_FAILED,
	VZ_LPR_WLIST_ERROR_UPDATE_VEHICLEINFO_FAILED,
	VZ_LPR_WLIST_ERROR_PLATEID_EMPTY,
	VZ_LPR_WLIST_ERROR_ROW_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_CUSTOMERINFO_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_VEHICLEINFO_NOT_CHANGED,
	VZ_LPR_WLIST_ERROR_CUSTOMER_VEHICLE_NOT_MATCH,
	VZ_LPR_WLIST_ERROR_SERVER_GONE,
}
VZ_LPR_WLIST_ERROR;

#define VZ_LPR_WLIST_INVAILID_ID 0xFFFFFFFF

/**黑白名单中的车辆记录*/
typedef struct
{
	unsigned	uVehicleID;										/**<车辆在数据库的ID*/
	char		strPlateID[VZ_LPR_WLIST_LP_MAX_LEN];			/**<车牌字符串*/
	unsigned	uCustomerID;									/**<客户在数据库的ID，与VZ_LPR_WLIST_CUSTOMER::uCustomerID对应*/
	unsigned	bEnable;										/**<该记录有效标记*/
	unsigned	bEnableTMEnable;								/**<是否开启生效时间*/
	unsigned	bEnableTMOverdule;								/**<是否开启过期时间*/
	VZ_TM		struTMEnable;									/**<该记录生效时间*/
	VZ_TM		struTMOverdule;									/**<该记录过期时间*/
	unsigned	bUsingTimeSeg;									/**<是否使用周期时间段*/
	VZ_TM_PERIOD struTimeSeg;									/**<周期时间段信息*/
	unsigned	bAlarm;											/**<是否触发报警（黑名单记录）*/
	int			iColor;											/**<车辆颜色*/
	int			iPlateType;										/**<车牌类型*/
	char		strCode[VZ_LPR_WLIST_VEHICLE_CODE_LEN];			/**<车辆编码*/
	char		strComment[VZ_LPR_WLIST_VEHICLE_COMMENT_LEN];	/**<车辆编码*/
}
VZ_LPR_WLIST_VEHICLE;

#define VZ_LPR_WLIST_CUSTOMER_NAME_LEN		32
#define VZ_LPR_WLIST_CUSTOMER_CODE_LEN		32

/**黑白名单记录的客户信息*/
typedef struct
{
	unsigned	uCustomerID;			/**<客户在数据库的ID，用于修改、删除操作（主键）*/
	char		strName[VZ_LPR_WLIST_CUSTOMER_NAME_LEN];	/**<客户姓名*/
	char		strCode[VZ_LPR_WLIST_CUSTOMER_CODE_LEN];	/**<客户编码*/

	char		reserved[256];
}
VZ_LPR_WLIST_CUSTOMER;

/**客户和其车辆中的一辆合成的一行数据*/
typedef struct
{
	VZ_LPR_WLIST_CUSTOMER *pCustomer;			/**<客户*/
	VZ_LPR_WLIST_VEHICLE *pVehicle;				/**<车辆，可以为空*/
}
VZ_LPR_WLIST_ROW;

/**查找数据条件*/
typedef struct
{
	char						key[VZ_LPR_WLIST_MAX_KEY_LEN];							/**<查找的字段*/
	char						search_string[VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN];		/**<查找的字符串*/
}
VZ_LPR_WLIST_SEARCH_CONSTRAINT;

typedef enum
{
	VZ_LPR_WLIST_LIMIT_TYPE_ONE,						/**<查找一条*/
	VZ_LPR_WLIST_LIMIT_TYPE_ALL,						/**<查找所有*/
	VZ_LPR_WLIST_LIMIT_TYPE_RANGE						/**<查找一段*/
}
VZ_LPR_WLIST_LIMIT_TYPE;

typedef struct
{
	int startIndex;
	int count;
}
VZ_LPR_WLIST_RANGE_LIMIT;

typedef struct
{
	VZ_LPR_WLIST_LIMIT_TYPE				limitType;					/**<查找条数限制*/
	VZ_LPR_WLIST_RANGE_LIMIT			*pRangeLimit;				/**<查找哪一段数据，当limitType为VZ_LPR_WLIST_LIMIT_TYPE_RANGE时起作用*/
}
VZ_LPR_WLIST_LIMIT;

typedef enum
{
	VZ_LPR_WLIST_SORT_DIRECTION_DESC=0,
	VZ_LPR_WLIST_SORT_DIRECTION_ASC=1,
}
VZ_LPR_WLIST_SORT_DIRECTION;

/**结果的排列方式*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	VZ_LPR_WLIST_SORT_DIRECTION direction;
}
VZ_LPR_WLIST_SORT_TYPE;

/**查找数据方式*/
typedef enum{
	VZ_LPR_WLIST_SEARCH_TYPE_LIKE,				/**<包含字符*/
	VZ_LPR_WLIST_SEARCH_TYPE_EQUAL				/**<完全匹配*/
}
VZ_LPR_WLIST_SEARCH_TYPE;

typedef struct{
	VZ_LPR_WLIST_SEARCH_TYPE			searchType;					/**<查找的方式，如果是完全匹配，每个条件之间为与，是包含时，每个条件之间为或*/
	unsigned int						searchConstraintCount;		/**<查找条件个数，为0表示没有搜索条件*/
	VZ_LPR_WLIST_SEARCH_CONSTRAINT*		pSearchConstraints;			/**<查找条件数组指针*/
}
VZ_LPR_WLIST_SEARCH_WHERE;

typedef struct
{
	VZ_LPR_WLIST_SEARCH_WHERE			*pSearchWhere;				/**<查找条件*/
	VZ_LPR_WLIST_LIMIT					*pLimit;					/**<查找条数限制*/
	VZ_LPR_WLIST_SORT_TYPE				*pSortType;					/**<结果的排序方式，为空表示按默认排序*/
}
VZ_LPR_WLIST_LOAD_CONDITIONS;

/**表的列id和中文名称*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	char	name[VZ_LPR_WLIST_MAX_KEY_LEN];
}
VZ_LPR_WLIST_KEY_DEFINE;

/**以整数代表的实际内容*/
typedef struct
{
	int		iValue;
	char	strValue[VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN];
}
VZ_LPR_WLIST_ENUM_VALUE;

/**批量导入每行的结果*/
typedef struct
{
	int ret;
	int error_code;
}
VZ_LPR_WLIST_IMPORT_RESULT;

typedef enum{
	VZLPRC_WLIST_CB_TYPE_ROW = 0,				/**<复合查询的结果返回*/
	VZLPRC_WLIST_CB_TYPE_CUSTOMER,				/**<客户信息查询的结果返回*/
	VZLPRC_WLIST_CB_TYPE_VEHICLE				/**<车辆信息查询的结果返回*/
}
VZLPRC_WLIST_CB_TYPE;

#ifdef WIN32
#define __STDCALL __stdcall
#else
#define __STDCALL
#endif

/**
*  @brief 白名单表和客户信息表的查询反馈结果函数
*  @param  [IN] type 返回的记录的类型
*  @param  [IN] pLP 查询的车辆信息记录
*  @param  [IN] pCustomer 查询的客户信息记录
*  @param  [IN] pUserData 回调函数中的上下文
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZLPRC_WLIST_QUERY_CALLBACK)(VZLPRC_WLIST_CB_TYPE type, const VZ_LPR_WLIST_VEHICLE *pLP, \
													 const VZ_LPR_WLIST_CUSTOMER *pCustomer,    \
													 void *pUserData);


/**白名单字段名称，查询时使用*/
const  char VZLPRC_WLIST_COL_TIME_ON_CREATE[]	= "timeOnCreate";
const  char VZLPRC_WLIST_COL_TIME_ENABLE[]		= "timeEnable";
const  char VZLPRC_WLIST_COL_TIME_OVERDUE[]		= "timeOverdue";
const  char VZLPRC_WLIST_COL_ENABLE[]			= "enable";
const  char VZLPRC_WLIST_COL_LP[]				= "PlateID";
const  char VZLPRC_WLIST_COL_USING_TIME_SEC[]	= "usingTimeSeg";
const  char VZLPRC_WLIST_COL_TIME_SEG[]			= "timeSeg";
const  char VZLPRC_WLIST_COL_NEED_ALARM[]		= "needAlarm";
const  char VZLPRC_WLIST_COL_CUSTOM_ID[]		= "CustomerID";
const  char VZLPRC_WLIST_COL_CUSTOM_NAME[]		= "Name";
const  char VZLPRC_WLIST_COL_CUSTOM_IDCODE[]	= "Code";
const  char VZLPRC_WLIST_COL_VEHICLE_ID[]		= "keyIndex";
const  char VZLPRC_WLIST_COL_VEHICLE_IDCODE[]		= "VehicleCode";
const  char VZLPRC_WLIST_COL_VEHICLE_COLOR[]		= "Color";
const  char VZLPRC_WLIST_COL_VEHICLE_PLATETYPE[]	= "PlateType";
const  char VZLPRC_WLIST_COL_VEHICLE_COMMENT[]	= "VehicleComment";

//==============黑白名单用的数据结构及宏定义 end=============


//==============人脸的数据结构及宏定义 start=============

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
	unsigned char data_type;	//  1 人脸 2 背脸 4人形 8热成像
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
	char age_real;								// 真实年龄
	unsigned char channel_id;					// 所属视频通道号
	unsigned char capture_mode;                 // 抓拍模式 0: 人脸抓拍 1:口罩报警模式
	float temperature;							// 温度
	char device_ip[16];							// 人脸设备ip
	char reserved[99];							// 保留数据
}TH_FaceResult;

typedef struct tagTH_FaceItemEx
{
	unsigned char face_type;	//  1 人脸 2 背脸 3人形 4热成像
	unsigned int face_id;		// 人脸ID
	unsigned char channel_id;	// 所属视频通道号

	char enable_temperature;
	char gate_result;			// 是否为门禁设备输出的结果
	char reserved1[8];			// 保留数据
	
	
	//属性
	short confidence;			// 置信度    （人脸/背脸/人形/热成像）
	short eye_dist;				// 瞳距      （人脸）
	short yaw;					// 水平转角，真实度量的左负右正[-180.0, 180.0]  （人脸/背脸）
	short pitch;				// 俯仰角，真实度量的上负下正[-180.0, 180.0]    （人脸/背脸）
	char roll;					// 旋转角，真实度量的左负右正[-180.0, 180.0]    （人脸/背脸）
	unsigned char sex;			// 0:男，1:女，2:未知 （人脸）
	unsigned char age;			// 1:少年 2:青年 3:中年 4:老年，5:未知 （人脸）
	unsigned char have_hat;     // 0:没，1:有，2:未知 （人脸）
	unsigned char have_glasses; // 0:没，1:有，2:未知 （人脸）
	unsigned char have_mask;    // 0:没，1:有，2:未知 （人脸）
	char age_real;				// 真实年龄           （人脸）
	float temperature;          // 温度               （热成像）
	
	int recg_face_id;			       // 识别结果所在人脸库中的id
	unsigned short recg_face_lib_id;   // 人脸库id
	unsigned char recg_face_score;     // 识别结果分数[0-100]
	unsigned char recg_sex;
	TH_FaceRect real_rect;		  // 人脸在小图中的坐标
	TH_FaceRect face_rect; 		  // 人脸区域 （人脸/背脸/人形/热成像）
	TH_FaceImg face_imgs;
	char recg_people_name[16];	  // 识别出的人名
	char recg_img_url[48];        // 图片路径
	char recg_birthday[12];       // 生日
	char recg_prov[16];           // 所在省份
	char user_id[20];			  // 用户自定义数据
	char reserved_id[4];	      // id预留	
	int user_type;		
	char reserved[8];	
}TH_FaceItemEx;

// 人脸抓拍结果信息
#define MAX_SNAP_COUNT   5
typedef struct tagTH_FaceResultEx 
{
	unsigned char channel_id;					// 所属视频通道号
	unsigned char trigger;  					// 触发类型，1：自动抓拍，2：手动抓拍，3：sdk抓拍，4：区域报警，
	                                            // 10：不带口罩触发， 11：温度过高触发
	char serialno[32];							// 设备序列号
	char datetime[20];							// 时间，格式：yyyy-MM-dd HH:mm:ss
	unsigned int msec;							// 时间戳，毫秒
	char reserved1[10];							// 保留数据
	unsigned char num;							// 人脸个数
	TH_FaceItemEx face_items[MAX_FACE_COUNT];   // 人脸信息
	TH_FaceImg face_imgs[MAX_FACE_COUNT];		// 人脸信息小图
	unsigned char snap_num;					    // 全图个数
	TH_FaceImg snap_img[MAX_SNAP_COUNT];		// 全图图像
	char device_ip[16];							// 人脸相机的ip
	char reserved2[48];							// 保留数据
}TH_FaceResultEx;

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
	short led_mode;                 // 状态灯模式， 0:智能 1：常亮 2：常灭
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
	unsigned char enable_reset_count;    // 是否开启定时计数清零
	char reset_time[MAX_FACE_TIME_LEN];  // 清零定时
	unsigned char point_count; // 点的个数
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];

}TH_FaceFlowStatistic;

typedef struct tagTH_FaceFlowStatisticEx
{
	unsigned char is_open;     // 是否开启人员区域统计
	unsigned char is_device_draw;     // 是否开启设备端绘制
	unsigned char is_area1;    // 是否开启向区域1流动人员统计
	unsigned char is_area2;    // 是否开启向区域2流动人员统计
	unsigned char enable_reset_count;    // 是否开启定时计数清零
	char reset_time[MAX_FACE_TIME_LEN];  // 清零定时
	unsigned char point_count; // 点的个数
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];
	char reserved[128];						// 保留数据
}TH_FaceFlowStatisticEx;

typedef struct tagTH_FaceCvbsParam
{
	int cvbs;             // 1：开 0:关
	int cvbs_signal_sys;  // 开启模式 0：PAL, 1:NTSC
}TH_FaceCvbsParam;

// 区域计数结果
#define MAX_RULE_POLYGON_COUNT_V2 4
typedef struct 
{
	unsigned char polygon_id;				// id
	unsigned char alarm_flag;               // 报警标识
	int           people_num;               // 人数
	char reserved[20];						// 保留数据
}TH_AreaCountPolygon;

typedef struct 
{
	char datetime[20];						// 时间，格式：yyyy-MM-dd HH:mm:ss
	unsigned int people_num;				// 当前用户配置区域统计出的人员数量
	TH_FaceImg snap_img;					// 全图图像
	int polygon_num;                        // 区域个数
	TH_AreaCountPolygon polygon[MAX_RULE_POLYGON_COUNT_V2];   // 区域参数
	char reserved[20];						// 保留数据
}TH_AreaCountResult;

typedef struct tagTH_FaceGuideData
{
	short definition;			// 人脸清晰度
	short confidence;			// 置信度（人脸角度）
	int face_count;				// 人脸个数
	TH_FaceRect face_rect; 		// 人脸区域

}TH_FaceGuideData;

//==============人脸的数据结构及宏定义 end=============


//==============人脸门禁的数据结构及宏定义 start=============
struct FaceRecoInfo {
	unsigned int sequence;  //抓拍序号，从1开始，每产生一组抓拍数据增加1。
	char camId[32];         //相机编号
	char posId[32];         //点位编号
	char posName[96];       //点位名称

	unsigned int tvSec;        //抓拍时间秒数，从1970年01月01日00时00分00秒至抓拍时间经过的秒数。
	unsigned int tvUsec;       //抓拍时间微秒数，tvSec的尾数


	short isRealtimeData;      //错误码 （主错误码+副错误码）

	short matched;             //比对结果，0：未比对。-1：比对失败。大于0的取值：比对成功时的确信度分数（100分制）。
	char matchPersonId[20];    //人员ID
	char matchPersonName[16];  //人员姓名
	int matchRole;             //人员角色，0：普通人员。 1：白名单人员。 2：黑名单人员

	int existImg;               //全景图，是否包含全景图像。0：不包含全景图像。非0：包含全景图像。
	char imgFormat[4];          //全景图像格式
	int imgLen;                 //全景图像大小
	unsigned short faceXInImg;  //人脸位于全景图像的X坐标。
	unsigned short faceYInImg;  //人脸位于全景图像的y坐标
	unsigned short faceWInImg;  //人脸位于全景图像宽度
	unsigned short faceHInImg;  //人脸位于全景图像高度

	int existFaceImg;               //人脸图，特写图像标志，是否包含特写图像。0：不包含特写图像。非0：包含特写图像。
	char faceImgFormat[4];          //人脸图像封装格式。
	int faceImgLen;                 //特写图像大小
	unsigned short faceXInFaceImg;  //人脸位于特写图像的X坐标。
	unsigned short faceYInFaceImg;  //人脸位于特写图像的y坐标。
	unsigned short faceWInFaceImg;  //人脸位于特写图像的宽度
	unsigned short faceHInFaceImg;  //人脸位于特写图像的高度

	int existVideo;               //是否包含视频。0：不包含视频。非0：包含视频。
	unsigned int videoStartSec;   //视频起始时间（秒）
	unsigned int videoStartUsec;  // videoStartSec尾数，微妙
	unsigned int videoEndSec;     //视频结束时间（秒）
	unsigned int videoEndUsec;    // videoEndSec尾数，微妙
	char videoFormat[4];          //视频封装格式。
	int videoLen;                 //视频大小

	unsigned char sex;         //性别 0: 无此信息 1：男 2：女
	unsigned char age;         //年龄 0: 无此信息 其它值：年龄
	unsigned char expression;  //表情 0: 无此信息 其它值：暂未定义
	unsigned char skinColour;  //肤色 0: 无此信息 其它值：暂未定义
	unsigned char qValue;      //注册标准分数，分数越高越适合用来注册
	char resv[123];            //保留 第一位 是否带帽子  从65到82 预留身份证号

	unsigned char *img;           //全景图像数据
	unsigned char *faceImg;       //特写图像数据
	unsigned char *video;         //视频数据
	int feature_size;             //当前抓拍人脸的特征数据大小
	float *feature;               //当前抓拍人脸的特征数据
	int modelFaceImgLen;          //模板人脸图像长度
	char modelFaceImgFmt[4];      //模板人脸图像类型
	unsigned char *modelFaceImg;  //模板人脸图像数据
};

struct FaceFlags {
	char faceID[20];		//人员ID
	char faceName[16];		//人员姓名
	int role;				//人员角色，0：普通人员。 1：白名单人员。 2：黑名单人员。-1：所有人员。
	
	unsigned int wgCardNO;		   //韦根协议门禁卡号
	unsigned int effectTime;	   //有效期截止时间，该人员信息在该时间内有效,从1970年1月1日0时0分0秒到截止时间的秒数（0xFFFFFFFF表示永久有效，0表示永久失效）
	unsigned int effectStartTime;  //有效期起始时间，该人员信息在该时间之后有效,从1970年1月1日0时0分0秒到起始时间的秒数（0表示未初始化）

	int usr_type;			//权限类型，取值 0 - 5，默认 0
	char resv[8184];		//前100字节预留身份证
};

struct FaceImage {
	int img_seq;         //图片编号
	int img_fmt;         //图片格式 0：jpg 1：bgr
	unsigned char *img;  //要注册的人脸图片数据，支持主流图像格式
	int img_len;         //img的长度
	int width;           //图像宽度，jpg图像不填此项
	int height;          //图像高度，jpg图像不填此项
};

struct ErrorFaceImage {
	int img_seq;   //注册失败的图像编号
	int err_code;  //失败的错误码
};

//人脸查询返回
struct QueryFaceFlags {
	char personID[20];         //人员ID
	char personName[16];       //姓名
	int featureSize;           //人脸特征数据大小
	float feature[2048];       //人脸特征数据
	int imgNum;                //图像数目
	int imgSize;               //图像大小
	unsigned char img[10240];  //图像数据
	char resv[16];
};

//人脸查询回调返回
struct QueryFaceInfoEx {
	int record_count;     //查询的角色记录总量
	int record_no;        //当前收到的记录序号
	char personID[20];    //人员ID
	char personName[16];  //姓名
	int role;			  //人员角色 0：普通人员。 1：白名单人员。 2：黑名单人员。 //-1：所有人员。

	int imgNum;           //模板图像数量
	int imgSize[5];       //图像大小，imgSize[i]为第i张图片的大小
	char imgFmt[5][4];    //图像格式,imgFmt[i]为第i张图片的格式
	unsigned char *imgBuff[5];     // imgBuff[i]位第i张图片给数据首地址
	unsigned int wgCardNO;         // 韦根门禁卡号
	unsigned int effectTime;       // 有效期截止时间，该人员信息在该时间内有效,从1970年1月1日0时0分0秒到截止时间的秒数（0xFFFFFFFF表示永久有效，0表示永久失效）
	unsigned int effectStartTime;  // 有效期起始时间，该人员信息在该时间之后有效,从1970年1月1日0时0分0秒到起始时间的秒数（0表示未初始化）
	char idcardper[100];           // 身份证号
	int user_type;                 // 权限
	char resv[128];
};


/// 抓拍比对纪录。
struct RecordData {
	/*! 查询的角色记录总量 */
	int record_count;

	/*! 当前收到的记录序号 */
	int record_no;

	/*! 抓拍纪录序列号 */
	unsigned int sequence;

	/*! 抓拍时间秒数，从1970年01月01日00时00分00秒至抓拍时间经过的秒数。 */
	unsigned int tvSec;

	/*! 抓拍时间微秒数，tvSec的尾数 */
	unsigned int tvUsec;

	/*! 比对状态(分数) */
	short matched;

	/*! 性别 */
	unsigned char sex;

	/*! 年龄*/
	unsigned char age;

	/*! 比对上的人员id */
	char person_id[20];

	/*! 比对上的人员姓名 */
	char person_name[16];

	/*！实时人脸图像长度 */
	int face_image_len;

	/*！实时人脸图像（jpg格式） */
	unsigned char *face_image;

	/*! 人脸位于特写图像的X坐标。 */
	unsigned short faceXInFaceImg;

	/*! 人脸位于特写图像的y坐标。 */
	unsigned short faceYInFaceImg;

	/*! 人脸位于特写图像的宽度 */
	unsigned short faceWInFaceImg;

	/*! 人脸位于特写图像的高度 */
	unsigned short faceHInFaceImg;

	/*！比对上的注册人脸图像长度，未比对上时为0*/
	int reg_image_len;

	/*！比对上的注册人脸图像（jpg格式），未比对上时为NULL */
	unsigned char *reg_image;

	/*! 人像质量。 */
	unsigned char qvalue;

	/*! 纪录是否已上传 1:表示已经上传 0：表示未上传*/
	char is_upload;

	/*! 保留 */
	char resv[2];
};


//系统网络信息
struct SystemNetInfo {
	char mac_addr[18];  //网卡物理地址
	char ip_addr[16];   //相机ip地址
	char netmask[16];   //子网掩码
	char gateway[16];   //默认网关
	char dns[16];		//设备dns
	char dns1[16];		//备用dns
	char resv[14];      //保留
};

//系统版本信息
struct SystemVersionInfo {
	char dev_id[32];              //设备序列号
	char protocol_ver[8];         //协议版本
	char firmware_ver[16];        //固件版本
	char code_ver[8];             //应用程序版本
	char build_time[20];          //应用编译时间
	char resv[16];                //保留
	char systemp_type[16];        //系统类型
	char plateform[16];           //硬件平台
	char sensor_type[16];         //传感器型号
	char algorithm_ver[16];       //算法版本
	char min_sdk_ver[16];         //最低sdk版本
	unsigned int min_client_ver;  //最低客户端版本
};

struct ha_rect {
	short x;       //人脸矩形区域左上角x坐标
	short y;       //人脸矩形区域左上角y坐标
	short width;   //人脸矩形区域宽度
	short height;  //人脸矩形区域高度
};

struct FaceRect {
	unsigned int faceId;      //人脸轮廓id
	struct ha_rect faceRect;  //人脸轮廓坐标
	char resv[4];
};

struct FaceRectInfo {
	char idShowFlag;
	char resv[3];
	int rectNum;  
	struct FaceRect faceRects[32];
};

struct FaceDelProgressInfo {
	int delCount;     //删除的纪录总数
	int curDelNo;     //当前删除第几条纪录
	char faceId[20];  //当前删除的人员ID
};

struct FaceReRegistProgressInfo {
	int regist_count;   //重注册的人员总数
	int cur_regist_no;  //当前重注册第几条纪录
	char faceId[20];    //当前重注册的人员id
};

struct DebugImage {
	int format;              //调试图像格式, 1:jpg
	short width;             //调试图像宽度
	short height;            //调试图像高度
	int imageLen;            //图像数据长度
	unsigned char *imgData;  //图像数据
};

struct DebugImageInfo {
	unsigned int timeStamp_s;  //时间戳 秒
	unsigned int timeStamp_u;  //时间戳 微妙
	int matched;			   //比对结果，0：未比对。-1：比对失败。1：比对成功
	int matchScore;            //比对分数
	char faceId[20];           //比对上的人员id，matched等于1时有效
	int imageNum;			   //调试图像数量，最大支持6张图像
	struct DebugImage debugImage[6];  //调试图像信息
};

//==============人脸门禁的数据结构及宏定义 end=============

//==============车牌识别定义 end=============
// 车牌识别相关参数
//---------------------------------------//
//车牌颜色
#define LC_UNKNOWN  0  //未知
#define LC_BLUE     1  //蓝色
#define LC_YELLOW   2  //黄色 
#define LC_WHITE    3  //白色
#define LC_BLACK    4  //黑色
#define LC_GREEN    5  //绿色

// 车牌识别相关参数
//---------------------------------------//
//车牌颜色
#define LC_UNKNOWN  0  //未知
#define LC_BLUE     1  //蓝色
#define LC_YELLOW   2  //黄色 
#define LC_WHITE    3  //白色
#define LC_BLACK    4  //黑色
#define LC_GREEN    5  //绿色

//车牌类型
#define LT_UNKNOWN  0   //未知车牌
#define LT_BLUE     1   //蓝牌小汽车
#define LT_BLACK    2   //黑牌小汽车
#define LT_YELLOW   3   //单排黄牌
#define LT_YELLOW2  4   //双排黄牌（大车尾牌，农用车）
#define LT_POLICE   5   //警车车牌
#define LT_ARMPOL   6   //武警车牌
#define LT_INDIVI   7   //个性化车牌
#define LT_ARMY     8   //单排军车牌
#define LT_ARMY2    9   //双排军车牌
#define LT_EMBASSY  10  //使馆车牌
#define LT_HONGKONG 11  //香港进出中国大陆车牌
#define LT_TRACTOR  12  //农用车牌
#define LT_COACH	13  //教练车牌
#define LT_MACAO	14  //澳门进出中国大陆车牌
#define LT_ARMPOL2   15 //双层武警车牌
#define LT_ARMPOL_ZONGDUI 16  // 武警总队车牌
#define LT_ARMPOL2_ZONGDUI 17 // 双层武警总队车牌
#define LI_AVIATION  18   //民航
#define LI_ENERGY    19   //新能源
#define LI_ENERGY2     20   //大型新能源
#define LI_EMERGENCY   21   //应急车牌
#define LI_CONSULATE   22   //领事馆

#define LI_FAKEPLATE 27 // 疑似虚假车牌警告
#define LI_CAR_COLOR 28 // 车身颜色
#define LI_CAR_TYPE  29 // 车辆类型
#define LI_CAR_BRAND 30 // 车标车款
#define LI_NOPLATE   31 // 无牌车信息


//运动方向
#define DIRECTION_LEFT	1  //左
#define DIRECTION_RIGHT	2  //右
#define DIRECTION_UP	3  //上
#define DIRECTION_DOWN	4  //下

//图像格式（TH_SetImageFormat函数的cImageFormat参数）
#define ImageFormatRGB		0			//RGBRGBRGB...
#define ImageFormatBGR		1			//BGRBGRBGR...
#define ImageFormatYUV422	2			//YYYY...UU...VV..	(YV16)
#define ImageFormatYUV420COMPASS 3		//YYYY...UV...		(NV12)
#define ImageFormatYUV420	4			//YYYY...U...V...	(YU12)
#define ImageFormatUYVY	    5			//UYVYUYVYUYVY...	(UYVY)
#define ImageFormatNV21		6			//YYYY...VU...		(NV21)
#define ImageFormatYV12		7			//YYYY...V...U		(YV12)
#define ImageFormatYUYV	    8			//YUYVYUYVYUYV..	(YUYV)
#define ImageFormatJPG	    9			//YUYVYUYVYUYV..	(YUYV)

//车辆颜色
#define LGRAY_DARK	0	//深
#define LGRAY_LIGHT	1	//浅

#define LCOLOUR_WHITE	0	//白	
#define LCOLOUR_SILVER	1	//灰(银)
#define LCOLOUR_YELLOW	2	//黄
#define LCOLOUR_PINK	3	//粉
#define LCOLOUR_RED		4	//红
#define LCOLOUR_GREEN	5	//绿
#define LCOLOUR_BLUE	6	//蓝
#define LCOLOUR_BROWN	7	//棕 
#define LCOLOUR_BLACK	8	//黑

// 触发识别类型定义
typedef enum _TH_TRIGGER_TYPE
{
	TRIGGER_TYPE_AUTO		=	0,		//自动
	TRIGGER_TYPE_EXTERNAL	=	1,		//外部
	TRIGGER_TYPE_SOFTWARE	=	2,		//软件
	TRIGGER_TYPE_VLOOP					//虚拟地感线圈
}TH_TRIGGER_TYPE;

typedef enum
{
	TRIGGER_TYPE_AUTO_BIT		= 1,    //自动
	TRIGGER_TYPE_EXTERNAL_BIT	= 1<<1, //外部
	TRIGGER_TYPE_SOFTWARE_BIT	= 1<<2, //软件
	TRIGGER_TYPE_VLOOP_BIT		= 1<<3  //虚拟地感线圈
}TH_TRIGGER_TYPE_BIT;

/**矩形区域信息*/
typedef struct TH_RECT
{
	int left;	/**<左*/
	int top;	/**<上*/
	int right;	/**<右*/
	int bottom;	/**<下*/
}TH_RECT;

typedef struct TH_TimeVal
{
	long    tv_sec;         /* 秒 */
	long    tv_usec;        /* 微秒 */
	long	tv_frameStamp;	/* 帧编号 */
}TH_TimeVal;

typedef struct
{
	unsigned uTVSec;
	unsigned uTVUSec;
}
VZ_TIMEVAL;

typedef struct CarBrand
{
	char brand;     // 品牌
	char type;      // 车型
	unsigned short year;      // 年份
} CarBrand;

#define TH_LP_LEN	16

/**车牌识别结果信息*/
typedef struct TH_PlateResult 
{
	char license[TH_LP_LEN];  	/**<车牌号码*/
	char color[8];      		/**<车牌颜色*/
	int nColor;					/**<车牌颜色序号，详见车牌颜色定义LC_X*/
	int nType;					/**<车牌类型，详见车牌类型定义LT_X*/
	int nConfidence;			/**<车牌可信度*/
	int nBright;				/**<亮度评价*/
	int nDirection;				/**<运动方向，详见运动方向定义 DIRECTION_X*/
	TH_RECT rcLocation; 		/**<车牌位置*/
	int nTime;          		/**<识别所用时间*/
	VZ_TIMEVAL tvPTS;			/**<识别时间点*/
	unsigned uBitsTrigType;		/**<强制触发结果的类型,见TH_TRIGGER_TYPE_BIT*/
	unsigned char nCarBright;	/**<车的亮度*/
	unsigned char nCarColor;	/**<车的颜色，详见车辆颜色定义LCOLOUR_X*/
	char reserved0;				/**为了对齐*/
	unsigned char ucWLResult;   /**白名单状态，详见白名单验证结果定义*/
	unsigned uId; 				/**<记录的编号*/
	VzBDTime    struBDTime;     /**<分解时间*/
	unsigned char nIsEncrypt;          /**<车牌是否加密*/
	unsigned char nPlateTrueWidth;     /**<车牌的真实宽度，单位cm*/
	unsigned char nPlateDistance;      /**<车牌距离相机的位置，单位dm(分米)*/
	unsigned char nIsFakePlate;        /**是否是伪车牌*/
	TH_RECT     car_location;   /**<车辆位置*/
	CarBrand    car_brand;      /**<车辆品牌*/
	char featureCode[20];       /**<车辆特征码*/
	char reserved1[24];			/**<保留*/     
}TH_PlateResult;

/**车牌识别结果在通过白名单验证的结果*/
typedef enum
{
	VZ_LPWL_UNHANDLE,       /**<未处理*/
	VZ_LPWL_VALID,          /**<在白名单中，且有效*/
	VZ_LPWL_INVALID,        /**<不在白名单中，或验证未通过*/
	VZ_LPWL_NO_LICENCE,     /**<无车牌*/
	VZ_LPWL_BLACK_LIST,     /**<黑名单*/
	VZ_LPWL_DISABLE,        /**<在白名单中，但记录无效*/
	VZ_LPWL_START_TIMEOUT,  /**<在白名单中，但记录还未到起始有效期*/
	VZ_LPWL_END_TIMEOUT,    /**<在白名单中，但记录超过结束有效期*/
	VZ_LPWL_SEG_TIMEOUT,    /**<在白名单中，但记录不在有效时间段内*/
	VZ_LPWL_SPECIAL_PLATE,  /**<特殊车牌*/
	VZ_LPWL_RESULT_COUNT,
}
VZ_LPWL_RESULT;

/**车牌识别结果的白名单信息扩展*/
typedef struct
{
	VzBDTime struTimeOverdue;   /**<白名单对应记录过期时间*/
	char strComment[32];        /**<授权号*/
	char strCode[64];           /**<用户ID*/
	unsigned char ucWLResult;   /**<白名单检验状态，详见白名单验证结果定义*/
	unsigned char ucRes[3];
}
VZ_LPWL_INFO;

#define ENCRYPT_NAME_LENGTH 32

/**加密类型**/
typedef struct
{
	unsigned uId;						//加密ID
	char sName[ENCRYPT_NAME_LENGTH];	//加密名
}VZ_EMS_INFO;

#define ENCRYPT_LENGTH 16
#define SIGNATURE_LENGTH 32

/**当前识别结果加密类型**/
typedef struct
{
	unsigned uActiveID;						//当前加密类型ID
	VZ_EMS_INFO oEncrpty[ENCRYPT_LENGTH];	//系统加密类型
	unsigned uSize;							//系统加密类型长度
	char signature[SIGNATURE_LENGTH];		//SIGNATURE
}VZ_LPRC_ACTIVE_ENCRYPT;

/**********当前已连接设备信息**************/
#define IPADDR_LENGTH 16
#define OVZID_NAME_LEN 385
#define SN_LEN 32

typedef struct
{
	unsigned enable_group;				// 是否加入组网
	char ip_addr[IPADDR_LENGTH];		// 设备IP
	char name[OVZID_NAME_LEN];			// 组网的名称
	char original_name[OVZID_NAME_LEN];	// 未解密之前的名称
	char sn[SN_LEN];					// 设备序列号
	unsigned type;						// 0未组网，1进口设备, 2出口设备
}VZ_OVZID_INFO;

#define OVZID_COUNT 64
typedef struct
{
	VZ_OVZID_INFO info[OVZID_COUNT];
	unsigned uCount;
}VZ_OVZID_RESULT;


//组网设备信息
typedef struct
{
	char vzName[128];               //识别结果来源设备名称
	char vzIP[16];                  //识别结果来源设备IP
	char vzSN[24];                  //识别结果来源设备序列号
	char vzType;                    //组网识别结果设备类型，0 : 入口 1 ： 出口
} IVS_DG_DEVICE_INFO;

/**可过滤的车牌识别触发类型*/
#define VZ_LPRC_TRIG_ENABLE_STABLE      0x1     /**<允许触发稳定结果*/
#define VZ_LPRC_TRIG_ENABLE_VLOOP       0x2     /**<允许触发虚拟线圈结果*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN1      0x10    /**<允许外部IO_IN_1触发*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN2      0x20    /**<允许外部IO_IN_2触发*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN3      0x40    /**<允许外部IO_IN_3触发*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN4      0x80    /**<允许外部IO_IN_4触发*/


#define   LPRC_CENTER_IPLEN  200
typedef struct      //中心服务器网络
{
	char centerServerIp[LPRC_CENTER_IPLEN];   //中心服务器地址
	WORD port;                         //中心服务器端口
	bool enableSsl;                    //是否使用ssl协议
	WORD sslPort;                      //ssl协议端口 
	WORD timeout;                      //超时时间设置错误, 范围【1~30】

}VZ_LPRC_CENTER_SERVER_NET;

/*抓拍结果推送配置*/
typedef struct
{
	unsigned char enable;	//默认不开启
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//推送地址
	unsigned level;	//推送结果级别。1 背景图 2 人脸图 4 背脸图 8 人形图 （如果是同时勾选采用或的方式进行组合 0代表无图）
}
VZ_CENTER_SERVER_ALARM_PARAM;

/*人员绊线统计推送配置*/
typedef struct
{
	unsigned char enable;	//默认不开启
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//推送地址
	unsigned interval;	//推送间隔时间
}
VZ_CENTER_SERVER_TRIPWIRE_PARAM;

/*区域计数推送配置*/
typedef struct
{
	unsigned char enable;
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//推送地址
	unsigned interval;	//推送间隔时间
	unsigned level;	//区域计数推送图片数据等级 （0 无图 1 背景图)
}
VZ_CENTER_SERVER_AREA_PEOPLE_COUNT_PARAM;

#define  URLLENGTH 1000
typedef struct      //中心服务器网络设备注册
{
	BYTE type;                         //中心服务器设备注册类型
	char url[URLLENGTH];               //中心服务器设备注册地址
}VZ_LPRC_CENTER_SERVER_DEVICE_REG;

typedef VZ_LPRC_CENTER_SERVER_NET VZ_CENTER_SERVER_INFO;
typedef VZ_LPRC_CENTER_SERVER_DEVICE_REG VZ_CENTER_SERVER_DEV_REG;

typedef struct       //中心服务器网络车牌
{
	char url[URLLENGTH];               //中心服务器车牌地址
	bool enable;                       //中心服务器车牌推送使能
	BYTE contentLevel;                 //中心服务器车牌内容详细等级
	bool sendLargeImage;               //中心服务器车牌是否发送大图片
	bool sendSmallImage;               //中心服务器车牌是否发送小图片
}VZ_LPRC_CENTER_SERVER_PLATE;

typedef struct						   //中心服务器网络设备端口触发
{
	bool enable;                       //中心服务器网络设备端口触发使能
	char url[URLLENGTH];               //中心服务器网络设备端口触发地址
}VZ_LPRC_CENTER_SERVER_GIONIN;

typedef struct      //中心服务器网络设备串口
{
	bool enable;                         //中心服务器网络设备串口使能
	char url[URLLENGTH];               //中心服务器网络设备串口地址
}VZ_LPRC_CENTER_SERVER_SERIAL;

typedef struct
{
	int default_stream;  /* 当前选择的码流 */
	int stream_id;       /* 码流类型 */
	int resolution;      /* 分辨率; */
	int frame_rate;      /* [0, 25]，帧率; */
	int encode_type;     /* h264; */
	int rate_type;       /* 码流类型，对应码流控制; */
	int data_rate;       /* 码流上限; */
	int video_quality;   /* 视频质量; */
}VZ_LPRC_R_ENCODE_PARAM;

#define  VZ_LPRC_MAX_RESOLUTION 12
#define  VZ_LPRC_MAX_RATE 5
#define  VZ_LPRC_MAX_VIDEO_QUALITY 12
#define  VZ_LPRC_MAX_ENCODE_TYPE 5
#define  VZ_LPRC_MAX_STREAM_TYPE 5
#define  VZ_LPRC_MAX_STREAM_COUNT 5

typedef struct
{
	int resolution_type;			/* 码流类型 */
	char resolution_content[32];    /* 码流类型 */

}VZ_LPRC_R_RESOLUTION;

typedef struct
{
	int rate_type_value;				
	char rate_type_content[32];

}VZ_LPRC_R_RATE_TYPE;

typedef struct
{
	int video_quality_type;
	char video_quality_content[32];
}VZ_LPRC_R_VIDEO_QUALITY;

typedef struct
{
	int encode_stream;												/* 当前选择的码流 */
	int resolution_cur;				/* 分辨率   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* 分辨率	*/			
	int frame_rate_cur;												/* 当前帧率; */
	int frame_rate_min;												/* 最小帧率; */
	int frame_rate_max;												/* 最大帧率; */
	int rate_type_cur;							/* 码率控制 */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* 码流上限; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;						/* 视频质量; */
	VZ_LPRC_R_VIDEO_QUALITY video_quality[VZ_LPRC_MAX_VIDEO_QUALITY];

}VZ_LPRC_R_ENCODE_PARAM_PROPERTY;

typedef struct
{
	int encode_type;
	char content[32];
}VZ_LPRC_ENCODE_TYPE;

typedef struct
{
	int encode_stream;												/* 当前选择的码流 */
	int resolution_cur;												/* 分辨率   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* 分辨率	*/			
	int frame_rate_cur;												/* 当前帧率; */
	int frame_rate_min;												/* 最小帧率; */
	int frame_rate_max;												/* 最大帧率; */
	int rate_type_cur;												/* 码率控制 */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* 码流上限; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;											/* 视频质量; */
	VZ_LPRC_R_VIDEO_QUALITY video_quality[VZ_LPRC_MAX_VIDEO_QUALITY];
	int encode_type_cur;
	VZ_LPRC_ENCODE_TYPE encode_type[VZ_LPRC_MAX_ENCODE_TYPE];
}VZ_LPRC_ENCODE_STREAM;

typedef struct
{
	int stream_type;
	char content[32];
}VZ_LPRC_STREAM_TYPE;

typedef struct
{
	int stream_cur;
	VZ_LPRC_STREAM_TYPE stream_type[VZ_LPRC_MAX_STREAM_TYPE];
	VZ_LPRC_ENCODE_STREAM encode_stream[VZ_LPRC_MAX_STREAM_COUNT];
}VZ_LPRC_ENCODE_PROP;

typedef struct
{
	int brightness; 
	int contrast;  
	int saturation;
	int sharpness; 
	int hue;     
	int exposure;
	int max_exposure;
	int gain;
	int max_gain; 
	int denoise;
	int flip;
	int frquency;
	int night_mode;
}VZ_LPRC_R_VIDEO_PARAM;

#define  VZ_LPRC_MAX_TIME_CTRL 3
#define  VZ_LPRC_MAX_TIME_LEN  16
#define  VZ_LPRC_MAX_LED_LEVEL 10
#define  VZ_LPRC_MAX_LED_MODE  5

typedef struct
{
	int id; 
	char time_begin[VZ_LPRC_MAX_TIME_LEN];
	char time_end[VZ_LPRC_MAX_TIME_LEN];
	int  led_level;
	int timectrl_enable;

}VZ_LPRC_TIME_CTRL_PARAM;


typedef struct
{
	int led_mode; 
	int led_level;
	VZ_LPRC_TIME_CTRL_PARAM time_ctrl[VZ_LPRC_MAX_TIME_CTRL];
}VZ_LPRC_CTRL_PARAM;

typedef struct
{
	int type; 
	char content[32];
}VZ_LPRC_LED_LEVEL_ITEM;

typedef struct
{
	int type; 
	char content[32];
}VZ_LPRC_LED_MODE_ITEM;

typedef struct
{
	VZ_LPRC_LED_LEVEL_ITEM level_items[VZ_LPRC_MAX_LED_LEVEL];
	VZ_LPRC_LED_MODE_ITEM mode_items[VZ_LPRC_MAX_LED_MODE];
}VZ_LPRC_LED_PROP;

typedef struct tagTH_ImgInfo
{
	char imt_type[12];		// 图像类型 如：bmp,jpg,jpeg
	unsigned char* img_buf; // 图像buf
	unsigned int img_len;	// 图像长度
}TH_ImgInfo;

//==============车牌识别定义 end=============

//==============路侧定义 start=============
#define MAX_BERTH_COUNT  16

typedef struct{
	int berth_number;				// 泊位编号
	int berth_state;                // 泊位状态 （1.入场 2.出场 0.无）
	char license[TH_LP_LEN];  	    // 车牌号码
} TH_RoadSiteBerth;

/**车牌识别结果信息*/
typedef struct 
{
	TH_PlateResult plate_result;
	TH_RECT berth_location;					 // 泊位图位置
	int berth_state;						 // 泊位图状态（1.入场 2.出场 0.无）
	int berth_number;						 // 泊位编号
	char berth_name[32];					 // 泊位名称
	TH_ImgInfo full_img[3];					 // 全图(3个时刻的图片)
	TH_ImgInfo clip_img;					 // 车牌图片
	TH_RoadSiteBerth berth[MAX_BERTH_COUNT]; // 泊位信息
	int berth_count;			             // 泊位个数
	char reserved1[128];		             // 预留数据
}TH_RoadSiteResult;

//==============路侧定义 end=============


//==============接口参数定义 start=============
/** LASTERROR 类型 */
typedef enum {
	VZ_LPRC_LASTERROR_SUCCESS,              /**<操作成功完成 */
	VZ_LPRC_LASTERROR_NOT_SETUP,            /**<未进行 Setup 操作 */
	VZ_LPRC_LASTERROR_CREATE_FAILED,        /**<创建 LPRC_OBJ 失败 */
	VZ_LPRC_LASTERROR_CONNECT_FAILED,       /**<设备连接失败 */
	VZ_LPRC_LASTERROR_INVALID_HANDLE,       /**<LPRC_OBJ 句柄不可用 */
	VZ_LPRC_LASTERROR_INVALID_IP,           /**<IP 不可用 */
	VZ_LPRC_LASTERROR_NOT_FOUND_IP,         /**<未发现该 IP */
	VZ_LPRC_LASTERROR_INVALID_PSTATUS,      /**<获取状态的变量地址不可用 */
	VZ_LPRC_LASTERROR_REALPLAY_FAILED,      /**<播放实时视频失败 */
	VZ_LPRC_LASTERROR_NOT_FOUND_PLAYHANDLE, /**<视频播放句柄查找失败 */
	VZ_LPRC_LASTERROR_CALLBACK_ERROR,       /**<回调函数类型错误 */
	VZ_LPRC_LASTERROR_IMAGEFORMAT_ERROR,    /**<图片格式为非 BGR 格式 */
	VZ_LPRC_LASTERROR_NULL_IMGINFO,         /**<图像结构体地址不可用 */
	/**<图像结构体地址不可用或 JPEG 的目的存储地址不可用 */
	VZ_LPRC_LASTERROR_WRONG_IMGINFO_DSTBUF,
	VZ_LPRC_LASTERROR_IOOUTPUT_ERROR,       /**<IO 获取输出状态的地址不可用 */
	VZ_LPRC_LASTERROR_INVALID_SERIALHANDLE, /**<透明通道句柄不可用 */
	VZ_LPRC_LASTERROR_INVALID_WHITELIST,    /**<白名单句柄不可用 */
	VZ_LPRC_LASTERROR_INVALID_FILENAME,     /**<文件名不可用 */
	VZ_LPRC_LASTERROR_SEARCHSET_ERROR,      /**<查询车牌号分页记录起止位置设置错误 */
	/**<获取车牌图片图片内存地址不可用或图片内存大小设置错误或图片内存大小地址不可用 */
	VZ_LPRC_LASTERROR_GETPLATE_ERROR,
	VZ_LPRC_LASTERROR_PLATESIZE_ERROR,      /**<视频图像高度或宽度变量地址不可用 */
	VZ_LPRC_LASTERROR_ENCODE_TYPE_ERROR,    /**<获取编码方式的地址不可用 */
	VZ_LPRC_LASTERROR_GPIO_STATUS_ERROR,    /**<获取 GPIO 状态的地址不可用 */
	VZ_LPRC_LASTERROR_GPIO_NUMBER_ERROR,    /**<GPIO 编号不可用 */
	VZ_LPRC_LASTERROR_INVALID_FILEPATH,     /**<文件路径不可用 */
	VZ_LPRC_LASTERROR_EDITION_ERROR,        /**<获取升级文件版本号内存地址不可用 */
	VZ_LPRC_LASTERROR_DBERROR_PLATEID_EXISTS,     /**<车牌ID已经存在 */
	VZ_LPRC_LASTERROR_DBERROR_INSERT_CUSTOMERINFO_FAILED, /**<添加客户资料出错 */
	VZ_LPRC_LASTERROR_DBERROR_INSERT_VEHICLEINFO_FAILED,  /**<添加白名单出错 */
	VZ_LPRC_LASTERROR_DBERROR_UPDATE_CUSTOMERINFO_FAILED, /**<更新客户资料出错 */
	VZ_LPRC_LASTERROR_DBERROR_UPDATE_VEHICLEINFO_FAILED,  /**<更新白名单出错 */
	VZ_LPRC_LASTERROR_DBERROR_PLATEID_EMPTY,  /**<白名单车牌ID为空 */
	VZ_LPRC_LASTERROR_DBERROR_ROW_NOT_CHANGED,    /**<更新失败 */
	VZ_LPRC_LASTERROR_DBERROR_CUSTOMERINFO_NOT_CHANGED,   /**<客户资料未更新 */
	VZ_LPRC_LASTERROR_DBERROR_VEHICLEINFO_NOT_CHANGED,    /**<白名单资料未更新 */
	/**<客户资料与白名单不匹配 */
	VZ_LPRC_LASTERROR_DBERROR_CUSTOMER_VEHICLE_NOT_MATCH,
	VZ_LPRC_LASTERROR_DBERROR_SQLERRORCODESERVERGONE  /**<SQLite服务器端出错 */
}
VZ_LPRC_LASTERROR_TYPE;

/**设置回调函数时需要指定的类型*/
typedef enum {
	VZ_LPRC_CALLBACK_COMMON_NOTIFY, /**<SDK通用信息反馈（预留）*/
	VZ_LPRC_CALLBACK_PLATE_STR,   /**<车牌号码字符（预留）*/
	VZ_LRPC_CALLBACK_FULL_IMAGE,  /**<完整图像*/
	VZ_LPRC_CALLBACK_CLIP_IMAGE,  /**<截取图像*/
	VZ_LPRC_CALLBACK_PLATE_RESULT, /**<实时识别结果*/
	VZ_LPRC_CALLBACK_PLATE_RESULT_STABLE, /**<稳定识别结果*/
	/**<触发的识别结果，包括API（软件）和IO（硬件）方式的*/
	VZ_LPRC_CALLBACK_PLATE_RESULT_TRIGGER,
	VZ_LPRC_CALLBACK_VIDEO,   /**<视频帧回调*/
}
VZ_LPRC_CALLBACK_TYPE;

/**通用信息反馈类型*/
typedef enum {
	VZ_LPRC_NO_ERR = 0, /**<无错误*/
	VZ_LPRC_ACCESS_DENIED,  /**<用户名密码错误*/
	VZ_LPRC_NETWORK_ERR,  /**<网络连接故障*/
	VZ_LPRC_ONLINE,     /**<设备上线*/
	VZ_LPRC_OFFLINE,    /**<设备掉线*/
	VZ_LPRC_IO_INPUT = 100, /**<IO口输入信号*/
}
VZ_LPRC_COMMON_NOTIFY;

typedef enum {
	VZ_NO_ERR = 0, /**<无错误*/
	VZ_ACCESS_DENIED,  /**<用户名密码错误*/
	VZ_NETWORK_ERR,  /**<网络连接故障*/
	VZ_ONLINE,     /**<设备上线*/
	VZ_OFFLINE,    /**<设备掉线*/
	VZ_IO_INPUT = 100, /**<IO口输入信号*/
}
VZ_COMMON_NOTIFY;

/**识别结果的类型*/
typedef enum {
	VZ_LPRC_RESULT_REALTIME,  /**<实时识别结果*/
	VZ_LPRC_RESULT_STABLE,  /**<稳定识别结果*/
	/**<调用“VzLPRClient_ForceTrigger”触发的识别结果*/
	VZ_LPRC_RESULT_FORCE_TRIGGER,
	VZ_LPRC_RESULT_IO_TRIGGER,  /**<外部IO信号触发的识别结果*/
	VZ_LPRC_RESULT_VLOOP_TRIGGER, /**<虚拟线圈触发的识别结果*/
	/**<由_FORCE_\_IO_\_VLOOP_中的一种或多种同时触发，具体需要根据每个识别结果的TH
	* _PlateResult::uBitsTrigType来判断*
	*/
	VZ_LPRC_RESULT_MULTI_TRIGGER,
	VZ_LPRC_RESULT_TYPE_NUM /**<结果种类个数*/
} VZ_LPRC_RESULT_TYPE;

/**顶点定义
*X_1000和Y_1000的取值范围为[0, 1000]；
*即位置信息为实际图像位置在整体图像位置的相对尺寸；
*例如X_1000 = x*1000/win_width，其中x为点在图像中的水平像素位置，win_width为图像宽度
*/
typedef struct {
	unsigned X_1000;  /**<水平方向相对坐标*/
	unsigned Y_1000;  /**<竖直方向相对坐标*/
} VZ_LPRC_VERTEX;

/**穿越方向枚举*/
typedef enum {
	VZ_LPRC_BIDIR,  /**双向触发*/
	VZ_LPRC_UP2DOWN,  /**从上到下方向的车辆触发*/
	VZ_LPRC_DOWN2UP,  /**从下到上方向的车辆触发*/
}
VZ_LPRC_DIR;
/**虚拟线圈名称*/
#define VZ_LPRC_VIRTUAL_LOOP_NAME_LEN 32

/**虚拟线圈顶点个数*/
#define VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM 4

/**虚拟线圈信息定义*/
typedef struct {
	BYTE byID;  /**<序号*/
	BYTE byEnable;  /**<是否有效*/
	BYTE byDraw;  /**<是否绘制*/
	BYTE byRes[1];  /**<预留*/
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<自定义名称*/
	VZ_LPRC_VERTEX struVertex[VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM];  /**<顶点数组*/
	VZ_LPRC_DIR eCrossDir;  /**<穿越方向限制*/
	unsigned uTriggerTimeGap; /**对相同车牌的触发时间间隔的限制，单位为秒*/
	unsigned uMaxLPWidth;  /**最大车牌尺寸限制*/
	unsigned uMinLPWidth;  /**最小车牌尺寸限制*/
}
VZ_LPRC_VIRTUAL_LOOP;

/**最大虚拟线圈个数*/
#define VZ_LPRC_VIRTUAL_LOOP_MAX_NUM  8

/**虚拟线圈序列*/
typedef struct {
	unsigned uNumVirtualLoop;	/**<实际个数*/
	/**<虚拟线圈数组*/
	VZ_LPRC_VIRTUAL_LOOP struLoop[VZ_LPRC_VIRTUAL_LOOP_MAX_NUM];
}
VZ_LPRC_VIRTUAL_LOOPS;

/**虚拟线圈顶点个数*/
#define VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM_EX  12

/**虚拟线圈信息定义*/
typedef struct {
	BYTE byID;  /**<序号*/
	BYTE byEnable;  /**<是否有效*/
	BYTE byDraw;  /**<是否绘制*/
	BYTE byRes[1];  /**<预留*/
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<自定义名称*/
	unsigned uNumVertex;  /**<顶点实际个数*/
	VZ_LPRC_VERTEX struVertex[VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM_EX];  /**<顶点数组*/
	VZ_LPRC_DIR eCrossDir;  /**<穿越方向限制*/
	unsigned uTriggerTimeGap; /**对相同车牌的触发时间间隔的限制，单位为秒*/
	unsigned uMaxLPWidth;  /**最大车牌尺寸限制*/
	unsigned uMinLPWidth;  /**最小车牌尺寸限制*/
}
VZ_LPRC_VIRTUAL_LOOP_EX;

/**虚拟线圈序列*/
typedef struct {
	unsigned uNumVirtualLoop;	 /**<实际个数*/
	/**<虚拟线圈数组*/
	VZ_LPRC_VIRTUAL_LOOP_EX struLoop[VZ_LPRC_VIRTUAL_LOOP_MAX_NUM];
}
VZ_LPRC_VIRTUAL_LOOPS_EX;

/**识别区域顶点个数*/
#define VZ_LPRC_ROI_VERTEX_NUM  4

/**识别区域信息定义*/
typedef struct {
	BYTE            byRes1;     /**<预留*/
	BYTE            byEnable;   /**<是否有效*/
	BYTE            byDraw;     /**<是否绘制*/
	BYTE            byRes2;     /**<预留*/
	BYTE            byRes3[32]; /**<预留*/
	VZ_LPRC_VERTEX  struVertex[VZ_LPRC_ROI_VERTEX_NUM];  /**<顶点数组*/
}
VZ_LPRC_ROI;

/**识别区域顶点个数*/
#define VZ_LPRC_ROI_VERTEX_NUM_EX 12
/**识别区域信息定义*/
typedef struct {
	BYTE            byRes1; /**<预留*/
	BYTE            byEnable; /**<是否有效*/
	BYTE            byDraw; /**<是否绘制*/
	BYTE            byRes2; /**<预留*/
	BYTE            byRes3[32]; /**<预留*/
	unsigned        uNumVertex; /**<顶点实际个数*/
	VZ_LPRC_VERTEX  struVertex[VZ_LPRC_ROI_VERTEX_NUM_EX]; /**<顶点数组*/
}
VZ_LPRC_ROI_EX;

/**省份字符串的最大尺寸*/
#define VZ_LPRC_PROVINCE_STR_LEN  128

/**预设省份信息*/
typedef struct {
	char strProvinces[VZ_LPRC_PROVINCE_STR_LEN];  /**<所有支持的省份简称构成的字符串*/
	int nCurrIndex; /**<当前的预设省份的序号，在strProvinces中的，-1为未设置*/
}
VZ_LPRC_PROVINCE_INFO;

/**图像信息*/
typedef struct {
	unsigned  uWidth; /**<宽度*/
	unsigned  uHeight;  /**<高度*/
	unsigned  uPitch; /**<图像宽度的一行像素所占内存字节数*/
	unsigned  uPixFmt;  /**<图像像素格式，参考枚举定义图像格式（ImageFormatXXX）*/
	unsigned char *pBuffer;   /**<图像内存的首地址*/
}
VZ_LPRC_IMAGE_INFO;

/**数据帧类型*/
typedef enum {
	VZ_LPRC_DATA_ENC_VIDEO, /**<视频帧编码数据*/
	VZ_LPRC_DATA_ENC_AUDIO, /**<音频帧编码数据*/
}
VZ_LPRC_DATA_TYPE;

/**数据帧信息*/
typedef struct {
	unsigned char	*pBuffer; /**<数据内存的首地址*/
	unsigned  uDataSize;  /**<数据帧尺寸，字节数*/
	unsigned  uPTS_Sec; /**<帧时间戳_秒*/
	unsigned  uPTS_USec;  /**<帧时间戳_微妙*/
	unsigned char	uIsKeyFrame;  /**<关键帧标志位：1为关键帧，0为非关键帧*/
	unsigned char	reserved[7];  /**<预留*/
}
VZ_LPRC_DATA_INFO;

/**镜头变倍变焦命令*/
typedef enum {
	VZ_LENS_OPT_STOP, /**<停止调节*/
	VZ_LENS_FOCUS_FAR,  /**<往远处聚焦*/
	VZ_LENS_FOCUS_NEAR, /**<往近处聚焦*/
	VZ_LENS_ZOOM_TELE,  /**<往长焦变倍*/
	VZ_LENS_ZOOM_WIDE,  /**<往短焦变倍*/
}
VZ_LENS_OPT;

/**LED补光灯命令*/
typedef enum {
	VZ_LED_AUTO,  /**<自动控制LED的开和关*/
	VZ_LED_MANUAL_ON, /**<手动控制LED开启*/
	VZ_LED_MANUAL_OFF,  /**<手动控制LED关闭*/
	VZ_LED_TIME_QUANTUM  /**<时间段*/
}
VZ_LED_CTRL;

/**用户私有数据的最大字节数*/
#define VZ_LPRC_USER_DATA_MAX_LEN 128

/**设备唯一序列号*/
typedef struct {
	unsigned uHi; /**<高位*/
	unsigned uLo; /**<低位*/
}
VZ_DEV_SERIAL_NUM;

/**设备日期时间参数*/
typedef struct {
	unsigned uYear; /**<年*/
	unsigned uMonth;  /**<月 [1, 12]*/
	unsigned uMDay; /**<月中的天数 [1, 31]*/
	unsigned uHour; /**<时*/
	unsigned uMin;  /**<分*/
	unsigned uSec;  /**<秒*/
}
VZ_DATE_TIME_INFO;

/**串口参数*/
typedef struct {
	// <波特率 300,600,1200,2400,4800,9600,19200,34800,57600,115200
	unsigned uBaudRate;
	unsigned uParity;   // <校验位 其值为0-2=no,odd,even
	unsigned uDataBits;   // <数据位 其值为7,8 位数据位
	unsigned uStopBit;  // <停止位 其值为1,2位停止位
}
VZ_SERIAL_PARAMETER;

/**存储设备类型*/
typedef enum {
	VZ_STORAGE_DEV_SD = 0,  /**<SD卡*/
	VZ_STORAGE_DEV_HD /**<硬盘*/
}
VZ_STORAGE_DEV_TYPE;

/**存储设备状态*/
typedef enum {
	VZ_STORAGE_DEV_NO_PART = 0, /**<未分区*/
	VZ_STORAGE_DEV_PART_OK, /**<已分区*/
}
VZ_STORAGE_DEV_STATUS;

/**存储设备分区的工作状态*/
typedef enum {
	VZ_STORAGE_DEV_PART_ERROR = 0,  /**<异常*/
	VZ_STORAGE_DEV_PART_NOT_FORMAT, /**<未格式化*/
	VZ_STORAGE_DEV_PART_NOT_MOUNT,  /**<未挂载*/
	VZ_STORAGE_DEV_PART_FORMATING,  /**<正在格式化*/
	VZ_STORAGE_DEV_PART_DELETING, /**<正在删除文件*/
	VZ_STORAGE_DEV_PART_NORMAL, /**<正常工作状态*/
}
VZ_STORAGE_DEV_PART_STATUS;

/**存储设备分区信息*/
typedef struct {
	VZ_STORAGE_DEV_PART_STATUS eStatus; /**<工作状态*/
	unsigned uUsed; /**<已用空间（MB)*/
	unsigned uLeft; /**<可用空间（MB)*/
	unsigned uTotal;  /**<总容量（MB）*/
	int nFormatPercent; /**<格式化百分比*/
}
VZ_STORAGE_DEV_PART_INFO;

#define VZ_MAX_NUM_STORAGE_DEV_PART_NUM 4
/**单个存储设备信息*/
typedef struct {
	char reserved[32];
	VZ_STORAGE_DEV_TYPE eType;  /**<存储设备类型*/
	VZ_STORAGE_DEV_STATUS eStatus;  /**<存储设备状态*/
	unsigned uPartNum;  /**<分区个数*/
	/**<各分区信息*/
	VZ_STORAGE_DEV_PART_INFO struPartInfo[VZ_MAX_NUM_STORAGE_DEV_PART_NUM];
}
VZ_STORAGE_DEVICE_INFO;

#define VZ_MAX_NUM_STORAGE_DEVICE 4
/**存储设备信息*/
typedef struct {
	int nDevCount;  /**<存储设备个数*/
	VZ_STORAGE_DEVICE_INFO struSDI[VZ_MAX_NUM_STORAGE_DEVICE];  /**<各存储设备信息*/
}
VZ_STORAGE_DEVICES_INFO;

#define LPRC_OSDTEXTLEN 64

typedef struct {
	unsigned char	dstampenable;   // 0 off 1 on
	int dateFormat; // 0:YYYY/MM/DD;1:MM/DD/YYYY;2:DD/MM/YYYY
	int datePosX;
	int datePosY;
	unsigned char	tstampenable;   // 0 off 1 on
	int timeFormat; // 0:12Hrs;1:24Hrs
	int timePosX;
	int timePosY;
	unsigned char	nLogoEnable;  // 0 off 1 on
	int nLogoPositionX;   ///<  logo position
	int nLogoPositionY;   ///<  logo position
	unsigned char	nTextEnable;    ///0 off 1 on
	int nTextPositionX;   ///<  text position
	int nTextPositionY;   ///<  text position
	char overlaytext[LPRC_OSDTEXTLEN]; ///user define text
}VZ_LPRC_OSD_Param;


typedef struct
{
	int realtime_result;
	int virtualloop_area;
	int plate_pos;
	int distance;
}VZ_LPRC_REALTIME_SHOW_PARAM;

#define MAX_USER_OSD_TEXT_LEN 64

typedef struct
{
	BYTE id; // id必须有0,1,2,，分别代表三行
	BYTE display; // 是否显示本行
	BYTE color; // 字体颜色 0：白色 1：红 2：蓝 3：绿    
	BYTE front_size; //字体大小 0:16号  1:24号  2:36号  3:48号
	char text[MAX_USER_OSD_TEXT_LEN]; // 文本内容，最大63个字节，中文一个占2字节

}VZ_LPRC_USER_OSD_ITEM_PARAM;

#define MAX_USER_OSD_ITEM_COUNT 3
typedef struct
{
	int x_pos; // 区域相对位置，取值范围[0,100]
	int y_pos; // 区域相对位置，取值范围[0,100]
	VZ_LPRC_USER_OSD_ITEM_PARAM osd_item[MAX_USER_OSD_ITEM_COUNT];
}VZ_LPRC_USER_OSD_PARAM;

#define MAX_USER_OSD_EX_ITEM_COUNT 4
typedef struct
{
	int x_pos; // 区域相对位置，取值范围[0,100]
	int y_pos; // 区域相对位置，取值范围[0,100]
	VZ_LPRC_USER_OSD_ITEM_PARAM osd_item[MAX_USER_OSD_EX_ITEM_COUNT];
}VZ_LPRC_USER_OSD_EX_PARAM;

// 云平台设备信息列表
#define MAX_PDNS_DEVICE_COUNT 128

typedef struct tagVZ_LPRC_PDNS_DEVICE_INFO
{
	char device_addr[16];
	char device_name[32];
	char sn[32];
	short status;

}VZ_LPRC_PDNS_DEVICE_INFO;

typedef struct tagVZ_LPRC_PDNS_DEVICE_LIST
{
	VZ_LPRC_PDNS_DEVICE_INFO device_info[MAX_PDNS_DEVICE_COUNT];
	int device_count; 
}VZ_LPRC_PDNS_DEVICE_LIST;

// 云平台分组信息
#define MAX_PDNS_GROUP_COUNT 128
typedef struct tagVZ_LPRC_PDNS_GROUP_INFO
{
	int group_id;
	int parent_id;
	char group_name[32];
}VZ_LPRC_PDNS_GROUP_INFO;

typedef struct tagVZ_LPRC_PDNS_GROUP_LIST
{
	VZ_LPRC_PDNS_GROUP_INFO group_info[MAX_PDNS_GROUP_COUNT];
	int group_count;
}VZ_LPRC_PDNS_GROUP_LIST;

#define LPRC_IPLEN				16

typedef struct VZ_LPRC_NETCFG {
	char ipaddr[LPRC_IPLEN];
	char netmask[LPRC_IPLEN];
	char gateway[LPRC_IPLEN];
	char dns[LPRC_IPLEN];
	WORD  http_port;
}VZ_LPRC_NETCFG;

typedef struct VZ_LPRC_NETCFG_EX {
	char ipaddr[LPRC_IPLEN];
	char netmask[LPRC_IPLEN];
	char gateway[LPRC_IPLEN];
	char dns[LPRC_IPLEN];
	WORD enable_dhcp;

	char ipaddr1[LPRC_IPLEN];
	char netmask1[LPRC_IPLEN];
	char gateway1[LPRC_IPLEN];
	char dns1[LPRC_IPLEN];
	WORD enable_dhcp1;

	WORD  http_port;
	WORD  rtsp_port;
	int   https_en;
	char reserved[120];
}VZ_LPRC_NETCFG_EX;

typedef enum _IMG_SIZE_MODE {
	IMG_MODE_NONE = 0,
	IMG_MODE_CIF,
	IMG_MODE_D1,
	IMG_MODE_720P
}IMG_SIZE_MODE;

#define LPRC_OEM_INFO_SIZE 7
#define LPRC_HW_VERSION_SIZE 4
typedef struct _VZ_FS_INFO_EX {
	char soft_platform;   //平台类型
	unsigned char oem_info[LPRC_OEM_INFO_SIZE];   ///< 前3位厂商的编号，后4位厂商简称
	///< 硬件版本号,1001是老版，,新版第三位表示通道路数，最后一位表示hwflag（HwFlags的按位与）
	unsigned char hw_version[LPRC_HW_VERSION_SIZE];
	unsigned int hw_flag;   ///< 硬件标识,新版改为保存HwType
}VZ_FS_INFO_EX;

//智能视频
typedef struct _VZ_LPRC_DRAWMODE {
	BYTE byDspAddTarget;  //dsp叠加报警目标
	BYTE byDspAddRule;  //dsp叠加设置规则
	BYTE byDspAddTrajectory;  //dsp叠加轨迹
	BYTE byPlateColor;  //叠加车牌颜色
	BYTE dwRes[1];
}VZ_LPRC_DRAWMODE;

// 手动校正车牌的参数配置
#define LPRC_MAX_PLATE_LEN 16
#define LPRC_MAX_MANU_PLATE_COUNT 200

typedef struct tagVZ_LPRC_MANU_PLATE_ITEM
{
	char src_plate[LPRC_MAX_PLATE_LEN];
	char dst_plate[LPRC_MAX_PLATE_LEN];
	char record_time[20];
	char plate_type;
	char plate_color;
}VZ_LPRC_MANU_PLATE_ITEM;

typedef struct tagVZ_LPRC_MANU_PLATE_RESULT
{
	unsigned short enable;
	unsigned short manu_count;
	VZ_LPRC_MANU_PLATE_ITEM manu_items[LPRC_MAX_MANU_PLATE_COUNT];
}VZ_LPRC_MANU_PLATE_RESULT;

/**可配置的识别类型*/
#define VZ_LPRC_REC_BLUE      (1<<(LT_BLUE))      /**<蓝牌车*/
#define VZ_LPRC_REC_YELLOW    (1<<(LT_YELLOW)|1<<(LT_YELLOW2))  /**<黄牌车*/
#define VZ_LPRC_REC_BLACK     (1<<(LT_BLACK))   /**<黑牌车*/
#define VZ_LPRC_REC_COACH     (1<<(LT_COACH))   /**<教练车*/
#define VZ_LPRC_REC_POLICE    (1<<(LT_POLICE))  /**<警车*/
/**<武警车*/
#define VZ_LPRC_REC_AMPOL     (1 << (LT_ARMPOL) | 1 << (LT_ARMPOL2))  
#define VZ_LPRC_REC_ARMY      (1<<(LT_ARMY)|1<<(LT_ARMY2))  /**<军车*/
#define VZ_LPRC_REC_GANGAO    (1<<(LT_HONGKONG)|1<<(LT_MACAO))  /**<港澳进出大陆车*/
#define VZ_LPRC_REC_EMBASSY   (1<<(LT_EMBASSY)) /**<使馆车*/
#define VZ_LPRC_REC_AVIATION  (1<<(LI_AVIATION))  /**<民航*/
#define VZ_LPRC_REC_ENERGY    (1<<(LI_ENERGY))  /**<新能源*/
#define VZ_LPRC_REC_EMERGENCY (1<<(LI_EMERGENCY))  /**<应急车牌*/
#define VZ_LPRC_REC_CONSULATE (1<<(LI_CONSULATE))  /**<领事馆*/

#define VZ_LPRC_REC_FAKEPLATE (1<<(LI_FAKEPLATE))  /**<疑似虚假车牌警告*/
#define VZ_LPRC_REC_CAR_COLOR (1<<(LI_CAR_COLOR))  /**<车身颜色*/
#define VZ_LPRC_REC_CAR_TYPE (1<<(LI_CAR_TYPE))  /**<车辆类型*/
#define VZ_LPRC_REC_CAR_BRAND (1<<(LI_CAR_BRAND))  /**<车标车款*/
#define VZ_LPRC_REC_NOPLATE (1<<(LI_NOPLATE))  /**<无牌车信息*/

//触发输入的类型
typedef enum {
	nWhiteList = 0,   //通过
	nNotWhiteList,    //不通过
	nNoLicence,   //无车牌
	nBlackList,   //黑名单
	nExtIoctl1,   //开关量/电平输入 1
	nExtIoctl2,   //开关量/电平输入 2
	nExtIoctl3,   //开关量/电平输入 3
	nSpecialPlates,  //特殊车牌
	nExtIoctl4       //开关量/电平输入 4
}VZ_InputType;

//输出配置
typedef struct {
	int switchout1;   //开关量输出 1
	int switchout2;   //开关量输出 2
	int switchout3;   //开关量输出 3
	int switchout4;   //开关量输出 4
	int levelout1;    //电平输出 1 
	int levelout2;    //电平输出 2
	int rs485out1;    //RS485-1
	int rs485out2;    //RS485-2
	VZ_InputType eInputType;    //触发输入的类型
}VZ_LPRC_OutputConfig;

#define MAX_OutputConfig_Len 9

//输出配置信息
typedef struct {
	//多个输出配置输出的消息
	VZ_LPRC_OutputConfig oConfigInfo[MAX_OutputConfig_Len];   
}VZ_OutputConfigInfo;

// RS-485推送配置类型
typedef enum {
	VZ_RS485_NOTYPE = 0,
	VZ_RS485_LICENSEENABLE,   //有无车牌
	VZ_RS485_LICENSECOLOR,    //车牌颜色
	VZ_RS485_LICENSE,   //车牌号
	VZ_RS485_LICENSETYPE,   //车牌类型
	VZ_RS485_CONFIDENCE,  //可信度
	VZ_RS485_DIRECTION,   //运动方向
	VZ_RS485_RECT,        //车牌区域
	VZ_RS485_TRIGGER,     //触发类型
	VZ_RS485_CARCOLOR,    //车辆颜色
	VZ_RS485_TIME,        //识别时间
	VZ_RS485_DUETIME,     //白名单过期时间 时间类型：VZ_RS485_TIME_FORMAT
	VZ_RS485_WLRESULT,    //白名单验证结果 时间类型：VZ_RS485_TIME_FORMAT
	VZ_RS485_OUT,         //输出IO
	VZ_RS485_SN,          //序列号
	VZ_RS485_CIPHERTEXT,  //密文
	VZ_RS485_ID,          //识别记录ID
	VZ_RS485_CHECKBEGIN,  //校验起始位
	VZ_RS485_CHECKEND,    //校验结束位
	VZ_RS485_CHECKSUM,    //校验位
	VZ_RS485_ENCODE,      //车牌编码
	VZ_RS485_EDIAN,       //大小端

	VZ_RS485_TYPELEN      //推送项长度
}VZ_RS485_PUSH_TYPE;

//时间类型
typedef enum {
	VZ_TIME_FOUR_STAMP = 0, //4字节 时间戳
	VZ_TIME_SEVEN_YYMDHMS,  //7字节 YYYYTTMMDDHHmmss
	VZ_TIME_SIX_YMDHMS,     //6字节 YYMMDDHHmmss
	VZ_TIME_SEVEN_HMSDMYY,  //7字节	HHmmssDDMMYYYY
	VZ_TIME_SIX_HMSDMY,     //6字节 HHmmssDDMMYY
	VZ_TIME_FOUR_YYMD,      //4字节 YYYYMMDD
	VZ_TIME_THREE_YMD       //3字节	YYMMDD
}VZ_RS485_TIME_FORMAT;

//校验位
typedef enum {
	VZ_CHECK_NO = 0,    //无校验
	VZ_CHECK_SUM,       //和校验
	VZ_CHECK_XOR        //异或校验
}VZ_RS485_ITEM_CHECKSUM;

//大小端
typedef enum {
	VZ_EDIAN_LITTLE = 0,    //小端
	VZ_EDIAN_BIG            //大端
}VZ_RS485_ITEM_EDIAN;

//车牌加密
typedef enum {
	VZ_ENCRY_NOTENCRY,    //有车牌不加密
	VZ_ENCRY_ENCRY        //有车牌且加密	
}VZ_RS485_ITEM_ENCRY;

//汉字编码
typedef enum {
	VZ_ENCODE_UTF8 = 1,
	VZ_ENCODE_GBK,
	VZ_ENCODE_GB2312
}VZ_RS485_ITEM_ENCODE;

// RS-485推送配置项
typedef struct {
	int item_type;    //推送字段类型
	int val;          //值
}VZ_RS485_ITEM;

//语音信息状态
typedef enum {
	VZ_VOICE_NOTYPE = 0,
	VZ_VOICE_IN,    //有效期内白名单
	VZ_VOICE_OUT,   //已过期
	VZ_VOICE_NA,    //不在白名单
	VZ_VOICE_IW,    //白名单剩余天数

	VZ_VOICE_STATUELEN    //状态数
}VZ_RS485_VOICE_STATUE;

//语音信息-白名单
typedef struct {
	int status;   //语音信息状态VZDEV_RS485_VOICE_STATUE
	int remain;   //剩余天数
	bool license;   //包含语音信息
	char prefix[36];  //语音前缀
	char suffix[36];  //语音后缀		
}VZ_RS485_VOICE_WL;

#define VZDEV_RS485_VOICE_LEN 4

//语音信息
typedef struct {
	VZ_RS485_VOICE_WL voiceWL[VZDEV_RS485_VOICE_LEN];
}VZ_RS485_VOICE;

#define RE485_PUSH_TYPE_LEN 22

// RS-485推送配置
typedef struct {
	VZ_RS485_ITEM configItem[RE485_PUSH_TYPE_LEN];  //推送项
	VZ_RS485_VOICE voice;   //语音信息
	char header[64];      //协议头
	char end[64];   //协议尾	
	bool voiceEnable;   //语音信息可用	
}VZ_RS485_Config;


typedef struct {
	char language[32];
	char *content;
	int content_len;
}VZ_LANGUAGE_CONTENT;

typedef struct {
	int e4g_num;
	int fan_num;
	int img_reset_num;
	int io_in_num;
	int io_out_num;
	int key_reset_num;
	int led_num;
	int moto_num;
	int ttl_num;
	int tty_num;
}VZ_DEVICE_CAPACITY;

typedef struct {
	int cam_sup_drawrect;
	int wifi;
	int g4g;
	int pdns;
	int io_alarm;
	int move_detect;
	int io_out_num;
	int io_in_num;
	int ttl_num;
	int rs485_num;
	int rs232_num;
}VZ_FACE_DEVICE_CAPACITY;

typedef struct {
	int priority;    // 优先级 1 有线优先 2 wifi优先
	int wifi_enable; // 0启用  1 不启用
}VZ_WIFI_CFG;

typedef struct {
	int wifi_enable;
	int priority;
	int status;
	char ssid[32];
	char apmc[32];
	int ip_way;
	char ip[16];
	char mask[16];
	char gateway[16];
	char dns[16];
}VZ_WIFI_PROPERTY;

// wifi搜索项 
#define MAX_WIFI_COUNT 64
typedef struct {
	char ssid[32];
	int quality;
	char apmac[32];
	int channel;
	int maxbitrate;
	int encry_mode;
}VZ_WIFI_ITEM;

typedef struct {
	VZ_WIFI_ITEM wifi_item[MAX_WIFI_COUNT];
	int wifi_count;
}VZ_WIFI_SEARCH_ITMES;

// wifi连接
typedef struct {
	int mode;
	char ssid[32];
	char pwd[32];
	int encry_type;
	int encry_mode;
	char apmac[32];
	int ip_way;
	char ip[16];
	char mask[16];
	char gateway[16];
	char dns[16];
	int status;
}VZ_LINK_WIFI_INFO;

// io开闸结果
#define MAX_IO_ITEM_COUNT 4
typedef struct
{
	int io;
	int ctrl_type;
}VZ_IO_ITME;

typedef struct
{
	int plate_id;							// 车牌id
	char plate[16];							// 车牌号
	int  wl_result;							// 白名单验证结果
	char time[32];							// 时间
	VZ_IO_ITME io_item[MAX_IO_ITEM_COUNT];  // io开闸信息

}VZ_IO_RESULT;

typedef struct
{
	int plate_id;							// 车牌id
	TH_PlateResult plate_result;            // 车牌结果
	VZ_IO_ITME io_item[MAX_IO_ITEM_COUNT];  // io开闸信息

}VZ_PLATE_IO_RESULT;

typedef struct
{
	int enable;			 // 是否输出清洗结果				
	int clean_time;      // 清洗时间,超过这个时间判断为已经清洗 单位秒
	int clean_timeout;   // 清洗超时时间, 超过这个时间,认为清洗时间过长了.单位秒

}VZ_CHECK_CLEAN_PARAM;

// 人脸图片数据
#define MAX_PIC_PAGE_SIZE 100
typedef struct
{
	char file_name[128];
	int event_type;
	int sub_type;
	char time[32];
}VZ_PIC_LIST_ITEM;

typedef struct
{
	int total_count;
	int record_count;
	VZ_PIC_LIST_ITEM pic_items[MAX_PIC_PAGE_SIZE]; 
}VZ_PIC_LIST_RESULT;

//人脸抓拍参数
typedef struct
{
	int generate_rate;	//目标生成帧数[1,5]：控制进入检测区域的人脸生成目标的速度，值越小，目标生成越快。对应检测算法的输出速度，可能会带来误报。
	int sensitivity;	//灵敏度[1,5]：灵敏度越大，越容易检测出人脸
	int capture_times;	//抓拍次数[1,10]：人脸进入检测区域到离开检测区域的过程中抓拍的次数
	int capture_interval;	//抓拍间隔, 100~10*1000 单位ms
	int enable_capture_interval; //是否开启间隔抓拍，1使得capture_interval有效，0则最后一张在人脸离开时输出
	int capture_threshold;	//抓拍评分阈值[1,20]，只有评分大于等于该阈值才输出
	int min_eye_distance;	//最小瞳距[20,150]，默认20，画面中的人脸瞳距大于等于该阈值才输出
	int max_eye_distance;	//最大瞳距
	int filter_time;		//人脸最短停留时间（秒），默认0
	char enable_bodydet; //人形检测开关
	char enable_caphead; //人头抓拍开关
	char enable_face_roi; //启用人脸ROI属性
	char enable_faceattr; //人脸属性开关
	char enable_facedet; //人脸抓拍开关
	char face_exposure;  //人脸曝光属性
	char image_quality; //大图的图像质量(1~9)
	char image_resolution; //大图的分辨率:10:1080p,9:720p
	short refer_brightness;//参考人脸亮度[1,100]
	short min_duration;    // 最小间隔时间

	// 400万相机独有参数
	char age_strategy;			// 年龄模式
	char downscale_img_encchnl; // 非0 初始化缩略图通道，并开启业务
	unsigned char hor_angle; // 水平角度
	unsigned char ver_angle; // 垂直角度
	unsigned char capture_scope; // 抓拍分数
	unsigned char capture_size; // 抓拍大小

	unsigned char reserved[14];	//预留
	//int enable_face_exposure;	//允许画面根据设定参考人脸亮度进行曝光调整
	//int refer_face_brightness;	//参考人脸亮度[1,100]
	//int duration_face_exposure;	//曝光调整后的持续时间（秒）
	//int image_quality;		//抓拍图像质量[10,100]
}
VZ_FACE_SNAPSHOT_PARAM;

// 结构化查询
#define MAX_FACE_RECORD_PAGE_SIZE 50
typedef struct {
	int sex;
	int age;
	int have_hat;
	int have_glasses;
	int have_mask;
}VZ_FACE_QUERY_CONDITION;

typedef struct
{
	int id;
	int trigger;
	int have_mask;
	char recg_time[32];
	int depend_id;
	int index;
	int feature_type;
	int confidence;
	int eye_dist;
	int sex;
	int age;
	int have_hat;
	int have_glasses;
	char ipc_serialnum[32];
	char *face_img_data;
	int face_img_len;
	char *feature_base64;
	int feature_len;

}VZ_FACE_RECORD_ITEM;

typedef struct
{
	int total_count;
	int record_count;
	int data_type;
	VZ_FACE_RECORD_ITEM record_items[MAX_FACE_RECORD_PAGE_SIZE]; 
}VZ_FACE_RECORD_RESULT;

// 区域计数配置参数
typedef struct
{
	int is_open;
	int is_osd;
	int is_alarm;
	int is_save_pic;
	int alarm_people_count;
	int alarm_internal;
	TH_FacePolygon area_polygons[MAX_RULE_POLYGON_COUNT];

}VZ_FACE_AREA_COUNT_PARAM;

// 区域计数配置参数
typedef struct
{
	int is_open;
	int is_osd;
	int is_draw;
	int is_alarm;
	int is_save_pic;
	int alarm_people_count;
	int alarm_internal;
	TH_FacePolygon area_polygons[MAX_RULE_POLYGON_COUNT];
	char reserved[128];						// 保留数据
}VZ_FACE_AREA_COUNT_PARAM_EX;

typedef struct tagTH_FacePolygon_V2
{
	unsigned char id;
	unsigned char enable;
	unsigned char point_num;
	int           alarm_people_count;
	TH_FacePoint  polygon_points[MAX_POLYGON_PT_COUNT];
	char reserved[64];						// 保留数据
}TH_FacePolygon_V2;

typedef struct
{
	int is_open;
	int is_osd;
	int is_draw;
	int is_alarm;
	int is_save_pic;
	int alarm_internal;
	int polygon_num;
	TH_FacePolygon_V2 area_polygons[MAX_RULE_POLYGON_COUNT_V2];
	char reserved[128];						// 保留数据
}VZ_FACE_AREA_COUNT_PARAM_V2;


//参数导入导出
#define  IMPORT_MAX_ITEM_NUM    64
#define  IMPORT_MAX_GROUP_NUM   64
typedef struct
{
    int is_selected;
	char key[64];
	int  kv;
	char item_name[64];
	char reserved[64];						// 保留数据
}VZ_PARAM_IMPORT_ITEM_V2;

typedef struct
{
    VZ_PARAM_IMPORT_ITEM_V2  items[IMPORT_MAX_ITEM_NUM];
	int  count;
	char group_name[64];
	int is_selected;
	char reserved[60];						// 保留数据
}VZ_PARAM_IMPORT_GROUP_V2;

typedef struct
{
    VZ_PARAM_IMPORT_GROUP_V2 groups[IMPORT_MAX_GROUP_NUM];
	int  count;
	char reserved[64];						// 保留数据
}VZ_PARAM_IMPORT_ABILITY_V2;


//设备信息
typedef struct {
	char    mac_addr[20];
	char    mac_addr2[20];
	char    serial_num[32];
	int     dev_type;
	VZ_FS_INFO_EX info_ex;
	char batch_number[20];
	char    reserved[88];
}VZ_HW_INFO;


typedef struct
{
	int input_vol;
	int output_vol;
	int audio_input;
	int noise_filter;
	int talk_io;
	int audio_output;
	char reserved[30];						// 保留数据
}VZ_AUDIO_PRM;


//////////////////////////////////////////////////////////////////////////
// begin 全智能相机相关

//设备信息
typedef struct {
	char    alg_ver[32];
	int     board_version;
	int     dev_type;
	unsigned long long exdata_size;
	int     exdata_checker;
	int     hw_flag;
	char    hw_version[20];
	char    mac_addr[20];
	char    oem_info[24];
	int     profocus_flag;
	char    serial_num[20];
	char    soft_ver[24];
	char    system_ver[52];
	int     write_status;
	int     parking_num;
	char    mac_addr2[20];
	int     replay_port;
	char    batch_number[20];
	char    reserved[84];
}VZ_FIC_DEVICE_INFO;

// 自动重启
typedef struct {
	int     enable;
	int     minute;
	char    wday[16];
}VZ_FIC_REBOOT_TIME;

// NTP校时
typedef struct {
	int     enable;
	int     cycle;
	char    server[64];
}VZ_FIC_NTP_CONFIG;

// 系统时间
typedef struct {
	char    datatime[32];
}VZ_FIC_SYSTEM_TIME;

// 网络参数
typedef struct {
	int     dhcp;
	char    ip[16];
	char    netmask[16];
	char    gateway[32];
	char    dns[16];
	char    dns2[16];
}VZ_FIC_NETWORK_CONFIG;

// 设备默认值
typedef struct {
	int     reset_level;
	char    source[16];
}VZ_FIC_RESET_FACTORY;

typedef struct {
	int    reserve; // 保留字段
}VZ_FIC_DEF_PARAM;

// 设备名称
typedef struct {
	char    title[32];
}VZ_FIC_DEVICE_NAME;

// 网络端口
typedef struct {
	int     http_port;
	int     rtsp_port;
}VZ_FIC_NETWORK_PORT;

#if 1
typedef struct {
	int     fmt_seconds;
	int     state;
	unsigned long long     pic_size;
	unsigned long long     pic_used;
	unsigned long long     rec_size;
	unsigned long long     rec_used;
	unsigned long long     size;
	unsigned long long     used;
}VZ_FIC_DISK_INFO;
#else
// 磁盘信息
#define MAX_FIC_DISK_PART_NUM   100
#define MAX_FIC_DISK_NUM        100
typedef struct {
	int     partstate;      // 磁盘状态:1=未格式化,2=未挂载,3=正在格式化,4=正在删除,5=工作正常,6=只读
	int     formatpercent;  // 格式化比例
	char    partname[32];   // 磁盘分区名
	int     total;          // 分区大小(MB)
	int     left;           // 分区剩余空间(MB)
	int     used;           // 分区使用空间(MB)
}VZ_FIC_DISK_PART;

typedef struct {
	char    devname[32];    // 磁盘名称
	int     devtotal;       // 磁盘总空间
	int     devtype;        // 磁盘类型:0=SD,1=USB
	int     partnum;
	VZ_FIC_DISK_PART parts[MAX_FIC_DISK_PART_NUM];
}VZ_FIC_DISK;

typedef struct {
	int     disknum;
	VZ_FIC_DISK parts[MAX_FIC_DISK_NUM];
}VZ_FIC_DISK_INFO;
#endif

// 格式化磁盘
typedef struct {
	int   pic;
}VZ_FIC_FORMAT_DISK;

// 删除磁盘数据
typedef struct {
	int    reserve; // 保留字段
}VZ_FIC_DELETE_DISK;

// VPN参数
typedef struct {
	int     enable;
	int     port;
	char    hostname[16];
	int     status;
}VZ_FIC_VPN_NETWORK;

// UPNP参数
typedef struct {
	int     enable;
	int     http_port;
	int     rtsp_port;
	int     status;
}VZ_FIC_UPNP_NETWORK;

// DDNS参数
typedef struct {
	int     enable;
	char    brandurl[32];  // ddns提供商
	char    name[32];      // 域名
	char    username[32];      // 用户名
	char    password[32];      // 密码
	int     status;
}VZ_FIC_DDNS_NETWORK;

// 4G参数
typedef struct {
	int     link_level;
	char    cloud_addr[32];     // 云服务器地址
	int     net_priority;       // 网络优先级
}VZ_FIC_4G_CONFIG;

// 时区参数
typedef struct {
	int     timezone;
}VZ_FIC_TIME_ZONE;

// 网络命令
typedef struct {
	char    cmd[64];
}VZ_FIC_NETWORK_MESSAGE;

// PDNS参数
typedef struct {
	int     enable;
	char    pdns_addr[16];
	int     pdns_port;
	int     is_connected;
	char    sn[128];
}VZ_FIC_PDNS_CONFIG;

// 用户信息
#define MAX_FIC_ACCOUNT_NUM 100
typedef struct {
	char    username[32];
	char    password[32];
	int     authority;
	int     signin_timeout;
	int     heartbeat_timeout;
	char    control[16];
	char    remote_id[16];
}VZ_FIC_ACCOUNT;

typedef struct {
	int accountnum;
	VZ_FIC_ACCOUNT account[MAX_FIC_ACCOUNT_NUM];
}VZ_FIC_ACCOUNT_INFO;

// 加密密码
typedef struct {
	char    key1[32];
	char    key2[32];
}VZ_FIC_KEY;

// 加密等级
typedef struct {
	char    key1[32];
	char    key2[32];
	int     encrypt_level;
}VZ_FIC_ENCRYPT_LEVEL;

// RS485参数
typedef struct {
	int     source;     // RS485-1\2\3
	int     baud_rate;  // 波特率
	int     parity_id;  // 校验位
	int     data_bits;  // 数据位
	int     stop_bits;  // 停止位
}VZ_FIC_RS485_PARAM;

// GPIO IN
typedef struct {
	int     source;
	int     gpio_in_status;
}VZ_FIC_GPIO_IN;

// GPIO OUT
typedef struct {
	int     source;
	int     gpio_out_status;
}VZ_FIC_GPIO_OUT;

// 二次开闸配置
typedef struct {
	int     enable;           // 是否启用
	int     gpioin_id;        // IO IN编号
	int     gpioout_id;       // IO OUT编号
	int     frequency_time;   // 间隔时间
	int     delay_stop_time;  // 延长输出时间
}VZ_FIC_REOPEN;

// 语音配置
#define MAX_FIC_VOICE_TIME_INV_LEVEL_NUM  100
typedef struct {
	int     voice_volume;
	char    start_time[12];
	char    end_time[12];
}VZ_FIC_VOICE_TIME_INV_LEVEL;

typedef struct {
	int     voice_type;
	char    greetings[32];
	int     start_mode;
	char    tag[32];
	int     voice_interval;
	int     voice_male;
	int     number;
	VZ_FIC_VOICE_TIME_INV_LEVEL voice_time_inv_level[MAX_FIC_VOICE_TIME_INV_LEVEL_NUM];
}VZ_FIC_VOICE_INFO;

/*
enum VZ_LENSTYPE        //镜头类型
{
	VZ_LENS_NONE = 0,   //非定焦镜头，无需矫正
	VZ_LENS_4MM,        //4mm定焦镜头
	VZ_LENS_6MM,        //6mm定焦镜头
	VZ_LENS_8MM,        //8mm定焦镜头
	VZ_LENS_12MM,        //12mm定焦镜头
	VZ_LENS_16MM,        //16mm定焦镜头
};
*/

// 录像文件列表查询
#define MAX_FIC_RECORD_VIDEO_NUM  100
typedef struct {
	char    file_name[200];
	int     event_type;
	int     sub_type;
	char    time[20];
}VZ_FIC_RECORD_VIDEO;

typedef struct {
	int     total;
	int     res_size;
	VZ_FIC_RECORD_VIDEO record[MAX_FIC_RECORD_VIDEO_NUM];
}VZ_FIC_RECORD_VIDEO_INFO;

typedef struct {
	int     source;
	int     gpio_out_status;
	int     out_delay_times;
}VZ_FIC_CONTROL_GPIOOUT;

// 
#define MAX_FIC_TRIGGER_NUM	8
typedef struct {
	int		reco_flag;
	char	plate_str[22];
	short	car_pos;
	int		car_loc_left;
	int		car_loc_right;
	int		car_loc_top;
	int		car_loc_bottom;
	int		reco_id;
	int		plate_type;
	int		plate_color;
	int		group_id;
	int		zone_id;
	char    zone_name[32];
	int		parking_state;
	int		plate_loc_left;
	int		plate_loc_right;
	int		plate_loc_top;
	int		plate_loc_bottom;
	int		time_s;
	int		time_ms;
	char		reco_time[20];
	char*		big_img_path;
	char*		small_img_path;
	unsigned char* img_data;
	char*		car_img_path;
	int		img_len;
	int     trigger_zone_id;
	char    user_data[20];
	char reserved[232];
}VZ_FIC_PLATE_INFO;

#define MAX_ZONE_COUNT	8
typedef struct {
	int     zone_id[MAX_ZONE_COUNT];
	int     zone_status[MAX_ZONE_COUNT];
	int     zone_num;
}VZ_FIC_ZONE_STATE;

typedef struct {
	int		trigger_type;
	int		result_num;
	VZ_FIC_PLATE_INFO result[MAX_FIC_TRIGGER_NUM];
}VZ_FIC_ROAD_TRIGGER_RESULT;

typedef struct {
	BYTE            byEnable;
	BYTE            byDraw; 
	unsigned        uNumVertex;
	BYTE            byRes1;
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<自定义名称*/
	VZ_LPRC_VERTEX  struVertex[VZ_LPRC_ROI_VERTEX_NUM_EX]; 
}
VZ_FIC_ZONE_AREA_ITEM;

typedef struct {
	unsigned        uNumZone; 
	VZ_FIC_ZONE_AREA_ITEM zone_items[MAX_ZONE_COUNT]; 
}
VZ_FIC_ROAD_RULE_PARAM;

#define FIC_OSDTEXTLEN				64
#define MAX_FIC_OSD_TEXT_COUNT		8
typedef struct
{
	unsigned char	nTextEnable;					///<  0 off 1 on
	int				nTextPositionX;   				///<  text position
	int				nTextPositionY;   				///<  text position
	char			overlaytext[FIC_OSDTEXTLEN];	///<  user define text
}VZ_FIC_OSD_TEXT;


//-----------OSD----------------
typedef struct
{
	unsigned char	dstampenable;						// 0 off 1 on
	int				dateFormat;							// 0:YYYY/MM/DD;1:MM/DD/YYYY;2:DD/MM/YYYY
	int				datePosX;
	int				datePosY;
	unsigned char	tstampenable;   					// 0 off 1 on
	int				timeFormat;							// 0:12Hrs;1:24Hrs
	int				timePosX;
	int				timePosY;
	VZ_FIC_OSD_TEXT osd_text[MAX_FIC_OSD_TEXT_COUNT];
}VZ_FIC_USER_OSD_PARAM;


//-----------ZONE----------------
#define MAX_ZONE_RECORD_COUNT 50
typedef struct
{
	int depend_id;
	char file_name[128];
	int group_id;
	int id;
	int index;
	short loc_bottom;
	short loc_left;
	short loc_right;
	short loc_top;
	int park_state;
	char plate[16];
	char plate_color;
	char plate_type;
	unsigned int recg_time;
	unsigned int recg_time_ms;
	int reco_flag;
	int reco_id;
	char reco_time[32];
	char trigger;
	int zone_id;
	char reserved[64];
}VZ_FIC_ZONE_ITEM;

typedef struct
{
	VZ_FIC_ZONE_ITEM record_items[MAX_ZONE_RECORD_COUNT];
	int total_count;
	int record_count;

}VZ_FIC_QUERY_ZONE_RESULT;

typedef struct
{
	int zone_id;
	int light_color;

}VZ_FIC_LIGHT_PARAM;

typedef struct
{
	int led_type;                           // 类型   1：系统状态灯 2：补光灯  3：颜色灯 4：4G状态灯 5：网络接通指示灯 6：红外灯 7：爆闪灯 8：外接灯
	int led_group;                          // 分组   
	int color;								// 颜色
	int level;                              // 亮度等级
	char reserved[30];						// 保留数据
}VZ_FIC_LIGHT_PARAM_V2;

typedef struct
{
	int etc_mode;
	int etc_port;
	char etc_ip[32];

}VZ_ETC_CONFIG_PARAM;

typedef struct
{
	int sensor_id;
	int dir_cmd;
	int degree;

}VZ_LPR_PTZ_PARAM;

//-----------全智能报警----------------
typedef enum _COMMON_ALARM_RESULT_TYPE{
	COMMON_ALARM_UNDEFINE = 0,			      // 未定义结果
	COMMON_ALARM_FACE_RECONITION = 1,         // 人脸识别报警结果
	COMMON_ALARM_FACE_SNAP,                   // 人脸抓拍报警结果
	COMMON_ALARM_HUMAN,                       // 人形抓拍报警结果
	COMMON_ALARM_CAR,                         // 车型抓拍报警结果
	COMMON_ALARM_NONVEHICLE,                  // 非机动车报警结果
	COMMON_ALARM_AREA_COUNT,                  // 区域密度报警结果
	COMMON_ALARM_GATERING,                    // 人群聚集报警结果
	COMMON_ALARM_LIFT_DETECT,                 // 电梯检测报警结果
	COMMON_ALARM_LANE_CONTROL,                // 车道布控报警结果
	COMMON_ALARM_MANUALLY_CAPTURE,            // 手动抓拍结果
	COMMON_ALARM_VEHICLE_VIOLATION,           // 车辆违章报警结果
	COMMON_ALARM_CHAIN_INFO,                  // 路侧相机证据链结果
	COMMON_ALARM_ROAD_RESULT,                 // 路侧识别结果
	COMMON_ALARM_EBICK_ILLEGAL,               // 非机动车违章结果
	
	COMMON_ALARM_MAX_NUM
}COMMON_ALARM_RESULT_TYPE;

// end 全智能相机相关



//////////////////////////////////////////////////////////////////////////
// begin 盒子相关参数

#define MAX_CHANNEL_COUNT 128
typedef struct
{
	char group_name[32];
	char alg_chn_id;
    unsigned char alg_status;
	unsigned char alg_type_bits;
	unsigned char chn_id;
	unsigned char conn_status;
	unsigned char enable_snaps;
	unsigned char  enable_video;
	unsigned int http_port;
	char ip[32];
	char name[200];
	char password[32];
	char username[32];
	unsigned char remote_alg_type;
	unsigned int rtsp_port;
	char rtsp_url[128];
	char rtsp_url_sub[128];
	char type[32];
	
}VZ_BOX_CAM_ITEM;

typedef struct
{
	VZ_BOX_CAM_ITEM cam_items[MAX_CHANNEL_COUNT];
	int cam_count;

}VZ_BOX_CAM_GROUP;

//向盒子添加相机的参数
typedef struct
{
	char ip[32];		//IP地址
	char name[32];		//用户自定义的相机名称
	char type[28];		//相机类型: "rtsp" / "vz" / "onvif"
	int dev_type;		//相机类型 int值(21代表人脸门禁)
	char username[32];	//如果相机类型为 "vz"或"onvif" 则需要用户名密码
	char password[32];	//登录密码
	char rtsp_url[128];		//如果相机类型为 "rtsp"，则需要输入 RTSP的主子码流地址
	char rtsp_url_sub[128];	//RTSP子码流
	unsigned int http_port;		//HTTP端口号（默认80）
	unsigned int rtsp_port;		//RTSP端口号（默认8557）
	unsigned char enable_snaps;	//对于"vz"的抓拍机，允许接受相机的截图，用于盒子的基于图片流的智能算法
	unsigned char enable_video;	//允许接受相机的视频流，用于盒子的转发与基于视频流的智能算法
}
VZ_BOX_CAM_INFO;

#define MAX_FACE_USER_COUNT 25
typedef struct
{
	char card_number[32];
	int card_type;
	char db_name[32];
	int face_id;
	int pic_index;
	char group_id[32];
	char phone[16];
	char *pic_data;
	int pic_len;
	char province[32];
	char city[16];
	double score;
	int sex;
	int user_type;
	char birthday[16];
	char address[64];
	char user_id[20];
	char reserved_id[4];
	char user_reserved[40];
	char user_info[64];
	char user_name[64];
	char user_remark[128];
	char img_url[128];
	                      
	// 人脸门禁设备
	int role;				       //人员角色，0：普通人员。 1：白名单人员。 2：黑名单人员。-1：所有人员。
	unsigned int effectTime;       //有效期截止时间，该人员信息在该时间内有效,从1970年1月1日0时0分0秒到截止时间的秒数（0xFFFFFFFF表示永久有效，0表示永久失效）
	unsigned int effectStartTime;  //有效期起始时间，该人员信息在该时间之后有效,从1970年1月1日0时0分0秒到起始时间的秒数（0表示未初始化）
	char idcardNum[24];			   //韦根号,智能卡号(可选)
	char usr_record_time[20];      // 人脸识别时间
	int usr_tag;				   // 用户标识
	char reserved[68];


}VZ_FACE_USER_ITEM;

typedef struct
{
	VZ_FACE_USER_ITEM face_items[MAX_FACE_USER_COUNT];
	int face_count;
	int total_count;

}VZ_FACE_USER_RESULT;

typedef struct
{
	char card_number[32];  // "" 空字符串忽略
	int card_type;         // 0:忽略 1:身份证 2:学生证 3:护照 4:其他
	char province[16];     // "" 空字符串忽略
	char city[16];         // "" 空字符串忽略
	int sex;               // -1:忽略  0: 男 1：女
	int user_type;         // 暂时未启用
	char birthday_start[16]; // "" 空字符串忽略
	char birthday_end[16];   // "" 空字符串忽略
	char user_name[64];      // "" 空字符串忽略
	char usr_record_time_s[20]; // "" 空字符串忽略
	char usr_record_time_e[20]; // "" 空字符串忽略
	int usr_tag;
	char reserved[84];
	int page_num;
	int page_count;

}VZ_FACE_LIB_SEARCH_CONDITION;


#define MAX_FACE_LIB_COUNT 120
typedef struct
{
	int threshold_value;
	int id;
	int enable;
	int lib_type;
	char name[32];
	char remark[64];
	char reserved[128];

}VZ_FACE_LIB_ITEM;

typedef struct
{
	VZ_FACE_LIB_ITEM lib_items[MAX_FACE_LIB_COUNT];
	int lib_count;

}VZ_FACE_LIB_RESULT;

typedef struct
{
	int offline_check;          // 脱机检查，0：关闭，1：开启
	int resend_times;			// 重发次数
	int mserver_status;			// 主服务器优先，0：不优先，1：优先
	char server_ip[32];			// 主服务器地址
	int server_port;			// 主服务器端口
	int timeout;				// 超时时间
	char server_ip_ext1[32];	// 备选服务器
	int ssl_enable;				// 是否启用ssl
	int ssl_port;				// SSL使用端口号
	int ca_enable;				// 是否使用证书
	char reserved[128];

}VZ_HTTP_PUSH_BASE_CFG;

typedef struct
{
	int reg_heart_mode;          // 心跳模式 0：取消心跳，1：普通心跳，2：comet轮询
	char reg_url[96];			 // 心跳推送地址

	int ivs_rlt_enable;			 // 抓拍结果推送 
	char ivs_rlt_url[96];		 // 抓拍结果推送地址
	int ivs_rlt_detail_level;    // 详细等级 0：全部，1：详细，2：简略，3：极简
	int ivs_rlt_img_mode;        // 图片模式 1 背景图 2 人脸图 4 背脸图 8 人形图 16 识别图
	int ivs_enable_resume;

	int area_trip_enable;		 // 推送绊线统计数据 
	char area_trip_url[96];		 // 绊线统计推送地址
	int area_trip_internal;      // 推送间隔时间(0-30)

	int area_count_enable;		 // 推送区域计数数据 
	char area_count_url[96];	 // 区域计数推送地址
	int area_count_internal;     // 推送间隔时间(0-30)
	int area_count_detail_level; // 详细等级 0：无图，1：背景图

	char reserved[128];

}VZ_BOX_HTTP_PUSH_PARAM;

//系统模块全局开关
typedef enum
{
	VZ_BOX_ALL_MOD_SWITCH,
	VZ_BOX_ALG_SWITCH,
	VZ_BOX_WEB_SWITCH,
}
VZ_BOX_SYS_MOD_SWITCH;


//授权参数
#define MAX_BOX_AUTH_LIST 100

typedef struct
{
	char auth_time_start[16];			          // 授权开始时间   hh:mm:ss
	char auth_time_end[16];			              // 授权结束时间
	char auth_ip_list[MAX_BOX_AUTH_LIST][32];	  // 授权设备白名单
	int  list_count;
}VZ_BOX_AUTH_PARAM;

// end   盒子相关参数
//////////////////////////////////////////////////////////////////////////

// 命令类型
// 车牌识别相机参数
#define VZ_PLATE_GET_MANU_RESULT_PARAM 1001
#define VZ_PLATE_SET_MANU_RESULT_PARAM 1002

// 用于判断是否为C相机
#define  VZ_GET_LPR_DEVICE_TYPE        1003  

// 获取当前系统的语言
#define  VZ_GET_SYS_LANGUAGE           1004

// 获取语言的内容
#define  VZ_GET_LANGUAGE_CONTENT       1005    

// 获取rtsp端口号
#define  VZ_GET_RTSP_PORT              1006

// 获取编码属性
#define  VZ_GET_ENCODE_PROP            1007

// 获取LED亮度等级
#define  VZ_GET_LED_PROP               1008

// 获取硬件能力
#define  VZ_GET_DEVICE_CAPACITY        1009

// 设置wifi参数
#define  VZ_SET_WIFI_CFG               1010

// 获取wifi的属性
#define  VZ_GET_WIFI_PROPERTY          1011

// 获取当前范围的wifi
#define  VZ_GET_WIFI_ITEMS             1012

// 设置车辆清洗检测参数
#define  VZ_SET_CHECK_CLEAN_PARAM      1013

// 获取rtsp url
#define  VZ_GET_RTSP_URL               1014

// 获取子码流rtsp url
#define  VZ_GET_SUB_RTSP_URL           1015

// 获取双屏相机第二路线圈参数
#define  VZ_GET_VIRLOOP_SECOND_PARA    1016

// 设置双屏相机第二路线圈参数
#define  VZ_SET_VIRLOOP_SECOND_PARA    1017

// 获取双屏相机第二路识别区域
#define  VZ_GET_REGION_SECOND_PARA     1018

// 设置双屏相机第二路识别区域
#define  VZ_SET_REGION_SECOND_PARA     1019

// 获取是否支持etc功能
#define  VZ_GET_ETC_ENABLE			   1020

// 获取etc配置
#define  VZ_GET_ETC_CONFIG			   1021

// 设置etc配置
#define  VZ_SET_ETC_CONFIG			   1022

// 云台操作
#define  VZ_SET_PTZ_PARA			   1023

// 获取子码流rtmp url
#define  VZ_GET_RTMP_URL               1024


// 人脸相机参数
#define VZ_FACE_GET_VIDEO_PARAM						3001
#define VZ_FACE_SET_VIDEO_PARAM						3002

#define VZ_FACE_GET_SD_INFO							3003

#define VZ_FACE_GET_AREA_FLOW_STATISTIC 			3004
#define VZ_FACE_SET_AREA_FLOW_STATISTIC				3005

#define VZ_FACE_SET_CVBS_CTRL						3006
#define VZ_FACE_GET_CVBS_CTRL						3007

#define VZ_FACE_SET_AUDIO_CTRL						3008
#define VZ_FACE_GET_AUDIO_CTRL						3009

// 夜间模式切换接口
#define VZ_FACE_SET_VIDEO_PARAMS					3010

#define VZ_FACE_GET_SUP_DRAWRECT					3011

#define VZ_FACE_GET_DEVICE_CAPACITY                 3012

// 区域计数的接口
#define VZ_FACE_SET_AREA_COUNT_PARAM                3013

#define VZ_FACE_GET_AREA_COUNT_PARAM                3014

#define VZ_FACE_SET_CAMERA_LENS                     3015

#define VZ_FACE_GET_CAMERA_LENS                     3016

// 开启安装向导
#define VZ_FACE_SET_GUIDE_CTRL                      3017

// 设置人脸缓存个数
// 用于获取最一段时间内保存的最佳结果
#define VZ_FACE_SET_CACHE_COUNT                     3019

// 拌线计数
#define VZ_FACE_GET_AREA_FLOW_STATISTIC_EX 			3020
#define VZ_FACE_SET_AREA_FLOW_STATISTIC_EX			3021
// 区域计数的接口
#define VZ_FACE_SET_AREA_COUNT_PARAM_EX             3022
#define VZ_FACE_GET_AREA_COUNT_PARAM_EX             3023

// 参入导入导出的接口
#define VZ_GET_IMPORT_PARAM_ABILITY_EX              3024

// 区域计数的接口
#define VZ_FACE_SET_AREA_COUNT_PARAM_V2             3025
#define VZ_FACE_GET_AREA_COUNT_PARAM_V2             3026

//人脸识别区域 
#define VZ_FACE_SET_RULE                            3027
#define VZ_FACE_GET_RULE                            3028

//人脸屏蔽区域 
#define VZ_FACE_SET_SHIELD_AREA                     3029
#define VZ_FACE_GET_SHIELD_AREA                     3030

//音频参数通用
#define VZ_SET_AUDIO_PARAM						    3031
#define VZ_GET_AUDIO_PARAM							3032

//是否支持lens设置
#define VZ_FACE_GET_CAMERA_LENS_SUPPORT             3033

//////////////////////////////////////////////////////////////////////////
// begin 全智能相机相关
#define VZ_FIC_GET_DEVICE_INFO                      4001    // 获取设备信息
#define VZ_FIC_SET_REBOOT_TIME                      4002    // 设置自动重启
#define VZ_FIC_GET_REBOOT_TIME                      4003    // 获取自动重启
#define VZ_FIC_SET_NTP_CONFIG                       4004    // 设置NTP校时
#define VZ_FIC_GET_NTP_CONFIG                       4005    // 获取NTP校时
#define VZ_FIC_SET_SYSTEM_TIME                      4006    // 设置系统时间
#define VZ_FIC_GET_SYSTEM_TIME                      4007    // 获取系统时间
#define VZ_FIC_SET_NETWORK_CONFIG                   4008    // 设置网络参数
#define VZ_FIC_GET_NETWORK_CONFIG                   4009    // 获取网络参数
#define VZ_FIC_SET_DEF_PARAM                        4010    // 设置用户默认值
#define VZ_FIC_SET_RESET_FACTORY                    4011    // 恢复设备默认值
#define VZ_FIC_SET_DEVICE_NAME                      4012    // 设置设备名称
#define VZ_FIC_GET_DEVICE_NAME                      4013    // 获取设备名称
#define VZ_FIC_SET_NETWORK_PORT                     4014    // 设置网络端口
#define VZ_FIC_GET_NETWORK_PORT                     4015    // 获取网络端口
#define VZ_FIC_GET_DISK_INFO                        4016    // 获取磁盘信息
#define VZ_FIC_SET_FORMAT_DISK                      4017    // 格式化磁盘
#define VZ_FIC_SET_DELETE_DISK                      4018    // 删除磁盘数据
#define VZ_FIC_GET_VPN_NETWORK                      4019    // 获取VPN参数
#define VZ_FIC_SET_VPN_NETWORK                      4020    // 设置VPN参数
#define VZ_FIC_GET_UPNP_NETWORK                     4021    // 获取UPNP参数
#define VZ_FIC_SET_UPNP_NETWORK                     4022    // 设置UPNP参数
#define VZ_FIC_GET_DDNS_NETWORK                     4023    // 获取DDNS参数
#define VZ_FIC_SET_DDNS_NETWORK                     4024    // 设置DDNS参数
#define VZ_FIC_GET_4G_CONFIG                        4025    // 获取4G参数
#define VZ_FIC_SET_4G_CONFIG                        4026    // 设置4G参数
#define VZ_FIC_GET_TIME_ZONE                        4027    // 获取时区参数
#define VZ_FIC_SET_TIME_ZONE                        4028    // 设置时区参数
#define VZ_FIC_SEND_NETWORK_MESSAGE                 4029    // 发送网络命令
#define VZ_FIC_GET_PDNS_CONFIG                      4030    // 获取PDNS参数
#define VZ_FIC_SET_PDNS_CONFIG                      4031    // 设置PDNS参数
#define VZ_FIC_GET_ACCOUNT                          4032    // 获取用户信息
#define VZ_FIC_SET_ACCOUNT                          4033    // 设置用户信息
#define VZ_FIC_MODIFY_KEY                           4034    // 修改加密密码
#define VZ_FIC_RESET_KEY                            4035    // 重置加密密码
#define VZ_FIC_MODIFY_ENCRYPT_LEVEL                 4036    // 修改加密等级
#define VZ_FIC_SET_RS485_PARAM                      4037    // 设置RS485参数
#define VZ_FIC_GET_RS485_PARAM                      4038    // 获取RS485参数
#define VZ_FIC_GET_GPIO_IN                          4039    // 获取GPIO IN状态
#define VZ_FIC_GET_GPIO_OUT                         4040    // 获取GPIO OUT状态
#define VZ_FIC_SET_REOPEN                           4041    // 设置二次开闸配置
#define VZ_FIC_GET_REOPEN                           4042    // 获取二次开闸配置
#define VZ_FIC_SET_VOICE_CONFIG                     4043    // 设置语音配置
#define VZ_FIC_GET_VOICE_CONFIG                     4044    // 获取语音配置
#define VZ_FIC_GET_RECORD_VIDEO                     4045    // 录像文件列表查询
#define VZ_FIC_SET_CONTROL_GPIOOUT                  4046    // 开闸控制
#define VZ_FIC_GET_VIDEO_MODE                       4047    // 获取视频模式 0正常模式 1走廊模式
#define VZ_FIC_GET_ENCRYPT_LEVEL                    4048    // 获取加密等级
#define VZ_FIC_GET_RECORD_PORT						4049    // 获取录像端口
 
#define VZ_FIC_SET_LIGHT_CONTROL					4050    //全智能设置灯状态
#define VZ_FIC_GET_DEVICE_DRAW                      4051    //设备端绘制
// end 全智能相机相关
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// begin 路侧相机相关
#define VZ_ROAD_GET_ROAD_RULE_PARAM                 5001    // 获取路侧配置参数
#define VZ_ROAD_SET_EVS_LIGHT_CONTROL               5002    // 设置灯光模式、控制指示灯
// end  路侧相机相关
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// begin 盒子相关
#define VZ_BOX_GET_AUTH_PARAM                       6001    // 获取盒子授权信息
#define VZ_BOX_SET_AUTH_PARAM                       6002    // 设置盒子授权信息

// end  盒子相关
//////////////////////////////////////////////////////////////////////////


#ifdef WIN32

/**设备句柄，由VzLPRClient_Open获得，设备操作相关的函数都需要*/
typedef int VzClientHandle;
#define VzLPRClientHandle VzClientHandle
#ifdef _DEV_API_
#define VZ_API extern "C" __declspec(dllexport)
#else
#define VZ_API extern "C" __declspec(dllimport)
#endif

#define VZ_DEPRECATED __declspec(deprecated)
#define __STDCALL __stdcall
#else
#define VZ_API __attribute__((visibility("default")))
// #define VZ_API
#define VZ_DEPRECATED
#define __STDCALL
typedef long VzClientHandle;
#define VzLPRClientHandle VzClientHandle
#endif

//==============接口参数定义 end=============
#endif
