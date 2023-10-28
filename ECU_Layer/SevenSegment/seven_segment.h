/*
 * seven_segment.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_H_
#define ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_H_

/*-------------------------------------Includes---------------------------------*/
#include "../../MCAL_Layer/GPIO/GPIO.h"
#include "seven_segment_cfg.h"


/* ------------------------------------Macro declarations --------------------- */


/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Data types ----------------------------- */
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;


/* ------------------------------------Function declarations ------------------- */
void SevenSeG_voidinit(void);
void SevenSeG_voidWriteNum(u8 number);

#endif /* ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_H_ */
