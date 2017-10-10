/******************************************************************
*描述:此文件包含操作TB的所有函数
*
*******************************************************************/
#ifndef __TB_H
#define __TB_H



typedef void (*TB_ISR_CALLBACK)(void);

#define MODE_Timer      0
#define MODE_PLACC      1

#define TBCLK           0
#define TBINCLK         3

#define IRQ_DISABLE     0
#define IRQ_ENABLE      1



void TB_PWM_Init(uint32 freq);
void TB_PWM_Open(uint8 channel, uint32 duty);
void TB_PWM_ChangeDuty(uint8 channel, uint32 duty);
void TB_Time_Init(uint8 mode, uint16 period_ms, TA_ISR_CALLBACK isr_func);
void TB_ClearIsr(void);
void TB_DelayMs(uint16 period_ms);
uint16 TB_GetPulseAcc(void);
void TB_Clear(void);







#endif



