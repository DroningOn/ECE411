/*******************************************************************************
 *
 *  hal_buttons.c - Hardware Abstraction Layer APIs for the buttons/port module
 *
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/

#include "msp430.h"
#include "hal_buttons.h"

unsigned char  buttonDebounce = 1;
volatile unsigned char  buttonsPressed = 0;
/**********************************************************************//**
 * @brief  Initializes the GPIO ports to act as buttons.
 * 
 * @param  buttonsMask The mask that specifies the button pins.
 * 
 * @return none
 *************************************************************************/   
void HalButtonsInit(unsigned char buttonsMask)
{  
  BUTTON_PORT_OUT |= buttonsMask;
  BUTTON_PORT_DIR &= ~buttonsMask;
  BUTTON_PORT_REN |= buttonsMask; 
  BUTTON_PORT_SEL &= ~buttonsMask;       
}

/**********************************************************************//**
 * @brief  Returns LOW for the buttons pressed.
 * 
 * @param  none
 * 
 * @return The buttons that have been pressed, identified by a bit = 0. 
 *************************************************************************/
unsigned char HalButtonsPressed(void)
{
  unsigned char value;
  value = BUTTON_PORT_IN;
  return (0xFF - value);                    //Low==ButtonPressed
}

/**********************************************************************//**
 * @brief  Returns HIGH for the buttons pressed registered by the interrupt.
 * 
 * @param  none
 * 
 * @return The buttons that have been pressed, identified by a bit = 0. 
 *************************************************************************/
extern unsigned char HalButtonsPressedIFG(void)
{
  volatile unsigned char temp = buttonsPressed;
  buttonsPressed = 0;
  return temp;
}

/**********************************************************************//**
 * @brief  Enables button interrupt(s) with low to high transitions.
 * 
 * @param  buttonIntEnableMask The button pin(s) for which the interrupt(s) 
 *                             should be enabled.
 * 
 * @return none
 *************************************************************************/
void HalButtonsInterruptEnable(unsigned char buttonIntEnableMask)
{
  BUTTON_PORT_IES &= ~buttonIntEnableMask;
  BUTTON_PORT_IFG &= ~buttonIntEnableMask;
  BUTTON_PORT_IE |= buttonIntEnableMask;
}

/**********************************************************************//**
 * @brief  Disables button interrupts 
 * 
 * @param  buttonIntEnableMask The button pin(s) for which the interrupt(s)
 *                             should be disabled. 
 * 
 * @return none
 *************************************************************************/
void HalButtonsInterruptDisable(unsigned char buttonIntEnableMask)
{
  BUTTON_PORT_IE &= ~buttonIntEnableMask;
}

/**********************************************************************//**
 * @brief  Clears the button GPIO settings, disables the buttons. 
 * 
 * @param  none
 *************************************************************************/
void HalButtonsShutDown()
{
  //All output, outputting 0s
  BUTTON_PORT_OUT &= ~(BUTTON_ALL);
  BUTTON_PORT_DIR |= BUTTON_ALL;             
}
/***************************************************************************//**
 * @brief  Sets up the WDT as a button debouncer, only activated once a
 *         button interrupt has occurred. 
 * @param  none  
 * @return none
 ******************************************************************************/
void HalButtonsStartWDT()
{
  // WDT as 250ms interval counter
  SFRIFG1 &= ~WDTIFG;
  WDTCTL = WDTPW + WDTSSEL_1 + WDTTMSEL + WDTCNTCL + WDTIS_5;
  SFRIE1 |= WDTIE;
}

/***************************************************************************//**
 * @brief  Handles Port 1 interrupts - performs button debouncing and registers
 *         button presses.
 * @param  none   
 * @return none
 ******************************************************************************/
#pragma vector=PORT1_VECTOR
__interrupt void Port1_ISR(void)
{ 
  if (buttonDebounce == 1)   
  {
    buttonsPressed = P1IFG & BUTTON_ALL;
    buttonDebounce = 2;   
    HalButtonsStartWDT();     
    __bic_SR_register_on_exit(LPM3_bits);    
  }
  else if (0 == buttonDebounce) 
  {
    buttonsPressed = P1IFG & BUTTON_ALL;
    __bic_SR_register_on_exit(LPM4_bits);     
  }   
  P1IFG = 0;
}

/***************************************************************************//**
 * @brief  Handles Watchdog Timer interrupts. 
 *
 *         Global variables are used to determine the module triggering the
 *         interrupt, and therefore, how to handle it.    
 * @param  none  
 * @return none
 ******************************************************************************/
#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR(void)
{
  if (buttonDebounce == 2)
  {
    buttonDebounce = 1;
	  SFRIFG1 &= ~WDTIFG;
	  SFRIE1 &= ~WDTIE;
	  WDTCTL = WDTPW + WDTHOLD;  
  }   
}

