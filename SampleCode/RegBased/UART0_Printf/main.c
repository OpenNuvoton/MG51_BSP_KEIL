/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/************************************************************************************************************/
/*  File Function: MG51 use UART0 as printf function output demo                                            */
/************************************************************************************************************/
#include "MG51.H"


void main (void) 
{

/* Modify HIRC to 24MHz is for UART baud rate deviation not over 1% */
    MODIFY_HIRC(HIRC_24);
    P06_QUASI_MODE;
    UART_Open(24000000,UART0_Timer3,115200);
    ENABLE_UART0_PRINTF;                              // Important! use prinft function must set TI=1;
  
    while(1)
    {
      printf("\n Hello world!");
      Timer0_Delay(16000000,300,1000);
    }
}