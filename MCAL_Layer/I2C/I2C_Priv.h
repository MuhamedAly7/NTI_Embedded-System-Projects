/*
 * I2C_Priv.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_I2C_I2C_PRIV_H_
#define MCAL_LAYER_I2C_I2C_PRIV_H_

#include "../std_types.h"

#define I2C_BASE            0x20


typedef struct {
	volatile u8 TWBR_REG;
	volatile u8 TWSR_REG;
	volatile u8 TWAR_REG;
	volatile u8 TWDR_REG;
	volatile u8 RESERVED[50];
	volatile u8 TWCR_REG;
}I2C_MAP;


#define I2C_CONTROL           ((volatile I2C_MAP *)I2C_BASE)


#endif /* MCAL_LAYER_I2C_I2C_PRIV_H_ */
