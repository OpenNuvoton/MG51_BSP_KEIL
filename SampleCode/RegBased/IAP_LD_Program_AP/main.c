/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MG51 LDROM program APROM demo code
//***********************************************************************************************************
#include "mg51.h"

//***********************************************************************************************************
//  Before using this demo code, please remind below CONFOGs setting, thanks.
//                 CONFIG0.7 --> CBS=0
//                 CONFIG1 = 0xFC, because this demo code size is less than 2K 
/*-----------------------------------------------------------------------------------------------------------*/
void main (void) 
{
    unsigned char i;
  
/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
  
    P12_QUASI_MODE;
    for(i=0;i<128;i++)
      IAPDataBuf[i]=i;

    while (P12);
    Erase_APROM(0x80,128);
    Erase_Verify_APROM(0x80,128);
    Program_APROM(0x80,128);
    Program_Verify_APROM(0x80,128);

    while(1);
}

