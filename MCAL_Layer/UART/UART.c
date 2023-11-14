/*
 * UART.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Mohamed Aly
 */

#include "UART.h"


Error_Status_t UART_Init(u32 baud_rate)
{
	Error_Status_t ret_status = NO_ERROR;

	//u8 baud = 51;
	//u8 baud = 107;
	u32 UBRR_value = UBRR_VALUE(baud_rate);

	// set baud rate
	UART_CONTROL->UBRRH_UCSRC_CFG = (u8)(UBRR_value >> 8);
	UART_CONTROL->UBRRL_CFG = (u8)(UBRR_value);

	// Enable transmitter and receiver
	u8 rx_tx = (0x01<<4) | (0x01<<3);
	UART_CONTROL->UCSRB_CFG = rx_tx;

	// set frame format
	u8 frame_form = (0x01<<7) | (0x01<<3) | (0x03<<1);
	UART_CONTROL->UBRRH_UCSRC_CFG = frame_form;

	return ret_status;
}


Error_Status_t UART_SendByte(u8 ch)
{
	Error_Status_t ret_status = NO_ERROR;
	while(!(UART_CONTROL->UCSRA_CFG & (0x01 << 5)));
	UART_CONTROL->UDR_CFG = ch;
	return ret_status;
}


Error_Status_t UART_ReceiveByte(u8 *RecByte)
{
	Error_Status_t ret_status = NO_ERROR;
	while(!(UART_CONTROL->UCSRA_CFG & (0x01 << 7)));
	*RecByte = UART_CONTROL->UDR_CFG;
	return ret_status;
}


Error_Status_t UART_SendString(u8 *Str)
{
	Error_Status_t ret_status = NO_ERROR;
	if(NULL == Str)
	{
		ret_status = NULL_POINTER;
	}
	else
	{
		while(*Str)
		{
			ret_status = UART_SendByte(*Str);
			Str++;
		}
	}
	return ret_status;
}
Error_Status_t UART_ReceiveByteAsynchCallBack(void(*fun_ptr)(u8));
