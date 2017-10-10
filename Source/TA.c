/******************************************************************
*描述:此文件包含操作TA的所有函数
*
*******************************************************************/
#include "include.h"

uint16 TACCR0_MOD = 0;

TA_ISR_CALLBACK TA_irq = (TA_ISR_CALLBACK)NULL;


/*
 * TA_PWM_Init
 * TA模块PWM功能初始化函数
 * 
 * 参数:
 *    freq--期望频率，单位Hz
 *
 * 输出:
 *    
 */
void TA_PWM_Init(uint32 freq)
{
	uint32 mod = 0;
	uint8 ps = 0; //分频系数
	CLKx clk;
	TA_TACTL |= TA_TACTL_TACLR_MASK; //清除定时器A
	if((mod=_ACLK/(freq*8))<0xFFFF)
	 {
	  ps = 3;
	  TACCR0_MOD = mod;
	  clk = ACLK;
	  if((mod=_ACLK/(freq*4))<0xFFFF)
	   {
	   	ps = 2;
		TACCR0_MOD = mod;
		if((mod=_ACLK/(freq*2))<0xFFFF)
		 {
		  ps = 1;
		  TACCR0_MOD = mod;
		  if((mod=_ACLK/(freq*1))<0xFFFF)
		   {
		    ps = 0;
		    TACCR0_MOD = mod;
		   }
		 }
	   }
	 }
	if((mod=_SMCLK/(freq*8))<0xFFFF)
	 {
	  ps = 3;
	  TACCR0_MOD = mod;
	  clk = SMCLK;
	  if((mod=_SMCLK/(freq*4))<0xFFFF)
	   {
	   	ps = 2;
		TACCR0_MOD = mod;
		if((mod=_SMCLK/(freq*2))<0xFFFF)
		 {
		  ps = 1;
		  TACCR0_MOD = mod;
		  if((mod=_SMCLK/(freq*1))<0xFFFF)
		   {
		    ps = 0;
		    TACCR0_MOD = mod;
		   }
		 }
	   }
	 }
	TA_TACTL = 0; //关闭定时器
	TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
				TA_TACTL_IDx(ps)+\
				TA_TACTL_MCx(1);
	TA_TACCR0 = TACCR0_MOD;
}


/*
 * TA_PWM_Open
 * TA模块PWM输出通道及占空比配置
 * 
 * 
 * 参数:
 *    channel - PWM输出通道
 *      |__0--TA1
 *      |__1--TA2
 *    duty - PWM输出占空比
 *      |__0~10000--占空比0.00%~100.00%
 *
 * 输出:
 */
void TA_PWM_Open(uint8 channel, uint32 duty)
{
	switch(channel)
		{
			case 0:{
					TA_TACCTL1 = TA_TACCTLx_CAP(0)+\
								TA_TACCTLx_OUTMODx(6);
					TA_TACCR1 = (uint16)((duty*TACCR0_MOD)/10000);
				}
			break;
			case 1:{
					TA_TACCTL2 = TA_TACCTLx_CAP(0)+\
								TA_TACCTLx_OUTMODx(6);
					TA_TACCR2 = (uint16)((duty*TACCR0_MOD)/10000);
				}
			break;
		}
}

/*
 * TA_PWM_ChangeDuty
 * 改变FTM0模块PWM输出通道占空比
 *
 * 参数:
 *    channel - PWM输出通道
 *      |__0--TA1
 *      |__1--TA2
 *    duty - PWM输出占空比
 *      |__0~10000--占空比0.00%~100.00%
 *
 * 输出:
 */
void TA_PWM_ChangeDuty(uint8 channel, uint32 duty)
{
	switch(channel)
		{
			case 0:{
					TA_TACCR1 = (uint16)((duty*TACCR0_MOD)/10000);
				}
			break;
			case 1:{
					TA_TACCR2 = (uint16)((duty*TACCR0_MOD)/10000);
				}
			break;
		}
}


/*
 * TA_Timer_Init
 * TA用作周期定时器和脉冲累加器时的初始化函数
 * 
 * 参数:
 *    mode--选择LPTMR模式
 *      |__MODE_Timer           --定时器模式
 *      |__MODE_PLACC           --脉冲累加模式
 *    period_ms--设定定时器的定时值 单位ms
 *      |__0                    --设置脉冲累加模式时选择为0
 *      |__1~65535              --1ms<= 定时周期  <=7680ms 
 *    channel--选择累加输入通道
 *      |__0                    --设置为定时器时选择为0
 *      |__TACLK           --设置TACLK, P1.0为脉冲累加输入
 *      |__TAINCLK           --设置TAINCLK, P2.1 为脉冲累加输入
 *    isr_func
 *      |__周期定时器中断回调函数
 *  
 * 输出:
 */

void TA_Time_Init(uint8 mode, uint16 period_ms, uint8 channel, TA_ISR_CALLBACK isr_func)
{
	uint32 mod;
	uint8 ps;
	uint16 _TACCR0_MOD;
	CLKx clk;

	TA_TACTL |= TA_TACTL_TACLR_MASK; //清除定时器A
	if(mode==MODE_Timer)  //定时器模式
		{
			if((mod=(period_ms*_ACLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TACCR0_MOD = mod;
					clk = ACLK;
					if((mod=(period_ms*_ACLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TACCR0_MOD = mod;
							if((mod=(period_ms*_ACLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TACCR0_MOD = mod;
									if((mod=(period_ms*_ACLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TACCR0_MOD = mod;
										}
								}
						}
				}
			if((mod=(period_ms*_SMCLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TACCR0_MOD = mod;
					clk = SMCLK;
					if((mod=(period_ms*_SMCLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TACCR0_MOD = mod;
							if((mod=(period_ms*_SMCLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TACCR0_MOD = mod;
									if((mod=(period_ms*_SMCLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TACCR0_MOD = mod;
										}
								}
						}
				}
			TA_TACTL = 0; //关闭定时器
			//设置相关寄存器
			TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
						TA_TACTL_IDx(ps)+\
						TA_TACTL_MCx(1)+\
						TA_TACTL_TAIE(0);
			TA_TACCTL0 = TA_TACCTLx_CCIE(1);
			TA_TACCR0 = _TACCR0_MOD;
			//设置中断函数
			TA_irq = isr_func;
		}
	else if(mode==MODE_PLACC)  //计数器模式
		{
			
			TA_TACTL = TA_TACTL_TASSELx(channel)+\
									TA_TACTL_IDx(0)+\
									TA_TACTL_MCx(2)+\
									TA_TACTL_TAIE(0);
			
		}
}

/*
 * TA_ClearIsr
 * 清除TA用户定义的中断服务函数，并禁用中断
 * 
 * 参数:
 * 输出:
 *	无
 */
void TA_ClearIsr(void)
{
	TA_irq = (TA_ISR_CALLBACK)NULL;
	TA_TACTL= TA_TACTL_TACLR(1);
}


/*
 *  TA_DelayMs
 *  低功耗定时器延时n个ms
 *  不用初始化
 * 参数:
 *    period_ms--设定定时器的定时值 单位ms
 *    最大65535ms
 *
 *  返回值:
 *      无
 */
void TA_DelayMs(uint16 period_ms)
{
	uint32 mod;
	uint8 ps;
	uint16 _TACCR0_MOD;
	CLKx clk;
	TA_TACTL |= TA_TACTL_TACLR_MASK; //清除定时器A
			if((mod=(period_ms*_ACLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TACCR0_MOD = mod;
					clk = ACLK;
					if((mod=(period_ms*_ACLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TACCR0_MOD = mod;
							if((mod=(period_ms*_ACLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TACCR0_MOD = mod;
									if((mod=(period_ms*_ACLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TACCR0_MOD = mod;
										}
								}
						}
				}
			if((mod=(period_ms*_SMCLK)/(8*1000))<0xFFFF)
				{
					ps = 3;
					_TACCR0_MOD = mod;
					clk = SMCLK;
					if((mod=(period_ms*_SMCLK)/(4*1000))<0xFFFF)
						{
							ps = 2;
							_TACCR0_MOD = mod;
							if((mod=(period_ms*_SMCLK)/(2*1000))<0xFFFF)
								{
									ps = 1;
									_TACCR0_MOD = mod;
									if((mod=(period_ms*_SMCLK)/(1*1000))<0xFFFF)
										{
											ps = 0;
											_TACCR0_MOD = mod;
										}
								}
						}
				}
			//设置相关寄存器
			TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
						TA_TACTL_IDx(ps)+\
						TA_TACTL_MCx(1)+\
						TA_TACTL_TAIE(0);
			TA_TACCR0 = _TACCR0_MOD;
			
	//等待定时到达
	TA_TACCTL0 &=0xFFFE;
	while((TA_TACCTL0&0x0001)==0);
	TA_TACCTL0 &=0xFFFE; //清除标志位
	TA_TACTL = TA_TACTL_TACLR(1); //关闭定时器
}

/*
 *  TA_GetPulseAcc
 *  得到脉冲累加的值
 * 
 *  参数:
 *      无
 *  返回值:
 *      脉冲累加值
 */
uint16 TA_GetPulseAcc(void)
{
   return (uint16)TA_TAR;
}


/*
 * TA_Clear
 *  清空定时器TA  Counter
 * 
 *  参数:
 *      无
 *  返回值:
 *      无
 */
void TA_Clear(void)
{
	TA_TAR = 0;
}


/*
 * TA_Capture_Init
 * TA模块捕获模式初始化
 * 
 * 
 * 参数:
 *    cap -- 选择捕获模块
 *      |__0--CCR0
 *      |__1--CCR1
 *      |__2--CCR2
 *    channel - Capture输入通道
 *      |__0--CCIxA
 *      |__1--CCIxB
 *      |__2--GND
 *      |__3--Vcc
 *    range - 捕获时间的量程选择
 *      |__0--0~8192us--8MHz--1分频
 *      |__1--8192~16384us--8MHz--2  
 *      |__2--16384~32768us--8Mhz--4
 *      |__3--32768~65536us--8Mhz--8
 *      |__4--65536~16000000us--4096Hz--1
 *      |__5--16~32s--4096--2
 *      |__6--32~64s--4096--4
 *      |__7--64~128s--4096--8
 * 输出:
 */
void TA_Capture_Init(uint8 cap ,uint8 channel, uint8 range)
{
	TA_TACTL |= TA_TACTL_TACLR_MASK; //清除定时器A
	switch(cap)
		{
			case 0:{
					switch(range)
						{
							case 0:
							case 1:
							case 2:
							case 3:{
									TA_TACTL = TA_TACTL_TASSELx(2)+\
												TA_TACTL_IDx(range)+\
												TA_TACTL_MCx(2);
								}
							break;
							case 4:
							case 5:
							case 6:
							case 7:{
									TA_TACTL = TA_TACTL_TASSELx(1)+\
												TA_TACTL_IDx(range-4)+\
												TA_TACTL_MCx(2);
								}
							break;
						}
					TA_TACCTL0 = TA_TACCTLx_CMx(3)+\
									TA_TACCTLx_CCISx(channel)+\
									TA_TACCTLx_SCS(1)+\
									TA_TACCTLx_CAP(1);
				}
			break;
			case 1:{
					switch(range)
						{
							case 0:
							case 1:
							case 2:
							case 3:{
									TA_TACTL = TA_TACTL_TASSELx(2)+\
												TA_TACTL_IDx(range)+\
												TA_TACTL_MCx(2);
								}
							break;
							case 4:
							case 5:
							case 6:
							case 7:{
									TA_TACTL = TA_TACTL_TASSELx(1)+\
												TA_TACTL_IDx(range-4)+\
												TA_TACTL_MCx(2);
								}
							break;
						}
					TA_TACCTL1 = TA_TACCTLx_CMx(3)+\
									TA_TACCTLx_CCISx(channel)+\
									TA_TACCTLx_SCS(1)+\
									TA_TACCTLx_CAP(1);
				}
			break;
			case 2:{
					switch(range)
						{
							case 0:
							case 1:
							case 2:
							case 3:{
									TA_TACTL = TA_TACTL_TASSELx(2)+\
												TA_TACTL_IDx(range)+\
												TA_TACTL_MCx(2);
								}
							break;
							case 4:
							case 5:
							case 6:
							case 7:{
									TA_TACTL = TA_TACTL_TASSELx(1)+\
												TA_TACTL_IDx(range-4)+\
												TA_TACTL_MCx(2);
								}
							break;
						}
					TA_TACCTL2 = TA_TACCTLx_CMx(3)+\
									TA_TACCTLx_CCISx(channel)+\
									TA_TACCTLx_SCS(1)+\
									TA_TACCTLx_CAP(1);
				}
			break;
			
		}
}

/*
 * TA_GetCapture
 * 用TA的捕获模式的到脉冲宽度
 * 
 * 
 * 参数:
 *    cap -- 选择捕获模块
 *      |__0--CCR0
 *      |__1--CCR1
 *      |__2--CCR2
 *    range - 捕获时间的量程选择
 *      |__0--0~8192us--8MHz--1分频
 *      |__1--8192~16384us--8MHz--2  
 *      |__2--16384~32768us--8Mhz--4
 *      |__3--32768~65536us--8Mhz--8
 *      |__4--65536~16000000us--4096Hz--1
 *      |__5--16~32s--4096--2
 *      |__6--32~64s--4096--4
 *      |__7--64~128s--4096--8

 * 输出:
 *     脉冲宽度单位us
 */  
uint32 TA_GetCapture(uint8 cap,uint8 range)
{
	uint32 width = 0;//宽度
	uint8 f = 0;//标志
	uint16 front = 0;//前
	uint16 back = 0; //后
	double graduation = 0;  //单位us
	//计算刻度
	switch(range)
		{
			case 0:graduation = 1.0/8; break;
			case 1:graduation = 1.0/4; break;
			case 2:graduation = 1.0/2; break;
			case 3:graduation = 1.0/1; break;
			case 4:graduation = (1.0/4096)*1000000; break;
			case 5:graduation = (1.0/2048)*1000000; break;
			case 6:graduation = (1.0/1024)*1000000; break;
			case 7:graduation = (1.0/512)*1000000; break;
		}
	//计算脉冲宽度
	while(f!=2)
		{
			switch(cap)
				{
					case 0:{
							if(TA_TACCTL0&TA_TACCTLx_CCIFG_MASK)
								{
									if(f==0)
										{
											front = TA_TACCR0;
											TA_TACCTL0 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 1;
										}
									else
										{
											back = TA_TACCR0;
											TA_TACCTL0 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 2;
										}
								}
						}
					break;
					case 1:{
							if(TA_TACCTL1&TA_TACCTLx_CCIFG_MASK)
								{
									if(f==0)
										{
											front = TA_TACCR1;
											TA_TACCTL1 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 1;
										}
									else
										{
											back = TA_TACCR1;
											TA_TACCTL1 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 2;
										}
								}
						}
					break;
					case 2:{
							if(TA_TACCTL2&TA_TACCTLx_CCIFG_MASK)
								{
									if(f==0)
										{
											front = TA_TACCR2;
											TA_TACCTL2 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 1;
										}
									else
										{
											back = TA_TACCR2;
											TA_TACCTL2 &= ~TA_TACCTLx_CCIFG_MASK;
											f = 2;
										}
								}
						}
					break;
				}
		}
	if(front<=back)
		{
			width = (uint32)((back-front)*graduation);
		}
	else
		{
			width = (uint32)((65536+back-front)*graduation);
		}
	return width;
}










/************************************************中断总入口*******************************************************/

/*******************************************
函数名称：TA_Isr
功    能：TA的外部中断总入口
参    数：无
返回值  ：无
********************************************/
#pragma vector = TIMERA0_VECTOR
__interrupt void TA_Isr(void)
{
	TA_irq();
}











