/******************************************************************
*描述:此文件中定义了操作时钟的所有函数
*
*******************************************************************/
#ifndef __CLK_H
#define __CLK_H

extern uint32 _ACLK;
extern uint32 _MCLK;
extern uint32 _SMCLK;


void XT1CLK_Init(void);
void XT2CLK_Init(uint8 key);
void CLK_Init(void);








#endif





