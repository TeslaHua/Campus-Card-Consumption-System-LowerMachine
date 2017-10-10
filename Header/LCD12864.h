#ifndef __LCD12864_H
#define __LCD12864_H


/*
��һ�е�ַ��80H 81H 82H 83H 84H 85H 86H 87H 
�ڶ��е�ַ��90H 91H 92H 93H 94H 95H 96H 97H
�����е�ַ��88H 89H 8AH 8BH 8CH 8DH 8EH 8FH
�����е�ַ��98H 99H 9AH 9BH 9CH 9DH 9EH 9FH
*/
void Delay_1ms(void);  //��ʱԼ1ms��ʱ��
void Delay_Nms(uint32 n);  //��ʱN����
void Write_Cmd(uint8 cod); //д����
void Write_Data(uint8 dat); //д����
void Init_Lcd(void);   //Һ����ʼ��
void Display(uint8 addr,uint8 * pt);  //��Һ��д�ַ���
void DisplayChar(uint8 addr,uint8 number);  //��Һ��д�ַ�

#endif