################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
SimpliciTI/Components/bsp/bsp.obj: C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/bsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/msp430_4.1.9/bin/cl430" --cmd_file="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/CCS/../SimpliciTI/Application/configuration/Access_Point/smpl_config_CCS.dat" --cmd_file="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/CCS/../SimpliciTI/Application/configuration/smpl_nwk_config_CCS.dat"  -vmsp --abi=eabi -O0 -g --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/msp430_4.1.9/include" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/F5xx_F6xx_Core_Lib" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/MSP-EXP430F6137_HAL" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/drivers" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/bsp/boards/MSP-EXP430F6137Rx" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/mrfi" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk" --include_path="C:/ti/msp430/MSP-EXPCC430_UE_1_00_00_01/src/MSP-EXP430F6137Rx_User_Experience/SimpliciTI/Components/simpliciti/nwk_applications" --advice:power_severity=remark --define=__CC430F6137__ --define=ISM_US --define=MRFI_CC430 --diag_warning=225 --display_error_number --silicon_errata=CPU18 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="SimpliciTI/Components/bsp/bsp.pp" --obj_directory="SimpliciTI/Components/bsp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


