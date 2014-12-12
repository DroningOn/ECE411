/*******************************************************************************
 *
 *  main.c - Main() Launch Point
 *  Revision A
 *  Portland State University ECE411 T08 Dec2014
 *
 *  Acts as entry point to core program Base() after disabling the watch dog
 *  timer.
 *
 *  Inspiration for this application provided by:
 *  MspExp430F6137RxUserExperience - Main User Experience Application
 *  Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *******************************************************************************/
 
#include "cc430f6137.h" 

extern void Base(void);
void main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  Base();									// Launch core program
} 
