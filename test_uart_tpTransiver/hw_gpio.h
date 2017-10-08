/*
 * hw_gpio.h
 *
 *  Created on: Mar 10, 2016
 *      Author: Mohammad Safie
 */

#ifndef HW_GPIO_H_
#define HW_GPIO_H_

#define SYS_BASE     0x400FE000
#define GPIO_CLK     0x608

#define Port_A_APB 0x40004000
#define Port_A_AHB 0x40058000

#define Port_B_APB 0x40005000
#define Port_B_AHB 0x40059000

#define Port_C_APB 0x40006000
#define Port_C_AHB 0x4005A000

#define Port_D_APB 0x40007000
#define Port_D_AHB 0x4005B000

#define Port_E_APB 0x40024000
#define Port_E_AHB 0x4005C000

#define Port_F_APB 0x40025000
#define Port_F_AHB 0x4005D000

#define DATA_offset 	0x3FC
#define DIR_offset 		0x400	//input by default
#define IS_offset		0x404	//interrupt sense(edge or level)
#define IBE_offset		0x408 	//interrupt both edge (if -1- both edge active, if -0- controlled by IEV)
#define IEV_offset		0x40C 	//interrupt event register (if -1- rising edge, if -0- falling edge)
#define IM_offset		0x410	// interrupt masking register (-1- active, -0- deactive)
#define RIS_offset		0x414	// raw interrupt status register
#define MIS_offset		0x418	// Masked interrupt status
#define ICR_offset  	0x41C	// interrupt clear register

#define AFSEL_offset	0x420 	// alternative function register
#define PCTL_offset		0x52C 	// alternative function choice
#define GPIOCR_offset	0x524	//Commit Reg
#define DIGITAL_OFFSET  0x51c
#define GPIOLOCK_offset	0x520	// Lock Reg

#define R2R_offset		0x500	// register is the 2-mA
#define R4R_offset		0x504	// register is the 4-mA
#define R8R_offset		0x508	// register is the 8-mA
#define AMSEL_offset 	0x528	//analog mode select 0-digital, 1 analoge
#define DEN_offset		0x51C	//digital enable 1-enable, 0-disable
#define PUR_offset		0x510	//pull up
#define PDR_offset		0x514	//pull down


#define ODR_offset		0x50c	// open drain register


#endif /* HW_GPIO_H_ */
