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
#include <avr/interrupt.h>

void adc_init()
{
	ADMUX |= (1<<REFS1) | (1<<REFS0); //internal ref ,enable adc 0
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) |(1<<ADIE); // en adc, prescalar = 128
}

void INT_EN()
{
	MCUCR |= (1<<ISC01); //falling edge
	GICR  |= (1<<INT0); //En int0
	
}

int main(void)
{
	DDRD &= ~(1<<2); //pD2 input
	adc_init();
	INT_EN();
	LCD_Init();
	LCD_Clear();
	_delay_ms(50);
	sei();
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

ISR(INT0_vect)
{
	char num[5];
	int adc_value;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA&(1<<ADSC)); //still converting 
	adc_value = ADCW;
	itoa(adc_value, num, 10);
	LCD_Clear();
	_delay_ms(250);
	//LCD_vidSendNumber(adc_value);
	LCD_Print_String("ADC = ");
	LCD_Print_String(num);
	_delay_ms(2000);
}

