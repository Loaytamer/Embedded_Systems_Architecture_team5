#ifndef EX_INT_CONFIG_H
#define EX_INT_CONFIG_H

#include "DIO_Interface.h"

// GICR: External Interrupt Enable
#define GICR_INT0 Pin6
#define GICR_INT1 Pin7
#define GICR_INT2 Pin5

// GIFR: External Interrupt Flag
#define GIFR_INTF1 Pin7
#define GIFR_INTF0 Pin6
#define GIFR_INTF2 Pin5

// MCUCR: Trigger
#define MCUCR_ISC00 Pin0
#define MCUCR_ISC01 Pin1
#define MCUCR_ISC10 Pin2
#define MCUCR_ISC11 Pin3

// MCUCSR: INT2
// 0: failling edge
// 1: rissing edge
#define MCUCSR_ISC2 Pin2

#endif