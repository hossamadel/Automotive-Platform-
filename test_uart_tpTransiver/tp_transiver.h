/*
 * tp_transiver.h
 *
 *  Created on: Sep 9, 2017
 *      Author: hadel
 */

#ifndef TP_TRANSIVER_H_
#define TP_TRANSIVER_H_
#include "types.h"
#include "uart.h"

#define CAN_TX uart_tpSendFrame
#define CAN_RX uart_tpRecevFrame

void tp_sender(uint8*buffer , uint8 len);


typedef struct S_Frame{
uint8 DLC;
uint8 data[7];
}gSFrame_t;

typedef struct F_Frame{
uint8 ID;
uint8 DLC;
uint8 data[6];
}gFFrame_t;

typedef struct C_Frame{
uint8 ID;
uint8 data[7];
}gCFrame_t;

typedef struct Flow_Frame{
uint8 ID;
uint8 NumberFrames;
uint8 stMin;
}gFlowFrame_t;






#endif /* TP_TRANSIVER_H_ */
