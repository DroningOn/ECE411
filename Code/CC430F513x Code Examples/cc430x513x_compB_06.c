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
// CC430x513x Demo - COMPB and TIMERAx interaction (TA0.1, TA1.1)
//
// Description: Use CompB to determine if input, Vcompare has a duty cycle 
//  greater than 50%. When Vcompare exceeds Vcc*3/4 then TimerA0 captures the 
//  time (TA0CCR1). When Vcompare is less than Vcc*1/4 then TimerA1 captures the
//  time (TA1CCR1) and resets the timers for TIMERA0 and TIMERA1. If TA0CCR1 is 
//  greater than TA1CCR1/2, then turn on the LED. If TA0CCR1 is less than 
//  TA1CCR1/2, then turn off the LED.    
//   
//	Clocks: ACLK = REFO; MCLK = SMCLK = 12MHz    
//                                
//                 CC430x513x
//             ------------------                        
//         /|\|                  |                       
//          | |                  |                       
//          --|RST           CB0 |<--Vcompare (200Hz<f<1Mhz) (vary dutycycle)         
//            |                  |                       
//            |                  |                       
//            |              P1.0|-->LED ('ON' if dutycycle > 50%; 'OFF' if dutycycle < 50%)              
//                                                       
//   M Morales
//   Texas Instruments Inc.
//   April 2009
//   Built with CCE Version: 3.2.2 and IAR Embedded Workbench Version: 4.11B
//******************************************************************************
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;     // Stop WDT
  
  // Setup UCS: ACLK = REFO; MCLK = SMCLK = 12MHz                                               
  UCSCTL4 = SELA__REFOCLK + SELS__DCOCLKDIV + SELM__DCOCLKDIV;
  UCSCTL3 |= SELREF__REFOCLK;               // Set DCO FLL reference = REFO
  
  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx
  UCSCTL1 = DCORSEL_5;                      // Select DCO range 24MHz operation
  UCSCTL2 = FLLD_1 + 374;                   // Set DCO Multiplier for 12MHz
                                            // (N + 1) * FLLRef = Fdco
                                            // (374 + 1) * 32768 = 12MHz
                                            // Set FLL Div = fDCOCLK/2
  __bic_SR_register(SCG0);                  // Enable the FLL control loop

  // Worst-case settling time for the DCO when the DCO range bits have been
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
  // UG for optimization.
  // 32 x 32 x 12 MHz / 32,768 Hz = 375000 = MCLK cycles for DCO to settle
  __delay_cycles(375000);
	
  // Loop until XT1,XT2 & DCO fault flag is cleared
  do
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + XT1HFOFFG + DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag
  
  P2SEL |= BIT0;                            // Enable CB0 input
  
// Setup ComparatorB                                            
  CBCTL0 |= CBIPEN + CBIPSEL_0; // Enable V+, input channel CB0              
  CBCTL1 |= CBPWRMD_0;          // CBMRVS=0 => select VREF1 as ref when CBOUT 
                                // is high and VREF0 when CBOUT is low  
                                // High-Speed Power mode        
  CBCTL2 |= CBRSEL;             // Ref is applied to -terminal  
  CBCTL2 |= CBRS_1+CBREF13;     // VREF1 is Vcc*1/4             
  CBCTL2 |= CBREF04+CBREF03;    // VREF0 is Vcc*3/4             
  CBCTL3 |= BIT0;               // Input Buffer Disable @P6.0/CB0    
  CBCTL1 |= CBON;               // Turn On ComparatorB           

// Setup Timer_A0 and Timer_A1                                  
// Internally CBOUT --> TA0CCTL1:CCIB (TA0.1)                          
//                  +-> TA1CCTL1:CCIB (TA1.1)                          
  TA0CTL = TASSEL_2 + MC_1;                 // SMCLK, upmode    
  TA1CTL = TASSEL_2 + MC_1;                 // SMCLK, upmode    
  TA0CCR0 = 0xFFFF;
  TA1CCR0 = 0xFFFF;
  TA0CCTL1 = CM_2+SCS+CAP+CCIS_1;           // Capture Falling Edge   
  TA1CCTL1 = CM_1+SCS+CAP+CCIS_1+CCIE;      // Capture Rising Edge, Enable Interrupt  

  P1DIR |= BIT0;                            // Set P1.0/LED to output           

  __bis_SR_register(LPM3_bits+GIE);         // Enter LPM0 with global interrupts enabled
  __no_operation();                         // For Debug 
}

#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER1_A1_VECTOR
__interrupt void Timer_A(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER1_A1_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  unsigned int temp;
  switch( TA1IV )
  {
   case  2:
          TA0CCR0 = 0;
          TA1CCR0 = 0;          
          TA0CCR0 = 0xFFFF;
          TA1CCR0 = 0xFFFF;                 // Halt and resart TimerA0 and A1 counters     
          temp = TA1CCR1>>1;				// Compare On and off time of input signal
          if(TA0CCR1 > temp)
          	P1OUT |= BIT0;
          else
          	P1OUT &= ~BIT0;
          break;                            
   case  4: break;                          // CCR2 not used
   case  6: break;                          // CCR3 not used
   case  8: break;                          // CCR4 not used
   case 10: break;                          // CCR5 not used
   case 12: break;                          // Reserved not used
   case 14:                                 // Overflow
          __no_operation();    
          while(1);                         // If input frequency < 200Hz, trap here
   default: break;
  }  
} 

