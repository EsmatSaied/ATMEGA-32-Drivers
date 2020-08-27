/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: EXTI       ************/
/*************   Layer: MCAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define  FALLING_EDGE_		1
#define  RISING_EDGE_		2
#define  LOW_LEVEL			3
#define  ON_CHANGE			4

#define ENABLED				5
#define DISABLED			6

#define INT0				1
#define INT1				2
#define INT2				3

void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

void EXTI_voidSetSenseControl(u8 Copy_u8Int, u8 Copy_u8Sense);
void EXTI_voidEnableInterrupt(u8 Copy_u8Int);
void EXTI_voidDisableInterrupt(u8 Copy_u8Int);


#endif