#include "lcd.h"

void CheckBusy(void) //BF ,CHACK BUSY FLAG
{
	unsigned short int i=0x8000;
	while(i&0x8000)
	{
		GPIO_ACT_PD = 0xFFFF; //Initialize GPIO_D output
		GPIO_OMOD_PD = 0x0;
		GPIO_OEN_PD = 0x0;

		GPIO_DAT_PD = (RW + E);

		GPIO_ACT_PD = 0xFF00; //Initialize GPIO_D input
		GPIO_RS_PD = 0xFF00;
		GPIO_REN_PD = 0xFF00;

		i = PAD_PD;

		GPIO_DAT_PD = CleanSet;
		//delay1(100000);
		delay1(100000);
	}
}
void WriteData(unsigned short int i)
{
	GPIO_ACT_PD = 0xFFFF; //Initialize GPIO_D output
	GPIO_OMOD_PD = 0x0;
	GPIO_OEN_PD = 0x0;

	GPIO_DAT_PD = ((i << 8) + RS + E);
	GPIO_DAT_PD = CleanSet;
	CheckBusy();
}

void WriteIns(unsigned short int instruction)
{
	GPIO_ACT_PD = 0xFFFF; //Initialize GPIO_D output
	GPIO_OMOD_PD = 0x0;
	GPIO_OEN_PD = 0x0;

	GPIO_DAT_PD = (instruction + E );
	GPIO_DAT_PD = CleanSet;

	CheckBusy();
}
void WriteString(char *p)
{
	while(*p)
	{
		WriteData(*p);
		p++;
	}
}

void gotoxy(unsigned int x, unsigned int y)
{
	if(x == 1)
		WriteIns(GOTO_LINE_1 + (y << 8));
	else
		WriteIns(GOTO_LINE_2 + (y << 8));
}

void InitialLCD(void)
{
	WriteIns(0x3800);  //FUNCTION SET
	WriteIns(0x0800);  // off display
	WriteIns(0x0100);  // clear buffer
	WriteIns(0x0e00);  // on display
	WriteIns(0x0600);  // set input mode
}
