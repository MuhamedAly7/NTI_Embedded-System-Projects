/*
 * button.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_BUTTON_BUTTON_H_
#define ECU_LAYER_BUTTON_BUTTON_H_

/* --------------------------- Includes Start ------------------------- */
#include "button_cfg.h"

/* ----------------------- Macro Declarations Start ------------------- */


/* ------------------ Macro Function Declarations Start --------------- */


/* -------------------- Data Type Declarations Start ------------------ */
typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW
}button_active_t;

/* --------------- Software Interfaces Declarations Start ------------- */
void Button_void_Init(u8 Button_Pin_Port, u8 Button_Pin_Num);
void Button_void_Read_State(u8 Button_Pin_Port, u8 Button_Pin_Num, button_active_t active_type, button_state_t *button_state);

#endif /* ECU_LAYER_BUTTON_BUTTON_H_ */
