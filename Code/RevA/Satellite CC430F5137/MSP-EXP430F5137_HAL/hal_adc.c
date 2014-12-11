/*******************************************************************************
 *
 *  hal_adc.c - Hardware Abstraction Layer APIs for the ADC module
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

#include "msp430.h"
#include "hal_adc.h" 

volatile signed int SavedADC12MEM0 = 0;
volatile unsigned long  SavedADC12MEM1 = 0;

volatile signed int IntDegC, IntDegF;
volatile unsigned long Vcc = 0;

unsigned char exit_active_from_ADC12 = 0;
int CAL_ADC_20T30, CAL_ADC_20T85;
float m = 0, c = 0;


// Workaround for ADC29 erratum. Manual 25C [RoomTemp] calibration for 
// temp sensor to replace faulty 30C Cal value.
//--ADC software temperature calibration constant, workaround for ADC27 erratum 
//  regarding faulty temperature calibration constant, is stored in INFOB

// Perform manual SW calibration if the default cal value is faulty

#ifdef __TI_COMPILER_VERSION__
// If CCS compiler is used
#pragma DATA_SECTION(adcTemp25Calibration, ".infoB");
int adcTemp25Calibration;

#elif __IAR_SYSTEMS_ICC__
// If IAR compiler is used
#define INFOB _Pragma("location=\"INFOB\"")
INFOB __no_init int adcTemp25Calibration;
#endif

/**********************************************************************//**
 * @brief  Turns on and initializes ADC12 in order to 
 *         sample temperature, Vcc
 * 
 * @param  none
 * 
 * @return none
 *************************************************************************/
void HalAdcInit(void)
{  
  //Sequence of channels, once, ADC12CLK=MODOSC    
  UCSCTL8 |= MODOSCREQEN;
  REFCTL0 &= ~REFVSEL_3;
  REFCTL0 |= REFVSEL_1 + REFON;                  // Configure internal 2.5V reference
  __delay_cycles(1900);                          // delay for reference to settle                      

  ADC12CTL0 &= ~ADC12ENC;                        // Ensure ENC is clear
  ADC12CTL0 = ADC12ON + ADC12SHT0_15 + ADC12MSC;  
  ADC12CTL1 = ADC12SHP + ADC12CONSEQ_1 + ADC12SSEL_0;  
  ADC12CTL2 = ADC12RES_2;
  ADC12MCTL0 = ADC12SREF_1 + TEMP_CHANNEL;
  ADC12MCTL1 = ADC12SREF_1 + VCC_CHANNEL + ADC12EOS;
  ADC12IE = 0x00;    
 
  CAL_ADC_20T30 = (*(int *)0x01A1E); //ADC temp calibration consts for 2.0V ref
  CAL_ADC_20T85 = (*(int *)0x01A20); 
     
  if ( ((unsigned int)adcTemp25Calibration) == 0xFFFF  )
  {
    m = (85-30)/(float)(CAL_ADC_20T85 - CAL_ADC_20T30); //calculate the slope
    c = 85 - m*CAL_ADC_20T85;
  }
  else
  {
    // Calculate slope for 25C room temp 
    //CAL_ADC_20T30 = adcTemp25Calibration;
    m = (85-25)/(float)(CAL_ADC_20T85 - adcTemp25Calibration); //calculate the slope
    c = 85 - m*CAL_ADC_20T85;  
  }                 
}



/**********************************************************************//**
 * @brief  Return light sensor sampled value in degree Celsius 
 * 
 * @param  none
 * 
 * @return lightSensorValue     light sensor ADC sampled value
 *************************************************************************/
 
int HalAdcGetTempRaw(void)
{
  return SavedADC12MEM0;   
} 

/**********************************************************************//**
 * @brief  Return light sensor sampled value in degree Celsius 
 * 
 * @param  none
 * 
 * @return lightSensorValue     light sensor ADC sampled value
 *************************************************************************/
unsigned long HalAdcGetTempDegC(void)
{
  return IntDegC;  
}

/**********************************************************************//**
 * @brief  Return light sensor sampled value in degree Fahrenheit
 * 
 * @param  none
 * 
 * @return lightSensorValue     light sensor ADC sampled value
 *************************************************************************/
unsigned long HalAdcGetTempDegF(void)
{
  return IntDegF;  
}
/**********************************************************************//**
 * @brief  Return light sensor sampled value 
 * 
 * @param  none
 * 
 * @return lightSensorValue     light sensor ADC sampled value
 *************************************************************************/
unsigned long HalAdcGetVcc(void)
{
  return Vcc;  
}
/**********************************************************************//**
 * @brief  Turns off / disable the ADC12. 
 * 
 * @param  none
 * 
 * @return none
 *************************************************************************/
void halAdcShutDown(void)
{
  //Turn off ADC module and internal reference
  ADC12CTL0 &= ~ADC12ENC;
  ADC12CTL0 = 0x00;
  ADC12IE = 0x00;
  REFCTL0 &= ~REFON;        
}



/**********************************************************************//**
 * @brief  Converts the ADC readings into Vcc & Temp. 
 * 
 * @param  none
 * 
 * @return none
 *************************************************************************/
void HalAdcConvertTempVcc(void)
{
  IntDegF = 10*(SavedADC12MEM0*m + c) *((float)9/5) + 320;
  IntDegC = 10*(SavedADC12MEM0*m + c);  
  Vcc = (SavedADC12MEM1 * 40) >> 12;  
}

/*----------------------------------------------------------------------------*/
/**********************************************************************//**
 * @brief  Starts the ADC conversion.
 * 
 * @param  none
 * 
 * @return none
 *************************************************************************/
void HalAdcStartRead(void)
{
  ADC12IFG = 0x00;                          // Clear all ADC12 channel int flags 
  REFCTL0 |= REFON;               // Turn on ADC12 reference         
  __delay_cycles(1900);                   // delay for reference to settle
  ADC12IE = BIT1;                         // Enable memory 1 interrupt
  ADC12CTL0 |= ADC12ENC | ADC12SC ;       // Start conversion  
}
/**********************************************************************//**
 * @brief  Sets the flag that causes an exit into active CPU mode from 
 *         the ADC12 ISR.
 * 
 * @param  quit 
 * 
 * - 1 - Exit active from ADC12 ISR
 * - 0 - Remain in LPMx on exit from ADC12ISR
 * 
 * @return none
 *************************************************************************/
void HalAdcSetQuitFromISR(unsigned char quit)
{
  exit_active_from_ADC12 = quit;  
}

/*----------------------------------------------------------------------------*/
#pragma vector=ADC12_VECTOR
__interrupt void ADC12_ISR(void)
{


  ADC12CTL0 &= ~ADC12ENC;                 // Disable ADC12 conversions
  REFCTL0 &= ~REFON;                      // Disable reference (if enabled)     
    
  SavedADC12MEM0 = ADC12MEM0;             // Store the sampled data 
  SavedADC12MEM1 = ADC12MEM1;  
  
    if (exit_active_from_ADC12) 
      __bic_SR_register_on_exit(LPM3_bits);

   
}



