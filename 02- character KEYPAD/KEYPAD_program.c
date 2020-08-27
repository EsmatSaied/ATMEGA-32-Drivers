/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: KEYPAD      ************/
/*************   Layer: HAL          ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#include "STD_TYPES.h"
#include  "DIO_interface.h"
#include  "KEYPAD_config.h"
#include  "KEYPAD_interface.h"
#include  "KEYPAD_private.h"


u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey= NO_KEY_PRESSED_VALUE;
	u8 Local_u8ColumnIndex, Local_u8RowIndex, Local_u8PinState;

	u8 Local_u8KeypadArr[ROWs_NUMBER][COLUMNs_NUMBER]= KEYPAD_KEYS_ARR4x4;

	u8 Local_u8RowsPinsArr[4]= {KEYPAD_u8_ROW0, KEYPAD_u8_ROW1, KEYPAD_u8_ROW2, KEYPAD_u8_ROW3};
	u8 Local_u8ColumnsPinsArr[4]= {KEYPAD_u8_COLUMN0, KEYPAD_u8_COLUMN1, KEYPAD_u8_COLUMN2, KEYPAD_u8_COLUMN3};

	for(Local_u8ColumnIndex=0; Local_u8ColumnIndex<COLUMNs_NUMBER; Local_u8ColumnIndex++)
	{
		/*Activate the current column by putting low signal*/
		DIO_u8SetPinValue(KEYPAD_u8_PORT, Local_u8ColumnsPinsArr[Local_u8ColumnIndex], DIO_u8_PIN_LOW);

		for(Local_u8RowIndex=0; Local_u8RowIndex<ROWs_NUMBER; Local_u8RowIndex++)
		{
			/*Read the current row*/
			DIO_u8GetPinValue(KEYPAD_u8_PORT, Local_u8RowsPinsArr[Local_u8RowIndex], &Local_u8PinState);

			if(Local_u8PinState == DIO_u8_PIN_LOW)
			{
				Local_u8PressedKey= Local_u8KeypadArr[Local_u8RowIndex][Local_u8ColumnIndex];

				/*Busy waiting(Polling) until the key is released, tol ma shayfo low e2rah tany w hakza*/
				while(Local_u8PinState== DIO_u8_PIN_LOW)
				{
					DIO_u8GetPinValue(KEYPAD_u8_PORT, Local_u8RowsPinsArr[Local_u8RowIndex], &Local_u8PinState);
				}
				/*b3d ma 3rft el button w shlt edy mn 3leh 5alas h return msh 3ayza akml el loop*/
				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column 34an el iteration el gdeda yb2a brdo button wa7d elly mt2ktv*/
			DIO_u8SetPinValue(KEYPAD_u8_PORT, Local_u8ColumnsPinsArr[Local_u8ColumnIndex], DIO_u8_PIN_HIGH);
	}
		/*Default value if not any one is pressed*/
		return Local_u8PressedKey;
}
