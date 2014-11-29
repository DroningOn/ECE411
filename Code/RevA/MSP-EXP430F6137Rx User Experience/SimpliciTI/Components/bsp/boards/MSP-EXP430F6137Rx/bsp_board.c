/**************************************************************************************************
  Revised:        $Date: 2009-02-28 10:43:04 -0800 (Sat, 28 Feb 2009) $
  Revision:       $Revision: 19285 $

  Copyright 2008-2009 Texas Instruments Incorporated.  All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights granted under
  the terms of a software license agreement between the user who downloaded the software,
  his/her employer (which must be your employer) and Texas Instruments Incorporated (the
  "License"). You may not use this Software unless you agree to abide by the terms of the
  License. The License limits your use, and you acknowledge, that the Software may not be
  modified, copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio frequency
  transceiver, which is integrated into your product. Other than for the foregoing purpose,
  you may not use, reproduce, copy, prepare derivative works of, modify, distribute,
  perform, display or sell this Software and/or its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS”
  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY
  WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
  IN NO EVENT SHALL TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE
  THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY
  INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST
  DATA, COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY
  THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 *   BSP (Board Support Package)
 *   Target : Texas Instruments CC430EM
 *   Top-level board code file.
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
 */

/* ------------------------------------------------------------------------------------------------
 *                                            Includes
 * ------------------------------------------------------------------------------------------------
 */
#include "bsp.h"
#include "bsp_config.h"

#include "HAL_UCS.h"
#include "HAL_PMM.h"
#include "hal_msp-exp430f6137rx.h"
/* ------------------------------------------------------------------------------------------------
 *                                            Prototypes
 * ------------------------------------------------------------------------------------------------
 */
static void Bsp_SetVCore(void);
static void Bsp_SetClocks(void);

int16_t __low_level_init(void); /* Used in IAR environment */
int16_t _system_pre_init(void); /* USed in CCE environment */

/* ------------------------------------------------------------------------------------------------
 *                                            Defines
 * ------------------------------------------------------------------------------------------------
 */
#define BSP_TIMER_CLK_MHZ   12       /* 12 MHz MCLKC and SMCLK */
#define BSP_DELAY_MAX_USEC  (0xFFFF/BSP_TIMER_CLK_MHZ) /* 5461 */

/**************************************************************************************************
 * @fn          Bsp_SetVCore
 *
 * @brief       Setup the core voltage to PMMCOREV_3.
 *
 * @param       none
 *
 * @return      none
 **************************************************************************************************
 */
static void Bsp_SetVCore(void)
{
  SetVCore(PMMCOREV_3);
//  PMMCTL0_H = 0xA5; /* Enable register access */
//
//  SVSMLCTL |= SVMLE; /* Enable low side SVM */
//
//  SVSMLCTL |= 0x3; /* Set SVM level to 1.84 */
//
//  while( !(PMMIFG & SVSMLDLYIFG) ); /* Wait till set: SVS and SVM Lowside Delay expired Flag */
//
//  PMMCTL0_L = PMMCOREV_3; /* Set VCore to 1.85V */
//
//  /* Wait till set: SVM LowSide VoltageLevelReached Flag */
//  while( !(PMMIFG & SVMLVLRIFG) );
//
//  SVSMLCTL &= ~(SVMLE); /* Enable low side SVM */
//
//  PMMCTL0_H = 0x00; /* Disable register access */
}

/**************************************************************************************************
 * @fn          Bsp_SetClocks
 *
 * @brief       Set up system clocks. 
 *            
 *              SMCLK = MCLK = 12MHz
 *              ACLK = REFOCLK
 *
 * @param       none
 *
 * @return      none
 **************************************************************************************************
 */
static void Bsp_SetClocks(void)
{
  /* Configure CPU clock for 12MHz */

  /* If clock settings are changed, remember to update BSP_TIMER_CLK_MHZ.
   * Otherwise, all timer settings would be incorrect.
   */
  //UCSCTL0 = 0x00;            // Set lowest possible DCOx, MODx
  //UCSCTL1 = DCORSEL_5;       // Select suitable range
  //UCSCTL2 = FLLD_1 | 0x16E;  // Set DCO Multiplier
  //UCSCTL3 = SELREF__REFOCLK; // Select REFO as FLL reference

  /* Select REFO as ACLK source and DCOCLK as MCLK and SMCLK source */
  //UCSCTL4 = SELA__REFOCLK | SELS__DCOCLKDIV | SELM__DCOCLKDIV;
  
  /*---------------EXP430F6137 Edit-----------------*/
    
  SELECT_FLLREF(SELREF__REFOCLK);
  SELECT_ACLK (SELA__REFOCLK);
  SELECT_MCLK (SELM__DCOCLK);
  SELECT_SMCLK (SELS__DCOCLK);
  Init_FLL_Settle( MAIN_CLOCK_FREQUENCY, 366 );              // DCO = 12MHz, no divider 
  
  
  
  
  
//  UCSCTL0 = 0x00;                           // Set lowest possible DCOx, MODx
//  UCSCTL1 = DCORSEL_6;                      // Select range for 12MHz operation
//  UCSCTL2 = 374;                            // Set DCO Multiplier for 12MHz
//                                            // (N + 1) * FLLRef = Fdco
//                                            // (374 + 1) * 32768 = 12MHz
//  UCSCTL3 = SELREF_2;                       // Set DCO FLL reference = REFO
//  UCSCTL4 = SELS_3 + SELM_3 + SELA_1;       // Set MCLK = SMCLK = DCOCLK
}

/* ------------------------------------------------------------------------------------------------
 *                                            Local Variables
 * ------------------------------------------------------------------------------------------------
 */
#if defined(SW_TIMER)
static uint8_t sIterationsPerUsec = 0;
#endif

/**************************************************************************************************
 * @fn          Bsp_EarlyInit
 *
 * @brief       This function is called by start-up code before doing the normal initialization
 *              of data segments. If the return value is zero, initialization is not performed.
 *              The gloabl label "BSP_EarlyInit" gets aliased (#defined) in the bsp_msp430_defs.h
 *              file, according to the specific compiler environment (CCE or IAR). In the CCE
 *              environment this function is named "_system_pre_init()", in the IAR environment
 *              this function is named "__low_level_init()".
 *
 * @param       None
 *
 * @return      0 - don't intialize data segments / 1 - do initialization
 **************************************************************************************************/
int16_t BSP_EarlyInit(void)
{
  /* Disable watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Setup Vcore */
  Bsp_SetVCore();

  /* Configure System clocks */
  Bsp_SetClocks();

  /* Return 1 - run seg_init */
  return (1);
}

/**************************************************************************************************
 * @fn          BSP_InitBoard
 *
 * @brief       Initialize the board.
 *
 * @param       none
 *
 * @return      none
 **************************************************************************************************
 */
void BSP_InitBoard(void)
{
  WDTCTL = WDTPW | WDTHOLD;
  Bsp_SetVCore();

  /* Configure System clocks */
  Bsp_SetClocks();  
  /* Configure TimerA for use by the delay function */

  /* Reset the timer */
  TA0CTL |= TACLR; /* Set the TACLR  */

  /* Clear all settings */
  TA0CTL = 0x0;

  /* Select the clk source to be - SMCLK (Sub-Main CLK)*/
  TA0CTL |= TASSEL_2;
  
#if defined(SW_TIMER)
#define MHZ_CLOCKS_PER_USEC      BSP_CLOCK_MHZ
#define MHZ_CLOCKS_PER_ITERATION 10

  sIterationsPerUsec = (uint8_t)(((MHZ_CLOCKS_PER_USEC)/(MHZ_CLOCKS_PER_ITERATION))+.5);

  if (!sIterationsPerUsec)
  {
    sIterationsPerUsec = 1;
  }
#endif   /* SW_TIMER */
}

/**************************************************************************************************
 * @fn          BSP_Delay
 *
 * @brief       Sleep for the requested amount of time.
 *
 * @param       # of microseconds to sleep.
 *
 * @return      none
 **************************************************************************************************
 */
void BSP_Delay(uint16_t usec)
#if !defined(SW_TIMER)
{
  BSP_ASSERT(usec < BSP_DELAY_MAX_USEC);

  TA0R = 0; /* initial count */
  TA0CCR0 = BSP_TIMER_CLK_MHZ*usec; /* compare count. (delay in ticks) */

  /* Start the timer in UP mode */
  TA0CTL |= MC_1;

  /* Loop till compare interrupt flag is set */
  while(!(TA0CCTL0 & CCIFG));

  /* Stop the timer */
  TA0CTL &= ~(MC_1);

  /* Clear the interrupt flag */
   TA0CCTL0 &= ~CCIFG;
}
#else  /* !SW_TIMER */
{
  /* Declared 'volatile' in case User optimizes for speed. This will
   * prevent the optimizer from eliminating the loop completely. But
   * it also generates more code...
   */
  volatile uint16_t repeatCount = sIterationsPerUsec*usec;

  while (repeatCount--) ;

  return;
}
#endif  /* !SW_TIMER */

