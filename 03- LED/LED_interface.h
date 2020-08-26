/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: LED        ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define  ATIVE_HIGH    1
#define  ATIVE_LOW     0

typedef struct
{
	u8 LED_u8_PORT;
	u8 LED_u8_PIN;
	u8 LED_ACTIVE_STATE;
}LEDS;

void LED_voidON(LEDS * Copy_StructLED);
void LED_voidOFF(LEDS * Copy_StructLED);

#endif