/******************************************************************
*����:���ļ��ж����˲���ʱ�ӵ����к���
*
*******************************************************************/
#include "include.h"

uint32 _ACLK;
uint32 _MCLK;
uint32 _SMCLK;

/*
 * XT1CLK_Init
 * XT1CLKͨ�ó�ʼ������
 * 
 * ����:
 *    ��
 * ���:
 *    ��
 */
void XT1CLK_Init(void)
{
	CLK_BCSCTL1 = CLK_BCSCTL1&(~((uint8)(1)<<CLK_BCSCTL1_XTS_SHIFT)); //XTS=0��Ƶģʽ
}

/*
 * XT2CLK_Init
 * XT2CLKͨ�ó�ʼ������
 * 
 * ����:
 *    key--XT2CLK����
 *     |__0         --�ر�XT2CLK        
 *     |__1         --����XT2CLK
 * ���:
 *    ��
 */
void XT2CLK_Init(uint8 key)
{
	if(key)
		{
			CLK_BCSCTL1 &= ~((uint8)(1)<<CLK_BCSCTL1_XT2OFF_SHIFT);  //XT2OFF=0
		}
	else
		{
			CLK_BCSCTL1 |= ((uint8)(1)<<CLK_BCSCTL1_XT2OFF_SHIFT);  //XT2OFF=1
		}
}


 /*
  * CLK_Init
  * CLKͨ�ó�ʼ������
  * 
  * ����:
  *           ��
  * ���:
  *           �� 
  */
void CLK_Init(void)
{      
       unsigned int qq;
       WDTCTL     = WDTPW + WDTHOLD                                     ; // �ؿ��Ź�
       BCSCTL1 &= ~XT2OFF;           //��XT2���پ�������(�ⲿ8M����)  
       do
       {
          IFG1 &= ~OFIFG;           //Clear oscFault flag�������ʧЧ��־
          for(qq=0xff;qq>0;qq--);
       }while((IFG1&OFIFG));       //oscFault flag still set
          
       BCSCTL2 |= SELM_2;          //MCLK=XT2
       //BCSCTL2 |= DIVM_0;        //����MCLK����Ƶ,Ĭ��
          
       BCSCTL2 |= SELS;            //SMCLK=XT2
       //BCSCTL2 |= DIVS_0;        //����SMCLK����Ƶ,Ĭ��
}


















