/*
 * char_lcd.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mohamed Aly
 */

#include "char_lcd.h"

u8 countDigits(s32 number);

void H_LCD_void_Init(void)
{
#if LCD_MODE_SELECT == LCD_4_BIT_MODE_SELECT

	// configure enale and rs and data pins
	DIO_voidSetPinDirection(LCD_4BIT_RS_PIN_PORT, LCD_4BIT_RS_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LCD_4BIT_D7_PIN_PORT, LCD_4_BIT_D7_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LCD_4BIT_D6_PIN_PORT, LCD_4_BIT_D6_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LCD_4BIT_D5_PIN_PORT, LCD_4_BIT_D5_PIN, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(LCD_4BIT_D4_PIN_PORT, LCD_4_BIT_D4_PIN, GPIO_DIRECTION_OUTPUT);

	// delay before any start
	_delay_ms(20);
	H_LCD_void_SendCommand(LCD_8BIT_MODE_2_LINE);
	_delay_ms(5);
	H_LCD_void_SendCommand(LCD_8BIT_MODE_2_LINE);
	_delay_ms(150);
	H_LCD_void_SendCommand(LCD_8BIT_MODE_2_LINE);
	H_LCD_void_SendCommand(LCD_CLEAR);
	H_LCD_void_SendCommand(LCD_RETURN_HOME);
	H_LCD_void_SendCommand(LCD_ENTRY_MODE);
	H_LCD_void_SendCommand(LCD_CURSOR_OFF_DISPLAY_ON);
	H_LCD_void_SendCommand(LCD_4BIT_MODE_2_LINE);
	H_LCD_void_SendCommand(LCD_DDRAM_START); // start column


#elif LCD_MODE_SELECT == LCD_8_BIT_MODE_SELECT


#endif
}



void H_LCD_void_SendCommand(u8 Copy_u8Command)
{
#if LCD_MODE_SELECT == LCD_4_BIT_MODE_SELECT
	// write logic low to rs pin
	DIO_voidSetPinValue(LCD_4BIT_RS_PIN_PORT, LCD_4BIT_RS_PIN, GPIO_LOW);

	// Sending most significant nibble of command through data pins
	DIO_voidSetPinValue(LCD_4BIT_D7_PIN_PORT, LCD_4_BIT_D7_PIN, (Copy_u8Command >> 4)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D6_PIN_PORT, LCD_4_BIT_D6_PIN, (Copy_u8Command >> 5)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D5_PIN_PORT, LCD_4_BIT_D5_PIN, (Copy_u8Command >> 6)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D4_PIN_PORT, LCD_4_BIT_D4_PIN, (Copy_u8Command >> 7)&(u8)1);

	// send enable signal
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_LOW);

	// Sending least significant nibble of command through data pins
	DIO_voidSetPinValue(LCD_4BIT_D7_PIN_PORT, LCD_4_BIT_D7_PIN, ((Copy_u8Command) >> 0)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D6_PIN_PORT, LCD_4_BIT_D6_PIN, ((Copy_u8Command) >> 1)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D5_PIN_PORT, LCD_4_BIT_D5_PIN, ((Copy_u8Command) >> 2)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D4_PIN_PORT, LCD_4_BIT_D4_PIN, ((Copy_u8Command) >> 3)&(u8)1);

	// send enable signal
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_LOW);
#elif LCD_MODE_SELECT == LCD_8_BIT_MODE_SELECT


#endif

}
void H_LCD_void_SendData(u8 Copy_u8Data)
{
#if LCD_MODE_SELECT == LCD_4_BIT_MODE_SELECT
	// write logic high to rs pin
	DIO_voidSetPinValue(LCD_4BIT_RS_PIN_PORT, LCD_4BIT_RS_PIN, GPIO_HIGH);

	// Sending most significant nibble of command through data pins
	DIO_voidSetPinValue(LCD_4BIT_D7_PIN_PORT, LCD_4_BIT_D7_PIN, (Copy_u8Data >> 4)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D6_PIN_PORT, LCD_4_BIT_D6_PIN, (Copy_u8Data >> 5)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D5_PIN_PORT, LCD_4_BIT_D5_PIN, (Copy_u8Data >> 6)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D4_PIN_PORT, LCD_4_BIT_D4_PIN, (Copy_u8Data >> 7)&(u8)1);

	// send enable signal
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_LOW);

	// Sending least significant nibble of command through data pins
	DIO_voidSetPinValue(LCD_4BIT_D7_PIN_PORT, LCD_4_BIT_D7_PIN, ((Copy_u8Data) >> 0)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D6_PIN_PORT, LCD_4_BIT_D6_PIN, ((Copy_u8Data) >> 1)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D5_PIN_PORT, LCD_4_BIT_D5_PIN, ((Copy_u8Data) >> 2)&(u8)1);
	DIO_voidSetPinValue(LCD_4BIT_D4_PIN_PORT, LCD_4_BIT_D4_PIN, ((Copy_u8Data) >> 3)&(u8)1);

	// send enable signal
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_HIGH);
	_delay_ms(5);
	DIO_voidSetPinValue(LCD_4BIT_EN_PIN_PORT, LCD_4BIT_EN_PIN, GPIO_LOW);

#elif LCD_MODE_SELECT == LCD_8_BIT_MODE_SELECT  // 8bits configurations


#endif
}
void H_LCD_void_SendString(u8 *Copy_u8Str)
{
	if(NULL == Copy_u8Str)
	{
		/* Nothing */
	}
	else
	{
		while(*Copy_u8Str)
		{
			H_LCD_void_SendData(*Copy_u8Str++);
		}
	}
}
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	copy_u8Col--;
	switch(copy_u8Row){
	case ROW1:
		H_LCD_void_SendCommand(0x80 + copy_u8Col);
		break;
	case ROW2:
		H_LCD_void_SendCommand(0xc0 + copy_u8Col);
		break;
	case ROW3:
		H_LCD_void_SendCommand(0x94 + copy_u8Col);
		break;
	case ROW4:
		H_LCD_void_SendCommand(0xd4 + copy_u8Col);
		break;
	default:

		break;
	}
}



void H_LCD_void_sendIntNum(u32 copy_s32Num)
{
//	u8 num_of_digits = countDigits(copy_s32Num);
//	u8 temp_str[num_of_digits];
//	memset(temp_str, ' ', num_of_digits);
//	temp_str[num_of_digits] = '\0';
//	sprintf((u8 *)temp_str, "%i", copy_s32Num);
//	H_LCD_void_SendString(temp_str);

	char buffer[11];  // A 32-bit number, maximum 10 digits
	itoa(copy_s32Num, buffer, 10);  // Convert the number to a string
	H_LCD_void_SendString(buffer);
}



void H_LCD_void_Clear_Display(void)
{
	H_LCD_void_SendCommand(LCD_CLEAR);
}



void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	u8 lcd_counter = 0;
	if(NULL != ArrPattern)
	{
		H_LCD_void_SendCommand(LCD_CGRAM_START);
		for(lcd_counter = 0; lcd_counter <= 7; ++lcd_counter)
		{
			H_LCD_void_SendData(ArrPattern[lcd_counter]);
		}
	}
	else{/* Nothing */}
}

void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{
	H_LCD_void_SendData(copy_u8charCode);
}


/* --------------------------------------- helper function --------------------------------------- */
//u8 countDigits(s32 number) {
//    u8 count = 0;
//
//    // Handle the case where the number is 0 separately
//    if (number == 0) {
//        return 1;
//    }
//    // For negative numbers, convert to positive before counting digits
//    if (number < 0) {
//    	number = -1 * number;
//    }
//    // Count the digits by dividing by 10 until the number becomes 0
//    while (number != 0) {
//        number /= 10;
//        ++count;
//    }
//
//    return count;
//}
