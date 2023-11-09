/*
 * LED.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Mohamed Aly
 */


#include "LED.h"


void Led_Init(u8 Led_Pin_Port, u8 Led_Pin_PinNum)
{
	DIO_voidSetPinDirection(Led_Pin_Port, Led_Pin_PinNum, GPIO_DIRECTION_OUTPUT);
}


void Led_TurnOn(u8 Led_Pin_Port, u8 Led_Pin_PinNum)
{
	DIO_voidSetPinValue(Led_Pin_Port, Led_Pin_PinNum, GPIO_HIGH);
}


void Led_TurnOff(u8 Led_Pin_Port, u8 Led_Pin_PinNum)
{
	DIO_voidSetPinValue(Led_Pin_Port, Led_Pin_PinNum, GPIO_LOW);
}


void Led_Toggle(u8 Led_Pin_Port, u8 Led_Pin_PinNum)
{
	DIO_voidTogglePinValue(Led_Pin_Port, Led_Pin_PinNum);
}
