

#include "xparameters.h"
#include "xgpio.h"

#include "xil_io.h"

/*
 * The following constant maps to the name of the hardware instances that
 * were created in the EDK XPS system.
 */
#define GPIO_EXAMPLE_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID
#define MY_ADDER_REG XPAR_MY_ADDER_0_BASEADDR
/*
 * The following constant is used to determine which channel of the GPIO is
 * used for the LED if there are 2 channels supported.
 */
#define LED_CHANNEL 1

XGpio Gpio; /* The Instance of the GPIO Driver */


void delay(int counter)
{
       while(counter) counter--;
}



int main(void)
{
	int Status;
	u32 value = 0 ;
	u32 period = 0 ;
	u32 beightness = 0 ;
	u32 cnt = 0 ;

	char led = 0x01 ;
	xil_printf("led = %x \n", led) ;

	Status = XGpio_Initialize(&Gpio, GPIO_EXAMPLE_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XGpio_DiscreteWrite(&Gpio, LED_CHANNEL,0);



    u32 init_value  = 0x00030003 ;
    Xil_Out32(MY_ADDER_REG, ((u32) init_value));
    xil_printf("Wrote : 0x%08x \n\r",Xil_In32( ((u32) MY_ADDER_REG   )) ) ;
    xil_printf("Read  : 0x%08x \n\r",Xil_In32( ((u32) MY_ADDER_REG +4)) ) ;
    xil_printf("%d + %d = %d \n\r",Xil_In32( ((u32) MY_ADDER_REG   ))>>16, Xil_In32( ((u32) MY_ADDER_REG   )) & 0xf,Xil_In32( ((u32) MY_ADDER_REG +4)) ) ;
	while (1) {

		if(led == 255)  led = 0x01 ;
		else 			led |= led << 1 ;
		xil_printf("led = %d \n\r", led) ;
		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL,led);


    	init_value +=0x00000001 ;
        Xil_Out32(MY_ADDER_REG, ((u32) init_value));
        xil_printf("Reg0(Wrote ): 0x%08x \n\r",Xil_In32( ((u32) MY_ADDER_REG   )) ) ;
        xil_printf("Reg1(Read)  : 0x%08x \n\r",Xil_In32( ((u32) MY_ADDER_REG +4)) ) ;
        xil_printf("%d + %d = %d \n\r",Xil_In32( ((u32) MY_ADDER_REG   ))>>16, Xil_In32( ((u32) MY_ADDER_REG   )) & 0xf,Xil_In32( ((u32) MY_ADDER_REG +4)) ) ;
        xil_printf("\n") ;
		delay(100000000); // about 1 second


	}

	return XST_SUCCESS;
}
