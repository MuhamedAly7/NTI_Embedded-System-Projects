/*
 * keypad.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#include "keypad.h"

static const u8 btn_values[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
                                                            {1, 2, 3, 4},
                                                            {5, 6, 7, 8},
                                                            {9, 10, 11, 12},
                                                            {13, 14, 15, 16},
                                                             };


PROGRAM_STATUS_T keypad_init(const keypad_t *keypad_obj)
{
	PROGRAM_STATUS_T ret_status = SUCCESS;
	u8 row_counter = 0;
	u8 column_counter = 0;
	if(NULL == keypad_obj)
	{
		ret_status = NULL_PTR;
	}
	else
	{
		for(row_counter = 0; row_counter < KEYPAD_ROWS; row_counter++)
		{
			ret_status = DIO_SetPinDirection(&(keypad_obj->keypad_rows_pins[row_counter]));
		}

		for(column_counter = 0; column_counter < KEYPAD_COLUMNS; column_counter++)
		{
			ret_status = DIO_SetPinDirection(&(keypad_obj->keypad_rows_pins[column_counter]));
		}
	}
	return ret_status;
}

PROGRAM_STATUS_T keypad_read_value(const keypad_t *keypad_obj, u8 *value)
{
	PROGRAM_STATUS_T ret_status = SUCCESS;
		u8 l_row_counter = 0;
		u8 l_column_counter = 0;
		u8 l_counter = 0;
		u8 column_logic = 0;
		if(NULL == keypad_obj)
		{
			ret_status = NULL_PTR;
		}
		else
		{
			for(l_row_counter = 0; l_row_counter < KEYPAD_ROWS; l_row_counter++)
			{
				// Set All pins to be low at first
				for(l_counter = 0; l_counter < KEYPAD_ROWS; l_counter++)
				{
					ret_status = DIO_SetPinValue(&(keypad_obj->keypad_rows_pins[l_counter]), GPIO_LOW);
				}

				ret_status = DIO_SetPinValue(&(keypad_obj->keypad_rows_pins[l_row_counter]), GPIO_HIGH);

				for(l_column_counter = 0; l_column_counter < KEYPAD_COLUMNS; l_column_counter++)
				{
					ret_status = DIO_GetPinValue(&(keypad_obj->keypad_columns_pins[l_column_counter]), &column_logic);

					if(column_logic == GPIO_HIGH)
					{
						*value = btn_values[l_row_counter][l_column_counter];
					}
				}
			}
		}
		return ret_status;
}
