/******************************************************************
*����:���ļ���������Flash�����к���
*
*******************************************************************/
#include "include.h"


/*
 * Flash_WriteB
 * Flashдһ���ֽں���
 * 
 * ����:
 *    address--��ַ
 *      |__F000h~F03Fh       --64B
 *    data8--��д�������
 *
 * ���:
 *   ��
 */
void Flash_WriteB(uint8 *address,uint8 data8)
{
	Flash_FCTL1 = 0xA500+0x0002;  //�������
	Flash_FCTL3 = 0xA500;  //����
	*address = 0;   //��������
	Flash_FCTL1 = 0xA500+0x0040;  //����д
	*address = data8;  //д������
	Flash_FCTL1 = 0xA500;
	Flash_FCTL3 = 0xA500+0x0010;  //����
}


/*
 * Flash_ReadB
 * Flash��һ���ֽں���
 * 
 * ����:
 *    address--��ַ
 *      |__F000h~F03Fh       --64B
 * ���:
 *      ������һ�ֽ�����
 */
uint8 Flash_ReadB(uint8 *address)
{
	return *address;
}




/*
 * Flash_Write
 * Flashдһ���ַ�����
 * 
 * ����:
 *    address--�׵�ַ
 *      |__F000h~F03Fh       --64B
 *    data8--��д������ݵ��׵�ַ
 *    length--��д������ݵĳ���
 * ���:
 *   ��
 */
void Flash_Write(uint8 *address,uint8 *data8,uint8 length)
{
	
	Flash_FCTL1 = 0xA500+0x0002;  //�������
	Flash_FCTL3 = 0xA500;  //����
	*address = 0;   //��������
	Flash_FCTL1 = 0xA500+0x0040;  //����д
	while(length--)     //д������
		{
			*address = *data8;
			address++;
			data8++;
		}
	Flash_FCTL1 = 0xA500;
	Flash_FCTL3 = 0xA500+0x0010;  //����
}


/*
 * Flash_Read
 * Flash��һ���ַ�����
 * 
 * ����:
 *    address--�׵�ַ
 *      |__F000h~F03Fh       --64B
 *    data8--������ݵ��׵�ַ
 *    length--�������ݵĳ���
 * ���:
 *   ��
 */
void Flash_Read(uint8 *address,uint8 *data8,uint8 length)
{
	uint8 i;
	for(i=0;i<length;i++)
		{
			data8[i] = address[i];
		}
}























