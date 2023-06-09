/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "MG51.H"

bit BIT_TMP;
/**
 * @brief       Read Dataflash
 * @param       Dataflash start address
 * @return      Dataflash Value
 * @details     None
 */
unsigned char Read_APROM_BYTE(unsigned int code *u16_addr)
{
    unsigned char rdata;
    rdata = *u16_addr >> 8;
    return rdata;
}