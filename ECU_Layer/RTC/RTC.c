/*
 * RTC.c
 *
 *  Created on: Nov 3, 2023
 *      Author: Mohamed Aly
 */


#include "RTC_cfg.h"
#include "RTC.h"

static u8 decimal_to_BCD(u8 decimal);
static u8 BCD_to_decimal(u8 bcd);


void RTC_Init(u8 req_speed)
{
	Error_Status_t ret_status = NO_ERROR;
	i2c_t init_i2c = {.master_or_slave = I2C_MASTER_MODE,
			.frequency = req_speed,
			.prescaler = 0};
	ret_status = I2C_Init(&init_i2c);
}


void RTC_SetTime(const RTC_TIME_T *init_time)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 sec_bcd = decimal_to_BCD(init_time->sec);
	u8 min_bcd = decimal_to_BCD(init_time->min);
	u8 hour_bcd = decimal_to_BCD(init_time->hour);

	// Send start
	ret_status = I2C_SendStart();

	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_WRITE);

	// Send address that wanted to access
	ret_status = I2C_SendByte(0x00);

	// send second
	ret_status = I2C_SendByte(sec_bcd);

	// send min
	ret_status = I2C_SendByte(min_bcd);

	// send hour
	ret_status = I2C_SendByte(hour_bcd);

	// send stop
	ret_status = I2C_SendStop();
}


void RTC_GetTime(RTC_TIME_T *time)
{
	Error_Status_t ret_status = NO_ERROR;
	// Send start
	ret_status = I2C_SendStart();
	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_WRITE);
	// Send address that wanted to access
	ret_status = I2C_SendByte(0x00);
	// Send start
	ret_status = I2C_SendStart();
	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_READ);

	// receive time
	ret_status = I2C_ReceiveByte_ACK(&(time->sec));
	ret_status = I2C_ReceiveByte_ACK(&(time->min));
	ret_status = I2C_ReceiveByte_NoACK(&(time->hour));
	// send stop
	ret_status = I2C_SendStop();

	time->sec = BCD_to_decimal(time->sec);
	time->min = BCD_to_decimal(time->min);
	time->hour = BCD_to_decimal(time->hour);
}


void RTC_SetDate(const RTC_DATE_T *init_date)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 day_bcd = decimal_to_BCD(init_date->day);
	u8 mon_bcd = decimal_to_BCD(init_date->month);
	u8 year_bcd = decimal_to_BCD(init_date->year);

	// Send start
	ret_status = I2C_SendStart();
	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_WRITE);
	// Send address that wanted to access
	ret_status = I2C_SendByte(0x04);
	// send day
	ret_status = I2C_SendByte(day_bcd);

	// send month
	ret_status = I2C_SendByte(mon_bcd);

	// send year
	ret_status = I2C_SendByte(year_bcd);

	// send stop
	ret_status = I2C_SendStop();

}


void RTC_GetDate(RTC_DATE_T *date)
{
	Error_Status_t ret_status = NO_ERROR;
	// Send start
	ret_status = I2C_SendStart();
	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_WRITE);
	// Send address that wanted to access
	ret_status = I2C_SendByte(0x04);
	// Send start
	ret_status = I2C_SendStart();
	// send address
	ret_status = I2C_SendByte(DS1307_ADDRESS_READ);
	// receive time
	ret_status = I2C_ReceiveByte_ACK(&(date->day));
	ret_status = I2C_ReceiveByte_ACK(&(date->month));
	ret_status = I2C_ReceiveByte_NoACK(&(date->year));
	// send stop
	ret_status = I2C_SendStop();

	date->day = BCD_to_decimal(date->day);
	date->month = BCD_to_decimal(date->month);
	date->year = BCD_to_decimal(date->year);
}


/* -------------------------------------------------- Helper functions ----------------------- */
static u8 decimal_to_BCD(u8 decimal)
{
	u8 first_digits = (u8)(decimal % 10); // Extract first digit from decimal
	u8 seconnd_digits = (u8)(decimal / 10); // Extract second digit from decimal
	u8 result_num = (seconnd_digits << 4) + first_digits;
}

static u8 BCD_to_decimal(u8 bcd)
{
	u8 first_digits = bcd & 0x0F;  // Extract the lower 4 bits
	u8 second_digits = (bcd >> 4) * 10;  // Extract the higher 4 bits and multiply by 10
	u8 result_num = second_digits + first_digits;
	return result_num;
}
