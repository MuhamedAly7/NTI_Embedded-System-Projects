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
#include "keypad_cfg.h"
#include <util/delay.h>

/* ------------------------------------Macro declarations --------------------- */
#define KEYPAD_ROWS    4
#define KEYPAD_COLUMNS 4
/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Data types ----------------------------- */

// additional types
typedef struct{
    u8 digits[5];
    u8 cursor;
}keypad_digit_t;

/* ------------------------------------Function declarations ------------------- */
void H_KEYPAD_void_Init(void);
void H_KEYPAD_u8_getPressedKey(u8 * pPressedKey);


// additional functions on keypad
void keypad_cursor_init(keypad_digit_t *digits_obj);
void H_KEYPAD_u8_WriteOnDigits(keypad_digit_t *digits_obj);

#endif /* ECU_LAYER_KEYPAD_KEYPAD_H_ */
