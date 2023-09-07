/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MG51 read UID demo
//***********************************************************************************************************
#include "mg51.h"


void main(void)
{
  unsigned char ct;

/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    

    Read_UID();
    printf ("\n UID = ");
    for(ct=0;ct<12;ct++)
    {
      printf (" 0x%bx",UIDBuffer[ct]);
    }
  
    while(1);


}