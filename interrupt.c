#include <nds32_intrinsic.h>

volatile int trigger;
volatile int g_nIntCount=0;


void initIntr()
{
	/* enable SW0, HW0 and HW1 */
	//__nds32__mtsr(0x10003, NDS32_SR_INT_MASK);
	__nds32__mtsr(0x0003, NDS32_SR_INT_MASK);
	//intc_reset();


}

void clear_swi ()
{
	unsigned int int_pend;

	int_pend = 0x10;
	__nds32__mtsr(int_pend, NDS32_SR_INT_PEND);
	__nds32__dsb();
}

/* User can use our handler or Default_Handler */
#if 0
void exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	//DRV_PutStr("exception handler\n");
	while(1);
}

void tlb_exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	//DRV_PutStr("tlb exception handler\n");
	while(1);
}

void error_exception_handler(int exception_nr)
{
	unsigned int *led = 0x902ffffc;
	*led = exception_nr;
	//DRV_PutStr("error exception handler\n");
	while(1);
}
#endif

void syscall_handler()
{
	static int cnt = 0;

	if (++cnt < 5)
		asm("syscall 0x5000\n\t");
		
}

void HW0_ISR()
{
	volatile unsigned int * nTIM1INTflag=0x00201C40;
  unsigned int i;
  unsigned int * nPortEOutPutLoHi;

  if(*nTIM1INTflag==0x10)
  {

	  nPortEOutPutLoHi=0x001F6A10;
	  *nTIM1INTflag=0x10;
	  //for (i=0;i<10;i++)
	  //{
	  *nPortEOutPutLoHi|=0x08;	//0x55555555; 
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  //*nPortEOutPutLoHi=0x0; 
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  //}
	  *nPortEOutPutLoHi^=0x08;
	  //*nTIM1INTflag=0x10;
	  //*nTIM1Start=0x8001;
  }
  //*/
	
}

void HW1_ISR()
{
	volatile unsigned int * nTIM2INTflag=0x00202040;
	volatile unsigned int * nTIM3INTflag=0x00202440;
	unsigned int nLED;
	if(*nTIM2INTflag==0x10)
	{
		*nTIM2INTflag=0x10;
		nLED=0x04;
	}
	else if(*nTIM3INTflag==0x10)
	{
		*nTIM3INTflag=0x10;
		nLED=0x20;
	}

	unsigned int i;
  	unsigned int * nPortEOutPutLoHi;

	  nPortEOutPutLoHi=0x001F6A10;

	  *nPortEOutPutLoHi|=nLED;	//0xffffffff; 
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);

	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  delay1(50000);
	  //}
	  *nPortEOutPutLoHi^=nLED;

}

void SW0_ISR()
{
	//DRV_PutStr("A software interrupt occurs ...\n");
	//*(unsigned int *)0x40006A10=*(unsigned int *)0x40006404;// ADC Data
	//*(unsigned int *)0x40006408=0x00000001; // Clear ADC interrupt
	*(unsigned int *)0x001F6A10=0x000000ff;
	return;
}

inline void GIE_ENABLE()
{
	__nds32__setgie_en();
	__nds32__dsb();
}

inline void GIE_DISABLE()
{
	__nds32__setgie_dis();
	__nds32__dsb();
}

 /* this function generates a s/w interrupt */
void gen_swi()
{
	unsigned int int_pend;

	int_pend = __nds32__mfsr(NDS32_SR_INT_PEND);
	int_pend |= 0x10000;
	__nds32__mtsr(int_pend, NDS32_SR_INT_PEND);
	__nds32__dsb();
}

#if 0
void SYSirq_Disable_Interrupts_Save_Flags(unsigned int *flags)
{
	unsigned int tmp_flags;

	*flags = __nds32__mfsr(NDS32_SR_PSW) & 0x1;
	__nds32__setgie_dis();
	__nds32__dsb();
}

void SYSirq_Enable_Interrupts_Save_Flags(unsigned int *flags)
{
	unsigned int tmp_flags;

	*flags = __nds32__mfsr(NDS32_SR_PSW) & 0x1;
	__nds32__setgie_en();
	__nds32__dsb();
}
 
void SYSirq_Interrupts_Restore_Flags(unsigned int flags)
{
 	unsigned int tmp;

	tmp = __nds32__mfsr(NDS32_SR_PSW);
	tmp = __nds32__bclr(tmp, 0) | flags;
	__nds32__mtsr(tmp, NDS32_SR_PSW);
	__nds32__dsb();
}
#endif
