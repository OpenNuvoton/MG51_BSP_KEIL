/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MG51 UART1 output for printf function demo
//***********************************************************************************************************
#include "mg51.h"
                          
/*==========================================================================*/
/* Remove ICE to check UART1 function */ 
/*==========================================================================*/
void main (void) 
{
/* Modify HIRC to 24MHz for UART baud rate deviation not over 1%*/
    MODIFY_HIRC(HIRC_24);
    P16_QUASI_MODE;
    P02_INPUT_MODE;  
    UART_Open(24000000,UART1_Timer3,115200);
    ENABLE_UART1_PRINTF;
    DISABLE_UART1_INTERRUPT;

    while(1)
    {
      printf("\n hello world !!!");
      Timer0_Delay(24000000,300,1000);
    }
}