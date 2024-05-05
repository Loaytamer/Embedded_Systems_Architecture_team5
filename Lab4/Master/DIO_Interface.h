#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"

typedef enum
{
    Port_A,
    Port_B,
    Port_C,
    Port_D,
} et_port;

typedef enum
{
    Pin0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7
} et_pin;

typedef enum
{
    Input,
    Output,
} et_direction;

typedef enum
{
    Low,
    High
} et_status;

// Pins
void DIO_Vid_Set_Pin_Direction(u8 port, u8 pin, u8 dirction);
void DIO_Vid_Set_Pin_Value(u8 port, u8 pin, u8 value);
void DIO_Vid_Get_Pin_Value(u8 port, u8 pin, u8 *value);

// PORT
void DIO_Vid_Set_Port_Direction(u8 port, u8 direction);
void DIO_Vid_Set_Port_Value(u8 port, u8 status);
void DIO_Vid_Get_Port_Value(u8 port, u8 *value);

// 7Seg
void DIO_7Seg_init(u8 port);
void DIO_7Seg_Write_Number(u8 num);
void DIO_7Seg_Write_Value(u8 value);
void DIO_7Seg_Write_Char(u8 ch);

#endif
