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

typedef enum{
	VZC_WATCHDOG_LOG
}
VZC_LogType;

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


#endif
