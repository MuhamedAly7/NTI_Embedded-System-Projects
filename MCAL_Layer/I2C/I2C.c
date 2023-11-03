/*
 * I2C.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aly
 */

#include "I2C.h"

Error_Status_t I2C_Init(const i2c_t *i2c_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == i2c_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		// to set prescaler to be one
		I2C_CONTROL->TWSR_REG &= ~(1 << 0);
		I2C_CONTROL->TWSR_REG &= ~(1 << 1);

		// to set bit rate register
		switch (i2c_obj->frequency)
		{
		case I2C_FREQ_100HZ:
			I2C_CONTROL->TWBR_REG = 72;
			break;
		case I2C_FERQ_400HZ:
			I2C_CONTROL->TWBR_REG = 12;
			break;
		default:

			break;
		}

		// Enable TWI
		I2C_CONTROL->TWCR_REG = (1 << 0) | (1 << 6);
	}
	return ret_status;
}



Error_Status_t I2C_SendByte(u8 Copy_u8data)
{
	Error_Status_t ret_status = NULL_POINTER;
	I2C_CONTROL->TWDR_REG = Copy_u8data;
	I2C_CONTROL->TWCR_REG = (1 << 7) | (1 << 2);
	while(!(I2C_CONTROL->TWCR_REG & (1 << 7)));
	return ret_status;
}



Error_Status_t I2C_SendStart(void)
{
	Error_Status_t ret_status = NULL_POINTER;
	I2C_CONTROL->TWCR_REG = (1 << 5) | (1 << 7) | (1 << 2);
	while(!(I2C_CONTROL->TWCR_REG & (1 << 7)));
	return ret_status;
}



Error_Status_t I2C_SendStop(void)
{
	Error_Status_t ret_status = NULL_POINTER;
	I2C_CONTROL->TWCR_REG = (1 << 4) | (1 << 7) | (1 << 2);
	return ret_status;
}


Error_Status_t I2C_ReceiveByte_ACK(u8 *ptr)
{
	Error_Status_t ret_status = NULL_POINTER;
	if(NULL == ptr)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		I2C_CONTROL->TWCR_REG = (1 << 7) | (1 << 6) | (1 << 2);
		while(!(I2C_CONTROL->TWCR_REG & (1 << 7)));
		*ptr = I2C_CONTROL->TWDR_REG;
	}
	return ret_status;
}


Error_Status_t I2C_ReceiveByte_NoACK(u8 *ptr)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == ptr)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		I2C_CONTROL->TWCR_REG = (1 << 7) | (1 << 2);
		while(!(I2C_CONTROL->TWCR_REG & (1 << 7)));
		*ptr = I2C_CONTROL->TWDR_REG;
	}
	return ret_status;
}
Error_Status_t I2C_GetStatus(u8 *status)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == status)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		*status = (I2C_CONTROL->TWSR_REG & 0xF8);
	}
	return ret_status;
}
