/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "main.h"

#define DEGREE_SYMBOL 0xdf

/* ----------------------------------- Error status ------------------------- */
Error_Status_t ret_status = NO_ERROR;
/* -------------------------------------------------------------------------- */

/*------------------------- Timer0 Configurations -------------------------- */
timer0_t timer0_obj = {
		.mode = TIMER0_FAST_PWM_MODE,
		.prescaler_select = TIMER1_PRESCALER_DIV_64,
		.ctc_mode_cfg = TIMER0_FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH,
		.timer0_over_flow_isr = NULL,
		.timer0_comp_isr = NULL};
/* ------------------------------------------------------------------------- */

/* To read the degree in celsius */
float celsius;

int main()
{
	/* To print temperature in LCD */
	u8 Temperature[10];
	/*-----------------------------*/

	/* Initialize LCD */
	H_LCD_void_Init();
	/*----------------*/

	/* Initialize the direction of channels */
	DIO_voidSetPinDirection(PORTA_INDEX, PIN0_INDEX, GPIO_DIRECTION_INPUT);
	DIO_voidSetPinDirection(PORTA_INDEX, PIN1_INDEX, GPIO_DIRECTION_INPUT);
	/*----------------------------------------*/

	/* Initialize LM35 sensor */
	LM35_Init();
	/*-------------------------*/

	/* ------------------------------ Initialize and start timer0 ----------- */
	ret_status = Timer0_Init(&timer0_obj);
	ret_status = Timer0_start(&timer0_obj);
	/* ----------------------------------------------------------------------- */

	/* Initialize DC motor */
	DC_Motor_Init(PORTC_INDEX, PIN3_INDEX, PORTC_INDEX, PIN4_INDEX);
	/*----------------------*/

	H_LCD_void_gotoXY(1, 1);
	H_LCD_void_SendString("Temperature");

	while (1)
	{
		/* Take readings of LM35 */
		LM35_Reading(LM35_CHANNEL_1, &celsius);
		/* ------------------------- */

		/* Printing temperature on LCD */
		sprintf(Temperature,"%d%cC  ", (int)celsius, DEGREE_SYMBOL);
		H_LCD_void_gotoXY(2, 1);
		H_LCD_void_SendString(Temperature);
		memset(Temperature,0,10);
		/* --------------------------------- */

		if((celsius >= 25.00) && (celsius <= 35.00))
		{
			DC_Motor_ON(PORTC_INDEX, PIN3_INDEX, PORTC_INDEX, PIN4_INDEX, MOTOR_CW_DIRECTION);
			ret_status = Timer0_setFastPWM(&timer0_obj, 30, 50);
		}
		else if(celsius >= 35.00)
		{
			DC_Motor_ON(PORTC_INDEX, PIN3_INDEX, PORTC_INDEX, PIN4_INDEX, MOTOR_CW_DIRECTION);
			ret_status = Timer0_setFastPWM(&timer0_obj, 30, 80);
		}
		else
		{
			DC_Motor_OFF(PORTC_INDEX, PIN3_INDEX, PORTC_INDEX, PIN4_INDEX);
			ret_status = Timer0_setFastPWM(&timer0_obj, 30, 0);
		}

	}

	return 0;
}
