/*
 * SPI.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_SPI_SPI_H_
#define MCAL_LAYER_SPI_SPI_H_

#include "SPI_Priv.h"
#include "SPI_cfg.h"
#include "../std_libraries.h"
#include "../GPIO/GPIO.h"
#include "../../math.h"
#include "../interrupt/GIE_interrupt.h"

#define SPI_VECTOR __vector_12

#define SPI_FOSC_DIV_4        0
#define SPI_FOSC_DIV_16       1
#define SPI_FOSC_DIV_64       2
#define SPI_FOSC_DIV_128      3
#define SPI_FOSC_DIV_2        4
#define SPI_FOSC_DIV_8        5
#define SPI_FOSC_DIV_32       6
#define SPI_FOSC_DIV_64_D     7

// To configure slave or master
#define MASTER_CONFIG         0
#define SLAVE_CONFIG          1

typedef struct {
	u8 interrupt;
	u8 dataorder;
	u8 MasterSlaveSelect;
	u8 polarity;
	u8 phase;
	u8 clk_rate;
	u8 enable_double_speed;
}SPI_T;


/* --------------------------------------------- APIs ----------------------------------  */
Error_Status_t SPI_Init(const SPI_T *spi_obj);
Error_Status_t SPI_Transfere(u8 Copy_u8Ch, u8 *pch);
Error_Status_t SPI_AsynchCallBack(void (*spi_callback)(void), u8 ch);

#endif /* MCAL_LAYER_SPI_SPI_H_ */
