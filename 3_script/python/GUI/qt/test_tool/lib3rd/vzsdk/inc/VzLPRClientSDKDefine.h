#ifndef SRC_LIB_INCLUDE_VZLPRCLIENTSDKDEFINE_H_
#define SRC_LIB_INCLUDE_VZLPRCLIENTSDKDEFINE_H_

#include <VzClientSDK_CommonDefine.h>
#include <VzClientSDK_LPDefine.h>
#include <VzClientSDK_FaceDefine.h>

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

// �ṹ����ѯ
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

enum VZ_LENSTYPE        //��ͷ����
{
	VZ_LENS_NONE = 0,   //�Ƕ�����ͷ���������
	VZ_LENS_4MM,        //4mm������ͷ
	VZ_LENS_6MM,        //6mm������ͷ
	VZ_LENS_8MM,        //8mm������ͷ
	VZ_LENS_12MM,        //12mm������ͷ
	VZ_LENS_16MM,        //16mm������ͷ
};

// ¼���ļ��б��ѯ
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
	unsigned		img_format;	   // ͼƬ��ʽ(0: jpg)
	unsigned char	*buffer;	   // ͼƬ�ڴ���׵�ַ
	unsigned int    img_len;       // ͼƬ���ݴ�С
	char            img_info[32];  // ͼ����Ϣ,�������Ƶ�
	char            reserved[128]; // Ԥ��
}
VZ_IMAGE_INFO;


/**��¼��Ϣ*/
typedef struct {
	char dev_ip[64];		// �豸���Ʒ���IP��ַ
	int  dev_port;			// �豸�Ķ˿ں�
	char username[32];      // �����豸�����û���
	char password[32];      // �����豸��������
	int  timeout;           // ��ʱʱ��(��λ���룬�糬ʱʱ��Ϊ5��ʱ����5000)
	int protocol_type;      // ����Э��(0:http, 1:https)
	int network_type;       // ��������(0:������,1:����-PDNS��ʽ, 2:����-BIND��ʽ, 3:������ƽ̨��ʽ)
	
	// ��������
	int http_port;          // �����˿�
	char sn[20];            // �豸���к�
	char extern_ip[16];		// ���ؾ��������豸IP��ַ
	char ak_id[36];         // ��ƽ̨��¼id
	char ak_secret[36];     // ��ƽ̨��¼����
	BYTE dwRes[128];        // ����
}VZ_LPRC_LOGIN_PARAM;

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

// ��ȡ������Ϣ
#define  VZ_GET_CAR_INFO               1201

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

// ��ͷ��������
#define VZ_FACE_SET_CAMERA_LENS                     3015

#define VZ_FACE_GET_CAMERA_LENS                     3016

// ������װ��
#define VZ_FACE_SET_GUIDE_CTRL                      3017


#ifdef WIN32

/**�豸�������VzLPRClient_Open��ã��豸������صĺ�������Ҫ*/
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

