/*
 * std_types.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_STD_TYPES_H_
#define MCAL_LAYER_STD_TYPES_H_

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short      u16;
typedef signed short        s16;
typedef unsigned long       u32;
typedef signed long         s32;


/* To return the program status */
typedef enum {
	NO_ERROR,
	NULL_POINTER,
	OUT_OF_RANGE_VALUE
}Error_Status_t;

#endif /* MCAL_LAYER_STD_TYPES_H_ */
