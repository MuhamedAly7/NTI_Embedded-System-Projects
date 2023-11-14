/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "main.h"

/* ----------------------------------- Error status ------------------------- */
Error_Status_t ret_status = NO_ERROR;
/* -------------------------------------------------------------------------- */

/* ---------------------------------------- User ID -------------------------*/
u8 ID[5] = "eebb";
/* ------------------------------------------------------------------------- */

/* ---------------------------------------- User Password ------------------ */
u8 pass[5] = "6677";
/* ------------------------------------------------------------------------- */


/* ---------------------------------- Return Keys from Keypad -------------- */
u8 pressed_key;
keypad_digit_t keypad_digits;
keypad_digit_t keypad_digits_pass;
/*----------------------------------------------------------------------------*/

/* --------------------- To counts number of times to write password -------- */
u8 repeated_pass = 0;
/* -------------------------------------------------------------------------- */


/* ----------------------------------- To work with RTC --------------------  */
RTC_TIME_T my_time = { // We will use RTC as a stop watch
		.hour = 0,
		.min = 0,
		.sec = 0};
RTC_TIME_T rec_time;
char buffer[50]; // This buffer to display the stop watch
/*----------------------------------------------------------------------------*/


/* ------------------------------- distance from Ultra-sound ----------------- */
u32 distance = 30;
/*-----------------------------------------------------------------------------*/

int main()
{
	/* ------------------------------- To Display distance value ------------ */
	char buffer[4];
	buffer[3] = ' ';
	/* ----------------------------------------------------------------------- */

	/* ----------------------------------- Keypad Initialize ------------------- */
	H_KEYPAD_void_Init();
	keypad_cursor_init(&keypad_digits);
	/* ------------------------------------------------------------------------ */

	/* -------------------------------- LCD Initialize ------------------------ */
	H_LCD_void_Init();
	/* ------------------------------------------------------------------------ */

	/* --------------------------- System Start message ----------------------- */
	H_LCD_void_gotoXY(2,4);
	H_LCD_void_SendString(" Login System ");
	_delay_ms(1000);
	/* ------------------------------------------------------------------------ */

	/* --------------------------- Clear display ------------------------------ */
	H_LCD_void_Clear_Display();
	/*--------------------------------------------------------------------------*/

	/*------------------------------------- Green Led --------------------------*/
	Led_Init(PORTA_INDEX, PIN4_INDEX);
	/* ------------------------------------------------------------------------ */
	/*------------------------------------- Blue Led --------------------------*/
	Led_Init(PORTA_INDEX, PIN5_INDEX);
	/* ------------------------------------------------------------------------ */

	/* --------------------------------- Initialize Trigger and Echo Pins-------------------- */
	Ultrasonic_Init(PORTD_INDEX, PIN2_INDEX, PORTD_INDEX, PIN6_INDEX);
	/* -------------------------------------------------------------------------------------- */

	/* --------------------------------------- Initialize RTC ---------------------------------*/
	RTC_Init(I2C_FREQ_100HZ);
	/* --------------------------------------------------------------------------------------- */

	while (1)
	{
		Start_again:
		/* --------------------------------- Set Trigger of Ultra-sound ------------------- */
		Ultrasonic_SetTrigger(PORTD_INDEX, PIN2_INDEX);
		/* -------------------------------------------------------------------------------- */

		/* --------------------------------- Read Distance -------------------------------- */
		Ultrasonic_Read_Distance(&distance);
		/* -------------------------------------------------------------------------------- */

		/* ---------------------------------- Display distance ---------------------------- */
		sprintf(buffer, "%03d", distance);
		H_LCD_void_gotoXY(2, 2);
		H_LCD_void_SendString("Distance : ");
		H_LCD_void_SendString(buffer);
		/* -------------------------------------------------------------------------------------- */

		if(distance <= 15)
		{
			/* -------------------------- User Message ---------------------------- */
			H_LCD_void_Clear_Display();
			H_LCD_void_gotoXY(2,4);
			H_LCD_void_SendString("User Detected");
			_delay_ms(500);
			/* -------------------------------------------------------------------------------------- */
			start_from_id:
			H_LCD_void_Clear_Display();
			H_LCD_void_gotoXY(2,1);
			H_LCD_void_SendString("Enter ID : ");
			while(1)
			{
				/*------------------------------ Still read the distance -----------------------*/
				Ultrasonic_SetTrigger(PORTD_INDEX, PIN2_INDEX);
				Ultrasonic_Read_Distance(&distance);
				/*------------------------------------------------------------------------------*/

				/* ---------------------------- Writing ID digits ----------------------------- */
				H_KEYPAD_u8_WriteOnDigits(&keypad_digits);
				H_LCD_void_gotoXY(2,12);
				H_LCD_void_SendString(keypad_digits.digits);
				/* ---------------------------------------------------------------------------- */

				if(strcmp(ID, keypad_digits.digits) == 0)
				{
					keypad_cursor_init(&keypad_digits);
					keypad_cursor_init(&keypad_digits_pass); // new
					H_LCD_void_Clear_Display();
					_delay_ms(500);
					H_LCD_void_gotoXY(2,4);
					H_LCD_void_SendString("Right ID");
					_delay_ms(500);
					H_LCD_void_Clear_Display();

					start_from_pass:
					H_LCD_void_gotoXY(2,1);
					H_LCD_void_SendString("Password : ");
					while(1)
					{
						/*------------------------------ Still read the distance -----------------------*/
						Ultrasonic_SetTrigger(PORTD_INDEX, PIN2_INDEX);
						Ultrasonic_Read_Distance(&distance);
						/*------------------------------------------------------------------------------*/

						/* ---------------------------- Writing Password digits ----------------------- */
						H_KEYPAD_u8_WriteOnDigits(&keypad_digits);
						H_LCD_void_gotoXY(2,12);
						H_LCD_void_SendString(keypad_digits.pass_digits);
						/*------------------------------------------------------------------------------*/

						if(strcmp(pass, keypad_digits.digits) == 0)
						{
							H_LCD_void_Clear_Display();
							_delay_ms(1000);
							H_LCD_void_gotoXY(2,2);
							H_LCD_void_SendString("Welcome Mohammed");
							_delay_ms(2000);
							H_LCD_void_Clear_Display();

							/* ---------------------------------------- Start Our Application ----------------------- */
							while(1)
							{
								/* ------------------------------ Control Your System now ---------------------------- */
								H_KEYPAD_u8_getPressedKey(&pressed_key);
								if(pressed_key == 1)
								{
									Led_TurnOn(PORTA_INDEX, PIN4_INDEX);
								}
								else if(pressed_key == 2)
								{
									Led_TurnOff(PORTA_INDEX, PIN4_INDEX);
								}
								else if(pressed_key == 3)
								{
									Led_TurnOn(PORTA_INDEX, PIN5_INDEX);
								}
								else if(pressed_key == 4)
								{
									Led_TurnOff(PORTA_INDEX, PIN5_INDEX);
								}
							}
							/* ----------------------------------------------------------------------------------- */
						}
						else if((strcmp(pass, keypad_digits.digits) != 0) && (keypad_digits.cursor == 4))
						{
							repeated_pass++;
							if(repeated_pass < 3)
							{
								H_LCD_void_Clear_Display();
								_delay_ms(500);
								H_LCD_void_gotoXY(2,4);
								H_LCD_void_SendString("Wrong Password");
								_delay_ms(500);
								H_LCD_void_Clear_Display();
								_delay_ms(1000);
								H_LCD_void_gotoXY(2,4);
								H_LCD_void_SendString("Try Again");
								_delay_ms(500);
								H_LCD_void_Clear_Display();
								keypad_cursor_init(&keypad_digits);
								goto start_from_pass;
							}
							else
							{
								repeated_pass = 0;
								H_LCD_void_Clear_Display();
								RTC_SetTime(&my_time);

								while(rec_time.sec <= 20)
								{
									/*------------------------------ Still read the distance -----------------------*/
									Ultrasonic_SetTrigger(PORTD_INDEX, PIN2_INDEX);
									Ultrasonic_Read_Distance(&distance);
									/*------------------------------------------------------------------------------*/
									RTC_GetTime(&rec_time);
									_delay_ms(10);
									sprintf(buffer, "%02d:%02d:%02d", rec_time.hour, rec_time.min, rec_time.sec);
									H_LCD_void_gotoXY(1, 1);
									H_LCD_void_SendString("Wait 20 seconds");
									H_LCD_void_gotoXY(2, 2);
									H_LCD_void_SendString(buffer);
								}
								H_LCD_void_Clear_Display();
								keypad_cursor_init(&keypad_digits);
								goto start_from_pass;
							}
						}

						/* To detect there user go out from system and avoid system stucking  */
						if(distance > 17)
						{
							H_LCD_void_Clear_Display();
							H_LCD_void_gotoXY(2, 4);
							H_LCD_void_SendString("GOOD Bye !");
							_delay_ms(300);
							H_LCD_void_Clear_Display();
							goto Start_again;
						}
						/*---------------------------------------------------------------------*/
					}
				}
				else if((strcmp(ID, keypad_digits.digits) != 0) && (keypad_digits.cursor == 4))
				{
					H_LCD_void_Clear_Display();
					_delay_ms(1000);
					H_LCD_void_gotoXY(2,4);
					H_LCD_void_SendString("Wrong ID");
					_delay_ms(1000);
					H_LCD_void_Clear_Display();
					_delay_ms(1000);
					H_LCD_void_gotoXY(2,4);
					H_LCD_void_SendString("Try Again");
					_delay_ms(1000);
					H_LCD_void_Clear_Display();
					keypad_cursor_init(&keypad_digits);
					goto start_from_id;
				}

				/* To detect there user go out from system and avoid system stucking  */
				if(distance > 17)
				{
					H_LCD_void_Clear_Display();
					H_LCD_void_gotoXY(2, 4);
					H_LCD_void_SendString("GOOD Bye !");
					_delay_ms(300);
					H_LCD_void_Clear_Display();
					break;
				}
				/*---------------------------------------------------------------------*/
			}
		} // End of distance measure
		else{/* Nothing */}
	}
	return 0;
}
