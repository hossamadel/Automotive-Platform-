/*
 * tp_transiver.c
 *
 *  Created on: Sep 9, 2017
 *      Author: hadel
 */

#include "tp_transiver.h"

static void send_single_frame(uint8 * buffer, uint8 len);
static void send_first_frame(uint8 * buffer, uint8 len);
static void send_cons_frame(uint8 * buffer, uint8 numConFrame, uint8 stMin);

static uint8 currentDataposition = 0;

void tp_sender(uint8 *buffer, uint8 len)
{
    gFlowFrame_t flowBuffer;

    /*single frame*/
    if (len < 8)
    {
        send_single_frame(buffer, len);
    }
    /*Con Frame*/
    else if (len > 7)
    {
        send_first_frame(buffer, len);
        while (currentDataposition < len)
        {
            /*ISR Routine using RTOS for 50 ms MAX waiting */
            CAN_RX((uint8*) &flowBuffer);
            if (flowBuffer.ID == 0x30)
            {
                if (0 == flowBuffer.NumberFrames)
                {
                    send_cons_frame(buffer, len - currentDataposition,
                                    flowBuffer.stMin);
                }
                else
                {
                    send_cons_frame(buffer, (flowBuffer.NumberFrames * 7),
                                    flowBuffer.stMin);
                }

            }
            else
            {
                /*Do nothing*/
            }
        }

    }
}

static void send_single_frame(uint8 * buffer, uint8 len)
{
    gSFrame_t s_frame;
    s_frame.DLC = len;
    uint8 index = 0;
    for (index = 0; index < len; index++)
    {
        s_frame.data[index] = buffer[index];
    }
    CAN_TX((uint8*) &s_frame);
}

static void send_first_frame(uint8 * buffer, uint8 len)
{
    /*send first frame*/

    gFFrame_t f_frame;

    f_frame.ID = 0x10;
    f_frame.DLC = len;
    uint8 index = 0;
    for (index = 0; index < 6; index++)
    {
        f_frame.data[index] = buffer[index];
    }
    CAN_TX((uint8*) &f_frame);
    currentDataposition = 6;
}

static void send_cons_frame(uint8 * buffer, uint8 dataSize, uint8 stMin)
{
    /*
     * Start Timer to calculate sMintime
     * using flowBuffer.stMin
     */
    gCFrame_t c_frame;
    c_frame.ID = 0x20;
    uint8 counter = 0;
    uint8 index;
    for (index = currentDataposition;
            index < (currentDataposition + (dataSize)); index++)
    {
        c_frame.data[counter] = buffer[index];
        counter++;
        if (counter == 7 || ((currentDataposition + dataSize) - 1 == index))
        {
            c_frame.ID++;
            CAN_TX((uint8*) &c_frame);
            counter = 0;
            if (c_frame.ID == 0x2f)
            {
                c_frame.ID = 0x20;
            }
            /* wait stMin */
        }
    }
    currentDataposition = index;
}

