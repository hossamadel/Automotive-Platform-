/*
 * gpio.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Mohammad Safie
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "types.h"

typedef enum {
	CURRENT_2mA, CURRENT_4mA, CURRENT_8mA,
} currentObj_t;

typedef enum {
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
} pinObj_t;

typedef enum {
	input, output,
} DirObj_t;

typedef enum {
	digital, analoge,
} DataTypeObj_t;

typedef enum {
	pullDown, pullUp,
} PullObj_t;


typedef enum {
	GPIO, Alternative,
} digitalType_t;

typedef struct gpio {
	uint32 port;
	pinObj_t pin;
	DirObj_t dir;
	DataTypeObj_t AorDtype;
	digitalType_t DType;
	currentObj_t current;
	uint32 openDrain;
	PullObj_t PullRes;
} gpioObj_t;


uint32 init_gpio(gpioObj_t *obj);
/*static inline void WR_REG(uint32 reg, uint32 val);
static inline void WR_PIN(uint32 reg, uint32 pin, uint32 val);
static inline uint32 RD_PIN(uint32 reg, uint32 pin);*/



























#endif /* GPIO_H_ */
