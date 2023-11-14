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


/* --------------------Pressed key form keypad ------------ */
u8 pressed_key = 0;
/* -------------------------------------------------------- */

u8 Fp_status;
u16 ret_ID;

u16 page_id = 1;

int main()
{
	/* ------------------ Initialize LCD ------------- */
	H_LCD_void_Init();
	/*--------------------------------------------------*/

	/* --------------------------- Keypad Initialize ------------------- */
	H_KEYPAD_void_Init();
	/* -------------------------------------------------------------- */

	Fp_status = FingerPS_handShake();
	Fp_status = 0;



	while (1)
	{
		/* ------------------------- write on keypad ---------------------- */
		H_KEYPAD_u8_getPressedKey(&pressed_key);
		/* ----------------------------------------------------------------- */


		/* ------------------- Display the selections ----------------------- */
		H_LCD_void_gotoXY(2,1);
		H_LCD_void_SendString("attendance->1");
		H_LCD_void_gotoXY(3,1);
		H_LCD_void_SendString("Enroll->2");
		/* ------------------------------------------------------------------ */


		if(pressed_key == 1) // Attendance
		{
			Fp_status = FingerPS_Attendance(&ret_ID);

			if(Fp_status == 1)
			{
				H_LCD_void_Clear_Display();
				H_LCD_void_gotoXY(2, 3);
				H_LCD_void_SendString("Welcome Sir!");
				_delay_ms(3000);
				H_LCD_void_Clear_Display();
			}
			else
			{
				H_LCD_void_Clear_Display();
				H_LCD_void_gotoXY(2, 3);
				H_LCD_void_SendString("Not existed");
				_delay_ms(3000);
				H_LCD_void_Clear_Display();
			}
			pressed_key = 0;
		}
		else if(pressed_key == 2) // Enrollment
		{
			Fp_status = FingerPS_Enrollment(page_id, &ret_ID);
			page_id++;
			if(Fp_status == 0)
			{
				H_LCD_void_Clear_Display();
				H_LCD_void_gotoXY(1, 3);
				H_LCD_void_SendString("this finger");
				H_LCD_void_gotoXY(2, 3);
				H_LCD_void_SendString("already exist");
				_delay_ms(2000);
				H_LCD_void_Clear_Display();
			}
			else if(Fp_status == 1)
			{
				H_LCD_void_Clear_Display();
				H_LCD_void_gotoXY(2, 1);
				H_LCD_void_SendString("Enrollment Complete");
				_delay_ms(2000);
				H_LCD_void_Clear_Display();
			}
			pressed_key = 0;
		}
	}

	return 0;
}
