##############################################################################
## Filename:          C:\Users\user\Desktop\ZED_LAB\LED_CTR\LED_CTR.srcs\sources_1\edk\system/drivers/testip_v1_00_a/data/testip_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Fri May 15 19:12:28 2015 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "testip" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
