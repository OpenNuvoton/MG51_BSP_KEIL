/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#define  GPIO_LED                P12
#define  GPIO_LED_QUASI_MODE     P12_QUASI_MODE
#define  GPIO_PRINTF             P06

#define  BOOT_APROM     0
#define  BOOT_LDROM     2

extern BIT BIT_TMP;

unsigned char Read_APROM_BYTE(unsigned int code *u16_addr);
void Software_Reset(unsigned char u8Bootarea);
void PowerDown_Mode(unsigned char PDStatus);
void Idle_Mode(unsigned char IdleStatus);
