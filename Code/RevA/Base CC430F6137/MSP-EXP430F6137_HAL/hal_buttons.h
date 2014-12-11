/*******************************************************************************
 *
 *  hal_buttons.h - Hardware Abstraction Layer API header for the buttons module
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
#ifndef HAL_BUTTONS_H
#define HAL_BUTTONS_H

#define BUTTON_PORT_DIR       P2DIR
#define BUTTON_PORT_OUT       P2OUT
#define BUTTON_PORT_IN        P2IN
#define BUTTON_PORT_REN       P2REN
#define BUTTON_PORT_IE        P2IE
#define BUTTON_PORT_IES       P2IES
#define BUTTON_PORT_IFG       P2IFG
#define BUTTON_PORT_SEL       P2SEL

#define BUTTON_R              BIT0          // Silkscreen label: SW_R 
#define BUTTON_U              BIT1          // Silkscreen label: SW_U
#define BUTTON_D              BIT2          // Silkscreen label: SW_D
#define BUTTON_L              BIT3          // Silkscreen label: SW_L

#define BUTTON_ALL            (BIT0+BIT1+BIT2+BIT3)

// Redefining buttons for easy of use
#define BUTTON_1              BIT0
#define BUTTON_2              BIT1
#define BUTTON_3              BIT2
#define BUTTON_4              BIT3

/*-------------------------------------------------------------
 *                  Function Prototypes 
 * ------------------------------------------------------------*/
extern void HalButtonsInit(unsigned char buttonsMask);
extern unsigned char HalButtonsPressed(void);
extern unsigned char HalButtonsPressedIFG(void);
extern void HalButtonsInterruptEnable(unsigned char buttonIntEnableMask);
extern void HalButtonsInterruptDisable(unsigned char buttonIntEnableMask);
extern void HalButtonsShutDown();
  
#endif
