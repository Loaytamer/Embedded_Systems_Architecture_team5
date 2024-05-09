/*
 * GccApplication1.c
 *
 * Created: 07/05/2024 23:00:44
 * Author : Loay
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define BAUD_RATE 9600 // Adjust this value for your desired baud rate
#define F_CPU 16000000UL
#include "LCD_Interface.h"


void uart_init() {
	// Set baud rate using UBRR registers
	uint16_t baud_prescaler = ((F_CPU / (BAUD_RATE * 16UL)) - 1);
	UBRRH = (uint8_t)(baud_prescaler >> 8);
	UBRRL = (uint8_t)(baud_prescaler & 0xFF);

	// Enable transmitter (TXEN0) and receiver (RXEN0)
	UCSRB |= (1 << TXEN) | (1 << RXEN);

	// Set frame format (8-bit data, 1 stop bit, no parity)
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0);
}

void uart_transmit(unsigned char data) {
	// Wait for empty transmit buffer (UDRE0 flag)
	while (!(UCSRA & (1 << UDRE)));

	// Write data to transmit register (UDR0)
	UDR = data;
}

unsigned char uart_receive() {
	// Wait for data to be received (RXC0 flag)
	while (!(UCSRA & (1 << RXC)));

	// Read data from receive register (UDR0)
	return UDR;
}



int main() {
	LCD_Init();
	LCD_Clear();
	_delay_ms(50);
	uart_init();
	 unsigned char data;
	

	while (1){
		
		data = uart_receive();
		LCD_Clear();
		_delay_ms(50);
		LCD_Void_Send_Data((char)data);
		_delay_ms(1000);
	}
	
}



