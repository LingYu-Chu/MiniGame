/*
   This file includes weak (i.e. optional) functions to perform SoC related
   initialization. They are:
	1). __mem_pre_c_init():
		Executed before C language initialization to make memory
		ready so that program data can be initialized. An example
		is to initialize DRAM.
		Since this is called before C initialization, please
		use provided macros to avoid problems.
	2). __soc_init():
		Further SoC intialization. Called after C language
		initialization, so it is a typical C function.
*/

#include "nds32_intrinsic.h"
#include "config.h"
#define inw(reg)  (*((volatile unsigned int*) (reg)))
#define outw(reg, data) ((*((volatile unsigned int*) (reg)))=(unsigned int)(data))
void __mem_pre_c_init()		//The function is weak (optional)
{
//Example of initializing (DRAM) memory controller for AG101 before first use

	/* remap */
	//remap();
	return;
}

void	__soc_init() 		//The function is weak (optional)
{
	//DRV_WatchDogDisable();
	//DRV_GpioInitial();
	//DRV_UartInitial();
	//unsigned int * pPortEOen = 0x001f6A04;
	unsigned int uiVal, ii;
	uiVal = inw(0x001F6A00);
	outw(0x001F6A00, 0x0);
	uiVal = inw(0x001F6A0C);
	uiVal = inw(0x001F6A0C);
	ii = uiVal;
}
