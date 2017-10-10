/******************************************************************
*描述:此文件中定义了操作时钟的所有函数
*
*******************************************************************/
#include "include.h"

uint32 _ACLK;
uint32 _MCLK;
uint32 _SMCLK;

/*
 * XT1CLK_Init
 * XT1CLK通用初始化函数
 * 
 * 参数:
 *    无
 * 输出:
 *    无
 */
void XT1CLK_Init(void)
{
	CLK_BCSCTL1 = CLK_BCSCTL1&(~((uint8)(1)<<CLK_BCSCTL1_XTS_SHIFT)); //XTS=0低频模式
}

/*
 * XT2CLK_Init
 * XT2CLK通用初始化函数
 * 
 * 参数:
 *    key--XT2CLK开关
 *     |__0         --关闭XT2CLK        
 *     |__1         --开启XT2CLK
 * 输出:
 *    无
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
  * CLK通用初始化函数
  * 
  * 参数:
  *           无
  * 输出:
  *           无 
  */
void CLK_Init(void)
{      
       unsigned int qq;
       WDTCTL     = WDTPW + WDTHOLD                                     ; // 关看门狗
       BCSCTL1 &= ~XT2OFF;           //打开XT2高速晶体振荡器(外部8M晶振)  
       do
       {
          IFG1 &= ~OFIFG;           //Clear oscFault flag清除振荡器失效标志
          for(qq=0xff;qq>0;qq--);
       }while((IFG1&OFIFG));       //oscFault flag still set
          
       BCSCTL2 |= SELM_2;          //MCLK=XT2
       //BCSCTL2 |= DIVM_0;        //控制MCLK不分频,默认
          
       BCSCTL2 |= SELS;            //SMCLK=XT2
       //BCSCTL2 |= DIVS_0;        //控制SMCLK不分频,默认
}


















