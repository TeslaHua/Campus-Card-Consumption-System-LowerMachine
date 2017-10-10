/******************************************************************
*����:���ļ���������TA�����к���
*
*******************************************************************/
#include "include.h"

uint16 TACCR0_MOD = 0;

TA_ISR_CALLBACK TA_irq = (TA_ISR_CALLBACK)NULL;


/*
 * TA_PWM_Init
 * TAģ��PWM���ܳ�ʼ������
 * 
 * ����:
 *    freq--����Ƶ�ʣ���λHz
 *
 * ���:
 *    
 */
void TA_PWM_Init(uint32 freq)
{
	uint32 mod = 0;
	uint8 ps = 0; //��Ƶϵ��
	CLKx clk;
	TA_TACTL |= TA_TACTL_TACLR_MASK; //�����ʱ��A
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
	TA_TACTL = 0; //�رն�ʱ��
	TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
				TA_TACTL_IDx(ps)+\
				TA_TACTL_MCx(1);
	TA_TACCR0 = TACCR0_MOD;
}


/*
 * TA_PWM_Open
 * TAģ��PWM���ͨ����ռ�ձ�����
 * 
 * 
 * ����:
 *    channel - PWM���ͨ��
 *      |__0--TA1
 *      |__1--TA2
 *    duty - PWM���ռ�ձ�
 *      |__0~10000--ռ�ձ�0.00%~100.00%
 *
 * ���:
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
 * �ı�FTM0ģ��PWM���ͨ��ռ�ձ�
 *
 * ����:
 *    channel - PWM���ͨ��
 *      |__0--TA1
 *      |__1--TA2
 *    duty - PWM���ռ�ձ�
 *      |__0~10000--ռ�ձ�0.00%~100.00%
 *
 * ���:
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
 * TA�������ڶ�ʱ���������ۼ���ʱ�ĳ�ʼ������
 * 
 * ����:
 *    mode--ѡ��LPTMRģʽ
 *      |__MODE_Timer           --��ʱ��ģʽ
 *      |__MODE_PLACC           --�����ۼ�ģʽ
 *    period_ms--�趨��ʱ���Ķ�ʱֵ ��λms
 *      |__0                    --���������ۼ�ģʽʱѡ��Ϊ0
 *      |__1~65535              --1ms<= ��ʱ����  <=7680ms 
 *    channel--ѡ���ۼ�����ͨ��
 *      |__0                    --����Ϊ��ʱ��ʱѡ��Ϊ0
 *      |__TACLK           --����TACLK, P1.0Ϊ�����ۼ�����
 *      |__TAINCLK           --����TAINCLK, P2.1 Ϊ�����ۼ�����
 *    isr_func
 *      |__���ڶ�ʱ���жϻص�����
 *  
 * ���:
 */

void TA_Time_Init(uint8 mode, uint16 period_ms, uint8 channel, TA_ISR_CALLBACK isr_func)
{
	uint32 mod;
	uint8 ps;
	uint16 _TACCR0_MOD;
	CLKx clk;

	TA_TACTL |= TA_TACTL_TACLR_MASK; //�����ʱ��A
	if(mode==MODE_Timer)  //��ʱ��ģʽ
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
			TA_TACTL = 0; //�رն�ʱ��
			//������ؼĴ���
			TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
						TA_TACTL_IDx(ps)+\
						TA_TACTL_MCx(1)+\
						TA_TACTL_TAIE(0);
			TA_TACCTL0 = TA_TACCTLx_CCIE(1);
			TA_TACCR0 = _TACCR0_MOD;
			//�����жϺ���
			TA_irq = isr_func;
		}
	else if(mode==MODE_PLACC)  //������ģʽ
		{
			
			TA_TACTL = TA_TACTL_TASSELx(channel)+\
									TA_TACTL_IDx(0)+\
									TA_TACTL_MCx(2)+\
									TA_TACTL_TAIE(0);
			
		}
}

/*
 * TA_ClearIsr
 * ���TA�û�������жϷ��������������ж�
 * 
 * ����:
 * ���:
 *	��
 */
void TA_ClearIsr(void)
{
	TA_irq = (TA_ISR_CALLBACK)NULL;
	TA_TACTL= TA_TACTL_TACLR(1);
}


/*
 *  TA_DelayMs
 *  �͹��Ķ�ʱ����ʱn��ms
 *  ���ó�ʼ��
 * ����:
 *    period_ms--�趨��ʱ���Ķ�ʱֵ ��λms
 *    ���65535ms
 *
 *  ����ֵ:
 *      ��
 */
void TA_DelayMs(uint16 period_ms)
{
	uint32 mod;
	uint8 ps;
	uint16 _TACCR0_MOD;
	CLKx clk;
	TA_TACTL |= TA_TACTL_TACLR_MASK; //�����ʱ��A
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
			//������ؼĴ���
			TA_TACTL = TA_TACTL_TASSELx((uint8)(clk))+\
						TA_TACTL_IDx(ps)+\
						TA_TACTL_MCx(1)+\
						TA_TACTL_TAIE(0);
			TA_TACCR0 = _TACCR0_MOD;
			
	//�ȴ���ʱ����
	TA_TACCTL0 &=0xFFFE;
	while((TA_TACCTL0&0x0001)==0);
	TA_TACCTL0 &=0xFFFE; //�����־λ
	TA_TACTL = TA_TACTL_TACLR(1); //�رն�ʱ��
}

/*
 *  TA_GetPulseAcc
 *  �õ������ۼӵ�ֵ
 * 
 *  ����:
 *      ��
 *  ����ֵ:
 *      �����ۼ�ֵ
 */
uint16 TA_GetPulseAcc(void)
{
   return (uint16)TA_TAR;
}


/*
 * TA_Clear
 *  ��ն�ʱ��TA  Counter
 * 
 *  ����:
 *      ��
 *  ����ֵ:
 *      ��
 */
void TA_Clear(void)
{
	TA_TAR = 0;
}


/*
 * TA_Capture_Init
 * TAģ�鲶��ģʽ��ʼ��
 * 
 * 
 * ����:
 *    cap -- ѡ�񲶻�ģ��
 *      |__0--CCR0
 *      |__1--CCR1
 *      |__2--CCR2
 *    channel - Capture����ͨ��
 *      |__0--CCIxA
 *      |__1--CCIxB
 *      |__2--GND
 *      |__3--Vcc
 *    range - ����ʱ�������ѡ��
 *      |__0--0~8192us--8MHz--1��Ƶ
 *      |__1--8192~16384us--8MHz--2  
 *      |__2--16384~32768us--8Mhz--4
 *      |__3--32768~65536us--8Mhz--8
 *      |__4--65536~16000000us--4096Hz--1
 *      |__5--16~32s--4096--2
 *      |__6--32~64s--4096--4
 *      |__7--64~128s--4096--8
 * ���:
 */
void TA_Capture_Init(uint8 cap ,uint8 channel, uint8 range)
{
	TA_TACTL |= TA_TACTL_TACLR_MASK; //�����ʱ��A
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
 * ��TA�Ĳ���ģʽ�ĵ�������
 * 
 * 
 * ����:
 *    cap -- ѡ�񲶻�ģ��
 *      |__0--CCR0
 *      |__1--CCR1
 *      |__2--CCR2
 *    range - ����ʱ�������ѡ��
 *      |__0--0~8192us--8MHz--1��Ƶ
 *      |__1--8192~16384us--8MHz--2  
 *      |__2--16384~32768us--8Mhz--4
 *      |__3--32768~65536us--8Mhz--8
 *      |__4--65536~16000000us--4096Hz--1
 *      |__5--16~32s--4096--2
 *      |__6--32~64s--4096--4
 *      |__7--64~128s--4096--8

 * ���:
 *     �����ȵ�λus
 */  
uint32 TA_GetCapture(uint8 cap,uint8 range)
{
	uint32 width = 0;//���
	uint8 f = 0;//��־
	uint16 front = 0;//ǰ
	uint16 back = 0; //��
	double graduation = 0;  //��λus
	//����̶�
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
	//����������
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










/************************************************�ж������*******************************************************/

/*******************************************
�������ƣ�TA_Isr
��    �ܣ�TA���ⲿ�ж������
��    ������
����ֵ  ����
********************************************/
#pragma vector = TIMERA0_VECTOR
__interrupt void TA_Isr(void)
{
	TA_irq();
}











