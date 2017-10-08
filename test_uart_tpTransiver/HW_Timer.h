/*
 * HW_Timer.h
 *
 *  Created on: Mar 15, 2016
 *      Author: Mohammad Safie
 */

#ifndef HW_TIMER_H_
#define HW_TIMER_H_

#define 16_32_Timer_Clock 			0x604
#define 32_Timer_Clock 				0x75C
#define Watchdog_Gating_Control		0x600 RCGCWD
#define 16_32_bit_Timer0 0x40030000
#define 16_32_bit_Timer1 0x40031000
#define 16_32_bit_Timer2 0x40032000
#define 16_32_bit_Timer3 0x40033000
#define 16_32_bit_Timer4 0x40034000
#define 16_32_bit_Timer5 0x40035000
#define 32_64_bit_Timer0 0x40036000
#define 32_64_bit_Timer1 0x40037000
#define 32_64_bit_Timer2 0x4004C000
#define 32_64_bit_Timer3 0x4004D000
#define 32_64_bit_Timer4 0x4004E000
#define 32_64_bit_Timer5 0x4004F000


#define  GPTMCFG 		0x000					//GPTM Configuration	0x0->Largest,	0x1->RTC,	0x4->Smallest
#define  GPTMTAMR 		0x004					//GPTM Timer A Mode
#define  GPTMTBMR 		0x008					//GPTM Timer B Mode
#define  GPTMCTL 		0x00C					//GPTM Control
#define  GPTMSYNC 		0x010					//GPTM Synchronize
#define  GPTMIMR  		0x018					//GPTM Interrupt Mask
#define  GPTMRIS  		0x01C					//GPTM Raw Interrupt Status
#define  GPTMMIS  		0x020					//GPTM Masked Interrupt Status
#define  GPTMICR  		0x024					//GPTM Interrupt Clear
#define  GPTMTAILR 		0x028					//GPTM Timer A Interval Load
#define  GPTMTBILR 		0x02C					//GPTM Timer B Interval Load
#define  GPTMTAMATCHR 	0x030					//GPTM Timer A Match
#define  GPTMTBMATCHR  	0x034					//GPTM Timer B Match
#define  GPTMTAPR		0x038					//GPTM Timer A Prescale
#define  GPTMTBPR		0x03C					//GPTM Timer B Prescale
#define  GPTMTAPMR 		0x040					//GPTM TimerA Prescale Match
#define  GPTMTBPMR 		0x044					//GPTM TimerB Prescale Match
#define  GPTMTAR 		0x048					//GPTM Timer A
#define  GPTMTBR 		0x04C					//GPTM Timer B
#define  GPTMTAV 		0x050					//GPTM Timer A Value
#define  GPTMTBV 		0x054					//GPTM Timer B Value
#define  GPTMRTCPD  	0x058					//GPTM RTC Predivide
#define  GPTMTAPS  		0x05C					//GPTM Timer A Prescale Snapshot
#define  GPTMTBPS  		0x060					//GPTM Timer B Prescale Snapshot
#define  GPTMTAPV  		0x064					//GPTM Timer A Prescale Value
#define  GPTMTBPV  		0x068					//GPTM Timer B Prescale Value
#define  GPTMPP  		0xFC0					//GPTM Peripheral Properties


#endif /* HW_TIMER_H_ */
