/*
 * RTC.h
 *
 *  Created on: Nov 3, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_RTC_RTC_H_
#define ECU_LAYER_RTC_RTC_H_

/* --------------------------------------------------- Includes ------------------------------------*/
#include "../../MCAL_Layer/I2C/I2C.h"



/* --------------------------------------------------- Macros objects ----------------------------- */
#define DS1307_ADDRESS_WRITE 0xD0
#define DS1307_ADDRESS_READ  0xD1
#define DS1307_BASE_ADDRESS_OF_TIME  0x00
#define DS1307_BASE_ADDRESS_OF_DATE  0x04

/* --------------------------------------------------- User data types ---------------------------- */

typedef enum {
	AM = 0,
	PM = 1
}time_format_t;

typedef struct {
	u8 hour;
	u8 min;
	u8 sec;
#if RTC_TIME_SYSTEM == RTC_12HR_SYSTEM
	time_format_t ampm;
#endif
}RTC_TIME_T;

typedef struct {
	u8 year;
	u8 month;
	u8 day;
}RTC_DATE_T;

/*--------------------------------------------------- APIs --------------------------------------- */
void RTC_Init(u8 req_speed);
void RTC_SetTime(const RTC_TIME_T *init_time);
void RTC_GetTime(RTC_TIME_T *time);
void RTC_SetDate(const RTC_DATE_T *init_date);
void RTC_GetDate(RTC_DATE_T *date);

#endif /* ECU_LAYER_RTC_RTC_H_ */
