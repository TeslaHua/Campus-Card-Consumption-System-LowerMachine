/******************************************************************
*描述:此文件中定义了操作IO的所有函数
*
*******************************************************************/

#ifndef __GPIO_H
#define __GPIO_H

#define DIR_INPUT       0
#define DIR_OUTPUT      1

#define OUTPUT_L        0
#define OUTPUT_H        1

#define IO              0
#define MOD             1

#define IRQC_DIS        0x00
#define IRQC_RI         0x01
#define IRQC_FA         0x02

typedef void (*GPIO_ISR_CALLBACK)(void);

void P1_2_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir, uint8 irqc);
void P3_6_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir);
void P1_2_SetIsr(Px px,uint8 port_bit, GPIO_ISR_CALLBACK isr_func);
void P1_2_ClearIsr(Px px,uint8 port_bit);
void GPIO_Set(Px px, uint8 data8);
void GPIO_Set_b(Px px, uint8 port_bit, uint8 data1);
uint8 GPIO_Get(Px px);
uint8 GPIO_Get_b(Px px, uint8 port_bit);
//void P1_Isr(void);
//void P2_Isr(void);
void GPIO_Init(Px px,uint8 dir);
void GPIO_Toggle(Px px, uint8 data8);
void GPIO_Toggle_b(Px px, uint8 port_bit);













#endif






