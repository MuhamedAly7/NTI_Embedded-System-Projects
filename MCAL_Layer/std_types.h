/*
 * std_types.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_STD_TYPES_H_
#define MCAL_LAYER_STD_TYPES_H_

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef signed char    s16;
typedef unsigned int   u32;
typedef signed int     s32;

/* To return the program status */
typedef enum{
    SUCCESS,
    NULL_PTR
}PROGRAM_STATUS_T;

#endif /* MCAL_LAYER_STD_TYPES_H_ */
