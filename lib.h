/*
 * lib.h
 *
 *  Created on: 2017/5/22
 *      Author: Huang
 */

#ifndef LIB_H_
#define LIB_H_

typedef unsigned short int U16;
typedef unsigned char U8;

extern void DRV_PutChar(char u8char);
extern void DRV_Putstr(const char *pFmt);
extern void DRV_IntToStr(U16 u16Val, U8 u8Base, char *pBuf);
extern void DRV_Printf(char *pFmt , U16 u16Val);
extern void DRV_UartInitial(void);
extern char DRV_GetChar();

extern void delay1(unsigned int nCount);
extern void CheckBusy(void);
extern void WriteData(unsigned short int i);
extern void WriteIns(unsigned short int instruction);
extern void WriteString(char *p);
extern void gotoxy(unsigned int x, unsigned int y);
extern void InitialLCD(void);

extern void delay2(unsigned int nCount);
extern void KeyScan(void);
extern int gotkey();


#endif /* LIB_H_ */
