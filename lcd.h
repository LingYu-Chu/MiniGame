/*
 * lcd.h
 *
 *  Created on: 2017/3/16
 *      Author: admin
 */


#include "WT59F064.h"

#define RS	0x0080
#define E	0x0040
#define RW	0x0020
#define CleanSet 0x0000

#define GOTO_LINE_1 0x8000
#define GOTO_LINE_2 0xC000

void delay1(unsigned int nCount);
void CheckBusy(void);
void WriteData(unsigned short int i);
void WriteIns(unsigned short int instruction);
void WriteString(char *p);
void gotoxy(unsigned int x, unsigned int y);
void InitialLCD(void);
