/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/************************************************************************************************************/
/*  File Function: MG51 Wakeup timer demo code with interrupt                                               */
/************************************************************************************************************/
#include "mg51.h"

BIT wktflag=0;

void WakeUp_Timer_ISR (void)   interrupt 17     //ISR for self wake-up timer
{
    PUSH_SFRS;
  
    clr_WKCON_WKTF;
    wktflag = 1;
    P12 ^= 1;
    POP_SFRS;
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
  /* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");

    P12_QUASI_MODE;
    
    WKT_AutoReload_Interrupt_Initial_S(1);
    WKT_Interrupt(Enable);
    ENABLE_GLOBAL_INTERRUPT;
    wktflag = 0;
    while(1)
    {
      if(wktflag)
      {
        SFRS=0;
        printf ("\n WKT interrupt!");
        wktflag = 0;
      }
    }
    
}


