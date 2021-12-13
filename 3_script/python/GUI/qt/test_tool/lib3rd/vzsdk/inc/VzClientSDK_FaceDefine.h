#ifndef _VZ_CLIENT_SDK_FACE_DEFINE_H_
#define _VZ_CLIENT_SDK_FACE_DEFINE_H_
#include <VzClientSDK_CommonDefine.h>

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
	unsigned char data_type;	//  1 ���� 2 ���� 4����
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
	char reserved[122];							// ��������
}TH_FaceResult;

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
	unsigned char point_count; // ��ĸ���
	TH_FacePoint points[MAX_FLOW_POINT_COUNT];

}TH_FaceFlowStatistic;

typedef struct tagTH_FaceCvbsParam
{
	int cvbs;             // 1���� 0:��
	int cvbs_signal_sys;  // ����ģʽ 0��PAL, 1:NTSC
}TH_FaceCvbsParam;

// ����������
typedef struct 
{
	char datetime[20];						// ʱ�䣬��ʽ��yyyy-MM-dd HH:mm:ss
	unsigned int people_num;				// ��ǰ�û���������ͳ�Ƴ�����Ա����
	TH_FaceImg snap_img;					// ȫͼͼ��
	char reserved[128];						// ��������
}TH_AreaCountResult;

typedef struct tagTH_FaceGuideData
{
	short definition;			// ����������
	short confidence;			// ���Ŷȣ������Ƕȣ�
	int face_count;				// ��������
	TH_FaceRect face_rect; 		// ��������

}TH_FaceGuideData;

#endif