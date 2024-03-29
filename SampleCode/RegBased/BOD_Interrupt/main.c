/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MG51 BOD interrupt demo code
//***********************************************************************************************************
#include "mg51.h"

BIT bodflag=0;
void BOD_ISR (void) interrupt 8           // Vector @  0x43
{
    PUSH_SFRS;
 
    clr_BODCON0_BOF;
    bodflag=1;

    POP_SFRS;
}

//----------------------------------------------------------------------------------------------//
void main (void)
{
/* As defaut all multi function define as GPIO */ 
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");

    BOD_Open(Enable, VBOD_2_7, BOD_Reset_Disable);
    BOD_LowPower(LPBOD_Mode_3);
    BOD_Interrupt(Enable);
    ENABLE_GLOBAL_INTERRUPT;
    while(1)
    {
       _delay_();
       if (bodflag)
       {
         while (1)
         {
           printf ("\n BOD interrupt! ");
         }
       }
  }
}



