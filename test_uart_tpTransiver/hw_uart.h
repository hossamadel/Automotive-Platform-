/*
 * hw_uart.h
 *
 *  Created on: Mar 11, 2016
 *      Author: Mohammad Safie
 */

#ifndef HW_UART_H_
#define HW_UART_H_

#define UART0 0x4000C000
#define UART1 0x4000D000
#define UART2 0x4000E000
#define UART3 0x4000F000
#define UART4 0x40010000
#define UART5 0x40011000
#define UART6 0x40012000
#define UART7 0x40013000

#define UARTDR 				0x000 	//UART Data
#define UARTRSR_UARTECR  	0x004 	//UART Receive Status/Error Clear
#define UARTFR 				0x018 	//UART Flag
#define UARTILPR 			0x020	//UART IrDA Low-Power Register

#define UARTIBRD 			0x024	//UART Integer Baud-Rate Divisor
#define UARTFBRD			0x028  	//UART Fractional Baud-Rate Divisor
//*(where BRDI is the integer part of the BRD and BRDF is the fractional part, separated by a decimal place.)*/
//BRD = BRDI + BRDF = UARTSysClk / (ClkDiv * Baud Rate)*/
//UARTFBRD[DIVFRAC] = integer(BRDF * 64 + 0.5)



#define UARTLCRH			0x02C  	//UART Line Control
#define UARTCTL				0x030  	//UART Control
// ClkDiv is either 16 (if HSE in UARTCTL is clear) or 8 (if HSE is set).

#define UARTIFLS			0x034  	//UART Interrupt FIFO Level Select
#define UARTIM				0x038   //UART Interrupt Mask
#define UARTRIS				0x03C   //UART Raw Interrupt Status
#define UARTMIS				0x040   //UART Masked Interrupt Status
#define UARTICR				0x044  	//UART Interrupt Clear
#define UARTDMACTL			0x048  	//UART DMA Control
#define UART9BITADDR		0x0A4  	//UART 9-Bit Self Address
#define UART9BITAMASK		0x0A8  	//UART 9-Bit Self Address Mask
#define UARTPP				0xFC0  	//UART Peripheral Properties
#define UARTCC				0xFC8  	//UART Clock Configuration

#define UARTPeriphID4		0xFD0  	//UART Peripheral Identification 4
#define UARTPeriphID5		0xFD4  	//UART Peripheral Identification 5
#define UARTPeriphID6		0xFD8  	//UART Peripheral Identification 6
#define UARTPeriphID7		0xFDC  	//UART Peripheral Identification 7
#define UARTPeriphID0		0xFE0  	//UART Peripheral Identification 0
#define UARTPeriphID1		0xFE4  	//UART Peripheral Identification 1
#define UARTPeriphID2		0xFE8  	//UART Peripheral Identification 2
#define UARTPeriphID3		0xFEC  	//UART Peripheral Identification 3
#define UARTPCellID0		0xFF0  	//UART PrimeCell Identification 0
#define UARTPCellID1		0xFF4  	//UART PrimeCell Identification 1
#define UARTPCellID2		0xFF8  	//UART PrimeCell Identification 2
#define UARTPCellID3		0xFFC 	//UART PrimeCell Identification 3

/*	E5  UART0
 E6  UART1
 E33 UART2
 E59 UART3
 E60 UART4
 E61 UART5
 E62 UART6
 E63 UART7
 */
#define	RCGCUART 	0x618	//Universal Asynchronous Receiver/Transmitter RunMode Clock Gating Control

#endif /* HW_UART_H_ */
