/******************************************************************
*描述:此文件包含操作TB的所有函数
*
*******************************************************************/
#include "include.h"

uint16 TBCCR0_MOD = 0;

TB_ISR_CALLBACK TB_irq = (TB_ISR_CALLBACK)NULL;


/*
 * TB_PWM_Init
 * TB模块PWM功能初始化函数
 * 
 * 参数:
 *    freq--期望频率，单位Hz
 *
 * 输出:
 *    
 */
void TB_PWM_Init(uint32 freq)
{
	uint32 mod = 0;
	uint8 ps = 0; //分频系数
	CLKx clk;

	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //清除定时器B
	if((mod=_ACLK/(freq*8))<0xFFFF)
	 {
	  ps = 3;
	  TBCCR0_MOD = mod;
	  clk = ACLK;
	  if((mod=_ACLK/(freq*4))<0xFFFF)
	   {
	   	ps = 2;
		TBCCR0_MOD = mod;
		if((mod=_ACLK/(freq*2))<0xFFFF)
		 {
		  ps = 1;
		  TBCCR0_MOD = mod;
		  if((mod=_ACLK/(freq*1))<0xFFFF)
		   {
		    ps = 0;
		    TBCCR0_MOD = mod;
		   }
		 }
	   }
	 }
	if((mod=_SMCLK/(freq*8))<0xFFFF)
	 {
	  ps = 3;
	  TBCCR0_MOD = mod;
	  clk = SMCLK;
	  if((mod=_SMCLK/(freq*4))<0xFFFF)
	   {
	   	ps = 2;
		TBCCR0_MOD = mod;
		if((mod=_SMCLK/(freq*2))<0xFFFF)
		 {
		  ps = 1;
		  TBCCR0_MOD = mod;
		  if((mod=_SMCLK/(freq*1))<0xFFFF)
		   {
		    ps = 0;
		    TBCCR0_MOD = mod;
		   }
		 }
	   }
	 }
	TB_TBCTL = 0; //关闭定时器
	TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
				TB_TBCTL_CNTLx(0)+\
				TB_TBCTL_TBSSELx(clk)+\
				TB_TBCTL_IDx(ps)+\
				TB_TBCTL_MCx(1);
		
	TB_TBCCR0 = TBCCR0_MOD;
}


/*
 * TB_PWM_Open
 * TB模块PWM输出通道及占空比配置
 * 
 * 
 * 参数:
 *    channel - PWM输出通道
 *      |__0--TB1
 *      |__1--TB2
 *      |__2--TB3
 *      |__3--TB4
 *      |__4--TB5
 *      |__5--TB6
 *    duty - PWM输出占空比
 *      |__0~10000--占空比0.00%~100.00%
 *
 * 输出:
 */
void TB_PWM_Open(uint8 channel, uint32 duty)
{
	switch(channel)
		{
			case 0:{
					TB_TBCCTL1 = TB_TBCCTLx_CLLDx(0)+\
									TB_TBCCTLx_CAP(0)+\
									TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR1 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 1:{
					TB_TBCCTL2 = TB_TBCCTLx_CLLDx(0)+\
							    TB_TBCCTLx_CAP(0)+\
								TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR2 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 2:{
					TB_TBCCTL3 = TB_TBCCTLx_CLLDx(0)+\
							    TB_TBCCTLx_CAP(0)+\
								TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR3 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 3:{
					TB_TBCCTL4 = TB_TBCCTLx_CLLDx(0)+\
							    TB_TBCCTLx_CAP(0)+\
								TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR4 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 4:{
					TB_TBCCTL5 = TB_TBCCTLx_CLLDx(0)+\
							    TB_TBCCTLx_CAP(0)+\
								TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR5 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 5:{
					TB_TBCCTL6 = TB_TBCCTLx_CLLDx(0)+\
							    TB_TBCCTLx_CAP(0)+\
								TB_TBCCTLx_OUTMODx(6);
					TB_TBCCR6 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			
		}
}

/*
 * TB_PWM_ChangeDuty
 * 改变FTM0模块PWM输出通道占空比
 *
 * 参数:
 *    channel - PWM输出通道
 *      |__0--TB1
 *      |__1--TB2
 *      |__2--TB3
 *      |__3--TB4
 *      |__4--TB5
 *      |__5--TB6
 *    duty - PWM输出占空比
 *      |__0~10000--占空比0.00%~100.00%
 *
 * 输出:
 */
void TB_PWM_ChangeDuty(uint8 channel, uint32 duty)
{
	switch(channel)
		{
			case 0:{
					TB_TBCCR1 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 1:{
					TB_TBCCR2 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 2:{
					TB_TBCCR3 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 3:{
					TB_TBCCR4 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 4:{
					TB_TBCCR5 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
			case 5:{
					TB_TBCCR6 = (uint16)((duty*TBCCR0_MOD)/10000);
				}
			break;
		}
}


/*
 * TB_Timer_Init
 * TB用作周期定时器和脉冲累加器时的初始化函数
 * 
 * 参数:
 *    mode--选择LPTMR模式
 *      |__MODE_Timer           --定时器模式
 *      |__MODE_PLACC           --脉冲累加模式
 *    period_ms--设定定时器的定时值 单位ms
 *      |__0                    --设置脉冲累加模式时选择为0
 *      |__1~65535              --1ms<= 定时周期  <=7680ms 
 *    isr_func
 *      |__低功耗定时器中断回调函数
 *  
 * 输出:
 */

void TB_Time_Init(uint8 mode, uint16 period_ms, TA_ISR_CALLBACK isr_func)
{
	uint32 mod;
	uint8 ps;
	uint16 _TBCCR0_MOD;
	CLKx clk;

	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //清除定时器B
	if(mode==MODE_Timer)  //定时器模式
		{
			if((mod=(period_ms*_ACLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TBCCR0_MOD = mod;
					clk = ACLK;
					if((mod=(period_ms*_ACLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TBCCR0_MOD = mod;
							if((mod=(period_ms*_ACLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TBCCR0_MOD = mod;
									if((mod=(period_ms*_ACLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TBCCR0_MOD = mod;
										}
								}
						}
				}
			if((mod=(period_ms*_SMCLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TBCCR0_MOD = mod;
					clk = SMCLK;
					if((mod=(period_ms*_SMCLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TBCCR0_MOD = mod;
							if((mod=(period_ms*_SMCLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TBCCR0_MOD = mod;
									if((mod=(period_ms*_SMCLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TBCCR0_MOD = mod;
										}
								}
						}
				}
			TB_TBCTL = 0; //关闭定时器
			//设置相关寄存器
			TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
						TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(clk)+\
						TB_TBCTL_IDx(ps)+\
						TB_TBCTL_MCx(1);
			TB_TBCCTL0 = TB_TBCCTLx_CCIE(1)+\
							TB_TBCCTLx_CLLDx(0);
			TB_TBCCR0 = _TBCCR0_MOD;
			//设置中断函数
			TB_irq = isr_func;
		}
	else if(mode==MODE_PLACC)  //计数器模式
		{
			
			TB_TBCTL = TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(0)+\
						TB_TBCTL_IDx(0)+\
						TB_TBCTL_MCx(2);
			
		}
}

/*
 * TB_ClearIsr
 * 清除TB用户定义的中断服务函数，并禁用中断
 * 
 * 参数:
 * 输出:
 *	无
 */
void TB_ClearIsr(void)
{
	uint16 BUF;
	BUF = TB_TBCTL;
	TB_irq = (TB_ISR_CALLBACK)NULL;
	TB_TBCTL &= ~TB_TBCTL_MCx_MASK;
	BUF &= ~TB_TBCTL_TBIE_MASK;
	TB_TBCTL &= ~TB_TBCTL_TBIE_MASK;
	TB_TBCTL =  BUF;
}


/*
 *  TB_DelayMs
 *  低功耗定时器延时n个ms
 * 
 * 参数:
 *    period_ms--设定定时器的定时值 单位ms
 *    最大65535ms
 *
 *  返回值:
 *      无
 */
void TB_DelayMs(uint16 period_ms)
{
	uint32 mod;
	uint8 ps;
	uint16 _TBCCR0_MOD;
	CLKx clk;
	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //清除定时器B
			if((mod=(period_ms*_ACLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TBCCR0_MOD = mod;
					clk = ACLK;
					if((mod=(period_ms*_ACLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TBCCR0_MOD = mod;
							if((mod=(period_ms*_ACLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TBCCR0_MOD = mod;
									if((mod=(period_ms*_ACLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TBCCR0_MOD = mod;
										}
								}
						}
				}
			if((mod=(period_ms*_SMCLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TBCCR0_MOD = mod;
					clk = SMCLK;
					if((mod=(period_ms*_SMCLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TBCCR0_MOD = mod;
							if((mod=(period_ms*_SMCLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TBCCR0_MOD = mod;
									if((mod=(period_ms*_SMCLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TBCCR0_MOD = mod;
										}
								}
						}
				}
			//设置相关寄存器
			TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
						TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(clk)+\
						TB_TBCTL_IDx(ps)+\
						TB_TBCTL_MCx(1);
			TB_TBCCR0 = _TBCCR0_MOD;
			
	//等待定时到达
	TB_TBCCTL0 &=0xFFFE;
	while((TB_TBCCTL0&0x0001)==0);
	TB_TBCCTL0 &=0xFFFE; //清除标志位
	TB_TBCTL = 0; //关闭定时器
}

/*
 *  TB_GetPulseAcc
 *  得到脉冲累加的值
 * 
 *  参数:
 *      无
 *  返回值:
 *      脉冲累加值
 */
uint16 TB_GetPulseAcc(void)
{
   return (uint16)TB_TBR;
}

/*
 * TB_Clear
 *  清空定时器TB  Counter
 * 
 *  参数:
 *      无
 *  返回值:
 *      无
 */
void TB_Clear(void)
{
	TB_TBR = 0;
}
















/************************************************中断总入口*******************************************************/

/*******************************************
函数名称：TA_Isr
功    能：TA的外部中断总入口
参    数：无
返回值  ：无
********************************************/
#pragma vector = TIMERB0_VECTOR
__interrupt void TB_Isr(void)
{
	TB_irq();
}








































