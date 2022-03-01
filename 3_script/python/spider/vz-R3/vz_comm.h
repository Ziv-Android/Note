/*!
 * \file vz_comm.h
 * \date 2017/09/04 15:51
 *
 * \author yangy
 *
 * \brief 臻识多媒体处理软件平台接口公用定义
 *
 * TODO: long description
 *
 * \note
 */

#ifndef __VZ_COMM_NEW_H__
#define __VZ_COMM_NEW_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

//#include <string.h>
#include <stdint.h>
#include <stdio.h>

typedef void                VZ_VOID;
typedef unsigned char       VZ_U8;
typedef unsigned short      VZ_U16;
typedef unsigned int        VZ_U32;
typedef unsigned long long  VZ_U64;

typedef signed char         VZ_S8;
typedef short               VZ_S16;
typedef int                 VZ_S32;
typedef char                VZ_CHAR;

#if 0
typedef VZ_U32              VZ_PHYS_ADDR_T;
typedef VZ_VOID*            VZ_VIRT_ADDR_T;
typedef VZ_U32              VZ_HANDLE;
#else
typedef VZ_U64              VZ_PHYS_ADDR_T;
typedef VZ_VOID*            VZ_VIRT_ADDR_T;
typedef VZ_U64              VZ_HANDLE;
#endif

/* common constants */
// #ifndef SUCCESS
// #define SUCCESS         0
// #endif
//
// #ifndef FAILURE
// #define FAILURE        -1
// #endif
//
// #define VZ_API_SUCCESS      0
// #define VZ_API_FAILED       -1

typedef enum {
  VZ_FAILED = -1,
  VZ_SUCCESS = 0,
  VZ_RESULT_FAILED = VZ_FAILED,
  VZ_RESULT_SUCCESS = VZ_SUCCESS,
  VZ_RESULT_INVAL,
  VZ_RESULT_IO,
  VZ_RESULT_NOMEM,
  VZ_RESULT_MODEL_NOT_MATCH,
  VZ_RESULT_UNKNOWN,
} VZ_RESULT;
///////////////////////////////

#ifndef CIF4_WIDTH
#define CIF4_WIDTH 704
#define CIF4_HEIGHT 576
#define CIF_WIDTH 352
#define CIF_HEIGHT 288
#endif

typedef enum { VZ_FALSE = 0, VZ_TRUE = 1 } VZ_BOOL;

typedef VZ_S32 VZ_AI_CHN;
typedef VZ_S32 VZ_AO_CHN;
typedef VZ_S32 VZ_AENC_CHN;
typedef VZ_S32 VZ_ADEC_CHN;
typedef VZ_S32 VZ_AUDIO_DEV;
typedef VZ_S32 VZ_AVENC_CHN;
typedef VZ_S32 VZ_VI_DEV;
typedef VZ_S32 VZ_VI_WAY;
typedef VZ_S32 VZ_VI_CHN;
typedef VZ_S32 VZ_VPSS_DEV;
typedef VZ_S32 VZ_VO_DEV;
typedef VZ_S32 VZ_VO_LAYER;
typedef VZ_S32 VZ_VO_CHN;
typedef VZ_S32 VZ_VO_WBC;
typedef VZ_S32 VZ_GRAPHIC_LAYER;
typedef VZ_S32 VZ_VENC_CHN;
typedef VZ_S32 VZ_VDEC_CHN;
typedef VZ_S32 VZ_VENC_GRP;
typedef VZ_S32 VZ_VO_GRP;
typedef VZ_S32 VZ_VDA_CHN;
typedef VZ_S32 VZ_IVE_HANDLE;
typedef VZ_S32 VZ_CLS_HANDLE;
typedef VZ_S32 VZ_FD_CHN;
typedef VZ_S32 VZ_MD_CHN;
typedef VZ_S32 VZ_ISP_DEV;
typedef VZ_S32 VZ_SENSOR_ID;
typedef VZ_S32 VZ_VPSS_CHN;

// #define VZ_SUCCESS 0
// #define VZ_FAIL    -1

/************************************************************************
ERROR define
************************************************************************/
//#define  E_SUCCESS              0   //Success
//#define  E_FAILURE              -1  //FAILURE
//#define  E_INVAL                1   //Invalid parameters
//#define  E_NOENT                2   //No such file or directory
//#define  E_IO                   3   //I/O Error
//#define  E_NOMEM                4   //Out of memory
//#define  E_NETERR               5   //Network error
//#define  E_NEEDINIT             6   //Need call some initial function first
//#define  E_OUTOFMAX             7   //Beyond the maxinum
//#define  E_NOTLOGIN             8   //Not login
//#define  E_SREJECT              9   //Server reject the request
//#define  E_MULTICASTNOTSUPPORT  10  //Multicast not support
//#define  E_TALKNOTSUPPORT       11  //Talk not support
//#define  E_AUDIOERR             12  //Audio can not operatioin
//#define  E_BUFSMALL             13  //Buffer too small
//#define  E_UNDEFINED            14

//错误代码
/*
sys   0XA1000001 - 0XA1FFFFFF
bus   0XA2000001 - 0XA2FFFFFF
audio 0XA3000001 - 0XA3FFFFFF
video 0XA4000001 - 0XA4FFFFFF
alg   0XA5000001 - 0XA5FFFFFF
*/

typedef struct {
  //识别结果图片
  VZ_VOID* pImgAddr;
  VZ_U32 u32ImgWidth;
  VZ_U32 u32ImgHeight;
  VZ_U32 u32ImgPitch;
  VZ_U32 u32ImgSize;
  VZ_BOOL bImgHasEnc;
} VZ_PIC_INFO;

//实时流数据类型
// typedef enum {
//     vHeadData = 1,      //视频编码头数据
//     vStreamData,        //
//     aStreamData         //
// } RealDataType;
//
// //解码数据的作用模式
// typedef enum VZC_DEC_DATA_MODE {
//     VZC_DEC_DATA_INSTANCE,
//     //实际解码数据，并将绘制到内部绘图（默认）。用户不能修改图像，否则影响图像质量
//     VZC_DEC_DATA_REFERENCE,
//     //拷贝解码数据，如果用户修改了图像，将显示到内部绘图。 VZC_DEC_DATA_COPY,
//     //拷贝解码数据，如果用户修改了图像，但不显示到内部绘图。
// } VZC_DEC_DATA_MODE;

//图像格式（TH_SetImageFormat函数的cImageFormat参数）
//#define ImageFormatRGB		0			//RGBRGBRGB...
//#define ImageFormatBGR		1			//BGRBGRBGR...
//#define ImageFormatYUV422	2			//YYYY...UU...VV..
//(YV16) #define ImageFormatYUV420COMPASS 3		//YYYY...UV...
//(NV12)
//#define ImageFormatYUV420	4			//YYYY...U...V...
//(YU12) #define ImageFormatUYVY	    5 //UYVYUYVYUYVY...	(UYVY) #define
//ImageFormatNV21		6			//YYYY...VU...
//(NV21) #define ImageFormatYV12		7
////YYYY...V...U		(YV12) #define ImageFormatYUYV	    8
////YUYVYUYVYUYV..	(YUYV)

///**YUV420P的帧结构体*/
//typedef struct VzYUV420P {
//  unsigned char* pY;
//  unsigned char* pU;
//  unsigned char* pV;
//  int widthStepY;
//  int widthStepU;
//  int widthStepV;
//  int width;
//  int height;
//} VzYUV420P;
//
///**带时间、序列号信息的视频帧*/
//typedef struct VzFrameBuffer {
//  VzYUV420P yuv;
//  unsigned int uTimeStamp;  // 当前帧的时间参数
//  unsigned int uSerialNum;  // 当前帧的编号
//} VzFrameBuffer;

/**分解时间*/
// typedef struct {
//    unsigned char   bdt_sec;    /**<秒，取值范围[0,59]*/
//    unsigned char   bdt_min;    /**<分，取值范围[0,59]*/
//    unsigned char   bdt_hour;   /**<时，取值范围[0,23]*/
//    unsigned char   bdt_mday;   /**<一个月中的日期，取值范围[1,31]*/
//    unsigned char   bdt_mon;    /**<月份，取值范围[1,12]*/
//    unsigned char   res1[3];    /**<预留*/
//    unsigned        bdt_year;   /**<年份*/
//    unsigned char   res2[4];    /**<预留*/
//} VzBDTime;   //broken-down time
typedef struct _VzBDTime {
  unsigned char bdt_sec;   //秒，取值范围[0,59]
  unsigned char bdt_min;   //分，取值范围[0,59]
  unsigned char bdt_hour;  //时，取值范围[0,23]
  unsigned char bdt_mday;  //一个月中的日期，取值范围[1,31]
  unsigned char bdt_mon;   //月份，取值范围[1,12]
  unsigned char bdt_msec;  //月份，取值范围[1,12]
  unsigned char res1[2];   //预留
  unsigned bdt_year;       //年份
  unsigned char res2[4];   //预留
} VzBDTime;                //分解时间

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif
