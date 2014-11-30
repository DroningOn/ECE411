/*******************************************************************************
 *
 *  MspExp430F6137RxUserExperience.c - Main User Experience Application
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
 *  MSP-EXP430F6137Rx User Epxerience Code
 *  MSP-EXP430F6137Rx configured as SimpliciTI star network access point (AP).
 *  Allows MSP-EXP430F5137Rx end devices (ED) to join the network. 
 *  Displays AP & EDs info on the LCD screen and transmits the data to the PC
 *  via the UART-USB bridge as well.
 *
 *  
 *  Version 1.0                       D. Dang
 *   
 *  Texas Instruments, Inc.
 *  Copyright 2011 Texas Instruments Incorporated. All rights reserved.
 *---------------------------------------------------------------------------- */
#include <string.h>
#include "bsp.h"
#include "mrfi.h"
#include "bsp_leds.h"
#include "bsp_buttons.h"
#include "nwk_types.h"
#include "nwk_api.h"
#include "nwk_frame.h"
#include "nwk.h"

#include "hal_leds.h"
#include "hal_buttons.h"
#include "hal_lcd.h"
#include "hal_adc.h"
#include "hal_uart.h"


/**************************** COMMENTS ON ASYNC LISTEN APPLICATION ***********************
Summary:
  This AP build includes implementation of an unknown number of end device peers in
  addition to AP functionality. In this scenario all End Devices establish a link to
  the AP and only to the AP. The AP acts as a data hub. All End Device peers are on
  the AP and not on other distinct ED platforms.

  There is still a limit to the number of peers supported on the AP that is defined
  by the macro NUM_CONNECTIONS. The AP will support NUM_CONNECTIONS or fewer peers
  but the exact number does not need to be known at build time.

  In this special but common scenario SimpliciTI restricts each End Device object to a
  single connection to the AP. If multiple logical connections are required these must
  be accommodated by supporting contexts in the application payload itself.

Solution overview:
  When a new peer connection is required the AP main loop must be notified. In essence
  the main loop polls a semaphore to know whether to begin listening for a peer Link
  request from a new End Device. There are two solutions: automatic notification and
  external notification. The only difference between the automatic notification
  solution and the external notification solution is how the listen semaphore is
  set. In the external notification solution the sempahore is set by the user when the
  AP is stimulated for example by a button press or a commend over a serial link. In the
  automatic scheme the notification is accomplished as a side effect of a new End Device
  joining.

  The Rx callback must be implemented. When the callback is invoked with a non-zero
  Link ID the handler could set a semaphore that alerts the main work loop that a
  SMPL_Receive() can be executed successfully on that Link ID.

  If the callback conveys an argument (LinkID) of 0 then a new device has joined the
  network. A SMPL_LinkListen() should be executed.

  Whether the joining device supports ED objects is indirectly inferred on the joining
  device from the setting of the NUM_CONNECTIONS macro. The value of this macro should
  be non-zero only if ED objects exist on the device. This macro is always non-zero
  for ED-only devices. But Range Extenders may or may not support ED objects. The macro
  should be be set to 0 for REs that do not also support ED objects. This prevents the
  Access Point from reserving resources for a joinng device that does not support any
  End Device Objects and it prevents the AP from executing a SMPL_LinkListen(). The
  Access Point will not ever see a Link frame if the joining device does not support
  any connections.

  Each joining device must execute a SMPL_Link() after receiving the join reply from the
  Access Point. The Access Point will be listening.

*************************** END COMMENTS ON ASYNC LISTEN APPLICATION ********************/

/************  THIS SOURCE FILE REPRESENTS THE AUTOMATIC NOTIFICATION SOLUTION ************/

/* reserve space for the maximum possible peer Link IDs */
static linkID_t sLID[NUM_CONNECTIONS];
static uint8_t  sNumCurrentPeers = 0;
/* callback handler */
static uint8_t sCB(linkID_t);
/* received message handler */
static void processMessage(linkID_t, uint8_t *, uint8_t);
/* work loop semaphores */
static volatile uint8_t sPeerFrameSem = 0;
static volatile uint8_t sJoinSem = 0;
/* blink LEDs when channel changes... */
static volatile uint8_t sBlinky = 0;

#define SPIN_ABOUT_A_QUARTER_SECOND   NWK_DELAY(250)

#define MESSAGE_BUTTON_PRESSED      0xFF
#define MESSAGE_HEART_BEAT          0xEE
#define MESSAGE_LENGTH              6

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
         
unsigned char string[6] = "xxxxxx";
unsigned char lastMessage = 0;

//void SetupRtc(void);
unsigned char ConvertVccToLevel(unsigned char vcc);

#define TEMP_MODE_FAHRENHEIT          0
#define TEMP_MODE_CELSIUS             1
unsigned char temperatureMode = TEMP_MODE_FAHRENHEIT;

#define UART_MODE_BRIEF               0
#define UART_MODE_VERBOSE             1
unsigned char uartMode = UART_MODE_VERBOSE;




#define NODE_DISPLAY_TEMPERATURE        0
#define NODE_DISPLAY_RSSI               1
#define AP_DISPLAY_LIGHT                2


typedef struct _nodeInfo
{

  unsigned char address;
  signed char rssi;
  signed int temperature;
  unsigned char vcc;  
     
} nodeInfo;  


nodeInfo nodeInfos[NUM_CONNECTIONS];
unsigned char nodeNum = 1;                  // Node #0 = Access Point
unsigned char nodeCurrent = 0;              // Current node to display info on the LCD
unsigned char nodeInfoDisplayMode = NODE_DISPLAY_TEMPERATURE;
unsigned char broadcastAlert = 0;
 unsigned char lcdClearSymbol = 0; //Flag to clear symbols 
 
 
#define HEART_BEAT              1
#define NOT_HEART_BEAT          0

void UpdateNodeInfoOnLcd(unsigned char nodeIndex, unsigned char heartBeat);
void TransmitUartData(unsigned char nodeIndex );
void SetupRtc(void);



void Base (void)
{

  bspIState_t intState;
  unsigned char buttonsPressed;
  
     
  BSP_Init();
  HalButtonsInit(BUTTON_ALL);
  HalButtonsInterruptEnable(BUTTON_ALL);
  HalLedsInit(LED_ALL);
  HalLcdInit();
  HalUartInit();
  HalAdcInit();
  HalAdcSetQuitFromISR( 1 );
  
  nodeInfos[0].rssi = 0;
  nodeInfos[0].address = 0;
  
  __bis_SR_register(GIE);
  
  

   
  //memset(sSample, 0x0, sizeof(sSample));

  SMPL_Init(sCB);
  HAL_LEDS_SET(LED_1);
  /* green and red LEDs on solid to indicate waiting for a Join. */
  HalLcdPrint7SegScroll((unsigned char*)"Access Point Up", 15, LCD_SCROLL_REPEAT);
  SetupRtc();
  /* main work loop */
  while (1)
  {
    /* Wait for the Join semaphore to be set by the receipt of a Join frame from a
     * device that supports an End Device.
     *
     * An external method could be used as well. A button press could be connected
     * to an ISR and the ISR could set a semaphore that is checked by a function
     * call here, or a command shell running in support of a serial connection
     * could set a semaphore that is checked by a function call.
     */
    if (sJoinSem && (sNumCurrentPeers < NUM_CONNECTIONS))
    {
      /* listen for a new connection */
      HalLcdPrintStopScrolling();
      HalLcdPrint7Seg((unsigned char*)"Listen");
      while (1)
      {
        HalLedsToggle(LED_1);
        if (SMPL_SUCCESS == SMPL_LinkListen(&sLID[sNumCurrentPeers]))
        {
          HalLedsSet(LED_2);
          HalLedsClear(LED_1);
          break;
        }
        /* Implement fail-to-link policy here. otherwise, listen again. */
      }
      HalLcdPrint7SegScroll((unsigned char*)"Add End Device", 14, LCD_SCROLL_NO_REPEAT);
      HalLedsClear(LED_2);
      HalLedsSet(LED_3);
      sNumCurrentPeers++;
      nodeNum++;
      BSP_ENTER_CRITICAL_SECTION(intState);
      sJoinSem--;
      BSP_EXIT_CRITICAL_SECTION(intState);
    }
   

    /* Have we received a frame on one of the ED connections?
     * No critical section -- it doesn't really matter much if we miss a poll
     */
    
    if (sPeerFrameSem)
    {
      uint8_t     msg[MAX_APP_PAYLOAD], len, i;

      /* process all frames waiting */
      for (i=0; i<sNumCurrentPeers; ++i)
      {
        if (SMPL_SUCCESS == SMPL_Receive(sLID[i], msg, &len))
        {
          
          processMessage(sLID[i], msg, len);          
          BSP_ENTER_CRITICAL_SECTION(intState);
          sPeerFrameSem--;
          BSP_EXIT_CRITICAL_SECTION(intState);
        }
      }
    }            
    buttonsPressed  = HalButtonsPressedIFG();
    if (buttonsPressed > 0)
    { 
      switch (buttonsPressed)
      {
        case BUTTON_U:  
                        if (nodeCurrent == 0)
                          nodeCurrent = nodeNum-1;
                        else
                          nodeCurrent--;     
                        if (nodeCurrent !=0)
                          if (nodeInfoDisplayMode == AP_DISPLAY_LIGHT)
                            nodeInfoDisplayMode = NODE_DISPLAY_TEMPERATURE;                                                                                       
                        break;
                        
        case BUTTON_D:  
                        if (++nodeCurrent == nodeNum)
                          nodeCurrent = 0;
                        if (nodeCurrent !=0)
                          if (nodeInfoDisplayMode == AP_DISPLAY_LIGHT)
                            nodeInfoDisplayMode = NODE_DISPLAY_TEMPERATURE;  
                        break;
                        
        case BUTTON_L:                    
        case BUTTON_R:
                        if (nodeCurrent != 0)   // Not Access Point                        
                        {
                          if (nodeInfoDisplayMode == NODE_DISPLAY_TEMPERATURE)
                            nodeInfoDisplayMode = NODE_DISPLAY_RSSI;  
                          else
                            nodeInfoDisplayMode = NODE_DISPLAY_TEMPERATURE;
                            //Always default back to temp regardless of node/AP
                        }  
                        else
                        {
                          if (buttonsPressed == BUTTON_L)
                            nodeInfoDisplayMode += 3 - 1;
                          else
                            nodeInfoDisplayMode += 1;
                          if (nodeInfoDisplayMode >=3)
                            nodeInfoDisplayMode -= 3;    
                        }

                        break;                      
        
      }
      UpdateNodeInfoOnLcd(nodeCurrent, NOT_HEART_BEAT);
    }
    
    if (HalAdcJustUpdated())
    {
      if (HalAdcGetLightSensor() < LIGHT_SENSOR_THRESHOLD)
        HalLcdSetSymbolR();
      else
        HalLcdClearSymbolR();  
      HalAdcConvertTempVcc();
      nodeInfos[0].vcc = HalAdcGetVcc();
      nodeInfos[0].temperature = HalAdcGetTempDegF();
      //broadcastAlert = (HalGetLightSensor()<LIGHT_SENSOR_THRESHOLD);
      if (!HalLcdIsScrolling())
        if (nodeCurrent == 0)
          UpdateNodeInfoOnLcd( 0, HEART_BEAT );  
      TransmitUartData( 0 );    
    }
    
    
    BSP_ENTER_CRITICAL_SECTION(intState);
    if (sBlinky)
    {
      if (++sBlinky >= 0xF)
      {
        sBlinky = 1;
        HalLedsToggle(LED_1 + LED_2);        
      }
    }
    BSP_EXIT_CRITICAL_SECTION(intState);
    
  }
  
}


/* Runs in ISR context. Reading the frame should be done in the */
/* application thread not in the ISR thread. */
static uint8_t sCB(linkID_t lid)
{
  if (lid)
  {
    sPeerFrameSem++;
    sBlinky = 0;
  }
  else
  {
    sJoinSem++;
  }

  /* leave frame to be read by application. */
  return 0;
}

static void processMessage(linkID_t lid, uint8_t *msg, uint8_t len)
{
  /* do something useful */
  ioctlRadioSiginfo_t sigInfo;
  if (len)
  {     
    HalLedsToggle(LED_4);
    
    // Update rssi value for the TXing ED 
    sigInfo.lid = lid;
    SMPL_Ioctl(IOCTL_OBJ_RADIO, IOCTL_ACT_RADIO_SIGINFO, (void *)&sigInfo);    
    nodeInfos[lid].rssi = sigInfo.sigInfo.rssi;

      
    
    if (msg[0] == MESSAGE_BUTTON_PRESSED)
    {
      HalLcdSetSymbolBang();
      if (lid != nodeCurrent)
      {
        nodeCurrent = lid;
        UpdateNodeInfoOnLcd(nodeCurrent, NOT_HEART_BEAT);
      }  
    }
    else 
    if (msg[0] == MESSAGE_HEART_BEAT)
    {
        nodeInfos[lid].address = lid;
        nodeInfos[lid].vcc = msg[1];
        *(unsigned char*)(&(nodeInfos[lid].temperature)) = msg[2];
        *((unsigned char*)(&(nodeInfos[lid].temperature))+1) = msg[3];
        
        //----To be implemented
        TransmitUartData(lid);  // Send nodeInfo[lid] update to PC
        if (!HalLcdIsScrolling())
          if (lid == nodeCurrent)
          {
             UpdateNodeInfoOnLcd(nodeCurrent, HEART_BEAT);
          }    
 
    }
    TransmitUartData(nodeCurrent);
    // INSERT CODE TO SETUP TRANSMIT UART to PC here
    // LID can be stored to save some info.
    
    
    //SetupRtc();
    *msg |= NWK_APP_REPLY_BIT;
    

  }
  return;
}



void UpdateNodeInfoOnLcd(unsigned char nodeIndex, unsigned char heartBeat)
{
  // Update a node from a heart beat message
  signed int tempTemperature;
   
  if (heartBeat)
    HalLcdSetSymbolHeart();
  HalLcdBarBatteryMode();
  HalLcdBar (ConvertVccToLevel(nodeInfos[nodeIndex].vcc)) ;
  
  if (nodeIndex>0)
  {  
    //string[0] = '0'+(((nodeInfos[nodeIndex].address)/10)%10);
    string[0] = '0'+((nodeInfos[nodeIndex].address)%10);
    if (string[0] > '9')
      string[0] = string[0]-'9'-1 + 'A';
    string[1] = ' ';  
  }
  else
  {
    string[0] = 'H';
    string[1] = ' ';
  
  }   
  
  if (nodeInfoDisplayMode == NODE_DISPLAY_TEMPERATURE)
  {    
    tempTemperature = nodeInfos[nodeIndex].temperature;
    
    if ((tempTemperature < 0) || (tempTemperature>=1000))
    {
      if (tempTemperature <0)
        string[2] = '-';
      else
        string[2] = '0' + ((tempTemperature/1000)%10);
          
      string[3] = '0' + ((tempTemperature/100)%10);
      string[4] = '0' + ((tempTemperature/10)%10);
      string[5] = 'F';        
      HalLcdPrint7Seg(string);
      HalLcdSetSymbolDegree();
    }
    else
    {      
      string[2] = '0' + ((tempTemperature/100)%10);
      string[3] = '0' + ((tempTemperature/10)%10);
      string[4] = '0' + ((tempTemperature/1)%10);
         
      string[5] = 'F';
      HalLcdPrint7Seg(string);
      HalLcdSetPeriod( 3 );
      HalLcdSetSymbolDegree();           
    }
    
  }
  else                                      // NODE_DISPLAY_RSSI
  if (nodeInfoDisplayMode == NODE_DISPLAY_RSSI)  
  { 
    if (nodeInfos[nodeIndex].rssi == 0)
    {
      string[2]=' ';
      string[3]='H';
      string[4]='U';
      string[5]='B';  
    }
    else    
    if (nodeInfos[nodeIndex].rssi<-100)
    { 
      string[2] = '-';
      string[3] = '0'+((-nodeInfos[nodeIndex].rssi/100)%10);
      string[4] = '0'+((-nodeInfos[nodeIndex].rssi/10)%10);
      string[5] = '0'+(-nodeInfos[nodeIndex].rssi%10);
       
    }
    else
    {
      string[2] = ' ';
      string[3] = '-';
      string[4] = '0'+((-nodeInfos[nodeIndex].rssi/10)%10);
      string[5] = '0'+(-nodeInfos[nodeIndex].rssi%10);
      
    }
    HalLcdPrint7Seg(string);              
  }
  else                                      // AP_DISPLAY_LIGHT
  {
      string[0] = 'L';
      string[1] = ' ';
      string[2] = '0'+((HalAdcGetLightSensor()/1000)%10);
      string[3] = '0'+((HalAdcGetLightSensor()/100)%10);
      string[4] = '0'+((HalAdcGetLightSensor()/10)%10);
      string[5] = '0'+(HalAdcGetLightSensor()%10);  
      HalLcdPrint7Seg(string);
  }
    
  lcdClearSymbol  = 1;
  //HalLcdSetFutureClearSymbol();
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
  RTCPS1CTL = RT1IP_5;              // Interrupt freq: 2Hz
  RTCPS1CTL |= RT1PSIE;
}


//void ConfigureLcdScrolling(void)
//{
//  //lcdClearSymbol = 2;
//  HalLcdSetupRtc();  
//}


#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
{
  static unsigned char updateAccessPointInfo = 0;
  switch (RTCIV)
  {
    default:      
      if (--lcdClearSymbol == 0)
      {        
        //HalLcdClearSymbolDegree();
        HalLcdClearSymbolBang();
        HalLcdClearSymbolHeart();          
      }
      if (HalLcdIsScrolling())
        HalLcdUpdateScrolling();
      if (++updateAccessPointInfo==4)
      {
        updateAccessPointInfo = 0;
        HalAdcStartRead();   
      }
      
  }
  
}


/**********************************************************************//**
 * @brief  Convert Vcc value into level for LCD's bar display 
 * 
 * Vcc range = 18 - 37
 * Bar range = 0  - 6
 * 
 * @param  none 
 *  
 * @return none
 *************************************************************************/
unsigned char ConvertVccToLevel(unsigned char vcc)
{
  unsigned char level = 0;
  while (vcc>=18)
  {
    vcc -= 3;
    level++;
  }
  if (level>6)
    level = 6;
  return level;
}



void TransmitUartData(unsigned char nodeIndex )
{
  
  unsigned char addrString[4];
  char rssiString[3];  
  char temp_string[] = {" XX.XF"};
  int rssi_int;
  int temp = nodeInfos[nodeIndex].temperature;
  static unsigned char output_verbose[] = {"\r\nNode:XXXX,Temp:-XX.XC,Battery:X.XV,Strength:XXX%,RE:0000000 "};  
  static unsigned char output_short[] = {"\r\n$ADDR,-XX.XC,V.C,RSI,N#"};
  
  if (nodeIndex == 0)
  {
    addrString[0] = 'H';
    addrString[1] = 'U';
    addrString[2] = 'B';
    addrString[3] = '0';
    rssiString[0] = '0';
    rssiString[1] = '0';
    rssiString[2] = '0';
  }
  else
  {
    addrString[0] = '0';
    addrString[1] = '0';
    addrString[2] = '0'+(((nodeInfos[nodeIndex].address)/10)%10);
    addrString[3] = '0'+((nodeInfos[nodeIndex].address)%10);
    
    rssi_int = (signed int) nodeInfos[nodeIndex].rssi;
    rssi_int = rssi_int+128;
    rssi_int = (rssi_int*100)/256;  
    rssiString[0] = '0'+(rssi_int%10);
    rssiString[1] = '0'+((rssi_int/10)%10);
    rssiString[2] = '0'+((rssi_int/100)%10);
  }
    
  
  if(temperatureMode == TEMP_MODE_CELSIUS)
  {
    temp = (int)(((float)temp-320)*5/9);
    temp_string[5] = 'C';
  }
  
  if( temp < 0 )
  {
    temp_string[0] = '-';
    temp = temp * -1;
  }
  else if( ((temp/1000)%10) != 0 )
  {
    temp_string[0] = '0'+((temp/1000)%10);
  }
  temp_string[4] ='0'+(temp%10);;
  temp_string[2] = '0'+((temp/10)%10);
  temp_string[1] = '0'+((temp/100)%10);
  

  if(uartMode == UART_MODE_VERBOSE)  
  {
    

    output_verbose[46] = rssiString[2];
    output_verbose[47] = rssiString[1];
    output_verbose[48] = rssiString[0];

    output_verbose[17] = temp_string[0];
    output_verbose[18] = temp_string[1];
    output_verbose[19] = temp_string[2];
    output_verbose[20] = temp_string[3];
    output_verbose[21] = temp_string[4];
    output_verbose[22] = temp_string[5];

    output_verbose[32] = '0'+(nodeInfos[nodeIndex].vcc/10)%10;
    output_verbose[34] = '0'+(nodeInfos[nodeIndex].vcc%10);
    output_verbose[7] = addrString[0];
    output_verbose[8] = addrString[1];
    output_verbose[9] = addrString[2];
    output_verbose[10] = addrString[3];
    HalUartTxString(output_verbose, sizeof output_verbose );
  }
  else
  {
    

    output_short[19] = rssiString[2];
    output_short[20] = rssiString[1];
    output_short[21] = rssiString[0];


    output_short[8] = temp_string[0];
    output_short[9] = temp_string[1];
    output_short[10] = temp_string[2];
    output_short[11] = temp_string[3];
    output_short[12] = temp_string[4];
    output_short[13] = temp_string[5];

    output_short[15] = '0'+((nodeInfos[nodeIndex].vcc/10)%10);
    output_short[17] = '0'+(nodeInfos[nodeIndex].vcc%10);
    output_short[3] = addrString[0];
    output_short[4] = addrString[1];
    output_short[5] = addrString[2];
    output_short[6] = addrString[3];
    HalUartTxString(output_short, sizeof output_short );
  }
  
}







