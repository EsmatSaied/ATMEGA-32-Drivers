/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied   ************/
/*************   Component: SWITCH     ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00        ************/
/**************************************************/
/**************************************************/
#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define SWITCH_PRESSED		1
#define SWITCH_NOT_PRESSED	0

#define PULL_UP				1
#define PULL_DOWN			0

typedef struct
{
	u8 SWITCH_u8_PORT;
	u8 SWITCH_U8_PIN;
	u8 SWITCH_ACTIVE_STATE;
}SWITCH;

u8 SWITCH_voidON(SWITCH * Copy_StructSWITCH);

#endif