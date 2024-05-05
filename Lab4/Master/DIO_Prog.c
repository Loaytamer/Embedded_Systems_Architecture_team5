#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "BIT_MATH.h"

u8 Seg = 'A';

// Pins
void DIO_Vid_Set_Pin_Direction(u8 port, u8 pin, u8 dirction)
{
    if(dirction == Input)
        switch (port)
        {
        case Port_A:
            CLR_BIT(DDRA, pin);
            break;
        case Port_B:
            CLR_BIT(DDRB, pin);
            break;
        case Port_C:
            CLR_BIT(DDRC, pin);
            break;
        case Port_D:
            CLR_BIT(DDRD, pin);
            break;
        }
    
    else if (dirction == Output)
        switch (port)
        {
        case Port_A:
            SET_BIT(DDRA, pin);
            break;
        case Port_B:
            SET_BIT(DDRB, pin);
            break;
        case Port_C:
            SET_BIT(DDRC, pin);
            break;
        case Port_D:
            SET_BIT(DDRD, pin);
            break;
        }
}

void DIO_Vid_Set_Pin_Value(u8 port, u8 pin, u8 value){
    if (value == Low)
        switch (port)
        {
        case Port_A:
            CLR_BIT(PORTA, pin);
            break;
        case Port_B:
            CLR_BIT(PORTB, pin);
            break;
        case Port_C:
            CLR_BIT(PORTC, pin);
            break;
        case Port_D:
            CLR_BIT(PORTD, pin);
            break;
        }

    else if (value == High)
        switch (port)
        {
        case Port_A:
            SET_BIT(PORTA, pin);
            break;
        case Port_B:
            SET_BIT(PORTB, pin);
            break;
        case Port_C:
            SET_BIT(PORTC, pin);
            break;
        case Port_D:
            SET_BIT(PORTD, pin);
            break;
        }
}

void DIO_Vid_Get_Pin_Value(u8 port, u8 pin, u8 *value)
{
    switch (port)
    {
    case Port_A:
        *value = GET_BIT(PORTA, pin);
        break;

    case Port_B:
        *value = GET_BIT(PORTB, pin);
        break;

    case Port_C:
        *value = GET_BIT(PORTC, pin);
        break;

    case Port_D:
        *value = GET_BIT(PORTD, pin);
        break;
    }
}

// Ports
void DIO_Vid_Set_Port_Direction(u8 port, u8 direction)
{
    if(direction == Input)
        switch (port)
        {
        case Port_A:
            DDRA = 0x00;
            break;

        case Port_B:
            DDRB = 0x00;
            break;

        case Port_C:
            DDRC = 0x00;
            break;

        case Port_D:
            DDRD = 0x00;
            break;
        }

    else if (direction == Output)
        switch (port)
        {
        case Port_A:
            DDRA = 0xff;
            break;

        case Port_B:
            DDRB = 0xff;
            break;

        case Port_C:
            DDRC = 0xff;
            break;

        case Port_D:
            DDRD = 0xff;
            break;
        }
}

void DIO_Vid_Set_Port_Value(u8 port, u8 status)
{
	switch (port)
	{
	case Port_A:
		PORTA = status;
		break;

	case Port_B:
		PORTB = status;
		break;

	case Port_C:
		PORTC = status;
		break;

	case Port_D:
		PORTD = status;
		break;
	}
}

void DIO_Vid_Get_Port_Value(u8 port, u8 *value)
{
    switch (port)
    {
    case Port_A:
        *value = PINA;
        break;

    case Port_B:
        *value = PINB;
        break;

    case Port_C:
        *value = PINC;
        break;

    case Port_D:
        *value = PIND;
        break;
    }
}

// 7Seg
void DIO_7Seg_init(u8 port)
{
	DIO_Vid_Set_Port_Value(port, 0x3F);

	switch (port)
	{
		case Port_A:
			Seg = 'A';
			break;
		case Port_B:
			Seg = 'B';
			break;
		case Port_C:
			Seg = 'C';
			break;
		case Port_D:
			Seg = 'D';
			break;
	}
}

/*
 g f e d c b a
 0 1 1 1 1 1 1 : 0 : 0x3F
 0 0 0 0 1 1 0 : 1 : 0x06
 1 0 1 1 0 1 1 : 2 : 0x5B
 1 0 0 1 1 1 1 : 3 : 0x4F
 1 1 0 0 1 1 0 : 4 : 0x66
 1 1 0 1 1 0 1 : 5 : 0x6D
 1 1 1 1 1 0 1 : 6 : 0x7D
 0 0 0 0 1 1 1 : 7 : 0x07
 1 1 1 1 1 1 1 : 8 : 0x7F
 1 1 0 1 1 1 1 : 9 : 0x6F
*/

void DIO_7Seg_Write_Number(u8 num)
{
    u8 numers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    switch (Seg)
	{
		case 'A':
			DIO_Vid_Set_Port_Value(Port_A, numers[num]);
			break;
		case 'B':
			DIO_Vid_Set_Port_Value(Port_B, numers[num]);
			break;
		case 'C':
			DIO_Vid_Set_Port_Value(Port_C, numers[num]);
			break;
		case 'D':
			DIO_Vid_Set_Port_Value(Port_D, numers[num]);
			break;
	}

}

void DIO_7Seg_Write_Value(u8 value)
{
	switch (Seg)
	{
		case 'A':
			DIO_Vid_Set_Port_Value(Port_A, value);
			break;
		case 'B':
			DIO_Vid_Set_Port_Value(Port_B, value);
			break;
		case 'C':
			DIO_Vid_Set_Port_Value(Port_C, value);
			break;
		case 'D':
			DIO_Vid_Set_Port_Value(Port_D, value);
			break;
	}
}

/*
 g f e d c b a
 1 1 1 0 1 1 1 : A : 0x77
 1 1 0 0 1 1 1 : a : 0x67
 1 1 1 1 1 1 1 : B : 0xFF
 1 1 1 1 1 0 0 : b : 0xFC
*/

void DIO_7Seg_Write_Char(u8 ch)
{
	u8 value = 0x00;

	switch (ch)
	{
		case 'A':
			value  = 0x77;
			break;
		case 'a':
			value  = 0x67;
			break;
		case 'B':
			value  = 0xFF;
			break;
		case 'b':
			value  = 0xFC;
			break;
	}

	DIO_7Seg_Write_Value(value);
}

