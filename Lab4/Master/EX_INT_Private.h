#ifndef EX_INT_PRIVATE_H
#define EX_INT_PRIVATE_H

#include "STD_TYPES.h"

#define GICR   (*(volatile u8*)0x5B)
#define GIFR   (*(volatile u8 *)0x5A)
#define MCUCR  (*(volatile u8 *)0x55)
#define MCUCSR (*(volatile u8 *)0x54)

#endif