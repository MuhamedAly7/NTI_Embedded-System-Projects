/*
 * EEPROM.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_EEROM_EEPROM_H_
#define ECU_LAYER_EEROM_EEPROM_H_

/* ---------------------------------------- Includes ---------------------- */
#include "EEPROM_cfg.h"
#include "../../MCAL_Layer/I2C/I2C.h"


#define EEPROM_DEVICE_ADDRESS_WRITE  0b10100000
#define EEPROM_DEVICE_ADDRESS_READ   0b10100001


/* ---------------------------------------- APIs -------------------------- */
void EEPROM_Init(u8 req_speed);
void EEPROM_WriteByte(u8 address_in_eeprom, u8 data);
u8 EEPROM_ReadByte(u8 address_in_eeprom);
void EEPROM_EraseByte(u8 address_in_eeprom);

#endif /* ECU_LAYER_EEROM_EEPROM_H_ */
