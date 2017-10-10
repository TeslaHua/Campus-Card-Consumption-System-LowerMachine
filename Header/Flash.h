/******************************************************************
*描述:此文件包含操作Flash的所有函数
*
*******************************************************************/
#ifndef __FLASH_H
#define __FLASH_H


void Flash_WriteB(uint8 *address,uint8 data8);
uint8 Flash_ReadB(uint8 *address);
void Flash_Write(uint8 *address,uint8 *data8,uint8 length);
void Flash_Read(uint8 *address,uint8 *data8,uint8 length);





#endif


