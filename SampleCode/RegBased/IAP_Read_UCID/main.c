/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MG51 read UCID demo
//***********************************************************************************************************
#include "mg51.h"


void main(void)
{
  unsigned char ct;
  
/* Modify HIRC to 24MHz for UART printf function only */
  MODIFY_HIRC(HIRC_24);
  Enable_UART0_VCOM_printf_24M_115200();

  Read_UCID();
  printf ("\n UCID = ");
  for(ct=0;ct<12;ct++)
  {
    printf (" 0x%bx",UCIDBuffer[ct]);
  }

  while(1);


}