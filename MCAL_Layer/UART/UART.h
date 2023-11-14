/*
 * UART.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_UART_UART_H_
#define MCAL_LAYER_UART_UART_H_

/* ---------------------------------------------- Includes ------------------------------ */
#include "UART_Priv.h"
#include "UART_cfg.h"
#include <util/delay.h>
#include "../../math.h"
#include  "../std_libraries.h"

/* --------------------------------------------- Macros Objects ------------------------- */

#define FCPU      16000000UL // Change this to your actual system clock frequency

// Macro to calculate UBRR value that responsible for baud rate generation
#define UBRR_VALUE(baud) ((FCPU / (16 * baud)) - 1)

// Macros for commonly used baud rates
#define UART_BAUDRATE_2400   2400
#define UART_BAUDRATE_4800   4800
#define UART_BAUDRATE_9600   9600
#define UART_BAUDRATE_19200  19200
#define UART_BAUDRATE_38400  38400
#define UART_BAUDRATE_57600  57600
#define UART_BAUDRATE_115200 115200



/* ---------------------------------------------- APIs ---------------------------------- */
Error_Status_t UART_Init(u32 baud_rate);
Error_Status_t UART_SendByte(u8 ch);
Error_Status_t UART_ReceiveByte(u8 *RecByte);
Error_Status_t UART_SendString(u8 *Str);
Error_Status_t UART_ReceiveByteAsynchCallBack(void(*fun_ptr)(u8));

#endif /* MCAL_LAYER_UART_UART_H_ */
