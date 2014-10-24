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
//  CC430F513x Demo - LFXT1 Oscillator Fault Detection
//
//  Description: System runs normally in LPM3 with with basic timer clocked by
//  32kHz ACLK with a 1 second interrupt. If an LFXT1 oscillator fault occurs,
//  NMI is requested forcing exit from LPM3. P1.0 is toggled rapidly by
//  software as long as LFXT1 oscillator fault is present. Assuumed only
//  LFXT1 as NMI source - code does not check for other NMI sources.
//  ACLK = LFXT1 = 32768Hz, MCLK = SMCLK = default DCO = 32 x ACLK = 1048576Hz
//  //* An external watch crystal between XIN & XOUT is required for ACLK *//	
//
//
//           CC430F5137
//         -----------------
//    /|\ |              XIN|-
//     |  |                 | 32kHz
//     ---|RST          XOUT|-
//        |                 |
//        |             P1.0|-->LED
//
//   M. Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

volatile unsigned int i;

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  // Set up XT1
  P5SEL |= BIT0 + BIT1;                     // Analog function for XT1 Pins
  
  UCSCTL6 |= XCAP_3;                        // Internal load cap

  P1DIR |= BIT0;                            // P1.0 output

  RTCCTL01 = RTCTEV_3;
  RTCPS0CTL = RT0PSDIV_7;                   // Set RTPS0 to /256
  RTCPS1CTL = RT1IP_6 + RT1PSIE + RT1SSEL_3;// Set RT1IP to /4, enable
                                            // RT1PS interrupt and select
                                            // RTOPS output as clock

  SFRIE1 = OFIE;                            // Enable osc fault interrupt

  __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3, enable interrupts
  __no_operation();                         // For debugger
}


// RTC Interrupt Service Routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(RTC_VECTOR))) RTC_ISR (void)
#else
#error Compiler not supported!
#endif
{
  P1OUT ^= 0x01;                            // Toggle P1.0
  RTCCTL01 &= ~RTCTEVIFG;
  RTCPS1CTL &= ~RT1PSIFG;
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=UNMI_VECTOR
__interrupt void UNMI_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(UNMI_VECTOR))) UNMI_ISR (void)
#else
#error Compiler not supported!
#endif
{
  do
  {
    UCSCTL7 &= ~(XT1LFOFFG + DCOFFG);       // Clear XT1 & DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear OSC Fault flag
    for (i = 0xFFFF; i > 0; i--);           // Time for flag to set
    P1OUT ^= BIT0;                          // Toggle P1.0 using exclusive-OR
  }while ( (SFRIFG1 & OFIFG) );
}
