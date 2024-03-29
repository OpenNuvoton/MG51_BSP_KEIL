/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

void Write_DATAFLASH_BYTE(unsigned int u16EPAddr,unsigned char u8EPData);
void Write_DATAFLASH_ARRAY(unsigned int u16_addr,unsigned char *pDat,unsigned int num);
void Read_DATAFLASH_ARRAY(unsigned int u16_addr,unsigned char *pDat,unsigned int num);
unsigned char WriteDataToOnePage(unsigned int u16_addr,const unsigned char *pDat,unsigned char num);