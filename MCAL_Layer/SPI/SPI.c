/*
 * SPI.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Aly
 */


#include "SPI.h"

//u8 dum = 0;

// SPI callback
void (*spi_callbackfun)() = NULL;

Error_Status_t SPI_Init(const SPI_T *spi_obj)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == spi_obj)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		if(MASTER_CONFIG == spi_obj->MasterSlaveSelect)
		{
			DIO_voidSetPinDirection(PORTB_INDEX, PIN5_INDEX, GPIO_DIRECTION_OUTPUT);
			DIO_voidSetPinDirection(PORTB_INDEX, PIN7_INDEX, GPIO_DIRECTION_OUTPUT);
			SPI_MAP->SPCR_CFG = (0x01 << 6) | (0x01 << 4) | (0x01 << 0);
		}
		else if(SLAVE_CONFIG == spi_obj->MasterSlaveSelect)
		{
			DIO_voidSetPinDirection(PORTB_INDEX, PIN6_INDEX, GPIO_DIRECTION_OUTPUT);
			SPI_MAP->SPCR_CFG = (0x01 <<6);
		}
	}
	return ret_status;
}
Error_Status_t SPI_Transfere(u8 Copy_u8Ch, u8 *pch)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == pch)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		SPI_MAP->SPDR_CFG = Copy_u8Ch;
		while(!(SPI_MAP->SPSR_CFG & (0x01<<7)));
		*pch = SPI_MAP->SPDR_CFG;
	}
	return ret_status;
}

Error_Status_t SPI_AsynchCallBack(void (*spi_callback)(void), u8 ch)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == spi_callback)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		GIE_Enable();
		SPI_MAP->SPCR_CFG |= (0x01<<7);
		spi_callbackfun = spi_callback;
		SPI_MAP->SPDR_CFG = ch;
	}
	return ret_status;
}

Error_Status_t SPI_Send_String(u8 *Str)
{
	Error_Status_t ret_status = NO_ERROR;
	u8 dummy_var;
	if(NULL == Str)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		while(*Str)
		{
			ret_status = SPI_Transfere(*Str, &dummy_var);
			Str++;
		}
	}
	return ret_status;
}


// Define the ISR function with attribute
void SPI_VECTOR(void) __attribute__((signal));
void SPI_VECTOR(void)
{
	// Clear flag

	// execute ISR if it existed
	//dum = SPI_MAP->SPDR_CFG;
//	CLEAR_BIT(SPI_MAP->SPCR_CFG, 7);

	if(spi_callbackfun)
	{
		spi_callbackfun();
	}
}
