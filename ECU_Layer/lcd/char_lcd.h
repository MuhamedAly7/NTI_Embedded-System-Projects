/*
 * char_lcd.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_LCD_CHAR_LCD_H_
#define ECU_LAYER_LCD_CHAR_LCD_H_

/* ----------------------------------------------- includes --------------------------------*/
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "char_lcd_cfg.h"
#include "util/delay.h"

/* ----------------------------------------------- macros objects ------------------------- */

// LCD commands
#define LCD_CLEAR                     0x01
#define LCD_RETURN_HOME               0x02
#define LCD_ENTRY_MODE                0x06
#define LCD_CURSOR_OFF_DISPLAY_ON     0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF    0x08
#define LCD_CURSOR_ON_BLINK_ON        0x0F
#define LCD_CURSOR_ON_BLINK_OFF       0x0E
#define LCD_DISPLAY_SHIFT_RIGHT       0x1C
#define LCD_DISPLAY_SHIFT_LEFT        0x18
#define LCD_8BIT_MODE_2_LINE          0x38
#define LCD_4BIT_MODE_2_LINE          0x28
#define LCD_CGRAM_START               0x40
#define LCD_DDRAM_START               0x80

// rows numbers
#define ROW1   1
#define ROW2   2
#define ROW3   3
#define ROW4   4

/* ----------------------------------------------- macros functions ----------------------- */

/* ----------------------------------------------- user data types -------------------------*/


/* ------------------------------------------------ APIs ---------------------------------- */

void H_LCD_void_Init(void);
void H_LCD_void_SendCommand(u8 Copy_u8Command);
void H_LCD_void_SendData(u8 Copy_u8Data);
void H_LCD_void_SendString(u8 *Copy_u8Str);
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);
void H_LCD_void_displayCustomChar(u8 copy_u8charCode);
void H_LCD_void_Clear_Display(void);

#endif /* ECU_LAYER_LCD_CHAR_LCD_H_ */
