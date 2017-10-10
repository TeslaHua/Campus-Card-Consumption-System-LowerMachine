/******************************************************************
*描述:此文件包含操作TA的所有函数
*
*******************************************************************/


#ifndef __TA_H
#define __TA_H


typedef void (*TA_ISR_CALLBACK)(void);

#define MODE_Timer      0
#define MODE_PLACC      1

#define TACLK           0
#define TAINCLK         3

#define IRQ_DISABLE     0
#define IRQ_ENABLE      1



void TA_PWM_Init(uint32 freq);
void TA_PWM_Open(uint8 channel, uint32 duty);
void TA_PWM_ChangeDuty(uint8 channel, uint32 duty);
void TA_Time_Init(uint8 mode, uint16 period_ms, uint8 channel, TA_ISR_CALLBACK isr_func);
void TA_ClearIsr(void);
void TA_DelayMs(uint16 period_ms);
uint16 TA_GetPulseAcc(void);
void TA_Capture_Init(uint8 cap ,uint8 channel, uint8 range);
uint32 TA_GetCapture(uint8 cap,uint8 range);
extern void TA_Clear(void);







#endif


