##############################################################################
## Filename:          C:\Users\user\Desktop\ZED_LAB\LED_CTR\LED_CTR.srcs\sources_1\edk\system/drivers/my_adder_v1_00_a/data/my_adder_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Mon May 18 10:54:39 2015 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "my_adder" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
