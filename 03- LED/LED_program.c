/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: LED        ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#include "Std_Types.h"
#include <util/delay.h>
#include "LED_config.h"
#include "LED_interface.h"
#include "LED_private.h"
#include  "DIO_interface.h"
#include  "PORT_interface.h"

void LED_voidON(LEDS * Copy_StructLED)
{
	if(Copy_StructLED->LED_ACTIVE_STATE== ATIVE_HIGH)
	{
		DIO_u8SetPinValue(Copy_StructLED->LED_u8_PORT, Copy_StructLED->LED_u8_PIN, DIO_u8_PIN_HIGH);
	}
	else if(Copy_StructLED->LED_ACTIVE_STATE== ATIVE_LOW)
	{
		DIO_u8SetPinValue(Copy_StructLED->LED_u8_PORT, Copy_StructLED->LED_u8_PIN, DIO_u8_PIN_LOW);
	}
}

void LED_voidOFF(LEDS * Copy_StructLED)
{
    	if(Copy_StructLED->LED_ACTIVE_STATE== ATIVE_HIGH)
	{
		DIO_u8SetPinValue(Copy_StructLED->LED_u8_PORT, Copy_StructLED->LED_u8_PIN, DIO_u8_PIN_LOW);
	}
	else if(Copy_StructLED->LED_ACTIVE_STATE== ATIVE_LOW)
	{
		DIO_u8SetPinValue(Copy_StructLED->LED_u8_PORT, Copy_StructLED->LED_u8_PIN, DIO_u8_PIN_HIGH);
	}

}
