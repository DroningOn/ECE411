/*******************************************************************************
 *
 *  main.c - Main() Launch Point
 *  Revision A
 *  Portland State University ECE411 T08 Dec2014
 *
 *  Acts as entry point to core program Satellite() after disabling the watch dog
 *  timer.
 *
 *  Inspiration for this application provided by:
 *  MspExp430F5137RxUserExperience - Main User Experience Application
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *******************************************************************************/
 
#include "cc430f5137.h" 



extern void Satellite(void);

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  Satellite();								// Launch Core Program
} 
