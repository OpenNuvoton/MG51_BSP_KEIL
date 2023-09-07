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

unsigned char code Random [] = { 
00,02,05,07
}; 


void main (void) 
{
    unsigned char ct;

/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Random address code = ");

    for(ct=0;ct<4;ct++)
    {
        printf ("0x%bx", Random[ct]);
    }

  while(1);
}



