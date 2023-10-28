/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */


#include "main.h"

void int0_isr(void)
{
	DIO_voidSetPinValue(PORTA_INDEX, PIN0_INDEX, GPIO_LOW);
	_delay_ms(100);
}

Error_Status_t ret_status = NO_ERROR;

EXT_INTERRUPT_T ext_obj = {.INTx_select = EXTI_INT0_ID,
						   .INTx_sense = EXTI_INT0_RISING_EDGE,
						   .EXT_INT_ISR = int0_isr};



int main()
{
	DIO_voidSetPinDirection(PORTA_INDEX, PIN0_INDEX, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(PORTD_INDEX, PIN2_INDEX, GPIO_DIRECTION_INPUT);
	ret_status = M_EXTI_voidEnable(&ext_obj);
	ret_status = M_EXTI_voidSet_CallBack(&ext_obj);
	while (1)
	{
		DIO_voidSetPinValue(PORTA_INDEX, PIN0_INDEX, GPIO_HIGH);
	}
	return 0;
}


