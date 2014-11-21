/*******************************************************************************
 *
 *  hal_leds.h - Hardware Abstraction Layer APIs header for the LED/port module
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

#ifndef HAL_LEDS_H
#define HAL_LEDS_H

#define LED_PORT_DIR       PJDIR
#define LED_PORT_OUT       PJOUT
#define LED_PORT_REN       PJREN
#define LED_PORT_IFG       PJIFG
#define LED_PORT_SEL       PJSEL

#define LED_1              BIT0
#define LED_2              BIT1
#define LED_3              BIT2
#define LED_4              BIT3
#define LED_ALL            (LED_1 + LED_2 + LED_3 + LED_4)

#define HAL_LEDS_INIT(ledsMask)   st( {PJOUT &= ~ledsMask; PJDIR|= ledsMask;})
#define HAL_LEDS_SET(ledsMask)    st( {PJOUT |= ledsMask; PJDIR|= ledsMask;})
#define HAL_LEDS_CLEAR(ledsMask)  st( {PJOUT &= ~ledsMask; PJDIR|= ledsMask;})
#define HAL_LEDS_TOGGLE(ledsMask) st( {PJOUT ^= ledsMask; PJDIR|= ledsMask;})
               

/*-------------------------------------------------------------
 *                  Function Prototypes 
 * ------------------------------------------------------------*/
#define HalLedsInit(ledsMask) HAL_LEDS_INIT(ledsMask)
#define HalLedsSet(ledsMask) HAL_LEDS_SET(ledsMask)
#define HalLedsClear(ledsMask) HAL_LEDS_CLEAR(ledsMask)
#define HalLedsToggle(ledsMask) HAL_LEDS_TOGGLE(ledsMask)
#endif
