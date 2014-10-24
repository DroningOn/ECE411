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
//*****************************************************************************
//  CC430F513x Demo - XT1 HF Xtal + Internal DCO
//
//  Description:  This program demonstrates using an external high speed crystal
//  or resonator to supply ACLK and MCLK for the CPU. SMLCK is supplied by the
//  internal DCO.  The high speed crystal or resonator connects between pins
//  Xin and Xout. The DCO clock is generated internally and calibrated from REFO
//  ACLK is brought out on pin P11.0, SMCLK is brought out on P11.2, and MCLK is
//  brought out on pin P11.1.
//  ACLK = LFXT1 = HF XTAL, MCLK = HF XTAL, SMCLK = 32 x ACLK = 1048576Hz
//
//  NOTE: External matching capacitors must be added for the high
//       speed crystal or resonator as required.
//
//                CC430F5137
//             -----------------
//        /|\ |              XIN|-
//         |  |                 | HF RF XTAL (26 - 27 MHz)
//         ---|RST          XOUT|-
//            |                 |
//            |            P2.0 |--> ACLK = High Freq Xtal or Resonator Out
//            |                 |
//            |            P2.2 |--> SMCLK = Default DCO
//            |                 |
//            |            P2.4 |--> MCLK = High Freq Xtal or Resonator Out
//            |                 |
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
  P2MAP0 = PM_ACLK;                         // Map ACLK output to P2.0 
  P2MAP2 = PM_MCLK;                         // Map MCLK output to P2.2 
  P2MAP4 = PM_SMCLK;                        // Map SMCLK output to P2.4 
  PMAPPWD = 0;                              // Lock port mapping registers  
   
  P2DIR |= BIT0 + BIT2 + BIT4;              // ACLK, MCLK, SMCLK set out to pins
  P2SEL |= BIT0 + BIT2 + BIT4;              // P2.0,2,4 for debugging purposes.

  P5SEL |= 0x03;                            // Port select XT1
  
  UCSCTL3 |= SELREF_2;                      // FLL Ref = REFO
  UCSCTL6 |= XT1DRIVE_3 + XTS;              // Max drive strength, adjust
                                            // according to crystal frequency.
                                            // LFXT1 HF mode

  // Loop until XT1 & DCO stabilizes
  do
  {
    UCSCTL7 &= ~(XT1HFOFFG + DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

  UCSCTL4 = SELA__XT1CLK + SELS__DCOCLK + SELM__XT1CLK;
                                            // Select ACLK = LFXT1
                                            //       SMCLK = DCO
                                            //        MCLK = LFXT1
  while(1);                                 // Loop in place
}
