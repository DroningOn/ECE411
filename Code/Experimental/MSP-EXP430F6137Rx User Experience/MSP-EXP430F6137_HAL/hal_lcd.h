/*******************************************************************************
 *
 *  hal_lcd.h - Hardware Abstraction Layer APIs header for the LCD module driver
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

#ifndef HAL_LCD_H
#define HAL_LCD_H


/*-----------------
 *  Seven-Segment 
 *   Arrangement 
 *      __A___
 *     |      |
 *    F|      |B  
 *     |__G___|
 *     |      |
 *    E|      |C 
 *     |______|  
 *        D 
 *-----------------*/

#define LCD_G0   BIT0
#define LCD_G1   BIT1
#define LCD_F    BIT2
#define LCD_E    BIT3
#define LCD_D    BIT4
#define LCD_C    BIT5
#define LCD_B    BIT6
#define LCD_A    BIT7

/*-----------------
 *  Alpha-numeric 
 *   Arrangement 
 *         L
 *      \  |  /
 * NEG  M\ | /K    [] 
 * ---    \|/       COLON
 *        /|\     []
 *      J/ | \H  
 *      /  |  \  [DP]
 *         I
 *-----------------*/
 
#define LCD_DP    BIT0
#define LCD_H     BIT1
#define LCD_I     BIT4
#define LCD_J     BIT3
#define LCD_K     BIT5
#define LCD_L     BIT6
#define LCD_M     BIT7



// Some digits have negative sign, others have the colon symbol
 
#define LCD_COLON BIT2
#define LCD_NEG   BIT2


#define LCD_DIGITS      6


//#ifdef LCD_ALPHA_NUMBERIC_MODE
//#endif


//#ifdef LCD_SYMBOL_MODE
//#endif

//-----LCDM6--------------------------
#define LCD_SYMBOL_ANTENNA        BIT2
#define LCD_SYMBOL_HEART          BIT6
#define LCD_SYMBOL_BANG           BIT4
#define LCD_SYMBOL_CLOCK          BIT7
#define LCD_SYMBOL_R              BIT5
//------------------------------------

//-----LCDM8--------------------------
#define LCD_SYMBOL_TX             BIT2
#define LCD_SYMBOL_RX             BIT0
//------------------------------------

//-----LCDM10-------------------------
#define LCD_SYMBOL_DEGREE         BIT2
//------------------------------------
#define HAL_LCD_BAR_BATTERY_MODE LCDM4|= BIT4
#define HAL_LCD_BAR_LEVEL_MODE  LCDM4&= ~BIT4
#define HAL_LCD_SET_SYMBOL_ANTENNA    LCDM6  |= LCD_SYMBOL_ANTENNA
#define HAL_LCD_SET_SYMBOL_HEART      LCDM6  |= LCD_SYMBOL_HEART
#define HAL_LCD_SET_SYMBOL_BANG       LCDM6  |= LCD_SYMBOL_BANG
#define HAL_LCD_SET_SYMBOL_CLOCK      LCDM6  |= LCD_SYMBOL_CLOCK
#define HAL_LCD_SET_SYMBOL_R          LCDM6  |= LCD_SYMBOL_R
#define HAL_LCD_SET_SYMBOL_TX         LCDM12  |= LCD_SYMBOL_TX
#define HAL_LCD_SET_SYMBOL_RX         LCDM12  |= LCD_SYMBOL_RX;
#define HAL_LCD_SET_SYMBOL_DEGREE     LCDM10 |=LCD_SYMBOL_DEGREE

#define HAL_LCD_CLEAR_SYMBOL_ANTENNA  LCDM6 &= ~LCD_SYMBOL_ANTENNA
#define HAL_LCD_CLEAR_SYMBOL_HEART    LCDM6 &= ~LCD_SYMBOL_HEART
#define HAL_LCD_CLEAR_SYMBOL_BANG     LCDM6 &= ~LCD_SYMBOL_BANG
#define HAL_LCD_CLEAR_SYMBOL_CLOCK    LCDM6 &= ~LCD_SYMBOL_CLOCK
#define HAL_LCD_CLEAR_SYMBOL_R        LCDM6 &= ~LCD_SYMBOL_R
#define HAL_LCD_CLEAR_SYMBOL_TX       LCDM12 &= ~LCD_SYMBOL_TX
#define HAL_LCD_CLEAR_SYMBOL_RX       LCDM12 &= ~LCD_SYMBOL_RX
#define HAL_LCD_CLEAR_SYMBOL_DEGREE   LCDM10 &=~LCD_SYMBOL_DEGREE



#define HAL_LCD_TURN_ON_ALL_SEGMENT   LCDM1=0xFF;  \
                                      LCDM2=0xFF;  \
                                      LCDM3=0xFF;  \
                                      LCDM4=0xFF;  \
                                      LCDM5=0xFF;  \
                                      LCDM6=0xFF;  \
                                      LCDM7=0xFF;  \
                                      LCDM8=0xFF;  \
                                      LCDM9=0xFF;  \
                                      LCDM10=0xFF; \
                                      LCDM11=0xFF; \
                                      LCDM12=0;
                                      
#define HAL_LCD_TURN_OFF_ALL_SEGMENT  LCDM1=0x00;  \
                                      LCDM2=0x00;  \
                                      LCDM3=0x00;  \
                                      LCDM4=0x00;  \
                                      LCDM5=0x00;  \
                                      LCDM6=0x00;  \
                                      LCDM7=0x00;  \
                                      LCDM8=0x00;  \
                                      LCDM9=0x00;  \
                                      LCDM10=0x00; \
                                      LCDM11=0x00; \
                                      LCDM12=0x00;

#define LCD_SCROLL_NO_REPEAT          0
#define LCD_SCROLL_REPEAT             1

  
#define LCD_TEXT_STRING_MAX_LENGTH    50

#define RIGHT_JUSTIFY                 1
#define LEFT_JUSTIFY                  0

void HalLcdInit(void);

//---------------------------------------------------------------------------
//---Functions for LIMITED MODE --------------------------------------------- 
//---------------------------------------------------------------------------

//--Note: these functions can also be used for other modes

void HalLcdPrint7SegDigit(unsigned char digit, unsigned char position);
void HalLcdPrint7Seg(unsigned char string[LCD_DIGITS]);


void HalLcdPrint7SegScroll(unsigned char string[], unsigned char length, unsigned char repeat);
void HalLcdPrint7SegScrollUpdate(void);
void HalLcdPrintStopScrolling(void);
unsigned char HalLcdJustStopsScrolling(void);
unsigned char HalLcdIsScrolling(void);
void HalLcdUpdateScrolling(void);
void HalLcdPrintDecNumber(long number, unsigned char string[6], unsigned justify);


#define HAL_LCD_SET_COLON_1 LCDM4 |= BIT2
#define HAL_LCD_SET_COLON_2 LCDM8 |= BIT2 
#define HAL_LCD_CLEAR_COLON_1 LCDM4 &= ~BIT2
#define HAL_LCD_CLEAR_COLON_2 LCDM8 &= ~BIT2

#define HalLcdSetColon1() HAL_LCD_SET_COLON_1
#define HalLcdSetColon2() HAL_LCD_SET_COLON_2
#define HalLcdClearColon1() HAL_LCD_CLEAR_COLON_1
#define HalLcdClearColon2() HAL_LCD_CLEAR_COLON_2
//---------------------------------------------------------------------------
//---Functions for FULL MODE ------------------------------------------------ 
//---------------------------------------------------------------------------
void HalLcdSetPeriod(unsigned char periodLocation);
void HalLcdClearPeriod(unsigned char periodLocation);


//------------------------------------------
//---Functions for ALPHANUMERIC MODE--------
//------------------------------------------
void HalLcdPrintAlphaNum(unsigned char string[LCD_DIGITS]);
void HalLcdPrintAlphaNumDigit(unsigned char digit, unsigned char position);
//------------------------------------------
//---Functions for SYMBOL MODE--------------
//------------------------------------------
void HalLcdBar(unsigned char level);
#define HalLcdBarBatteryMode()  HAL_LCD_BAR_BATTERY_MODE
#define HalLcdBarLevelMode()    HAL_LCD_BAR_LEVEL_MODE
#define HalLcdSetSymbolAntenna()      HAL_LCD_SET_SYMBOL_ANTENNA
#define HalLcdSetSymbolHeart()        HAL_LCD_SET_SYMBOL_HEART
#define HalLcdSetSymbolBang()         HAL_LCD_SET_SYMBOL_BANG
#define HalLcdSetSymbolClock()        HAL_LCD_SET_SYMBOL_CLOCK
#define HalLcdSetSymbolR()            HAL_LCD_SET_SYMBOL_R
#define HalLcdSetSymbolTx()           HAL_LCD_SET_SYMBOL_TX
#define HalLcdSetSymbolRx()           HAL_LCD_SET_SYMBOL_RX
#define HalLcdSetSymbolDegree()       HAL_LCD_SET_SYMBOL_DEGREE
#define HalLcdClearSymbolAntenna()    HAL_LCD_CLEAR_SYMBOL_ANTENNA
#define HalLcdClearSymbolHeart()      HAL_LCD_CLEAR_SYMBOL_HEART
#define HalLcdClearSymbolBang()       HAL_LCD_CLEAR_SYMBOL_BANG
#define HalLcdClearSymbolClock()      HAL_LCD_CLEAR_SYMBOL_CLOCK
#define HalLcdClearSymbolR()          HAL_LCD_CLEAR_SYMBOL_R
#define HalLcdClearSymbolTx()         HAL_LCD_CLEAR_SYMBOL_TX
#define HalLcdClearSymbolRx()         HAL_LCD_CLEAR_SYMBOL_RX
#define HalLcdClearSymbolDegree()     HAL_LCD_CLEAR_SYMBOL_DEGREE


//------------------------------------------
//---Helper Functions ----------------------
//------------------------------------------
void HalLcdSetupRtc(void);


#endif
