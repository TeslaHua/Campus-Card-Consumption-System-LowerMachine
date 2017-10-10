/******************************************************************
*����:���ļ���������UART�����к���
*
*******************************************************************/
#ifndef __UART_H
#define __UART_H

//UARTģ���жϻص���������
typedef void (*UART_ISR_CALLBACK)(void);

void tochar(uint8 id);
void UART_Init(UARTx uartx);  //���ڳ�ʼ��
uint8 Get1Char(UARTx uartx);         //����PC��һ���ֽ�
void Send1Char(UARTx uartx ,uint8 sendchar);//��PC����һ���ֽ�
void PutString(UARTx uartx,uint8 *ptr);   //��PC�����ַ���������
void UART_RIE_Enable(UARTx uartx, UART_ISR_CALLBACK isr_func); //ʹ���ж�
void UART_RIE_Disable(UARTx uartx);  //ʧ���ж�
void UART1_GetCharINT(void);   //�жϷ�ʽ����һ���ֽ�
void BuzzerOn1s(void);         //����������




#endif




