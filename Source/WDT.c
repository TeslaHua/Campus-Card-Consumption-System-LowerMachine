/******************************************************************
*����:���ļ��ж����˲���WDT�����к���
*
*******************************************************************/
#include "include.h"

/*
 * WDT_Enabled
 * WDT��ʼ������
 * 
 * ����:
 *    clksou--ʱ��Դѡ��
 *      |__ACLK          --����ʱ��Դ
 *      |__SMCLK        --��ϵͳʱ��Դ
 *
 * ���:
 *   ��
 */
void WDT_Enabled(CLKx clksou)
{
	//ʱ��Դѡ��
	switch(clksou)
		{
			case ACLK:{
					WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTSSEL(1);
				}
			break;
			case SMCLK:{
					WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTSSEL(0);
				}
			break;
		}
	//����WDT
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTHOLD(0)+WDT_WDTCTL_WDTTMSEL(0);
	
}


/*
 * WDT_Disabled
 * WDT�رպ���
 * 
 * ����:
 *
 * ���:
 *   ��
 */
void WDT_Disabled(void)
{
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTHOLD(1);
}


/*
 * WDT_Clear.
 * WDT���������㺯��
 * 
 * ����:
 *
 * ���:
 *   ��
 */
void WDT_Clear(void)
{
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTCNTCL(1);
}























