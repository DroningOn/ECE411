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
 *  MspExp430F5137RxUserExperience - Main User Experience Application
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

  // Input, output, interrupt initizalization
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
  
  
  // Create a unique address based off the device's wafer ID & X/Y coordinates
  
  lAddr.addr[0] = (*(uint8_t *)0x01A0E) ^ (*(uint8_t *)0x01A0A); 
  lAddr.addr[1] = (*(uint8_t *)0x01A0F) ^ (*(uint8_t *)0x01A0B);
  lAddr.addr[2] = (*(uint8_t *)0x01A10) ^ (*(uint8_t *)0x01A0C);
  lAddr.addr[3] = (*(uint8_t *)0x01A11) ^ (*(uint8_t *)0x01A0D);
  
  SMPL_Ioctl(IOCTL_OBJ_ADDR, IOCTL_ACT_SET, &lAddr);



  //Check to see if AP is around a few times, sleep if not.
  //Toggle LEDS to indicate no connection available.
  while (SMPL_SUCCESS != SMPL_Init(sCB))
  {
	  uint8_t attempts;
	  for(attempts =0; attempts < TX_RECONNECTS; attempts++)
	  {
		  HalLedsToggle(LED_ALL);
		  SPIN_ABOUT_A_20th_SECOND;
	  }
	  HalLedsClear(LED_ALL);
	  __bis_SR_register(LPM3_bits + GIE); //AP probably not there, go to sleep, wait for button press.
	  __no_operation();
  }



  //AP is around, sync up and enter main program loop.
  linkTo();

  //Bottomless pit of MCU safety.
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
	  for(transmitAttempts =0; transmitAttempts < TX_RECONNECTS; transmitAttempts++)
	  	  {
	  		  HalLedsToggle(LED_ALL);
	  		  SPIN_ABOUT_A_20th_SECOND;
	  	  }
	  //AP was there but no reply, go to sleep, wait for button press to try again.
	  	  HalLedsClear(LED_ALL);
	  	  __bis_SR_register(LPM3_bits + GIE);
	  	  __no_operation();
  }

  //System linked with AP, clear LEDS, prepare for sleep.
  HalLedsClear(LED_ALL);

  /* sleep until button press... */
  SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SLEEP, 0);
  

  while (1)
  {
    /* Send a message when either button pressed */
    __bis_SR_register(LPM3_bits + GIE);
    __no_operation();

    done = 0;
    switch (buttonsPressed) //Works with current definitions since button sub ports are unique
    {
		case BUTTON_A:
			activeLed = LED_A;
			button = 0;
			break;
		case BUTTON_B:
			activeLed = LED_B;
			button = 1;
			break;
		case BUTTON_C:
			activeLed = LED_C;
			button = 2;
			break;
		case BUTTON_D:
			activeLed = LED_D;
			button = 3;
			break;
		default:
			//Probably don't end up here.
			//But incase we do, lets tell the user something got messed up.
			activeLed = LED_ALL;
			button = 0; 		//Just send 'A', all LED blink should tell user to try again
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

    

    //Turn on radio
    SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_AWAKE, 0);


    //Try to send the packet and get an ACK
    for(transmitAttempts = 0; transmitAttempts < TX_RECONNECTS; transmitAttempts++)
    {
      for (misses=0; misses < MISSES_IN_A_ROW; ++misses)
        if (SMPL_SUCCESS == SMPL_SendOpt(sLinkID1, msg, sizeof(msg), SMPL_TXOPTION_ACKREQ))
          break;      
      if (misses == MISSES_IN_A_ROW)
      {

    	//Assume AP sync issue, so try to reconnect.

    	  //Drop current link
    	  SMPL_Unlink(sLinkID1);
    	  //Send new join request
    	  if (SMPL_SUCCESS != SMPL_Init(sCB))
    	   {
    	     HalLedsToggle(LED_ALL);
    	     SPIN_ABOUT_A_20th_SECOND;
    	   }
    	  //Link up with AP
    	  if (SMPL_SUCCESS != SMPL_Link(&sLinkID1))
    	    {
    	      HalLedsToggle(LED_ALL);
    	      SPIN_ABOUT_A_20th_SECOND;
    	    }

      }
      else
      {
        //Got the ACK. Life is good.
    	done = 1;
        break;
      }
    }

    //Turn off radio
    SMPL_Ioctl( IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SLEEP, 0);

    //If everything went well blink the LED a couple times.
    //Fairly hackish but should work ok
    if(done)
    {
    	HalButtonsInterruptDisable(BUTTON_ALL_PORT1, PORT1); //Disable button interrupts for blinking
    	HalButtonsInterruptDisable(BUTTON_ALL_PORT2, PORT2);

    	RTCPS1CTL = RT1IP_5;				//Half second delay to turn on light
		RTCPS1CTL |= RT1PSIE;				//RTC interrupt enable

		__bis_SR_register(LPM3_bits + GIE); //Sleep till RTC wakes it up, first one is to clear fractional periods on RTC
	    __no_operation();
		HalLedsSet(activeLed);
		RTCPS1CTL = RT1IP_4;				//Quarter second blinks
		RTCPS1CTL |= RT1PSIE;				//RTC interrupt enable
		__bis_SR_register(LPM3_bits + GIE);
		 __no_operation();
		HalLedsClear(activeLed);
		__bis_SR_register(LPM3_bits + GIE);
		__no_operation();
		HalLedsSet(activeLed);
		__bis_SR_register(LPM3_bits + GIE);
		__no_operation();
		RTCPS1CTL &= ~RT1PSIE;				//RTC interrupt disable
		HalButtonsInterruptEnable(BUTTON_ALL_PORT1, PORT1);
		HalButtonsInterruptEnable(BUTTON_ALL_PORT2, PORT2);
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


/* RTC initialization for interval interrupts. No args()*/
void SetupRtc(void)
{  
  RTCCTL01 = RTCMODE + RTCBCD + RTCHOLD + RTCTEV_1;
  RTCCTL01 &= ~RTCHOLD;
     
//  RTCPS1CTL = RT1IP_7;              // Interrupt freq: .5Hz
//  RTCPS1CTL = RT1IP_6;              // Interrupt freq: 1Hz
//  RTCPS1CTL = RT1IP_5;              // Interrupt freq: 2Hz
    RTCPS1CTL = RT1IP_4;              // Interrupt freq: 4Hz
}

#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
{
  switch (RTCIV)
  {
    default:      
      __bic_SR_register_on_exit(LPM0_bits);
  }
  
}
