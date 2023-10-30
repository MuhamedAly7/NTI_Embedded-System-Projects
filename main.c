/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */


#include "main.h"

u8 dum1 = 0;

void Spi_Isr(void)
{
	DIO_voidSetPinValue(PORTA_INDEX, PIN1_INDEX, GPIO_HIGH);
	dum1 = SPI_MAP->SPDR_CFG;
	DIO_voidSetPinValue(PORTA_INDEX, PIN2_INDEX, GPIO_HIGH);
}

Error_Status_t ret_status = NO_ERROR;
//u8 rec_byte;

SPI_T my_spi = {.MasterSlaveSelect = MASTER_CONFIG};

u8 dummy_spi;

u8 string[] = "HELLO";

int main()
{
	ret_status = SPI_Init(&my_spi);
	DIO_voidSetPinDirection(PORTA_INDEX, PIN1_INDEX, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(PORTA_INDEX, PIN2_INDEX, GPIO_DIRECTION_OUTPUT);
	while (1)
	{
//		ret_status = SPI_AsynchCallBack(Spi_Isr, 'A');
//		_delay_ms(1000);
//		DIO_voidSetPinValue(PORTA_INDEX, PIN1_INDEX, GPIO_LOW);
//		DIO_voidSetPinValue(PORTA_INDEX, PIN1_INDEX, GPIO_LOW);
//		_delay_ms(1000);

		DIO_voidSetPinValue(PORTA_INDEX, PIN1_INDEX, GPIO_HIGH);
		DIO_voidSetPinValue(PORTA_INDEX, PIN2_INDEX, GPIO_HIGH);
		_delay_ms(1000);
		ret_status = SPI_Transfere('A', &dummy_spi);
		//ret_status = SPI_AsynchCallBack(Spi_Isr, 'A');
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA_INDEX, PIN1_INDEX, GPIO_LOW);
		DIO_voidSetPinValue(PORTA_INDEX, PIN2_INDEX, GPIO_LOW);
		_delay_ms(1000);
	}
	return 0;
}


