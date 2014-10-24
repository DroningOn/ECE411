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
//  CC430F5137 Demo - Timer_A3, Toggle P1.0;P2.1-3, Cont. Mode ISR, 32kHz ACLK
//
//  Description: Use Timer1_A CCRx units and overflow to generate four
//  independent timing intervals. For demonstration, CCR0, CCR1 and CCR2
//  output units are optionally selected with port pins P2.0, P2.2 and P2.4
//  in toggle mode. As such, these pins will toggle when respective CCRx
//  registers match the TAR counter. Interrupts are also enabled with all
//  CCRx units, software loads offset to next interval only - as long as
//  the interval offset is added to CCRx, toggle rate is generated in
//  hardware. Timer1_A overflow ISR is used to toggle P1.0 with software.
//  Proper use of the TAIV interrupt vector generator is demonstrated.
//  ACLK = TACLK = 32kHz, MCLK = SMCLK = default DCO ~1.045MHz
//
//  As coded and with TACLK = 32768Hz, toggle rates are:
//  P2.0= CCR0 = 32768/(2*4) = 4096Hz
//  P2.2= CCR1 = 32768/(2*16) = 1024Hz
//  P2.4= CCR2 = 32768/(2*100) = 163.84Hz
//  P1.0= overflow = 32768/(2*65536) = 0.25Hz
//
//               CC430F5137
//            -------------------
//        /|\|                   |
//         | |                   |
//         --|RST                |
//           |                   |
//           |         P2.0/TA1.0|--> CCR0
//           |         P2.2/TA1.1|--> CCR1
//           |         P2.4/TA1.2|--> CCR2
//           |               P1.0|--> Overflow/software
//           |               P1.0|--> LED
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
  P2MAP2 = PM_TA1CCR1A;                     // Map TA1CCR1 output to P2.2 
  P2MAP4 = PM_TA1CCR2A;                     // Map TA1CCR2 output to P2.4 
  PMAPPWD = 0;                              // Lock port mapping registers 
  
  P2SEL |= BIT0 + BIT2 + BIT4;              // P2.0, P2.2, P2.4 option select
  P2DIR |= BIT0 + BIT2 + BIT4;              // P2.0, P2.2, P2.4 outputs
  P1DIR |= BIT0;                            // P1.0 - Outputs
  
  TA1CCTL0 = OUTMOD_4 + CCIE;               // CCR0 toggle, interrupt enabled
  TA1CCTL1 = OUTMOD_4 + CCIE;               // CCR1 toggle, interrupt enabled
  TA1CCTL2 = OUTMOD_4 + CCIE;               // CCR2 toggle, interrupt enabled
  TA1CTL = TASSEL_1 + MC_2 + TACLR + TAIE;  // ACLK, contmode, clear TAR,
                                            // interrupt enabled

  __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3, interrupts enabled
  __no_operation();                         // For debugger
}

// Timer1 A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A0 (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER1_A0_VECTOR))) Timer_A0 (void)
#else
#error Compiler not supported!
#endif
{
  TA1CCR0 += 4;                             // Add Offset to CCR0
}

// Timer_A3 Interrupt Vector (TAIV) handler
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER1_A1_VECTOR))) TIMER1_A1_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(TA1IV,14))
  {
    case 0: break;                  
    case 2:  TA1CCR1 += 16;                 // Add Offset to CCR1
             break;
    case 4:  TA1CCR2 += 100;                // Add Offset to CCR2
             break;
    case 6:  break;                         // CCR3 not used
    case 8:  break;                         // CCR4 not used
    case 10: break;                         // CCR5 not used
    case 12: break;                         // Reserved not used
    case 14: P1OUT ^= 0x01;                 // overflow
             break;
    default: break;
 }
}

