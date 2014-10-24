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
//  CC430F5137 Demo - ADC12_A, Sequence of Conversions (non-repeated)
//
//  Description: This example shows how to perform A/D conversions on a sequence
//  of channels. A single sequence of conversions is performed - one conversion
//  each on channels A0, A1, A2, and A3. Each conversion uses AVcc and AVss for
//  the references. The conversion results are stored in ADC12MEM0, ADC12MEM1,
//  ADC12MEM2, and ADC12MEM3 respectively and are moved to 'results[]' upon
//  completion of the sequence. Test by applying voltages to pins A0, A1, A2,
//  and A3, then setting and running to a break point at the "_BIC..."
//  instruction in the ISR. To view the conversion results, open a watch window
//  in debugger and view 'results' or view ADC12MEM0, ADC12MEM1, ADC12MEM2, and
//  ADC12MEM3 in an ADC12 SFR window.
//  This can run even in LPM4 mode as ADC has its own clock
//  Note that a sequence has no restrictions on which channels are converted.
//  For example, a valid sequence could be A0, A3, A2, A4, A2, A1, A0, and A7.
//  See the CC430 User's Guide for instructions on using the ADC12.
//
//                CC430F5137
//             -----------------
//         /|\|                 |
//          | |                 |
//          --|RST              |
//            |                 |
//    Vin0 -->|P2.0/A0          |
//    Vin1 -->|P2.1/A1          |
//    Vin2 -->|P2.2/A2          |
//    Vin3 -->|P2.3/A3          |
//            |                 |
//
//   M Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

volatile unsigned int results[4];           // Needs to be global in this example
                                            // Otherwise, the compiler removes it
                                            // because it is not used for anything.

int main(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer
  
  P2SEL = 0x0F;                             // Enable A/D channel inputs
  
  /* Initialize ADC12_A */ 
  ADC12CTL0 = ADC12ON+ADC12MSC+ADC12SHT0_2; // Turn on ADC12, set sampling time
  ADC12CTL1 = ADC12SHP+ADC12CONSEQ_1;       // Use sampling timer, single sequence
  ADC12MCTL0 = ADC12INCH_0;                 // ref+=AVcc, channel = A0
  ADC12MCTL1 = ADC12INCH_1;                 // ref+=AVcc, channel = A1
  ADC12MCTL2 = ADC12INCH_2;                 // ref+=AVcc, channel = A2
  ADC12MCTL3 = ADC12INCH_3+ADC12EOS;        // ref+=AVcc, channel = A3, end seq.
  ADC12IE = 0x08;                           // Enable ADC12IFG.3
  ADC12CTL0 |= ADC12ENC;                    // Enable conversions

  while(1)
  {
    ADC12CTL0 |= ADC12SC;                   // Start convn - software trigger
    
    __bis_SR_register(LPM4_bits + GIE);     // Enter LPM4, Enable interrupts
    __no_operation();                       // For debugger    
  }
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt void ADC12ISR (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(ADC12_VECTOR))) ADC12ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(ADC12IV,34))
  {
  case  0: break;                           // Vector  0:  No interrupt
  case  2: break;                           // Vector  2:  ADC overflow
  case  4: break;                           // Vector  4:  ADC timing overflow
  case  6: break;                           // Vector  6:  ADC12IFG0
  case  8: break;                           // Vector  8:  ADC12IFG1
  case 10: break;                           // Vector 10:  ADC12IFG2
  case 12:                                  // Vector 12:  ADC12IFG3
    results[0] = ADC12MEM0;                 // Move results, IFG is cleared
    results[1] = ADC12MEM1;                 // Move results, IFG is cleared
    results[2] = ADC12MEM2;                 // Move results, IFG is cleared
    results[3] = ADC12MEM3;                 // Move results, IFG is cleared
    __bic_SR_register_on_exit(LPM4_bits);   // Exit active CPU, SET BREAKPOINT HERE  
  case 14: break;                           // Vector 14:  ADC12IFG4
  case 16: break;                           // Vector 16:  ADC12IFG5
  case 18: break;                           // Vector 18:  ADC12IFG6
  case 20: break;                           // Vector 20:  ADC12IFG7
  case 22: break;                           // Vector 22:  ADC12IFG8
  case 24: break;                           // Vector 24:  ADC12IFG9
  case 26: break;                           // Vector 26:  ADC12IFG10
  case 28: break;                           // Vector 28:  ADC12IFG11
  case 30: break;                           // Vector 30:  ADC12IFG12
  case 32: break;                           // Vector 32:  ADC12IFG13
  case 34: break;                           // Vector 34:  ADC12IFG14
  default: break; 
  }
}

