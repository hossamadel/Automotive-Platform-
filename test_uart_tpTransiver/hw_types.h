/*
 * hw_types.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Mohammad Safie
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_
#include "types.h"

static inline void WR_REG(uint32 reg, uint32 val) {
	*(volatile uint32 *) (reg) = val;
}

static inline void WR_PIN(uint32 reg, uint32 pin, uint32 val) {
	if (1 == val)
	{
		*(volatile uint32 *) (reg) |= 1 << pin;
	}
	else if (0 == val)
	{
		*(volatile uint32 *) (reg) &= ~(1 << pin);
	} else
	{
		/*DO NOTHING */
	}
}

static inline uint32 RD_PIN(uint32 reg, uint32 pin) {
	return (*(volatile uint32 *) reg & (1 << pin)) >> pin;
}

#endif /* HW_TYPES_H_ */
