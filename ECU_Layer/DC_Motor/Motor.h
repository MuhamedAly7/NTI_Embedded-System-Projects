/*
 * Motor.h
 *
 *  Created on: Nov 10, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_DC_MOTOR_MOTOR_H_
#define ECU_LAYER_DC_MOTOR_MOTOR_H_

/* ---------------------------------------------- Includes ------------------------ */
#include "Motor_cfg.h"
#include "../../MCAL_Layer/GPIO/GPIO.h"

/* --------------------------------------------- Macros Objects ------------------- */


/* -------------------------------------------- Macros functions ------------------ */


/* -------------------------------------------- User data types ------------------- */
typedef enum {
	MOTOR_CW_DIRECTION,
	MOTOR_CCW_DIRECTION
}Direction_t;

/* -------------------------------------------- APIs ------------------------------ */
void DC_Motor_Init(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num);
void DC_Motor_ON(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num, Direction_t direction);
void DC_Motor_OFF(u8 Motor_Pin1_Port, u8 Motor_Pin1_Num, u8 Motor_Pin2_Port, u8 Motor_Pin2_Num);
#endif /* ECU_LAYER_DC_MOTOR_MOTOR_H_ */
