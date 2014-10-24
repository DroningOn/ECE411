/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************
 * 
 *                       MSP430 CODE EXAMPLE DISCLAIMER
 *
 * MSP430 code examples are self-contained low-level programs that typically
 * demonstrate a single peripheral function or device feature in a highly
 * concise manner. For this the code may rely on the device's power-on default
 * register values and settings such as the clock configuration and care must
 * be taken when combining code from several examples to avoid potential side
 * effects. Also see www.ti.com/grace for a GUI- and www.ti.com/msp430ware
 * for an API functional library-approach to peripheral configuration.
 *
 * --/COPYRIGHT--*/
//******************************************************************************
//  CC430F513x Demo - Timer_A3, Toggle P2.1/TA1.0, Up Mode, 32kHz ACLK
//
//  Description: Toggle P2.0 using hardware TA1.0 output. Timer1_A is configured
//  for up mode with CCR0 defining period. 
//  Thus the output frequency on P2.0 will be the TACLK/20. No CPU or software
//  resources required. Normal operating mode is LPM3.
//  As coded with TACLK = ACLK, P2.0 output frequency = 32768/20 = 1.6384kHz.
//  ACLK = TACLK = 32kHz, MCLK = default DCO ~1.045MHz
//
//                CC430F5137
//            -------------------
//        /|\|                   |
//         | |                   |
//         --|RST                |
//           |                   |
//           |         P2.0/TA1.0|--> ACLK/20
//
//   M Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP0 = PM_TA1CCR0A;                     // Map TA1CCR0 output to P2.0 
  PMAPPWD = 0;                              // Lock port mapping registers 
  
  P2DIR |= BIT0;                            // P2.0 output
  P2SEL |= BIT0;                            // P2.0 option select
  TA1CCTL0 = OUTMOD_4;                      // CCR0 toggle mode
  TA1CCR0 = 10-1;
  TA1CTL = TASSEL_1 + MC_1 + TACLR;         // ACLK, upmode, clear TAR

  __bis_SR_register(LPM3_bits);             // Enter LPM3
  __no_operation();                         // For debugger
}
