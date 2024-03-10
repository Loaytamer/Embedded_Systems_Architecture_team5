/*
 * LCD.c
 *
 * Created: 3/2/2024 9:17:58 PM
 * Author : Ayat
 */ 
#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_Interface.h"
#include "DIO_INTERFACE.h"
#include  <util/delay.h>
int main(void)
{
	LCD_Init();
	LCD_Clear();
	_delay_ms(50);
    while (1) 
    {
          int i=0;
		  for(i = 0 ; i < 10 ; i++)
		  {
			  if(i <= 5)
			  {
				  LCD_Move_Cursor(0,i);
				  LCD_Print_String("Hello");
				  _delay_ms(1000);
				    LCD_Clear();
				_delay_ms(5);
			  }
			  else if(i > 5)
			  {
				   LCD_Move_Cursor(0,10-i);
				  LCD_Print_String("Hello");
				  _delay_ms(1000);
				  LCD_Move_Cursor(0,i);
				  LCD_Clear();
				  _delay_ms(5);
			  }
		  }
		
    }
}

