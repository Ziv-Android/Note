#ifndef ALG_INTERFACE_H
#define ALG_INTERFACE_H

#include "vz_comm.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IVS_I2S(int_val, total) \
  ((short)(((int)(int_val) << 14) / ((int)(total))))
#define IVS_S2I(short_val, total) \
  (((int)(short_val) * (total) + (1 << 13)) >> 14)

//// 由算法定义
////// user type definition, which will be used in the whole project
//////////////////////
typedef enum {
  VZ_FRAME_FORMAT_RGB = 0,            // RGBRGBRGB...
  VZ_FRAME_FORMAT_BGR = 1,            // BGRBGRBGR...
  VZ_FRAME_FORMAT_YUV422 = 2,         // YYYY...UU...VV..  (YV16)
  VZ_FRAME_FORMAT_YUV420COMPASS = 3,  // YYYY...UV...    (NV12)
  VZ_FRAME_FORMAT_YUV420 = 4,         // YYYY...U...V...  (YU12)
  VZ_FRAME_FORMAT_UYVY = 5,           // UYVYUYVYUYVY...  (UYVY)
  VZ_FRAME_FORMAT_NV21 = 6,           // YYYY...VU...    (NV21)
  VZ_FRAME_FORMAT_YV12 = 7,           // YYYY...V...U    (YV12)
  VZ_FRAME_FORMAT_YUYV = 8,           // YUYVYUYVYUYV..  (YUYV)
  VZ_FRAME_FORMAT_MAX
} VZ_FRAME_FORMAT;

typedef enum {
  VZ_CROSS_BOTH_DIRECTION = 0,
  VZ_CROSS_LEFT_TO_RIGHT_DIRECTION = 1,
  VZ_CROSS_RIGHT_TO_LEFT_DIRECTION = 2,
} VZ_CROSS_DIRECTION;

typedef enum {
  VZ_TRIGGER_DIR_LEFT = 1,
  VZ_TRIGGER_DIR_RIGHT = 2,
  VZ_TRIGGER_DIR_UP = 3,
  VZ_TRIGGER_DIR_DOWN = 4,
} VZ_TRIGGER_DIRECTION;

typedef struct {
  VZ_S16 x;
  VZ_S16 y;
} VZ_Point;

typedef struct {
  VZ_Point start;
  VZ_Point end;
} VZ_Line;

typedef struct {
  VZ_S32 x;
  VZ_S32 y;
  VZ_S32 width;
  VZ_S32 height;
} VZ_Rect;

/**矩形区域信息*/
typedef struct TH_RECT {
  int left;   /**<左*/
  int top;    /**<上*/
  int right;  /**<右*/
  int bottom; /**<下*/
} TH_RECT;

typedef struct TH_TimeVal {
  long tv_sec;        /* 秒 */
  long tv_usec;       /* 微秒 */
  long tv_frameStamp; /* 帧编号 */
} TH_TimeVal;
typedef struct {
  unsigned uTVSec;
  unsigned uTVUSec;
} VZ_TIMEVAL;

#define VZ_POLYGN_POINTS_COUNTS_MAX 15
typedef struct {
  VZ_U32 u32PointsCounts;
  VZ_Point stPoints[VZ_POLYGN_POINTS_COUNTS_MAX];
} VZ_Polygn;

//////////////////////// 算法接口 ==> 初始化相关
//////////////////////////////////////
#define VZ_MODEL_FILE_NAME_LEN_MAX 128  // 模型文件名长度最大值
#define VZ_MODEL_FILE_COUNTS_MAX 128    // 最多载入模型文件数量
#define VZ_MODEL_FILE_HEADER_SIZE 18432  // 单个模型文件头大小限制,1024B 对齐
typedef struct {
  VZ_U8 u8ModelName[VZ_MODEL_FILE_NAME_LEN_MAX];  // 模型文件名
  // VZ_U8        *pu8ModelData;                            //
  // 模型数据地址,亦可以通过offset计算
  VZ_U32 u32ModelSize;    // 模型文件大小
  VZ_U32 u32ModelOffset;  // 模型文件在整个加载内存中的偏移地址
} VZ_Model;
typedef struct {
  VZ_U32 u32ModelCounts;                       // 加载的模型文件计数
  VZ_Model stModel[VZ_MODEL_FILE_COUNTS_MAX];  // 模型文件的详细信息
  VZ_U8* pu8ModelPtr;                          // 模型文件首地址
  VZ_U32 u32ModelTotalSize;                    // 模型文件总长度
} VZ_ModelInfo;

typedef enum {
  ALG_MODE_CN = 1 << 0,                 //国内通用版本
  ALG_MODE_EN_UNIVERSAL = 1 << 1,       //海外通用版本
  ALG_MODE_EN_HONGKONG = 1 << 2,        //海外香港版本
}VZ_AlgMode;
typedef struct {
  VZ_U32 u32MaxFrameWidth;              // 输入图像最大宽度
  VZ_U32 u32MaxFrameHeight;             // 输入图像最大高度
  // VZ_ModelInfo  stModelInfo;         // 模型文件
  VZ_U8* modelPtr;                      // 模型文件首地址
  VZ_U32 alg_mode_mask;                 // 算法模式mask, VZ_AlgMode枚举值.默认0 为 国内通用算法版本
  // VZ_U8         modelVersion[128]; //模型版本号
} VZ_AlgInitParams;

////////////////////// 算法接口 ==> 输入图像帧及封装头部相关信息
////////////////////////////////
#define VZ_VIDEO_BUF_SUPPORT_MAX 3   //最多同时输入视频帧
#define VZ_ENCRYPT_DATA_LEN 32       //加密数据长度
#define VZ_ENCRYPT_KEY_LEN 8         //加密KEY长度
#define VZ_RECOG_AREA_POINTS_MAX 20  //识别区域支持的最大点数
#define VZ_VIR_LOOP_POINTS_MAX 4     //虚拟线圈支持的最大点数

typedef struct {
  VZ_U32 u32Offset;               //暂未使用
  VZ_U32 u32FrameSize;            //图像占用空间大小
  VZ_U32 u32FrameWidth;           //图像宽度
  VZ_U32 u32FrameHeight;          //图像高度度
  VZ_U32 u32FrameStride;          //图像行跨度
  VZ_U32 u32FrameStrideUV;        //图像行跨度
  VZ_FRAME_FORMAT enFrameFormat;  //图像像素格式
  VZ_PHYS_ADDR_T u64PhyAddr[3];   //图像帧物理地址
  VZ_VIRT_ADDR_T u64VirAddr[3];   //图像帧虚拟地址
} VZ_VideoFrameInfo;

typedef struct {
  VZ_U8 u8Id[4];     //标识，始终为{'$','V','Z','\0'}
  VZ_U32 u32Counts;  //实际缓存的图像数据计数，最多为三帧
  VZ_VideoFrameInfo stBufInfo[VZ_VIDEO_BUF_SUPPORT_MAX];  //图像数据信息结构体
  VZ_U8 u8Stub[8];                           //算法保留？不知何用 = =
  VZ_U8 u8EncryptData[VZ_ENCRYPT_DATA_LEN];  //加密原始信息
  VZ_U8 u8EncryptKey[VZ_ENCRYPT_KEY_LEN];    //加密userdata
} VZ_VideoBufInfo;

////////////////////// 算法接口 ==> 输入参数信息 /////////////////////////////
typedef enum {
  ALG_RUN_AUTO_MODE = 0,  //默认
  ALG_RUN_PARK_GATE,      //停车场
  ALG_RUN_CHECK_POINT,    //卡口
} VZ_ALG_RUN_MODE;

typedef enum {
  VZ_DEBUG_MSG_ALL_OFF = -1,  //关闭所有显示
  VZ_DEBUG_MSG_ALERT = 0,     //严重问题信息
  VZ_DEBUG_MSG_ERROR,         //显示错误信息
  VZ_DEBUG_MSG_WARNING,       //显示警告信息,默认警告信息显示
  VZ_DEBUG_MSG_INFO,          //显示一般信息
  VZ_DEBUG_MSG_DEBUG,         //显示所有信息
} VZ_DEBUG_LEVEL;

typedef enum {
  VZ_ALG_RUN_DETECT_ONLY = 0,
  VZ_ALG_RUN_DETECT_RECOGNITION,
  /*
  VZ_ALG_RUN_NONE=0,                                               //算法不运行
  VZ_ALG_RUN_DETECT=0x00000001,                                    //仅运行检测
  VZ_ALG_RUN_PALATE=0x00000002, //运行车牌识别 VZ_ALG_RUN_STYLE=0x00000004,
  //运行车型识别 VZ_ALG_RUN_MANUFACTOR=0x00000008, //运行车标识别，制造商识别
  VZ_ALG_RUN_SERIES=0x00000010, //运行车系/车款识别 VZ_ALG_RUN_FAKE=0x00000020
  //运行车牌真伪检测
  */
} VZ_ALG_RUN_CTRL;

typedef struct {
  VZ_HANDLE hdlTriggerType;             //触发类型
  VZ_U32 u32TriggerInterval;            //车牌触发间隔
  VZ_CROSS_DIRECTION enCrossDirection;  //车辆触发方向
  //     VZ_U32                 u32TriggerAfterNumOfFrames; //无牌车触发确认帧
} VZ_TriggerConfig;

typedef struct {
  VZ_BOOL bRecogAreaEnable;     //算法识别区域是否有效
  VZ_BOOL bReverseEnable;       //算法识别区域反转,算法没有使用
  VZ_U32 u32RecogPointsCounts;  //算法识别区域点数
  VZ_Point stRecogArea[VZ_RECOG_AREA_POINTS_MAX];  //算法识别区域坐标点
} VZ_RecogAreaConfig;

typedef struct {
  VZ_BOOL bVirtualLoopEnable;     //虚拟线圈识别区域是否有效
  VZ_U32 u32VirLoopPointsCounts;  //虚拟线圈点数
  VZ_Point stVirtualLoopArea[VZ_VIR_LOOP_POINTS_MAX];  //虚拟线圈识别坐标点
} VZ_VirtualLoopConfig;

typedef struct {
  VZ_ALG_RUN_MODE enRunMode;    //运行模式
  VZ_DEBUG_LEVEL enDebugLevel;  //算法调试级别
  VZ_ALG_RUN_CTRL enAlgRunCtrl;  //控制是否启用算法识别功能,检测常开,,算法功能没有
  VZ_U32 u32DefaultProvince;   //默认省份
  VZ_U32 u32OutputResultType;  //输出类型
  VZ_U32 u32RecognitionType;   //识别车牌类型
  VZ_U32 u32PlateSizeMax;      //车牌最大尺寸
  VZ_U32 u32PlateSizeMin;      //车牌最小尺寸
  VZ_U32 u32PlateThr;          //车牌输出阈值,写死了
  VZ_U32 uShutterTime;         //当前快门时间
  VZ_U32 uTS[2];               // 当前时间戳
  // VZ_ALG_INPUT_MODE      enInputMode; //输入数据类型，视频流
  // 或图片，用于二次识别
} VZ_AlgBasicConfig;

typedef struct {
  VZ_CHAR *pData;                            //加密数据
  VZ_CHAR *pLibPath;                         //库路径
  VZ_U32 u32DataSize;                        //加密数据长度
} VZ_AlgEncryptParam;

typedef struct {
  VZ_VideoBufInfo stFrameIn;                 //封装后的视频帧信息
  VZ_TriggerConfig stTriggerConfig;          //触发相关信息配置
  VZ_RecogAreaConfig stRecogAreaConfig;      //识别区域相关配置
  VZ_VirtualLoopConfig stVirtualLoopConfig;  //虚拟线圈
  VZ_AlgBasicConfig stAlgBasicConfig;        //算法基础配置信息
  VZ_AlgEncryptParam stAlgEncryptData;       //用户需要输入的解密信息
  VZ_U8 u8Reserve[114];                      //保留区用于扩展
} VZ_AlgInputParams;

////////////////////// 算法接口 ==》 输入图像帧及封装头部相关信息
////////////////////////////////
#define VZ_ALG_ALGORITHM_VERSION_LEN 32  //算法版本信息长度
#define VZ_PLATE_RESULTS_COUNTS_MAX 2    //每次稳定结果最多2个车牌
#define VZ_PLATE_RESULTS_IN_FRAME_MAX 8  //一帧图像最多8个结果
#define TH_LP_LEN 16                     //车牌号码信息长度

//车牌颜色
typedef enum {
  LC_UNKNOWN = 0,  //未知
  LC_BLUE,         //蓝色
  LC_YELLOW,       //黄色
  LC_WHITE,        //白色
  LC_BLACK,        //黑色
  LC_GREEN,        //绿色
  LC_YELLOW_GREEN, //黄绿色,大型新能源颜色
} VZ_PLATE_COLOR;

typedef enum {
  LT_UNKNOWN = 0,      //未知车牌
  LT_BLUE,             //蓝牌小汽车
  LT_BLACK,            //黑牌小汽车
  LT_YELLOW,           //单排黄牌
  LT_YELLOW2,          //双排黄牌（大车尾牌，农用车）
  LT_POLICE,           //警车车牌
  LT_ARMPOL,           //武警车牌
  LT_INDIVI,           //个性化车牌
  LT_ARMY,             //单排军车牌
  LT_ARMY2,            //双排军车牌
  LT_EMBASSY,          //使馆车牌
  LT_HONGKONG,         //香港进出中国大陆车牌
  LT_TRACTOR,          //农用车牌
  LT_COACH,            //教练车牌
  LT_MACAO,            //澳门进出中国大陆车牌
  LT_ARMPOL2,          //双层武警车牌
  LT_ARMPOL_ZONGDUI,   //武警总队车牌
  LT_ARMPOL2_ZONGDUI,  //双层武警总队车牌
  LT_CA,               //民航车牌
  LT_NEW_ENERGY,       //新能源车牌
  LI_ENERGY_LARGE,     //新能源大型车
  LT_EMERGENCY = 21,   //应急
  LT_CONSULATE = 22,   //领馆车牌
  LT_NEW_FUEL_CAR = 23, //新标准小型燃油车
  LT_NEW_NE_CAR = 24,   //新标准小型新能源车
  LT_AIRPORT = 25,      //机场车牌
  LT_OVERSEA = 26,      //海外车牌(所有海外车牌类型)
  LT_FAKEPLATE = 29,    //假车牌
  LT_CAR_LOGO = 30,    //车标
  LT_NO_PLATE = 31,    //无牌车
} VZ_PLATE_TYPE;

//运动方向
typedef enum {
  DIRECTION_UNKNOWN = 0,
  DIRECTION_LEFT = 1,  //左
  DIRECTION_RIGHT,     //右
  DIRECTION_UP,        //上
  DIRECTION_DOWN,      //下
} VZ_MOTION_DIRECTION;

//车辆颜色
#define LGRAY_DARK 0   //深
#define LGRAY_LIGHT 1  //浅

typedef enum {
  LCOLOUR_WHITE = 0,   //白
  LCOLOUR_SILVER,  //银
  LCOLOUR_YELLOW,  //黄
  LCOLOUR_PINK,    //粉
  LCOLOUR_RED,     //红
  LCOLOUR_GREEN,   //绿
  LCOLOUR_BLUE,    //蓝
  LCOLOUR_BROWN,   //棕
  LCOLOUR_BLACK,   //黑
  LCOLOUR_GRAY,    //灰
  LCOLOUR_UNKNOWN = 255,
} VZ_CAR_BODY_COLOR;

enum NewCarTypeExtEnum{
  LNEW_SMALL_CAR_TYPE_UNKNOWN = 0,
  LNEW_SMALL_CAR_TYPE_F,
  LNEW_SMALL_CAR_TYPE_Y,
  LNEW_SMALL_CAR_TYPE_G,
};

typedef enum {
  VZ_TRIGGER_NONE = 0,       //无触发
  VZ_TRIGGER_IO,             // IO触发
  VZ_TRIGGER_SOFTWARE,       //强制触发
  VZ_TRIGGER_ALG_DEAL = 255  //算法处理，待应用层处理
} VZ_TRIGGER_TYPE;

typedef enum {
  TRIGGER_TYPE_AUTO_BIT = 1,           //自动
  TRIGGER_TYPE_EXTERNAL_BIT = 1 << 1,  //外部
  TRIGGER_TYPE_SOFTWARE_BIT = 1 << 2,  //软件
  TRIGGER_TYPE_VLOOP_BIT = 1 << 3      //虚拟地感线圈
} VZ_TRIGGER_TYPE_BIT;

typedef struct {
  int left;
  int top;
  int right;
  int bottom;
} VZ_RECT;

typedef struct CarBrand {
  unsigned char brand;   // 品牌
  unsigned char type;    // 车型
  unsigned short model;  // 车系
} CarBrand;

typedef struct TH_PlateResult {
  char license[TH_LP_LEN];  //车牌号码
  char color[8];            //车牌颜色
  int nColor;               //车牌颜色序号，详见车牌颜色定义LC_X
  int nType;                //车牌类型，详见车牌类型定义LT_X
  int nConfidence;          //车牌可信度
  int nBright;              //亮度评价
  int nDirection;          //运动方向，详见运动方向定义 DIRECTION_X
  VZ_RECT rcLocation;      //车牌位置
  int nTime;               //识别所用时间
  VZ_TIMEVAL tvPTS;        //识别时间点
  unsigned uBitsTrigType;  //强制触发结果的类型,见TH_TRIGGER_TYPE_BIT
  unsigned char nCarBright;  //车的亮度
  unsigned char nCarColor;   //车的颜色，详见车辆颜色定义LCOLOUR_X
  char reserved0;         //为了对齐
  unsigned char ucWLResult;  //白名单状态，详见白名单验证结果定义
  unsigned uId;              //记录的编号
  VzBDTime struBDTime;       //分解时间
  unsigned char nIsEncrypt;  //车牌是否加密
  unsigned char nPlateTrueWidth;  //车牌的真实宽度，单位cm
  unsigned char nPlateDistance;  //车牌距离相机的位置，单位dm(分米)
  unsigned char nIsFakePlate;    //是否是伪车牌
  VZ_RECT struCarLocation;       //车辆位置
  CarBrand struCarBrand;         //车辆品牌
  unsigned char featureCode[20];  //车辆特征码
  unsigned char nPlateTypeExtInfo;  //新式小型车牌扩展,仅在车牌为小型车牌的时候有效,详情:NewCarTypeExtEnum
  unsigned char reservedC1[3];          //保留一个字节用于结构体对齐大小不变，下次扩展一个字节的时候可以使用这个字节
  uint32_t triggerTimeMS;            //触发所用时间 单位：ms
  char reserved1[16];			           /**<保留*/
} TH_PlateResult;                 //车牌识别结果信息


typedef struct TH_EventResult {
  char license[TH_LP_LEN];  //车牌号码
  char color[32];           //车牌颜色
  char nType[64];           //车牌类型，详见车牌类型定义LT_X
  // char date[32];
  int nPlateTrueWidth;  //车牌的真实宽度，单位cm
  int nConfidence;          //车牌可信度
  unsigned uId;             //记录的编号
  int event_type;          //事件类型
  int full_image_id;       //大图id
  int full_image_type;
  int small_image_type;
  int small_image_id;      //小图id
  int alg_chn;
  int chn_id;
  int rule_id;
  int result_id;
  // int uid;
  VZ_Rect crop_area;
  VzBDTime struBDTime;       //识别时间
  VZ_TIMEVAL tvPTS;        //识别时间点
  char reserved1[16];			           /**<保留*/
} TH_EventResult; 


typedef struct {
  VZ_U32 u32ResultCountRealTime;  //实时识别有效车牌结果个数
  TH_PlateResult stResultRealTime[VZ_PLATE_RESULTS_COUNTS_MAX];  //实时识别有效车牌结果
  VZ_U32 u32ResultCountForce;  //强制触发识别有效车牌结果个数
  TH_PlateResult stResultForce[VZ_PLATE_RESULTS_COUNTS_MAX];  //强制触发识别有效车牌结果
  VZ_U32 u32ResultCountVirLoop;  //线圈触发识别有效车牌结果个数
  TH_PlateResult stResultVirLoop[VZ_PLATE_RESULTS_COUNTS_MAX];  //线圈触发识别有效车牌结果
  VZ_U32 u32ResultCountStable;  //稳定识别有效车牌结果个数
  TH_PlateResult struResultStable[VZ_PLATE_RESULTS_COUNTS_MAX];  //稳定识别有效车牌结果
} VZ_PLATE_RESULT;

typedef struct {
  VZ_VIRT_ADDR_T u64VirAddr;  //图像帧虚拟地址
  VZ_PHYS_ADDR_T u64PhyAddr;  //图像帧物理地址
} VZ_FrameOutputInfo;

typedef struct {
  VZ_U32 u32TriggerType;                 //触发类型,位或输出
  VZ_PLATE_RESULT stPlateResult;         //车牌识别结果
  VZ_FrameOutputInfo stFrameOutputInfo;  //算法输出帧信息和深度信息
  VZ_U8 u8AlgVerison[VZ_ALG_ALGORITHM_VERSION_LEN];  //算法版本信息
  VZ_BOOL b32SaveImage;  //是否保留当前图像,应用层抠图会使用.算法不确定用不用
  VZ_BOOL bFuzzyMatch[4][VZ_PLATE_RESULTS_COUNTS_MAX];  //模糊匹配生效结果对应位
  VZ_RECT stPlateLocation;                              //车牌位置, 用于ISP优化成像
  VZ_U8 u8Reserved[76];                                 //保留，扩展用
} VZ_AlgOutputParams;

typedef struct {
  TH_RECT rect[4];
  int charColor[4];
  int num;
} VZ_DetectResult;

////////////////////// 算法接口 ==》 退出和销毁部分
////////////////////////////////
typedef struct {
  VZ_U8 u8Reserved[128];  //保留，扩展用
} VZ_AlgExitParams;

////////////////////// 算法接口 ==》  API 接口部分 /////////////////////////////
VZ_RESULT Init(VZ_AlgInitParams* pstParams);
VZ_RESULT Process(VZ_AlgInputParams* pstInArgs, VZ_AlgOutputParams* pstOutArgs);
VZ_RESULT ProcessAgain(VZ_AlgInputParams* pstInArgs, VZ_AlgOutputParams* pstOutArgs);
VZ_RESULT Release(VZ_AlgExitParams* pstExitParams);
#ifdef __cplusplus
}
#endif

#endif  // ifndef ALG_INTERFACE_H
