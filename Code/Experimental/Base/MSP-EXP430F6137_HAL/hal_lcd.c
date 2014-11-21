/*******************************************************************************
 *
 *  hal_lcd.c - Hardware Abstraction Layer APIs for the LCD module & driver
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
#include "cc430f6137.h"
#include "hal_lcd.h"


#define NEGATIVE_ONE            0x1F  

const unsigned char FontSevenSegment[] = 
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x62, //NEGATIVE_ONE
//                                        - 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x01, 0, 0,
  
  0xFC, 0x60, 0xDB, 0xF3, 0x67, 0xB7, 0xBF, 0xE0, 0xFF, 0xF7, 0, 0, 0, 0, 0, 0,   //0-9

//  ?    A     B     C     D     E     F     G     H     I     J      K         L     M     N      O
  0x00, 0xEF, 0x3F, 0x9C, 0x7B, 0x9F, 0x8E, 0xBD, 0x6F, 0x0C, 0x78, 0x6F/*K*/, 0x1C, 0xEC, 0x2B, 0xFC,

//  P    Q     R     S     T     U     V     W     X     Y     Z      ?     ?     ?      ?
  0xCF, 0xE7, 0x0B, 0xB7, 0x1E, 0x7C, 0x38, 0x54, 0x6F, 0x77, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00,
  
  0x00, 0xEF, 0x3F, 0x9C, 0x7B, 0x9F, 0x8F, 0xBD, 0x6F, 0x0C, 0x78, 0x6F/*K*/, 0x1C, 0xEC, 0x2B, 0xFC,

//  P    Q     R     S     T     U     V     W     X     Y     Z      ?     ?     ?      ?
  0xCF, 0xE7, 0x0B, 0xB7, 0x1E, 0x7C, 0x38, 0x54, 0x6F, 0x77, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00
};


const unsigned char FontAlphaNum[][2] = 
{
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},  
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
  {0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
  
  {0xFC,0x28},{0x60,0x00},{0xDB,0x00},{0xF3,0x00},{0x67,0x00},{0xB7,0x00}, {0xBF,0x00}, {0xE0,0x00},
  {0xFF,0x00},{0xF7,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
//                A           B           C           D           E             F           G                
  {0x00,0x00},{0xEF,0x00},{0xF1,0x88},{0x9C,0x00},{0xFC,0x00}, {0x9F,0x00}, {0x8E,0x00},{0xBD,0x00},    
//     H          I           J           K           L           M             N           O                
  {0x6F,0x00},{0x90,0x50},{0x78,0x00},{0x0E,0x22},{0x3C,0x00}, {0x6C,0xA0}, {0x6C,0x82},{0xFC,0x00},
//     P          Q           R           S           T           U             V           W                
  {0xCF,0x00},{0xFC,0x02},{0x8E,0x22},{0xB7,0x00},{0x80,0x50}, {0x7C,0x00}, {0x60,0x82},{0x6C,0x0A},
//     X          Y           Z                                                                              
  {0x00,0xAA},{0x00,0xB0},{0x90,0x28},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},
//                a           b           c           d           e             f           g                
  {0x00,0x00},{0x1A,0x10},{0x1E,0x02},{0x1A,0x00},{0x1A,0x50}, {0xDF,0x00}, {0x8E,0x00},{0xF7,0x00},    
//     h          i           j           k           l           m             n           o               
  {0x0E,0x10},{0x00,0x10},{0x78,0x00},{0x00,0x72},{0x1C,0x00}, {0x44,0xA0}, {0x04,0xC0},{0x3B,0x00},
//     p          q           r           s           t           u             v           w                
  {0xC1,0x50},{0x86,0x50},{0x0B,0x00},{0xB7,0x00},{0x03,0x50}, {0x06,0x40}, {0x00,0xA0},{0x28,0x0A},
//     x          y           z                                                                              
  {0x00,0xAA},{0x00,0xA8},{0x12,0x80},{0x00,0x00},{0x00,0x00},{0x00,0x00}, {0x00,0x00}, {0x00,0x00},  
};



unsigned char lcdTextString[LCD_TEXT_STRING_MAX_LENGTH + LCD_DIGITS + LCD_DIGITS] = "      HELLO CC430      ";
unsigned char lcdTextLength = 0;
unsigned char lcdScrollActive = 0;
unsigned char lcdScrollJustStop = 0;
unsigned char lcdScrollPosition = 0;
unsigned char lcdScrollRepeat = 0; //Repeat the text scrolling?
//unsigned char lcdScrollDirection = 0; // 0 = LEFT to RIGHT, 1 = RIGHT to LEFT


void HalLcdInit(void)
{
  P5SEL |= ( BIT5 | BIT6 | BIT7);
  P5DIR |= ( BIT5 | BIT6 | BIT7);
  // Configure LCD_B
  LCDBCTL0 =  (LCDDIV0 + LCDDIV1 + LCDDIV2 + LCDDIV3 + LCDDIV4)| LCDPRE0 | LCD4MUX | LCDON | LCDSON;  
  LCDBVCTL = LCDCPEN | VLCD_3_02;
  //REFCTL0 &= ~REFMSTR;
  //Charge pump generated internally at 3.44V, external bias (V2-V4) generation
  //Internal reference for charge pump 
  LCDBPCTL0 = 0xFFFF;                         //Select all LCD Segments
  LCDBPCTL1 = 0x00FF;
  LCDM1=0;
  LCDM2=0;
  LCDM3=0;
  LCDM4=0;
  LCDM5=0;
  LCDM6=0;
  LCDM7=0;
  LCDM8=0;
  LCDM9=0;
  LCDM10=0;
  LCDM11=0;
  LCDM12=0;   
}


void HalLcdPrint7SegDigit(unsigned char digit, unsigned char position)
{
  switch (position)
  {
    case 0: LCDM1 = FontSevenSegment[digit]; break;
    case 1: LCDM3 = FontSevenSegment[digit]; break;
    case 2: LCDM5 = FontSevenSegment[digit]; break;
    case 3: LCDM7 = FontSevenSegment[digit]; break;
    case 4: LCDM9 = FontSevenSegment[digit]; break;
    case 5: LCDM11 = FontSevenSegment[digit]; break;
  } 
}

void HalLcdPrint7Seg(unsigned char string[LCD_DIGITS])
{
  // Disables scrolling after each print
  // If this function is called by the scrolling update, 
  // the scrolling function should then re-enable scrolling bit  
  lcdScrollActive = 0;
  HalLcdClearSymbolDegree();
  // Clear periods
  LCDM2  &= ~BIT0;
  LCDM4  &= ~BIT0; 
  LCDM6  &= ~BIT0; 
  LCDM8  &= ~BIT0; 
  LCDM10 &= ~BIT0; 
  LCDM12 &= ~BIT0;   
  LCDM1 = FontSevenSegment[string[0]];
  LCDM3 = FontSevenSegment[string[1]];
  LCDM5 = FontSevenSegment[string[2]];
  LCDM7 = FontSevenSegment[string[3]];
  LCDM9 = FontSevenSegment[string[4]];
  LCDM11 = FontSevenSegment[string[5]];    
}

void HalLcdPrint7SegScroll(unsigned char string[], unsigned char length, unsigned char repeat)
{
  unsigned char i;
  lcdScrollRepeat = repeat;
  lcdTextLength = length + LCD_DIGITS + LCD_DIGITS - 2;
  /* Buffer the text string with white spaces before & after the string*/
  for (i=0;i< LCD_DIGITS - 1;i++)
  	  lcdTextString[i] = ' ';
  for (i=0; i <length; i++)
    lcdTextString[i + LCD_DIGITS - 1] = string[i];
  for (i=length+ LCD_DIGITS - 1;i<length + LCD_DIGITS + LCD_DIGITS - 2; i++)
	  lcdTextString[i] = ' ';

  lcdScrollActive = 1;
  lcdScrollPosition = LCD_DIGITS;
  HalLcdPrint7SegScrollUpdate();  
}

void HalLcdPrint7SegScrollUpdate(void)
{
  unsigned char saveScrollActive = lcdScrollActive;
    
  // HalLcdPrint7Seg automatically reset the ScrollActive flag
  //   to account for new non-scrolling udates
  // This function needs to set the flag again
  HalLcdPrint7Seg((unsigned char*)(&(lcdTextString[lcdScrollPosition])));
  lcdScrollActive = saveScrollActive;  
}
void HalLcdPrintStopScrolling(void)
{
  lcdScrollActive = 0;
  lcdScrollPosition = 0;
  lcdScrollRepeat = 0;  
}
unsigned char HalLcdJustStopsScrolling(void)
{
  unsigned char temp;
  temp = lcdScrollJustStop;
  lcdScrollJustStop = 0; 
  return temp;
}

unsigned char HalLcdIsScrolling(void)
{   
  return lcdScrollActive;
}






//---------------------------------------------------------------------------
//---Functions for FULL MODE ------------------------------------------------ 
//---------------------------------------------------------------------------


// 0 1 2 3 4 5
void HalLcdSetPeriod(unsigned char periodLocation)
{
  switch (periodLocation)
  {
  case 0: LCDM2  |= BIT0; break;
  case 1: LCDM4  |= BIT0; break;
  case 2: LCDM6  |= BIT0; break;
  case 3: LCDM8  |= BIT0; break;
  case 4: LCDM10 |= BIT0; break;
  case 5: LCDM12 |= BIT0; break;  
  }    
}

void HalLcdClearPeriod(unsigned char periodLocation)
{
  switch (periodLocation)
  {
  case 0: LCDM2  &= ~BIT0; break;
  case 1: LCDM4  &= ~BIT0; break;
  case 2: LCDM6  &= ~BIT0; break;
  case 3: LCDM8  &= ~BIT0; break;
  case 4: LCDM10 &= ~BIT0; break;
  case 5: LCDM12 &= ~BIT0; break;  
  }
}

//---------------------------------------------------------------------------
//---These functions require LCD to be used in Full mode and alphanumeric---- 
//---------------------------------------------------------------------------
void HalLcdPrintAlphaNum(unsigned char string[LCD_DIGITS])
{
  LCDM1 = FontAlphaNum [string[0]][0];
  LCDM2 = FontAlphaNum [string[0]][1];
  LCDM3 = FontAlphaNum [string[1]][0];
  LCDM4 = FontAlphaNum [string[1]][1];
  LCDM5 = FontAlphaNum [string[2]][0];
  LCDM6 = FontAlphaNum [string[2]][1];
  LCDM7 = FontAlphaNum [string[3]][0];
  LCDM8 = FontAlphaNum [string[3]][1];
  LCDM9 = FontAlphaNum [string[4]][0];
  LCDM10 = FontAlphaNum [string[4]][1];
  LCDM11 = FontAlphaNum [string[5]][0];
  LCDM12 = FontAlphaNum [string[5]][1];  
}

void HalLcdPrintAlphaNumDigit(unsigned char digit, unsigned char position)
{
  switch (position)
  {
    case 0: LCDM1 = FontAlphaNum[digit][0];  LCDM2 = FontAlphaNum[digit][1]; break;
    case 1: LCDM3 = FontAlphaNum[digit][0];  LCDM4 = FontAlphaNum[digit][1]; break;
    case 2: LCDM5 = FontAlphaNum[digit][0];  LCDM6 = FontAlphaNum[digit][1]; break;
    case 3: LCDM7 = FontAlphaNum[digit][0];  LCDM8 = FontAlphaNum[digit][1]; break;
    case 4: LCDM9 = FontAlphaNum[digit][0];  LCDM10 = FontAlphaNum[digit][1]; break;
    case 5: LCDM11 = FontAlphaNum[digit][0]; LCDM12 = FontAlphaNum[digit][1]; break;
  } 
}


//---------------------------------------------------------------------------
//---These functions require LCD to be used in Full mode and with symbols---- 
//---------------------------------------------------------------------------



void HalLcdBar(unsigned char level)
{
  LCDM2 |= BIT4;      // Box [] around the bars
  LCDM2 &= ~0xE0;     // Clear bars 
  LCDM4 &= ~ 0xE0;    // Clear bars
  switch (level)
  {
    case 6: LCDM4 |= BIT7;    // Each level adds a segment to the bar
    case 5: LCDM2 |= BIT7;
    case 4: LCDM4 |= BIT6;        
    case 3: LCDM2 |= BIT6;
    case 2: LCDM4 |= BIT5;
    case 1: LCDM2 |= BIT5;
    case 0: break; 
  }   
}




void HalLcdUpdateScrolling(void)
{
  
    // Adjust position & direction of the scrolling       
     


    // End of scrolling to the right  
    if (++lcdScrollPosition == lcdTextLength - LCD_DIGITS + 1)
    {
      // If scroll repeat --> restart scrolling
      if (lcdScrollRepeat != 0)
        lcdScrollPosition = 0;


      // Else stop scrolling
      else
      {
        lcdScrollActive = 0;
        lcdScrollJustStop = 1;       
        return;   
          // Turn off RTC or keep it on for other functions?
          //            RTCCTL01 |= RTCHOLD; 
          //            RTCPS1CTL &= ~RT1PSIE;           
      }    
    }    


   HalLcdPrint7SegScrollUpdate();

}




/**********************************************************************//**
 * @brief  Converts & formats a number [in decimal] into a string  
 *         
 * 
 * @param  number             decimal number to be converted to string
 *         string             string to store the result
 *         justify            Right/Left justification
 *                            0 = LEFT_JUSTIFY
 *                            1 = RIGHT_JUSTIFY
 * @return none
 *************************************************************************/
void HalLcdPrintDecNumber(long number, unsigned char string[6], unsigned justify)
{
  volatile int sign = 0, i, j;
  long x;  
  
  //--------------- Range & sign check
  if (number <0)
  {
    sign = 1;
    number = - number;
    if (number > 1999999)
    {
      string = (unsigned char*)"-INFI";
      return;
    }
      
  } 
  else
    if (number > 999999)
    {
      string = (unsigned char*)" INFI";
      return;
    }
  //----------End of range & sign check
  for (i=0;i<5;i++)
    string[i] = ' ';
    
  i = 5;  
  while (number != 0)
  {
    x = number / 10;
    string[i--] = '0' + (unsigned char)(number - x *10);
    number = x; 
  }
  i = 0;
  while (string[i] ==' ')
    i++;
  if (sign == 1)
  {
    if (string[i]=='1')
      string[i] = NEGATIVE_ONE;
    else
    {
      string[--i] = '-';
    }    
  }
  // If right justify, the string is already in right format
  if (justify)      
    return;
  // Else left-justify the string    
  if (i>0)
    for (j=0; j < 6-i; j++)
    {
      string[j] = string[i+j];
      string[i+j] = ' ';
    }   
      
}
