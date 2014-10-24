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
// CC430x513x Demo - COMPB output Toggle in LPM4; internal 2.0V reference
//
// Description: Use CompB and internal reference to determine if input'Vcompare'
//    is high of low.  When Vcompare exceeds 2.0V CBOUT goes high and when 
//    Vcompare is less than 2.0V then CBOUT goes low. 
//    Connect P1.6/CBOUT to P1.0 externally to see the LED toggle accordingly.
//                                                   
//                 CC430x513x
//             ------------------                        
//         /|\|                  |                       
//          | |                  |                       
//          --|RST       P2.0/CB0|<--Vcompare            
//            |                  |                                         
//            |        P1.6/CBOUT|----> 'high'(Vcompare>2.0V); 'low'(Vcompare<2.0V)
//            |                  |  |
//            |            P1.0  |__| LED 'ON'(Vcompare>2.0V); 'OFF'(Vcompare<2.0V)
//            |                  | 
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
  
  P1DIR |= BIT6;                            // P1.6 output direction  
  P1SEL |= BIT6;                            // Select CBOUT function on P1.6/CBOUT
 
  PMAPPWD = 0x02D52;                        // Get write-access to port mapping regs  
  P1MAP6 = PM_CBOUT0;                       // Map CBOUT output to P1.6 
  PMAPPWD = 0;                              // Lock port mapping registers 
  
  P2SEL |= BIT0;                            // Select CB0 input for P2.0 
   
  // Setup ComparatorB                           
  CBCTL0 |= CBIPEN + CBIPSEL_0;             // Enable V+, input channel CB0
  CBCTL1 |= CBPWRMD_1;                      // normal power mode         
  CBCTL2 |= CBRSEL;                         // VREF is applied to -terminal 
  CBCTL2 |= CBRS_3+CBREFL_2;                // R-ladder off; bandgap ref voltage (1.2V)
                                            // supplied ref amplifier to get Vcref=2.0V (CBREFL_2)           
  CBCTL3 |= BIT0;                           // Input Buffer Disable @P6.0/CB0    
  CBCTL1 |= CBON;                           // Turn On ComparatorB           
	
	__delay_cycles(75);				

  __bis_SR_register(LPM4_bits);             // Enter LPM4 
  __no_operation();                         // For debug  
}
