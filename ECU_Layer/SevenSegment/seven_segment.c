/*
 * seven_segment.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */
#include "seven_segment.h"

void SevenSeG_voidinit(void)
{
	DIO_voidSetPinDirection(SEGMENT_PIN0_PORT, SEGMENT_PIN0, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(SEGMENT_PIN1_PORT, SEGMENT_PIN1, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(SEGMENT_PIN2_PORT, SEGMENT_PIN2, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(SEGMENT_PIN3_PORT, SEGMENT_PIN3, GPIO_DIRECTION_OUTPUT);
}

void SevenSeG_voidWriteNum(u8 Copy_u8Number)
{

	DIO_voidSetPinValue(SEGMENT_PIN0_PORT, SEGMENT_PIN0, ((Copy_u8Number >> 0) & 0x01));
	DIO_voidSetPinValue(SEGMENT_PIN1_PORT, SEGMENT_PIN1, ((Copy_u8Number >> 1) & 0x01));
	DIO_voidSetPinValue(SEGMENT_PIN2_PORT, SEGMENT_PIN2, ((Copy_u8Number >> 2) & 0x01));
	DIO_voidSetPinValue(SEGMENT_PIN3_PORT, SEGMENT_PIN3, ((Copy_u8Number >> 3) & 0x01));
}


