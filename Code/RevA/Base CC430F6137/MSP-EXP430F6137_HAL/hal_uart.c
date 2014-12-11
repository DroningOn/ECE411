/*******************************************************************************
 *
 *  hal_uart.c - Hardware Abstraction Layer APIs for the UART module [-->USB PC]
 *
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/
#include "hal_uart.h"


#define UART_MODE_BRIEF               0
#define UART_MODE_VERBOSE             1
extern unsigned char uartMode;

#define TEMP_MODE_FAHRENHEIT          0
#define TEMP_MODE_CELSIUS             1
extern unsigned char temperatureMode ;


unsigned char uartBuffer[20], rxBufferIndex=0;

void HalUartInit(void)
{
  UART_PORT_SEL |= UART_TXD_PIN + UART_RXD_PIN;
  UART_PORT_DIR |= UART_TXD_PIN;
  UCA0BR0 = UART_BR0_SETTING;
  UCA0BR1 = UART_BR1_SETTING;
  UCA0MCTL = UART_MCTL_SETTING;
  UCA0CTL0 = 0;                             // 8-bit, 1 stop bit, no parity, UART async
  UCA0CTL1 |= UCSSEL_2;
  
  UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
  UCA0IE |= UCRXIE;                         // Enable RX interrupt
}

//void HalUartTX(unsigned char string[], unsigned char length);

void HalUartShutdown(void)
{ 
  UART_PORT_SEL &= ~(UART_TXD_PIN + UART_RXD_PIN);
  UCA0IE &= ~UCRXIE;    
}


void HalUartTxString( unsigned char* string, unsigned int length )
{
  unsigned int i;
  for( i = 0; i < length; i++)
  {    
   
    UCA0TXBUF = string[i];    
     while (!(UCA0IFG & UCTXIFG));              // USCI_A0 TX buffer ready? 
  }
}

unsigned char HalUartRxBufferEmpty(void)
{
  if (rxBufferIndex)
    return 0;
  else
    return 1;
}
unsigned char HalUartRxByte(void)
{
  return uartBuffer[0];   
}



/*------------------------------------------------------------------------------
* USCIA interrupt service routine
------------------------------------------------------------------------------*/
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
  char rx = UCA0RXBUF;
  UCA0IFG &= ~UCRXIFG;
  if ( rx == 'V' || rx == 'v' )
  {    
    uartMode = UART_MODE_VERBOSE;
  }
  else if ( rx == 'M' || rx == 'm' )
  {
    uartMode = UART_MODE_BRIEF;
  }
  else if ( rx == 'F' || rx == 'f' )
  {
    temperatureMode = TEMP_MODE_FAHRENHEIT;

  }
  else if ( rx == 'C' || rx == 'c' )
  {
    temperatureMode = TEMP_MODE_CELSIUS;
  }
  uartBuffer[0] = rx;
   
}
