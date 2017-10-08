/*
 * uart.h
 *
 *  Created on: Mar 12, 2016
 *      Author: Mohammad Safie
 */

#ifndef UART_H_
#define UART_H_
#include "types.h"
char readChar(void);
void printChar(unsigned char buffer);
void printString(char *buffer);
void uart_tpSendFrame(uint8 *buffer);
void uart_tpRecevFrame(uint8 * buffer);
#endif /* UART_H_ */
