#ifndef __KEY_H
#define __KEY_H
#include "sys.h"


	
//������״̬�ṹ��	
typedef struct{
 u8 EN_STATE;
 u8 EN_KEY	;
}_encoder_dev;

typedef struct{
	
u8 relay_key_state;
	
}_relay_key_dev;

extern _relay_key_dev relay_key_dev;


//�������Ͱ���״̬
#define TURN_R 1
#define TURN_L 2
#define EN_KEY_UP 3
#define EN_KEY_DOWN 6
#define RE_KEY_UP 4
#define RE_KEY_DOWN 5
#define XNULL 0


//��ƽ״̬
#define  H 1
#define  L 0

	//��ȡ��ƽ״̬
#define ENCODER_B      PBin(15)
#define ENCODER_A      PBin(14)
#define ENCODER_KEY    PBin(12)
#define RELAY_KEY      PBin(13)

//#define ENCODER_B      PBin(10)
//#define ENCODER_A      PBin(11)
//#define ENCODER_KEY    PBin(12)
//#define RELAY_KEY      PBin(13)


void key_init(void);//������ʼ������
u8 encoder(void);//��������ת״̬
u8 encoder_key(void);//����������״̬
u8 relay_key(void);//�̵������ذ���
#endif











