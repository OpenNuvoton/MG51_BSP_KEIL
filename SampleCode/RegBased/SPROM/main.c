/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MG51 locate data in APROM simple demo 
//***********************************************************************************************************
#include "mg51.h"
#include "sprom.h"


void main (void) 
{
/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");
    
    set_IAPUEN_SPMEN;             //Enable SPROM memory mapping only for check SPROM in memory window
    while(1)
    {
      SPROM_CODE();
      printf ("\n SPTEMP= 0x%BX", SPTEMP);
      Timer0_Delay(24000000,300,1000);
    }
}
