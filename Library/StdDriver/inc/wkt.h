/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
void WKT_AutoReload_Interrupt_Initial_S(unsigned int u16WKTRLData);
void WKT_AutoReload_Interrupt_Initial_MS(unsigned int u16WKTRLData);
void WKT_Open(unsigned int u16WKTDIV, unsigned char u8WKTRLData);
void WKT_Interrupt(unsigned char u8WKTINT);
void WKT_Close();
