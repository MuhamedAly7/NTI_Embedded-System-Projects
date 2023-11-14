/*
 * LM35.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_LM35_LM35_H_
#define ECU_LAYER_LM35_LM35_H_

/* ---------------------------------------------- Includes ------------------------------ */
#include "../../MCAL_Layer/ADC/ADC.h"


/* --------------------------------------------- Macros Objects ------------------------- */
#define LM35_CHANNEL_0       ADC0_CHANNEL_SE_SELECT
#define LM35_CHANNEL_1       ADC1_CHANNEL_SE_SELECT
#define LM35_CHANNEL_2       ADC2_CHANNEL_SE_SELECT
#define LM35_CHANNEL_3       ADC3_CHANNEL_SE_SELECT
#define LM35_CHANNEL_4       ADC4_CHANNEL_SE_SELECT
#define LM35_CHANNEL_5       ADC5_CHANNEL_SE_SELECT
#define LM35_CHANNEL_6       ADC6_CHANNEL_SE_SELECT
#define LM35_CHANNEL_7       ADC7_CHANNEL_SE_SELECT

/* ---------------------------------------------- APIs ---------------------------------- */
void LM35_Init(void);
void LM35_Reading(u8 Copy_u8Channel, float *celsius);
#endif /* ECU_LAYER_LM35_LM35_H_ */
