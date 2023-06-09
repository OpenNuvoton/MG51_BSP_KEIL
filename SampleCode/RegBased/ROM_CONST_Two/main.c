/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


/************************************************************************************************************/
/*  File Function: MG51 data location in APROM/DATAFLASH demo code                                          */
/************************************************************************************************************/
#include "MG51.H"

//=========================================================================================================
void main(void)
{
    unsigned char code *Table_Address_Locate;
    unsigned char code *Table_Data_Locate;
    unsigned char readtemp, readtemp1;
   
/* UART0 settting for printf function */
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");
  
    Table_Address_Locate = 0x2C00;
    readtemp = *Table_Address_Locate;
    printf ("\n readtemp = 0x%bx", readtemp);

    Table_Data_Locate = 0x3404;
    readtemp1 = *Table_Data_Locate;
    printf ("\n readtemp1 = 0x%bx", readtemp1);

    while(1);
}