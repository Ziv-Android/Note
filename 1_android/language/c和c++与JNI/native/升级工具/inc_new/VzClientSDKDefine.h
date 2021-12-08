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

/**ͼ����Ϣ*/
typedef struct {
	char dev_ip[16];		// �豸��IP��ַ
	int  dev_port;			// �豸�Ķ˿ں�
	char username[32];      // �����豸�����û���
	char password[32];      // �����豸��������
	int  timeout;           // ��ʱʱ��(��λ���룬�糬ʱʱ��Ϊ5��ʱ����5000)
	int protocol_type;      // ����Э��(0:http, 1:https)
	int network_type;       // ��������(0:������,1:����-PDNS��ʽ, 2:����-BIND��ʽ)
	//��������
	int http_port;          // �����˿�
	char sn[20];            // �豸���к�
	int tcp_port;			// tcp�˿�
	BYTE dwRes[60];         // ����
}VZ_LPRC_LOGIN_PARAM;

//�ص���������Ϣ�ȶ�����Ϣ
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


//���ò�������
#define VZDEV_SERIALNO_LEN 					7
#define VZDEV_MAX_MDNUM						8

#define VZDEV_DATATYPE_AV					0x01    //����Ƶͬ������
#define VZDEV_DATATYPE_USVIDEO		        0x02    //�Զ�����Ƶ����
#define VZDEV_DATATYPE_SOUND		        0x04    //�����Խ�����

#define VZDEV_STREAM_TYPE_AV		        0	/* ������*/
#define VZDEV_STREAM_TYPE_VIDEO				1	/* ��Ƶ��*/

#define VZDEV_FRAMESIZE_CIF4				0	/* CIF4 704*576*/
#define VZDEV_FRAMESIZE_CIF					1	/* CIF 352*288*/
#define VZDEV_FRAMESIZE_720P				2	/* 1280 * 720*/
#define VZDEV_FRAMESIZE_1080P				3	/* 1920 * 1080*/

#define VZDEV_VIDEO_COMPRESS_FIX_RATE		0	/* �̶����� */
#define VZDEV_VIDEO_COMPRESS_VAR_RATE		1	/* �ɱ����� */

#define VZDEV_TALK_STAT_OPENED		        0x01	//�����Խ���
#define VZDEV_TALK_WAVEIN_INSIDE			0x01	//�����ڲ������豸
#define VZDEV_TALK_WAVEIN_OUTSIDE			0x02	//�����ⲿ��������


#define MAX_STORAGE_DEVICE_NUM	4
#define MAX_STORAGE_DEVICE_PARTED_NUM   4

#define    PUSH_ADDR_BUFFER_MAX_SIZE 200

//�������������
typedef enum
{
	WhiteList = 0,	//ͨ��
	NotWhiteList,	//��ͨ��
	NoLicence,		//�޳���
	BlackList,		//������
	ExtIoctl1,		//������/��ƽ���� 1
	ExtIoctl2,		//������/��ƽ���� 2
	ExtIoctl3,		//������/��ƽ���� 3
	SpecialPlates,	//���⳵��
	ExtIoctl4,		//������/��ƽ���� 4
	InputTypeLen 
}DeviceInputType;

//�������
typedef struct
{
	int switchout1;					//��������� 1
	int switchout2;					//��������� 2
	int switchout3;					//��������� 3
	int switchout4;					//��������� 4
	int levelout1;					//��ƽ��� 1 
	int levelout2;					//��ƽ��� 2
	int rs485out1;					//RS485-1
	int rs485out2;					//RS485-2
	DeviceInputType oInputType;		//�������������
}VZDEV_OutputConfig;

#define MAX_OutputConfig_Len 9

//���������Ϣ
typedef struct
{
	VZDEV_OutputConfig oConfigInfo[MAX_OutputConfig_Len];	//�����������������Ϣ
}VZDEV_OutputConfigInfo;

//��������֤ģʽ
typedef enum
{
	AutoEnable = 0, //�ѻ��Զ�����
	Enable,		 //����
	Disable		 //������
}DeviceWLCheckMethod;

//������ģ��ƥ��
typedef enum
{
	Accurate  = 0,		 //��ȷƥ��
	Similar,			 //�����ַ�ƥ��
	Normal				 //��ͨ�ַ�ģ��ƥ��
}DeviceWLFuzzy;

//RS-485������������
typedef enum
{
	RS485_NOTYPE = 0,			
	RS485_LICENSEENABLE,	//���޳���
	RS485_LICENSECOLOR,		//������ɫ
	RS485_LICENSE,			//���ƺ�
	RS485_LICENSETYPE,		//��������
	RS485_CONFIDENCE,		//���Ŷ�
	RS485_DIRECTION,		//�˶�����
	RS485_RECT,				//��������
	RS485_TRIGGER,			//��������
	RS485_CARCOLOR,			//������ɫ
	RS485_TIME,				//ʶ��ʱ��
	RS485_DUETIME,			//����������ʱ�� ֵ���ͣ�RS485_TIME_FORMAT
	RS485_WLRESULT,			//��������֤��� ֵ���ͣ�RS485_TIME_FORMAT
	RS485_OUT,				//���IO
	RS485_SN,				//���к�
	RS485_CIPHERTEXT,		//����
	RS485_ID,				//ʶ���¼ID
	RS485_CHECKBEGIN,		//У����ʼλ
	RS485_CHECKEND,			//У�����λ
	RS485_CHECKSUM,			//У��λ
	RS485_ENCODE,			//���Ʊ���
	RS485_EDIAN,			//��С��

	RS485_TYPELEN			//�������
}RS485_PUSH_TYPE;

//RS-485����������
typedef struct 
{
	int item_type;				//�����ֶ�����
	int  val;					//ֵ
}VZDEV_RS485_ITEM;

//У��λ
typedef enum
{
	CHECK_NO = 0,	//��У��
	CHECK_SUM,		//��У��
	CHECK_XOR		//���У��
}RS485_ITEM_CHECKSUM;

//��С��
typedef enum
{
	EDIAN_LITTLE = 0,	//С��
	EDIAN_BIG			//���
}RS485_ITEM_EDIAN;

//ʱ������
typedef enum 
{
	TIME_FOUR_STAMP = 0,//4�ֽ� ʱ���
	TIME_SEVEN_YYMDHMS,	//7�ֽ� YYYYTTMMDDHHmmss
	TIME_SIX_YMDHMS,	//6�ֽ� YYMMDDHHmmss
	TIME_SEVEN_HMSDMYY,	//7�ֽ�	HHmmssDDMMYYYY
	TIME_SIX_HMSDMY,	//6�ֽ� HHmmssDDMMYY
	TIME_FOUR_YYMD,		//4�ֽ� YYYYMMDD
	TIME_THREE_YMD		//3�ֽ�	YYMMDD
}RS485_TIME_FORMAT;

//������Ϣ״̬
typedef enum
{
	VOICE_NOTYPE = 0,
	VOICE_IN,	//��Ч���ڰ�����
	VOICE_OUT,		//�ѹ���
	VOICE_NA,		//���ڰ�����
	VOICE_IW,		//��������������

	VOICE_STATUELEN	//״̬��
}VZDEV_RS485_VOICE_STATUE;

//������Ϣ-������
typedef struct
{
	int status;			//������Ϣ״̬VZDEV_RS485_VOICE_STATUE
	int remain;			//ʣ������
	bool license;		//����������Ϣ
	char prefix[36];	//����ǰ׺
	char suffix[36];	//������׺		
}VZDEV_RS485_VOICE_WL;

#define VZDEV_RS485_VOICE_LEN 4
//������Ϣ
typedef struct
{
	VZDEV_RS485_VOICE_WL voiceWL[VZDEV_RS485_VOICE_LEN];
}VZDEV_RS485_VOICE;

#define RE485_PUSH_TYPE_LEN 22
//RS-485��������
typedef struct
{
	VZDEV_RS485_ITEM configItem[RE485_PUSH_TYPE_LEN];	//������
	VZDEV_RS485_VOICE voice;
	char header[64];	//Э��ͷ
	char end[64];		//Э��β	
	bool voiceEnable;	//������Ϣ����	
}VZDEV_RS485_Config;


//������Ƶ��ز���
//---------------------------------------------------------------------------
///-------------------vz alarm------------------------
#ifndef _VZ_CLIENT_SDK_IVS_DEFINE_H_
#define _VZ_CLIENT_SDK_IVS_DEFINE_H_

#define VZ_IVS_MAX_RELATIVE_SHORT 0x4000

//�����������ԵĻ�ת
typedef short VZ_FIXPOINT_SHORT;
//FIXPOINT_SHORT����Ϊ �������Ķ�������ʾ��������Ҫ�����������Ľṹ�壬����ͨ�������IVS_I2S�����ת��
/*���磺
���ڷֱ���Ϊ640*480������㣨320��240��
�ú�IVS_I2S�����ǿ���ֱ�ӵõ�
VZ_FIXPOINT_SHORT x = IVS_I2S(320��640);
VZ_FIXPOINT_SHORT y = IVS_I2S(240��480);
*/
#define IVS_I2S(int_val,total) ((short)(((int)(int_val)<<14)/((int)(total))))
#define IVS_S2I(short_val,total) (((int)(short_val)*(total)+(1<<13))>>14)

//
typedef struct _VZ_IVS_POINT{
	VZ_FIXPOINT_SHORT  X;//������귶Χ[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_FIXPOINT_SHORT  Y;
}VZ_IVS_POINT;//���������

typedef struct _VZ_IVS_LINE{
	VZ_IVS_POINT   struStart;
	VZ_IVS_POINT   struEnd;
}VZ_IVS_LINE;//�߽ṹ����

#define IVS_MAX_BROKEN_LINE_POINT_NUM 10
typedef struct _VZ_IVS_BROKEN_LINE{
	DWORD           dwPointNum;
	VZ_IVS_POINT   struPos[IVS_MAX_BROKEN_LINE_POINT_NUM];
}VZ_IVS_BROKEN_LINE;//�߽ṹ����

typedef struct _VZ_IVS_RECT{
	VZ_FIXPOINT_SHORT   X;//������귶Χ[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_FIXPOINT_SHORT   Y;
	VZ_FIXPOINT_SHORT   Width;
	VZ_FIXPOINT_SHORT   Height;
}VZ_IVS_RECT;//����

#define VZ_IVS_LPR_OBJSIZE_MIN 45
#define VZ_IVS_LPR_OBJSIZE_MAX 400

typedef struct _VZ_IVS_OBJSIZE_RANGE{
	WORD   Min;
	WORD   Max;
}VZ_IVS_OBJSIZE_RANGE;//����

//sizeof POLYGON	2*sizeof(float)*IVS_MAX_POLYGON_POINT_NUM+4 = 84
#define IVS_MAX_POLYGON_POINT_NUM 15
typedef struct _VZ_IVS_POLYGON{
	DWORD           dwPointNum;
	VZ_IVS_POINT   struPos[IVS_MAX_POLYGON_POINT_NUM];
}VZ_IVS_POLYGON;//�����

typedef enum _IVS_CROSS_DIRECTION{
	IVS_BOTH_DIRECTION  = 0,
	IVS_LEFT_GO_RIGHT   = 1,
	IVS_RIGHT_GO_LEFT   = 2
}IVS_CROSS_DIRECTION;//��Խ����

typedef struct _VZ_IVS_TRAVERSE_PLANE{
	VZ_IVS_BROKEN_LINE	  struPlaneBottom;
	IVS_CROSS_DIRECTION   dwCrossDirection;
	BYTE                  byRes1;
	BYTE                  byPlaneHeight;
	BYTE                  byRes2[38];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_TRAVERSE_PLANE;//��Խ���������


typedef struct _VZ_IVS_TRAVERSE_PLANE_EXT{
	VZ_IVS_BROKEN_LINE	  struPlaneBottom;
	IVS_CROSS_DIRECTION   dwCrossDirection;
	BYTE				  byIsCalibed[IVS_MAX_BROKEN_LINE_POINT_NUM-1];
	VZ_IVS_LINE			  CalibLine[IVS_MAX_BROKEN_LINE_POINT_NUM-1];
}VZ_IVS_TRAVERSE_PLANE_EXT;//��Խ��������չ
/////////////////////////////////////////

typedef struct _VZ_IVS_ENTER_OUT{
	BYTE			  byEnable;
	BYTE			  byEnter;	// 0�뿪 1���� 2�����롢�뿪��ͬʱ���
	BYTE              byRes[2];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_ENTER_OUT;//����/�뿪�������

typedef struct _VZ_IVS_INTRUSION{
	BYTE			  byEnable;
	BYTE              byRes[1];
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_INTRUSION;//���ֲ���

typedef struct _VZ_IVS_LOITER{
	BYTE			    byEnable;
	BYTE				byRes[1];
	WORD				wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_LOITER;//�ǻ�����

typedef struct _VZ_IVS_TAKE_LEFT{
	BYTE			  byEnable;
	BYTE			  byTake; // 0���� 1��� 2�������������ͬʱ���
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_TAKE_LEFT;//����/�������

typedef struct _VZ_IVS_PARKING{
	BYTE			  byEnable;
	BYTE              byRes[1];
	WORD              wDuration;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_PARKING;//ͣ������

typedef struct _VZ_IVS_RUN{
	BYTE			  byEnable;
	BYTE              byRes[1];
	VZ_FIXPOINT_SHORT              RunDistance;//������귶Χ[0-VZ_IVS_MAX_RELATIVE_SHORT]
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_RUN;//���ܲ���

typedef struct _VZ_IVS_HIGH_DENSITY{
	BYTE			  byEnable;
	BYTE              byRes[3];
	float             fDensity;
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_HIGH_DENSITY;	// ��Ա�ۼ�����

typedef struct _VZ_IVS_OIL_INTRUSION{
	BYTE			  byEnable;
	BYTE              byRes[7];
	VZ_IVS_OBJSIZE_RANGE  ObjectSize;
}VZ_IVS_OIL_INTRUSION; // �;����ֲ���

//����ʶ�����
typedef struct _VZ_IVS_LPR{
	BYTE					byEnable;
	BYTE					byTrigTimeout;	//������ʱʱ�䣨ʱ�������ͬ���Ʋ����ظ�������[1-255]��
	BYTE					byCrossDirection;	//��������
	BYTE					byRes[5];
	VZ_IVS_OBJSIZE_RANGE	struObjSize;
}VZ_IVS_LPR;

typedef struct _VZ_IVS_PSD{
	uint32		nParkId;			//��λ��
	uint32		nIsOrderd;			//�Ƿ�Ԥ����λ
	BYTE		byOrderLicense[12];	//Ԥ�����ƺ�
}VZ_IVS_PSD;


//�����������
typedef enum _HJ_DETECT_TYPE
{
	PIPE_WATER = 1,	//��ˮ�ŷ�
	BUBBLE,			//����
	EXHAUST_GAS,	//����
	HJ_DETECT_NUM
}
HJ_DETECT_TYPE;

typedef struct _VZ_IVS_HJ
{
	BYTE			byEnable;
	BYTE			byRes[1];
	HJ_DETECT_TYPE	dwDetectType;
}
VZ_IVS_HJ;	//����������

// �������
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

//������Ĥ�������������ܷ����ĸ���Ȥ����
typedef struct _VZ_IVS_AREA_MASK
{
	VZ_IVS_POLYGON			struRegion;
	BYTE					byRes[6];
	BYTE                    bEnable;
	BYTE                    bInvert;    //����ѡ�У������Ϊ1��˵����������Ч��������������Ч
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
	IVS_RULE_LINE = 0x1,	// ���߹���
	IVS_RULE_AREA = 0x2,	// �������
	IVS_RULE_LINE_EX,		//��չ�İ��߹���
	IVS_RULE_AREA_EX,		//��չ���������
	IVS_RULE_MASK,          //�����������Ĥ
}IVS_RULE_TYPE;

#define MAX_EVENT_NUM 32

enum
{
	OFFSET_TRAVERSE_PLANE = 0,	//��Խ������
	OFFSET_ENTER_AREA,			//Ŀ���������֧��������� 
	OFFSET_EXIT_AREA,			//Ŀ���뿪����֧���������
	OFFSET_INTRUSION,			//�ܽ����֣�֧��������� 
	OFFSET_LOITER,				//�ǻ���֧��������� 
	OFFSET_LEFT_TAKE,			//���������֧���������
	OFFSET_PARKING,				//ͣ����֧��������� 
	OFFSET_RUN,					//���ܣ�֧��������� 
	OFFSET_HIGH_DENSITY,		//��������Ա�ܶȣ�֧��������� 
	OFFSET_OIL_INTRUSION,		//�;�����
	OFFSET_FIRE_SMOKE,			//�̻��¼�
	OFFSET_PEOPLE_COUNT,		//����ͳ��
	OFFSET_PLATE_R,				//����ʶ��
	OFFSET_CAM_HEALTH,			//���������״�����
	OFFSET_CAR_COUNT,			//����ͳ��
	OFFSET_PLATE_R_SERVER,		//����ʶ���������
	OFFSET_AUTO_PTZ,			//PTZ�Զ������¼�
	OFFSET_HJ_PIPE_WATER,		//������ˮ
	OFFSET_HJ_BUBBLE,			//��������
	OFFSET_HJ_EXHAUST_GAS		//��������
};

typedef enum _IVS_EVENT_TYPE{
	IVS_TRAVERSE_PLANE	= 1<<OFFSET_TRAVERSE_PLANE,	//��Խ������ 
	IVS_ENTER_AREA		= 1<<OFFSET_ENTER_AREA,		//Ŀ���������֧��������� 
	IVS_EXIT_AREA		= 1<<OFFSET_EXIT_AREA,		//Ŀ���뿪����֧��������� 
	IVS_INTRUSION		= 1<<OFFSET_INTRUSION,		//�ܽ����֣�֧��������� 
	IVS_LOITER			= 1<<OFFSET_LOITER,			//�ǻ���֧��������� 
	IVS_LEFT_TAKE		= 1<<OFFSET_LEFT_TAKE,		//���������֧��������� 
	IVS_PARKING			= 1<<OFFSET_PARKING,		//ͣ����֧��������� 
	IVS_RUN				= 1<<OFFSET_RUN,			//���ܣ�֧��������� 
	IVS_HIGH_DENSITY	= 1<<OFFSET_HIGH_DENSITY,	//��������Ա�ܶȣ�֧��������� 
	IVS_OIL_INTRUSION	= 1<<OFFSET_OIL_INTRUSION,	//�;�����
	IVS_FIRE_SMOKE		= 1<<OFFSET_FIRE_SMOKE,		//�̻��¼�
	IVS_PEOPLE_COUNT	= 1<<OFFSET_PEOPLE_COUNT,	//����ͳ��
	IVS_PLATE_R			= 1<<OFFSET_PLATE_R,		//����ʶ��
	IVS_CAM_HEALTH		= 1<<OFFSET_CAM_HEALTH,		//���������״�����
	IVS_CAR_COUNT 		= 1<<OFFSET_CAR_COUNT,		//����ͳ��
	IVS_PLATE_R_SERVER	= 1<<OFFSET_PLATE_R_SERVER,	//����ʶ�������
	IVS_AUTO_PTZ		= 1<<OFFSET_AUTO_PTZ,		//PTZ�Զ������¼�
	IVS_HJ_PIPE_WATER	= 1<<OFFSET_HJ_PIPE_WATER,	//������ˮ
	IVS_HJ_BUBBLE	    = 1<<OFFSET_HJ_BUBBLE,		//��������
	IVS_HJ_EXHAUST_GAS	= 1<<OFFSET_HJ_EXHAUST_GAS	//��������
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
}VZ_IVS_RULE_INFO;//�¼�������Ϣ

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
#define VZ_IVS_DAY_NULL	0x80	//��ʾʹ��ÿ֡�����ʱ�������������ʱ����Ч

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
}VZ_IVS_TARGET_INFO;//����Ŀ����Ϣ


#define VZ_MAX_TARGET_NUM	320
//blob����
#define VZ_BLOB_HUMAN	0
#define VZ_BLOB_CAR		1
#define VZ_BLOB_TRUCK	2
#define VZ_BLOB_ANIMAL	3
#define VZ_BLOB_WATER	4
#define VZ_BLOB_BUBBLE	5
#define VZ_BLOB_GAS		6


typedef struct VZ_IVS_TARGET
{
	int id;		//Ŀ��ID
	int kind;	//Ŀ������
	unsigned short x;	//�������Xֵ
	unsigned short y;	//�������Yֵ
	unsigned short w;	//���ο��
	unsigned short h;	//���θ߶�
	unsigned int dwBitsRules;		//��λ��ӦruleID��Υ���Ϊ��1
	unsigned int dwBitsEvent;		//��IVS_EVENT_TYPE���
	//�жϸ�Ŀ���Ƿ�Υ�棬����dwBitsEvente������rulesFlag
}
VZ_IVS_TARGET;	//��������Ŀ�� size= 8+8+8 = 24

//������Ϣ
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
	int motionKind;							//0Ϊ���룬1Ϊ����
	int contrailLen;						//�켣ʵ�ʳ���	//*/
	unsigned short contrailX[MAX_HIS_NUM];	//�켣X
	unsigned short contrailY[MAX_HIS_NUM];	//�켣Y
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
	VZ_ALARM_TYPE_RULE,		//�ɱ������򴥷���
	VZ_ALARM_TYPE_INPUT,	//�����뱨�����ص�
	VZ_ALARM_TYPE_PROTOCOL,	//�������Э�����ݴ�����
	VZ_ALARM_TYPE_PLATE_RESULT,		//����ʶ����
	VZ_ALARM_TYPE_MAX
} VZ_ALARM_TYPE;

//������Ƶ
typedef struct _VZ_IVS_DRAWMODE{
	BYTE byDspAddTarget;		//dsp���ӱ���Ŀ��
	BYTE byDspAddRule;			//dsp�������ù���
	BYTE byDspAddTrajectory;	//dsp���ӹ켣	
	BYTE dwRes[2];
}VZ_IVS_DRAWMODE;

#define IVS_MAX_MODE 4	//�豸���е����ģʽ��	
typedef struct _IVS_Ability_INFO_{
	int ModeNum;//ģʽ����
	int AbilityMask[IVS_MAX_MODE];//ģʽ����
}IVS_Ability_INFO;

typedef struct _VZ_IVS_EVENT_ABILITY{
	IVS_Ability_INFO ability_info;
	BYTE  byMaxRuleNum;		//��������	
	BYTE  byMaxTargetNum;	//���Ŀ����
}VZ_IVS_EVENT_ABILITY;

//�����豸���� 
typedef enum _IVS_TYPE_{		
	IVS_NO				= 0,	//��������Ƶ�汾
	IVS_OIL_BASE		= 1,	//���������
	IVS_OIL_FULL		= 2,	//����ȫ���ܰ�
	IVS_BEHAVIOR_BASE   = 3,	//��Ϊ����������
	IVS_BEHAVIOR_FULL   = 4,    //��Ϊ����ȫ���ܰ�
	IVS_ITS				= 5,	//���ܽ�ͨ�豸
	IVS_FIRE			= 6,    //�̻�ʶ��
	IVS_ENHANCE			= 7,    //��Ƶ��ǿ��
	IVS_ATM				= 8,	//ATM �����豸
	IVS_CARCOUNT		= 9,	//����ͳ���豸
	IVS_CAMHEALTH_SERVER= 10,	//���������״�����
	IVS_PLATER_CLIENT   = 11,	//����ʶ��ͻ���
	IVS_PLATER_SERVER   = 12,	//����ʶ�������
	IVS_PTZ				= 13,	//ptz������
	IVS_HJ_T212			= 14,	//������������豸
	IVS_PTZ_TA			= 15,	//PTZ��������ʮ������£���
	IVS_PCOUNT_SERVER	= 16,	//����ͳ����
	IVS_BEHAVIOR_BASE_HELMET = 17,	//��ȫñ���
	IVS_PACK_DETECTION	= 18,	//��λ���
	IVS_TYPE_NUM
}IVS_TYPE;


#endif

//--------------------end of vz alarm config-----------------------

//=======================ͨ�����ܹ�������======================


//���������ƣ����룩+�������ͣ��������ֲ�ͬ���������������Ҫ��+��ţ��������ֶ�η�������ͬ��������Ҫ��
#define MAKE_IVS_CMD(CMD_NAME, IVS_TYPE, CMD_SN) ((((CMD_SN)&0xFF)<<16)|(((IVS_TYPE)&0xFF)<<8)|((CMD_NAME)&0xFF))

#define GET_IVS_CMD_NAME(CMD) ((CMD)&0xFF)

#define GET_IVS_CMD_IVS_TYPE(CMD) (((CMD)>>8)&0xFF)

#define GET_IVS_CMD_SN(CMD) (((CMD)>>16)&0xFF)

#define MAX_VZIVS_CTRL_CMD_BUF_LEN	1016
typedef struct
{
	unsigned int uCMD;		//IVSͨ������
	unsigned int uLenCMD;	//����buf�ĳ���
	unsigned char buf[MAX_VZIVS_CTRL_CMD_BUF_LEN];	//IVSͨ�����������
}
VZ_IVS_CTRL;	//���ڿ��������豸��ͨ������ṹ��

//==================VS��Ϣ����====================s
#define MAXNUM_CLIENT_INFO	256
//�����ӵĿͻ�����Ϣ
typedef struct VzClientInfo
{
	unsigned char ip[4];	//IP��ַ
}
VzClientInfo;

//��Ϣ��
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
	int bTSTimeout;	//ʱ������µĹ�����Ч
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
//����Э�����ݵı���(VZ_ALARM_TYPE_PROTOCOL)���صĽṹ��
typedef struct _IVSProtocolInput
{
	char strDetail[MAX_STRLEN_PROTOCOL_DETAIL];		//��ϸ�����ݽṹ����
	int sizeParam;	//���ݽṹ�ߴ磨����ΪУ�飩
	void *pParam;	//���ݽṹָ�룬�ο���strDetail��Ӧ��ͷ�ļ��ж����
}
IVSProtocolInput;

typedef struct _IVSProtocolInputEx
{
	char strDetail[MAX_STRLEN_PROTOCOL_DETAIL];		//��ϸ�����ݽṹ����
	int sizeParam;	//���ݽṹ�ߴ磨����ΪУ�飩
	void *pParam;	//���ݽṹָ�룬�ο���strDetail��Ӧ��ͷ�ļ��ж����

	int RS485Chn;
}
IVSProtocolInputEx;



//==============�ڰ������õ����ݽṹ���궨�� start=============

#define VZ_LPR_WLIST_DATETIME_LEN	32
#define VZ_LPR_WLIST_TIME_SEG_LEN	128

#define VZ_LPR_WLIST_LP_MAX_LEN			32
#define VZ_LPR_WLIST_TIME_SEG_MAX_NUM	8

#define VZ_LPR_WLIST_MAX_KEY_LEN 32
#define	VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN 128

#define VZ_LPR_WLIST_VEHICLE_CODE_LEN		32
#define VZ_LPR_WLIST_VEHICLE_COMMENT_LEN	64
#define VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN		32

/**����ʱ������*/
typedef struct
{
	short nYear;	/**<��*/
	short nMonth;	/**<��*/
	short nMDay;	/**<��*/
	short nHour;	/**<ʱ*/
	short nMin;		/**<��*/
	short nSec;		/**<��*/
}
VZ_TM;

/**һ�������ѡ����Ĥ*/
typedef struct
{
	char bSun;		/**<����*/
	char bMon;		/**<��һ*/
	char bTue;		/**<�ܶ�*/
	char bWed;		/**<����*/
	char bThur;		/**<����*/
	char bFri;		/**<����*/
	char bSat;		/**<����*/
	char reserved;
}
VZ_TM_WEEK_DAY;

/**һ���е�ʱ����*/
typedef struct
{
	short nHour;
	short nMin;
	short nSec;
	short reserved;
}
VZ_TM_DAY;

/**ʱ�����Ϣ*/
typedef struct
{
	unsigned		uEnable;
	VZ_TM_WEEK_DAY	struDaySelect;		/**<һ���ڵ�����ѡ��*/
	VZ_TM_DAY		struDayTimeStart;	/**ÿ���ʱ�����*/
	VZ_TM_DAY		struDayTimeEnd;		/**ÿ���ʱ���յ�*/
}
VZ_TM_WEEK_SEGMENT;

typedef struct
{
	VZ_TM		struTimeStart;		/**ÿ���ʱ�����*/
	VZ_TM		struTimeEnd;		/**ÿ���ʱ���յ�*/
}
VZ_TM_RANGE;

typedef struct
{
	unsigned			uEnable;										/**�Ƿ���*/
	VZ_TM_WEEK_SEGMENT  struWeekSeg[VZ_LPR_WLIST_TIME_SEG_MAX_NUM];		/**����ʱ�������*/
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

/**�ڰ������еĳ�����¼*/
typedef struct
{
	unsigned	uVehicleID;										/**<���������ݿ��ID*/
	char		strPlateID[VZ_LPR_WLIST_LP_MAX_LEN];			/**<�����ַ���*/
	unsigned	uCustomerID;									/**<�ͻ������ݿ��ID����VZ_LPR_WLIST_CUSTOMER::uCustomerID��Ӧ*/
	unsigned	bEnable;										/**<�ü�¼��Ч���*/
	unsigned	bEnableTMEnable;								/**<�Ƿ�����Чʱ��*/
	unsigned	bEnableTMOverdule;								/**<�Ƿ�������ʱ��*/
	VZ_TM		struTMEnable;									/**<�ü�¼��Чʱ��*/
	VZ_TM		struTMOverdule;									/**<�ü�¼����ʱ��*/
	unsigned	bUsingTimeSeg;									/**<�Ƿ�ʹ������ʱ���*/
	VZ_TM_PERIOD struTimeSeg;									/**<����ʱ�����Ϣ*/
	unsigned	bAlarm;											/**<�Ƿ񴥷���������������¼��*/
	int			iColor;											/**<������ɫ*/
	int			iPlateType;										/**<��������*/
	char		strCode[VZ_LPR_WLIST_VEHICLE_CODE_LEN];			/**<��������*/
	char		strComment[VZ_LPR_WLIST_VEHICLE_COMMENT_LEN];	/**<��������*/
}
VZ_LPR_WLIST_VEHICLE;

#define VZ_LPR_WLIST_CUSTOMER_NAME_LEN		32
#define VZ_LPR_WLIST_CUSTOMER_CODE_LEN		32

/**�ڰ�������¼�Ŀͻ���Ϣ*/
typedef struct
{
	unsigned	uCustomerID;			/**<�ͻ������ݿ��ID�������޸ġ�ɾ��������������*/
	char		strName[VZ_LPR_WLIST_CUSTOMER_NAME_LEN];	/**<�ͻ�����*/
	char		strCode[VZ_LPR_WLIST_CUSTOMER_CODE_LEN];	/**<�ͻ�����*/

	char		reserved[256];
}
VZ_LPR_WLIST_CUSTOMER;

/**�ͻ����䳵���е�һ���ϳɵ�һ������*/
typedef struct
{
	VZ_LPR_WLIST_CUSTOMER *pCustomer;			/**<�ͻ�*/
	VZ_LPR_WLIST_VEHICLE *pVehicle;				/**<����������Ϊ��*/
}
VZ_LPR_WLIST_ROW;

/**������������*/
typedef struct
{
	char						key[VZ_LPR_WLIST_MAX_KEY_LEN];							/**<���ҵ��ֶ�*/
	char						search_string[VZ_LPR_WLIST_MAX_SEARCH_STRING_LEN];		/**<���ҵ��ַ���*/
}
VZ_LPR_WLIST_SEARCH_CONSTRAINT;

typedef enum
{
	VZ_LPR_WLIST_LIMIT_TYPE_ONE,						/**<����һ��*/
	VZ_LPR_WLIST_LIMIT_TYPE_ALL,						/**<��������*/
	VZ_LPR_WLIST_LIMIT_TYPE_RANGE						/**<����һ��*/
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
	VZ_LPR_WLIST_LIMIT_TYPE				limitType;					/**<������������*/
	VZ_LPR_WLIST_RANGE_LIMIT			*pRangeLimit;				/**<������һ�����ݣ���limitTypeΪVZ_LPR_WLIST_LIMIT_TYPE_RANGEʱ������*/
}
VZ_LPR_WLIST_LIMIT;

typedef enum
{
	VZ_LPR_WLIST_SORT_DIRECTION_DESC=0,
	VZ_LPR_WLIST_SORT_DIRECTION_ASC=1,
}
VZ_LPR_WLIST_SORT_DIRECTION;

/**��������з�ʽ*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	VZ_LPR_WLIST_SORT_DIRECTION direction;
}
VZ_LPR_WLIST_SORT_TYPE;

/**�������ݷ�ʽ*/
typedef enum{
	VZ_LPR_WLIST_SEARCH_TYPE_LIKE,				/**<�����ַ�*/
	VZ_LPR_WLIST_SEARCH_TYPE_EQUAL				/**<��ȫƥ��*/
}
VZ_LPR_WLIST_SEARCH_TYPE;

typedef struct{
	VZ_LPR_WLIST_SEARCH_TYPE			searchType;					/**<���ҵķ�ʽ���������ȫƥ�䣬ÿ������֮��Ϊ�룬�ǰ���ʱ��ÿ������֮��Ϊ��*/
	unsigned int						searchConstraintCount;		/**<��������������Ϊ0��ʾû����������*/
	VZ_LPR_WLIST_SEARCH_CONSTRAINT*		pSearchConstraints;			/**<������������ָ��*/
}
VZ_LPR_WLIST_SEARCH_WHERE;

typedef struct
{
	VZ_LPR_WLIST_SEARCH_WHERE			*pSearchWhere;				/**<��������*/
	VZ_LPR_WLIST_LIMIT					*pLimit;					/**<������������*/
	VZ_LPR_WLIST_SORT_TYPE				*pSortType;					/**<���������ʽ��Ϊ�ձ�ʾ��Ĭ������*/
}
VZ_LPR_WLIST_LOAD_CONDITIONS;

/**�����id����������*/
typedef struct
{
	char	key[VZ_LPR_WLIST_MAX_KEY_LEN];
	char	name[VZ_LPR_WLIST_MAX_KEY_LEN];
}
VZ_LPR_WLIST_KEY_DEFINE;

/**�����������ʵ������*/
typedef struct
{
	int		iValue;
	char	strValue[VZ_LPR_WLIST_MAX_ENUM_VALUE_LEN];
}
VZ_LPR_WLIST_ENUM_VALUE;

/**��������ÿ�еĽ��*/
typedef struct
{
	int ret;
	int error_code;
}
VZ_LPR_WLIST_IMPORT_RESULT;

typedef enum{
	VZLPRC_WLIST_CB_TYPE_ROW = 0,				/**<���ϲ�ѯ�Ľ������*/
	VZLPRC_WLIST_CB_TYPE_CUSTOMER,				/**<�ͻ���Ϣ��ѯ�Ľ������*/
	VZLPRC_WLIST_CB_TYPE_VEHICLE				/**<������Ϣ��ѯ�Ľ������*/
}
VZLPRC_WLIST_CB_TYPE;

#ifdef WIN32
#define __STDCALL __stdcall
#else
#define __STDCALL
#endif

/**
*  @brief ��������Ϳͻ���Ϣ��Ĳ�ѯ�����������
*  @param  [IN] type ���صļ�¼������
*  @param  [IN] pLP ��ѯ�ĳ�����Ϣ��¼
*  @param  [IN] pCustomer ��ѯ�Ŀͻ���Ϣ��¼
*  @param  [IN] pUserData �ص������е�������
*  @ingroup group_callback
*/
typedef void(__STDCALL *VZLPRC_WLIST_QUERY_CALLBACK)(VZLPRC_WLIST_CB_TYPE type, const VZ_LPR_WLIST_VEHICLE *pLP, \
													 const VZ_LPR_WLIST_CUSTOMER *pCustomer,    \
													 void *pUserData);


/**�������ֶ����ƣ���ѯʱʹ��*/
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

//==============�ڰ������õ����ݽṹ���궨�� end=============


//==============���������ݽṹ���궨�� start=============

// һ��ͼƬ�����������
#define MAX_FACE_COUNT 108

/**����������Ϣ*/
typedef struct tagTH_FaceRect
{
	unsigned short left;	// ��
	unsigned short top;		// ��
	unsigned short right;	// ��
	unsigned short bottom;	// ��
}TH_FaceRect;

typedef struct tagTH_FaceImg
{
	char imt_type[12];		// ͼ������ �磺bmp,jpg,jpeg
	unsigned char* img_buf; // ͼ��buf
	unsigned int img_len;	// ͼ�񳤶�
}TH_FaceImg;

typedef struct tagTH_FaceItem
{
	unsigned int face_id;		// ����ID
	short confidence;			// ���Ŷ�
	short eye_dist;				// ͫ��
	short yaw;					// ˮƽת�ǣ���ʵ������������[-180.0, 180.0]
	short pitch;				// �����ǣ���ʵ�������ϸ�����[-180.0, 180.0]
	char roll;					// ��ת�ǣ���ʵ������������[-180.0, 180.0]
	unsigned char data_type;	//  1 ���� 2 ���� 4���� 8�ȳ���
	TH_FaceRect face_rect; 		// ��������
}TH_FaceItem;

// ����ץ�Ľ����Ϣ
typedef struct tagTH_FaceResult 
{
	unsigned char trigger;  					// �������ͣ�1���Զ�ץ�ģ�2���ֶ�ץ��
	char datetime[20];							// ʱ�䣬��ʽ��yyyy-MM-dd HH:mm:ss
	unsigned int msec;							// ʱ���������
	unsigned char num;							// ��������
	TH_FaceItem face_items[MAX_FACE_COUNT];     // ������Ϣ
	TH_FaceImg face_imgs[MAX_FACE_COUNT];		// ��������ͼ��
	TH_FaceImg snap_img;						// ȫͼͼ��
	char serialno[32];							// �豸���к�
	unsigned char person_num;					// ��������
	unsigned char sex;							// 0:�У�1:Ů��2:δ֪
	unsigned char age;							// 1:���� 2:���� 3:���� 4:���꣬5:δ֪
	unsigned char have_hat;                     // 0:û��1:�У�2:δ֪
	unsigned char have_glasses;                 // 0:û��1:�У�2:δ֪
	unsigned char have_mask;                    // 0:û��1:�У�2:δ֪
	char age_real;								// ��ʵ����
	unsigned char channel_id;					// ������Ƶͨ����
	unsigned char capture_mode;                 // ץ��ģʽ 0: ����ץ�� 1:���ֱ���ģʽ
	float temperature;							// �¶�
	char device_ip[16];							// �����豸ip
	char reserved[99];							// ��������
}TH_FaceResult;

typedef struct tagTH_FaceItemEx
{
	unsigned char face_type;	//  1 ���� 2 ���� 3���� 4�ȳ���
	unsigned int face_id;		// ����ID
	unsigned char channel_id;	// ������Ƶͨ����

	char enable_temperature;
	char gate_result;			// �Ƿ�Ϊ�Ž��豸����Ľ��
	char reserved1[8];			// ��������
	
	
	//����
	short confidence;			// ���Ŷ�    ������/����/����/�ȳ���
	short eye_dist;				// ͫ��      ��������
	short yaw;					// ˮƽת�ǣ���ʵ������������[-180.0, 180.0]  ������/������
	short pitch;				// �����ǣ���ʵ�������ϸ�����[-180.0, 180.0]    ������/������
	char roll;					// ��ת�ǣ���ʵ������������[-180.0, 180.0]    ������/������
	unsigned char sex;			// 0:�У�1:Ů��2:δ֪ ��������
	unsigned char age;			// 1:���� 2:���� 3:���� 4:���꣬5:δ֪ ��������
	unsigned char have_hat;     // 0:û��1:�У�2:δ֪ ��������
	unsigned char have_glasses; // 0:û��1:�У�2:δ֪ ��������
	unsigned char have_mask;    // 0:û��1:�У�2:δ֪ ��������
	char age_real;				// ��ʵ����           ��������
	float temperature;          // �¶�               ���ȳ���
	
	int recg_face_id;			       // ʶ���������������е�id
	unsigned short recg_face_lib_id;   // ������id
	unsigned char recg_face_score;     // ʶ��������[0-100]
	unsigned char recg_sex;
	TH_FaceRect real_rect;		  // ������Сͼ�е�����
	TH_FaceRect face_rect; 		  // �������� ������/����/����/�ȳ���
	TH_FaceImg face_imgs;
	char recg_people_name[16];	  // ʶ���������
	char recg_img_url[48];        // ͼƬ·��
	char recg_birthday[12];       // ����
	char recg_prov[16];           // ����ʡ��
	char user_id[20];			  // �û��Զ�������
	char reserved_id[4];	      // idԤ��	
	int user_type;		
	char reserved[8];	
}TH_FaceItemEx;

// ����ץ�Ľ����Ϣ
#define MAX_SNAP_COUNT   5
typedef struct tagTH_FaceResultEx 
{
	unsigned char channel_id;					// ������Ƶͨ����
	unsigned char trigger;  					// �������ͣ�1���Զ�ץ�ģ�2���ֶ�ץ�ģ�3��sdkץ�ģ�4�����򱨾���
	                                            // 10���������ִ����� 11���¶ȹ��ߴ���
	char serialno[32];							// �豸���к�
	char datetime[20];							// ʱ�䣬��ʽ��yyyy-MM-dd HH:mm:ss
	unsigned int msec;							// ʱ���������
	char reserved1[10];							// ��������
	unsigned char num;							// ��������
	TH_FaceItemEx face_items[MAX_FACE_COUNT];   // ������Ϣ
	TH_FaceImg face_imgs[MAX_FACE_COUNT];		// ������ϢСͼ
	unsigned char snap_num;					    // ȫͼ����
	TH_FaceImg snap_img[MAX_SNAP_COUNT];		// ȫͼͼ��
	char device_ip[16];							// ���������ip
	char reserved2[48];							// ��������
}TH_FaceResultEx;

// ����ץ�Ĺ�������
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
	unsigned char polygon_num; // ʶ���������
	TH_FacePolygon area_polygons[MAX_RULE_POLYGON_COUNT];
}TH_FaceRuleArea;

// �������ι�������
#define MAX_SHIELD_POLYGON_COUNT 4
typedef struct tagTH_FaceShieldArea
{
	unsigned char polygon_num; // �����������
	TH_FacePolygon area_polygons[MAX_SHIELD_POLYGON_COUNT];
}TH_FaceShieldArea;


// ����SD����Ϣ
typedef struct tagTH_FaceSDInfo
{
	int sector_size;		// �豸������С
	int state;				// �豸״̬��5.���� 8.�쳣��
	long long used;			// ��λ�ֽڣ��豸ʹ�ô�С
	long long total_size;	// ��λ�ֽڣ��豸�ܴ�С�����⣩
}TH_FaceSDInfo;

// ��Ƶ����
typedef struct tagTH_FaceVideoParam
{
	short brightness;		// ���ȣ�Ĭ��ֵ50
	short contrast;			// �Աȶȣ�Ĭ��ֵ50
	short saturation;		// ���Ͷȣ�Ĭ��ֵ50
	short sharpness;		// ��ȣ�Ĭ��ֵ50
	short max_gain;			// ������棬Ĭ��ֵ50
	short max_exposure;		// �ع�ʱ��
	short flip;				// ͼ��ת��0��ԭʼͼ��1�����·�ת��2�����ҷ�ת��3�����ķ�ת��Ĭ��ֵ0
}TH_FaceVideoParam;

#define MAX_FACE_TIME_LEN 16

typedef struct tagTH_FaceDaynightParam
{
	short daynight_type;			// ��ҹת����0��ҹ�䣬1����ʱ�л���2�����죬3���Զ���4���������봥��
	short distance_level;			// ����ȼ���Ĭ��ֵ50
	short led_mode;                 // ״̬��ģʽ�� 0:���� 1������ 2������
	short sensitivity;				// �Զ�ת���������ȣ�Ĭ��ֵ3
	short filter_time;				// �Զ�ת���Ĺ���ʱ�䣬Ĭ��ֵ60
	char begin_time[MAX_FACE_TIME_LEN];	// ��ʱ�л��Ŀ�ʼʱ�䣬��ʽ��HH:mm:ss��Ĭ��ֵ07:00:00
	char end_time[MAX_FACE_TIME_LEN];	// ��ʱ�л��Ľ���ʱ�䣬��ʽ��HH:mm:ss��Ĭ��ֵ18:00:00
	short alarm_status;				// ��������״̬��0�����죬1��ҹ��Ĭ��ֵ1
}TH_FaceDaynightParam;

typedef struct tagTH_FaceVideoDaynightParam
{
	TH_FaceVideoParam video_param;			// ��Ƶ����
	TH_FaceDaynightParam daynight_param;	// ��ҹת������
}TH_FaceVideoDaynightParam;

// ��Ա��������ͳ�ƹ���
#define MAX_FLOW_POINT_COUNT 8
typedef struct tagTH_FaceFlowStatistic
{
	unsigned char is_open;     // �Ƿ�����Ա����ͳ��
	unsigned char is_area1;    // �Ƿ���������1������Աͳ��
	unsigned char is_area2;    // �Ƿ���������2������Աͳ��
	unsigned char enable_reset_count;    // �Ƿ�����ʱ��������
	char reset_time[MAX_FACE_TIME_LEN];  // ���㶨ʱ
	unsigned char point_count; // ��ĸ���
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];

}TH_FaceFlowStatistic;

typedef struct tagTH_FaceFlowStatisticEx
{
	unsigned char is_open;     // �Ƿ�����Ա����ͳ��
	unsigned char is_device_draw;     // �Ƿ����豸�˻���
	unsigned char is_area1;    // �Ƿ���������1������Աͳ��
	unsigned char is_area2;    // �Ƿ���������2������Աͳ��
	unsigned char enable_reset_count;    // �Ƿ�����ʱ��������
	char reset_time[MAX_FACE_TIME_LEN];  // ���㶨ʱ
	unsigned char point_count; // ��ĸ���
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];
	char reserved[128];						// ��������
}TH_FaceFlowStatisticEx;

typedef struct tagTH_FaceCvbsParam
{
	int cvbs;             // 1���� 0:��
	int cvbs_signal_sys;  // ����ģʽ 0��PAL, 1:NTSC
}TH_FaceCvbsParam;

// ����������
#define MAX_RULE_POLYGON_COUNT_V2 4
typedef struct 
{
	unsigned char polygon_id;				// id
	unsigned char alarm_flag;               // ������ʶ
	int           people_num;               // ����
	char reserved[20];						// ��������
}TH_AreaCountPolygon;

typedef struct 
{
	char datetime[20];						// ʱ�䣬��ʽ��yyyy-MM-dd HH:mm:ss
	unsigned int people_num;				// ��ǰ�û���������ͳ�Ƴ�����Ա����
	TH_FaceImg snap_img;					// ȫͼͼ��
	int polygon_num;                        // �������
	TH_AreaCountPolygon polygon[MAX_RULE_POLYGON_COUNT_V2];   // �������
	char reserved[20];						// ��������
}TH_AreaCountResult;

typedef struct tagTH_FaceGuideData
{
	short definition;			// ����������
	short confidence;			// ���Ŷȣ������Ƕȣ�
	int face_count;				// ��������
	TH_FaceRect face_rect; 		// ��������

}TH_FaceGuideData;

//==============���������ݽṹ���궨�� end=============


//==============�����Ž������ݽṹ���궨�� start=============
struct FaceRecoInfo {
	unsigned int sequence;  //ץ����ţ���1��ʼ��ÿ����һ��ץ����������1��
	char camId[32];         //������
	char posId[32];         //��λ���
	char posName[96];       //��λ����

	unsigned int tvSec;        //ץ��ʱ����������1970��01��01��00ʱ00��00����ץ��ʱ�侭����������
	unsigned int tvUsec;       //ץ��ʱ��΢������tvSec��β��


	short isRealtimeData;      //������ ����������+�������룩

	short matched;             //�ȶԽ����0��δ�ȶԡ�-1���ȶ�ʧ�ܡ�����0��ȡֵ���ȶԳɹ�ʱ��ȷ�Ŷȷ�����100���ƣ���
	char matchPersonId[20];    //��ԱID
	char matchPersonName[16];  //��Ա����
	int matchRole;             //��Ա��ɫ��0����ͨ��Ա�� 1����������Ա�� 2����������Ա

	int existImg;               //ȫ��ͼ���Ƿ����ȫ��ͼ��0��������ȫ��ͼ�񡣷�0������ȫ��ͼ��
	char imgFormat[4];          //ȫ��ͼ���ʽ
	int imgLen;                 //ȫ��ͼ���С
	unsigned short faceXInImg;  //����λ��ȫ��ͼ���X���ꡣ
	unsigned short faceYInImg;  //����λ��ȫ��ͼ���y����
	unsigned short faceWInImg;  //����λ��ȫ��ͼ����
	unsigned short faceHInImg;  //����λ��ȫ��ͼ��߶�

	int existFaceImg;               //����ͼ����дͼ���־���Ƿ������дͼ��0����������дͼ�񡣷�0��������дͼ��
	char faceImgFormat[4];          //����ͼ���װ��ʽ��
	int faceImgLen;                 //��дͼ���С
	unsigned short faceXInFaceImg;  //����λ����дͼ���X���ꡣ
	unsigned short faceYInFaceImg;  //����λ����дͼ���y���ꡣ
	unsigned short faceWInFaceImg;  //����λ����дͼ��Ŀ��
	unsigned short faceHInFaceImg;  //����λ����дͼ��ĸ߶�

	int existVideo;               //�Ƿ������Ƶ��0����������Ƶ����0��������Ƶ��
	unsigned int videoStartSec;   //��Ƶ��ʼʱ�䣨�룩
	unsigned int videoStartUsec;  // videoStartSecβ����΢��
	unsigned int videoEndSec;     //��Ƶ����ʱ�䣨�룩
	unsigned int videoEndUsec;    // videoEndSecβ����΢��
	char videoFormat[4];          //��Ƶ��װ��ʽ��
	int videoLen;                 //��Ƶ��С

	unsigned char sex;         //�Ա� 0: �޴���Ϣ 1���� 2��Ů
	unsigned char age;         //���� 0: �޴���Ϣ ����ֵ������
	unsigned char expression;  //���� 0: �޴���Ϣ ����ֵ����δ����
	unsigned char skinColour;  //��ɫ 0: �޴���Ϣ ����ֵ����δ����
	unsigned char qValue;      //ע���׼����������Խ��Խ�ʺ�����ע��
	char resv[123];            //���� ��һλ �Ƿ��ñ��  ��65��82 Ԥ�����֤��

	unsigned char *img;           //ȫ��ͼ������
	unsigned char *faceImg;       //��дͼ������
	unsigned char *video;         //��Ƶ����
	int feature_size;             //��ǰץ���������������ݴ�С
	float *feature;               //��ǰץ����������������
	int modelFaceImgLen;          //ģ������ͼ�񳤶�
	char modelFaceImgFmt[4];      //ģ������ͼ������
	unsigned char *modelFaceImg;  //ģ������ͼ������
};

struct FaceFlags {
	char faceID[20];		//��ԱID
	char faceName[16];		//��Ա����
	int role;				//��Ա��ɫ��0����ͨ��Ա�� 1����������Ա�� 2����������Ա��-1��������Ա��
	
	unsigned int wgCardNO;		   //Τ��Э���Ž�����
	unsigned int effectTime;	   //��Ч�ڽ�ֹʱ�䣬����Ա��Ϣ�ڸ�ʱ������Ч,��1970��1��1��0ʱ0��0�뵽��ֹʱ���������0xFFFFFFFF��ʾ������Ч��0��ʾ����ʧЧ��
	unsigned int effectStartTime;  //��Ч����ʼʱ�䣬����Ա��Ϣ�ڸ�ʱ��֮����Ч,��1970��1��1��0ʱ0��0�뵽��ʼʱ���������0��ʾδ��ʼ����

	int usr_type;			//Ȩ�����ͣ�ȡֵ 0 - 5��Ĭ�� 0
	char resv[8184];		//ǰ100�ֽ�Ԥ�����֤
};

struct FaceImage {
	int img_seq;         //ͼƬ���
	int img_fmt;         //ͼƬ��ʽ 0��jpg 1��bgr
	unsigned char *img;  //Ҫע�������ͼƬ���ݣ�֧������ͼ���ʽ
	int img_len;         //img�ĳ���
	int width;           //ͼ���ȣ�jpgͼ�������
	int height;          //ͼ��߶ȣ�jpgͼ�������
};

struct ErrorFaceImage {
	int img_seq;   //ע��ʧ�ܵ�ͼ����
	int err_code;  //ʧ�ܵĴ�����
};

//������ѯ����
struct QueryFaceFlags {
	char personID[20];         //��ԱID
	char personName[16];       //����
	int featureSize;           //�����������ݴ�С
	float feature[2048];       //������������
	int imgNum;                //ͼ����Ŀ
	int imgSize;               //ͼ���С
	unsigned char img[10240];  //ͼ������
	char resv[16];
};

//������ѯ�ص�����
struct QueryFaceInfoEx {
	int record_count;     //��ѯ�Ľ�ɫ��¼����
	int record_no;        //��ǰ�յ��ļ�¼���
	char personID[20];    //��ԱID
	char personName[16];  //����
	int role;			  //��Ա��ɫ 0����ͨ��Ա�� 1����������Ա�� 2����������Ա�� //-1��������Ա��

	int imgNum;           //ģ��ͼ������
	int imgSize[5];       //ͼ���С��imgSize[i]Ϊ��i��ͼƬ�Ĵ�С
	char imgFmt[5][4];    //ͼ���ʽ,imgFmt[i]Ϊ��i��ͼƬ�ĸ�ʽ
	unsigned char *imgBuff[5];     // imgBuff[i]λ��i��ͼƬ�������׵�ַ
	unsigned int wgCardNO;         // Τ���Ž�����
	unsigned int effectTime;       // ��Ч�ڽ�ֹʱ�䣬����Ա��Ϣ�ڸ�ʱ������Ч,��1970��1��1��0ʱ0��0�뵽��ֹʱ���������0xFFFFFFFF��ʾ������Ч��0��ʾ����ʧЧ��
	unsigned int effectStartTime;  // ��Ч����ʼʱ�䣬����Ա��Ϣ�ڸ�ʱ��֮����Ч,��1970��1��1��0ʱ0��0�뵽��ʼʱ���������0��ʾδ��ʼ����
	char idcardper[100];           // ���֤��
	int user_type;                 // Ȩ��
	char resv[128];
};


/// ץ�ıȶԼ�¼��
struct RecordData {
	/*! ��ѯ�Ľ�ɫ��¼���� */
	int record_count;

	/*! ��ǰ�յ��ļ�¼��� */
	int record_no;

	/*! ץ�ļ�¼���к� */
	unsigned int sequence;

	/*! ץ��ʱ����������1970��01��01��00ʱ00��00����ץ��ʱ�侭���������� */
	unsigned int tvSec;

	/*! ץ��ʱ��΢������tvSec��β�� */
	unsigned int tvUsec;

	/*! �ȶ�״̬(����) */
	short matched;

	/*! �Ա� */
	unsigned char sex;

	/*! ����*/
	unsigned char age;

	/*! �ȶ��ϵ���Աid */
	char person_id[20];

	/*! �ȶ��ϵ���Ա���� */
	char person_name[16];

	/*��ʵʱ����ͼ�񳤶� */
	int face_image_len;

	/*��ʵʱ����ͼ��jpg��ʽ�� */
	unsigned char *face_image;

	/*! ����λ����дͼ���X���ꡣ */
	unsigned short faceXInFaceImg;

	/*! ����λ����дͼ���y���ꡣ */
	unsigned short faceYInFaceImg;

	/*! ����λ����дͼ��Ŀ�� */
	unsigned short faceWInFaceImg;

	/*! ����λ����дͼ��ĸ߶� */
	unsigned short faceHInFaceImg;

	/*���ȶ��ϵ�ע������ͼ�񳤶ȣ�δ�ȶ���ʱΪ0*/
	int reg_image_len;

	/*���ȶ��ϵ�ע������ͼ��jpg��ʽ����δ�ȶ���ʱΪNULL */
	unsigned char *reg_image;

	/*! ���������� */
	unsigned char qvalue;

	/*! ��¼�Ƿ����ϴ� 1:��ʾ�Ѿ��ϴ� 0����ʾδ�ϴ�*/
	char is_upload;

	/*! ���� */
	char resv[2];
};


//ϵͳ������Ϣ
struct SystemNetInfo {
	char mac_addr[18];  //���������ַ
	char ip_addr[16];   //���ip��ַ
	char netmask[16];   //��������
	char gateway[16];   //Ĭ������
	char dns[16];		//�豸dns
	char dns1[16];		//����dns
	char resv[14];      //����
};

//ϵͳ�汾��Ϣ
struct SystemVersionInfo {
	char dev_id[32];              //�豸���к�
	char protocol_ver[8];         //Э��汾
	char firmware_ver[16];        //�̼��汾
	char code_ver[8];             //Ӧ�ó���汾
	char build_time[20];          //Ӧ�ñ���ʱ��
	char resv[16];                //����
	char systemp_type[16];        //ϵͳ����
	char plateform[16];           //Ӳ��ƽ̨
	char sensor_type[16];         //�������ͺ�
	char algorithm_ver[16];       //�㷨�汾
	char min_sdk_ver[16];         //���sdk�汾
	unsigned int min_client_ver;  //��Ϳͻ��˰汾
};

struct ha_rect {
	short x;       //���������������Ͻ�x����
	short y;       //���������������Ͻ�y����
	short width;   //��������������
	short height;  //������������߶�
};

struct FaceRect {
	unsigned int faceId;      //��������id
	struct ha_rect faceRect;  //������������
	char resv[4];
};

struct FaceRectInfo {
	char idShowFlag;
	char resv[3];
	int rectNum;  
	struct FaceRect faceRects[32];
};

struct FaceDelProgressInfo {
	int delCount;     //ɾ���ļ�¼����
	int curDelNo;     //��ǰɾ���ڼ�����¼
	char faceId[20];  //��ǰɾ������ԱID
};

struct FaceReRegistProgressInfo {
	int regist_count;   //��ע�����Ա����
	int cur_regist_no;  //��ǰ��ע��ڼ�����¼
	char faceId[20];    //��ǰ��ע�����Աid
};

struct DebugImage {
	int format;              //����ͼ���ʽ, 1:jpg
	short width;             //����ͼ����
	short height;            //����ͼ��߶�
	int imageLen;            //ͼ�����ݳ���
	unsigned char *imgData;  //ͼ������
};

struct DebugImageInfo {
	unsigned int timeStamp_s;  //ʱ��� ��
	unsigned int timeStamp_u;  //ʱ��� ΢��
	int matched;			   //�ȶԽ����0��δ�ȶԡ�-1���ȶ�ʧ�ܡ�1���ȶԳɹ�
	int matchScore;            //�ȶԷ���
	char faceId[20];           //�ȶ��ϵ���Աid��matched����1ʱ��Ч
	int imageNum;			   //����ͼ�����������֧��6��ͼ��
	struct DebugImage debugImage[6];  //����ͼ����Ϣ
};

//==============�����Ž������ݽṹ���궨�� end=============

//==============����ʶ���� end=============
// ����ʶ����ز���
//---------------------------------------//
//������ɫ
#define LC_UNKNOWN  0  //δ֪
#define LC_BLUE     1  //��ɫ
#define LC_YELLOW   2  //��ɫ 
#define LC_WHITE    3  //��ɫ
#define LC_BLACK    4  //��ɫ
#define LC_GREEN    5  //��ɫ

// ����ʶ����ز���
//---------------------------------------//
//������ɫ
#define LC_UNKNOWN  0  //δ֪
#define LC_BLUE     1  //��ɫ
#define LC_YELLOW   2  //��ɫ 
#define LC_WHITE    3  //��ɫ
#define LC_BLACK    4  //��ɫ
#define LC_GREEN    5  //��ɫ

//��������
#define LT_UNKNOWN  0   //δ֪����
#define LT_BLUE     1   //����С����
#define LT_BLACK    2   //����С����
#define LT_YELLOW   3   //���Ż���
#define LT_YELLOW2  4   //˫�Ż��ƣ���β�ƣ�ũ�ó���
#define LT_POLICE   5   //��������
#define LT_ARMPOL   6   //�侯����
#define LT_INDIVI   7   //���Ի�����
#define LT_ARMY     8   //���ž�����
#define LT_ARMY2    9   //˫�ž�����
#define LT_EMBASSY  10  //ʹ�ݳ���
#define LT_HONGKONG 11  //��۽����й���½����
#define LT_TRACTOR  12  //ũ�ó���
#define LT_COACH	13  //��������
#define LT_MACAO	14  //���Ž����й���½����
#define LT_ARMPOL2   15 //˫���侯����
#define LT_ARMPOL_ZONGDUI 16  // �侯�ܶӳ���
#define LT_ARMPOL2_ZONGDUI 17 // ˫���侯�ܶӳ���
#define LI_AVIATION  18   //��
#define LI_ENERGY    19   //����Դ
#define LI_ENERGY2     20   //��������Դ
#define LI_EMERGENCY   21   //Ӧ������
#define LI_CONSULATE   22   //���¹�

#define LI_FAKEPLATE 27 // ������ٳ��ƾ���
#define LI_CAR_COLOR 28 // ������ɫ
#define LI_CAR_TYPE  29 // ��������
#define LI_CAR_BRAND 30 // ���공��
#define LI_NOPLATE   31 // ���Ƴ���Ϣ


//�˶�����
#define DIRECTION_LEFT	1  //��
#define DIRECTION_RIGHT	2  //��
#define DIRECTION_UP	3  //��
#define DIRECTION_DOWN	4  //��

//ͼ���ʽ��TH_SetImageFormat������cImageFormat������
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

//������ɫ
#define LGRAY_DARK	0	//��
#define LGRAY_LIGHT	1	//ǳ

#define LCOLOUR_WHITE	0	//��	
#define LCOLOUR_SILVER	1	//��(��)
#define LCOLOUR_YELLOW	2	//��
#define LCOLOUR_PINK	3	//��
#define LCOLOUR_RED		4	//��
#define LCOLOUR_GREEN	5	//��
#define LCOLOUR_BLUE	6	//��
#define LCOLOUR_BROWN	7	//�� 
#define LCOLOUR_BLACK	8	//��

// ����ʶ�����Ͷ���
typedef enum _TH_TRIGGER_TYPE
{
	TRIGGER_TYPE_AUTO		=	0,		//�Զ�
	TRIGGER_TYPE_EXTERNAL	=	1,		//�ⲿ
	TRIGGER_TYPE_SOFTWARE	=	2,		//���
	TRIGGER_TYPE_VLOOP					//����ظ���Ȧ
}TH_TRIGGER_TYPE;

typedef enum
{
	TRIGGER_TYPE_AUTO_BIT		= 1,    //�Զ�
	TRIGGER_TYPE_EXTERNAL_BIT	= 1<<1, //�ⲿ
	TRIGGER_TYPE_SOFTWARE_BIT	= 1<<2, //���
	TRIGGER_TYPE_VLOOP_BIT		= 1<<3  //����ظ���Ȧ
}TH_TRIGGER_TYPE_BIT;

/**����������Ϣ*/
typedef struct TH_RECT
{
	int left;	/**<��*/
	int top;	/**<��*/
	int right;	/**<��*/
	int bottom;	/**<��*/
}TH_RECT;

typedef struct TH_TimeVal
{
	long    tv_sec;         /* �� */
	long    tv_usec;        /* ΢�� */
	long	tv_frameStamp;	/* ֡��� */
}TH_TimeVal;

typedef struct
{
	unsigned uTVSec;
	unsigned uTVUSec;
}
VZ_TIMEVAL;

typedef struct CarBrand
{
	char brand;     // Ʒ��
	char type;      // ����
	unsigned short year;      // ���
} CarBrand;

#define TH_LP_LEN	16

/**����ʶ������Ϣ*/
typedef struct TH_PlateResult 
{
	char license[TH_LP_LEN];  	/**<���ƺ���*/
	char color[8];      		/**<������ɫ*/
	int nColor;					/**<������ɫ��ţ����������ɫ����LC_X*/
	int nType;					/**<�������ͣ�����������Ͷ���LT_X*/
	int nConfidence;			/**<���ƿ��Ŷ�*/
	int nBright;				/**<��������*/
	int nDirection;				/**<�˶���������˶������� DIRECTION_X*/
	TH_RECT rcLocation; 		/**<����λ��*/
	int nTime;          		/**<ʶ������ʱ��*/
	VZ_TIMEVAL tvPTS;			/**<ʶ��ʱ���*/
	unsigned uBitsTrigType;		/**<ǿ�ƴ������������,��TH_TRIGGER_TYPE_BIT*/
	unsigned char nCarBright;	/**<��������*/
	unsigned char nCarColor;	/**<������ɫ�����������ɫ����LCOLOUR_X*/
	char reserved0;				/**Ϊ�˶���*/
	unsigned char ucWLResult;   /**������״̬�������������֤�������*/
	unsigned uId; 				/**<��¼�ı��*/
	VzBDTime    struBDTime;     /**<�ֽ�ʱ��*/
	unsigned char nIsEncrypt;          /**<�����Ƿ����*/
	unsigned char nPlateTrueWidth;     /**<���Ƶ���ʵ��ȣ���λcm*/
	unsigned char nPlateDistance;      /**<���ƾ��������λ�ã���λdm(����)*/
	unsigned char nIsFakePlate;        /**�Ƿ���α����*/
	TH_RECT     car_location;   /**<����λ��*/
	CarBrand    car_brand;      /**<����Ʒ��*/
	char featureCode[20];       /**<����������*/
	char reserved1[24];			/**<����*/     
}TH_PlateResult;

/**����ʶ������ͨ����������֤�Ľ��*/
typedef enum
{
	VZ_LPWL_UNHANDLE,       /**<δ����*/
	VZ_LPWL_VALID,          /**<�ڰ������У�����Ч*/
	VZ_LPWL_INVALID,        /**<���ڰ������У�����֤δͨ��*/
	VZ_LPWL_NO_LICENCE,     /**<�޳���*/
	VZ_LPWL_BLACK_LIST,     /**<������*/
	VZ_LPWL_DISABLE,        /**<�ڰ������У�����¼��Ч*/
	VZ_LPWL_START_TIMEOUT,  /**<�ڰ������У�����¼��δ����ʼ��Ч��*/
	VZ_LPWL_END_TIMEOUT,    /**<�ڰ������У�����¼����������Ч��*/
	VZ_LPWL_SEG_TIMEOUT,    /**<�ڰ������У�����¼������Чʱ�����*/
	VZ_LPWL_SPECIAL_PLATE,  /**<���⳵��*/
	VZ_LPWL_RESULT_COUNT,
}
VZ_LPWL_RESULT;

/**����ʶ�����İ�������Ϣ��չ*/
typedef struct
{
	VzBDTime struTimeOverdue;   /**<��������Ӧ��¼����ʱ��*/
	char strComment[32];        /**<��Ȩ��*/
	char strCode[64];           /**<�û�ID*/
	unsigned char ucWLResult;   /**<����������״̬�������������֤�������*/
	unsigned char ucRes[3];
}
VZ_LPWL_INFO;

#define ENCRYPT_NAME_LENGTH 32

/**��������**/
typedef struct
{
	unsigned uId;						//����ID
	char sName[ENCRYPT_NAME_LENGTH];	//������
}VZ_EMS_INFO;

#define ENCRYPT_LENGTH 16
#define SIGNATURE_LENGTH 32

/**��ǰʶ������������**/
typedef struct
{
	unsigned uActiveID;						//��ǰ��������ID
	VZ_EMS_INFO oEncrpty[ENCRYPT_LENGTH];	//ϵͳ��������
	unsigned uSize;							//ϵͳ�������ͳ���
	char signature[SIGNATURE_LENGTH];		//SIGNATURE
}VZ_LPRC_ACTIVE_ENCRYPT;

/**********��ǰ�������豸��Ϣ**************/
#define IPADDR_LENGTH 16
#define OVZID_NAME_LEN 385
#define SN_LEN 32

typedef struct
{
	unsigned enable_group;				// �Ƿ��������
	char ip_addr[IPADDR_LENGTH];		// �豸IP
	char name[OVZID_NAME_LEN];			// ����������
	char original_name[OVZID_NAME_LEN];	// δ����֮ǰ������
	char sn[SN_LEN];					// �豸���к�
	unsigned type;						// 0δ������1�����豸, 2�����豸
}VZ_OVZID_INFO;

#define OVZID_COUNT 64
typedef struct
{
	VZ_OVZID_INFO info[OVZID_COUNT];
	unsigned uCount;
}VZ_OVZID_RESULT;


//�����豸��Ϣ
typedef struct
{
	char vzName[128];               //ʶ������Դ�豸����
	char vzIP[16];                  //ʶ������Դ�豸IP
	char vzSN[24];                  //ʶ������Դ�豸���к�
	char vzType;                    //����ʶ�����豸���ͣ�0 : ��� 1 �� ����
} IVS_DG_DEVICE_INFO;

/**�ɹ��˵ĳ���ʶ�𴥷�����*/
#define VZ_LPRC_TRIG_ENABLE_STABLE      0x1     /**<�������ȶ����*/
#define VZ_LPRC_TRIG_ENABLE_VLOOP       0x2     /**<������������Ȧ���*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN1      0x10    /**<�����ⲿIO_IN_1����*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN2      0x20    /**<�����ⲿIO_IN_2����*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN3      0x40    /**<�����ⲿIO_IN_3����*/
#define VZ_LPRC_TRIG_ENABLE_IO_IN4      0x80    /**<�����ⲿIO_IN_4����*/


#define   LPRC_CENTER_IPLEN  200
typedef struct      //���ķ���������
{
	char centerServerIp[LPRC_CENTER_IPLEN];   //���ķ�������ַ
	WORD port;                         //���ķ������˿�
	bool enableSsl;                    //�Ƿ�ʹ��sslЭ��
	WORD sslPort;                      //sslЭ��˿� 
	WORD timeout;                      //��ʱʱ�����ô���, ��Χ��1~30��

}VZ_LPRC_CENTER_SERVER_NET;

/*ץ�Ľ����������*/
typedef struct
{
	unsigned char enable;	//Ĭ�ϲ�����
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//���͵�ַ
	unsigned level;	//���ͽ������1 ����ͼ 2 ����ͼ 4 ����ͼ 8 ����ͼ �������ͬʱ��ѡ���û�ķ�ʽ������� 0������ͼ��
}
VZ_CENTER_SERVER_ALARM_PARAM;

/*��Ա����ͳ����������*/
typedef struct
{
	unsigned char enable;	//Ĭ�ϲ�����
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//���͵�ַ
	unsigned interval;	//���ͼ��ʱ��
}
VZ_CENTER_SERVER_TRIPWIRE_PARAM;

/*���������������*/
typedef struct
{
	unsigned char enable;
	char uri[PUSH_ADDR_BUFFER_MAX_SIZE];	//���͵�ַ
	unsigned interval;	//���ͼ��ʱ��
	unsigned level;	//�����������ͼƬ���ݵȼ� ��0 ��ͼ 1 ����ͼ)
}
VZ_CENTER_SERVER_AREA_PEOPLE_COUNT_PARAM;

#define  URLLENGTH 1000
typedef struct      //���ķ����������豸ע��
{
	BYTE type;                         //���ķ������豸ע������
	char url[URLLENGTH];               //���ķ������豸ע���ַ
}VZ_LPRC_CENTER_SERVER_DEVICE_REG;

typedef VZ_LPRC_CENTER_SERVER_NET VZ_CENTER_SERVER_INFO;
typedef VZ_LPRC_CENTER_SERVER_DEVICE_REG VZ_CENTER_SERVER_DEV_REG;

typedef struct       //���ķ��������糵��
{
	char url[URLLENGTH];               //���ķ��������Ƶ�ַ
	bool enable;                       //���ķ�������������ʹ��
	BYTE contentLevel;                 //���ķ���������������ϸ�ȼ�
	bool sendLargeImage;               //���ķ����������Ƿ��ʹ�ͼƬ
	bool sendSmallImage;               //���ķ����������Ƿ���СͼƬ
}VZ_LPRC_CENTER_SERVER_PLATE;

typedef struct						   //���ķ����������豸�˿ڴ���
{
	bool enable;                       //���ķ����������豸�˿ڴ���ʹ��
	char url[URLLENGTH];               //���ķ����������豸�˿ڴ�����ַ
}VZ_LPRC_CENTER_SERVER_GIONIN;

typedef struct      //���ķ����������豸����
{
	bool enable;                         //���ķ����������豸����ʹ��
	char url[URLLENGTH];               //���ķ����������豸���ڵ�ַ
}VZ_LPRC_CENTER_SERVER_SERIAL;

typedef struct
{
	int default_stream;  /* ��ǰѡ������� */
	int stream_id;       /* �������� */
	int resolution;      /* �ֱ���; */
	int frame_rate;      /* [0, 25]��֡��; */
	int encode_type;     /* h264; */
	int rate_type;       /* �������ͣ���Ӧ��������; */
	int data_rate;       /* ��������; */
	int video_quality;   /* ��Ƶ����; */
}VZ_LPRC_R_ENCODE_PARAM;

#define  VZ_LPRC_MAX_RESOLUTION 12
#define  VZ_LPRC_MAX_RATE 5
#define  VZ_LPRC_MAX_VIDEO_QUALITY 12
#define  VZ_LPRC_MAX_ENCODE_TYPE 5
#define  VZ_LPRC_MAX_STREAM_TYPE 5
#define  VZ_LPRC_MAX_STREAM_COUNT 5

typedef struct
{
	int resolution_type;			/* �������� */
	char resolution_content[32];    /* �������� */

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
	int encode_stream;												/* ��ǰѡ������� */
	int resolution_cur;				/* �ֱ���   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* �ֱ���	*/			
	int frame_rate_cur;												/* ��ǰ֡��; */
	int frame_rate_min;												/* ��С֡��; */
	int frame_rate_max;												/* ���֡��; */
	int rate_type_cur;							/* ���ʿ��� */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* ��������; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;						/* ��Ƶ����; */
	VZ_LPRC_R_VIDEO_QUALITY video_quality[VZ_LPRC_MAX_VIDEO_QUALITY];

}VZ_LPRC_R_ENCODE_PARAM_PROPERTY;

typedef struct
{
	int encode_type;
	char content[32];
}VZ_LPRC_ENCODE_TYPE;

typedef struct
{
	int encode_stream;												/* ��ǰѡ������� */
	int resolution_cur;												/* �ֱ���   */
	VZ_LPRC_R_RESOLUTION resolution[VZ_LPRC_MAX_RESOLUTION];		/* �ֱ���	*/			
	int frame_rate_cur;												/* ��ǰ֡��; */
	int frame_rate_min;												/* ��С֡��; */
	int frame_rate_max;												/* ���֡��; */
	int rate_type_cur;												/* ���ʿ��� */
	VZ_LPRC_R_RATE_TYPE rate_type[VZ_LPRC_MAX_RATE];
	int data_rate_cur;												/* ��������; */
	int data_rate_min;							
	int data_rate_max;
	int video_quality_cur;											/* ��Ƶ����; */
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
	char imt_type[12];		// ͼ������ �磺bmp,jpg,jpeg
	unsigned char* img_buf; // ͼ��buf
	unsigned int img_len;	// ͼ�񳤶�
}TH_ImgInfo;

//==============����ʶ���� end=============

//==============·�ඨ�� start=============
#define MAX_BERTH_COUNT  16

typedef struct{
	int berth_number;				// ��λ���
	int berth_state;                // ��λ״̬ ��1.�볡 2.���� 0.�ޣ�
	char license[TH_LP_LEN];  	    // ���ƺ���
} TH_RoadSiteBerth;

/**����ʶ������Ϣ*/
typedef struct 
{
	TH_PlateResult plate_result;
	TH_RECT berth_location;					 // ��λͼλ��
	int berth_state;						 // ��λͼ״̬��1.�볡 2.���� 0.�ޣ�
	int berth_number;						 // ��λ���
	char berth_name[32];					 // ��λ����
	TH_ImgInfo full_img[3];					 // ȫͼ(3��ʱ�̵�ͼƬ)
	TH_ImgInfo clip_img;					 // ����ͼƬ
	TH_RoadSiteBerth berth[MAX_BERTH_COUNT]; // ��λ��Ϣ
	int berth_count;			             // ��λ����
	char reserved1[128];		             // Ԥ������
}TH_RoadSiteResult;

//==============·�ඨ�� end=============


//==============�ӿڲ������� start=============
/** LASTERROR ���� */
typedef enum {
	VZ_LPRC_LASTERROR_SUCCESS,              /**<�����ɹ���� */
	VZ_LPRC_LASTERROR_NOT_SETUP,            /**<δ���� Setup ���� */
	VZ_LPRC_LASTERROR_CREATE_FAILED,        /**<���� LPRC_OBJ ʧ�� */
	VZ_LPRC_LASTERROR_CONNECT_FAILED,       /**<�豸����ʧ�� */
	VZ_LPRC_LASTERROR_INVALID_HANDLE,       /**<LPRC_OBJ ��������� */
	VZ_LPRC_LASTERROR_INVALID_IP,           /**<IP ������ */
	VZ_LPRC_LASTERROR_NOT_FOUND_IP,         /**<δ���ָ� IP */
	VZ_LPRC_LASTERROR_INVALID_PSTATUS,      /**<��ȡ״̬�ı�����ַ������ */
	VZ_LPRC_LASTERROR_REALPLAY_FAILED,      /**<����ʵʱ��Ƶʧ�� */
	VZ_LPRC_LASTERROR_NOT_FOUND_PLAYHANDLE, /**<��Ƶ���ž������ʧ�� */
	VZ_LPRC_LASTERROR_CALLBACK_ERROR,       /**<�ص��������ʹ��� */
	VZ_LPRC_LASTERROR_IMAGEFORMAT_ERROR,    /**<ͼƬ��ʽΪ�� BGR ��ʽ */
	VZ_LPRC_LASTERROR_NULL_IMGINFO,         /**<ͼ��ṹ���ַ������ */
	/**<ͼ��ṹ���ַ�����û� JPEG ��Ŀ�Ĵ洢��ַ������ */
	VZ_LPRC_LASTERROR_WRONG_IMGINFO_DSTBUF,
	VZ_LPRC_LASTERROR_IOOUTPUT_ERROR,       /**<IO ��ȡ���״̬�ĵ�ַ������ */
	VZ_LPRC_LASTERROR_INVALID_SERIALHANDLE, /**<͸��ͨ����������� */
	VZ_LPRC_LASTERROR_INVALID_WHITELIST,    /**<��������������� */
	VZ_LPRC_LASTERROR_INVALID_FILENAME,     /**<�ļ��������� */
	VZ_LPRC_LASTERROR_SEARCHSET_ERROR,      /**<��ѯ���ƺŷ�ҳ��¼��ֹλ�����ô��� */
	/**<��ȡ����ͼƬͼƬ�ڴ��ַ�����û�ͼƬ�ڴ��С���ô����ͼƬ�ڴ��С��ַ������ */
	VZ_LPRC_LASTERROR_GETPLATE_ERROR,
	VZ_LPRC_LASTERROR_PLATESIZE_ERROR,      /**<��Ƶͼ��߶Ȼ��ȱ�����ַ������ */
	VZ_LPRC_LASTERROR_ENCODE_TYPE_ERROR,    /**<��ȡ���뷽ʽ�ĵ�ַ������ */
	VZ_LPRC_LASTERROR_GPIO_STATUS_ERROR,    /**<��ȡ GPIO ״̬�ĵ�ַ������ */
	VZ_LPRC_LASTERROR_GPIO_NUMBER_ERROR,    /**<GPIO ��Ų����� */
	VZ_LPRC_LASTERROR_INVALID_FILEPATH,     /**<�ļ�·�������� */
	VZ_LPRC_LASTERROR_EDITION_ERROR,        /**<��ȡ�����ļ��汾���ڴ��ַ������ */
	VZ_LPRC_LASTERROR_DBERROR_PLATEID_EXISTS,     /**<����ID�Ѿ����� */
	VZ_LPRC_LASTERROR_DBERROR_INSERT_CUSTOMERINFO_FAILED, /**<��ӿͻ����ϳ��� */
	VZ_LPRC_LASTERROR_DBERROR_INSERT_VEHICLEINFO_FAILED,  /**<��Ӱ��������� */
	VZ_LPRC_LASTERROR_DBERROR_UPDATE_CUSTOMERINFO_FAILED, /**<���¿ͻ����ϳ��� */
	VZ_LPRC_LASTERROR_DBERROR_UPDATE_VEHICLEINFO_FAILED,  /**<���°��������� */
	VZ_LPRC_LASTERROR_DBERROR_PLATEID_EMPTY,  /**<����������IDΪ�� */
	VZ_LPRC_LASTERROR_DBERROR_ROW_NOT_CHANGED,    /**<����ʧ�� */
	VZ_LPRC_LASTERROR_DBERROR_CUSTOMERINFO_NOT_CHANGED,   /**<�ͻ�����δ���� */
	VZ_LPRC_LASTERROR_DBERROR_VEHICLEINFO_NOT_CHANGED,    /**<����������δ���� */
	/**<�ͻ��������������ƥ�� */
	VZ_LPRC_LASTERROR_DBERROR_CUSTOMER_VEHICLE_NOT_MATCH,
	VZ_LPRC_LASTERROR_DBERROR_SQLERRORCODESERVERGONE  /**<SQLite�������˳��� */
}
VZ_LPRC_LASTERROR_TYPE;

/**���ûص�����ʱ��Ҫָ��������*/
typedef enum {
	VZ_LPRC_CALLBACK_COMMON_NOTIFY, /**<SDKͨ����Ϣ������Ԥ����*/
	VZ_LPRC_CALLBACK_PLATE_STR,   /**<���ƺ����ַ���Ԥ����*/
	VZ_LRPC_CALLBACK_FULL_IMAGE,  /**<����ͼ��*/
	VZ_LPRC_CALLBACK_CLIP_IMAGE,  /**<��ȡͼ��*/
	VZ_LPRC_CALLBACK_PLATE_RESULT, /**<ʵʱʶ����*/
	VZ_LPRC_CALLBACK_PLATE_RESULT_STABLE, /**<�ȶ�ʶ����*/
	/**<������ʶ����������API���������IO��Ӳ������ʽ��*/
	VZ_LPRC_CALLBACK_PLATE_RESULT_TRIGGER,
	VZ_LPRC_CALLBACK_VIDEO,   /**<��Ƶ֡�ص�*/
}
VZ_LPRC_CALLBACK_TYPE;

/**ͨ����Ϣ��������*/
typedef enum {
	VZ_LPRC_NO_ERR = 0, /**<�޴���*/
	VZ_LPRC_ACCESS_DENIED,  /**<�û����������*/
	VZ_LPRC_NETWORK_ERR,  /**<�������ӹ���*/
	VZ_LPRC_ONLINE,     /**<�豸����*/
	VZ_LPRC_OFFLINE,    /**<�豸����*/
	VZ_LPRC_IO_INPUT = 100, /**<IO�������ź�*/
}
VZ_LPRC_COMMON_NOTIFY;

typedef enum {
	VZ_NO_ERR = 0, /**<�޴���*/
	VZ_ACCESS_DENIED,  /**<�û����������*/
	VZ_NETWORK_ERR,  /**<�������ӹ���*/
	VZ_ONLINE,     /**<�豸����*/
	VZ_OFFLINE,    /**<�豸����*/
	VZ_IO_INPUT = 100, /**<IO�������ź�*/
}
VZ_COMMON_NOTIFY;

/**ʶ����������*/
typedef enum {
	VZ_LPRC_RESULT_REALTIME,  /**<ʵʱʶ����*/
	VZ_LPRC_RESULT_STABLE,  /**<�ȶ�ʶ����*/
	/**<���á�VzLPRClient_ForceTrigger��������ʶ����*/
	VZ_LPRC_RESULT_FORCE_TRIGGER,
	VZ_LPRC_RESULT_IO_TRIGGER,  /**<�ⲿIO�źŴ�����ʶ����*/
	VZ_LPRC_RESULT_VLOOP_TRIGGER, /**<������Ȧ������ʶ����*/
	/**<��_FORCE_\_IO_\_VLOOP_�е�һ�ֻ����ͬʱ������������Ҫ����ÿ��ʶ������TH
	* _PlateResult::uBitsTrigType���ж�*
	*/
	VZ_LPRC_RESULT_MULTI_TRIGGER,
	VZ_LPRC_RESULT_TYPE_NUM /**<����������*/
} VZ_LPRC_RESULT_TYPE;

/**���㶨��
*X_1000��Y_1000��ȡֵ��ΧΪ[0, 1000]��
*��λ����ϢΪʵ��ͼ��λ��������ͼ��λ�õ���Գߴ磻
*����X_1000 = x*1000/win_width������xΪ����ͼ���е�ˮƽ����λ�ã�win_widthΪͼ����
*/
typedef struct {
	unsigned X_1000;  /**<ˮƽ�����������*/
	unsigned Y_1000;  /**<��ֱ�����������*/
} VZ_LPRC_VERTEX;

/**��Խ����ö��*/
typedef enum {
	VZ_LPRC_BIDIR,  /**˫�򴥷�*/
	VZ_LPRC_UP2DOWN,  /**���ϵ��·���ĳ�������*/
	VZ_LPRC_DOWN2UP,  /**���µ��Ϸ���ĳ�������*/
}
VZ_LPRC_DIR;
/**������Ȧ����*/
#define VZ_LPRC_VIRTUAL_LOOP_NAME_LEN 32

/**������Ȧ�������*/
#define VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM 4

/**������Ȧ��Ϣ����*/
typedef struct {
	BYTE byID;  /**<���*/
	BYTE byEnable;  /**<�Ƿ���Ч*/
	BYTE byDraw;  /**<�Ƿ����*/
	BYTE byRes[1];  /**<Ԥ��*/
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<�Զ�������*/
	VZ_LPRC_VERTEX struVertex[VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM];  /**<��������*/
	VZ_LPRC_DIR eCrossDir;  /**<��Խ��������*/
	unsigned uTriggerTimeGap; /**����ͬ���ƵĴ���ʱ���������ƣ���λΪ��*/
	unsigned uMaxLPWidth;  /**����Ƴߴ�����*/
	unsigned uMinLPWidth;  /**��С���Ƴߴ�����*/
}
VZ_LPRC_VIRTUAL_LOOP;

/**���������Ȧ����*/
#define VZ_LPRC_VIRTUAL_LOOP_MAX_NUM  8

/**������Ȧ����*/
typedef struct {
	unsigned uNumVirtualLoop;	/**<ʵ�ʸ���*/
	/**<������Ȧ����*/
	VZ_LPRC_VIRTUAL_LOOP struLoop[VZ_LPRC_VIRTUAL_LOOP_MAX_NUM];
}
VZ_LPRC_VIRTUAL_LOOPS;

/**������Ȧ�������*/
#define VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM_EX  12

/**������Ȧ��Ϣ����*/
typedef struct {
	BYTE byID;  /**<���*/
	BYTE byEnable;  /**<�Ƿ���Ч*/
	BYTE byDraw;  /**<�Ƿ����*/
	BYTE byRes[1];  /**<Ԥ��*/
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<�Զ�������*/
	unsigned uNumVertex;  /**<����ʵ�ʸ���*/
	VZ_LPRC_VERTEX struVertex[VZ_LPRC_VIRTUAL_LOOP_VERTEX_NUM_EX];  /**<��������*/
	VZ_LPRC_DIR eCrossDir;  /**<��Խ��������*/
	unsigned uTriggerTimeGap; /**����ͬ���ƵĴ���ʱ���������ƣ���λΪ��*/
	unsigned uMaxLPWidth;  /**����Ƴߴ�����*/
	unsigned uMinLPWidth;  /**��С���Ƴߴ�����*/
}
VZ_LPRC_VIRTUAL_LOOP_EX;

/**������Ȧ����*/
typedef struct {
	unsigned uNumVirtualLoop;	 /**<ʵ�ʸ���*/
	/**<������Ȧ����*/
	VZ_LPRC_VIRTUAL_LOOP_EX struLoop[VZ_LPRC_VIRTUAL_LOOP_MAX_NUM];
}
VZ_LPRC_VIRTUAL_LOOPS_EX;

/**ʶ�����򶥵����*/
#define VZ_LPRC_ROI_VERTEX_NUM  4

/**ʶ��������Ϣ����*/
typedef struct {
	BYTE            byRes1;     /**<Ԥ��*/
	BYTE            byEnable;   /**<�Ƿ���Ч*/
	BYTE            byDraw;     /**<�Ƿ����*/
	BYTE            byRes2;     /**<Ԥ��*/
	BYTE            byRes3[32]; /**<Ԥ��*/
	VZ_LPRC_VERTEX  struVertex[VZ_LPRC_ROI_VERTEX_NUM];  /**<��������*/
}
VZ_LPRC_ROI;

/**ʶ�����򶥵����*/
#define VZ_LPRC_ROI_VERTEX_NUM_EX 12
/**ʶ��������Ϣ����*/
typedef struct {
	BYTE            byRes1; /**<Ԥ��*/
	BYTE            byEnable; /**<�Ƿ���Ч*/
	BYTE            byDraw; /**<�Ƿ����*/
	BYTE            byRes2; /**<Ԥ��*/
	BYTE            byRes3[32]; /**<Ԥ��*/
	unsigned        uNumVertex; /**<����ʵ�ʸ���*/
	VZ_LPRC_VERTEX  struVertex[VZ_LPRC_ROI_VERTEX_NUM_EX]; /**<��������*/
}
VZ_LPRC_ROI_EX;

/**ʡ���ַ��������ߴ�*/
#define VZ_LPRC_PROVINCE_STR_LEN  128

/**Ԥ��ʡ����Ϣ*/
typedef struct {
	char strProvinces[VZ_LPRC_PROVINCE_STR_LEN];  /**<����֧�ֵ�ʡ�ݼ�ƹ��ɵ��ַ���*/
	int nCurrIndex; /**<��ǰ��Ԥ��ʡ�ݵ���ţ���strProvinces�еģ�-1Ϊδ����*/
}
VZ_LPRC_PROVINCE_INFO;

/**ͼ����Ϣ*/
typedef struct {
	unsigned  uWidth; /**<���*/
	unsigned  uHeight;  /**<�߶�*/
	unsigned  uPitch; /**<ͼ���ȵ�һ��������ռ�ڴ��ֽ���*/
	unsigned  uPixFmt;  /**<ͼ�����ظ�ʽ���ο�ö�ٶ���ͼ���ʽ��ImageFormatXXX��*/
	unsigned char *pBuffer;   /**<ͼ���ڴ���׵�ַ*/
}
VZ_LPRC_IMAGE_INFO;

/**����֡����*/
typedef enum {
	VZ_LPRC_DATA_ENC_VIDEO, /**<��Ƶ֡��������*/
	VZ_LPRC_DATA_ENC_AUDIO, /**<��Ƶ֡��������*/
}
VZ_LPRC_DATA_TYPE;

/**����֡��Ϣ*/
typedef struct {
	unsigned char	*pBuffer; /**<�����ڴ���׵�ַ*/
	unsigned  uDataSize;  /**<����֡�ߴ磬�ֽ���*/
	unsigned  uPTS_Sec; /**<֡ʱ���_��*/
	unsigned  uPTS_USec;  /**<֡ʱ���_΢��*/
	unsigned char	uIsKeyFrame;  /**<�ؼ�֡��־λ��1Ϊ�ؼ�֡��0Ϊ�ǹؼ�֡*/
	unsigned char	reserved[7];  /**<Ԥ��*/
}
VZ_LPRC_DATA_INFO;

/**��ͷ�䱶�佹����*/
typedef enum {
	VZ_LENS_OPT_STOP, /**<ֹͣ����*/
	VZ_LENS_FOCUS_FAR,  /**<��Զ���۽�*/
	VZ_LENS_FOCUS_NEAR, /**<�������۽�*/
	VZ_LENS_ZOOM_TELE,  /**<�������䱶*/
	VZ_LENS_ZOOM_WIDE,  /**<���̽��䱶*/
}
VZ_LENS_OPT;

/**LED���������*/
typedef enum {
	VZ_LED_AUTO,  /**<�Զ�����LED�Ŀ��͹�*/
	VZ_LED_MANUAL_ON, /**<�ֶ�����LED����*/
	VZ_LED_MANUAL_OFF,  /**<�ֶ�����LED�ر�*/
	VZ_LED_TIME_QUANTUM  /**<ʱ���*/
}
VZ_LED_CTRL;

/**�û�˽�����ݵ�����ֽ���*/
#define VZ_LPRC_USER_DATA_MAX_LEN 128

/**�豸Ψһ���к�*/
typedef struct {
	unsigned uHi; /**<��λ*/
	unsigned uLo; /**<��λ*/
}
VZ_DEV_SERIAL_NUM;

/**�豸����ʱ�����*/
typedef struct {
	unsigned uYear; /**<��*/
	unsigned uMonth;  /**<�� [1, 12]*/
	unsigned uMDay; /**<���е����� [1, 31]*/
	unsigned uHour; /**<ʱ*/
	unsigned uMin;  /**<��*/
	unsigned uSec;  /**<��*/
}
VZ_DATE_TIME_INFO;

/**���ڲ���*/
typedef struct {
	// <������ 300,600,1200,2400,4800,9600,19200,34800,57600,115200
	unsigned uBaudRate;
	unsigned uParity;   // <У��λ ��ֵΪ0-2=no,odd,even
	unsigned uDataBits;   // <����λ ��ֵΪ7,8 λ����λ
	unsigned uStopBit;  // <ֹͣλ ��ֵΪ1,2λֹͣλ
}
VZ_SERIAL_PARAMETER;

/**�洢�豸����*/
typedef enum {
	VZ_STORAGE_DEV_SD = 0,  /**<SD��*/
	VZ_STORAGE_DEV_HD /**<Ӳ��*/
}
VZ_STORAGE_DEV_TYPE;

/**�洢�豸״̬*/
typedef enum {
	VZ_STORAGE_DEV_NO_PART = 0, /**<δ����*/
	VZ_STORAGE_DEV_PART_OK, /**<�ѷ���*/
}
VZ_STORAGE_DEV_STATUS;

/**�洢�豸�����Ĺ���״̬*/
typedef enum {
	VZ_STORAGE_DEV_PART_ERROR = 0,  /**<�쳣*/
	VZ_STORAGE_DEV_PART_NOT_FORMAT, /**<δ��ʽ��*/
	VZ_STORAGE_DEV_PART_NOT_MOUNT,  /**<δ����*/
	VZ_STORAGE_DEV_PART_FORMATING,  /**<���ڸ�ʽ��*/
	VZ_STORAGE_DEV_PART_DELETING, /**<����ɾ���ļ�*/
	VZ_STORAGE_DEV_PART_NORMAL, /**<��������״̬*/
}
VZ_STORAGE_DEV_PART_STATUS;

/**�洢�豸������Ϣ*/
typedef struct {
	VZ_STORAGE_DEV_PART_STATUS eStatus; /**<����״̬*/
	unsigned uUsed; /**<���ÿռ䣨MB)*/
	unsigned uLeft; /**<���ÿռ䣨MB)*/
	unsigned uTotal;  /**<��������MB��*/
	int nFormatPercent; /**<��ʽ���ٷֱ�*/
}
VZ_STORAGE_DEV_PART_INFO;

#define VZ_MAX_NUM_STORAGE_DEV_PART_NUM 4
/**�����洢�豸��Ϣ*/
typedef struct {
	char reserved[32];
	VZ_STORAGE_DEV_TYPE eType;  /**<�洢�豸����*/
	VZ_STORAGE_DEV_STATUS eStatus;  /**<�洢�豸״̬*/
	unsigned uPartNum;  /**<��������*/
	/**<��������Ϣ*/
	VZ_STORAGE_DEV_PART_INFO struPartInfo[VZ_MAX_NUM_STORAGE_DEV_PART_NUM];
}
VZ_STORAGE_DEVICE_INFO;

#define VZ_MAX_NUM_STORAGE_DEVICE 4
/**�洢�豸��Ϣ*/
typedef struct {
	int nDevCount;  /**<�洢�豸����*/
	VZ_STORAGE_DEVICE_INFO struSDI[VZ_MAX_NUM_STORAGE_DEVICE];  /**<���洢�豸��Ϣ*/
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
	BYTE id; // id������0,1,2,���ֱ��������
	BYTE display; // �Ƿ���ʾ����
	BYTE color; // ������ɫ 0����ɫ 1���� 2���� 3����    
	BYTE front_size; //�����С 0:16��  1:24��  2:36��  3:48��
	char text[MAX_USER_OSD_TEXT_LEN]; // �ı����ݣ����63���ֽڣ�����һ��ռ2�ֽ�

}VZ_LPRC_USER_OSD_ITEM_PARAM;

#define MAX_USER_OSD_ITEM_COUNT 3
typedef struct
{
	int x_pos; // �������λ�ã�ȡֵ��Χ[0,100]
	int y_pos; // �������λ�ã�ȡֵ��Χ[0,100]
	VZ_LPRC_USER_OSD_ITEM_PARAM osd_item[MAX_USER_OSD_ITEM_COUNT];
}VZ_LPRC_USER_OSD_PARAM;

#define MAX_USER_OSD_EX_ITEM_COUNT 4
typedef struct
{
	int x_pos; // �������λ�ã�ȡֵ��Χ[0,100]
	int y_pos; // �������λ�ã�ȡֵ��Χ[0,100]
	VZ_LPRC_USER_OSD_ITEM_PARAM osd_item[MAX_USER_OSD_EX_ITEM_COUNT];
}VZ_LPRC_USER_OSD_EX_PARAM;

// ��ƽ̨�豸��Ϣ�б�
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

// ��ƽ̨������Ϣ
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
	char soft_platform;   //ƽ̨����
	unsigned char oem_info[LPRC_OEM_INFO_SIZE];   ///< ǰ3λ���̵ı�ţ���4λ���̼��
	///< Ӳ���汾��,1001���ϰ棬,�°����λ��ʾͨ��·�������һλ��ʾhwflag��HwFlags�İ�λ�룩
	unsigned char hw_version[LPRC_HW_VERSION_SIZE];
	unsigned int hw_flag;   ///< Ӳ����ʶ,�°��Ϊ����HwType
}VZ_FS_INFO_EX;

//������Ƶ
typedef struct _VZ_LPRC_DRAWMODE {
	BYTE byDspAddTarget;  //dsp���ӱ���Ŀ��
	BYTE byDspAddRule;  //dsp�������ù���
	BYTE byDspAddTrajectory;  //dsp���ӹ켣
	BYTE byPlateColor;  //���ӳ�����ɫ
	BYTE dwRes[1];
}VZ_LPRC_DRAWMODE;

// �ֶ�У�����ƵĲ�������
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

/**�����õ�ʶ������*/
#define VZ_LPRC_REC_BLUE      (1<<(LT_BLUE))      /**<���Ƴ�*/
#define VZ_LPRC_REC_YELLOW    (1<<(LT_YELLOW)|1<<(LT_YELLOW2))  /**<���Ƴ�*/
#define VZ_LPRC_REC_BLACK     (1<<(LT_BLACK))   /**<���Ƴ�*/
#define VZ_LPRC_REC_COACH     (1<<(LT_COACH))   /**<������*/
#define VZ_LPRC_REC_POLICE    (1<<(LT_POLICE))  /**<����*/
/**<�侯��*/
#define VZ_LPRC_REC_AMPOL     (1 << (LT_ARMPOL) | 1 << (LT_ARMPOL2))  
#define VZ_LPRC_REC_ARMY      (1<<(LT_ARMY)|1<<(LT_ARMY2))  /**<����*/
#define VZ_LPRC_REC_GANGAO    (1<<(LT_HONGKONG)|1<<(LT_MACAO))  /**<�۰Ľ�����½��*/
#define VZ_LPRC_REC_EMBASSY   (1<<(LT_EMBASSY)) /**<ʹ�ݳ�*/
#define VZ_LPRC_REC_AVIATION  (1<<(LI_AVIATION))  /**<��*/
#define VZ_LPRC_REC_ENERGY    (1<<(LI_ENERGY))  /**<����Դ*/
#define VZ_LPRC_REC_EMERGENCY (1<<(LI_EMERGENCY))  /**<Ӧ������*/
#define VZ_LPRC_REC_CONSULATE (1<<(LI_CONSULATE))  /**<���¹�*/

#define VZ_LPRC_REC_FAKEPLATE (1<<(LI_FAKEPLATE))  /**<������ٳ��ƾ���*/
#define VZ_LPRC_REC_CAR_COLOR (1<<(LI_CAR_COLOR))  /**<������ɫ*/
#define VZ_LPRC_REC_CAR_TYPE (1<<(LI_CAR_TYPE))  /**<��������*/
#define VZ_LPRC_REC_CAR_BRAND (1<<(LI_CAR_BRAND))  /**<���공��*/
#define VZ_LPRC_REC_NOPLATE (1<<(LI_NOPLATE))  /**<���Ƴ���Ϣ*/

//�������������
typedef enum {
	nWhiteList = 0,   //ͨ��
	nNotWhiteList,    //��ͨ��
	nNoLicence,   //�޳���
	nBlackList,   //������
	nExtIoctl1,   //������/��ƽ���� 1
	nExtIoctl2,   //������/��ƽ���� 2
	nExtIoctl3,   //������/��ƽ���� 3
	nSpecialPlates,  //���⳵��
	nExtIoctl4       //������/��ƽ���� 4
}VZ_InputType;

//�������
typedef struct {
	int switchout1;   //��������� 1
	int switchout2;   //��������� 2
	int switchout3;   //��������� 3
	int switchout4;   //��������� 4
	int levelout1;    //��ƽ��� 1 
	int levelout2;    //��ƽ��� 2
	int rs485out1;    //RS485-1
	int rs485out2;    //RS485-2
	VZ_InputType eInputType;    //�������������
}VZ_LPRC_OutputConfig;

#define MAX_OutputConfig_Len 9

//���������Ϣ
typedef struct {
	//�����������������Ϣ
	VZ_LPRC_OutputConfig oConfigInfo[MAX_OutputConfig_Len];   
}VZ_OutputConfigInfo;

// RS-485������������
typedef enum {
	VZ_RS485_NOTYPE = 0,
	VZ_RS485_LICENSEENABLE,   //���޳���
	VZ_RS485_LICENSECOLOR,    //������ɫ
	VZ_RS485_LICENSE,   //���ƺ�
	VZ_RS485_LICENSETYPE,   //��������
	VZ_RS485_CONFIDENCE,  //���Ŷ�
	VZ_RS485_DIRECTION,   //�˶�����
	VZ_RS485_RECT,        //��������
	VZ_RS485_TRIGGER,     //��������
	VZ_RS485_CARCOLOR,    //������ɫ
	VZ_RS485_TIME,        //ʶ��ʱ��
	VZ_RS485_DUETIME,     //����������ʱ�� ʱ�����ͣ�VZ_RS485_TIME_FORMAT
	VZ_RS485_WLRESULT,    //��������֤��� ʱ�����ͣ�VZ_RS485_TIME_FORMAT
	VZ_RS485_OUT,         //���IO
	VZ_RS485_SN,          //���к�
	VZ_RS485_CIPHERTEXT,  //����
	VZ_RS485_ID,          //ʶ���¼ID
	VZ_RS485_CHECKBEGIN,  //У����ʼλ
	VZ_RS485_CHECKEND,    //У�����λ
	VZ_RS485_CHECKSUM,    //У��λ
	VZ_RS485_ENCODE,      //���Ʊ���
	VZ_RS485_EDIAN,       //��С��

	VZ_RS485_TYPELEN      //�������
}VZ_RS485_PUSH_TYPE;

//ʱ������
typedef enum {
	VZ_TIME_FOUR_STAMP = 0, //4�ֽ� ʱ���
	VZ_TIME_SEVEN_YYMDHMS,  //7�ֽ� YYYYTTMMDDHHmmss
	VZ_TIME_SIX_YMDHMS,     //6�ֽ� YYMMDDHHmmss
	VZ_TIME_SEVEN_HMSDMYY,  //7�ֽ�	HHmmssDDMMYYYY
	VZ_TIME_SIX_HMSDMY,     //6�ֽ� HHmmssDDMMYY
	VZ_TIME_FOUR_YYMD,      //4�ֽ� YYYYMMDD
	VZ_TIME_THREE_YMD       //3�ֽ�	YYMMDD
}VZ_RS485_TIME_FORMAT;

//У��λ
typedef enum {
	VZ_CHECK_NO = 0,    //��У��
	VZ_CHECK_SUM,       //��У��
	VZ_CHECK_XOR        //���У��
}VZ_RS485_ITEM_CHECKSUM;

//��С��
typedef enum {
	VZ_EDIAN_LITTLE = 0,    //С��
	VZ_EDIAN_BIG            //���
}VZ_RS485_ITEM_EDIAN;

//���Ƽ���
typedef enum {
	VZ_ENCRY_NOTENCRY,    //�г��Ʋ�����
	VZ_ENCRY_ENCRY        //�г����Ҽ���	
}VZ_RS485_ITEM_ENCRY;

//���ֱ���
typedef enum {
	VZ_ENCODE_UTF8 = 1,
	VZ_ENCODE_GBK,
	VZ_ENCODE_GB2312
}VZ_RS485_ITEM_ENCODE;

// RS-485����������
typedef struct {
	int item_type;    //�����ֶ�����
	int val;          //ֵ
}VZ_RS485_ITEM;

//������Ϣ״̬
typedef enum {
	VZ_VOICE_NOTYPE = 0,
	VZ_VOICE_IN,    //��Ч���ڰ�����
	VZ_VOICE_OUT,   //�ѹ���
	VZ_VOICE_NA,    //���ڰ�����
	VZ_VOICE_IW,    //������ʣ������

	VZ_VOICE_STATUELEN    //״̬��
}VZ_RS485_VOICE_STATUE;

//������Ϣ-������
typedef struct {
	int status;   //������Ϣ״̬VZDEV_RS485_VOICE_STATUE
	int remain;   //ʣ������
	bool license;   //����������Ϣ
	char prefix[36];  //����ǰ׺
	char suffix[36];  //������׺		
}VZ_RS485_VOICE_WL;

#define VZDEV_RS485_VOICE_LEN 4

//������Ϣ
typedef struct {
	VZ_RS485_VOICE_WL voiceWL[VZDEV_RS485_VOICE_LEN];
}VZ_RS485_VOICE;

#define RE485_PUSH_TYPE_LEN 22

// RS-485��������
typedef struct {
	VZ_RS485_ITEM configItem[RE485_PUSH_TYPE_LEN];  //������
	VZ_RS485_VOICE voice;   //������Ϣ
	char header[64];      //Э��ͷ
	char end[64];   //Э��β	
	bool voiceEnable;   //������Ϣ����	
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
	int priority;    // ���ȼ� 1 �������� 2 wifi����
	int wifi_enable; // 0����  1 ������
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

// wifi������ 
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

// wifi����
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

// io��բ���
#define MAX_IO_ITEM_COUNT 4
typedef struct
{
	int io;
	int ctrl_type;
}VZ_IO_ITME;

typedef struct
{
	int plate_id;							// ����id
	char plate[16];							// ���ƺ�
	int  wl_result;							// ��������֤���
	char time[32];							// ʱ��
	VZ_IO_ITME io_item[MAX_IO_ITEM_COUNT];  // io��բ��Ϣ

}VZ_IO_RESULT;

typedef struct
{
	int plate_id;							// ����id
	TH_PlateResult plate_result;            // ���ƽ��
	VZ_IO_ITME io_item[MAX_IO_ITEM_COUNT];  // io��բ��Ϣ

}VZ_PLATE_IO_RESULT;

typedef struct
{
	int enable;			 // �Ƿ������ϴ���				
	int clean_time;      // ��ϴʱ��,�������ʱ���ж�Ϊ�Ѿ���ϴ ��λ��
	int clean_timeout;   // ��ϴ��ʱʱ��, �������ʱ��,��Ϊ��ϴʱ�������.��λ��

}VZ_CHECK_CLEAN_PARAM;

// ����ͼƬ����
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

//����ץ�Ĳ���
typedef struct
{
	int generate_rate;	//Ŀ������֡��[1,5]�����ƽ������������������Ŀ����ٶȣ�ֵԽС��Ŀ������Խ�졣��Ӧ����㷨������ٶȣ����ܻ�����󱨡�
	int sensitivity;	//������[1,5]��������Խ��Խ���׼�������
	int capture_times;	//ץ�Ĵ���[1,10]�����������������뿪�������Ĺ�����ץ�ĵĴ���
	int capture_interval;	//ץ�ļ��, 100~10*1000 ��λms
	int enable_capture_interval; //�Ƿ������ץ�ģ�1ʹ��capture_interval��Ч��0�����һ���������뿪ʱ���
	int capture_threshold;	//ץ��������ֵ[1,20]��ֻ�����ִ��ڵ��ڸ���ֵ�����
	int min_eye_distance;	//��Сͫ��[20,150]��Ĭ��20�������е�����ͫ����ڵ��ڸ���ֵ�����
	int max_eye_distance;	//���ͫ��
	int filter_time;		//�������ͣ��ʱ�䣨�룩��Ĭ��0
	char enable_bodydet; //���μ�⿪��
	char enable_caphead; //��ͷץ�Ŀ���
	char enable_face_roi; //��������ROI����
	char enable_faceattr; //�������Կ���
	char enable_facedet; //����ץ�Ŀ���
	char face_exposure;  //�����ع�����
	char image_quality; //��ͼ��ͼ������(1~9)
	char image_resolution; //��ͼ�ķֱ���:10:1080p,9:720p
	short refer_brightness;//�ο���������[1,100]
	short min_duration;    // ��С���ʱ��

	// 400��������в���
	char age_strategy;			// ����ģʽ
	char downscale_img_encchnl; // ��0 ��ʼ������ͼͨ����������ҵ��
	unsigned char hor_angle; // ˮƽ�Ƕ�
	unsigned char ver_angle; // ��ֱ�Ƕ�
	unsigned char capture_scope; // ץ�ķ���
	unsigned char capture_size; // ץ�Ĵ�С

	unsigned char reserved[14];	//Ԥ��
	//int enable_face_exposure;	//����������趨�ο��������Ƚ����ع����
	//int refer_face_brightness;	//�ο���������[1,100]
	//int duration_face_exposure;	//�ع������ĳ���ʱ�䣨�룩
	//int image_quality;		//ץ��ͼ������[10,100]
}
VZ_FACE_SNAPSHOT_PARAM;

// �ṹ����ѯ
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

// ����������ò���
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

// ����������ò���
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
	char reserved[128];						// ��������
}VZ_FACE_AREA_COUNT_PARAM_EX;

typedef struct tagTH_FacePolygon_V2
{
	unsigned char id;
	unsigned char enable;
	unsigned char point_num;
	int           alarm_people_count;
	TH_FacePoint  polygon_points[MAX_POLYGON_PT_COUNT];
	char reserved[64];						// ��������
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
	char reserved[128];						// ��������
}VZ_FACE_AREA_COUNT_PARAM_V2;


//�������뵼��
#define  IMPORT_MAX_ITEM_NUM    64
#define  IMPORT_MAX_GROUP_NUM   64
typedef struct
{
    int is_selected;
	char key[64];
	int  kv;
	char item_name[64];
	char reserved[64];						// ��������
}VZ_PARAM_IMPORT_ITEM_V2;

typedef struct
{
    VZ_PARAM_IMPORT_ITEM_V2  items[IMPORT_MAX_ITEM_NUM];
	int  count;
	char group_name[64];
	int is_selected;
	char reserved[60];						// ��������
}VZ_PARAM_IMPORT_GROUP_V2;

typedef struct
{
    VZ_PARAM_IMPORT_GROUP_V2 groups[IMPORT_MAX_GROUP_NUM];
	int  count;
	char reserved[64];						// ��������
}VZ_PARAM_IMPORT_ABILITY_V2;


//�豸��Ϣ
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
	char reserved[30];						// ��������
}VZ_AUDIO_PRM;


//////////////////////////////////////////////////////////////////////////
// begin ȫ����������

//�豸��Ϣ
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

// �Զ�����
typedef struct {
	int     enable;
	int     minute;
	char    wday[16];
}VZ_FIC_REBOOT_TIME;

// NTPУʱ
typedef struct {
	int     enable;
	int     cycle;
	char    server[64];
}VZ_FIC_NTP_CONFIG;

// ϵͳʱ��
typedef struct {
	char    datatime[32];
}VZ_FIC_SYSTEM_TIME;

// �������
typedef struct {
	int     dhcp;
	char    ip[16];
	char    netmask[16];
	char    gateway[32];
	char    dns[16];
	char    dns2[16];
}VZ_FIC_NETWORK_CONFIG;

// �豸Ĭ��ֵ
typedef struct {
	int     reset_level;
	char    source[16];
}VZ_FIC_RESET_FACTORY;

typedef struct {
	int    reserve; // �����ֶ�
}VZ_FIC_DEF_PARAM;

// �豸����
typedef struct {
	char    title[32];
}VZ_FIC_DEVICE_NAME;

// ����˿�
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
// ������Ϣ
#define MAX_FIC_DISK_PART_NUM   100
#define MAX_FIC_DISK_NUM        100
typedef struct {
	int     partstate;      // ����״̬:1=δ��ʽ��,2=δ����,3=���ڸ�ʽ��,4=����ɾ��,5=��������,6=ֻ��
	int     formatpercent;  // ��ʽ������
	char    partname[32];   // ���̷�����
	int     total;          // ������С(MB)
	int     left;           // ����ʣ��ռ�(MB)
	int     used;           // ����ʹ�ÿռ�(MB)
}VZ_FIC_DISK_PART;

typedef struct {
	char    devname[32];    // ��������
	int     devtotal;       // �����ܿռ�
	int     devtype;        // ��������:0=SD,1=USB
	int     partnum;
	VZ_FIC_DISK_PART parts[MAX_FIC_DISK_PART_NUM];
}VZ_FIC_DISK;

typedef struct {
	int     disknum;
	VZ_FIC_DISK parts[MAX_FIC_DISK_NUM];
}VZ_FIC_DISK_INFO;
#endif

// ��ʽ������
typedef struct {
	int   pic;
}VZ_FIC_FORMAT_DISK;

// ɾ����������
typedef struct {
	int    reserve; // �����ֶ�
}VZ_FIC_DELETE_DISK;

// VPN����
typedef struct {
	int     enable;
	int     port;
	char    hostname[16];
	int     status;
}VZ_FIC_VPN_NETWORK;

// UPNP����
typedef struct {
	int     enable;
	int     http_port;
	int     rtsp_port;
	int     status;
}VZ_FIC_UPNP_NETWORK;

// DDNS����
typedef struct {
	int     enable;
	char    brandurl[32];  // ddns�ṩ��
	char    name[32];      // ����
	char    username[32];      // �û���
	char    password[32];      // ����
	int     status;
}VZ_FIC_DDNS_NETWORK;

// 4G����
typedef struct {
	int     link_level;
	char    cloud_addr[32];     // �Ʒ�������ַ
	int     net_priority;       // �������ȼ�
}VZ_FIC_4G_CONFIG;

// ʱ������
typedef struct {
	int     timezone;
}VZ_FIC_TIME_ZONE;

// ��������
typedef struct {
	char    cmd[64];
}VZ_FIC_NETWORK_MESSAGE;

// PDNS����
typedef struct {
	int     enable;
	char    pdns_addr[16];
	int     pdns_port;
	int     is_connected;
	char    sn[128];
}VZ_FIC_PDNS_CONFIG;

// �û���Ϣ
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

// ��������
typedef struct {
	char    key1[32];
	char    key2[32];
}VZ_FIC_KEY;

// ���ܵȼ�
typedef struct {
	char    key1[32];
	char    key2[32];
	int     encrypt_level;
}VZ_FIC_ENCRYPT_LEVEL;

// RS485����
typedef struct {
	int     source;     // RS485-1\2\3
	int     baud_rate;  // ������
	int     parity_id;  // У��λ
	int     data_bits;  // ����λ
	int     stop_bits;  // ֹͣλ
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

// ���ο�բ����
typedef struct {
	int     enable;           // �Ƿ�����
	int     gpioin_id;        // IO IN���
	int     gpioout_id;       // IO OUT���
	int     frequency_time;   // ���ʱ��
	int     delay_stop_time;  // �ӳ����ʱ��
}VZ_FIC_REOPEN;

// ��������
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
enum VZ_LENSTYPE        //��ͷ����
{
	VZ_LENS_NONE = 0,   //�Ƕ�����ͷ���������
	VZ_LENS_4MM,        //4mm������ͷ
	VZ_LENS_6MM,        //6mm������ͷ
	VZ_LENS_8MM,        //8mm������ͷ
	VZ_LENS_12MM,        //12mm������ͷ
	VZ_LENS_16MM,        //16mm������ͷ
};
*/

// ¼���ļ��б��ѯ
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
	char strName[VZ_LPRC_VIRTUAL_LOOP_NAME_LEN];  /**<�Զ�������*/
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
	int led_type;                           // ����   1��ϵͳ״̬�� 2�������  3����ɫ�� 4��4G״̬�� 5�������ָͨʾ�� 6������� 7�������� 8����ӵ�
	int led_group;                          // ����   
	int color;								// ��ɫ
	int level;                              // ���ȵȼ�
	char reserved[30];						// ��������
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

//-----------ȫ���ܱ���----------------
typedef enum _COMMON_ALARM_RESULT_TYPE{
	COMMON_ALARM_UNDEFINE = 0,			      // δ������
	COMMON_ALARM_FACE_RECONITION = 1,         // ����ʶ�𱨾����
	COMMON_ALARM_FACE_SNAP,                   // ����ץ�ı������
	COMMON_ALARM_HUMAN,                       // ����ץ�ı������
	COMMON_ALARM_CAR,                         // ����ץ�ı������
	COMMON_ALARM_NONVEHICLE,                  // �ǻ������������
	COMMON_ALARM_AREA_COUNT,                  // �����ܶȱ������
	COMMON_ALARM_GATERING,                    // ��Ⱥ�ۼ��������
	COMMON_ALARM_LIFT_DETECT,                 // ���ݼ�ⱨ�����
	COMMON_ALARM_LANE_CONTROL,                // �������ر������
	COMMON_ALARM_MANUALLY_CAPTURE,            // �ֶ�ץ�Ľ��
	COMMON_ALARM_VEHICLE_VIOLATION,           // ����Υ�±������
	COMMON_ALARM_CHAIN_INFO,                  // ·�����֤�������
	COMMON_ALARM_ROAD_RESULT,                 // ·��ʶ����
	COMMON_ALARM_EBICK_ILLEGAL,               // �ǻ�����Υ�½��
	
	COMMON_ALARM_MAX_NUM
}COMMON_ALARM_RESULT_TYPE;

// end ȫ����������



//////////////////////////////////////////////////////////////////////////
// begin ������ز���

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

//������������Ĳ���
typedef struct
{
	char ip[32];		//IP��ַ
	char name[32];		//�û��Զ�����������
	char type[28];		//�������: "rtsp" / "vz" / "onvif"
	int dev_type;		//������� intֵ(21���������Ž�)
	char username[32];	//����������Ϊ "vz"��"onvif" ����Ҫ�û�������
	char password[32];	//��¼����
	char rtsp_url[128];		//����������Ϊ "rtsp"������Ҫ���� RTSP������������ַ
	char rtsp_url_sub[128];	//RTSP������
	unsigned int http_port;		//HTTP�˿ںţ�Ĭ��80��
	unsigned int rtsp_port;		//RTSP�˿ںţ�Ĭ��8557��
	unsigned char enable_snaps;	//����"vz"��ץ�Ļ��������������Ľ�ͼ�����ں��ӵĻ���ͼƬ���������㷨
	unsigned char enable_video;	//��������������Ƶ�������ں��ӵ�ת���������Ƶ���������㷨
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
	                      
	// �����Ž��豸
	int role;				       //��Ա��ɫ��0����ͨ��Ա�� 1����������Ա�� 2����������Ա��-1��������Ա��
	unsigned int effectTime;       //��Ч�ڽ�ֹʱ�䣬����Ա��Ϣ�ڸ�ʱ������Ч,��1970��1��1��0ʱ0��0�뵽��ֹʱ���������0xFFFFFFFF��ʾ������Ч��0��ʾ����ʧЧ��
	unsigned int effectStartTime;  //��Ч����ʼʱ�䣬����Ա��Ϣ�ڸ�ʱ��֮����Ч,��1970��1��1��0ʱ0��0�뵽��ʼʱ���������0��ʾδ��ʼ����
	char idcardNum[24];			   //Τ����,���ܿ���(��ѡ)
	char usr_record_time[20];      // ����ʶ��ʱ��
	int usr_tag;				   // �û���ʶ
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
	char card_number[32];  // "" ���ַ�������
	int card_type;         // 0:���� 1:���֤ 2:ѧ��֤ 3:���� 4:����
	char province[16];     // "" ���ַ�������
	char city[16];         // "" ���ַ�������
	int sex;               // -1:����  0: �� 1��Ů
	int user_type;         // ��ʱδ����
	char birthday_start[16]; // "" ���ַ�������
	char birthday_end[16];   // "" ���ַ�������
	char user_name[64];      // "" ���ַ�������
	char usr_record_time_s[20]; // "" ���ַ�������
	char usr_record_time_e[20]; // "" ���ַ�������
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
	int offline_check;          // �ѻ���飬0���رգ�1������
	int resend_times;			// �ط�����
	int mserver_status;			// �����������ȣ�0�������ȣ�1������
	char server_ip[32];			// ����������ַ
	int server_port;			// ���������˿�
	int timeout;				// ��ʱʱ��
	char server_ip_ext1[32];	// ��ѡ������
	int ssl_enable;				// �Ƿ�����ssl
	int ssl_port;				// SSLʹ�ö˿ں�
	int ca_enable;				// �Ƿ�ʹ��֤��
	char reserved[128];

}VZ_HTTP_PUSH_BASE_CFG;

typedef struct
{
	int reg_heart_mode;          // ����ģʽ 0��ȡ��������1����ͨ������2��comet��ѯ
	char reg_url[96];			 // �������͵�ַ

	int ivs_rlt_enable;			 // ץ�Ľ������ 
	char ivs_rlt_url[96];		 // ץ�Ľ�����͵�ַ
	int ivs_rlt_detail_level;    // ��ϸ�ȼ� 0��ȫ����1����ϸ��2�����ԣ�3������
	int ivs_rlt_img_mode;        // ͼƬģʽ 1 ����ͼ 2 ����ͼ 4 ����ͼ 8 ����ͼ 16 ʶ��ͼ
	int ivs_enable_resume;

	int area_trip_enable;		 // ���Ͱ���ͳ������ 
	char area_trip_url[96];		 // ����ͳ�����͵�ַ
	int area_trip_internal;      // ���ͼ��ʱ��(0-30)

	int area_count_enable;		 // ��������������� 
	char area_count_url[96];	 // ����������͵�ַ
	int area_count_internal;     // ���ͼ��ʱ��(0-30)
	int area_count_detail_level; // ��ϸ�ȼ� 0����ͼ��1������ͼ

	char reserved[128];

}VZ_BOX_HTTP_PUSH_PARAM;

//ϵͳģ��ȫ�ֿ���
typedef enum
{
	VZ_BOX_ALL_MOD_SWITCH,
	VZ_BOX_ALG_SWITCH,
	VZ_BOX_WEB_SWITCH,
}
VZ_BOX_SYS_MOD_SWITCH;


//��Ȩ����
#define MAX_BOX_AUTH_LIST 100

typedef struct
{
	char auth_time_start[16];			          // ��Ȩ��ʼʱ��   hh:mm:ss
	char auth_time_end[16];			              // ��Ȩ����ʱ��
	char auth_ip_list[MAX_BOX_AUTH_LIST][32];	  // ��Ȩ�豸������
	int  list_count;
}VZ_BOX_AUTH_PARAM;

// end   ������ز���
//////////////////////////////////////////////////////////////////////////

// ��������
// ����ʶ���������
#define VZ_PLATE_GET_MANU_RESULT_PARAM 1001
#define VZ_PLATE_SET_MANU_RESULT_PARAM 1002

// �����ж��Ƿ�ΪC���
#define  VZ_GET_LPR_DEVICE_TYPE        1003  

// ��ȡ��ǰϵͳ������
#define  VZ_GET_SYS_LANGUAGE           1004

// ��ȡ���Ե�����
#define  VZ_GET_LANGUAGE_CONTENT       1005    

// ��ȡrtsp�˿ں�
#define  VZ_GET_RTSP_PORT              1006

// ��ȡ��������
#define  VZ_GET_ENCODE_PROP            1007

// ��ȡLED���ȵȼ�
#define  VZ_GET_LED_PROP               1008

// ��ȡӲ������
#define  VZ_GET_DEVICE_CAPACITY        1009

// ����wifi����
#define  VZ_SET_WIFI_CFG               1010

// ��ȡwifi������
#define  VZ_GET_WIFI_PROPERTY          1011

// ��ȡ��ǰ��Χ��wifi
#define  VZ_GET_WIFI_ITEMS             1012

// ���ó�����ϴ������
#define  VZ_SET_CHECK_CLEAN_PARAM      1013

// ��ȡrtsp url
#define  VZ_GET_RTSP_URL               1014

// ��ȡ������rtsp url
#define  VZ_GET_SUB_RTSP_URL           1015

// ��ȡ˫������ڶ�·��Ȧ����
#define  VZ_GET_VIRLOOP_SECOND_PARA    1016

// ����˫������ڶ�·��Ȧ����
#define  VZ_SET_VIRLOOP_SECOND_PARA    1017

// ��ȡ˫������ڶ�·ʶ������
#define  VZ_GET_REGION_SECOND_PARA     1018

// ����˫������ڶ�·ʶ������
#define  VZ_SET_REGION_SECOND_PARA     1019

// ��ȡ�Ƿ�֧��etc����
#define  VZ_GET_ETC_ENABLE			   1020

// ��ȡetc����
#define  VZ_GET_ETC_CONFIG			   1021

// ����etc����
#define  VZ_SET_ETC_CONFIG			   1022

// ��̨����
#define  VZ_SET_PTZ_PARA			   1023

// ��ȡ������rtmp url
#define  VZ_GET_RTMP_URL               1024


// �����������
#define VZ_FACE_GET_VIDEO_PARAM						3001
#define VZ_FACE_SET_VIDEO_PARAM						3002

#define VZ_FACE_GET_SD_INFO							3003

#define VZ_FACE_GET_AREA_FLOW_STATISTIC 			3004
#define VZ_FACE_SET_AREA_FLOW_STATISTIC				3005

#define VZ_FACE_SET_CVBS_CTRL						3006
#define VZ_FACE_GET_CVBS_CTRL						3007

#define VZ_FACE_SET_AUDIO_CTRL						3008
#define VZ_FACE_GET_AUDIO_CTRL						3009

// ҹ��ģʽ�л��ӿ�
#define VZ_FACE_SET_VIDEO_PARAMS					3010

#define VZ_FACE_GET_SUP_DRAWRECT					3011

#define VZ_FACE_GET_DEVICE_CAPACITY                 3012

// ��������Ľӿ�
#define VZ_FACE_SET_AREA_COUNT_PARAM                3013

#define VZ_FACE_GET_AREA_COUNT_PARAM                3014

#define VZ_FACE_SET_CAMERA_LENS                     3015

#define VZ_FACE_GET_CAMERA_LENS                     3016

// ������װ��
#define VZ_FACE_SET_GUIDE_CTRL                      3017

// ���������������
// ���ڻ�ȡ��һ��ʱ���ڱ������ѽ��
#define VZ_FACE_SET_CACHE_COUNT                     3019

// ���߼���
#define VZ_FACE_GET_AREA_FLOW_STATISTIC_EX 			3020
#define VZ_FACE_SET_AREA_FLOW_STATISTIC_EX			3021
// ��������Ľӿ�
#define VZ_FACE_SET_AREA_COUNT_PARAM_EX             3022
#define VZ_FACE_GET_AREA_COUNT_PARAM_EX             3023

// ���뵼�뵼���Ľӿ�
#define VZ_GET_IMPORT_PARAM_ABILITY_EX              3024

// ��������Ľӿ�
#define VZ_FACE_SET_AREA_COUNT_PARAM_V2             3025
#define VZ_FACE_GET_AREA_COUNT_PARAM_V2             3026

//����ʶ������ 
#define VZ_FACE_SET_RULE                            3027
#define VZ_FACE_GET_RULE                            3028

//������������ 
#define VZ_FACE_SET_SHIELD_AREA                     3029
#define VZ_FACE_GET_SHIELD_AREA                     3030

//��Ƶ����ͨ��
#define VZ_SET_AUDIO_PARAM						    3031
#define VZ_GET_AUDIO_PARAM							3032

//�Ƿ�֧��lens����
#define VZ_FACE_GET_CAMERA_LENS_SUPPORT             3033

//////////////////////////////////////////////////////////////////////////
// begin ȫ����������
#define VZ_FIC_GET_DEVICE_INFO                      4001    // ��ȡ�豸��Ϣ
#define VZ_FIC_SET_REBOOT_TIME                      4002    // �����Զ�����
#define VZ_FIC_GET_REBOOT_TIME                      4003    // ��ȡ�Զ�����
#define VZ_FIC_SET_NTP_CONFIG                       4004    // ����NTPУʱ
#define VZ_FIC_GET_NTP_CONFIG                       4005    // ��ȡNTPУʱ
#define VZ_FIC_SET_SYSTEM_TIME                      4006    // ����ϵͳʱ��
#define VZ_FIC_GET_SYSTEM_TIME                      4007    // ��ȡϵͳʱ��
#define VZ_FIC_SET_NETWORK_CONFIG                   4008    // �����������
#define VZ_FIC_GET_NETWORK_CONFIG                   4009    // ��ȡ�������
#define VZ_FIC_SET_DEF_PARAM                        4010    // �����û�Ĭ��ֵ
#define VZ_FIC_SET_RESET_FACTORY                    4011    // �ָ��豸Ĭ��ֵ
#define VZ_FIC_SET_DEVICE_NAME                      4012    // �����豸����
#define VZ_FIC_GET_DEVICE_NAME                      4013    // ��ȡ�豸����
#define VZ_FIC_SET_NETWORK_PORT                     4014    // ��������˿�
#define VZ_FIC_GET_NETWORK_PORT                     4015    // ��ȡ����˿�
#define VZ_FIC_GET_DISK_INFO                        4016    // ��ȡ������Ϣ
#define VZ_FIC_SET_FORMAT_DISK                      4017    // ��ʽ������
#define VZ_FIC_SET_DELETE_DISK                      4018    // ɾ����������
#define VZ_FIC_GET_VPN_NETWORK                      4019    // ��ȡVPN����
#define VZ_FIC_SET_VPN_NETWORK                      4020    // ����VPN����
#define VZ_FIC_GET_UPNP_NETWORK                     4021    // ��ȡUPNP����
#define VZ_FIC_SET_UPNP_NETWORK                     4022    // ����UPNP����
#define VZ_FIC_GET_DDNS_NETWORK                     4023    // ��ȡDDNS����
#define VZ_FIC_SET_DDNS_NETWORK                     4024    // ����DDNS����
#define VZ_FIC_GET_4G_CONFIG                        4025    // ��ȡ4G����
#define VZ_FIC_SET_4G_CONFIG                        4026    // ����4G����
#define VZ_FIC_GET_TIME_ZONE                        4027    // ��ȡʱ������
#define VZ_FIC_SET_TIME_ZONE                        4028    // ����ʱ������
#define VZ_FIC_SEND_NETWORK_MESSAGE                 4029    // ������������
#define VZ_FIC_GET_PDNS_CONFIG                      4030    // ��ȡPDNS����
#define VZ_FIC_SET_PDNS_CONFIG                      4031    // ����PDNS����
#define VZ_FIC_GET_ACCOUNT                          4032    // ��ȡ�û���Ϣ
#define VZ_FIC_SET_ACCOUNT                          4033    // �����û���Ϣ
#define VZ_FIC_MODIFY_KEY                           4034    // �޸ļ�������
#define VZ_FIC_RESET_KEY                            4035    // ���ü�������
#define VZ_FIC_MODIFY_ENCRYPT_LEVEL                 4036    // �޸ļ��ܵȼ�
#define VZ_FIC_SET_RS485_PARAM                      4037    // ����RS485����
#define VZ_FIC_GET_RS485_PARAM                      4038    // ��ȡRS485����
#define VZ_FIC_GET_GPIO_IN                          4039    // ��ȡGPIO IN״̬
#define VZ_FIC_GET_GPIO_OUT                         4040    // ��ȡGPIO OUT״̬
#define VZ_FIC_SET_REOPEN                           4041    // ���ö��ο�բ����
#define VZ_FIC_GET_REOPEN                           4042    // ��ȡ���ο�բ����
#define VZ_FIC_SET_VOICE_CONFIG                     4043    // ������������
#define VZ_FIC_GET_VOICE_CONFIG                     4044    // ��ȡ��������
#define VZ_FIC_GET_RECORD_VIDEO                     4045    // ¼���ļ��б��ѯ
#define VZ_FIC_SET_CONTROL_GPIOOUT                  4046    // ��բ����
#define VZ_FIC_GET_VIDEO_MODE                       4047    // ��ȡ��Ƶģʽ 0����ģʽ 1����ģʽ
#define VZ_FIC_GET_ENCRYPT_LEVEL                    4048    // ��ȡ���ܵȼ�
#define VZ_FIC_GET_RECORD_PORT						4049    // ��ȡ¼��˿�
 
#define VZ_FIC_SET_LIGHT_CONTROL					4050    //ȫ�������õ�״̬
#define VZ_FIC_GET_DEVICE_DRAW                      4051    //�豸�˻���
// end ȫ����������
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// begin ·��������
#define VZ_ROAD_GET_ROAD_RULE_PARAM                 5001    // ��ȡ·�����ò���
#define VZ_ROAD_SET_EVS_LIGHT_CONTROL               5002    // ���õƹ�ģʽ������ָʾ��
// end  ·��������
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// begin �������
#define VZ_BOX_GET_AUTH_PARAM                       6001    // ��ȡ������Ȩ��Ϣ
#define VZ_BOX_SET_AUTH_PARAM                       6002    // ���ú�����Ȩ��Ϣ

// end  �������
//////////////////////////////////////////////////////////////////////////


#ifdef WIN32

/**�豸�������VzLPRClient_Open��ã��豸������صĺ�������Ҫ*/
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

//==============�ӿڲ������� end=============
#endif
