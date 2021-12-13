#ifndef _VZ_CLIENT_SDK_LP_DEFINE_H_
#define _VZ_CLIENT_SDK_LP_DEFINE_H_
#include <VzClientSDK_CommonDefine.h>

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
	unsigned char nPlateTypeExtInfo; /**��ʽС�ͳ�����չ,���ڳ���ΪС�ͳ��Ƶ�ʱ����Ч,����:NewCarTypeExtEnum*/
	unsigned char reservedC1[3];
	unsigned int triggerTimeMS;    /**����ʱ�� ��λ��ms*/
	char reserved1[16];			   /**<����*/
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


#define   LPRC_CENTER_IPLEN  200
typedef struct      //���ķ���������
{
	char centerServerIp[LPRC_CENTER_IPLEN];   //���ķ�������ַ
	WORD port;                         //���ķ������˿�
	bool enableSsl;                    //�Ƿ�ʹ��sslЭ��
	WORD sslPort;                      //sslЭ��˿� 
	WORD timeout;                      //��ʱʱ�����ô���, ��Χ��1~30��

}VZ_LPRC_CENTER_SERVER_NET;

#define  URLLENGTH 1000
typedef struct      //���ķ����������豸ע��
{
	BYTE type;                         //���ķ������豸ע������
	char url[URLLENGTH];               //���ķ������豸ע���ַ
}VZ_LPRC_CENTER_SERVER_DEVICE_REG;

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

/**¼���ѯ����*/
typedef struct _VzStream_RecordInfo {
	char file_name[256];
	int size;
	int type;		//0�ƻ�¼�� 1����¼�� 2����¼��
	int start_time;
	int end_time;
}VzStream_RecordInfo;

typedef struct _VzStream_RecordList {
	int out_code;
	int total;
	VzStream_RecordInfo records[512];
	char error_message[256];
}VzStream_RecordList;

typedef struct _VzStream_RecordQuery {
	char start_time[64]; //��ʽ�磺 2021-5-12 00:00:00
	char end_time[64];   //��ʽ�磺 2021-5-12 23:59:59
	int type;		     //0�ƻ�¼�� 1����¼�� 2����¼��   99����¼��
	int query_size;	     //0-128
}VzStream_RecordQueryInfo;

typedef struct _VzStream_MonthRecord {
	int out_code;
	char record_flag[32];	//record_flag[0]����1�ŵ�¼������� record_flag[1]����2�ŵ�¼�����������1������¼��0������¼��
	char error_message[256];
}VzStream_MonthRecord;


//RG���»�������Ϣ
typedef struct {
	int dev_online;			// �����豸�Ƿ����ߣ�0������ 1�����ߣ�
	char dev_type[16];		// �����豸����
	char dev_name[32];		// �����豸��
	char sn[32];            // �����豸���к�
	char dev_ip[64];		// �����豸IP��ַ

}VZ_LPRC_MATE_INFO;

//RG���»���Rtsp������Ϣ
typedef struct {
	char rtsp_ip[128];		// RtspIP��ַ
	char rtsp_proxyurl[128];// ����ת����rtsp��ַ
}VZ_LPRC_RTSP_INFO;

//RG���»�������������Ϣ
typedef struct {
	int encode_type;		// ֧�ֵı�������(1:PCM   2:G711  3:PCM | G711)
	int talk_port;			// ����ת���������Ķ˿�
	int sampling_rate;		// ������
	int window_size;		//���������ڴ�С��ÿ�η������ݰ��Ĵ�С
}VZ_LPRC_REQUEST_TALK_INFO;
#endif