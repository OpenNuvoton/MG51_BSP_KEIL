/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2023 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "mg51.h"

BIT   pwm0flag=0;
/************************************************************************************************************/
/*   PWM interrupt subroutine                                                                               */
/************************************************************************************************************/
void PWM_ISR (void) interrupt 13
{
    PUSH_SFRS;
  
    clr_PWMCON0_PWMF;               // clear PWM interrupt flag
    pwm0flag = 1;

    POP_SFRS;
}	

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main(void)
{
    MODIFY_HIRC(HIRC_24);
    Enable_UART0_VCOM_printf_24M_115200();
    printf ("\n Test start ...");
/**********************************************************************
  PWM frequency = Fpwm/((PWMPH,PWMPL) + 1) <Fpwm = Fsys/PWM_CLOCK_DIV> 
                = (22.1184MHz/8)/(0x3FF + 1)
                = 2.7KHz
***********************************************************************/
    PWM2_P10_OUTPUT_ENABLE;
    P10_PUSHPULL_MODE;
    PWM_INT_PWM2;
    PWM_FALLING_INT;           /*Setting Interrupt happen when PWM0 falling signal */
  
    PWM_CLOCK_DIV_8;
    PWMPH = 0x03;              /*Setting PWM period  */
    PWMPL = 0xFF;
    PWM2H = 0x01;              /*PWM0 high duty = 1/2 PWM period */
    PWM2L = 0xFF;  

    ENABLE_PWM_INTERRUPT;      /*Enable PWM interrupt  */
    ENABLE_GLOBAL_INTERRUPT;
    set_PWMCON0_LOAD;
    set_PWMCON0_PWMRUN;
    while(1)
    {
      if (pwm0flag)
      {
        printf ("\n PWM interrupt!");
        pwm0flag = 0;
      }
    }
    while(1);
}