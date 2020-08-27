/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: SWITCH        ************/
/*************   Layer: HAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_interface.h"
#include "SWITCH_private.h"

u8 Local_u8_SwitchState;
u8 SWITCH_voidON(SWITCH * Copy_StructSWITCH)
{
	if(Copy_StructSWITCH-> SWITCH_ACTIVE_STATE== PULL_UP)
	{
		DIO_u8GetPinValue(Copy_StructSWITCH-> SWITCH_u8_PORT, Copy_StructSWITCH-> SWITCH_U8_PIN, &Local_u8_SwitchState);
		_delay_ms(250);
		if(Local_u8_SwitchState== DIO_u8_PIN_LOW)
			return SWITCH_PRESSED;
		else if(Local_u8_SwitchState== DIO_u8_PIN_HIGH)
			return SWITCH_NOT_PRESSED;
	}
	else if(Copy_StructSWITCH-> SWITCH_ACTIVE_STATE== PULL_DOWN)
	{
		DIO_u8GetPinValue(Copy_StructSWITCH->SWITCH_u8_PORT, Copy_StructSWITCH->SWITCH_U8_PIN, &Local_u8_SwitchState);
		_delay_ms(250);
		if(Local_u8_SwitchState== DIO_u8_PIN_HIGH)
			return SWITCH_PRESSED;
		else if(Local_u8_SwitchState== DIO_u8_PIN_LOW)
			return SWITCH_NOT_PRESSED;
	}
	return Local_u8_SwitchState;
}
