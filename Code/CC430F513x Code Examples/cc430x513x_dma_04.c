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
//  CC430x513x Demo - DMA0, Single transfer using ADC12_A triggered by Timer_A0
//
//  Description: This software uses TACCR1 as a sample and convert input into
//  the A0 of ADC12. ADC12IFG is used to trigger a DMA transfer and DMA
//  interrupt triggers when DMA transfer is done. TA1 is set as an output and
//  P1.0 is toggled when DMA ISR is serviced.
// 
//  ACLK = REFO = 32kHz, MCLK = SMCLK = default DCO 1048576Hz
//
//                 CC430x513x
//             -----------------
//         /|\|              XIN|-
//          | |                 | 32kHz
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//            |                 |
//            |             P4.1|-->TA1 output
//            |                 |
//            |             P6.0|<--A0
//
//  M. Morales
//  Texas Instruments Inc.
//  April 2009
//  Built with CCE v3.1 Build 3.2.3.6.4 & IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

unsigned int DMA_DST;

int main(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Hold WDT

  P1OUT  = 0;                               // P1.0, P1.6 clear
  P1DIR |= BIT0 + BIT6;                     // P1.0 output to LED, P1.6 GND 
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP6 = PM_TA0CCR1A;                     // Map TA0CCR1 output to P2.6 
  PMAPPWD = 0;                              // Lock port mapping registers 

  P2DIR |= BIT6;                            // Output TA0CCR1 
  P2SEL |= BIT6;                            // Enable TA0CCR1 functionality   
  
  /* Initialize Timer A0 */
  TA0CCR0 = 0xFFFE;
  TA0CCR1 = 0x8000;
  TA0CCTL1 = OUTMOD_3;                       // CCR1 set/reset mode
  TA0CTL = TASSEL_2+MC_1+TACLR;              // SMCLK, Up-Mode

  /* Initialize REF module */
  // Enable 2.5V shared reference, disable temperature sensor to save power
  REFCTL0 |= REFMSTR+REFVSEL_2+REFON+REFTCOFF; 
  
  /* Initialize ADC12_A */
  ADC12CTL0 = ADC12SHT0_15+ADC12MSC+ADC12ON;// Sampling time, MSC, ADC12 on
  ADC12CTL1 = ADC12SHS_1+ADC12CONSEQ_2;     // Use sampling timer; ADC12MEM0
                                            // Sample-and-hold source = CCI0B =
                                            // TBCCR1 output
                                            // Repeated-single-channel
  ADC12MCTL0 = ADC12SREF_0+ADC12INCH_0;     // V+=AVcc V-=AVss, A0 channel
  ADC12CTL0 |= ADC12ENC;

  __delay_cycles(75);                       // ~75us shared ref. settling time
 
  /* Initialize DMA0 */ 
  DMACTL0 = DMA0TSEL_24;                    // ADC12IFGx triggered
  DMACTL4 = DMARMWDIS;                      // Read-modify-write disable
  DMA0CTL &= ~DMAIFG;
  DMA0CTL = DMADT_4+DMAEN+DMADSTINCR_3+DMAIE; // Rpt single tranfer, inc dst, Int
  DMA0SZ = 1;                               // DMA0 size = 1
  __data16_write_addr((unsigned short) &DMA0SA,(unsigned long) &ADC12MEM0);
                                            // ... from ADC12MEM0
  __data16_write_addr((unsigned short) &DMA0DA,(unsigned long) &DMA_DST);
                                            // ... to destination in RAM

  __bis_SR_register(LPM0_bits + GIE);       // LPM0 w/ interrupts
  __no_operation();                         // used for debugging
}

//------------------------------------------------------------------------------
// DMA Interrupt Service Routine
//------------------------------------------------------------------------------
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=DMA_VECTOR
__interrupt void DMA_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(DMA_VECTOR))) DMA_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(DMAIV,16))
  {
    case 0: break;
    case 2:                                 // DMA0IFG = DMA Channel 0
      P1OUT ^= BIT0;                        // Toggle P1.0
      break;
    case 4: break;                          // DMA1IFG = DMA Channel 1
    case 6: break;                          // DMA2IFG = DMA Channel 2
    case 8: break;                          // DMA3IFG = DMA Channel 3
    case 10: break;                         // DMA4IFG = DMA Channel 4
    case 12: break;                         // DMA5IFG = DMA Channel 5
    case 14: break;                         // DMA6IFG = DMA Channel 6
    case 16: break;                         // DMA7IFG = DMA Channel 7
    default: break;
  }
}
