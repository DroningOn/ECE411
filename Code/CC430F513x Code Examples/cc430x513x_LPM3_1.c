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
//   CC430x513x Demo - Enters LPM3 (ACLK = LFXT1)
//
//   Description: Configure ACLK = LFXT1 and enters LPM3. Measure current.
//   Note: SVS(H,L) & SVM(H,L) are disabled
//   ACLK = LFXT1 = 32kHz, MCLK = SMCLK = default DCO
//
//                 CC430x513x
//             -----------------
//        /|\ |              XIN|-
//         |  |                 | 32kHz
//         ---|RST          XOUT|-
//            |                 |
//
//   M. Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

int main(void)
{  
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

  P5SEL |= BIT0 + BIT1;                     // Select XT1
  UCSCTL6 |= XCAP_3;                        // Internal load cap

  // Loop until XT1,XT2 & DCO stabilizes
  do
  {
    UCSCTL7 &= ~(XT1LFOFFG + DCOFFG);
                                            // Clear LFXT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1 & OFIFG);                   // Test oscillator fault flag

  UCSCTL6 &= ~(XT1DRIVE_3);                 // Xtal is now stable, reduce drive
                                            // strength

  P1OUT = 0x00; P2OUT = 0x00; P3OUT = 0x00; P5OUT = 0x00;
  P1DIR = 0xFF; P2DIR = 0xFF; P3DIR = 0xFF; P5DIR = 0x03;
  
  PJOUT = 0x00;
  PJDIR = 0xFF;

  // Turn off SVSH, SVSM
  PMMCTL0_H = 0xA5;
  SVSMHCTL = 0; 
  SVSMLCTL = 0; 
  PMMCTL0_H = 0x00; 

  __bis_SR_register(LPM3_bits);             // Enter LPM3
  __no_operation();                         // For debugger
}
