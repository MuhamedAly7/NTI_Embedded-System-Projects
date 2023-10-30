/*
 * UART.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_UART_UART_H_
#define MCAL_LAYER_UART_UART_H_

#include "UART_Priv.h"
#include "UART_cfg.h"
#include <util/delay.h>
#include "../../math.h"
#include  "../std_libraries.h"

#define F_CPU   8000000UL

Error_Status_t UART_Init(void);
Error_Status_t UART_SendByte(u8 ch);
Error_Status_t UART_ReceiveByte(u8 *RecByte);
Error_Status_t UART_SendString(u8 *Str);
Error_Status_t UART_ReceiveByteAsynchCallBack(void(*fun_ptr)(u8));

#endif /* MCAL_LAYER_UART_UART_H_ */
