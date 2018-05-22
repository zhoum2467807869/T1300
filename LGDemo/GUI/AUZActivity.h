#ifndef __AUZACTIVITY_H
#define __AUZACTIVITY_H

#include "Component.h"


typedef struct{
  u8 p_one;
  u8 p_two;
  u8 p_three;
  u8 p_four;
  u8 p_five;
	u8 p_six;
}AUZ_Data;
typedef struct{
	
 void (*auzActivityPage)(void);
 void (*auzActivityItemSelect)(void);
 AUZ_Data* user_Data;
 u8* freeTime; 
 u8 (*checkAUZData)(AUZ_Data*,AUZ_Data*);
 void (*saveAUZData)(void);
 void (*readAUZData)(void);
 void (*auzActivityUserPage)();
}AUZActivity;

extern AUZActivity auzActivity;
void auzActivityPage(void);
void auzActivityItemSelect(void);
void auzActivityAction(void);
void flashAUZItem(u8 anchor,u8 lastanchor);
u8 checkAUZData(AUZ_Data* auzDataTemep,AUZ_Data* auzData);
void saveAUZData(void);
void readAUZData(void);
void pwdSelectItem(void);
void auzActivityUserPage(void);
void auzActivityUserPageItemSelect(AUZ_Data* userDataTemp,u8* isUserRight);
void flashUserItem(u8 anchor,u8 lastanchor);
u8 isFreeDayOver(void);

#endif

