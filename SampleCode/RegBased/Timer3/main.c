/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


/************************************************************************************************************/
/*  File Function: MG51 Timer 3 with interrupt demo                                                         */
/************************************************************************************************************/
#include "MG51.H"


BIT  timer3IntFlag=0;

/************************************************************************************************************
*    TIMER 3 interrupt subroutine
************************************************************************************************************/
void Timer3_ISR (void) interrupt 16 
{
    _push_(SFRS);

    clr_T3CON_TF3;
    timer3IntFlag=1;
    P12 ^= 1;

    _pop_(SFRS);
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


    Timer3_AutoReload_Interrupt_Initial(24,300000);     // FSYS 24M,  Timer divder 128, delay 300ms)
    ENABLE_GLOBAL_INTERRUPT;                                    //enable global interrupts
    while(1)
    {
      if (timer3IntFlag)
      { 
          printf ("\n Timer3 Interrupt !");
        timer3IntFlag=0;
      }
    }
}

