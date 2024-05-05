/*
 * main.c
 *
 *  Created on: 1 May 2024
 *      Author: Nouran
 */

// Master:
#include <avr/io.h>
#include <avr/delay.h>
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"
#include "EX_INT_Interface.h"

void INT0_ISR();
u8 x = 0x40;

void init_SPI_master() {
    DDRB |= (1 << DDB5) | (1 << DDB7) | (1 << DDB4); // Set MOSI, SCK, SS as output
    SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, Master mode, Fosc/16
}

int main()
{
	DIO_Vid_Set_Pin_Direction(Port_D, Pin2, Input);
	DIO_Vid_Set_Pin_Direction(Port_C, Pin0, Output);

	GIE_Enable();
	EX_INT0_INIT(3);
	EX_SET_INT0(&INT0_ISR);

	init_SPI_master();
	while(1)
	{
		_delay_ms(100); // Delay for stability
	}
}

void INT0_ISR()
{
	if(x == 0x7A)
		x = 0x41;
	else
		x++;

	SPDR = x;
	TOG_BIT(PORTC, 0);
}
