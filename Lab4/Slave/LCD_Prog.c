/*
 * LCD_Prog.h
 *
 * Created: 3/2/2024 9:21:35 PM
 *  Author: Ayat Mohamed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "DIO_INTERFACE.h"
#include  <util/delay.h>
#ifndef LCD_PROG_H_
#define LCD_PROG_H_
static uint8 cursor = 1;
void LCD_Init(void)
{
	DIO_VidSetPinDirection(CONTROL_PORT , RS ,Output);
	DIO_VidSetPinDirection(CONTROL_PORT , EN ,Output);
    _delay_ms(20);
	DIO_VidSetPinDirection(CONTROL_PORT , D4 ,Output);
	DIO_VidSetPinDirection(CONTROL_PORT , D5 ,Output);
	DIO_VidSetPinDirection(CONTROL_PORT , D6 ,Output);
	DIO_VidSetPinDirection(CONTROL_PORT , D7 ,Output);
	
	DIO_VidSetPinValue(CONTROL_PORT , RS , PinLow );
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinLow );
    LCD_Void_Send_Command(0x02);
	/*Function set: 2 lines 5*8*/
	LCD_Void_Send_Command(0x28);//10100000
	_delay_ms(1);
	/*Display on off :display enable ,display cursor,no blink cursor */
	LCD_Void_Send_Command(0x0C);
	LCD_Void_Send_Command(0x06);
	LCD_Void_Send_Command(0x80);
	LCD_Void_Send_Command(0x01);
}
void LCD_Void_Send_Data(uint8 Data)
{
	
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinHigh);
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , D4 ,GET_BIT(Data,Pin4));  
	DIO_VidSetPinValue(CONTROL_PORT , D5 ,GET_BIT(Data,Pin5));
	DIO_VidSetPinValue(CONTROL_PORT , D6 ,GET_BIT(Data,Pin6));
	DIO_VidSetPinValue(CONTROL_PORT , D7 ,GET_BIT(Data,Pin7));
	DIO_VidSetPinValue(CONTROL_PORT , RS , PinHigh);
	_delay_ms(1);
	 DIO_VidSetPinValue(CONTROL_PORT , EN ,PinLow );
	 _delay_ms(1);
	 DIO_VidSetPinValue(CONTROL_PORT , EN ,PinHigh);
	 _delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , D4 ,GET_BIT(Data,Pin0));
	DIO_VidSetPinValue(CONTROL_PORT , D5 ,GET_BIT(Data,Pin1));
	DIO_VidSetPinValue(CONTROL_PORT , D6 ,GET_BIT(Data,Pin2));
	DIO_VidSetPinValue(CONTROL_PORT , D7 ,GET_BIT(Data,Pin3));
	DIO_VidSetPinValue(CONTROL_PORT , RS , PinHigh);
    _delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinLow );
	_delay_ms(1);
	
}


void LCD_Void_Send_Command(uint8 Com)
{
	//uint8_t Local_Com ;
	DIO_VidSetPinValue(CONTROL_PORT , RS , PinLow );
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinHigh);
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , D4 ,GET_BIT(Com,Pin4));
	DIO_VidSetPinValue(CONTROL_PORT , D5 ,GET_BIT(Com,Pin5));
	DIO_VidSetPinValue(CONTROL_PORT , D6 ,GET_BIT(Com,Pin6));
	DIO_VidSetPinValue(CONTROL_PORT , D7 ,GET_BIT(Com,Pin7));
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinLow );
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , EN ,PinHigh);
	_delay_ms(1);
	DIO_VidSetPinValue(CONTROL_PORT , D4 ,GET_BIT(Com,Pin0));
	DIO_VidSetPinValue(CONTROL_PORT , D5 ,GET_BIT(Com,Pin1));
	DIO_VidSetPinValue(CONTROL_PORT , D6 ,GET_BIT(Com,Pin2));
	DIO_VidSetPinValue(CONTROL_PORT , D7 ,GET_BIT(Com,Pin3));
    _delay_ms(1);
    DIO_VidSetPinValue(CONTROL_PORT , EN ,PinLow );
    _delay_ms(1);
}

void LCD_Print_String(uint8 *Copy_Str)
{

	uint8 iterator = 0;
	// check if the string is ending or not
	while(Copy_Str[iterator] != '\0')
	{
		
		// print the data
		LCD_Void_Send_Data(Copy_Str[iterator]);

		//increase the address by one to send the next element.
		iterator++;
	}
}

void LCD_Move_Cursor(uint8 row , uint8 column)
{
	switch(row)
	{
		case 0 :
		if(column < 16)
		{
			LCD_Void_Send_Command((0x80) + (column));
			cursor = column;
		}
		break;
		case 1:
		if(column < 16)
		{
			LCD_Void_Send_Command((0x80) + 0x40 + (column));
			cursor = 17 + column;
		}
		break;
	}
}
void LCD_Clear(void)
{
	LCD_Void_Send_Command(0x01);
	 _delay_ms(1);
}


#endif /* LCD_PROG_H_ */

