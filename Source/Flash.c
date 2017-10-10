/******************************************************************
*描述:此文件包含操作Flash的所有函数
*
*******************************************************************/
#include "include.h"


/*
 * Flash_WriteB
 * Flash写一个字节函数
 * 
 * 参数:
 *    address--地址
 *      |__F000h~F03Fh       --64B
 *    data8--待写入的数据
 *
 * 输出:
 *   无
 */
void Flash_WriteB(uint8 *address,uint8 data8)
{
	Flash_FCTL1 = 0xA500+0x0002;  //允许擦除
	Flash_FCTL3 = 0xA500;  //解锁
	*address = 0;   //启动擦除
	Flash_FCTL1 = 0xA500+0x0040;  //允许写
	*address = data8;  //写入数据
	Flash_FCTL1 = 0xA500;
	Flash_FCTL3 = 0xA500+0x0010;  //锁定
}


/*
 * Flash_ReadB
 * Flash读一个字节函数
 * 
 * 参数:
 *    address--地址
 *      |__F000h~F03Fh       --64B
 * 输出:
 *      读到的一字节数据
 */
uint8 Flash_ReadB(uint8 *address)
{
	return *address;
}




/*
 * Flash_Write
 * Flash写一串字符函数
 * 
 * 参数:
 *    address--首地址
 *      |__F000h~F03Fh       --64B
 *    data8--待写入的数据的首地址
 *    length--待写入的数据的长度
 * 输出:
 *   无
 */
void Flash_Write(uint8 *address,uint8 *data8,uint8 length)
{
	
	Flash_FCTL1 = 0xA500+0x0002;  //允许擦除
	Flash_FCTL3 = 0xA500;  //解锁
	*address = 0;   //启动擦除
	Flash_FCTL1 = 0xA500+0x0040;  //允许写
	while(length--)     //写入数据
		{
			*address = *data8;
			address++;
			data8++;
		}
	Flash_FCTL1 = 0xA500;
	Flash_FCTL3 = 0xA500+0x0010;  //锁定
}


/*
 * Flash_Read
 * Flash读一串字符函数
 * 
 * 参数:
 *    address--首地址
 *      |__F000h~F03Fh       --64B
 *    data8--存放数据的首地址
 *    length--待读数据的长度
 * 输出:
 *   无
 */
void Flash_Read(uint8 *address,uint8 *data8,uint8 length)
{
	uint8 i;
	for(i=0;i<length;i++)
		{
			data8[i] = address[i];
		}
}























