#include "STD_TYPES.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	//set RW pin to write
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_LOW);
	//set RS to be command
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_LOW);
	//send the command to LCD
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Command);
	//enable pulse
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
		//set RW pin to write
		DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RW_PIN, DIO_u8_PIN_LOW);
		//set RS to be data
		DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_RS_PIN, DIO_u8_PIN_HIGH);
		//send the command to LCD
		DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Data);
		//enable pulse
		DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(LCD_u8_CTRL_PORT, LCD_u8_E_PIN, DIO_u8_PIN_LOW);
}

void LCD_voidInit(void)
{
	//wait for more than 30ms after power up
	_delay_ms(40);
	//as in data sheet, RS&RW=0, it means send command so call its fn
	/*function set command
	 * 2 lines
	 * font= 5*7
	 */
	LCD_voidSendCommand(0b00111000);
	//wait for more than 39us
	_delay_ms(1);
	/*display on/off control command
	 * 1-display enable
	 * 2-cursor off
	 * 3-blink cursor off
	 */
	LCD_voidSendCommand(0b00001100);
	//wait for more than 39us
	_delay_ms(1);
	//LCD clear
	LCD_voidSendCommand(0b00000001);
	//wait for more than 1.53ms
		_delay_ms(2);


}

void LCD_voidWriteString(char const *Copy_pchString)
{
    u8 Local_u8ColumnCounter=0;
	while(*Copy_pchString != '\0')
		{
			LCD_voidSendData(*Copy_pchString);
			Copy_pchString++;
            Local_u8ColumnCounter++;
			if(Local_u8ColumnCounter> LCD_u8_SIXTEETH_COLUMN)
			{
				LCD_voidGotoXY(LCD_u8_SECOND_LINE, (Local_u8ColumnCounter-16));
			}
		}
	/*da el implementation elly kont 3amlah el awl
	/*u8 Iterator;
	for(Iterator=0; string[Iterator]!=0; Iterator++)
	{
		LCD_voidSendData(string[Iterator]);
	}*/
}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_u32Reserved=1; /*3mlnaha 1 w 5lena el do while t check 3la 1 bdl 0 34an
	a2dr atb3 arqam feha 0 3l ymen, y3ny bzwd 1 gnb el rqm el gayly k t7ayol bs msh 3ayza atb3o*/

	while(Copy_u32Number!=0)
	{
		Local_u32Reserved=Local_u32Reserved*10 + Copy_u32Number%10;
		Copy_u32Number/=10;
		/*this is the logic of
		swapping digits of no, i use it in palindrome code with Neso academy*/
	}
	do
	{
		LCD_voidSendData((Local_u32Reserved%10)+'0');//+'0' to convert to ascii
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);

	/*ana kont 3amla implementation by itoa fn(it's a pre-defined fn in c but in E.S we
	* use limited memories so as a rule we should write everything just as we need*/
}

void LCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;//we are already know the add won't exceed 80

	/*Addresses starts from address 0*/
	if(Copy_u8XPos==LCD_u8_FIRST_LINE)
	{
		Local_u8Address=Copy_u8YPos;
	}

	/*Addresses starts with address 0x40*/
	else if(Copy_u8XPos==LCD_u8_SECOND_LINE)
	{
		Local_u8Address=0x40+Copy_u8YPos;
	}

	/*sending the SET DDRAM address command with bit 7 equal to 1
	 * we could do this in several ways (SET_BIT(Local_u8Address,7)),
	 * Local_u8Address|= 1<<7, Local_u8Address+0b10000000, Local_u8Address+128*/
	LCD_voidSendCommand(Local_u8Address+128);
}

void LCD_voidCustomCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{/*pattern no is the block no mn el 8 blocks el available lya fl CGRAM*/
	u8 Local_u8Address, Local_u8PatternCounter; //u8 34an el max 3ndy 8*8=64

	/*1-Calculate the required address of CGRAM*/
	Local_u8Address= Copy_u8PatternNumber*8; //8 el far2 ben kol block wl tany
	/*2-Set CGRAM address with bit7=0 & bit6=1*/
	LCD_voidSendCommand(Local_u8Address+64);//+0b01000000 according to datasheet

	for(Local_u8PatternCounter=0; Local_u8PatternCounter<8; Local_u8PatternCounter++)
	{
		/*3-Storing the pattern into CGRAM*/
		LCD_voidSendData(Copy_pu8Pattern[Local_u8PatternCounter]);/*from the datasheet we
		found that the way to write to CG or DD RAM is the same so it's a regular send data*/
	}
	/*4-shift the address counter to the DDRAM*/
	LCD_voidGotoXY(Copy_u8XPos, Copy_u8YPos);
	/*/LCD_voidSendCommand(0b10000000); da lw msh 3ayza el user y7dd pos hwa el char
	 * 3latol hytl3 3la awl pos*/
	/*5-Passing the block no to be displayed*/
	LCD_voidSendData(Copy_u8PatternNumber);
}
