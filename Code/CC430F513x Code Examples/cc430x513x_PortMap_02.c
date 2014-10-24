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
// CC430x513x Demo - Port Mapping single function to multiple pins;
//
// Description:  Port 2 is port mapped to output TimerA digital signals.  
// TACCR1-3 generate different DutyCycles and have been output on multiple pins. 
// ACLK = REFO~32kHz; MCLK = SMCLK = default DCO;                           
//                                                       
//                 CC430x513x
//             ------------------                        
//         /|\|                  |                       
//          | |                  |                       
//          --|RST               |                                   
//            |     P2.0(TA0CCR1)|--> 25%   
//            |     P2.1(TA0CCR1)|--> 25% 
//            |     P2.2(TA0CCR2)|--> 50%                 
//            |     P2.3(TA0CCR2)|--> 50%                 
//            |     P2.4(TA0CCR3)|--> 75%                 
//            |     P2.5(TA0CCR3)|--> 75%   
//            |     P2.6(default)|--> DVSS                
//            |     P2.7(default)|--> DVSS  
//                 
//   M Morales
//   Texas Instruments Inc.
//   December 2008
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************
#include <msp430.h>

void Port_Mapping(void);

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  
  Port_Mapping();
  
  // Setup Port Pins              
  P2DIR |= 0xFF;                            // P2.0 - P2.7 output
  P2SEL |= 0xFF;                            // P2.0 - P2.6 Port Map functions
  
  // Setup TB0 
  TA0CCR0 = 128;                            // PWM Period/2
  TA0CCTL1 = OUTMOD_6;                      // CCR1 toggle/set
  TA0CCR1 = 96;                             // CCR1 PWM duty cycle
  TA0CCTL2 = OUTMOD_6;                      // CCR2 toggle/set
  TA0CCR2 = 64;                             // CCR2 PWM duty cycle
  TA0CCTL3 = OUTMOD_6;                      // CCR3 toggle/set
  TA0CCR3 = 32;                             // CCR3 PWM duty cycle
  TA0CTL = TASSEL__ACLK + MC_3;             // ACLK/2, up-down mode

  __bis_SR_register(LPM3_bits);		        // Enter LPM3
  __no_operation();                         // For debugger
}

void Port_Mapping(void)
{
  __disable_interrupt();                    // Disable Interrupts before altering 
                                            // Port Mapping registers
  PMAPPWD = 0x02D52;                        // Enable Write-access to modify 
                                            // Port Mapping registers
 
  #ifdef PORT_MAP_RECFG                     
    PMAPCTL = PMAPRECFG;                    // Allow reconfiguration during runtime
  #endif  
  
  P2MAP0 = PM_TA0CCR1A;
  P2MAP1 = PM_TA0CCR1A;
  P2MAP2 = PM_TA0CCR2A;
  P2MAP3 = PM_TA0CCR2A;
  P2MAP4 = PM_TA0CCR3A;
  P2MAP5 = PM_TA0CCR3A;
  P2MAP6 = PM_NONE; 
  P2MAP7 = PM_NONE; 
  
  PMAPPWD = 0;                              // Disable Write-Access to modify port mapping registers
  
  #ifdef PORT_MAP_EINT
    __enable_interrupt();                   // Re-enable all interrupts
  #endif  
}

