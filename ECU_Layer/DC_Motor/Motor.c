/*
 * Motor.c
 *
 *  Created on: Nov 10, 2023
 *      Author: Mohamed Aly
 */

#include "Motor.h"

void DC_Motor_Init(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num)
{
	DIO_voidSetPinDirection(Motor_Pin1_Port, Motor_Pin1_Num, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(Motor_Pin2_Port, Motor_Pin2_Num, GPIO_DIRECTION_OUTPUT);
}


void DC_Motor_ON(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num, Direction_t direction)
{
	switch(direction)
	{
		case MOTOR_CW_DIRECTION:
			DIO_voidSetPinValue(Motor_Pin1_Port, Motor_Pin1_Num, GPIO_HIGH);
			DIO_voidSetPinValue(Motor_Pin2_Port, Motor_Pin2_Num, GPIO_LOW);
			break;
		case MOTOR_CCW_DIRECTION:
			DIO_voidSetPinValue(Motor_Pin1_Port, Motor_Pin1_Num, GPIO_LOW);
			DIO_voidSetPinValue(Motor_Pin2_Port, Motor_Pin2_Num, GPIO_HIGH);
			break;
	}
}


void DC_Motor_OFF(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num)
{
	DIO_voidSetPinValue(Motor_Pin1_Port, Motor_Pin1_Num, GPIO_LOW);
	DIO_voidSetPinValue(Motor_Pin2_Port, Motor_Pin2_Num, GPIO_LOW);
}
