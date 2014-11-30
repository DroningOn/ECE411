################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
SimpliciTI/Components/mrfi/mrfi.obj: ../SimpliciTI/Components/mrfi/mrfi.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"c:/ti/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" --cmd_file="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Application/configuration/End_Device/smpl_config_CCS.dat" --cmd_file="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Application/configuration/smpl_nwk_config_CCS.dat"  -vmspx --abi=eabi -O2 -g --include_path="c:/ti/ccsv6/ccs_base/msp430/include" --include_path="c:/ti/ccsv6/tools/compiler/msp430_4.3.3/include" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/F5xx_F6xx_Core_Lib" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/MSP-EXP430F5137_HAL" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Application/configuration" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/bsp" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/bsp/drivers" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/bsp/boards/MSP-EXP430F5137Rx" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/mrfi" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/simpliciti/nwk" --include_path="C:/Users/Seth/Documents/GitHub/ECE411/Code/Experimental/Satellite/SimpliciTI/Components/simpliciti/nwk_applications" --define=__CC430F5137__ --define=ISM_US --define=MRFI_CC430 --diag_warning=225 --silicon_errata=CPU18 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="SimpliciTI/Components/mrfi/mrfi.pp" --obj_directory="SimpliciTI/Components/mrfi" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


