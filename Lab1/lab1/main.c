/*
 * lab1.c
 *
 * Created: 18/02/2024 22:36:06
 * Author : Loay Tamer Mohamed
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>
#define F_CPU 8000000UL

typedef enum{
	rst,
	up,
	down,
	}Mode;
static uint8 seven_seg_values []={0x7F, 0x0D, 0xB7, 0x9F, 0xCD, 0xDB, 0xF9, 0x0F, 0xFF, 0xDF}; 
int main(void)
{
	DIO_VidSetPortDirection(Port_A, Output);
	DIO_VidSetPinDirection(Port_C, Pin7, Output);
	DIO_VidSetPinDirection(Port_C, Pin6, Output);
	DIO_VidSetPinDirection(Port_D, Pin2, Input);
	DIO_VidSetPinDirection(Port_D, Pin3, Input);
	DIO_VidSetPinDirection(Port_D, Pin4, Input);
	DIO_VidSetPinDirection(Port_B, Pin4, Output);
    int f1 =0,f2=0;
	int count=0, ones, tens, upBtn_val, downBtn_val, rstBtn_val;
	Mode mode=up;
	DIO_VidSetPinValue(Port_B, Pin4, PinLow);
    while (1) 
    {	
		ones = count%10;
		tens = count/10;
	    DIO_VidSetPinValue(Port_C, Pin6, PinHigh);
		DIO_VidSetPinValue(Port_C, Pin7, PinLow);
		DIO_VidSetPortValue(Port_A, seven_seg_values[ones]);
		_delay_ms(4);   
		DIO_VidSetPinValue(Port_C, Pin7, PinHigh);
		DIO_VidSetPinValue(Port_C, Pin6, PinLow);
		DIO_VidSetPortValue(Port_A, seven_seg_values[tens]);
		_delay_ms(3);
		/*if(mode == up)
		{
			if (count==99)
			{
				count=0;
			}
			else
			{
				count++;
			}
		}
		else if(mode == down)
		{
			if (count==0)
			{
				count=99;
			}
			else
			{
				count--;
			}
		}
		else if(mode == rst)
		{
			count = 0;
			_delay_ms(3500);
			mode = up;
		}*/
		
		if(!(PIND &(1<<2))) // up mode 
		{
			if(f1 == 0 )
			{
				f1=1;
                  	if (count==99)
                  	{
	                  	count=0;
                  	}
                  	else
                  	{
	                  	count++;
                  	}
			}
			//mode = up;
		}
		else if(!(PIND &(1<<3))) // down mode
		{
			if(f2 == 0)
			{
				    f2 = 1;
					if (count==0)
					{
						count=99;
					}
					else
					{
						count--;
					}
			
			}
			//mode = down;
		}
		else if(!(PIND &(1<<4))) //reset
		{
			count = 0;
			//mode = rst;
		}
		else
		{
		     f1 = 0 ; 
			 f2 = 0;
		}
		
		
    }
}

