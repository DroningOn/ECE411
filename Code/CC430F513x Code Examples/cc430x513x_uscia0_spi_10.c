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
//   CC430F513x Demo - USCI_A0, SPI 3-Wire Slave Data Echo
//
//   Description: SPI slave talks to SPI master using 3-wire mode. Data received
//   from master is echoed back.  USCI RX ISR is used to handle communication,
//   CPU normally in LPM4.  Prior to initial data exchange, master pulses
//   slaves RST for complete reset.
//   ACLK = ~32.768kHz, MCLK = SMCLK = DCO ~ 1048kHz
//
//   Use with SPI Master Incremented Data code example.  If the slave is in
//   debug mode, the reset signal from the master will conflict with slave's
//   JTAG; to work around, use IAR's "Release JTAG on Go" on slave device.  If
//   breakpoints are set in slave RX ISR, master must stopped also to avoid
//   overrunning slave RXBUF.
//
//                   CC430F5137
//                 -----------------
//            /|\ |                 |
//             |  |                 |
//    Master---+->|RST          P1.0|-> LED
//                |                 |
//                |             P2.0|-> Data Out (UCA0SIMO)
//                |                 |
//                |             P2.2|<- Data In (UCA0SOMI)
//                |                 |
//                |             P2.4|-> Serial Clock Out (UCA0CLK)
//
//
//   M Morales
//   Texas Instruments Inc.
//   October 2008
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW+WDTHOLD;                   // Stop watchdog timer

  while(!(P2IN&BIT4));                      // If clock sig from mstr stays low,
                                            // it is not yet in SPI mode
  
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P2MAP0 = PM_UCA0SIMO;                     // Map UCA0SIMO output to P2.0 
  P2MAP2 = PM_UCA0SOMI;                     // Map UCA0SOMI output to P2.2 
  P2MAP4 = PM_UCA0CLK;                      // Map UCA0CLK output to P2.4 
  PMAPPWD = 0;                              // Lock port mapping registers  
   
  P2DIR |= BIT0 + BIT2 + BIT4;              // ACLK, MCLK, SMCLK set out to pins
  P2SEL |= BIT0 + BIT2 + BIT4;              // P2.0,2,4 for debugging purposes
    
  UCA0CTL1 |= UCSWRST;                      // **Put state machine in reset**
  UCA0CTL0 |= UCSYNC+UCCKPL+UCMSB;          // 3-pin, 8-bit SPI slave,
                                            // Clock polarity high, MSB
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  UCA0IE |= UCRXIE;                         // Enable USCI_A0 RX interrupt

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4, enable interrupts
}

// Echo character
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(UCA0IV,4))
  {
    case 0:break;                             // Vector 0 - no interrupt
    case 2:                                   // Vector 2 - RXIFG
      while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
      UCA0TXBUF = UCA0RXBUF;
      break;
    case 4:break;                             // Vector 4 - TXIFG
    default: break;
  }
}
