/*
 * math.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed Aly
 */

#ifndef MATH_H_
#define MATH_H_

#define BIT_MASK    0x01

#define SET_BIT(REG,BIT_POS)        (REG |= (BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)      (REG &= ~(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS)     (REG ^= (BIT_MASK << BIT_POS))
#define READ_BIT(REG,BIT_POS)       ((REG >> BIT_POS) & BIT_MASK)

#endif /* MATH_H_ */
