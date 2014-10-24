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
//  CC430x513x Demo - Flash In-System Programming w/ Long-Word write at 0x1800
//
//  Description: This program first erases flash seg D, then it writes a 32-bit
//  value to memory location 0x1800 using long-word write mode. Long-word write
//  provides faster write than byte/word mode.
//  RESET the device to re-execute code. This is implemented to prevent
//  stressing of Flash unintentionally.
//  ACLK = REFO = 32kHz, MCLK = SMCLK = default DCO 1048576Hz
//
//                CC430x513x
//            -----------------
//        /|\|              XIN|-
//         | |                 |
//         --|RST          XOUT|-
//           |                 |
//
//
//  M. Morales
//  Texas Instruments Inc.
//  April 2009
//  Built with CCE v3.1 Build 3.2.3.6.4 and IAR Embedded Workbench v4.11B
//******************************************************************************

#include <msp430.h>

int main(void)
{
  unsigned long * Flash_ptrD;               // Initialize Flash pointer Seg D
  unsigned long value;
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

  Flash_ptrD = (unsigned long *) 0x1800;    // Initialize Flash pointer
  value = 0x12345678;                       // Initialize Value
  __disable_interrupt();                    // Flash31 Workaround: Disable global
                                            // interrupt while erasing. Re-Enable
                                            // GIE if needed
  FCTL3 = FWKEY;                            // Clear Lock bit
  FCTL1 = FWKEY+ERASE;                      // Set Erase bit
  *Flash_ptrD = 0;                          // Dummy write to erase Flash seg
  FCTL1 = FWKEY+BLKWRT;                     // Enable long-word write
  *Flash_ptrD = value;                      // Write to Flash
  FCTL1 = FWKEY;                            // Clear WRT bit
  FCTL3 = FWKEY+LOCK;                       // Set LOCK bit
  while(1);                                 // Loop forever, SET BREAKPOINT HERE
}
