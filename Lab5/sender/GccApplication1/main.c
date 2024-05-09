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
#include "avr/interrupt.h"

#include <stdio.h>
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

void INT_EN()
{
	MCUCR |= (1<<ISC01); //falling edge
	GICR  |= (1<<INT0); //En int0
	
}
char x = 0x40;
int main() {
	DDRD &= ~(1<<2); //pD2 input
	uart_init();
	INT_EN();
	sei();

	while (1){}
}

ISR(INT0_vect)
{
	if(x ==0x7a)
	{
		x= 0x40;
	}
	x++;
	uart_transmit(x);
	_delay_ms(1500);
}

