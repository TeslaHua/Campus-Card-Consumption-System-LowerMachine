/******************************************************************
*描述:此文件包含操作UART的所有函数
*
*******************************************************************/
#ifndef __UART_H
#define __UART_H

//UART模块中断回调函数类型
typedef void (*UART_ISR_CALLBACK)(void);

void tochar(uint8 id);
void UART_Init(UARTx uartx);  //串口初始化
uint8 Get1Char(UARTx uartx);         //接收PC的一个字节
void Send1Char(UARTx uartx ,uint8 sendchar);//像PC发送一个字节
void PutString(UARTx uartx,uint8 *ptr);   //像PC发送字符串并换行
void UART_RIE_Enable(UARTx uartx, UART_ISR_CALLBACK isr_func); //使能中断
void UART_RIE_Disable(UARTx uartx);  //失能中断
void UART1_GetCharINT(void);   //中断方式接收一个字节
void BuzzerOn1s(void);         //蜂鸣器报警




#endif




