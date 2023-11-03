/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "main.h"

Error_Status_t ret_status = NO_ERROR;

u8 rec_data;

RTC_TIME_T my_time = {.hour = 22,
		.min = 28,
		.sec = 0,
		.ampm = 0};

RTC_DATE_T my_date = {.year = 23,
		.month = 11,
		.day = 3};


RTC_TIME_T rec_time;
RTC_DATE_T rec_date;

char buffer1[50];
char buffer2[50];

int main()
{
	H_LCD_void_Init();
	RTC_Init(I2C_FREQ_100HZ);
	RTC_SetTime(&my_time);
	RTC_SetDate(&my_date);

	while (1)
	{
		_delay_ms(20);
		RTC_GetTime(&rec_time);
		_delay_ms(20);
		_delay_ms(20);
		RTC_GetDate(&rec_date);
		_delay_ms(20);

		sprintf(buffer1, "%02d:%02d:%02d", rec_time.hour, rec_time.min, rec_time.sec);
		sprintf(buffer2, "%02d:%02d:%02d", rec_date.month, rec_date.day, rec_date.year);
		H_LCD_void_gotoXY(2, 1);
		H_LCD_void_SendString("Time : ");
		H_LCD_void_SendString(buffer1);
		H_LCD_void_gotoXY(3, 1);
		H_LCD_void_SendString("Date : ");
		H_LCD_void_SendString(buffer2);
	}
	return 0;
}


