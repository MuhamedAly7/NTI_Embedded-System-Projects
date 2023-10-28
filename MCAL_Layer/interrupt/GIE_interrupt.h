/*
 * GIE_interrupt.h
 *
 *  Created on: Oct 28, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_H_
#define MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_H_

/* ----------------------------------------- Includes ------------------------------- */
#include "GIE_interrupt_priv.h"


/* ------------------------------------------ Macros object -------------------------- */

// These macros functions to enable and disable general interrupt
#define GIE_Enable()             (SREG_CONTROL->GIE_BIT = 1)
#define GIE_Disable()            (SREG_CONTROL->GIE_BIT = 0)

/* ------------------------------------------- Macros functions ---------------------- */


#endif /* MCAL_LAYER_INTERRUPT_GIE_INTERRUPT_H_ */
