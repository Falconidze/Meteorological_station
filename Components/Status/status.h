#ifndef STATUS_H
#define STATUS_H

#define Status_Key_Up 0x0001
#define Status_Key_Down 0x0002
#define Status_Key_Left 0x0004
#define Status_Key_Right 0x0008
#define Status_Key_Mid 0x0010
#define Status_Key_Mid_Long 0x0020
//#define Status_Write_Data 0x0100

#include "stdint.h"
void status_init(void);
void status_set(uint16_t data);
uint16_t status_get(void);

#endif /* STATUS_H */