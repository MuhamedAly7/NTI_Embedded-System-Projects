/*
 * GIE_interrupt_priv.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_PRIV_H_
#define MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_PRIV_H_

/* ----------------------------------------- Includes ------------------------------- */
#include "../std_types.h"


/* ------------------------------------------ Macros object -------------------------- */
#define SREG_BASE_ADD         0x5F

/* ------------------------------------------- Macros functions ---------------------- */

/* ------------------------------------------- User types -----------------------------*/
typedef struct{
	volatile u8 reserved : 7;
	volatile u8 GIE_BIT  : 1;
}SREG_MAP;


#define SREG_CONTROL              ((volatile SREG_MAP *)SREG_BASE_ADD)

#endif /* MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_PRIV_H_ */
