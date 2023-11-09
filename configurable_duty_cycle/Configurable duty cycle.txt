/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "main.h"
extern u8 duty_cycle;
extern keypad_digit_t keypad_digits;

/* ------------------------------------ External Interrupt ISR ---------------------- */
void INTx_ISR(void)
{
	sscanf(keypad_digits.digits, "%d", &duty_cycle);
}
/* ----------------------------------------------------------------------------- */

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

/* ---------------------------------- Return Keys from Keypad -------------- */
keypad_digit_t keypad_digits;
/* ------------------------------------------------------------------------- */

/* ------------------------------------ Duty cycle ------------------------- */
u8 duty_cycle = 0;
/* ------------------------------------------------------------------------- */


/* ----------------------- External Interrupt configurations --------------- */
EXT_INTERRUPT_T EXT_INT = {.INTx_select = EXTI_INT0_ID,
						   .INTx_sense = EXTI_INT0_RISING_EDGE,
						   .EXT_INT_ISR = INTx_ISR};
/* ------------------------------------------------------------------------- */

int main()
{
	/* --------------------------------Initialize LCD ----------------------- */
	H_LCD_void_Init();
	/* ---------------------------------------------------------------------- */

	/* ---------------------------------- Initialize Keypad ----------------- */
	H_KEYPAD_void_Init();
	keypad_cursor_init(&keypad_digits);
	/* ---------------------------------------------------------------------- */

	/* ------------------------------ Initialize and start timer0 ----------- */
	ret_status = Timer0_Init(&timer0_obj);
	ret_status = Timer0_start(&timer0_obj);
	/* ----------------------------------------------------------------------- */

	/* -------------------- Enable External Interrupt ------------------------ */
	M_EXTI_voidEnable(&EXT_INT);
	/* ----------------------------------------------------------------------- */

	/* ------------------- Set Call back for ISR of External Interrupt ------- */
	M_EXTI_voidSet_CallBack(&EXT_INT);
	/* ----------------------------------------------------------------------- */

	/* ------------------------------------ Motor Pins ------------------------*/
	DIO_voidSetPinDirection(PORTA_INDEX, PIN4_INDEX, GPIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(PORTA_INDEX, PIN5_INDEX, GPIO_DIRECTION_OUTPUT);
	/* ------------------------------------------------------------------------ */

	while (1)
	{
		/* ------------------------- To Write On specific number of digits ------- */
		H_KEYPAD_u8_WriteOnDigits(&keypad_digits);
		/* ------------------------------------------------------------------------ */

		/* --------------------  --- Set PWM --------------------------------------- */
		ret_status = Timer0_setFastPWM(&timer0_obj, 30, duty_cycle);
		/* ------------------------------------------------------------------------- */

		DIO_voidSetPinValue(PORTA_INDEX, PIN4_INDEX, GPIO_HIGH);
		DIO_voidSetPinValue(PORTA_INDEX, PIN5_INDEX, GPIO_LOW);

		/* ---------------------------------- Print on screen ----------------------- */
		H_LCD_void_gotoXY(2, 1);
		H_LCD_void_SendString("desired duty cyc: ");
		H_LCD_void_gotoXY(3, 8);
		H_LCD_void_SendString(keypad_digits.digits);
		/* -------------------------------------------------------------------------- */
	}
	return 0;
}
