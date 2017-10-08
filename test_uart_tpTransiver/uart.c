/*
 * uart.c
 *
 *  Created on: Sep 9, 2017
 *      Author: hadel
 */
#include "types.h"
#include "hw_uart.h"
#include "uart.h"
//#define DEBUG
char readChar(void)
{
    char c;
    while ((*(volatile uint32 *) (UART0 + UARTFR) & (1 << 4)) != 0)
        ;

    c = *(volatile uint32 *) (UART0 + UARTDR);

    return c;
}

void printChar(unsigned char buffer)
{
    while ((*(volatile uint32 *) (UART0 + UARTFR) & (1 << 5)) != 0)
        ;
    *(volatile uint32 *) (UART0 + UARTDR) = buffer;
}

void printString(char *buffer)
{
    while (*buffer != '\0')
    {
        while ((*(volatile uint32 *) (UART0 + UARTFR) & (1 << 5)) != 0)
            ;
        *(volatile uint32 *) (UART0 + UARTDR) = *buffer;
        buffer++;
    }
}

void uart_tpSendFrame(uint8 *buffer)
{
#ifdef DEBUG
    uint8 testData[8], index = 0;
    for (index = 0; index < 8; index++)
    {

        testData[index] = buffer[index];
    }
#endif
    uint8 count = 8;
    while (count--)
    {
        while ((*(volatile uint32 *) (UART0 + UARTFR) & (1 << 5)) != 0)
            ;
        *(volatile uint32 *) (UART0 + UARTDR) = *buffer;
        buffer++;
    }
}

void uart_tpRecevFrame(uint8 * buffer)
{
    uint8 count = 8;
    while (count--)
    {
        while ((*(volatile uint32 *) (UART0 + UARTFR) & (1 << 4)) != 0)
            ;

        *buffer = *(volatile uint32 *) (UART0 + UARTDR);
        buffer++;
    }

#ifdef DEBUG
    uint8 testData[8],index = 0;
    for (index = 0; index < 8; index++)
    {

        testData[index] = buffer[index];
    }
#endif
}


