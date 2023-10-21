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


/* ------------------------------------Macro declarations --------------------- */
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 4

/* ------------------------------------Macro Functions ------------------------ */

/* ------------------------------------Data types ----------------------------- */
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
	GPIO_CFG_T segment_pins[4];
    segment_type_t segment_type;
}seven_segment_t;

/* ------------------------------------Function declarations ------------------- */
PROGRAM_STATUS_T seven_segment_initailize(const seven_segment_t *_segment);
PROGRAM_STATUS_T seven_segment_write_number(const seven_segment_t *_segment, u8 number);

#endif /* ECU_LAYER_SEVENSEGMENT_SEVEN_SEGMENT_H_ */
