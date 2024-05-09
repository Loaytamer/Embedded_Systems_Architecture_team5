/*
 * LCD_Interface.h
 *
 * Created: 3/2/2024 9:21:17 PM
 *  Author: Q
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include "STD_TYPES.h"
#define  CONTROL_PORT  Port_A
#define  RS            Pin1
#define  EN            Pin2
#define  D4            Pin3
#define  D5            Pin4
#define  D6            Pin5
#define  D7            Pin6

void LCD_Init(void);
void LCD_Void_Send_Data(uint8 Data);
void LCD_Void_Send_Command(uint8 Com);
void LCD_Print_String(uint8 *Copy_Str);
void LCD_Move_Cursor(uint8 row , uint8 column);
void LCD_Clear(void);
void LCD_vidSendNumber(uint32 Copy_u8Number);




#endif /* LCD_INTERFACE_H_ */