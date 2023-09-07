/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MUG51 I2C Slave demo code
//***********************************************************************************************************

#include "mg51.h"


#define I2C_SLAVE_ADDRESS         0xA0
#define LOOP_SIZE                 10 

#define SDA                       P14
#define SCL                       P13

unsigned char data_received[34], data_num = 0 ; 
unsigned int u16PageOffset_HB,u16ReadAddress;
BIT I2CWOVERFLAG = 0;

//========================================================================================================
void I2C0_ISR(void) interrupt 6
{
  PUSH_SFRS;
  SFRS = 0;
  switch (I2STAT)
    {
        case 0x00:
            set_I2CON_STO;
            while(I2CON&SET_BIT4);
        break;

        case 0x60:
            set_I2CON_AA;
        break;
        
        case 0x68:
            clr_I2CON_AA;
        break;

        case 0x80:
            data_received[data_num] = I2DAT;
            u16ReadAddress = (data_received[0]<<8) + data_received[1];  //This for read process
            data_num++;
            if (data_num == 32)   /* 2 byte address + 30 bytes Data */
            {
                clr_I2CON_AA;
            }
            else
                set_I2CON_AA;
        break;

        case 0x88:
            data_received[data_num] = I2DAT;
            data_num = 0;
            clr_I2CON_AA;
        break;

        case 0xA0:

            if (data_num>20)
            {
               I2CWOVERFLAG = 1 ;
            }
            data_num =0;
            set_I2CON_AA;
        break;

        case 0xA8:
            I2DAT = Read_APROM_BYTE((unsigned int code *)(u16ReadAddress+data_num));
            data_num++;
            set_I2CON_AA;
        break;
        
        case 0xB8: 
            I2DAT = Read_APROM_BYTE((unsigned int code *)(u16ReadAddress+data_num));
            data_num++;
            set_I2CON_AA;
        break;

        case 0xC0:
            data_num = 0;
            set_I2CON_AA;
        break; 

        case 0xC8:
            set_I2CON_AA;
        break;
    }

    I2C0_SI_Check();
POP_SFRS;
}

//========================================================================================================
void Init_I2C_Slave_Interrupt(void)
{
    P13_OPENDRAIN_MODE;          /* External pull high resister in circuit */
    P14_OPENDRAIN_MODE;          /* External pull high resister in circuit */

    P13_ST_ENABLE;               /* Setting schmit tigger mode */
    P14_ST_ENABLE;               /* Setting schmit tigger mode */
  
    SDA = 1;                     /* set SDA and SCL pins high */
    SCL = 1;
  
    I2C_Slave_Open(I2C_SLAVE_ADDRESS) ;
    I2C_Interrupt(ENABLE);
}

//========================================================================================================
void main(void)
{
    MODIFY_HIRC(HIRC_24);
    /* Initial I2C function */
    Init_I2C_Slave_Interrupt();                                 //initial I2C circuit
    ENABLE_GLOBAL_INTERRUPT;

/* =================== */
    while (1)
    {
         if (I2CWOVERFLAG )
        {
           /* After receive storage in dataflash */
           u16PageOffset_HB =  (data_received[0]<<8) + data_received[1];
           Write_DATAFLASH_ARRAY(u16PageOffset_HB, data_received+2, 32);
           I2CWOVERFLAG = 0;
        }
     }

}

