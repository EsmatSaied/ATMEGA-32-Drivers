/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied   ************/
/*************   Component: 7-SEG     ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00        ************/
/**************************************************/
/**************************************************/


#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_private.h"

void SEVEN_SEG_voidON(SEVEN_SEG * Copy_StructSEG, u8 Copy_sevseg)
{
	static u8 sevensegment[10]=
		{0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111,};
	u8 Local_u8Iterator2, RIGHT, LEFT;

	if(Copy_StructSEG-> SEVEN_SEG_ACTIVE_STATE== COMMON_ANODE)
	{
		for(Local_u8Iterator2=0; Local_u8Iterator2<50; Local_u8Iterator2++)
		{
					RIGHT= Copy_sevseg%10;
					LEFT=  Copy_sevseg/10;
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, DIO_u8_PIN_LOW);
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_LOW);
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, ~(sevensegment[RIGHT]));
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_HIGH);
					_delay_ms(10);
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_LOW);
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, ~(sevensegment[LEFT]));
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_HIGH);
					_delay_ms(10);
		}
	}

	else if(Copy_StructSEG-> SEVEN_SEG_ACTIVE_STATE== COMMON_CATHODE)
	{
		for(Local_u8Iterator2=0; Local_u8Iterator2<50; Local_u8Iterator2++)
		{
					RIGHT= Copy_sevseg%10;
					LEFT=  Copy_sevseg/10;
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, DIO_u8_PIN_LOW);
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_LOW);
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, (sevensegment[RIGHT]));
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_HIGH);
					_delay_ms(10);
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_LOW);
					DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, (sevensegment[LEFT]));
					DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_HIGH);
					_delay_ms(10);
		}
	}
}

void SEVEN_SEG_voidOFF(SEVEN_SEG * Copy_StructSEG)
{
    	if(Copy_StructSEG-> SEVEN_SEG_ACTIVE_STATE== COMMON_ANODE)
	{
        DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, DIO_u8_PIN_LOW);
        DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_LOW);
        _delay_ms(10);
        DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_LOW);
        _delay_ms(10);
    }
    	else if(Copy_StructSEG-> SEVEN_SEG_ACTIVE_STATE== COMMON_CATHODE)
	{
            DIO_u8SetPortValue(Copy_StructSEG->SEVEN_SEG_u8_PORT, DIO_u8_PIN_LOW);
            DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E2_PIN, DIO_u8_PIN_LOW);
            _delay_ms(10);
            DIO_u8SetPinValue(Copy_StructSEG-> SEVEN_SEG_u8_Enable_PORT, Copy_StructSEG->SEVEN_SEG_u8E1_PIN, DIO_u8_PIN_LOW);
            _delay_ms(10);
	}
}
