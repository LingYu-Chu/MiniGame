#include "WT59F064.h"
#include <stdlib.h>
#include "lib.h"
#define To_ASCII 0x30

unsigned int note[32] = {0, 2551, 2273, 2024, 1912, 1704, 1517, 1433, 1276, 1136, 1012, 956, 851, 759, 716, 638,
						0, 2551, 2273, 2024, 1912, 1704, 1517, 1433, 1276, 1136, 1012, 956, 851, 759, 716, 638};
unsigned char win[] = {0X51,0x01,0x31,0x51,0x31,0x61,0x51,0x41,0x31,0x41,0X51,0x01,0x31,0x41,0x51,0x01,0x31,0x51,0x01,0x31,0x41,0x31,0x41,0x21,0x11,0x01};
unsigned char song[] = {0x51,0x01,0x31,0x51,0x31,0x61,0x51,0x41,0x31,0x41,0x51,0x01,0x31,0x41,0x51,0x01,0x31,0x51,0x01,0x31,0x41,0x31,0x41,0x21,0x11,0x01};
unsigned char begin[] = {0X02,0x92,0x82,0x52,0x82,0x92,0xC4,0x92,0xA2,0X92,0x52,0x82,0x01};
unsigned char lose[] = {0x12, 0x42, 0x32, 0x42, 0x22, 0x02, 0x22, 0x22, 0x42, 0x92, 0x82, 0x88, 0x02, 0x52, 0x52, 0x72,  0x72, 0x62, 0x64, 0x02, 0x62, 0x52, 0x32,0x53, 0x41, 0x42, 0x31, 0x41, 0x02, 0x42, 0x32, 0x42,0x74, 0x02, 0x12, 0x82, 0x72, 0x62, 0x52,0x01};
void note_translate (unsigned int note)
{
	PWM6_PERIOD = note;
	PWM6_DUTY = note/2;
}

void PWM_Initial(void)
{
	GPIO_ACT_PD = 0xFFFF;//GPIO portD.2 are PWM1 function.

	PWM4_PWM7_BASE_CLK = 0x3; 	// MUC Clock = 24MHz  => 2MHz
	PWM4_PWM7_ENABLE = 0x40; 	//PWM6 enable
}
void timer_delay(int cnt)
{
	int i;
	for(i=0; i<cnt; i++)
	{
		TIM0_CTL |= BIT0; // Timer Start
		while(TIM0_CNT <= 187);
		TIM0_CTL &= ~BIT0; // Timer Stop
		TIM0_CNT = 0;
	}
}

void timer_initialize()
{
	TIM0_CTL |= BITF; // Timer Enable
	TIM0_CNT = 0; //incremented every (pscl + 1) of trigger source
	TIM0_PSCL = 23999; //除頻值
	/*TIM0_MAT0A = 5; //Match mat0a register for output match mode		//試試看會不會讓他有1000次中斷一次那樣
	TIM0_IE |= BIT4; // Interrupt enable for mat0a
	IE0_0 |= BIT3;  // 1: Enable Timer 0 interrupt
	TIM0_CTL |= BIT0; // Timer Start
	*/

}

#define Digit_0	0x6000
#define Digit_1	0x4000
#define Digit_2	0x2000
#define Digit_3	0x0000
#define Digit_4	0xE000
#define Digit_5	0xC000
#define Digit_6	0xA000
#define Digit_7	0x8000

#define Number_0	0x3F3F
#define Number_1	0x0606
#define Number_2	0x5B5B
#define Number_3	0x4F4F
#define Number_4	0x6666
#define Number_5	0x6D6D
#define Number_6	0x7D7D
#define Number_7	0x2727
#define Number_8	0x7F7F
#define Number_9	0x6767
#define Number_Dot  0x8080



unsigned char input,key;
void delay1(unsigned int nCount)
{	unsigned int i;
   for(i=0;i<nCount;i++);
}

void KeyScan(void) //掃描按鍵
{
	unsigned char Col, Row;
	unsigned char ScanLine = 0x8;
	unsigned char KeyIn, temp;
	for(Col=0;Col<4;Col++)
	{
		GPIO_OMOD_PC = 0x3FF0; //輸出掃描信號Port C bit0~bit3
		GPIO_OEN_PC = 0x3FF0;
		GPIO_DAT_PC = ~ScanLine; //輸出掃描信號

		GPIO_RS_PC = 0x00FF;
		GPIO_REN_PC = 0x00FF;
		KeyIn = (PAD_PC & 0xF0); //讀取目前按鍵狀態
		delay1(10000);
		temp = (PAD_PC & 0xF0);
		if(temp == KeyIn && KeyIn != 0xF0)
			input = (PAD_PC & 0xFF); //判斷按鍵碼
			key = (PAD_PC & 0xFF);
		ScanLine >>= 1; //掃描循環
	}
}
unsigned char beat, temp;
unsigned char operator,score=0,score2=0,X,px,a,b,c,K,p1,p2;		//operator=0
unsigned int x,y,i,n,j,u,l,o,p;										//operator=1	1P發射
																	//operator=2	2P發射
void show()															//operator=3	卡卡跑丁車
{
	switch(input){
		case 0xB7:
		case 0x77:
			gotoxy(x,0);
			WriteString("=3=");
			delay1(1000);
			break;

		case 0xE7:
			for(n=3;n<=12;n++){
				gotoxy(x,n);
				WriteString("-");
				gotoxy(x,n);
				WriteString(" ");
			}
			break;

		case 0xBE:
		case 0x7E:
			gotoxy(j,13);
			WriteString("OAO");
			delay1(1000);
			break;

		case 0xEE:
			for(n=12;n>=3;n--){
				gotoxy(j,n);
				WriteString("-");
				gotoxy(j,n);
				WriteString(" ");
			}
			break;
	}
}
void show1()
{
	switch(input){
		case 0xB7:
		case 0x77:
			WriteIns(0x0100);
			gotoxy(x,0);
			WriteString("=3=");
			gotoxy(K,15);
			WriteString("M");
			gotoxy((K*-1)+3,15);
			WriteString(" ");
			delay1(1000);
			break;

		case 0x7E:
			gotoxy(x,3);
			WriteString("-");
			gotoxy(K,15);
			WriteString("M");
			gotoxy((K*-1)+3,15); //清掉怪物的另外一邊  避免出現殘影
			WriteString(" ");
			for(n=4;n<=16;n++){
				gotoxy(x,n-1);
				WriteString(" ");
				gotoxy(x,n);
				WriteString("-");
				//delay1(1000);
				}
			break;
	}
}
void monster(){

	while(1){
		X = rand()%2+1;
		gotoxy(X,15);
		WriteString("M");
		//
		site();
		//delay1(10000);
		gotoxy(X,15);
		WriteString(" ");
		K=X;
		X=0;
		break;
		}
	}
void site(){      //單人計分

	if (a==1 && operator==1){

		if(K==x){
				score+=1;
				operator=0;
		}
		else if(K!=x){
			score=score+0;
			operator=0;
		}
	}
}
void SCORE(){    //七段
	site();
	if(score==0){
			GPIO_DAT_PE = Number_0;
			GPIO_DAT_PB = Digit_0;
			delay1(1000);

		}
	if(score==1){
		GPIO_DAT_PE = Number_1;
		GPIO_DAT_PB = Digit_0;
		delay1(1000);

	}
	if(score==2){
			GPIO_DAT_PE = Number_2;
			GPIO_DAT_PB = Digit_0;
			delay1(1000);

		}
	if(score==3){
			GPIO_DAT_PE = Number_3;
			GPIO_DAT_PB = Digit_0;
			delay1(1000);

		}
	if(score==4){
			GPIO_DAT_PE = Number_4;
			GPIO_DAT_PB = Digit_0;
			delay1(1000);

		}
	if(score==5){
			GPIO_DAT_PE = Number_5;
			GPIO_DAT_PB = Digit_0;
			delay1(1000);

		}
	if(score==6){
				GPIO_DAT_PE = Number_6;
				GPIO_DAT_PB = Digit_0;
				delay1(1000);

			}
	if(score==7){
				GPIO_DAT_PE = Number_7;
				GPIO_DAT_PB = Digit_0;
				delay1(1000);

			}
	if(score==8){
				GPIO_DAT_PE = Number_8;
				GPIO_DAT_PB = Digit_0;
				delay1(1000);

			}
	if(score==9){
				GPIO_DAT_PE = Number_9;
				GPIO_DAT_PB = Digit_0;
				delay1(1000);

			}
	if(score==10){
				GPIO_DAT_PE = Number_0;
				GPIO_DAT_PB = Digit_0;
				delay1(1000000);

				GPIO_DAT_PE = Number_1;
				GPIO_DAT_PB = Digit_1;
				delay1(1000);

			}

}
void sum(){
	if(x==j && operator==1)	{	//x為1P位址	j為2P位址
		u=u+1;	//1P發射且將打中

	}
	else
		u=u+0;
	operator=0;
}
void sum1(){
	if (j==x && operator==2)	//2P發射且將打中
		l=l+1;
	else
		l=l+0;
	operator=0;
}
void num(){
	sum();
	gotoxy(2,4);
	WriteData((u/10) + To_ASCII);
	WriteData((u%10) + To_ASCII);

}
void num1(){
	sum1();
	gotoxy(2,12);
	WriteData((l/10) + To_ASCII);
	WriteData((l%10) + To_ASCII);
}



typedef struct {
		int second;
} time;
time now={0},display;
void TIMER(int time)
{
	TIM0_CNT = 0;
	TIM0_OFIF |= BIT4; // write ‘1’ to clear Interrupt flag of mat0a

	now.second++;
	if (now.second==time){
		WriteIns(0x0100);

		gotoxy(2,0);
		WriteString("=3=:");
		num();

		gotoxy(2,8);
		WriteString("OAO:");
		num1();
		if(u>l){

			gotoxy(1,3);
			WriteString("=3= WIN!");
		}
		else if(l>u){

			gotoxy(1,3);
			WriteString("OAO WIN!");

		}
		else if(l==u){

			gotoxy(1,3);
			WriteString("GAME TIE!");
		}
		operator=3;
	}
}
void TIMER1(int time) //單人時間
{
	TIM0_CNT = 0;
	TIM0_OFIF |= BIT4; // write ‘1’ to clear Interrupt flag of mat0a

	now.second++;
	if(now.second!=time && score==5){

		WriteIns(0x0100);
		gotoxy(1,0);
		WriteString("YOU WIN");
		operator=2;
	}
	if (now.second==time){

		WriteIns(0x0100);
		gotoxy(1,0);
		WriteString("YOU LOSE");
		operator=3;
	}
}
void music(){   //全家
	do{
		temp = begin[i];
		if(temp ==0)
			return 0;
		beat=temp & 0x0f;
		temp=(temp>>4) & 0x0f;
		note_translate(note[temp]);
		timer_delay(beat);
		i++;
	}while(1);
}

void Timer0_Initial(void)
{

	TIM0_CTL |= BITF;  // Timer Enable
	TIM0_CNT = 0; //incremented every (pscl + 1) of trigger source
	TIM0_PSCL = 23999; //除頻值
	TIM0_MAT0A = 1000; //Match mat0a register for output match mode
	TIM0_IE |= BIT4; // Interrupt enable for mat0a
	IE0_0 |= BIT3;  // 1: Enable Timer 0 interrupt
	TIM0_CTL |= BIT0; // Timer Start
}
void IntInitial(void)
{	initIntr();
	GIE_ENABLE();
}

void clear(int A,int B){
	gotoxy(A,B);
	WriteString("   ");
}
int main()
{
	InitialLCD();
	WriteIns(0x0100);
	WriteIns(0x0C00);	//不要游標

	GPIO_ACT_PA = 0x01FE; //Initialize GPIO_A input
	GPIO_RS_PA = 0x01FE;
	GPIO_REN_PA = 0x01FE;

	GPIO_ACT_PC = 0xFF;
    GPIO_ACT_PB = 0xFFFF; //Initialize GPIO_B
    GPIO_OMOD_PB = 0x0;
    GPIO_OEN_PB = 0x0;

    GPIO_ACT_PE = 0xFFFF; //Initialize GPIO_E
    GPIO_OMOD_PE = 0x0;
    GPIO_OEN_PE = 0x0;

    unsigned char beat, temp;

	while(1){

	unsigned short open;
	open=PAD_PA;
	if((open>>1)& 0x0001==0x0001){
		int g=0;
		input=0xFF;
		while(1){
				KeyScan();
				if(input != 0xFF){
					if(input==0xB7){
						x=1;
						gotoxy(K,15);
						WriteString("M");
						gotoxy((K*-1)+3,15);
						WriteString(" ");
						a=1;}

					if(input==0x77){
						x=2;
						gotoxy(K,15);
						WriteString("M");
						gotoxy((K*-1)+3,15);
						WriteString(" ");
						a=1;
						}
						show1();
					if(input==0x7E){
						gotoxy(K,15);
						WriteString("M");
						operator=1;
					}

					if(input==0xE7){
						int i = 0;
						System_Control_00 = ( System_Control_00 | 0x000E); // Using external crystal
						System_Control_04 = ( System_Control_04 | 0x0001);
						// Switch clock source from external crystal.
						PWM_Initial();
						timer_initialize();
						PWM6_CLOCK=1;
						WriteIns(0x0100);
						gotoxy(1,0);
						WriteString("START");
						music();
						g=1;


				}
			}
					if(operator==2){
		 i = 0;
					do{

						temp = win[i];
						if(temp ==0)
								return 0;
						beat=temp & 0x0f;
						temp=(temp>>4) & 0x0f;
						note_translate(note[temp]);
						timer_delay(beat);
							i++;
					}while(operator==2);
					}
					if(operator==3){

						do{
							temp = lose[i];
							if(temp ==0)
									return 0;
							beat=temp & 0x0f;
							temp=(temp>>4) & 0x0f;
							note_translate(note[temp]);
							timer_delay(beat);
								i++;
							}while(operator==3);
					}
				if(g==1){
					monster();
					TIMER1(90);}
				SCORE(score);
				input = 0xFF;
			}
	}
	if((open>>2)& 0x0001==0x0001){    //雙人

		KeyScan();
		if(input != 0xFF){

			if(input==0xB7){//8	1P 上
				x=1;
				clear(2,0);
			}
			if(input==0x77){	//C 下
				x=2;
				clear(1,0);
			}

			if(input==0xE7)	//0 發射
				operator=1;
			sum();	//1P分數

			if(input==0xBE){	//B	2P 上
				j=1;
				clear(2,13);
			}
			if(input==0x7E){	//F  下
				j=2;
				clear(1,13);
			}

			if(input==0xEE)	//3 發射
				operator=2;
			sum1();	//2P分數

			show();


			if(input==0xEB){		//第2個鍵 START
				int i = 0;
				System_Control_00 = ( System_Control_00 | 0x000E); // Using external crystal
				System_Control_04 = ( System_Control_04 | 0x0001);
				// Switch clock source from external crystal.
				 	PWM_Initial();
				 	timer_initialize();
					PWM6_CLOCK=1;

				gotoxy(1,0);
				WriteString("WELCOME");
				music();
				WriteIns(0x0100);
			}
		}
		if(operator==3){
			do{
				temp = song[i];	//跑跑卡丁車
				if(temp ==0)
					return 0;
				beat=temp & 0x0f;
				temp=(temp>>4) & 0x0f;
				note_translate(note[temp]);
				timer_delay(beat);
				i++;
			}while(operator==3);
		}

		TIMER(1200);
		input = 0xFF;
		}
	}
}
