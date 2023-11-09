/*
 * Ultrasonic.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_ULTRASONIC_ULTRASONIC_H_
#define ECU_LAYER_ULTRASONIC_ULTRASONIC_H_

/* ------------------------------------------------- Includes ----------------------------------------- */
#include "Ultrasonic_cfg.h"
#include "../../MCAL_Layer/timer1/timer1.h"
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include <util/delay.h>
/* ------------------------------------------------ Macros objects ------------------------------------ */


/* ------------------------------------------------ Macros Functions ---------------------------------- */


/* ------------------------------------------------ User Data Types ----------------------------------- */


/* ------------------------------------------------ APIs ---------------------------------------------- */
void Ultrasonic_Init(u8 Trig_Pin_Port, u8 Trig_Pin_PinNum, u8 Echo_Pin_Port, u8 Echo_Pin_Num);
void Ultrasonic_SetTrigger(u8 Trig_Pin_Port, u8 Trig_Pin_Num);
void Ultrasonic_Read_Distance(u16 *distance);

#endif /* ECU_LAYER_ULTRASONIC_ULTRASONIC_H_ */
