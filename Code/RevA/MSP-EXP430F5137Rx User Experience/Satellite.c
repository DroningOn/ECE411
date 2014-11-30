/*******************************************************************************
 *
 *  MspExp430F5137RxUserExperience.c - Main User Experience Application
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
/*----------------------------------------------------------------------------
 *  MSP-EXP430F5137Rx User Epxerience Code
 *	End device, connects to Access Point MSP-EXP430F6137Rx in a star network
 *  topology. 
 *  Transmits device's analog data (Vcc, Temp) as well as button presses to the
 *  AP periodically.
 *
 *  Version 1.0                       D. Dang
 *   
 *  Texas Instruments, Inc.
 *  Copyright 2011 Texas Instruments Incorporated. All rights reserved.
 * 
 *---------------------------------------------------------------------------- */
 
 

#include "bsp.h"
#include "mrfi.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"


#include "hal_leds.h"
#include "hal_buttons.h"
#include "hal_adc.h"

#define MESSAGE_BUTTON_PRESSED      0xFF
#define MESSAGE_HEART_BEAT          0xEE


#define USER_EXPERIENCE_FIRMWARE_MODE              0x00
#define USER_EXPERIENCE_PRODUCTION_TEST_MODE       0xFF


/*-----------------------------------------------------------------------------
 *  
 * 
 *  Packet construct:
 *  Byte 0: Message Type      [HeartBeat            or        ButtonPressed]
 *  Byte 1:   Content            Vcc                     MESSAGE_BUTTON_PRESSED 
 *  Byte 2:   Content            Temp_MSB                MESSAGE_BUTTON_PRESSED
 *  Byte 3:   Content            Temp_LSB                MESSAGE_BUTTON_PRESSED
 *  Byte 4:   PacketID MSB 
 *  Byte 5:   PacketID LSB
 *  
 
 *---------------------------------------------------------------------------- */

unsigned char FIRMWARE_MODE = 0xFF;

extern volatile unsigned char  buttonsPressed;
static void linkTo(void);



static uint16_t sTid = 0;

/* Callback handler */
static uint8_t sCB(linkID_t);

static volatile uint8_t  sPeerFrameSem = 0;
static          linkID_t sLinkID1 = 0;

#define SPIN_ABOUT_A_SECOND   NWK_DELAY(1000)
#define SPIN_ABOUT_A_QUARTER_SECOND NWK_DELAY(250)
#define SPIN_ABOUT_A_20th_SECOND   NWK_DELAY(50)

/* How many times to try a Tx and miss an acknowledge before doing a scan */
#define TX_RECONNECTS 5
#define MISSES_IN_A_ROW  2
void SetupRtc(void);

void Satellite (void)
{
  addr_t lAddr;
  
  BSP_Init();
  HalButtonsInit(BUTTON_A, PORT2);
  HalButtonsInterruptEnable(BUTTON_A, PORT2);
  HalButtonsInit(BUTTON_B, PORT2);
  HalButtonsInterruptEnable(BUTTON_B, PORT2);
  HalButtonsInit(BUTTON_C, PORT2);
  HalButtonsInterruptEnable(BUTTON_C, PORT2);
  HalButtonsInit(BUTTON_D, PORT1);
  HalButtonsInterruptEnable(BUTTON_D, PORT1);
  HalLedsInit(LED_A);
  HalLedsInit(LED_B);
  HalLedsInit(LED_C);
  HalLedsInit(LED_D);
  HalAdcInit();
  HalAdcSetQuitFromISR( 1 );
  SetupRtc();
  
  
  // Create a unique address based off the device's wafer ID & 
  // X/Y coordinates
  
  lAddr.addr[0] = (*(uint8_t *)0x01A0E) ^ (*(uint8_t *)0x01A0A); 
  lAddr.addr[1] = (*(uint8_t *)0x01A0F) ^ (*(uint8_t *)0x01A0B);
  lAddr.addr[2] = (*(uint8_t *)0x01A10) ^ (*(uint8_t *)0x01A0C);
  lAddr.addr[3] = (*(uint8_t *)0x01A11) ^ (*(uint8_t *)0x01A0D);
  
  SMPL_Ioctl(IOCTL_OBJ_ADDR, IOCTL_ACT_SET, &lAddr);



  /* Keep trying to join (a side effect of successful initialization) until
   * successful. Toggle LEDS to indicate that joining has not occurred.
   */
  while (SMPL_SUCCESS != SMPL_Init(sCB))
  {
    HalLedsToggle(LED_ALL);
    SPIN_ABOUT_A_SECOND;
  }

  /* LEDs on solid to indicate successful join. */


  /* Unconditional link to AP which is listening due to successful join. */
  linkTo();

  //Bottomless pit.
  while (1) ;
}



static void linkTo()
{
  uint8_t msg[4];
  uint8_t misses, transmitAttempts, done, activeLed;

  char button;


  /* Keep trying to link... */
  while (SMPL_SUCCESS != SMPL_Link(&sLinkID1))
  {
    HalLedsToggle(LED_D);
    SPIN_ABOUT_A_20th_SECOND;
  }
  //System linked with AP, clear LEDS, prepare for sleep.
  HalLedsClear(LED_ALL);

  /* sleep until button press... */
  SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SLEEP, 0);
  
  //RTCPS1CTL |= RT1PSIE;
  
  while (1)
  { 
    /* Send a message when either button pressed */   
    __bis_SR_register(LPM3_bits + GIE);   
    __no_operation();
    done = 0;
    button = HalAlphaButtonsPressed();
    switch (button)
    {
		case 0: //Button A
			activeLed = LED_A;
			break;
		case 1: //Button B
			activeLed = LED_B;
			break;
		case 2: //Button C
			activeLed = LED_C;
			break;
		case 3: //Button D
			activeLed = LED_D;
			break;
		default:
			//Probably don't end up here.
			break;
    }




    //Form packet, send info on button pressed, battery voltage, and transmission count
    HalAdcStartRead();
    __bis_SR_register(LPM0_bits + GIE);
    HalAdcConvertTempVcc();
    msg[0] = button;
    msg[1] = HalAdcGetVcc();
    sTid++; //Transmission counter
    msg[2] = (unsigned char) (sTid>>8);
    msg[3] = (unsigned char) (sTid & 0xFF);

    

    /* get radio ready...awakens in idle state */
    SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_AWAKE, 0);

    /* Set TID and designate which LED to toggle */    

    for(transmitAttempts = 0; transmitAttempts < TX_RECONNECTS; transmitAttempts++)
    {
      for (misses=0; misses < MISSES_IN_A_ROW; ++misses)
        if (SMPL_SUCCESS == SMPL_SendOpt(sLinkID1, msg, sizeof(msg), SMPL_TXOPTION_ACKREQ))
          break;      
      if (misses == MISSES_IN_A_ROW)
      {
        /* This can only happen if we are supporting Frequency Agility and we
         * appear not to have received an acknowledge. Do a scan.
         */
    	  /*
        ioctlScanChan_t scan;
        freqEntry_t     freq[NWK_FREQ_TBL_SIZE];

        scan.freq = freq;
        SMPL_Ioctl(IOCTL_OBJ_FREQ, IOCTL_ACT_SCAN, &scan);
        */
        /* If we now know the channel (number == 1) change to it. In any case
         * try it all again. If we changed channels we should get an ack now.
         */
        /*
    	if (1 == scan.numChan)
        {
          SMPL_Ioctl(IOCTL_OBJ_FREQ, IOCTL_ACT_SET, freq);
        }
       */

    	//For Classboy we assume AP sync issue, so correct.
    	  /*Drop current link*/
    	  SMPL_Unlink(sLinkID1);
    	  /*Send new join request*/
    	  if (SMPL_SUCCESS != SMPL_Init(sCB))
    	   {
    	     HalLedsToggle(LED_ALL);
    	     SPIN_ABOUT_A_20th_SECOND;
    	   }
    	  /*Relink*/
    	  if (SMPL_SUCCESS != SMPL_Link(&sLinkID1))
    	    {
    	      HalLedsToggle(LED_ALL);
    	      SPIN_ABOUT_A_20th_SECOND;
    	    }

      }
      else
      {
        /* Got the ack. We're done. */
    	done = 1;
        break;
      }
    }

    /* radio back to sleep */
    SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SLEEP, 0);

    //Probably should do an RTC sleep here to save power
    if(done)
    {
    HalLedsSet(activeLed);
    SPIN_ABOUT_A_QUARTER_SECOND;
    HalLedsClear(activeLed);
    SPIN_ABOUT_A_QUARTER_SECOND;
    HalLedsSet(activeLed);
    SPIN_ABOUT_A_QUARTER_SECOND;
    }
    HalLedsClear(LED_ALL);
  }
}


static uint8_t sCB(linkID_t lid)
{
  if (lid == sLinkID1)
  {
    sPeerFrameSem++;
    return 0;
  }

  return 1;
}



/**********************************************************************//**
 * @brief  Initializes the RTC module for interval mode 
 * 
 * 
 * 
 * @param  none 
 *  
 * @return none
 *************************************************************************/
void SetupRtc(void)
{  
  RTCCTL01 = RTCMODE + RTCBCD + RTCHOLD + RTCTEV_1;
  

  
  RTCCTL01 &= ~RTCHOLD;
     
  RTCPS1CTL = RT1IP_7;              // Interrupt freq: .5Hz
//  RTCPS1CTL = RT1IP_6;              // Interrupt freq: 1Hz
//  RTCPS1CTL = RT1IP_5;              // Interrupt freq: 2Hz
//  RTCPS1CTL = RT1IP_4;              // Interrupt freq: 4Hz
  
  
    
  //RTCPS0CTL = RT0IP_7;                      // Interrupt freq: 128hz
  
  //RTCCTL0 |= RTCTEVIE;           // Enable interrupt  
}

#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
{
  switch (RTCIV)
  {
    default:      
      __bic_SR_register_on_exit(LPM3_bits);
  }
  
}
