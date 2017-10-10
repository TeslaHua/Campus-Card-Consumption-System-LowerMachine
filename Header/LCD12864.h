#ifndef __LCD12864_H
#define __LCD12864_H


/*
第一行地址：80H 81H 82H 83H 84H 85H 86H 87H 
第二行地址：90H 91H 92H 93H 94H 95H 96H 97H
第三行地址：88H 89H 8AH 8BH 8CH 8DH 8EH 8FH
第四行地址：98H 99H 9AH 9BH 9CH 9DH 9EH 9FH
*/
void Delay_1ms(void);  //延时约1ms的时间
void Delay_Nms(uint32 n);  //延时N毫秒
void Write_Cmd(uint8 cod); //写命令
void Write_Data(uint8 dat); //写数据
void Init_Lcd(void);   //液晶初始化
void Display(uint8 addr,uint8 * pt);  //往液晶写字符串
void DisplayChar(uint8 addr,uint8 number);  //往液晶写字符

#endif