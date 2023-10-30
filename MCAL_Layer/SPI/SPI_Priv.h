/*
 * SPI_Priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_SPI_SPI_PRIV_H_
#define MCAL_LAYER_SPI_SPI_PRIV_H_

#include "../std_types.h"

#define SPI_BASE      0x2D



typedef struct {
	volatile u8 SPCR_CFG;
	volatile u8 SPSR_CFG;
	volatile u8 SPDR_CFG;
}SPI_MAP;


#define SPI_MAP     ((volatile SPI_MAP *)SPI_BASE)

#endif /* MCAL_LAYER_SPI_SPI_PRIV_H_ */
