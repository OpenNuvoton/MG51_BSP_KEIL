/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


/************************************************************************************************************/
/*  File Function: MG51 INT1 extneranl interrupt demo                                                       */
/************************************************************************************************************/
#include "mg51.h"

BIT int1flag=0;
/* External pin interrupt INT0 subroutine */
void INT0_ISR(void) interrupt 2          // Vector @  0x03
{
    PUSH_SFRS;
  
    clr_TCON_IE1;          //clr int flag wait next falling edge
    int1flag =1;

    POP_SFRS;
}

void main (void) 
{
  /* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");

    P17_QUASI_MODE;                      //setting INT0 pin P1.7 as Quasi mode with internal pull high  
    P17 = 1;
    INT1_LOW_LEVEL_TRIG;                //setting trig condition level or edge
    ENABLE_INT1_INTERRUPT;                         //INT0_Enable;
    ENABLE_GLOBAL_INTERRUPT;            //Global interrupt enable
    while(1)
    {
      if (int1flag)
      {
        printf ("\n INT1 Interrupt! ");
      }
    }
}



