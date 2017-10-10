/******************************************************************
*����:���ļ���������TB�����к���
*
*******************************************************************/
#include "include.h"

uint16 TBCCR0_MOD = 0;

TB_ISR_CALLBACK TB_irq = (TB_ISR_CALLBACK)NULL;


/*
 * TB_PWM_Init
 * TBģ��PWM���ܳ�ʼ������
 * 
 * ����:
 *    freq--����Ƶ�ʣ���λHz
 *
 * ���:
 *    
 */
void TB_PWM_Init(uint32 freq)
{
	uint32 mod = 0;
	uint8 ps = 0; //��Ƶϵ��
	CLKx clk;

	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //�����ʱ��B
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
	TB_TBCTL = 0; //�رն�ʱ��
	TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
				TB_TBCTL_CNTLx(0)+\
				TB_TBCTL_TBSSELx(clk)+\
				TB_TBCTL_IDx(ps)+\
				TB_TBCTL_MCx(1);
		
	TB_TBCCR0 = TBCCR0_MOD;
}


/*
 * TB_PWM_Open
 * TBģ��PWM���ͨ����ռ�ձ�����
 * 
 * 
 * ����:
 *    channel - PWM���ͨ��
 *      |__0--TB1
 *      |__1--TB2
 *      |__2--TB3
 *      |__3--TB4
 *      |__4--TB5
 *      |__5--TB6
 *    duty - PWM���ռ�ձ�
 *      |__0~10000--ռ�ձ�0.00%~100.00%
 *
 * ���:
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
 * �ı�FTM0ģ��PWM���ͨ��ռ�ձ�
 *
 * ����:
 *    channel - PWM���ͨ��
 *      |__0--TB1
 *      |__1--TB2
 *      |__2--TB3
 *      |__3--TB4
 *      |__4--TB5
 *      |__5--TB6
 *    duty - PWM���ռ�ձ�
 *      |__0~10000--ռ�ձ�0.00%~100.00%
 *
 * ���:
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
 * TB�������ڶ�ʱ���������ۼ���ʱ�ĳ�ʼ������
 * 
 * ����:
 *    mode--ѡ��LPTMRģʽ
 *      |__MODE_Timer           --��ʱ��ģʽ
 *      |__MODE_PLACC           --�����ۼ�ģʽ
 *    period_ms--�趨��ʱ���Ķ�ʱֵ ��λms
 *      |__0                    --���������ۼ�ģʽʱѡ��Ϊ0
 *      |__1~65535              --1ms<= ��ʱ����  <=7680ms 
 *    isr_func
 *      |__�͹��Ķ�ʱ���жϻص�����
 *  
 * ���:
 */

void TB_Time_Init(uint8 mode, uint16 period_ms, TA_ISR_CALLBACK isr_func)
{
	uint32 mod;
	uint8 ps;
	uint16 _TBCCR0_MOD;
	CLKx clk;

	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //�����ʱ��B
	if(mode==MODE_Timer)  //��ʱ��ģʽ
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
			TB_TBCTL = 0; //�رն�ʱ��
			//������ؼĴ���
			TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
						TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(clk)+\
						TB_TBCTL_IDx(ps)+\
						TB_TBCTL_MCx(1);
			TB_TBCCTL0 = TB_TBCCTLx_CCIE(1)+\
							TB_TBCCTLx_CLLDx(0);
			TB_TBCCR0 = _TBCCR0_MOD;
			//�����жϺ���
			TB_irq = isr_func;
		}
	else if(mode==MODE_PLACC)  //������ģʽ
		{
			
			TB_TBCTL = TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(0)+\
						TB_TBCTL_IDx(0)+\
						TB_TBCTL_MCx(2);
			
		}
}

/*
 * TB_ClearIsr
 * ���TB�û�������жϷ��������������ж�
 * 
 * ����:
 * ���:
 *	��
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
 *  �͹��Ķ�ʱ����ʱn��ms
 * 
 * ����:
 *    period_ms--�趨��ʱ���Ķ�ʱֵ ��λms
 *    ���65535ms
 *
 *  ����ֵ:
 *      ��
 */
void TB_DelayMs(uint16 period_ms)
{
	uint32 mod;
	uint8 ps;
	uint16 _TBCCR0_MOD;
	CLKx clk;
	TB_TBCTL |= TB_TBCTL_TBCLR_MASK; //�����ʱ��B
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
			//������ؼĴ���
			TB_TBCTL = TB_TBCTL_TBCLGRP(0)+\
						TB_TBCTL_CNTLx(0)+\
						TB_TBCTL_TBSSELx(clk)+\
						TB_TBCTL_IDx(ps)+\
						TB_TBCTL_MCx(1);
			TB_TBCCR0 = _TBCCR0_MOD;
			
	//�ȴ���ʱ����
	TB_TBCCTL0 &=0xFFFE;
	while((TB_TBCCTL0&0x0001)==0);
	TB_TBCCTL0 &=0xFFFE; //�����־λ
	TB_TBCTL = 0; //�رն�ʱ��
}

/*
 *  TB_GetPulseAcc
 *  �õ������ۼӵ�ֵ
 * 
 *  ����:
 *      ��
 *  ����ֵ:
 *      �����ۼ�ֵ
 */
uint16 TB_GetPulseAcc(void)
{
   return (uint16)TB_TBR;
}

/*
 * TB_Clear
 *  ��ն�ʱ��TB  Counter
 * 
 *  ����:
 *      ��
 *  ����ֵ:
 *      ��
 */
void TB_Clear(void)
{
	TB_TBR = 0;
}
















/************************************************�ж������*******************************************************/

/*******************************************
�������ƣ�TA_Isr
��    �ܣ�TA���ⲿ�ж������
��    ������
����ֵ  ����
********************************************/
#pragma vector = TIMERB0_VECTOR
__interrupt void TB_Isr(void)
{
	TB_irq();
}








































