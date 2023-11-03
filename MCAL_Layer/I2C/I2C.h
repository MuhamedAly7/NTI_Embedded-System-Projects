/*
 * I2C.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aly
 */

#ifndef MCAL_LAYER_I2C_I2C_H_
#define MCAL_LAYER_I2C_I2C_H_

#include "I2C_cfg.h"
#include "I2C_Priv.h"
#include "../std_libraries.h"


/* -------------------------------------- Macros objects -------------------------- */

// To select frequency
#define I2C_FREQ_100HZ         0
#define I2C_FERQ_400HZ         1

#define I2C_MASTER_MODE        0
#define I2C_SLAVE_MODE         1

/* -------------------------------------- user Data types ------------------------- */
typedef struct {
	u8 master_or_slave;
	u8 frequency; /* 100 Hz  or 400 Hz */
	u8 prescaler;
}i2c_t;

/* -------------------------------------- APIs ------------------------------------ */
Error_Status_t I2C_Init(const i2c_t *i2c_obj);
Error_Status_t I2C_SendByte(u8 Copy_u8data);
Error_Status_t I2C_SendStart(void);
Error_Status_t I2C_SendStop(void);
Error_Status_t I2C_ReceiveByte_ACK(u8 *ptr);
Error_Status_t I2C_ReceiveByte_NoACK(u8 *ptr);
Error_Status_t I2C_GetStatus(u8 *status);
#endif /* MCAL_LAYER_I2C_I2C_H_ */
