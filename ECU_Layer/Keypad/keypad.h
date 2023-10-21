/*
 * keypad.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_KEYPAD_KEYPAD_H_
#define ECU_LAYER_KEYPAD_KEYPAD_H_
/*-------------------------------------Includes---------------------------------*/
#include "../../MCAL_Layer/GPIO/GPIO.h"

/* ------------------------------------Macro declarations --------------------- */
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4
/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Data types ----------------------------- */
typedef struct{
	GPIO_CFG_T keypad_rows_pins[KEYPAD_ROWS];
	GPIO_CFG_T keypad_columns_pins[KEYPAD_COLUMNS];
}keypad_t;
/* ------------------------------------Function declarations ------------------- */
PROGRAM_STATUS_T keypad_init(const keypad_t *keypad_obj);
PROGRAM_STATUS_T keypad_read_value(const keypad_t *keypad_obj, u8 *value);
#endif /* ECU_LAYER_KEYPAD_KEYPAD_H_ */
