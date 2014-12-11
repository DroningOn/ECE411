#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"

































 




 

#line 1 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 





#line 50 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"
 






typedef unsigned size_t;


#line 1 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/linkage.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 




 





 
 
 
#line 59 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/linkage.h"

#line 61 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"

#line 69 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"

 size_t  strlen(const char *_string);

 char *strcpy(char *_dest, const char *_src);
 char *strncpy(char *_to, const char *_from, size_t _n);
 char *strcat(char *_string1, const char *_string2);
 char *strncat(char *_to, const char *_from, size_t _n);
 char *strchr(const char *_string, int _c);
 char *strrchr(const char *_string, int _c);

 int  strcmp(const char *_string1, const char *_string2);
 int  strncmp(const char *_string1, const char *_string2, size_t _n);

 int     strcoll(const char *_string1, const char *_string2);
 size_t  strxfrm(char *_to, const char *_from, size_t _n);
 char   *strpbrk(const char *_string, const char *_chs);
 size_t  strspn(const char *_string, const char *_chs);
 size_t  strcspn(const char *_string, const char *_chs);
 char   *strstr(const char *_string1, const char *_string2);
 char   *strtok(char *_str1, const char *_str2);
 char   *strerror(int _errno);

 void   *memmove(void *_s1, const void *_s2, size_t _n);
 void   *memcpy(void *_s1, const void *_s2, size_t _n);

 int     memcmp(const void *_cs, const void *_ct, size_t _n);
 void   *memchr(const void *_cs, int _c, size_t _n);

   void   *memset(void *_mem, int _ch, size_t _n);






#line 311 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"



#line 341 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/string.h"

#line 42 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"





























 





 








 
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/boards/MSP-EXP430F6137Rx/bsp_board_defs.h"





























 






 








 






 
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"






























 






 

#line 1 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 

    typedef   signed char    int8_t;
    typedef unsigned char   uint8_t;
    typedef          int    int16_t;
    typedef unsigned int   uint16_t;
    typedef          long   int32_t;
    typedef unsigned long  uint32_t;


    typedef          long long  int64_t;
    typedef unsigned long long uint64_t;

 

    typedef  int8_t   int_least8_t;
    typedef uint8_t  uint_least8_t;

    typedef  int16_t  int_least16_t;
    typedef uint16_t uint_least16_t;
    typedef  int32_t  int_least32_t;
    typedef uint32_t uint_least32_t;


    typedef  int64_t  int_least64_t;
    typedef uint64_t uint_least64_t;

 

    typedef  int16_t  int_fast8_t;
    typedef uint16_t uint_fast8_t;
    typedef  int16_t  int_fast16_t;
    typedef uint16_t uint_fast16_t;

    typedef  int32_t  int_fast32_t;
    typedef uint32_t uint_fast32_t;


    typedef  int64_t  int_fast64_t;
    typedef uint64_t uint_fast64_t;

 

    typedef          long intptr_t;
    typedef unsigned long uintptr_t;





 
    typedef          long long intmax_t;
    typedef unsigned long long uintmax_t;





 


 






















#line 130 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"






#line 142 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"










#line 161 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"





 









#line 183 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"








 







 

#line 207 "c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include/stdint.h"





 






#line 43 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"



 





 

 
#line 86 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"

 
#line 1 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 
 
 
 























 











 
 
 


 



typedef void (* __SFR_FARPTR)();








 

#line 109 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 

#line 123 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

#line 140 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\in430.h"
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



 
 
 

#line 47 "c:\\ti\\ccsv6\\ccs_base\\msp430\\include\\in430.h"

#line 142 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"
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





 
#line 143 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 155 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 





 



 




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
#line 246 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

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
#line 269 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 287 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 297 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 307 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 324 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 341 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 359 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 369 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 379 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"











#line 398 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






#line 420 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 430 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 439 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 







 
#line 457 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 474 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 483 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 500 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 509 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 518 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 535 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 544 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 553 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 574 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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

 
#line 605 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




 









 
#line 638 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 648 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 658 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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

 

















 












 












#line 743 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 760 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 775 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 
#line 788 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 



















 
#line 829 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 839 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 849 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 882 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






#line 920 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






#line 942 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 951 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 960 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 















 















 






 




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

 



 



 
#line 1135 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1144 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1153 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 





 





 






 
#line 1180 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1199 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 1240 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 1248 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1262 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




 
 
#line 1277 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1284 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 
#line 1302 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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

 
#line 1381 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 






 






 






 






 




 




 
#line 1436 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1446 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 1455 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"
















#line 1479 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 





#line 1518 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1551 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1584 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1617 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1650 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1683 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




extern volatile unsigned int FCTL1;                              
extern volatile unsigned char FCTL1_L;                             
extern volatile unsigned char FCTL1_H;                             

extern volatile unsigned int FCTL3;                              
extern volatile unsigned char FCTL3_L;                             
extern volatile unsigned char FCTL3_H;                             
extern volatile unsigned int FCTL4;                              
extern volatile unsigned char FCTL4_L;                             
extern volatile unsigned char FCTL4_H;                             

#line 1708 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 









 









 
#line 1737 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


 
#line 1747 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


 





 







 




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








#line 1816 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"













#line 1837 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1850 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1915 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 






#line 1931 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"














#line 1953 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 1963 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






#line 1977 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1986 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 1995 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2004 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"












#line 2028 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2038 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"







 





 
#line 2068 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2085 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2103 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2113 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2123 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2141 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2151 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2161 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2179 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2189 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2199 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"












#line 2220 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2230 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




extern volatile unsigned char LCDM1;                               
#line 2241 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"
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
#line 2272 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"
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

#line 2396 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 


#line 2408 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 


#line 2418 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




#line 2432 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 
#line 2448 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

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
#line 2489 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2500 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2510 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 2521 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 
#line 2538 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

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


#line 2565 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2572 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 
#line 2585 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

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


#line 2612 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 




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

#line 2691 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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

#line 2720 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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

#line 2749 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2786 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




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




 
#line 2826 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2834 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






 




 




 
#line 2865 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2874 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2883 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2892 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






 
#line 2913 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2922 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2931 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 2940 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






 






 




 



 
#line 2975 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2983 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 2991 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 
#line 3005 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3013 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 







 




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

#line 3171 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3181 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"









 









 
#line 3209 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



#line 3227 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




#line 3239 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 


#line 3249 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 











 

















 












 












#line 3314 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 3323 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 











 












#line 3375 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 3384 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"






 
#line 3397 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3405 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"





 




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

 

















 

















 

















 















 














 

















 


















 






 
#line 3656 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3675 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"





 




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

 
#line 3710 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 3736 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3753 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 3770 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




#line 3784 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3794 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 








 




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

 

 
#line 3831 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 






 




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

 



#line 3886 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 












 












 

















 

















#line 3960 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 3972 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"







 
#line 3988 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"




 









#line 4016 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 

















#line 4078 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 














 











#line 4138 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4153 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4168 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 











 











#line 4225 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4240 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4255 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4270 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4281 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"








 
#line 4298 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"








 









#line 4324 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 

















 

















 

















 



















 




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


#line 4475 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

















#line 4500 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"










#line 4521 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4531 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4548 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4557 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4568 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




 
#line 4583 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4593 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 









 
#line 4616 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4626 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 




 
#line 4643 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4653 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 



 



 
#line 4669 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 



 
#line 4681 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4692 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 




extern volatile unsigned int WDTCTL;                             
extern volatile unsigned char WDTCTL_L;                            
extern volatile unsigned char WDTCTL_H;                            
 
 
#line 4713 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
#line 4723 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



#line 4742 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

#line 4750 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"

 
 




 




 
 




 








 






#line 4798 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 

#pragma diag_suppress 1107
#line 4812 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"


#line 4909 "c:/ti/ccsv6/ccs_base/msp430/include/cc430x613x.h"



 







#line 90 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"
#line 97 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"




 

	
 




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





 
#line 111 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/mcus/bsp_msp430_defs.h"














 

















 
#line 55 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/boards/MSP-EXP430F6137Rx/bsp_board_defs.h"





 
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\bsp\\boards\\MSP-EXP430F6137Rx\\bsp_config.h"





























 






 





 



 
#line 62 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/boards/MSP-EXP430F6137Rx/bsp_board_defs.h"






 




void BSP_InitBoard(void);
void BSP_Delay(uint16_t usec);




 


 
#line 47 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\bsp\\bsp_macros.h"





























 





 








 
 


























 




 
#line 48 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"




 








 






 












 










 
typedef unsigned short  bspIState_t;

#line 101 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"





 












 

#line 132 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"

 






 
void BSP_Init(void);

 










 








#line 176 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.h"



 



#line 43 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi/mrfi.h"





























 





 








 
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"





























 





 







 






 










 

 
#line 93 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"

 
#line 102 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"





 


































 
#line 176 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"





 








 

 
#line 212 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"

 
#line 222 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\mrfi\\mrfi_defs.h"



 
#line 48 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi/mrfi.h"





 




 



 



 








 
#line 83 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi/mrfi.h"

 
#line 96 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi/mrfi.h"


 
#line 107 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi/mrfi.h"

 














 






 










 
typedef struct
{
  uint8_t frame[((10+3) + (1 + (2 * 4)))];
  uint8_t rxMetrics[2];
} mrfiPacket_t;





 
void    MRFI_Init(void);
uint8_t MRFI_Transmit(mrfiPacket_t *, uint8_t);
void    MRFI_Receive(mrfiPacket_t *);
void    MRFI_RxCompleteISR(void);  
uint8_t MRFI_GetRadioState(void);
void    MRFI_RxOn(void);
void    MRFI_RxIdle(void);
int8_t  MRFI_Rssi(void);
void    MRFI_SetLogicalChannel(uint8_t);
uint8_t MRFI_SetRxAddrFilter(uint8_t *);
void    MRFI_EnableRxAddrFilter(void);
void    MRFI_DisableRxAddrFilter(void);
void    MRFI_Sleep(void);
void    MRFI_WakeUp(void);
uint8_t MRFI_RandomByte(void);
void    MRFI_DelayMs(uint16_t);
void    MRFI_ReplyDelay(void);
void    MRFI_PostKillSem(void);
void    MRFI_SetRFPwr(uint8_t);




 
extern const uint8_t mrfiBroadcastAddr[];



 
#line 44 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_types.h"

































 

















typedef struct
{
  uint8_t  addr[4];
} addr_t;

typedef uint8_t linkID_t;
typedef uint8_t ccRadioStatus_t;





 
enum ioctlObject  {
  IOCTL_OBJ_FREQ,
  IOCTL_OBJ_CRYPTKEY,
  IOCTL_OBJ_RAW_IO,
  IOCTL_OBJ_RADIO,
  IOCTL_OBJ_AP_JOIN,
  IOCTL_OBJ_ADDR,
  IOCTL_OBJ_CONNOBJ,
  IOCTL_OBJ_FWVER,
  IOCTL_OBJ_PROTOVER,
  IOCTL_OBJ_NVOBJ,
  IOCTL_OBJ_TOKEN
};

enum ioctlAction  {
  IOCTL_ACT_SET,
  IOCTL_ACT_GET,
  IOCTL_ACT_READ,
  IOCTL_ACT_WRITE,
  IOCTL_ACT_RADIO_SLEEP,
  IOCTL_ACT_RADIO_AWAKE,
  IOCTL_ACT_RADIO_SIGINFO,
  IOCTL_ACT_RADIO_RSSI,
  IOCTL_ACT_RADIO_RXON,
  IOCTL_ACT_RADIO_RXIDLE,
  IOCTL_ACT_RADIO_SETPWR,
  IOCTL_ACT_ON,
  IOCTL_ACT_OFF,
  IOCTL_ACT_SCAN,
  IOCTL_ACT_DELETE
};

typedef enum ioctlObject   ioctlObject_t;
typedef enum ioctlAction   ioctlAction_t;

enum ioctlLevel
{
  IOCTL_LEVEL_0,
  IOCTL_LEVEL_1,
  IOCTL_LEVEL_2
};

typedef enum ioctlLevel ioctlLevel_t;

typedef struct
{
  addr_t   *addr;
  uint8_t  *msg;
  uint8_t   len;
  uint8_t   port;
} ioctlRawSend_t;

typedef struct
{
  addr_t  *addr;
  uint8_t *msg;
  uint8_t  len;
  uint8_t  port;
  uint8_t  hopCount;
} ioctlRawReceive_t;



 
typedef int8_t rssi_t;

typedef struct
{
  rssi_t  rssi;
  uint8_t lqi;
} rxMetrics_t;

typedef struct
{
  linkID_t     lid;         
  rxMetrics_t  sigInfo;
} ioctlRadioSiginfo_t;


 
enum tokenType
{
  TT_LINK,       
  TT_JOIN        
};

typedef enum tokenType tokenType_t;

 
typedef union
{
  uint32_t linkToken;
  uint32_t joinToken;
} token_t;

typedef struct
{
  tokenType_t  tokenType;
  token_t      token;
} ioctlToken_t;
 




 
typedef struct
{
  uint8_t logicalChan;
} freqEntry_t;

typedef struct
{
  uint8_t      numChan;
  freqEntry_t *freq;
} ioctlScanChan_t;

 
typedef uint8_t  secMAC_t;
typedef uint8_t  secFCS_t;
























 
typedef struct
{
  uint8_t    objVersion;
  uint16_t   objLen;
  uint8_t  **objPtr;
} ioctlNVObj_t;




 

enum smplStatus  {
  SMPL_SUCCESS,
  SMPL_TIMEOUT,
  SMPL_BAD_PARAM,
  SMPL_NOMEM,
  SMPL_NO_FRAME,
  SMPL_NO_LINK,
  SMPL_NO_JOIN,
  SMPL_NO_CHANNEL,
  SMPL_NO_PEER_UNLINK,
  SMPL_TX_CCA_FAIL,
  SMPL_NO_PAYLOAD,
  SMPL_NO_AP_ADDRESS,
  SMPL_NO_ACK
};

typedef enum smplStatus    smplStatus_t;

 
enum fhStatus
{
  FHS_RELEASE,    
  FHS_KEEP,       
  FHS_REPLAY      
};

typedef enum fhStatus   fhStatus_t;

 
enum rcvType
{
  RCV_NWK_PORT,
  RCV_APP_LID,
  RCV_RAW_POLL_FRAME
};

typedef enum rcvType rcvType_t;

 
typedef  uint16_t   txOpt_t;

typedef struct
{
  rcvType_t   type;
  union
  {
    linkID_t      lid;
    uint8_t       port;
    mrfiPacket_t *pkt;
  } t;
} rcvContext_t;
 



typedef struct
{
  uint8_t  protocolVersion;
  uint8_t  fwVerString[4];
} smplVersionInfo_t;






 
typedef uint8_t  appPTid_t;


 
typedef struct
{
  addr_t    clientAddr;
  appPTid_t lastTID;
} sfClientInfo_t;

typedef struct
{
  uint8_t        curNumSFClients;
  sfClientInfo_t sfClients[3];
} sfInfo_t;




 

 












 
#line 332 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_types.h"

#line 45 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_frame.h"

































 








 
#line 63 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_frame.h"

#line 76 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_frame.h"







 








 




 




 





 






typedef struct
{
  uint8_t   rssi;
  uint8_t   lqi;
} sigInfo_t;

typedef struct
{
  volatile uint8_t      fi_usage;
           uint8_t      orderStamp;
           mrfiPacket_t mrfiPkt;
} frameInfo_t;


 
frameInfo_t  *nwk_buildFrame(uint8_t, uint8_t *msg, uint8_t len, uint8_t hops);

frameInfo_t  *nwk_buildAckReqFrame(uint8_t, uint8_t *, uint8_t, uint8_t, volatile uint8_t *);

void          nwk_receiveFrame(void);
void          nwk_frameInit(uint8_t (*)(linkID_t));
smplStatus_t  nwk_retrieveFrame(rcvContext_t *, uint8_t *, uint8_t *, addr_t *, uint8_t *);
smplStatus_t  nwk_sendFrame(frameInfo_t *, uint8_t txOption);
frameInfo_t  *nwk_getSandFFrame(mrfiPacket_t *, uint8_t);
uint8_t       nwk_getMyRxType(void);
void          nwk_SendEmptyPollRspFrame(mrfiPacket_t *);

void          nwk_sendAckReply(mrfiPacket_t *, uint8_t);



 
void  nwk_replayFrame(frameInfo_t *);



#line 46 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk.h"

































 





 
#line 47 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk.h"




 






 





 



 






 







typedef struct
{
  volatile uint8_t     connState;
           uint8_t     hops2target;

  volatile uint8_t     ackTID;

           uint8_t     peerAddr[4];
           rxMetrics_t sigInfo;
           uint8_t     portRx;
           uint8_t     portTx;
           linkID_t    thisLinkID;




} connInfo_t;




















 



#line 130 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk.h"

 
smplStatus_t  nwk_nwkInit(uint8_t (*)(linkID_t));
connInfo_t   *nwk_getNextConnection(void);
void          nwk_freeConnection(connInfo_t *);
uint8_t       nwk_getNextClientPort(void);
connInfo_t   *nwk_getConnInfo(linkID_t port);
connInfo_t   *nwk_isLinkDuplicate(uint8_t *, uint8_t);
uint8_t       nwk_findAddressMatch(mrfiPacket_t *);
smplStatus_t  nwk_checkConnInfo(connInfo_t *, uint8_t);
uint8_t       nwk_isConnectionValid(mrfiPacket_t *, linkID_t *);
uint8_t       nwk_allocateLocalRxPort(uint8_t, connInfo_t *);
uint8_t       nwk_isValidReply(mrfiPacket_t *, uint8_t, uint8_t, uint8_t);
connInfo_t   *nwk_findPeer(addr_t *, uint8_t);
smplStatus_t  nwk_NVObj(ioctlAction_t, ioctlNVObj_t *);


uint8_t       nwk_checkAppMsgTID(appPTid_t, appPTid_t);
void          nwk_getNumObjectFromMsg(void *, void *, uint8_t);
void          nwk_putNumObjectIntoMsg(void *, void *, uint8_t);

sfInfo_t     *nwk_getSFInfoPtr(void);

uint8_t       nwk_saveJoinedDevice(mrfiPacket_t *);
connInfo_t   *nwk_findAlreadyJoined(mrfiPacket_t *);




#line 47 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"



































 







#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_freq.h"

































 




 
 






 


 




 


 



 
void         nwk_freqInit(void);
fhStatus_t   nwk_processFreq(mrfiPacket_t *);

smplStatus_t nwk_setChannel(freqEntry_t *);
void         nwk_getChannel(freqEntry_t *);
uint8_t      nwk_scanForChannels(freqEntry_t *);
smplStatus_t nwk_freqControl(ioctlAction_t, void *);


#line 45 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_ping.h"

































 





 


 
 




 


 
fhStatus_t   nwk_processPing(mrfiPacket_t *);
void         nwk_pingInit(void);
smplStatus_t nwk_ping(linkID_t);


#line 46 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_link.h"

































 




 







 
 



 





 




 

 


 






 
#line 85 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_link.h"






 




 
fhStatus_t   nwk_processLink(mrfiPacket_t *);
linkID_t     nwk_getLocalLinkID(void);
void         nwk_linkInit(void);
smplStatus_t nwk_link(linkID_t *);
smplStatus_t nwk_unlink(linkID_t);
void         nwk_setLinkToken(uint32_t);
void         nwk_getLinkToken(uint32_t *);
void         nwk_setListenContext(uint8_t);

#line 47 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_mgmt.h"

































 





 


 


 
 



 



 


 


 
void         nwk_mgmtInit(void);
fhStatus_t   nwk_processMgmt(mrfiPacket_t *);
smplStatus_t nwk_poll(uint8_t, uint8_t *);
void         nwk_resetSFMarker(uint8_t);

#line 48 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_join.h"

































 








 



 


 
 


 



 




 


 








 


 
void            nwk_joinInit(uint8_t (*)(linkID_t));
smplStatus_t    nwk_join(void);
fhStatus_t      nwk_processJoin(mrfiPacket_t *);
void            nwk_getJoinToken(uint32_t *);
void            nwk_setJoinContext(uint8_t);
void            nwk_setJoinToken(uint32_t);
void            nwk_getJoinToken(uint32_t *);

sfClientInfo_t *nwk_isSandFClient(uint8_t *, uint8_t *);




#line 49 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_security.h"

































 





 


 
void       nwk_securityInit(void);
fhStatus_t nwk_processSecurity(mrfiPacket_t *);
void       nwk_setSecureFrame(mrfiPacket_t *, uint8_t, uint32_t *);
uint8_t    nwk_getSecureFrame(mrfiPacket_t *, uint8_t, uint32_t *);
#line 50 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"
#line 1 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications/nwk_ioctl.h"



































 






 
smplStatus_t nwk_rawSend(ioctlRawSend_t *);
smplStatus_t nwk_rawReceive(ioctlRawReceive_t *);
smplStatus_t nwk_radioControl(ioctlAction_t, void *);
smplStatus_t nwk_deviceAddress(ioctlAction_t, addr_t *);
smplStatus_t nwk_connectionControl(ioctlAction_t, void *);

smplStatus_t nwk_joinContext(ioctlAction_t);


#line 51 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_app.h"



#line 48 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_QMgmt.h"

































 











 
void              nwk_QInit(void);
frameInfo_t *nwk_QfindSlot(uint8_t);
void              nwk_QadjustOrder(uint8_t, uint8_t);
frameInfo_t *nwk_QfindOldest(uint8_t, rcvContext_t *, uint8_t);
frameInfo_t *nwk_getQ(uint8_t);

#line 49 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
#line 1 "C:\\ti\\msp430\\MSP-EXPCC430_UE_1_00_00_01\\src\\MSP-EXP430F6137Rx_User_Experience\\SimpliciTI\\Components\\simpliciti\\nwk\\nwk_globals.h"

































 





 
void           nwk_globalsInit(void);
addr_t const  *nwk_getMyAddress(void);
uint8_t        nwk_setMyAddress(addr_t *addr);
void           nwk_setAPAddress(addr_t *addr);
addr_t const  *nwk_getAPAddress(void);
addr_t const  *nwk_getBCastAddress(void);
uint8_t const *nwk_getFWVersion(void);
uint8_t        nwk_getProtocolVersion(void);


#line 50 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"





 



 



 



 


 
static  fhStatus_t (* const func[])(mrfiPacket_t *) = { nwk_processPing,
                                                        nwk_processLink,
                                                        nwk_processJoin,
                                                        nwk_processSecurity,
                                                        nwk_processFreq,
                                                        nwk_processMgmt
                                                      };


static uint8_t sTRACTID = 0;

static addr_t const *sMyAddr = 0;

static uint8_t  sMyRxType = 0, sMyTxType = 0;


static uint8_t  (*spCallback)(linkID_t) = 0;




 


 
static void  dispatchFrame(frameInfo_t *);


 
uint8_t  isDupSandFFrame(mrfiPacket_t *);






 



 












 

void nwk_frameInit(uint8_t (*pF)(linkID_t))
{

 
   
   

    sMyRxType = 0x00;

    sMyTxType = 0x20;
#line 148 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
 


  spCallback = pF;




  sMyAddr = nwk_getMyAddress();

  while (!(sTRACTID=MRFI_RandomByte())) ;

  return;
}




















 
frameInfo_t *nwk_buildFrame(uint8_t port, uint8_t *msg, uint8_t len, uint8_t hops)
{
  frameInfo_t  *fInfoPtr;

  if (!(fInfoPtr=nwk_QfindSlot(2)))
  {
    return (frameInfo_t *)0;
  }

  do { (&fInfoPtr->mrfiPkt)->frame[0] = len+(3+0) + (2 * 4); } while (192 == -1);

  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x40))) | (0); } while(0);
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x3F))) | (port); } while(0);
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[2] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[2] & ~((0xFF))) | (sTRACTID); } while(0);
  while (!(++sTRACTID)) ;   
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x40))) | (sMyRxType); } while(0);
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x07))) | (hops); } while(0);

   
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x80))) | (0); } while(0);
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x08))) | (0); } while(0);

   
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x80))) | (0); } while(0);

  memcpy((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)]))+(3+0), msg, len);
  memcpy((&((&fInfoPtr->mrfiPkt)->frame[((0 + 1) + 4)])), sMyAddr, 4);

  return fInfoPtr;
}
























 
frameInfo_t *nwk_buildAckReqFrame(uint8_t port, uint8_t *msg, uint8_t len, uint8_t hops, volatile uint8_t *tid)
{
  frameInfo_t *fInfoPtr;

   
  if (!(fInfoPtr=nwk_buildFrame(port, msg, len, hops)))
  {
    return (frameInfo_t *)0;
  }

   
  *tid = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[2] & ((0xFF)));
   
  do {((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fInfoPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x80))) | (0x80); } while(0);

  return fInfoPtr;
}














 
void MRFI_RxCompleteISR()
{
  frameInfo_t  *fInfoPtr;

   
  if (fInfoPtr=nwk_QfindSlot(1))
  {
    MRFI_Receive(&fInfoPtr->mrfiPkt);

    dispatchFrame(fInfoPtr);
  }

  return;
}



























 
smplStatus_t nwk_retrieveFrame(rcvContext_t *rcv, uint8_t *msg, uint8_t *len, addr_t *srcAddr, uint8_t *hopCount)
{
  frameInfo_t *fPtr;
  uint8_t      done;

  do {
     
    *len = 0;
    done = 1;

    fPtr = nwk_QfindOldest(1, rcv, 1);
    if (fPtr)
    {
      connInfo_t  *pCInfo = 0;

      if (RCV_APP_LID == rcv->type)
      {
        pCInfo = nwk_getConnInfo(rcv->t.lid);
        if (!pCInfo)
        {
          return SMPL_BAD_PARAM;
        }
#line 371 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
      }

       
      *len = ((&fPtr->mrfiPkt)->frame[0] - (2 * 4)) - (3+0);
      memcpy(msg, (&((&fPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)]))+(3+0), *len);
       
      if (pCInfo)
      {
         
        pCInfo->sigInfo.rssi = fPtr->mrfiPkt.rxMetrics[0];
        pCInfo->sigInfo.lqi  = fPtr->mrfiPkt.rxMetrics[1];
      }
      if (srcAddr)
      {
         
        memcpy(srcAddr, (&((&fPtr->mrfiPkt)->frame[((0 + 1) + 4)])), 4);
      }
      if (hopCount)
      {
         
        *hopCount = (((&((&fPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ((0x07)));
      }
       
      nwk_QadjustOrder(1, fPtr->orderStamp);

      fPtr->fi_usage = 0;
      return SMPL_SUCCESS;
    }
  } while (!done);

  return SMPL_NO_FRAME;
}














 
static void dispatchFrame(frameInfo_t *fiPtr)
{
  uint8_t     port       = (((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ((0x3F)));
  uint8_t     nwkAppSize = sizeof(func)/sizeof(func[0]);
  fhStatus_t  rc;
  linkID_t    lid;

  uint8_t loc;


  uint8_t isForMe;


   
  if (!memcmp((&((&fiPtr->mrfiPkt)->frame[((0 + 1) + 4)])), sMyAddr, 4))
  {
    fiPtr->fi_usage = 0;
    return;
  }

   
#line 447 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
  if ((((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ((0x40))))
  {
     
    fiPtr->fi_usage = 0;
    return;
  }


  

 
  if (port && (port <= nwkAppSize))
  {
#line 468 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
    rc = func[port-1](&fiPtr->mrfiPkt);
    if (FHS_KEEP == rc)
    {
      fiPtr->fi_usage = 1;
    }

    else if (FHS_REPLAY == rc)
    {
       
      nwk_replayFrame(fiPtr);
    }

    else   
    {
      fiPtr->fi_usage = 0;
    }
    return;
  }
   
  else if ((port != 0x3F) && ((port < 0x20) || (port > 0x3E)))
  {
     
    fiPtr->fi_usage = 0;
    return;
  }

  




 

#line 540 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"

  





 
  isForMe = !memcmp(sMyAddr, (&((&fiPtr->mrfiPkt)->frame[(0 + 1)])), 4);
  if (isForMe || ((port == 0x3F) && !memcmp(nwk_getBCastAddress(), (&((&fiPtr->mrfiPkt)->frame[(0 + 1)])), 4)))
  {
    

 
    if (nwk_isConnectionValid(&fiPtr->mrfiPkt, &lid))
    {
      






 
       
      if (!isForMe)
      {
         
        nwk_replayFrame(fiPtr);
      }
       
      fiPtr->fi_usage = 1;
      if (spCallback && spCallback(lid))
      {
        fiPtr->fi_usage = 0;
        return;
      }
    }
    else
    {
      fiPtr->fi_usage = 0;
    }
  }

  

 
  else if (nwk_isSandFClient((&((&fiPtr->mrfiPkt)->frame[(0 + 1)])), &loc))
  {
    

 
    if (!isDupSandFFrame(&fiPtr->mrfiPkt) &&
        !((((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ((0x80))))
       )
    {

       
      do {((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x80))) | (0); } while(0);

      fiPtr->fi_usage = 3;
    }
    else
    {
      fiPtr->fi_usage = 0;
    }
  }
  else if ((((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ((0x30))) == 0x20)
  {
     
    fiPtr->fi_usage = 0;
  }
#line 619 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
  else
  {
    

 
    nwk_replayFrame(fiPtr);
  }

  return;
}
















 
smplStatus_t nwk_sendFrame(frameInfo_t *pFrameInfo, uint8_t txOption)
{
  smplStatus_t rc;

   
  do {((&((&pFrameInfo->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&pFrameInfo->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x30))) | (sMyTxType); } while(0);

  if (0 == MRFI_Transmit(&pFrameInfo->mrfiPkt, txOption))
  {
    rc = SMPL_SUCCESS;
  }
  else
  {
    

 
    rc = SMPL_TX_CCA_FAIL;
  }

   
  pFrameInfo->fi_usage = 0;

  return rc;
}














 
uint8_t nwk_getMyRxType(void)
{
  return sMyRxType;
}














 
void nwk_sendAckReply(mrfiPacket_t *frame, uint8_t port)
{
  mrfiPacket_t dFrame;
  uint8_t      tid = (((&((frame)->frame[(((0 + 1) + 4) + 4)])))[2] & ((0xFF)));

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x30))) | (sMyTxType); } while(0);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x40))) | (sMyRxType); } while(0);

   
  memcpy((&((&dFrame)->frame[(0 + 1)])), (&((frame)->frame[((0 + 1) + 4)])), 4);

   
  memcpy((&((&dFrame)->frame[((0 + 1) + 4)])), sMyAddr, 4);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x3F))) | (port); } while(0);

   
  do { (&dFrame)->frame[0] = (3+0) + (2 * 4); } while (725 == -1);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[2] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[2] & ~((0xFF))) | (tid); } while(0);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x07))) | (3); } while(0);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x08))) | (0x08); } while(0);
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x80))) | (0); } while(0);

    
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x80))) | (0); } while(0);

   

  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x40))) | (0); } while(0);





  MRFI_Transmit(&dFrame, 0);

  return;
}















 
void nwk_replayFrame(frameInfo_t *pFrameInfo)
{
  uint8_t  hops = (((&((&pFrameInfo->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ((0x07)));

   
  if (hops--)
  {
    do {((&((&pFrameInfo->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&pFrameInfo->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x07))) | (hops); } while(0);
    

 
#line 788 "C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk/nwk_frame.c"
    MRFI_DelayMs(1);
    nwk_sendFrame(pFrameInfo, 1);
  }
  else
  {
    pFrameInfo->fi_usage = 0;
  }
  return;
}


















 
frameInfo_t *nwk_getSandFFrame(mrfiPacket_t *frame, uint8_t osPort)
{
  uint8_t        i, port = *((&((frame)->frame[(((0 + 1) + 4) + 4)]))+(3+0)+osPort);
  frameInfo_t *fiPtr;
  rcvContext_t rcv;

  rcv.type  = RCV_RAW_POLL_FRAME;
  rcv.t.pkt = frame;
   
  if (fiPtr=nwk_QfindOldest(1, &rcv, 2))
  {
    return fiPtr;
  }

  


 
  fiPtr = nwk_getQ(2);
  for (i=0; i<2; ++i, fiPtr++)
  {
    if (3 == fiPtr->fi_usage)
    {
      if (!memcmp((&((&fiPtr->mrfiPkt)->frame[(0 + 1)])), (&((frame)->frame[((0 + 1) + 4)])), 4))
      {
        if ((((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])))[0] & ((0x3F))) == port)
        {
          return fiPtr;
        }
      }
    }
  }
  return 0;
}













 
void nwk_SendEmptyPollRspFrame(mrfiPacket_t *frame)
{
  mrfiPacket_t dFrame;
  uint8_t      port = *((&((frame)->frame[(((0 + 1) + 4) + 4)]))+(3+0)+2);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x30))) | (0x20); } while(0);
  

 
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x40))) | (sMyRxType); } while(0);
   
  memcpy((&((&dFrame)->frame[(0 + 1)])), (&((frame)->frame[((0 + 1) + 4)])), 4);
   
  memcpy((&((&dFrame)->frame[((0 + 1) + 4)])), (&((frame)->frame[(((0 + 1) + 4) + 4)]))+(3+0)+3, 4);
   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x3F))) | (port); } while(0);
   
  do { (&dFrame)->frame[0] = (3+0) + (2 * 4); } while (882 == -1);
   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[2] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[2] & ~((0xFF))) | (sTRACTID); } while(0);
  sTRACTID++;
   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x07))) | (1); } while(0);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x08))) | (0); } while(0);
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[1] & ~((0x80))) | (0); } while(0);

   
  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x80))) | (0x80); } while(0);

   

  do {((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] = (((&((&dFrame)->frame[(((0 + 1) + 4) + 4)])))[0] & ~((0x40))) | (0); } while(0);





  MRFI_Transmit(&dFrame, 0);

  return;
}












 
uint8_t  isDupSandFFrame(mrfiPacket_t *frame)
{
  uint8_t      i, plLen = ((frame)->frame[0] - (2 * 4));
  frameInfo_t *fiPtr;

   
  fiPtr = nwk_getQ(1);
  for (i=0; i<6; ++i, fiPtr++)
  {
    if (3 == fiPtr->fi_usage)
    {
       
      if (((&fiPtr->mrfiPkt)->frame[0] - (2 * 4)) == plLen                                   &&
          !memcmp((&((&fiPtr->mrfiPkt)->frame[(0 + 1)])), (&((frame)->frame[(0 + 1)])), 4) &&
          !memcmp((&((&fiPtr->mrfiPkt)->frame[((0 + 1) + 4)])), (&((frame)->frame[((0 + 1) + 4)])), 4) &&
          !memcmp((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)])), (&((frame)->frame[(((0 + 1) + 4) + 4)])), 1)               &&
          !memcmp((&((&fiPtr->mrfiPkt)->frame[(((0 + 1) + 4) + 4)]))+2, (&((frame)->frame[(((0 + 1) + 4) + 4)]))+2, plLen-2)
          )
      {
        return 1;
      }
    }
  }
  return 0;
}


