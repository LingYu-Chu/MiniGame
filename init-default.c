#include "nds32_intrinsic.h"
#include "config.h"

/* It will use Default_Handler if you don't have one */
#pragma weak tlb_exception_handler 	= Default_Handler
#pragma weak error_exception_handler 	= Default_Handler
#pragma weak syscall_handler 		= Default_Handler
#pragma weak HW0_ISR 			= Default_Handler
#pragma weak HW1_ISR 			= Default_Handler
#pragma weak HW2_ISR 			= Default_Handler
#pragma weak HW3_ISR 			= Default_Handler
#pragma weak HW4_ISR 			= Default_Handler
#pragma weak HW5_ISR 			= Default_Handler
#pragma weak SW0_ISR 			= Default_Handler

//static void Default_Handler() { while(1); }
static void Default_Handler()
{
	//for WT6320 PCB
	int i, j;
	outw(0x001F6A00, inw(0x001F6A00)|0x7C);		//port e gpio enable
	outw(0x001F6A04, inw(0x001F6A04) & ~0x7C);	//output enable
	outw(0x001F6A08, inw(0x001F6A08) & ~0x7C);	//push pull enable
	for (i=0;i<100;i++)
	{
		outw(0x001F6A10, inw(0x001F6A10)|0x7C);		//output 1
		for (j=0;j<1000000;j++);
		outw(0x001F6A10, inw(0x001F6A10) & ~0x7C);		//output 1
	}
}
#pragma weak __mem_pre_c_init		= __null_function
#pragma weak __soc_init			= __null_function

void	__null_function() { ; }

void __c_init()
{
/* Use compiler builtin memcpy and memset */
#define MEMCPY(des, src, n)	__builtin_memcpy ((des), (src), (n))
#define MEMSET(s, c, n)		__builtin_memset ((s), (c), (n))

	extern char _end;
	extern char __bss_start;
	int size;

	/* If we load code to RAM we don't need to copy 
	 * data section and lma will be equal to vma.*/
#if BURN
	extern char __data_lmastart;
	extern char __data_start;
	extern char _edata;
	/* Copy data section to RAM */
	size = &_edata - &__data_start;
	MEMCPY( &__data_start, &__data_lmastart, size);
#endif	
	/* Clear bss section */
	size = &_end - &__bss_start;
	MEMSET( &__bss_start, 0, size);
	return;
}
void __cpu_init()
{
 	unsigned int tmp;

    /* turn on BTB */
	tmp = 0x0;
	__nds32__mtsr(tmp, NDS32_SR_MISC_CTL);

    /* setup $IVB, IVIC and vector size 4, base 0x0 if not reset values.*/
	tmp = 0x0;
	__nds32__mtsr(tmp, NDS32_SR_IVB);

    /* Set PSW INTL to 0 */
	tmp = __nds32__mfsr(NDS32_SR_PSW);
	//tmp = __nds32__bclr(tmp, 0x1);
	tmp = tmp & 0xfffffffe;
	__nds32__mtsr(tmp, NDS32_SR_PSW);
	__nds32__dsb();
	return;
}

void __init()
{
	//__mem_pre_c_init();	//most MCU doesn't need this.

/*----------------------------------------------------------
   !!  Users should NOT add any code before this comment  !!
------------------------------------------------------------*/  
	__c_init();		//copy data section, clean bss

	__cpu_init();
	__soc_init();
	return;
}


