#ifndef SRC_LIB_INCLUDE_VZLPRCLIENTSDKDEFINE_H_
#define SRC_LIB_INCLUDE_VZLPRCLIENTSDKDEFINE_H_

#include <VzClientSDK_CommonDefine.h>
#include <VzClientSDK_LPDefine.h>
#include <VzClientSDK_FaceDefine.h>

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

typedef enum _IMG_SIZE_MODE {
  IMG_MODE_NONE = 0,
  IMG_MODE_CIF,
  IMG_MODE_D1,
  IMG_MODE_720P
}IMG_SIZE_MODE;

#define LPRC_OEM_INFO_SIZE 7
#define LPRC_HW_VERSION_SIZE 4
typedef struct _VZ_FS_INFO_EX {
  char reserved;
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
#define LPRC_MAX_MANU_PLATE_COUNT 50

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

// 结构化查询
#define MAX_FACE_RECORD_PAGE_SIZE 100
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

enum VZ_LENSTYPE        //镜头类型
{
	VZ_LENS_NONE = 0,   //非定焦镜头，无需矫正
	VZ_LENS_4MM,        //4mm定焦镜头
	VZ_LENS_6MM,        //6mm定焦镜头
	VZ_LENS_8MM,        //8mm定焦镜头
	VZ_LENS_12MM,        //12mm定焦镜头
	VZ_LENS_16MM,        //16mm定焦镜头
};

// 录像文件列表查询
#define MAX_FIC_RECORD_VIDEO_NUM  100
typedef struct {
	char    file_name[180];
	char    end_time[20];
	int     event_type;
	int     sub_type;
	char    time[20];
}VZ_FIC_RECORD_VIDEO;

typedef struct {
	int     total;
	int     res_size;
	VZ_FIC_RECORD_VIDEO record[MAX_FIC_RECORD_VIDEO_NUM];
}VZ_FIC_RECORD_VIDEO_INFO;

#define MAX_CAR_INFO_LEN  32

typedef struct {
	int logo_id;
	char car_logo[MAX_CAR_INFO_LEN];
	int series_id;
	char car_series[MAX_CAR_INFO_LEN];
	int style_id;
	char car_style[MAX_CAR_INFO_LEN];
	char reserved[128];

}VZ_CAR_INFO;

typedef struct
{
	unsigned		img_format;	   // 图片格式(0: jpg)
	unsigned char	*buffer;	   // 图片内存的首地址
	unsigned int    img_len;       // 图片数据大小
	char            img_info[32];  // 图像信息,比如名称等
	char            reserved[128]; // 预留
}
VZ_IMAGE_INFO;


/**登录信息*/
typedef struct {
	char dev_ip[64];		// 设备或云服务IP地址
	int  dev_port;			// 设备的端口号
	char username[32];      // 访问设备所需用户名
	char password[32];      // 访问设备所需密码
	int  timeout;           // 超时时间(单位毫秒，如超时时间为5秒时，填5000)
	int protocol_type;      // 网络协议(0:http, 1:https)
	int network_type;       // 网络类型(0:局域网,1:外网-PDNS方式, 2:外网-BIND方式, 3:新臻云平台方式)
	
	// 外网参数
	int http_port;          // 外网端口
	char sn[20];            // 设备序列号
	char extern_ip[16];		// 本地局域网内设备IP地址
	char ak_id[36];         // 云平台登录id
	char ak_secret[36];     // 云平台登录密码
	BYTE dwRes[128];        // 保留
}VZ_LPRC_LOGIN_PARAM;

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

// 获取车辆信息
#define  VZ_GET_CAR_INFO               1201

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

// 镜头参数操作
#define VZ_FACE_SET_CAMERA_LENS                     3015

#define VZ_FACE_GET_CAMERA_LENS                     3016

// 开启安装向导
#define VZ_FACE_SET_GUIDE_CTRL                      3017


#ifdef WIN32

/**设备句柄，由VzLPRClient_Open获得，设备操作相关的函数都需要*/
typedef int VzLPRClientHandle;
#ifdef _DEV_API_
#define VZ_LPRC_API extern "C" __declspec(dllexport)
#else
#define VZ_LPRC_API extern "C" __declspec(dllimport)
#endif

#define VZ_DEPRECATED __declspec(deprecated)
#define __STDCALL __stdcall
#else
#define VZ_LPRC_API __attribute__((visibility("default")))
// #define VZ_LPRC_API
#define VZ_DEPRECATED
#define __STDCALL
typedef long VzLPRClientHandle;
#endif



#endif  // SRC_LIB_INCLUDE_VZLPRCLIENTSDKDEFINE_H_

