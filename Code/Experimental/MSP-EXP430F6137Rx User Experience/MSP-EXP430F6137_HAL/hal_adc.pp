#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/MSP-EXP430F6137_HAL/hal_adc.c"


































 

#line 1 "c:/ti/ccsv6/ccs_base/msp430/include/msp430.h"





 





#line 1 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 























 











 
 
 


 



typedef void (* __SFR_FARPTR)();








 

#line 103 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 

#line 117 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

#line 134 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\in430.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
 
 

#line 47 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\in430.h"

#line 136 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"
#line 1 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/intrinsics.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





void           _nop(void);
void           _enable_interrupts(void);
void           _disable_interrupts(void);
unsigned short _swap_bytes(unsigned short a);
unsigned short _bic_SR_register(unsigned short a);
unsigned short _bic_SR_register_on_exit(unsigned short a);
unsigned short _bis_SR_register(unsigned short);
unsigned short _bis_SR_register_on_exit(unsigned short a);
unsigned short _get_SR_register(void); 
unsigned short _get_SR_register_on_exit(void);
void           _never_executed(void );

unsigned short _bcd_add_short(unsigned short, unsigned short);
unsigned long  _bcd_add_long(unsigned long, unsigned long);

unsigned int   _even_in_range(unsigned int, unsigned int);
void           _op_code(unsigned short);
void           _data20_write_char(unsigned long, unsigned char);
void           _data20_write_short(unsigned long, unsigned short);
void           _data20_write_long(unsigned long, unsigned long);
unsigned char  _data20_read_char(unsigned long);
unsigned short _data20_read_short(unsigned long);
unsigned long  _data20_read_long(unsigned long);
unsigned short _get_interrupt_state(void);
void           _set_interrupt_state(unsigned short);
unsigned short _get_SP_register(void);
void           _set_SP_register(unsigned short);





 
#line 137 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 149 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 





 



 




extern volatile unsigned int ADC12CTL0;                          
extern volatile unsigned char ADC12CTL0_L;                         
extern volatile unsigned char ADC12CTL0_H;                         
extern volatile unsigned int ADC12CTL1;                          
extern volatile unsigned char ADC12CTL1_L;                         
extern volatile unsigned char ADC12CTL1_H;                         
extern volatile unsigned int ADC12CTL2;                          
extern volatile unsigned char ADC12CTL2_L;                         
extern volatile unsigned char ADC12CTL2_H;                         
extern volatile unsigned int ADC12IFG;                           
extern volatile unsigned char ADC12IFG_L;                          
extern volatile unsigned char ADC12IFG_H;                          
extern volatile unsigned int ADC12IE;                            
extern volatile unsigned char ADC12IE_L;                           
extern volatile unsigned char ADC12IE_H;                           
extern volatile unsigned int ADC12IV;                            
extern volatile unsigned char ADC12IV_L;                           
extern volatile unsigned char ADC12IV_H;                           

extern volatile unsigned int ADC12MEM0;                          
extern volatile unsigned char ADC12MEM0_L;                         
extern volatile unsigned char ADC12MEM0_H;                         
extern volatile unsigned int ADC12MEM1;                          
extern volatile unsigned char ADC12MEM1_L;                         
extern volatile unsigned char ADC12MEM1_H;                         
extern volatile unsigned int ADC12MEM2;                          
extern volatile unsigned char ADC12MEM2_L;                         
extern volatile unsigned char ADC12MEM2_H;                         
extern volatile unsigned int ADC12MEM3;                          
extern volatile unsigned char ADC12MEM3_L;                         
extern volatile unsigned char ADC12MEM3_H;                         
extern volatile unsigned int ADC12MEM4;                          
extern volatile unsigned char ADC12MEM4_L;                         
extern volatile unsigned char ADC12MEM4_H;                         
extern volatile unsigned int ADC12MEM5;                          
extern volatile unsigned char ADC12MEM5_L;                         
extern volatile unsigned char ADC12MEM5_H;                         
extern volatile unsigned int ADC12MEM6;                          
extern volatile unsigned char ADC12MEM6_L;                         
extern volatile unsigned char ADC12MEM6_H;                         
extern volatile unsigned int ADC12MEM7;                          
extern volatile unsigned char ADC12MEM7_L;                         
extern volatile unsigned char ADC12MEM7_H;                         
extern volatile unsigned int ADC12MEM8;                          
extern volatile unsigned char ADC12MEM8_L;                         
extern volatile unsigned char ADC12MEM8_H;                         
extern volatile unsigned int ADC12MEM9;                          
extern volatile unsigned char ADC12MEM9_L;                         
extern volatile unsigned char ADC12MEM9_H;                         
extern volatile unsigned int ADC12MEM10;                         
extern volatile unsigned char ADC12MEM10_L;                        
extern volatile unsigned char ADC12MEM10_H;                        
extern volatile unsigned int ADC12MEM11;                         
extern volatile unsigned char ADC12MEM11_L;                        
extern volatile unsigned char ADC12MEM11_H;                        
extern volatile unsigned int ADC12MEM12;                         
extern volatile unsigned char ADC12MEM12_L;                        
extern volatile unsigned char ADC12MEM12_H;                        
extern volatile unsigned int ADC12MEM13;                         
extern volatile unsigned char ADC12MEM13_L;                        
extern volatile unsigned char ADC12MEM13_H;                        
extern volatile unsigned int ADC12MEM14;                         
extern volatile unsigned char ADC12MEM14_L;                        
extern volatile unsigned char ADC12MEM14_H;                        
extern volatile unsigned int ADC12MEM15;                         
extern volatile unsigned char ADC12MEM15_L;                        
extern volatile unsigned char ADC12MEM15_H;                        
#line 240 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

extern volatile unsigned char ADC12MCTL0;                          
extern volatile unsigned char ADC12MCTL1;                          
extern volatile unsigned char ADC12MCTL2;                          
extern volatile unsigned char ADC12MCTL3;                          
extern volatile unsigned char ADC12MCTL4;                          
extern volatile unsigned char ADC12MCTL5;                          
extern volatile unsigned char ADC12MCTL6;                          
extern volatile unsigned char ADC12MCTL7;                          
extern volatile unsigned char ADC12MCTL8;                          
extern volatile unsigned char ADC12MCTL9;                          
extern volatile unsigned char ADC12MCTL10;                         
extern volatile unsigned char ADC12MCTL11;                         
extern volatile unsigned char ADC12MCTL12;                         
extern volatile unsigned char ADC12MCTL13;                         
extern volatile unsigned char ADC12MCTL14;                         
extern volatile unsigned char ADC12MCTL15;                         
#line 263 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 281 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 291 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 301 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 318 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 335 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 353 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 363 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 373 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"











#line 392 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






#line 414 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 424 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 433 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 







 
#line 451 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 468 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 477 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 494 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 503 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 512 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 529 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 538 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 547 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 568 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int AESACTL0;                           
extern volatile unsigned char AESACTL0_L;                          
extern volatile unsigned char AESACTL0_H;                          
extern volatile unsigned int AESASTAT;                           
extern volatile unsigned char AESASTAT_L;                          
extern volatile unsigned char AESASTAT_H;                          
extern volatile unsigned int AESAKEY;                            
extern volatile unsigned char AESAKEY_L;                           
extern volatile unsigned char AESAKEY_H;                           
extern volatile unsigned int AESADIN;                            
extern volatile unsigned char AESADIN_L;                           
extern volatile unsigned char AESADIN_H;                           
extern volatile unsigned int AESADOUT;                           
extern volatile unsigned char AESADOUT_L;                          
extern volatile unsigned char AESADOUT_H;                          

 
#line 599 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




 









 
#line 632 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 642 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 652 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int CBCTL0;                             
extern volatile unsigned char CBCTL0_L;                            
extern volatile unsigned char CBCTL0_H;                            
extern volatile unsigned int CBCTL1;                             
extern volatile unsigned char CBCTL1_L;                            
extern volatile unsigned char CBCTL1_H;                            
extern volatile unsigned int CBCTL2;                             
extern volatile unsigned char CBCTL2_L;                            
extern volatile unsigned char CBCTL2_H;                            
extern volatile unsigned int CBCTL3;                             
extern volatile unsigned char CBCTL3_L;                            
extern volatile unsigned char CBCTL3_H;                            
extern volatile unsigned int CBINT;                              
extern volatile unsigned char CBINT_L;                             
extern volatile unsigned char CBINT_H;                             
extern volatile unsigned int CBIV;                               

 

















 












 












#line 737 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 754 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 769 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 
#line 782 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 



















 
#line 823 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 833 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 843 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 876 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






#line 914 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






#line 936 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 945 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 954 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 















 















 






 




extern volatile unsigned int RF1AIFCTL0;                         
extern volatile unsigned char RF1AIFCTL0_L;                        
extern volatile unsigned char RF1AIFCTL0_H;                        
extern volatile unsigned int RF1AIFCTL1;                         
extern volatile unsigned char RF1AIFCTL1_L;                        
extern volatile unsigned char RF1AIFCTL1_H;                        


extern volatile unsigned int RF1AIFCTL2;                         
extern volatile unsigned char RF1AIFCTL2_L;                        
extern volatile unsigned char RF1AIFCTL2_H;                        
extern volatile unsigned int RF1AIFERR;                          
extern volatile unsigned char RF1AIFERR_L;                         
extern volatile unsigned char RF1AIFERR_H;                         
extern volatile unsigned int RF1AIFERRV;                         
extern volatile unsigned char RF1AIFERRV_L;                        
extern volatile unsigned char RF1AIFERRV_H;                        
extern volatile unsigned int RF1AIFIV;                           
extern volatile unsigned char RF1AIFIV_L;                          
extern volatile unsigned char RF1AIFIV_H;                          
extern volatile unsigned int RF1AINSTRW;                         
extern volatile unsigned char RF1AINSTRW_L;                        
extern volatile unsigned char RF1AINSTRW_H;                        


extern volatile unsigned int RF1AINSTR1W;                        
extern volatile unsigned char RF1AINSTR1W_L;                       
extern volatile unsigned char RF1AINSTR1W_H;                       

extern volatile unsigned int RF1AINSTR2W;                        
extern volatile unsigned char RF1AINSTR2W_L;                       
extern volatile unsigned char RF1AINSTR2W_H;                       

extern volatile unsigned int RF1ADINW;                           
extern volatile unsigned char RF1ADINW_L;                          
extern volatile unsigned char RF1ADINW_H;                          

extern volatile unsigned int RF1ASTAT0W;                         
extern volatile unsigned char RF1ASTAT0W_L;                        
extern volatile unsigned char RF1ASTAT0W_H;                        





extern volatile unsigned int RF1ASTAT1W;                         
extern volatile unsigned char RF1ASTAT1W_L;                        
extern volatile unsigned char RF1ASTAT1W_H;                        


extern volatile unsigned int RF1ASTAT2W;                         
extern volatile unsigned char RF1ASTAT2W_L;                        
extern volatile unsigned char RF1ASTAT2W_H;                        


extern volatile unsigned int RF1ADOUT0W;                         
extern volatile unsigned char RF1ADOUT0W_L;                        
extern volatile unsigned char RF1ADOUT0W_H;                        



extern volatile unsigned int RF1ADOUT1W;                         
extern volatile unsigned char RF1ADOUT1W_L;                        
extern volatile unsigned char RF1ADOUT1W_H;                        
extern volatile unsigned int RF1ADOUT2W;                         
extern volatile unsigned char RF1ADOUT2W_L;                        
extern volatile unsigned char RF1ADOUT2W_H;                        
extern volatile unsigned int RF1AIN;                             
extern volatile unsigned char RF1AIN_L;                            
extern volatile unsigned char RF1AIN_H;                            
extern volatile unsigned int RF1AIFG;                            
extern volatile unsigned char RF1AIFG_L;                           
extern volatile unsigned char RF1AIFG_H;                           
extern volatile unsigned int RF1AIES;                            
extern volatile unsigned char RF1AIES_L;                           
extern volatile unsigned char RF1AIES_H;                           
extern volatile unsigned int RF1AIE;                             
extern volatile unsigned char RF1AIE_L;                            
extern volatile unsigned char RF1AIE_H;                            
extern volatile unsigned int RF1AIV;                             
extern volatile unsigned char RF1AIV_L;                            
extern volatile unsigned char RF1AIV_H;                            
extern volatile unsigned int RF1ARXFIFO;                         
extern volatile unsigned char RF1ARXFIFO_L;                        
extern volatile unsigned char RF1ARXFIFO_H;                        
extern volatile unsigned int RF1ATXFIFO;                         
extern volatile unsigned char RF1ATXFIFO_L;                        
extern volatile unsigned char RF1ATXFIFO_H;                        

 



 



 
#line 1129 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1138 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1147 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 





 





 






 
#line 1174 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1193 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 1234 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 1242 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1256 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




 
 
#line 1271 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1278 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 
#line 1296 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int CRCDI;                              
extern volatile unsigned char CRCDI_L;                             
extern volatile unsigned char CRCDI_H;                             
extern volatile unsigned int CRCINIRES;                          
extern volatile unsigned char CRCINIRES_L;                         
extern volatile unsigned char CRCINIRES_H;                         



 




extern volatile unsigned int DMACTL0;                            
extern volatile unsigned char DMACTL0_L;                           
extern volatile unsigned char DMACTL0_H;                           
extern volatile unsigned int DMACTL1;                            
extern volatile unsigned char DMACTL1_L;                           
extern volatile unsigned char DMACTL1_H;                           
extern volatile unsigned int DMACTL2;                            
extern volatile unsigned char DMACTL2_L;                           
extern volatile unsigned char DMACTL2_H;                           
extern volatile unsigned int DMACTL3;                            
extern volatile unsigned char DMACTL3_L;                           
extern volatile unsigned char DMACTL3_H;                           
extern volatile unsigned int DMACTL4;                            
extern volatile unsigned char DMACTL4_L;                           
extern volatile unsigned char DMACTL4_H;                           
extern volatile unsigned int DMAIV;                              
extern volatile unsigned char DMAIV_L;                             
extern volatile unsigned char DMAIV_H;                             

extern volatile unsigned int DMA0CTL;                            
extern volatile unsigned char DMA0CTL_L;                           
extern volatile unsigned char DMA0CTL_H;                           
extern __SFR_FARPTR DMA0SA;                             
extern volatile unsigned int DMA0SAL;                            
extern __SFR_FARPTR DMA0DA;                             
extern volatile unsigned int DMA0DAL;                            
extern volatile unsigned int DMA0SZ;                             

extern volatile unsigned int DMA1CTL;                            
extern volatile unsigned char DMA1CTL_L;                           
extern volatile unsigned char DMA1CTL_H;                           
extern __SFR_FARPTR DMA1SA;                             
extern volatile unsigned int DMA1SAL;                            
extern __SFR_FARPTR DMA1DA;                             
extern volatile unsigned int DMA1DAL;                            
extern volatile unsigned int DMA1SZ;                             

extern volatile unsigned int DMA2CTL;                            
extern volatile unsigned char DMA2CTL_L;                           
extern volatile unsigned char DMA2CTL_H;                           
extern __SFR_FARPTR DMA2SA;                             
extern volatile unsigned int DMA2SAL;                            
extern __SFR_FARPTR DMA2DA;                             
extern volatile unsigned int DMA2DAL;                            
extern volatile unsigned int DMA2SZ;                             

 
#line 1375 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 






 






 






 






 




 




 
#line 1430 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1440 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 1449 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"
















#line 1473 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 





#line 1512 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1545 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1578 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1611 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1644 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1677 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int FCTL1;                              
extern volatile unsigned char FCTL1_L;                             
extern volatile unsigned char FCTL1_H;                             

extern volatile unsigned int FCTL3;                              
extern volatile unsigned char FCTL3_L;                             
extern volatile unsigned char FCTL3_H;                             
extern volatile unsigned int FCTL4;                              
extern volatile unsigned char FCTL4_L;                             
extern volatile unsigned char FCTL4_H;                             

#line 1702 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 









 









 
#line 1731 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


 
#line 1741 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


 





 







 




extern volatile unsigned int LCDBCTL0;                           
extern volatile unsigned char LCDBCTL0_L;                          
extern volatile unsigned char LCDBCTL0_H;                          
extern volatile unsigned int LCDBCTL1;                           
extern volatile unsigned char LCDBCTL1_L;                          
extern volatile unsigned char LCDBCTL1_H;                          
extern volatile unsigned int LCDBBLKCTL;                         
extern volatile unsigned char LCDBBLKCTL_L;                        
extern volatile unsigned char LCDBBLKCTL_H;                        
extern volatile unsigned int LCDBMEMCTL;                         
extern volatile unsigned char LCDBMEMCTL_L;                        
extern volatile unsigned char LCDBMEMCTL_H;                        
extern volatile unsigned int LCDBVCTL;                           
extern volatile unsigned char LCDBVCTL_L;                          
extern volatile unsigned char LCDBVCTL_H;                          
extern volatile unsigned int LCDBPCTL0;                          
extern volatile unsigned char LCDBPCTL0_L;                         
extern volatile unsigned char LCDBPCTL0_H;                         
extern volatile unsigned int LCDBPCTL1;                          
extern volatile unsigned char LCDBPCTL1_L;                         
extern volatile unsigned char LCDBPCTL1_H;                         
extern volatile unsigned int LCDBPCTL2;                          
extern volatile unsigned char LCDBPCTL2_L;                         
extern volatile unsigned char LCDBPCTL2_H;                         
extern volatile unsigned int LCDBPCTL3;                          
extern volatile unsigned char LCDBPCTL3_L;                         
extern volatile unsigned char LCDBPCTL3_H;                         
extern volatile unsigned int LCDBCPCTL;                          
extern volatile unsigned char LCDBCPCTL_L;                         
extern volatile unsigned char LCDBCPCTL_H;                         
extern volatile unsigned int LCDBIV;                             








#line 1810 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"













#line 1831 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1844 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1909 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 






#line 1925 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"














#line 1947 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 1957 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






#line 1971 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1980 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1989 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 1998 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"












#line 2022 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2032 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"







 





 
#line 2062 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2079 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2097 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2107 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2117 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2135 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2145 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2155 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2173 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2183 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2193 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"












#line 2214 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2224 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




extern volatile unsigned char LCDM1;                               
#line 2235 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"
extern volatile unsigned char LCDM2;                               
extern volatile unsigned char LCDM3;                               
extern volatile unsigned char LCDM4;                               
extern volatile unsigned char LCDM5;                               
extern volatile unsigned char LCDM6;                               
extern volatile unsigned char LCDM7;                               
extern volatile unsigned char LCDM8;                               
extern volatile unsigned char LCDM9;                               
extern volatile unsigned char LCDM10;                              
extern volatile unsigned char LCDM11;                              
extern volatile unsigned char LCDM12;                              
extern volatile unsigned char LCDM13;                              
extern volatile unsigned char LCDM14;                              
extern volatile unsigned char LCDM15;                              
extern volatile unsigned char LCDM16;                              
extern volatile unsigned char LCDM17;                              
extern volatile unsigned char LCDM18;                              
extern volatile unsigned char LCDM19;                              
extern volatile unsigned char LCDM20;                              
extern volatile unsigned char LCDM21;                              
extern volatile unsigned char LCDM22;                              
extern volatile unsigned char LCDM23;                              
extern volatile unsigned char LCDM24;                              

extern volatile unsigned char LCDBM1;                              
#line 2266 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"
extern volatile unsigned char LCDBM2;                              
extern volatile unsigned char LCDBM3;                              
extern volatile unsigned char LCDBM4;                              
extern volatile unsigned char LCDBM5;                              
extern volatile unsigned char LCDBM6;                              
extern volatile unsigned char LCDBM7;                              
extern volatile unsigned char LCDBM8;                              
extern volatile unsigned char LCDBM9;                              
extern volatile unsigned char LCDBM10;                             
extern volatile unsigned char LCDBM11;                             
extern volatile unsigned char LCDBM12;                             
extern volatile unsigned char LCDBM13;                             
extern volatile unsigned char LCDBM14;                             
extern volatile unsigned char LCDBM15;                             
extern volatile unsigned char LCDBM16;                             
extern volatile unsigned char LCDBM17;                             
extern volatile unsigned char LCDBM18;                             
extern volatile unsigned char LCDBM19;                             
extern volatile unsigned char LCDBM20;                             
extern volatile unsigned char LCDBM21;                             
extern volatile unsigned char LCDBM22;                             
extern volatile unsigned char LCDBM23;                             
extern volatile unsigned char LCDBM24;                             

 








 




extern volatile unsigned int MPY;                                
extern volatile unsigned char MPY_L;                               
extern volatile unsigned char MPY_H;                               
extern volatile unsigned int MPYS;                               
extern volatile unsigned char MPYS_L;                              
extern volatile unsigned char MPYS_H;                              
extern volatile unsigned int MAC;                                
extern volatile unsigned char MAC_L;                               
extern volatile unsigned char MAC_H;                               
extern volatile unsigned int MACS;                               
extern volatile unsigned char MACS_L;                              
extern volatile unsigned char MACS_H;                              
extern volatile unsigned int OP2;                                
extern volatile unsigned char OP2_L;                               
extern volatile unsigned char OP2_H;                               
extern volatile unsigned int RESLO;                              
extern volatile unsigned char RESLO_L;                             
extern volatile unsigned char RESLO_H;                             
extern volatile unsigned int RESHI;                              
extern volatile unsigned char RESHI_L;                             
extern volatile unsigned char RESHI_H;                             
extern volatile unsigned int SUMEXT;                             
extern volatile unsigned char SUMEXT_L;                            
extern volatile unsigned char SUMEXT_H;                            

extern volatile unsigned int MPY32L;                             
extern volatile unsigned char MPY32L_L;                            
extern volatile unsigned char MPY32L_H;                            
extern volatile unsigned int MPY32H;                             
extern volatile unsigned char MPY32H_L;                            
extern volatile unsigned char MPY32H_H;                            
extern volatile unsigned int MPYS32L;                            
extern volatile unsigned char MPYS32L_L;                           
extern volatile unsigned char MPYS32L_H;                           
extern volatile unsigned int MPYS32H;                            
extern volatile unsigned char MPYS32H_L;                           
extern volatile unsigned char MPYS32H_H;                           
extern volatile unsigned int MAC32L;                             
extern volatile unsigned char MAC32L_L;                            
extern volatile unsigned char MAC32L_H;                            
extern volatile unsigned int MAC32H;                             
extern volatile unsigned char MAC32H_L;                            
extern volatile unsigned char MAC32H_H;                            
extern volatile unsigned int MACS32L;                            
extern volatile unsigned char MACS32L_L;                           
extern volatile unsigned char MACS32L_H;                           
extern volatile unsigned int MACS32H;                            
extern volatile unsigned char MACS32H_L;                           
extern volatile unsigned char MACS32H_H;                           
extern volatile unsigned int OP2L;                               
extern volatile unsigned char OP2L_L;                              
extern volatile unsigned char OP2L_H;                              
extern volatile unsigned int OP2H;                               
extern volatile unsigned char OP2H_L;                              
extern volatile unsigned char OP2H_H;                              
extern volatile unsigned int RES0;                               
extern volatile unsigned char RES0_L;                              
extern volatile unsigned char RES0_H;                              
extern volatile unsigned int RES1;                               
extern volatile unsigned char RES1_L;                              
extern volatile unsigned char RES1_H;                              
extern volatile unsigned int RES2;                               
extern volatile unsigned char RES2_L;                              
extern volatile unsigned char RES2_H;                              
extern volatile unsigned int RES3;                               
extern volatile unsigned char RES3_L;                              
extern volatile unsigned char RES3_H;                              
extern volatile unsigned int MPY32CTL0;                          
extern volatile unsigned char MPY32CTL0_L;                         
extern volatile unsigned char MPY32CTL0_H;                         

#line 2390 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 


#line 2402 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 


#line 2412 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




#line 2426 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 
#line 2442 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

extern volatile unsigned int PAIN;                               
extern volatile unsigned char PAIN_L;                              
extern volatile unsigned char PAIN_H;                              
extern volatile unsigned int PAOUT;                              
extern volatile unsigned char PAOUT_L;                             
extern volatile unsigned char PAOUT_H;                             
extern volatile unsigned int PADIR;                              
extern volatile unsigned char PADIR_L;                             
extern volatile unsigned char PADIR_H;                             
extern volatile unsigned int PAREN;                              
extern volatile unsigned char PAREN_L;                             
extern volatile unsigned char PAREN_H;                             
extern volatile unsigned int PADS;                               
extern volatile unsigned char PADS_L;                              
extern volatile unsigned char PADS_H;                              
extern volatile unsigned int PASEL;                              
extern volatile unsigned char PASEL_L;                             
extern volatile unsigned char PASEL_H;                             
extern volatile unsigned int PAIES;                              
extern volatile unsigned char PAIES_L;                             
extern volatile unsigned char PAIES_H;                             
extern volatile unsigned int PAIE;                               
extern volatile unsigned char PAIE_L;                              
extern volatile unsigned char PAIE_H;                              
extern volatile unsigned int PAIFG;                              
extern volatile unsigned char PAIFG_L;                             
extern volatile unsigned char PAIFG_H;                             


extern volatile unsigned int P1IV;                               
extern volatile unsigned int P2IV;                               
#line 2483 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2494 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2504 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 2515 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 
#line 2532 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

extern volatile unsigned int PBIN;                               
extern volatile unsigned char PBIN_L;                              
extern volatile unsigned char PBIN_H;                              
extern volatile unsigned int PBOUT;                              
extern volatile unsigned char PBOUT_L;                             
extern volatile unsigned char PBOUT_H;                             
extern volatile unsigned int PBDIR;                              
extern volatile unsigned char PBDIR_L;                             
extern volatile unsigned char PBDIR_H;                             
extern volatile unsigned int PBREN;                              
extern volatile unsigned char PBREN_L;                             
extern volatile unsigned char PBREN_H;                             
extern volatile unsigned int PBDS;                               
extern volatile unsigned char PBDS_L;                              
extern volatile unsigned char PBDS_H;                              
extern volatile unsigned int PBSEL;                              
extern volatile unsigned char PBSEL_L;                             
extern volatile unsigned char PBSEL_H;                             


#line 2559 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2566 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 
#line 2579 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

extern volatile unsigned int PCIN;                               
extern volatile unsigned char PCIN_L;                              
extern volatile unsigned char PCIN_H;                              
extern volatile unsigned int PCOUT;                              
extern volatile unsigned char PCOUT_L;                             
extern volatile unsigned char PCOUT_H;                             
extern volatile unsigned int PCDIR;                              
extern volatile unsigned char PCDIR_L;                             
extern volatile unsigned char PCDIR_H;                             
extern volatile unsigned int PCREN;                              
extern volatile unsigned char PCREN_L;                             
extern volatile unsigned char PCREN_H;                             
extern volatile unsigned int PCDS;                               
extern volatile unsigned char PCDS_L;                              
extern volatile unsigned char PCDS_H;                              
extern volatile unsigned int PCSEL;                              
extern volatile unsigned char PCSEL_L;                             
extern volatile unsigned char PCSEL_H;                             


#line 2606 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 




extern volatile unsigned int PJIN;                               
extern volatile unsigned char PJIN_L;                              
extern volatile unsigned char PJIN_H;                              
extern volatile unsigned int PJOUT;                              
extern volatile unsigned char PJOUT_L;                             
extern volatile unsigned char PJOUT_H;                             
extern volatile unsigned int PJDIR;                              
extern volatile unsigned char PJDIR_L;                             
extern volatile unsigned char PJDIR_H;                             
extern volatile unsigned int PJREN;                              
extern volatile unsigned char PJREN_L;                             
extern volatile unsigned char PJREN_H;                             
extern volatile unsigned int PJDS;                               
extern volatile unsigned char PJDS_L;                              
extern volatile unsigned char PJDS_H;                              



 




extern volatile unsigned int PMAPKEYID;                          
extern volatile unsigned char PMAPKEYID_L;                         
extern volatile unsigned char PMAPKEYID_H;                         
extern volatile unsigned int PMAPCTL;                            
extern volatile unsigned char PMAPCTL_L;                           
extern volatile unsigned char PMAPCTL_H;                           





 



 





 




extern volatile unsigned int P1MAP01;                            
extern volatile unsigned char P1MAP01_L;                           
extern volatile unsigned char P1MAP01_H;                           
extern volatile unsigned int P1MAP23;                            
extern volatile unsigned char P1MAP23_L;                           
extern volatile unsigned char P1MAP23_H;                           
extern volatile unsigned int P1MAP45;                            
extern volatile unsigned char P1MAP45_L;                           
extern volatile unsigned char P1MAP45_H;                           
extern volatile unsigned int P1MAP67;                            
extern volatile unsigned char P1MAP67_L;                           
extern volatile unsigned char P1MAP67_H;                           

#line 2685 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int P2MAP01;                            
extern volatile unsigned char P2MAP01_L;                           
extern volatile unsigned char P2MAP01_H;                           
extern volatile unsigned int P2MAP23;                            
extern volatile unsigned char P2MAP23_L;                           
extern volatile unsigned char P2MAP23_H;                           
extern volatile unsigned int P2MAP45;                            
extern volatile unsigned char P2MAP45_L;                           
extern volatile unsigned char P2MAP45_H;                           
extern volatile unsigned int P2MAP67;                            
extern volatile unsigned char P2MAP67_L;                           
extern volatile unsigned char P2MAP67_H;                           

#line 2714 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int P3MAP01;                            
extern volatile unsigned char P3MAP01_L;                           
extern volatile unsigned char P3MAP01_H;                           
extern volatile unsigned int P3MAP23;                            
extern volatile unsigned char P3MAP23_L;                           
extern volatile unsigned char P3MAP23_H;                           
extern volatile unsigned int P3MAP45;                            
extern volatile unsigned char P3MAP45_L;                           
extern volatile unsigned char P3MAP45_H;                           
extern volatile unsigned int P3MAP67;                            
extern volatile unsigned char P3MAP67_L;                           
extern volatile unsigned char P3MAP67_H;                           

#line 2743 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2780 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int PMMCTL0;                            
extern volatile unsigned char PMMCTL0_L;                           
extern volatile unsigned char PMMCTL0_H;                           
extern volatile unsigned int PMMCTL1;                            
extern volatile unsigned char PMMCTL1_L;                           
extern volatile unsigned char PMMCTL1_H;                           
extern volatile unsigned int SVSMHCTL;                           
extern volatile unsigned char SVSMHCTL_L;                          
extern volatile unsigned char SVSMHCTL_H;                          
extern volatile unsigned int SVSMLCTL;                           
extern volatile unsigned char SVSMLCTL_L;                          
extern volatile unsigned char SVSMLCTL_H;                          
extern volatile unsigned int SVSMIO;                             
extern volatile unsigned char SVSMIO_L;                            
extern volatile unsigned char SVSMIO_H;                            
extern volatile unsigned int PMMIFG;                             
extern volatile unsigned char PMMIFG_L;                            
extern volatile unsigned char PMMIFG_H;                            
extern volatile unsigned int PMMRIE;                             
extern volatile unsigned char PMMRIE_L;                            
extern volatile unsigned char PMMRIE_H;                            




 
#line 2820 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2828 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






 




 




 
#line 2859 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2868 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2877 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2886 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






 
#line 2907 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2916 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2925 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 2934 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






 






 




 



 
#line 2969 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2977 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 2985 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 
#line 2999 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3007 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 







 




extern volatile unsigned int RCCTL0;                             
extern volatile unsigned char RCCTL0_L;                            
extern volatile unsigned char RCCTL0_H;                            

 





 









 




extern volatile unsigned int REFCTL0;                            
extern volatile unsigned char REFCTL0_L;                           
extern volatile unsigned char REFCTL0_H;                           

 

















 













 


















 




extern volatile unsigned int RTCCTL01;                           
extern volatile unsigned char RTCCTL01_L;                          
extern volatile unsigned char RTCCTL01_H;                          
extern volatile unsigned int RTCCTL23;                           
extern volatile unsigned char RTCCTL23_L;                          
extern volatile unsigned char RTCCTL23_H;                          
extern volatile unsigned int RTCPS0CTL;                          
extern volatile unsigned char RTCPS0CTL_L;                         
extern volatile unsigned char RTCPS0CTL_H;                         
extern volatile unsigned int RTCPS1CTL;                          
extern volatile unsigned char RTCPS1CTL_L;                         
extern volatile unsigned char RTCPS1CTL_H;                         
extern volatile unsigned int RTCPS;                              
extern volatile unsigned char RTCPS_L;                             
extern volatile unsigned char RTCPS_H;                             
extern volatile unsigned int RTCIV;                              
extern volatile unsigned int RTCTIM0;                            
extern volatile unsigned char RTCTIM0_L;                           
extern volatile unsigned char RTCTIM0_H;                           
extern volatile unsigned int RTCTIM1;                            
extern volatile unsigned char RTCTIM1_L;                           
extern volatile unsigned char RTCTIM1_H;                           
extern volatile unsigned int RTCDATE;                            
extern volatile unsigned char RTCDATE_L;                           
extern volatile unsigned char RTCDATE_H;                           
extern volatile unsigned int RTCYEAR;                            
extern volatile unsigned char RTCYEAR_L;                           
extern volatile unsigned char RTCYEAR_H;                           
extern volatile unsigned int RTCAMINHR;                          
extern volatile unsigned char RTCAMINHR_L;                         
extern volatile unsigned char RTCAMINHR_H;                         
extern volatile unsigned int RTCADOWDAY;                         
extern volatile unsigned char RTCADOWDAY_L;                        
extern volatile unsigned char RTCADOWDAY_H;                        

#line 3165 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3175 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"









 









 
#line 3203 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



#line 3221 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




#line 3233 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 


#line 3243 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 











 

















 












 












#line 3308 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 3317 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 











 












#line 3369 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 3378 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"






 
#line 3391 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3399 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"





 




extern volatile unsigned int SFRIE1;                             
extern volatile unsigned char SFRIE1_L;                            
extern volatile unsigned char SFRIE1_H;                            

 


















extern volatile unsigned int SFRIFG1;                            
extern volatile unsigned char SFRIFG1_L;                           
extern volatile unsigned char SFRIFG1_H;                           
 


















extern volatile unsigned int SFRRPCR;                            
extern volatile unsigned char SFRRPCR_L;                           
extern volatile unsigned char SFRRPCR_H;                           
 












 




extern volatile unsigned int SYSCTL;                             
extern volatile unsigned char SYSCTL_L;                            
extern volatile unsigned char SYSCTL_H;                            
extern volatile unsigned int SYSBSLC;                            
extern volatile unsigned char SYSBSLC_L;                           
extern volatile unsigned char SYSBSLC_H;                           
extern volatile unsigned int SYSJMBC;                            
extern volatile unsigned char SYSJMBC_L;                           
extern volatile unsigned char SYSJMBC_H;                           
extern volatile unsigned int SYSJMBI0;                           
extern volatile unsigned char SYSJMBI0_L;                          
extern volatile unsigned char SYSJMBI0_H;                          
extern volatile unsigned int SYSJMBI1;                           
extern volatile unsigned char SYSJMBI1_L;                          
extern volatile unsigned char SYSJMBI1_H;                          
extern volatile unsigned int SYSJMBO0;                           
extern volatile unsigned char SYSJMBO0_L;                          
extern volatile unsigned char SYSJMBO0_H;                          
extern volatile unsigned int SYSJMBO1;                           
extern volatile unsigned char SYSJMBO1_L;                          
extern volatile unsigned char SYSJMBO1_H;                          

extern volatile unsigned int SYSBERRIV;                          
extern volatile unsigned char SYSBERRIV_L;                         
extern volatile unsigned char SYSBERRIV_H;                         
extern volatile unsigned int SYSUNIV;                            
extern volatile unsigned char SYSUNIV_L;                           
extern volatile unsigned char SYSUNIV_H;                           
extern volatile unsigned int SYSSNIV;                            
extern volatile unsigned char SYSSNIV_L;                           
extern volatile unsigned char SYSSNIV_H;                           
extern volatile unsigned int SYSRSTIV;                           
extern volatile unsigned char SYSRSTIV_L;                          
extern volatile unsigned char SYSRSTIV_H;                          

 

















 

















 

















 















 














 

















 


















 






 
#line 3650 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3669 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"





 




extern volatile unsigned int TA0CTL;                             
extern volatile unsigned int TA0CCTL0;                           
extern volatile unsigned int TA0CCTL1;                           
extern volatile unsigned int TA0CCTL2;                           
extern volatile unsigned int TA0CCTL3;                           
extern volatile unsigned int TA0CCTL4;                           
extern volatile unsigned int TA0R;                               
extern volatile unsigned int TA0CCR0;                            
extern volatile unsigned int TA0CCR1;                            
extern volatile unsigned int TA0CCR2;                            
extern volatile unsigned int TA0CCR3;                            
extern volatile unsigned int TA0CCR4;                            
extern volatile unsigned int TA0IV;                              
extern volatile unsigned int TA0EX0;                             

 
#line 3704 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 3730 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3747 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 3764 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




#line 3778 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3788 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 








 




extern volatile unsigned int TA1CTL;                             
extern volatile unsigned int TA1CCTL0;                           
extern volatile unsigned int TA1CCTL1;                           
extern volatile unsigned int TA1CCTL2;                           
extern volatile unsigned int TA1R;                               
extern volatile unsigned int TA1CCR0;                            
extern volatile unsigned int TA1CCR1;                            
extern volatile unsigned int TA1CCR2;                            
extern volatile unsigned int TA1IV;                              
extern volatile unsigned int TA1EX0;                             

 

 
#line 3825 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 






 




extern volatile unsigned int UCSCTL0;                            
extern volatile unsigned char UCSCTL0_L;                           
extern volatile unsigned char UCSCTL0_H;                           
extern volatile unsigned int UCSCTL1;                            
extern volatile unsigned char UCSCTL1_L;                           
extern volatile unsigned char UCSCTL1_H;                           
extern volatile unsigned int UCSCTL2;                            
extern volatile unsigned char UCSCTL2_L;                           
extern volatile unsigned char UCSCTL2_H;                           
extern volatile unsigned int UCSCTL3;                            
extern volatile unsigned char UCSCTL3_L;                           
extern volatile unsigned char UCSCTL3_H;                           
extern volatile unsigned int UCSCTL4;                            
extern volatile unsigned char UCSCTL4_L;                           
extern volatile unsigned char UCSCTL4_H;                           
extern volatile unsigned int UCSCTL5;                            
extern volatile unsigned char UCSCTL5_L;                           
extern volatile unsigned char UCSCTL5_H;                           
extern volatile unsigned int UCSCTL6;                            
extern volatile unsigned char UCSCTL6_L;                           
extern volatile unsigned char UCSCTL6_H;                           
extern volatile unsigned int UCSCTL7;                            
extern volatile unsigned char UCSCTL7_L;                           
extern volatile unsigned char UCSCTL7_H;                           
extern volatile unsigned int UCSCTL8;                            
extern volatile unsigned char UCSCTL8_L;                           
extern volatile unsigned char UCSCTL8_H;                           

 



#line 3880 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 












 












 

















 

















#line 3954 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 3966 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"







 
#line 3982 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"




 









#line 4010 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 

















#line 4072 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 














 











#line 4132 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4147 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4162 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 











 











#line 4219 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4234 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4249 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4264 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4275 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"








 
#line 4292 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"








 









#line 4318 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 

















 

















 

















 



















 




extern volatile unsigned int UCA0CTLW0;                          
extern volatile unsigned char UCA0CTLW0_L;                         
extern volatile unsigned char UCA0CTLW0_H;                         


extern volatile unsigned int UCA0BRW;                            
extern volatile unsigned char UCA0BRW_L;                           
extern volatile unsigned char UCA0BRW_H;                           


extern volatile unsigned char UCA0MCTL;                            
extern volatile unsigned char UCA0STAT;                            
extern volatile unsigned char UCA0RXBUF;                           
extern volatile unsigned char UCA0TXBUF;                           
extern volatile unsigned char UCA0ABCTL;                           
extern volatile unsigned int UCA0IRCTL;                          
extern volatile unsigned char UCA0IRCTL_L;                         
extern volatile unsigned char UCA0IRCTL_H;                         


extern volatile unsigned int UCA0ICTL;                           
extern volatile unsigned char UCA0ICTL_L;                          
extern volatile unsigned char UCA0ICTL_H;                          


extern volatile unsigned int UCA0IV;                             




 





extern volatile unsigned int UCB0CTLW0;                          
extern volatile unsigned char UCB0CTLW0_L;                         
extern volatile unsigned char UCB0CTLW0_H;                         


extern volatile unsigned int UCB0BRW;                            
extern volatile unsigned char UCB0BRW_L;                           
extern volatile unsigned char UCB0BRW_H;                           


extern volatile unsigned char UCB0STAT;                            
extern volatile unsigned char UCB0RXBUF;                           
extern volatile unsigned char UCB0TXBUF;                           
extern volatile unsigned int UCB0I2COA;                          
extern volatile unsigned char UCB0I2COA_L;                         
extern volatile unsigned char UCB0I2COA_H;                         
extern volatile unsigned int UCB0I2CSA;                          
extern volatile unsigned char UCB0I2CSA_L;                         
extern volatile unsigned char UCB0I2CSA_H;                         
extern volatile unsigned int UCB0ICTL;                           
extern volatile unsigned char UCB0ICTL_L;                          
extern volatile unsigned char UCB0ICTL_H;                          


extern volatile unsigned int UCB0IV;                             


#line 4469 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

















#line 4494 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"










#line 4515 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4525 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4542 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4551 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4562 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




 
#line 4577 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4587 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 









 
#line 4610 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4620 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 




 
#line 4637 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4647 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 



 



 
#line 4663 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 



 
#line 4675 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4686 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 




extern volatile unsigned int WDTCTL;                             
extern volatile unsigned char WDTCTL_L;                            
extern volatile unsigned char WDTCTL_H;                            
 
 
#line 4707 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
#line 4717 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



#line 4736 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

#line 4744 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"

 
 




 




 
 




 








 






#line 4792 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 

#pragma diag_suppress 1107
#line 4806 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"


#line 4903 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\cc430f6137.h"



 







#line 803 "c:/ti/ccsv6/ccs_base/msp430/include/msp430.h"

#line 1714 "c:/ti/ccsv6/ccs_base/msp430/include/msp430.h"



#line 38 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/MSP-EXP430F6137_HAL/hal_adc.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\MSP-EXP430F6137_HAL\\hal_adc.h"


































 

















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
#line 39 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/MSP-EXP430F6137_HAL/hal_adc.c"

volatile unsigned long SavedADC12MEM0 = 0;
volatile signed int SavedADC12MEM1 = 0;
volatile unsigned long SavedADC12MEM2 = 0;

volatile signed int IntDegC, IntDegF;
volatile unsigned long Vcc = 0;
volatile unsigned long lightSensor;

unsigned char exit_active_from_ADC12 = 0;
int CAL_ADC_20T30, CAL_ADC_20T85;
float m = 0, c = 0;










#pragma DATA_SECTION(adcTemp25Calibration, ".infoB");
int adcTemp25Calibration;









unsigned char adcValuesJustUpdated = 0;


 






 
void HalAdcInit(void)
{
  

  
  (PASEL_H) |= (0x0010);
  (PADIR_H) &= ~(0x0010);
  
  
  
  UCSCTL8 |= (0x0008);
  REFCTL0 &= ~(0x0030);
  REFCTL0 |= (0x0010) + (0x0001);                  
  __delay_cycles(1900);                          

  ADC12CTL0 &= ~(0x0002);                        
  ADC12CTL0 = (0x0010) + (15*0x100u) + (0x0080);  
  ADC12CTL1 = (0x0200) + (1*2u) + (0*8u);  
  ADC12CTL2 = (0x0020);    
  ADC12MCTL0 = (1*0x10u) + (0x0004);
  ADC12MCTL1 = (1*0x10u) + (0x000A);
  ADC12MCTL2 = (1*0x10u) + (0x000B) + (0x0080);
  ADC12IE = 0x00;    
     
  
  
  
  

 
  CAL_ADC_20T30 = 1650;
  CAL_ADC_20T85 = (*(int *)0x01A20); 
  
  if ( ((unsigned int)adcTemp25Calibration) == 0xFFFF  )
  {
    m = (85-30)/(float)(CAL_ADC_20T85 - CAL_ADC_20T30); 
    c = 85 - m*CAL_ADC_20T85;
  }
  else
  {
    
    
    m = (85-25)/(float)(CAL_ADC_20T85 - adcTemp25Calibration); 
    c = 85 - m*CAL_ADC_20T85;  
  }   
                            
}


 





 
unsigned long HalAdcGetLightSensor(void)
{
  return SavedADC12MEM0;  
}


 





 
 
int HalAdcGetTempRaw(void)
{
  return SavedADC12MEM1;   
} 
 





 
int HalAdcGetTempDegC(void)
{
  return IntDegC;  
}

 





 
int HalAdcGetTempDegF(void)
{
  return IntDegF;  
}
 





 
unsigned long HalAdcGetVcc(void)
{
  return Vcc;  
}


 





 
void HalAdcShutDown(void)
{
  
  ADC12CTL0 &= ~(0x0002);
  ADC12CTL0 = 0x00;
  ADC12IE = 0x00;
  REFCTL0 &= ~(0x0001);
  (PADIR_H) &= ~(0x0010);
  (PASEL_H) &= ~(0x0010);      
}


 





 
void HalAdcConvertTempVcc(void)
{
  IntDegF = 10*(SavedADC12MEM1*m + c)*((float)9/5) + 320;
  IntDegC = 10*(SavedADC12MEM1*m + c);    
  Vcc = (SavedADC12MEM2 * 40) >> 12;  
}



 
 





 
void HalAdcStartRead(void)
{
  ADC12IFG = 0x00;                          
  REFCTL0 |= (0x0001);               
  __delay_cycles(1900);                   
  ADC12IE = (0x0004);                         
  ADC12CTL0 |= (0x0002) | (0x0001) ;       
}
 









 
void HalAdcSetQuitFromISR(unsigned char quit)
{
  exit_active_from_ADC12 = quit;  
}


unsigned char HalAdcJustUpdated(void)
{
  unsigned char temp;
  temp = adcValuesJustUpdated;
  adcValuesJustUpdated = 0;
  return temp;  
}


 
#pragma vector=(56 * 1u)
__interrupt void ADC12_ISR(void)
{

  adcValuesJustUpdated = 1;
  ADC12CTL0 &= ~(0x0002);                 
  REFCTL0 &= ~(0x0001);                      
    
  SavedADC12MEM0 = ADC12MEM0;             
  SavedADC12MEM1 = ADC12MEM1;
  SavedADC12MEM2 = ADC12MEM2;
  
    if (exit_active_from_ADC12) 
      __bic_SR_register_on_exit(((0x0080)+(0x0040)+(0x0010)));

   
}



