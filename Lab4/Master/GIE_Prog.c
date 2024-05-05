#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "BIT_MATH.h"

void GIE_Enable()
{
    SET_BIT(SREG, SREG_I);
}

void GIE_Disable()
{
    CLR_BIT(SREG, SREG_I);
}