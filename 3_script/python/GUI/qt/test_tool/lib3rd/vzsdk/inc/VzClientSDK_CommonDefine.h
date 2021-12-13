//һЩ���еķ��Ŷ���
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

//ʵʱ����������
typedef enum
{
	vHeadData = 1,	//��Ƶ����ͷ����
	vStreamData,	//
	aStreamData		//	
}RealDataType;

//�������ݵ�����ģʽ
typedef enum VZC_DEC_DATA_MODE
{
	VZC_DEC_DATA_INSTANCE,	//ʵ�ʽ������ݣ��������Ƶ��ڲ���ͼ��Ĭ�ϣ����û������޸�ͼ�񣬷���Ӱ��ͼ������
	VZC_DEC_DATA_REFERENCE,	//�����������ݣ�����û��޸���ͼ�񣬽���ʾ���ڲ���ͼ��
	VZC_DEC_DATA_COPY,		//�����������ݣ�����û��޸���ͼ�񣬵�����ʾ���ڲ���ͼ��
}
VZC_DEC_DATA_MODE;

/**YUV420P��֡�ṹ��*/
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

/**��ʱ�䡢���к���Ϣ����Ƶ֡*/
typedef struct VzFrameBuffer
{
	VzYUV420P yuv;
	unsigned int uTimeStamp;	//��ǰ֡��ʱ�����
	unsigned int uSerialNum;    //��ǰ֡�ı��
}
VzFrameBuffer;

/**�ֽ�ʱ��*/
typedef struct
{
    unsigned char   bdt_sec;    /**<�룬ȡֵ��Χ[0,59]*/
    unsigned char   bdt_min;    /**<�֣�ȡֵ��Χ[0,59]*/
    unsigned char   bdt_hour;   /**<ʱ��ȡֵ��Χ[0,23]*/
    unsigned char   bdt_mday;   /**<һ�����е����ڣ�ȡֵ��Χ[1,31]*/
    unsigned char   bdt_mon;    /**<�·ݣ�ȡֵ��Χ[1,12]*/
    unsigned char   res1[3];    /**<Ԥ��*/
    unsigned        bdt_year;   /**<���*/
    unsigned char   res2[4];    /**<Ԥ��*/
}
VzBDTime;   //broken-down time

/**ͼ����Ϣ*/
typedef struct
{
	unsigned		uWidth;			/**<���*/
	unsigned		uHeight;		/**<�߶�*/
	unsigned		uPitch;			/**<ͼ���ȵ�һ��������ռ�ڴ��ֽ���*/
	unsigned		uPixFmt;		/**<ͼ�����ظ�ʽ���ο�ö�ٶ���ͼ���ʽ��ImageFormatXXX��*/
	unsigned char	*pBuffer;	/**<ͼ���ڴ���׵�ַ*/
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
