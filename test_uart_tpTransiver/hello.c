#include <stdio.h>
#include "hw_gpio.h"
#include "hw_types.h"
#include "types.h"
#include "gpio.h"
#include "hw_uart.h"
#include "uart.h"
#include "tp_transiver.h"

int main(void)
{
    char input_char;

    *(volatile uint32 *) (SYS_BASE + RCGCUART) |= (1 << 0);		//Active UART 0
    *(volatile uint32 *) (SYS_BASE + GPIO_CLK) |= (1 << 0);		//Active Port A

    *(volatile uint32 *) (Port_A_APB + AFSEL_offset) |= (1 << 1) | (1 << 0);//Active Alternative
    *(volatile uint32 *) (Port_A_APB + DIGITAL_OFFSET) |= (1 << 1) | (1 << 0);//Active Digital Functionality

    *(volatile uint32 *) (Port_A_APB + PCTL_offset) = (1 << 0) | (1 << 4);//Assign as UART Function

    //RBD=(16,000,000/(16*9600)=104,16666666666
    //UARTFBRD[DIVFRAC] = integer(0.166667*64+0.5)=11

    *(volatile uint32 *) (UART0 + UARTCTL) &= ~(1 << 0);	//Disable UART 0
    *(volatile uint32 *) (UART0 + UARTIBRD) = 0x08;	//Integer Baud Rate
    *(volatile uint32 *) (UART0 + UARTFBRD) = 0x2c;	//Float Baud Rate
    *(volatile uint32 *) (UART0 + UARTLCRH) = 0x70;	//Number of data bits transmitted or received is 8-bits

    *(volatile uint32 *) (UART0 + UARTCC) = (0x0);	//System Clock
    //*(volatile uint32 *) (UART0 + UARTDMACTL) |= 0x3;//µDMA for the transmit and receive FIFO is enabled.
    *(volatile uint32 *) (UART0 + UARTCTL) |= (1 << 0) | (1 << 8) | (1 << 9); //RXE TXE UARTEN is enabled.

    *(volatile uint32 *) (SYS_BASE + GPIO_CLK) |= (1 << 5);		//Active Port F
    *(volatile uint32 *) (Port_F_APB + DIR_offset) = (1 << 1) | (1 << 2)
            | (1 << 3);		//OUTPUT
    *(volatile uint32 *) (Port_F_APB + DIGITAL_OFFSET) = (1 << 1) | (1 << 2)
            | (1 << 3); //Active Digital Functionality
    *(volatile uint32 *) (Port_F_APB + DATA_offset) &= ~((1 << 1) | (1 << 2)
            | (1 << 3)); //LED OFF

    while (1)
    {
        tp_sender("ROUND 7 Test TP", 16);

        //tp_sender("ROUND 7 Test TP layer sender ostorha m3na ya rab", 40);

        printString("end tp session");
        /*
         input_char = readChar();
         printString("UART TEST ");

         switch (input_char)
         {
         case 'r':
         *(volatile uint32 *) (Port_F_APB + DATA_offset) |= (1 << 1); //LED RED ON
         break;
         case 'b':
         *(volatile uint32 *) (Port_F_APB + DATA_offset) |= (1 << 2); //LED BLUE ON
         break;
         case 'g':
         *(volatile uint32 *) (Port_F_APB + DATA_offset) |= (1 << 3); //LED GREEN ON
         break;
         default:
         *(volatile uint32 *) (Port_F_APB + DATA_offset) &= ~((1 << 1)
         | (1 << 2) | (1 << 3)); //LEDs OFF
         break;
         }
         */
    }
}
