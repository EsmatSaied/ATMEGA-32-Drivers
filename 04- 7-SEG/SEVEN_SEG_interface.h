/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied   ************/
/*************   Component: 7-SEG     ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00        ************/
/**************************************************/
/**************************************************/

#ifndef SEVEN_SEG_INTERFACE_H_
#define SEVEN_SEG_INTERFACE_H_

#define  COMMON_ANODE  		  1
#define  COMMON_CATHODE       0

typedef struct
{
	u8 SEVEN_SEG_u8_PORT;
	u8 SEVEN_SEG_u8_Enable_PORT;
	u8 SEVEN_SEG_u8E1_PIN;
	u8 SEVEN_SEG_u8E2_PIN;
	u8 SEVEN_SEG_ACTIVE_STATE;
}SEVEN_SEG;

void SEVEN_SEG_voidON(SEVEN_SEG * Copy_StructSEG, u8 Copy_sevseg);
void SEVEN_SEG_voidOFF(SEVEN_SEG * Copy_StructSEG);


#endif