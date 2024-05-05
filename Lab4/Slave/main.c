/*
 * main.c
 *
 *  Created on: 1 May 2024
 *      Author: Nouran
 */

// Slave:
#include <avr/io.h>
#include <avr/delay.h>
#include "DIO_Interface.h"
#include "LCD_Interface.h"

void init_SPI_slave() {
    DDRB |= (1 << DDB6); // Set MISO as output
    SPCR |= (1 << SPE);  // Enable SPI
}

int main()
{
	LCD_Init();
	init_SPI_slave();

	//LCD_Send_String("Slave");
	LCD_Print_String("Slave");
	char data=0;

	while(1)
	{
		while (!(SPSR & (1 << SPIF)));
		data = SPDR;
//		LCD_GoTo_2nd_Line();
//		LCD_Send_Data(data);
		LCD_Move_Cursor(1,0);
		LCD_Void_Send_Data(data);
		_delay_ms(100);
	}
}
