/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


/************************************************************************************************************/
/*  File Function: MG51 UART1 with interrupt demo                                                           */
/************************************************************************************************************/
#include "mg51.h"

unsigned char  UART_BUFFER;

/****************************************************************************************************************
 * UART1 Interrupt vector 
 ***************************************************************************************************************/
void SerialPort1_ISR(void) interrupt 15
{
    PUSH_SFRS;
  
    if (RI_1)
    {
        uart1_receive_data = SBUF_1;
        uart1_receive_flag = 1;
        clr_SCON_1_RI_1;                             /* clear reception flag for next reception */
    }

    if (TI_1 == 1)
    {
        if (!PRINTFG)
        {
            clr_SCON_1_TI_1;                             /* if emission occur */
        }
    }

    POP_SFRS;
}

/****************************************************************************************************************
 * FUNCTION_PURPOSE: Main function 
  
 !!! MG51FB9AE / MG51XB9AE /MG51XB9BE UART1 pin also occupied by debug pin, 
 please remove Nu-link or not in debug mode to test UART1 function.

 External UART1 connect also disturb debug download
 ***************************************************************************************************************/
void main (void)
{
    MODIFY_HIRC(HIRC_24);
    P12_PUSHPULL_MODE;    // For I/O toggle display
/* Modify HIRC to 24MHz for UART baud rate deviation not over 1%*/
    P16_QUASI_MODE;
    P02_INPUT_MODE;
    UART_Open(24000000,UART1_Timer3,115200);
    ENABLE_UART1_INTERRUPT;
    ENABLE_GLOBAL_INTERRUPT;                //ENABLE_GLOBAL_INTERRUPT

    while(1)
    {
      if (uart1_receive_flag)
      {
          P12 ^= 1;      //Receive each byte P12 toggle, never work under debug mode
          UART_Send_Data(UART1,uart1_receive_data);
          uart1_receive_flag = 0;
      }
    }
}
  
