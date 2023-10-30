/*
 * UART_Priv.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_UART_UART_PRIV_H_
#define MCAL_LAYER_UART_UART_PRIV_H_

/*------------------------------------------ Includes -----------------------------------------*/
#include "../std_types.h"

#define UART_BASE       0x29


typedef struct {
	volatile u8 UBRRL_CFG;
	volatile u8 UCSRB_CFG;
	volatile u8 UCSRA_CFG;
	volatile u8 UDR_CFG;
	volatile u8 RESERVED[19];
	volatile u8 UBRRH_UCSRC_CFG;    // To access UBRRH or UCSRC we must write on bit 7 to decide
}UART_MAP;

#define UART_CONTROL          ((volatile UART_MAP*)UART_BASE)


#endif /* MCAL_LAYER_UART_UART_PRIV_H_ */
