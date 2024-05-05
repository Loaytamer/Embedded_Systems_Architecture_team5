#include <stdio.h>
#include "EX_INT_Config.h"
#include "EX_INT_Interface.h"
#include "EX_INT_Private.h"
#include "BIT_MATH.h"

// ******************
// ****** Mode ******
// 0: Low Leve
// 1: On Change
// 2: Failing Edge
// 3: Rissing Edge
// ******************

// Initilization:
void EX_INT0_INIT(u8 mode)
{
    // INT0 Enable
    SET_BIT(GICR, GICR_INT0);

    switch (mode)
    {
    case 0:
        CLR_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
        break;

    case 1:
        SET_BIT(MCUCR, MCUCR_ISC00);
        CLR_BIT(MCUCR, MCUCR_ISC01);
        break;

    case 2:
        CLR_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
        break;

    case 3:
        SET_BIT(MCUCR, MCUCR_ISC00);
        SET_BIT(MCUCR, MCUCR_ISC01);
        break;
    }
}

void EX_INT1_INIT(u8 mode)
{
    // INT1 Enable
    SET_BIT(GICR, GICR_INT1);

    switch (mode)
    {
    case 0:
        CLR_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
        break;

    case 1:
        SET_BIT(MCUCR, MCUCR_ISC10);
        CLR_BIT(MCUCR, MCUCR_ISC11);
        break;

    case 2:
        CLR_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
        break;

    case 3:
        SET_BIT(MCUCR, MCUCR_ISC10);
        SET_BIT(MCUCR, MCUCR_ISC11);
        break;
    }
}

void EX_INT2_INIT(u8 mode)
{
    // INT2 Enable
    SET_BIT(GICR, GICR_INT2);

    // 0: failling edge
    // 1: rissing edge
    switch (mode)
    {
    case 0:
        CLR_BIT(MCUCSR, MCUCSR_ISC2);
        break;

    case 1:
        SET_BIT(MCUCSR, MCUCSR_ISC2);
        break;
    }
}

// Pointer to Function:
void (*INT0_Function_PTR)(void) = NULL;
void (*INT1_Function_PTR)(void) = NULL;
void (*INT2_Function_PTR)(void) = NULL;

// Set Pointer:
void EX_SET_INT0(void *INT0_PTR(void))
{
	if(INT0_PTR != NULL)
		INT0_Function_PTR = INT0_PTR;
}

void EX_SET_INT1(void *INT1_PTR(void))
{
	if(INT1_PTR != NULL)
		INT1_Function_PTR = INT1_PTR;
}

void EX_SET_INT2(void *INT2_PTR(void))
{
	if(INT2_PTR != NULL)
		INT2_Function_PTR = INT2_PTR;
}

// ISR:
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
    // Callback function:
	if(INT0_Function_PTR != NULL)
	{
		INT0_Function_PTR();

	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
    // Callback function:
	if(INT1_Function_PTR != NULL)
	{
		INT1_Function_PTR();

	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void){
    // Callback function:
	if(INT2_Function_PTR != NULL)
	{
		INT2_Function_PTR();

	}
}
