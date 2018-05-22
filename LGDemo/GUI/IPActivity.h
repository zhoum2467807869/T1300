#ifndef __IPACTIVITY_H
#define __IPACTIVITY_H
#include "Component.h"

typedef struct  /*时序器IP地址数据结构体*/
{ 
  u8 ip;
}_ip_data;
extern _ip_data ip_data;
typedef struct{

 void (*IPActivityPage)(void);
 void (*IPActivityItemSelect)(void);
 void (*readIPData)();
 void (*saveIPData)();
	
	
}IPActivity;
extern IPActivity ipActivity;
void IPActivityPage(void);
void ipActivityItemSelect(void);
void ipActivityAction(void);	
void flashIpItem(u8 anchor,u8 lastanchor);
void readIPData(void);
void saveIPData(void);
#endif 
