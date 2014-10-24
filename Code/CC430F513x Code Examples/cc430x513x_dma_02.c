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
//   CC430x513x Demo - DMA0, Single Transfer in Block Mode UART1 9600, ACLK
//
//   Description: DMA0 is used to transfer a string as a block to USCI_A0.
//   USCIA0TXIFG WILL trigger DMA0. "Hello World" is TX'd via 9600 baud on
//   USCI_A0. Watchdog in interval mode triggers block transfer every 1000ms.
//   Level senstive trigger used for USCIA0TXIFG to prevent loss of inital edge
//   sensitive triggers - USCIA0TXIFG which is set at POR.
//   ACLK = UCLK 32768Hz, MCLK = SMCLK = default DCO 1048576Hz
//   Baud rate divider with 32768hz XTAL @9600 = 32768Hz/9600 = 3.41 (0003h 4Ah)
//
//                 CC430x513x
//             -----------------
//         /|\|              XIN|-
//          | |                 | 32768Hz
//          --|RST          XOUT|-
//            |                 |
//            |             P2.7|------------> "Hello World"
//            |                 | 9600 - 8N1
//
//  M Morales
//  Texas Instruments Inc.
//  April 2009
//  Built with CCE v3.1 Build 3.2.3.6.4 & IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

const char String1[13] = "Hello World\r\n";

int main(void)
{
  WDTCTL = WDT_ADLY_1000;                   // WDT 1000ms, ACLK, interval timer
  SFRIE1 |= WDTIE;                          // Enable WDT interrupt
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP7 = PM_UCA0TXD;                      // Map UCA0TXD output to P2.7 
  PMAPPWD = 0;                              // Lock port mapping registers 
  
  P2DIR |= BIT7;                            // Set P2.7 as TX output
  P2SEL |= BIT7;                            // Select P2.6 & P2.7 to UART function
  
  UCA0CTL1 |= UCSWRST;                      // 8-bit characters
  UCA0CTL1 = UCSSEL_1;                      // CLK = ACLK
  UCA0BR0 = 0x03;                           // 32k/9600=3.41
  UCA0BR1 = 0x00;
  UCA0MCTL = UCBRS_3+UCBRF_0;               // Modulation
  UCA0CTL1 &= ~UCSWRST;                     // Release USCI state machine

  DMACTL0 = DMA0TSEL_17;                    // USCI_A0 TXIFG trigger
  __data16_write_addr((unsigned short) &DMA0SA,(unsigned long) String1);
                                            // Source block address
  __data16_write_addr((unsigned short) &DMA0DA,(unsigned long) &UCA0TXBUF);
                                            // Destination single address
  DMA0SZ = sizeof(String1);                 // Block size
  DMA0CTL = DMASRCINCR_3+DMASBDB+DMALEVEL;  // Repeat, inc src

  __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3 w/ interrupts
  __no_operation();                         // Required only for debugger
}

//------------------------------------------------------------------------------
// Trigger DMA block transfer
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
  DMA0CTL |= DMAEN;                         // Enable
}
