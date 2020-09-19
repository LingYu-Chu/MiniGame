//gotkey.c
#include "gotkey.h"

unsigned char Key = 0;
void delay2(unsigned int nCount)
{
   unsigned int i;
   for(i=0;i<nCount;i++);
}


int gotkey()
{
	GPIO_ACT_PC = 0xFF; //Initialize GPIO_C in/output
	while(1){
		KeyScan(); //±½´y«öÁä
		if(Key != 0xFF){
			switch(Key){
				case 0xE7: return 0;
				case 0xEB: return 1;
				case 0xED: return 2;
				case 0xEE: return 3;
				case 0xD7: return 4;
				case 0xDB: return 5;
				case 0xDD: return 6;
				case 0xDE: return 7;
				case 0xB7: return 8;
				case 0xBB: return 9;
				case 0xBD: return 10;
				case 0xBE: return 11;
				case 0x77:	return 12;
				case 0x7B:	return 13;
				case 0x7D:	return 14;
				case 0x7E:	return 15;
				default:	return 16;
			}
		}
		return 16;
	}
}
