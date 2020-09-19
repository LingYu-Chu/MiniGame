#ifndef __WT59F064_H__
#define __WT59F064_H__

void initIntr();
void GIE_ENABLE();

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                0x0001
#define BIT1                0x0002
#define BIT2                0x0004
#define BIT3                0x0008
#define BIT4                0x0010
#define BIT5                0x0020
#define BIT6                0x0040
#define BIT7                0x0080
#define BIT8                0x0100
#define BIT9                0x0200
#define BITA                0x0400
#define BITB                0x0800
#define BITC                0x1000
#define BITD                0x2000
#define BITE                0x4000
#define BITF                0x8000

#define FALSE               0x0000
#define TURE                0x0001

/************************************************************
* name:     PWM0~PWM3 Base Address
* desc:     PWM0~PWM3 Controller Registers
* baseAddr: 0x001F5C00
************************************************************/

#define PWM0_PWM3_ENABLE    *((unsigned int *) 0x001F5C00)  // PWM0~PWM3 enable register
#define PWM0_PWM3_BASE_CLK  *((unsigned int *) 0x001F5C04)  // PWM0~PWM3 base clock registers
#define PWM0_CLOCK          *((unsigned int *) 0x001F5C08)  // PWM0 clock register
#define PWM1_CLOCK          *((unsigned int *) 0x001F5C0C)  // PWM1 clock register
#define PWM2_CLOCK          *((unsigned int *) 0x001F5C10)  // PWM2 clock register
#define PWM3_CLOCK          *((unsigned int *) 0x001F5C14)  // PWM3 clock register
#define PWM0_DUTY           *((unsigned int *) 0x001F5C18)  // PWM0 duty register
#define PWM1_DUTY           *((unsigned int *) 0x001F5C1C)  // PWM1 duty register
#define PWM2_DUTY           *((unsigned int *) 0x001F5C20)  // PWM2 duty register
#define PWM3_DUTY           *((unsigned int *) 0x001F5C24)  // PWM3 duty register
#define PWM0_PERIOD         *((unsigned int *) 0x001F5C28)  // PWM0 period register
#define PWM1_PERIOD         *((unsigned int *) 0x001F5C2C)  // PWM1 period register
#define PWM2_PERIOD         *((unsigned int *) 0x001F5C30)  // PWM2 period register
#define PWM3_PERIOD         *((unsigned int *) 0x001F5C34)  // PWM3 period register

/************************************************************
* name:     PWM4~PWM7 Base Address
* desc:     PWM0~PWM3 Controller Registers
* baseAddr: 0x001F6000
************************************************************/

#define PWM4_PWM7_ENABLE    *((unsigned int *) 0x001F6000)  // PWM4~PWM7 enable register
#define PWM4_PWM7_BASE_CLK  *((unsigned int *) 0x001F6004)  // PWM4~PWM7 base clock register
#define PWM4_CLOCK          *((unsigned int *) 0x001F6008)  // PWM4 clock register
#define PWM5_CLOCK          *((unsigned int *) 0x001F600C)  // PWM5 clock register
#define PWM6_CLOCK          *((unsigned int *) 0x001F6010)  // PWM6 clock register
#define PWM7_CLOCK          *((unsigned int *) 0x001F6014)  // PWM7 clock register
#define PWM4_DUTY           *((unsigned int *) 0x001F6018)  // PWM4 duty register
#define PWM5_DUTY           *((unsigned int *) 0x001F601C)  // PWM5 duty register
#define PWM6_DUTY           *((unsigned int *) 0x001F6020)  // PWM6 duty register
#define PWM7_DUTY           *((unsigned int *) 0x001F6024)  // PWM7 duty register
#define PWM4_PERIOD         *((unsigned int *) 0x001F6028)  // PWM4 period register
#define PWM5_PERIOD         *((unsigned int *) 0x001F602C)  // PWM5 period register
#define PWM6_PERIOD         *((unsigned int *) 0x001F6030)  // PWM6 period register
#define PWM7_PERIOD         *((unsigned int *) 0x001F6034)  // PWM7 period register

/************************************************************
* name:     GPIO Port A Base Address
* desc:     GPIO Port A Controller Register
* baseAddr: 0x001F6800
************************************************************/

#define GPIO_ACT_PA           *((unsigned int *) 0x001F6800)  // GPIO port A act register
#define GPIO_OEN_PA           *((unsigned int *) 0x001F6804)  // GPIO port A output enable register
#define GPIO_OMOD_PA          *((unsigned int *) 0x001F6808)  // GPIO port A output mode register
#define PAD_PA		          *((unsigned int *) 0x001F680C)  // GPIO port A input data register
#define GPIO_DAT_PA           *((unsigned int *) 0x001F6810)  // GPIO port A output data register
#define GPIO_REN_PA           *((unsigned int *) 0x001F6814)  // GPIO port A input pull resister enable register
#define GPIO_RS_PA            *((unsigned int *) 0x001F6818)  // GPIO port A inpu pull-up/pull-down select register
#define GPIO_BR_PA            *((unsigned int *) 0x001F681C)  // Reset GPIO port A output data register
#define GPIO_BS_PA            *((unsigned int *) 0x001F6820)  // Set GPIO port A output data register

/************************************************************
* name:     GPIO Port B Base Address
* desc:     GPIO Port B Controller Register
* baseAddr: 0x001F6880
************************************************************/

#define GPIO_ACT_PB           *((unsigned int *) 0x001F6880)  // GPIO port B act register
#define GPIO_OEN_PB           *((unsigned int *) 0x001F6884)  // GPIO port B output enable register
#define GPIO_OMOD_PB          *((unsigned int *) 0x001F6888)  // GPIO port B output mode register
#define PAD_PB                *((unsigned int *) 0x001F688C)  // GPIO port B input data register
#define GPIO_DAT_PB           *((unsigned int *) 0x001F6890)  // GPIO port B output data register
#define GPIO_REN_PB           *((unsigned int *) 0x001F6894)  // GPIO port B input pull resister enable register
#define GPIO_RS_PB            *((unsigned int *) 0x001F6898)  // GPIO port B inpu pull-up/pull-down select register
#define GPIO_BR_PB            *((unsigned int *) 0x001F689C)  // Reset GPIO port B output data register
#define GPIO_BS_PB            *((unsigned int *) 0x001F68A0)  // Set GPIO port B output data register

/************************************************************
* name:     GPIO Port C Base Address
* desc:     GPIO Port C Controller Register
* baseAddr: 0x001F6900
************************************************************/

#define GPIO_ACT_PC           *((unsigned int *) 0x001F6900)  // GPIO port C act register
#define GPIO_OEN_PC           *((unsigned int *) 0x001F6904)  // GPIO port C output enable register
#define GPIO_OMOD_PC          *((unsigned int *) 0x001F6908)  // GPIO port C output mode register
#define PAD_PC                *((unsigned int *) 0x001F690C)  // GPIO port C input data register
#define GPIO_DAT_PC           *((unsigned int *) 0x001F6910)  // GPIO port C output data register
#define GPIO_REN_PC           *((unsigned int *) 0x001F6914)  // GPIO port C input pull resister enable register
#define GPIO_RS_PC            *((unsigned int *) 0x001F6918)  // GPIO port C inpu pull-up/pull-down select register
#define GPIO_BR_PC            *((unsigned int *) 0x001F691C)  // Reset GPIO port C output data register
#define GPIO_BS_PC            *((unsigned int *) 0x001F6920)  // Set GPIO port C output data register

/************************************************************
* name:     GPIO Port D Base Address
* desc:     GPIO Port D Controller Register
* baseAddr: 0x001F6980
************************************************************/

#define GPIO_ACT_PD           *((unsigned int *) 0x001F6980)  // GPIO port D act register
#define GPIO_OEN_PD           *((unsigned int *) 0x001F6984)  // GPIO port D output enable register
#define GPIO_OMOD_PD          *((unsigned int *) 0x001F6988)  // GPIO port D output mode register
#define PAD_PD                *((unsigned int *) 0x001F698C)  // GPIO port D input data register
#define GPIO_DAT_PD           *((unsigned int *) 0x001F6990)  // GPIO port D output data register
#define GPIO_REN_PD           *((unsigned int *) 0x001F6994)  // GPIO port D input pull resister enable register
#define GPIO_RS_PD            *((unsigned int *) 0x001F6998)  // GPIO port D inpu pull-up/pull-down select register
#define GPIO_BR_PD            *((unsigned int *) 0x001F699C)  // Reset GPIO port D output data register
#define GPIO_BS_PD            *((unsigned int *) 0x001F69A0)  // Set GPIO port D output data register

/************************************************************
* name:     GPIO Port E Base Address
* desc:     GPIO Port E Controller Register
* baseAddr: 0x001F6A00
************************************************************/

#define GPIO_ACT_PE           *((unsigned int *) 0x001F6A00)  // GPIO port E act register
#define GPIO_OEN_PE           *((unsigned int *) 0x001F6A04)  // GPIO port E output enable register
#define GPIO_OMOD_PE          *((unsigned int *) 0x001F6A08)  // GPIO port E output mode register
#define PAD_PE                *((unsigned int *) 0x001F6A0C)  // GPIO port E input data register
#define GPIO_DAT_PE           *((unsigned int *) 0x001F6A10)  // GPIO port E output data register
#define GPIO_REN_PE           *((unsigned int *) 0x001F6A14)  // GPIO port E input pull resister enable register
#define GPIO_RS_PE            *((unsigned int *) 0x001F6A18)  // GPIO port E inpu pull-up/pull-down select register
#define GPIO_BR_PE            *((unsigned int *) 0x001F6A1C)  // Reset GPIO port E output data register
#define GPIO_BS_PE            *((unsigned int *) 0x001F6A20)  // Set GPIO port E output data register

/************************************************************
* System Register
************************************************************/

#define System_Control_00   *((unsigned int *) 0x00200000)  // System Control Register Index 00
#define System_Control_04   *((unsigned int *) 0x00200004)  // System Control Register Index 04
#define System_Control_08   *((unsigned int *) 0x00200008)  // System Control Register Index 08
#define System_Control_0C   *((unsigned int *) 0x0020000C)  // System Control Register Index 0C
#define System_Control_10   *((unsigned int *) 0x00200010)  // System Control Register Index 10
#define System_Control_14   *((unsigned int *) 0x00200014)  // System Control Register Index 14
#define System_Control_18   *((unsigned int *) 0x00200018)  // System Control Register Index 18
#define System_Control_1C   *((unsigned int *) 0x0020001C)  // System Control Register Index 1C
#define System_Control_20   *((unsigned int *) 0x00200020)  // System Control Register Index 20
#define System_Control_24   *((unsigned int *) 0x00200024)  // System Control Register Index 24
#define System_Control_28   *((unsigned int *) 0x00200028)  // System Control Register Index 28
#define System_Control_2C   *((unsigned int *) 0x0020002C)  // System Control Register Index 2C
#define System_Control_30   *((unsigned int *) 0x00200030)  // System Control Register Index 30

/************************************************************
* Interrupt
************************************************************/

#define IE0_0               *((unsigned int *) 0x00200D00)  // Interrupt 0 Enable Control 0
#define IE0_1               *((unsigned int *) 0x00200D04)  // Interrupt 0 Enable Control 1
#define IE1_0               *((unsigned int *) 0x00200D08)  // Interrupt 1 Enable Control 0
#define IE1_1               *((unsigned int *) 0x00200D0C)  // Interrupt 1 Enable Control 1

#define IF0_0               *((unsigned int *) 0x00200D10)  // Interrupt 0 Flag Control 0
#define IF0_1               *((unsigned int *) 0x00200D14)  // Interrupt 0 Flag Control 1
#define IF1_0               *((unsigned int *) 0x00200D18)  // Interrupt 1 Flag Control 0
#define IF1_1               *((unsigned int *) 0x00200D1C)  // Interrupt 1 Flag Control 1

/************************************************************
* UART 0/1
************************************************************/

#define UART0_Control_Reg_1 *((unsigned int *) 0x00203400)  // UART0 Control Register 1
#define UART0_Control_Reg_2 *((unsigned int *) 0x00203404)  // UART0 Control Register 2
#define UART0_Status_Reg    *((unsigned int *) 0x00203408)  // UART0 Status Register
#define UART0_TxData_Reg    *((unsigned int *) 0x0020340C)  // UART0 Transmit Data Register
#define UART0_RxData_Reg    *((unsigned int *) 0x00203410)  // UART0 Receive Data Register
#define UART0_BaudRate_Reg  *((unsigned int *) 0x00203414)  // UART0 Baud Rate Register
#define UART0_Break_Reg     *((unsigned int *) 0x00203418)  // UART0 Break Register

#define UART1_Control_Reg_1 *((unsigned int *) 0x00203800)  // UART1 Control Register 1
#define UART1_Control_Reg_2 *((unsigned int *) 0x00203804)  // UART1 Control Register 2
#define UART1_Status_Reg    *((unsigned int *) 0x00203808)  // UART1 Status Register
#define UART1_TxData_Reg    *((unsigned int *) 0x0020380C)  // UART1 Transmit Data Register
#define UART1_RxData_Reg    *((unsigned int *) 0x00203810)  // UART1 Receive Data Register
#define UART1_BaudRate_Reg  *((unsigned int *) 0x00203814)  // UART1 Baud Rate Register
#define UART1_Break_Reg     *((unsigned int *) 0x00203818)  // UART1 Break Register

/************************************************************
* UART 2/3
************************************************************/

#define UART2_Control_Reg_1 *((unsigned int *) 0x00203C00)  // UART2 Control Register 1
#define UART2_Control_Reg_2 *((unsigned int *) 0x00203C04)  // UART2 Control Register 2
#define UART2_Status_Reg    *((unsigned int *) 0x00203C08)  // UART2 Status Register
#define UART2_TxData_Reg    *((unsigned int *) 0x00203C0C)  // UART2 Transmit Data Register
#define UART2_RxData_Reg    *((unsigned int *) 0x00203C10)  // UART2 Receive Data Register
#define UART2_BaudRate_Reg  *((unsigned int *) 0x00203C14)  // UART2 Baud Rate Register
#define UART2_Break_Reg     *((unsigned int *) 0x00203C18)  // UART2 Break Register

#define UART3_Control_Reg_1 *((unsigned int *) 0x00204000)  // UART3 Control Register 1
#define UART3_Control_Reg_2 *((unsigned int *) 0x00204004)  // UART3 Control Register 2
#define UART3_Status_Reg    *((unsigned int *) 0x00204008)  // UART3 Status Register
#define UART3_TxData_Reg    *((unsigned int *) 0x0020400C)  // UART3 Transmit Data Register
#define UART3_RxData_Reg    *((unsigned int *) 0x00204010)  // UART3 Receive Data Register
#define UART3_BaudRate_Reg  *((unsigned int *) 0x00204014)  // UART3 Baud Rate Register
#define UART3_Break_Reg     *((unsigned int *) 0x00204018)  // UART3 Break Register

/************************************************************
* Real Time Clock (RTC)
************************************************************/

#define RTC_SEC             *((unsigned int *) 0x00201000)  // Second coded in BCD
#define RTC_MIN             *((unsigned int *) 0x00201004)  // Minute coded in BCD
#define RTC_HOUR            *((unsigned int *) 0x00201008)  // Hour coded in BCD
#define RTC_DAY             *((unsigned int *) 0x0020100C)  // Day of month coded in BCD
#define RTC_WEEK            *((unsigned int *) 0x00201010)  // Day of week
#define RTC_MONTH           *((unsigned int *) 0x00201014)  // Month
#define RTC_YEAR            *((unsigned int *) 0x00201018)  // Year coded in BCD
#define RTC_BACKUP1         *((unsigned int *) 0x00201020)  // Back up register 1
#define RTC_BACKUP2         *((unsigned int *) 0x00201024)  // Back up register 2
#define RTC_BACKUP3         *((unsigned int *) 0x00201028)  // Back up register 3
#define RTC_BACKUP4         *((unsigned int *) 0x0020102C)  // Back up register 4
#define RTC_AMP             *((unsigned int *) 0x00201030)  // Amplifier stages options to adjust current
#define RTC_CA              *((unsigned int *) 0x00201034)  // Calibration bits
#define RTC_Control_0       *((unsigned int *) 0x00201038)  // RTC Control Register 0
#define RTC_Control_1       *((unsigned int *) 0x0020103C)  // RTC Control Register 1

/************************************************************
* IR Remote Control
************************************************************/

#define IR_EN               *((unsigned int *) 0x00201800)  // IR Control Register
#define IR_HL               *((unsigned int *) 0x00201804)  // Read IR input H/L
#define IR_CNT              *((unsigned int *) 0x00201808)  // IR counter
#define IR_FILTER           *((unsigned int *) 0x0020180C)  // IR digital filter

/************************************************************
* Timer 0
************************************************************/

#define TIM0_CTL            *((unsigned int *) 0x00201C00)  // Timer 0 Control Register
#define TIM0_CNT            *((unsigned int *) 0x00201C04)  // Timer 0 Counter
#define TIM0_PSCL           *((unsigned int *) 0x00201C08)  // Timer 0 Prescale setting
#define TIM0_PCNT           *((unsigned int *) 0x00201C0C)  // Timer 0 Prescale counter
#define TIM0_CCTL           *((unsigned int *) 0x00201C10)  // Timer 0 Capture Control
#define TIM0_CICTL          *((unsigned int *) 0x00201C14)  // Timer 0 Capture Operation
#define TIM0_MCTL           *((unsigned int *) 0x00201C18)  // Timer 0 Match Control
#define TIM0_MOCTL          *((unsigned int *) 0x00201C1C)  // Timer 0 Match Counter
#define TIM0_MAT0A          *((unsigned int *) 0x00201C30)  // Timer 0 Match 0 A Register
#define TIM0_MAT0B          *((unsigned int *) 0x00201C34)  // Timer 0 Match 0 B Register
#define TIM0_MAT1A          *((unsigned int *) 0x00201C38)  // Timer 0 Match 1 A Register
#define TIM0_MAT1B          *((unsigned int *) 0x00201C3C)  // Timer 0 Match 1 B Register
#define TIM0_OFIF           *((unsigned int *) 0x00201C40)  // Timer 0 Overflow and interrupt flags
#define TIM0_IE             *((unsigned int *) 0x00201C44)  // Timer 0 Interrupt Enable
#define TIM0_RF             *((unsigned int *) 0x00201C48)  // Timer 0 DMA Request flag
#define TIM0_RE             *((unsigned int *) 0x00201C4C)  // Timer 0 DMA Request enable

/************************************************************
* Timer 1
************************************************************/

#define TIM1_CTL            *((unsigned int *) 0x00202000)  // Timer 1 Control Register
#define TIM1_CNT            *((unsigned int *) 0x00202004)  // Timer 1 Counter
#define TIM1_PSCL           *((unsigned int *) 0x00202008)  // Timer 1 Prescale setting
#define TIM1_PCNT           *((unsigned int *) 0x0020200C)  // Timer 1 Prescale counter
#define TIM1_CCTL           *((unsigned int *) 0x00202010)  // Timer 1 Capture Control
#define TIM1_CICTL          *((unsigned int *) 0x00202014)  // Timer 1 Capture Operation
#define TIM1_MCTL           *((unsigned int *) 0x00202018)  // Timer 1 Match Control
#define TIM1_MOCTL          *((unsigned int *) 0x0020201C)  // Timer 1 Match Counter
#define TIM1_MAT0A          *((unsigned int *) 0x00202030)  // Timer 1 Match 0 A Register
#define TIM1_MAT0B          *((unsigned int *) 0x00202034)  // Timer 1 Match 0 B Register
#define TIM1_MAT1A          *((unsigned int *) 0x00202038)  // Timer 1 Match 1 A Register
#define TIM1_MAT1B          *((unsigned int *) 0x0020203C)  // Timer 1 Match 1 B Register
#define TIM1_OFIF           *((unsigned int *) 0x00202040)  // Timer 1 Overflow and interrupt flags
#define TIM1_IE             *((unsigned int *) 0x00202044)  // Timer 1 Interrupt Enable
#define TIM1_RF             *((unsigned int *) 0x00202048)  // Timer 1 DMA Request flag
#define TIM1_RE             *((unsigned int *) 0x0020204C)  // Timer 1 DMA Request enable

/************************************************************
* Timer 2
************************************************************/

#define TIM2_CTL            *((unsigned int *) 0x00202400)  // Timer 2 Control Register
#define TIM2_CNT            *((unsigned int *) 0x00202404)  // Timer 2 Counter
#define TIM2_PSCL           *((unsigned int *) 0x00202408)  // Timer 2 Prescale setting
#define TIM2_PCNT           *((unsigned int *) 0x0020240C)  // Timer 2 Prescale counter
#define TIM2_CCTL           *((unsigned int *) 0x00202410)  // Timer 2 Capture Control
#define TIM2_CICTL          *((unsigned int *) 0x00202414)  // Timer 2 Capture Operation
#define TIM2_MCTL           *((unsigned int *) 0x00202418)  // Timer 2 Match Control
#define TIM2_MOCTL          *((unsigned int *) 0x0020241C)  // Timer 2 Match Counter
#define TIM2_MAT0A          *((unsigned int *) 0x00202430)  // Timer 2 Match 0 A Register
#define TIM2_MAT0B          *((unsigned int *) 0x00202434)  // Timer 2 Match 0 B Register
#define TIM2_MAT1A          *((unsigned int *) 0x00202438)  // Timer 2 Match 1 A Register
#define TIM2_MAT1B          *((unsigned int *) 0x0020243C)  // Timer 2 Match 1 B Register
#define TIM2_OFIF           *((unsigned int *) 0x00202440)  // Timer 2 Overflow and interrupt flags
#define TIM2_IE             *((unsigned int *) 0x00202444)  // Timer 2 Interrupt Enable
#define TIM2_RF             *((unsigned int *) 0x00202448)  // Timer 2 DMA Request flag
#define TIM2_RE             *((unsigned int *) 0x0020244C)  // Timer 2 DMA Request enable

/************************************************************
* Timer 3
************************************************************/

#define TIM3_CTL            *((unsigned int *) 0x00202800)  // Timer 3 Control Register
#define TIM3_CNT            *((unsigned int *) 0x00202804)  // Timer 3 Counter
#define TIM3_PSCL           *((unsigned int *) 0x00202808)  // Timer 3 Prescale setting
#define TIM3_PCNT           *((unsigned int *) 0x0020280C)  // Timer 3 Prescale counter
#define TIM3_CCTL           *((unsigned int *) 0x00202810)  // Timer 3 Capture Control
#define TIM3_CICTL          *((unsigned int *) 0x00202814)  // Timer 3 Capture Operation
#define TIM3_MCTL           *((unsigned int *) 0x00202818)  // Timer 3 Match Control
#define TIM3_MOCTL          *((unsigned int *) 0x0020281C)  // Timer 3 Match Counter
#define TIM3_MAT0A          *((unsigned int *) 0x00202830)  // Timer 3 Match 0 A Register
#define TIM3_MAT0B          *((unsigned int *) 0x00202834)  // Timer 3 Match 0 B Register
#define TIM3_MAT1A          *((unsigned int *) 0x00202838)  // Timer 3 Match 1 A Register
#define TIM3_MAT1B          *((unsigned int *) 0x0020283C)  // Timer 3 Match 1 B Register
#define TIM3_OFIF           *((unsigned int *) 0x00202840)  // Timer 3 Overflow and interrupt flags
#define TIM3_IE             *((unsigned int *) 0x00202844)  // Timer 3 Interrupt Enable
#define TIM3_RF             *((unsigned int *) 0x00202848)  // Timer 3 DMA Request flag
#define TIM3_RE             *((unsigned int *) 0x0020284C)  // Timer 3 DMA Request enable

/************************************************************
* Timer 4
************************************************************/

#define TIM4_CTL            *((unsigned int *) 0x00202C00)  // Timer 4 Control Register
#define TIM4_CNT            *((unsigned int *) 0x00202C04)  // Timer 4 Counter
#define TIM4_PSCL           *((unsigned int *) 0x00202C08)  // Timer 4 Prescale setting
#define TIM4_PCNT           *((unsigned int *) 0x00202C0C)  // Timer 4 Prescale counter
#define TIM4_CCTL           *((unsigned int *) 0x00202C10)  // Timer 4 Capture Control
#define TIM4_CICTL          *((unsigned int *) 0x00202C14)  // Timer 4 Capture Operation
#define TIM4_MCTL           *((unsigned int *) 0x00202C18)  // Timer 4 Match Control
#define TIM4_MOCTL          *((unsigned int *) 0x00202C1C)  // Timer 4 Match Counter
#define TIM4_MAT0A          *((unsigned int *) 0x00202C30)  // Timer 4 Match 0 A Register
#define TIM4_MAT0B          *((unsigned int *) 0x00202C34)  // Timer 4 Match 0 B Register
#define TIM4_MAT1A          *((unsigned int *) 0x00202C38)  // Timer 4 Match 1 A Register
#define TIM4_MAT1B          *((unsigned int *) 0x00202C3C)  // Timer 4 Match 1 B Register
#define TIM4_OFIF           *((unsigned int *) 0x00202C40)  // Timer 4 Overflow and interrupt flags
#define TIM4_IE             *((unsigned int *) 0x00202C44)  // Timer 4 Interrupt Enable
#define TIM4_RF             *((unsigned int *) 0x00202C48)  // Timer 4 DMA Request flag
#define TIM4_RE             *((unsigned int *) 0x00202C4C)  // Timer 4 DMA Request enable

/************************************************************
* Timer 5
************************************************************/

#define TIM5_CTL            *((unsigned int *) 0x00203000)  // Timer 5 Control Register
#define TIM5_CNT            *((unsigned int *) 0x00203004)  // Timer 5 Counter
#define TIM5_PSCL           *((unsigned int *) 0x00203008)  // Timer 5 Prescale setting
#define TIM5_PCNT           *((unsigned int *) 0x0020300C)  // Timer 5 Prescale counter
#define TIM5_CCTL           *((unsigned int *) 0x00203010)  // Timer 5 Capture Control
#define TIM5_CICTL          *((unsigned int *) 0x00203014)  // Timer 5 Capture Operation
#define TIM5_MCTL           *((unsigned int *) 0x00203018)  // Timer 5 Match Control
#define TIM5_MOCTL          *((unsigned int *) 0x0020301C)  // Timer 5 Match Counter
#define TIM5_MAT0A          *((unsigned int *) 0x00203030)  // Timer 5 Match 0 A Register
#define TIM5_MAT0B          *((unsigned int *) 0x00203034)  // Timer 5 Match 0 B Register
#define TIM5_MAT1A          *((unsigned int *) 0x00203038)  // Timer 5 Match 1 A Register
#define TIM5_MAT1B          *((unsigned int *) 0x0020303C)  // Timer 5 Match 1 B Register
#define TIM5_OFIF           *((unsigned int *) 0x00203040)  // Timer 5 Overflow and interrupt flags
#define TIM5_IE             *((unsigned int *) 0x00203044)  // Timer 5 Interrupt Enable
#define TIM5_RF             *((unsigned int *) 0x00203048)  // Timer 5 DMA Request flag
#define TIM5_RE             *((unsigned int *) 0x0020304C)  // Timer 5 DMA Request enable

#endif
