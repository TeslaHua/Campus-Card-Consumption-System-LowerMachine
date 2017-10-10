/******************************************************************
*描述:此文件中定义了操作WDT的所有函数
*
*******************************************************************/
#include "include.h"

/*
 * WDT_Enabled
 * WDT初始化函数
 * 
 * 参数:
 *    clksou--时钟源选择
 *      |__ACLK          --辅助时钟源
 *      |__SMCLK        --从系统时钟源
 *
 * 输出:
 *   无
 */
void WDT_Enabled(CLKx clksou)
{
	//时钟源选择
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
	//开启WDT
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTHOLD(0)+WDT_WDTCTL_WDTTMSEL(0);
	
}


/*
 * WDT_Disabled
 * WDT关闭函数
 * 
 * 参数:
 *
 * 输出:
 *   无
 */
void WDT_Disabled(void)
{
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTHOLD(1);
}


/*
 * WDT_Clear.
 * WDT计数器清零函数
 * 
 * 参数:
 *
 * 输出:
 *   无
 */
void WDT_Clear(void)
{
	WDT_WDTCTL = 0x5A00+WDT_WDTCTL_WDTCNTCL(1);
}























