/*
 * FingerPrint.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Mohamed Aly
 */

#ifndef ECU_LAYER_FINGERPRINT_FINGERPRINT_H_
#define ECU_LAYER_FINGERPRINT_FINGERPRINT_H_

/* -------------------------------------------- Include -------------------------------- */
#include "FingerPrint_cfg.h"
#include "FingerPrint_Priv.h"
#include "../../MCAL_Layer/UART/UART.h"

/* ------------------------------------------- Macros Objects -------------------------- */
#define SUCCESS  1
#define ERROR    0

/* ------------------------------------------- Macros Functions ------------------------ */


/* --------------------------------------------- APIs ----------------------------------- */
u8 FingerPS_handShake(void);
u8 FingerPS_genImg(void);
u8 FingerPS_convertImg2CharFile(u8 BufferId);
u8 FingerPS_genTemplate(void);
u8 FingerPS_strTemplate(u8 ID);
u8 FingerPS_searchFinger(void); /* 1:n must be done at  each enrollment to ensure that the template doesn't allocated */
u8 FingerPS_emptyLibrary(void);
u8 FingerPS_deleteFinger(void);
u8 FingerPS_LoadCharFile(void);
static u16  FingerPS_calcCheckSum(u8 *frame);
u8 FingerPS_match(void); /* Used for attendance mode */

#endif /* ECU_LAYER_FINGERPRINT_FINGERPRINT_H_ */
