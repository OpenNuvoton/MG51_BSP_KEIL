/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


/************************************************************************************************************/
/*  File Function: MG51 INT0 pin external interrupt demo                                                    */
/************************************************************************************************************/
#include "mg51.h"

BIT  int0flag=0;

/* External pin interrupt INT0 subroutine */
void INT0_ISR(void) interrupt 0          // Vector @  0x03
{
    PUSH_SFRS;
    clr_TCON_IE0;          //clr int flag wait next falling edge
    int0flag = 1;
    POP_SFRS;
}


void main (void) 
{
/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");


    P30_QUASI_MODE;                      //setting INT0 pin P3.0 as Quasi mode with internal pull high  
    P30 = 1;
    INT0_FALLING_EDGE_TRIG;              //setting trig condition level or edge
    ENABLE_INT0_INTERRUPT;                         //INT0_Enable;
    ENABLE_GLOBAL_INTERRUPT;            //Global interrupt enable
    while(1)
    {
      if (int0flag)
      {
        printf ("\n INT0 Interrupt !");
      }
    }
}



