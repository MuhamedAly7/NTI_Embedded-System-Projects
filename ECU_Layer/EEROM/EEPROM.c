/*
 * EEPROM.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aly
 */

#include "EEPROM.h"



void EEPROM_Init(u8 req_speed)
{
	Error_Status_t ret_status = NO_ERROR;
	i2c_t init_i2c = {.master_or_slave = I2C_MASTER_MODE,
					  .frequency = req_speed,
					  .prescaler = 0};
	ret_status = I2C_Init(&init_i2c);
}


void EEPROM_WriteByte(u8 address_in_eeprom, u8 data)
{
	// Send start condition
	I2C_SendStart();

	// Send device address with write bit
	I2C_SendByte(EEPROM_DEVICE_ADDRESS_WRITE);

	// Send EEPROM internal address
	I2C_SendByte(address_in_eeprom);

	// Send data byte
	I2C_SendByte(data);

	// Send stop condition
	I2C_SendStop();
}
u8 EEPROM_ReadByte(u8 address_in_eeprom)
{
	u8 data;

	// Send start condition
	I2C_SendStart();

	// Send device address with write bit
	I2C_SendByte(EEPROM_DEVICE_ADDRESS_WRITE);

	// Send EEPROM internal address
	I2C_SendByte(address_in_eeprom);

	// Send repeated start condition
	I2C_SendStart();

	// Send device address with read bit
	I2C_SendByte(EEPROM_DEVICE_ADDRESS_READ);

	// Receive data byte with ACK
	I2C_ReceiveByte_ACK(&data);

	// Send stop condition
	I2C_SendStop();

	return data;
}

void EEPROM_EraseByte(u8 address_in_eeprom)
{
    // Send start condition
    I2C_SendStart();

    // Send device address with write bit
    I2C_SendByte(EEPROM_DEVICE_ADDRESS_WRITE);

    // Send EEPROM internal address
    I2C_SendByte(address_in_eeprom);

    // Send data byte for erasing (e.g., 0xFF)
    I2C_SendByte(0xFF);

    // Send stop condition
    I2C_SendStop();
}
