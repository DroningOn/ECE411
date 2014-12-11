/*******************************************************************************
 *  Satellite.c - Core Application for the PSU Classboy
 *  Revision A
 *  Portland State University ECE411 T08 Dec2014
 *
 *
 *  Overview: Application sets up and operates the PSU Classboy by initializing
 *  the required interrupts for user input and connecting as a node to a star
 *  network managed by the Base. After initialization this device remains in
 *  low power mode 3 until a user triggered interrupt wakes the PSU Classboy.
 *  Upon waking, a packet is formed with information about the button pressed,
 *  battery voltage, and packets sent since last reset. The packet is  transmitted
 *  to the Base and expects an ACK. If no ACK is received several attempts are
 *  made to transmit, and then several attempts to fully reconnect to the network
 *  follow. If attempting to reconnect to the network all LED's will blink, notifying
 *  the user that there are connection issues, after several reconnection attempts the
 *  device will return to sleep to conserve energy until next user input. If ACK is
 *  received, the LED related to the button pressed by the user will blink twice and
 *  the device will return to sleep.
 *
 *  Manages core behavior of PSU Classboy with high level control over:
 *
 *  	* Inputs
 *  	* Interrupt initialization
 *  	* Network management
 *      * LED Output
 *
 *  Inspiration for this application provided by:
 *  MspExp430F5137RxUserExperience.c - Main User Experience Application
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *******************************************************************************/



/*-----------------------------------------------------------------------------
 *  Currently defined transmission structure
 *
 *  Packet construct:
 *  Byte 0:   Content            button               User input
 *  Byte 1:   Content            Vcc                  Battery level
 *  Byte 2:   PacketID MSB                            Transmission counter highbyte
 *  Byte 3:   PacketID LSB                            Transmission counter lowbyte
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


extern volatile unsigned char  buttonsPressed;	//User input
static volatile uint8_t  sPeerFrameSem = 0; 	//Linked peer incoming semaphore
static uint16_t sTid = 0;  						//Tx packet counter
static uint8_t sCB(linkID_t); 					//Callback handler
static linkID_t sLinkID1 = 0;		 			//Link ID token

#define SPIN_ABOUT_A_SECOND   NWK_DELAY(1000)
#define SPIN_ABOUT_A_QUARTER_SECOND NWK_DELAY(250)
#define SPIN_ABOUT_A_20th_SECOND   NWK_DELAY(50)

/* Transmission attempts without ACK before reconnect*/
#define MISSES_IN_A_ROW  2
/* Number of network reconnect attempts*/
#define TX_RECONNECTS 5

void SetupRtc(void);
static void linkTo(void);

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

    	//Assume AP sync issue, so try to reconnect.

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
