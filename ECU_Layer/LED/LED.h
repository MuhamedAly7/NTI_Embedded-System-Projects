/*
 * LED.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_LED_LED_H_
#define ECU_LAYER_LED_LED_H_

/* ------------------------------------------------- Includes ----------------------------------------- */
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "LED_cfg.h"

/* ------------------------------------------------ Macros objects ------------------------------------ */


/* ------------------------------------------------ Macros Functions ---------------------------------- */


/* ------------------------------------------------ User Data Types ----------------------------------- */


/* ------------------------------------------------ APIs ---------------------------------------------- */
void Led_Init(u8 Led_Pin_Port, u8 Led_Pin_PinNum);
void Led_TurnOn(u8 Led_Pin_Port, u8 Led_Pin_PinNum);
void Led_TurnOff(u8 Led_Pin_Port, u8 Led_Pin_PinNum);
void Led_Toggle(u8 Led_Pin_Port, u8 Led_Pin_PinNum);

#endif /* ECU_LAYER_LED_LED_H_ */
