/*******************************************************************************
 *
 *  hal_adc.h - Hardware Abstraction Layer APIs header for the ADC module
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
#ifndef HAL_ADC_H
#define HAL_ADC_H

#define TEMP_CHANNEL                        ADC12INCH_10
#define VCC_CHANNEL                         ADC12INCH_11


#define LIGHT_SENSOR_PORT_SEL               P2SEL
#define LIGHT_SENSOR_PORT_DIR               P2DIR
#define LIGHT_SENSOR_PIN                    BIT4
#define LIGHT_SENSOR_CHANNEL                ADC12INCH_4
#define LIGHT_SENSOR_THRESHOLD              1500





void HalAdcSetQuitFromISR(unsigned char quit);
void HalAdcStartRead(void);
void HalAdcConvertTempVcc(void);
void HalAdcInit(void);
unsigned long HalAdcGetVcc(void);
int HalAdcGetTempRaw(void);
int HalAdcGetTempDegC(void);
int HalAdcGetTempDegF(void);
unsigned long HalAdcGetLightSensor(void);
unsigned char HalAdcJustUpdated(void);
#endif
