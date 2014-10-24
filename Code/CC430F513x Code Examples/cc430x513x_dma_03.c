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
//  CC430x513x Demo - SPI TX & RX using DMA0 & DMA1 Single Transfer in Fixed
//                     Address Mode
//
//  Description: This code has to be used with CC430x513x_uscia0_spi_10.c as
//  slave SPI. DMA0 is used to transfer a single byte while DMA1 is used to
//  RX from slave SPI at the same time. This code will set P1.0 if RX character
//  is correct and clears P1.0 if received character is wrong. Watchdog in
//  interval mode triggers block transfer every 1000ms.
//  ACLK = REFO = 32kHz, MCLK = SMCLK = default DCO 1048576Hz
//
//                   CC430F5137
//                 -----------------
//             /|\|                 |
//              | |                 |
//              --|RST          P1.0|-> LED
//                |                 |
//                |             P2.0|-> Data Out (UCA0SIMO)
//                |                 |
//                |             P2.2|<- Data In (UCA0SOMI)
//                |                 |
//                |             P2.4|-> Serial Clock Out (UCA0CLK)
//
//  M Morales
//  Texas Instruments Inc.
//  April 2009
//  Built with CCE v3.1 Build 3.2.3.6.4 & IAR Embedded Workbench Version: 4.11B
//******************************************************************************
 
#include <msp430.h>

char TxString;
char RxString;

int main(void)
{
  WDTCTL = WDT_ADLY_1000;                   // WDT 1000ms, ACLK, interval timer
  SFRIE1 |= WDTIE;                          // Enable WDT interrupt
  
  P1OUT &= ~0x01;                           // Clear P1.0
  P1DIR |= 0x01;                            // P1.0 = Output
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP0 = PM_UCA0SIMO;                     // Map UCA0SIMO output to P2.0 
  P2MAP2 = PM_UCA0SOMI;                     // Map UCA0SOMI output to P2.2 
  P2MAP4 = PM_UCA0CLK;                      // Map UCA0CLK output to P2.4 
  PMAPPWD = 0;                              // Lock port mapping registers  
   
  P2DIR |= BIT0 + BIT2 + BIT4;              // ACLK, MCLK, SMCLK set out to pins
  P2SEL |= BIT0 + BIT2 + BIT4;              // P2.0,2,4 for debugging purposes.

  UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
  UCA0CTL0 = UCMST+UCSYNC+UCCKPL+UCMSB;     // 3-pin, 8-bit SPI master
                                            // Clock polarity high, MSB
  UCA0CTL1 = UCSSEL_2;                      // SMCLK
  UCA0BR0 = 0x02;                           // /2
  UCA0BR1 = 0x00;                           //
  UCA0MCTL = 0x00;                          // No modulation
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**

  DMACTL0 = DMA1TSEL_16+DMA0TSEL_17;        // DMA0 - UCA0TXIFG
                                            // DMA1 - UCA0RXIFG
  // Setup DMA0
  __data16_write_addr((unsigned short) &DMA0SA,(unsigned long) &TxString);
                                            // Source block address
  __data16_write_addr((unsigned short) &DMA0DA,(unsigned long) &UCA0TXBUF);
                                            // Destination single address
  DMA0SZ = 1;                               // Block size
  DMA0CTL = DMASRCINCR_3+DMASBDB+DMALEVEL;  // inc src

  // Setup DMA1
  __data16_write_addr((unsigned short) &DMA1SA,(unsigned long) &UCA0RXBUF);
                                            // Source block address
  __data16_write_addr((unsigned short) &DMA1DA,(unsigned long) &RxString);
                                            // Destination single address
  DMA1SZ = 1;                               // Block size
  DMA1CTL = DMADSTINCR_3+DMASBDB+DMALEVEL;  // inc dst

  TxString = RxString = 0;                  // Clear TxString
                                            // Clear RxString
  __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3 w/ interrupts
  __no_operation();                         // Required only for debugger
}

//------------------------------------------------------------------------------
// Trigger DMA0 & DMA1 block transfer.
//------------------------------------------------------------------------------
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(WDT_VECTOR))) WDT_ISR (void)
#else
#error Compiler not supported!
#endif
{
  if(TxString-1 == RxString)
    P1OUT |= 0x01;                          // Set P1.0 if True
  else
    P1OUT &= ~0x01;                         // Clear P1.0 if False

  TxString++;                               // Increment TxString counter
  DMA1CTL |= DMAEN;                         // DMA1 Enable
  DMA0CTL |= DMAEN;                         // DMA0 Enable
}
