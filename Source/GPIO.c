/******************************************************************
*����:���ļ��ж����˲���IO�����к���
*
*******************************************************************/
#include "MSP430.h"
#include "include.h"

void GPIO_Isr(void)
{;}
//�û��Զ����жϷ���������
GPIO_ISR_CALLBACK P1_ISR[8]={GPIO_Isr};

GPIO_ISR_CALLBACK P2_ISR[8]={GPIO_Isr};


/*
 * GPIO_Init
 * GPIOͨ�ó�ʼ������
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    dir--�˿����ݷ���
 *      |__DIR_INPUT  --����
 *      |__DIR_OUTPUT --���
 *
 * ���:
 *   ��
 */
void GPIO_Init(Px px,uint8 dir)
{
	switch(px)
		{
			case P1:{
					P1_PSEL = GPIO_PSEL(0x00);
					P1_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P1_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P1_POUT = 0xFF;
							P1_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
			case P2:{
					P2_PSEL = GPIO_PSEL(0x00);
					P2_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P2_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P2_POUT = 0xFF;
							P2_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
			case P3:{
					P3_PSEL = GPIO_PSEL(0x00);
					//P3_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P3_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P3_POUT = 0xFF;
							P3_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
			case P4:{
					P4_PSEL = GPIO_PSEL(0x00);
					//P1_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P4_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P4_POUT = 0xFF;
							P4_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
			case P5:{
					P5_PSEL = GPIO_PSEL(0x00);
					//P1_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P5_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P5_POUT = 0xFF;
							P5_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
			case P6:{
					P6_PSEL = GPIO_PSEL(0x00);
					//P1_PIE = GPIO_PIE(0x00);
					if(dir==DIR_INPUT)
						{
							P6_PDIR = GPIO_PDIR(0x00);
						}
					else
						{
							P6_POUT = 0xFF;
							P6_PDIR = GPIO_PDIR(0xFF);
						}
				}
			break;
		}
}








/*
 * P1_2_Init
 * P1_2ͨ�ó�ʼ������
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--�˿�λ��
 *      |__0~7
 *    fun--����ѡ��
 *      |__IO       --IO����
 *      |__MOD    --��Χģ�鹦��
 *    dir--�˿����ݷ���
 *      |__DIR_INPUT  --����
 *      |__DIR_OUTPUT --���
 *    irqc--�����ж�
 *      |__IRQC_DIS   --��ʹ���ж�
 *      |__IRQC_RI    --�����ش����ж�
 *      |__IRQC_FA    --�½��ش����ж�
 *
 * ���:
 *   ��
 */
void P1_2_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir, uint8 irqc)
{
	//����жϱ�־λ
	P1_PIFG = 0x00;
	P2_PIFG = 0x00;
	
	switch(px)
		{
			case P1:{
					if(fun==IO)
						{
							P1_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P1_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P1_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{
							P1_POUT |= ((uint8)(1)<<port_bit);
							P1_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
					
					switch(irqc)
						{
							case IRQC_DIS:{
									P1_PIE &= ~((uint8)(1)<<port_bit);  //�ر��ж�
								}
								break;
							case IRQC_RI:{
									P1_PIE |= ((uint8)(1)<<port_bit);   //���ж�
									P1_PIES &= ~((uint8)(1)<<port_bit);  //�����ش���
								}
								break;
							case IRQC_FA:{
									P1_PIE |= ((uint8)(1)<<port_bit);  //���ж�
									P1_PIES |= ((uint8)(1)<<port_bit);  //�½��ش���
								}
								break;
						}
				}
				break;
			case P2:{
					if(fun==IO)
						{
							P2_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P2_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P2_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{
							P2_POUT |= ((uint8)(1)<<port_bit);
							P2_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
					switch(irqc)
						{
							case IRQC_DIS:{
									P2_PIE &= ~((uint8)(1)<<port_bit);  //�ر��ж�
								}
								break;
							case IRQC_RI:{
									P2_PIE |= ((uint8)(1)<<port_bit);   //���ж�
									P2_PIES &= ~((uint8)(1)<<port_bit);  //�����ش���
								}
								break;
							case IRQC_FA:{
									P2_PIE |= ((uint8)(1)<<port_bit);  //���ж�
									P2_PIES |= ((uint8)(1)<<port_bit);  //�½��ش���
								}
								break;
						}
				}
				break;
		}
	
}

/*
 * P3_6_Init
 * P3_6ͨ�ó�ʼ������
 * 
 * ����:
 *    px--�˿ں�
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6 
 *    port_bit--�˿�λ��
 *      |__0~7
 *    fun--����ѡ��
 *      |__IO       --IO����
 *      |__MOD    --��Χģ�鹦��
 *    dir--�˿����ݷ���
 *      |__DIR_INPUT  --����
 *      |__DIR_OUTPUT --���
 *
 * ���:
 *   ��
 */
void P3_6_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir)
{
	switch(px)
		{
			case P3:{
					if(fun==IO)
						{
							P3_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P3_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P3_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{	
							P3_POUT |= ((uint8)(1)<<port_bit);
							P3_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
				}
			break;
			case P4:{
					if(fun==IO)
						{
							P4_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P4_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P4_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{
							P4_POUT |= ((uint8)(1)<<port_bit);
							P4_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
				}
			break;
			case P5:{
					if(fun==IO)
						{
							P5_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P5_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P5_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{
							P5_POUT |= ((uint8)(1)<<port_bit);
							P5_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
				}
			break;
			case P6:{
					if(fun==IO)
						{
							P6_PSEL &= ~((uint8)(1)<<port_bit);   //���ó�GPIO
						}
					else
						{
							P6_PSEL |= ((uint8)(1)<<port_bit);   //���ó���Χģ�鹦��
						}
					if(dir==DIR_INPUT)
						{
							P6_PDIR &= ~((uint8)(1)<<port_bit);   //���ó����빦��
						}
					else
						{
							P6_POUT |= ((uint8)(1)<<port_bit);
							P6_PDIR |= ((uint8)(1)<<port_bit);    //���ó��������							
						}
				}
			break;
		}
}

/*
 * P1_2_SetIsr
 * ����P1_2ͨ���û�������жϷ���������ʹ���ж�
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--�˿�λ��
 *      |__0~7
 *    isr_func--�û��жϳ�����ڵ�ַ
 *      |__�û��ڹ����ļ��¶�����жϺ���������������Ϊ:�޷���ֵ,�޲���(eg. void isr(void);)
 *
 * ���:
 *	��
 */
void P1_2_SetIsr(Px px,uint8 port_bit, GPIO_ISR_CALLBACK isr_func)
{
	switch(px)
		{
			case P1:{
					P1_ISR[port_bit] = isr_func;
					P1_PIE |= ((uint8)(1)<<port_bit);//ʹ���ж�
				}
			break;
			case P2:{
					P2_ISR[port_bit] = isr_func;
					P2_PIE |= ((uint8)(1)<<port_bit);//ʹ���ж�
				}
			break;
		}
}

/*
 * P1_2_ClearIsr
 * ���P1_2ͨ���û�������жϷ��������������ж�
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--�˿�λ��
 *      |__0~7	
 * ���:
 *	��
 */
void P1_2_ClearIsr(Px px,uint8 port_bit)
{
	switch(px)
		{
			case P1:{
					P1_ISR[port_bit] = GPIO_Isr;
					P1_PIE &= ~((uint8)(1)<<port_bit);//�����ж�
				}
			break;
			case P2:{
					P2_ISR[port_bit] = GPIO_Isr;
					P2_PIE &= ~((uint8)(1)<<port_bit);//ʹ���ж�
				}
			break;
		}
}

/*
 * GPIO_Set
 * ����GPIO�˿�0~7λ���
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    data8--�������
 *      |__0x00~0xFF--�͵��ߴ���GPIO�ڵĵ�0~8λ����
 *
 * ���:
 *	��
 */
void GPIO_Set(Px px, uint8 data8)
{
	switch(px)
		{
			case P1:{
					P1_POUT = data8;
				}
			break;
			case P2:{
					P2_POUT = data8;
				}
			break;
			case P3:{
					P3_POUT = data8;
				}
			break;
			case P4:{
					P4_POUT = data8;
				}
			break;
			case P5:{
					P5_POUT = data8;
				}
			break;
			case P6:{
					P6_POUT = data8;
				}
			break;
		}
}

/*
 * GPIO_Set_b
 * ����GPIO�˿�һλ�����
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--λ��
 *      |__0~7       --GPIO�ڵĵ�0~7λ
 *    data1--�������
 *      |__0   --����͵�ƽ
 *      |__1   --����ߵ�ƽ
 *
 * ���:
 *
 */
void GPIO_Set_b(Px px, uint8 port_bit, uint8 data1)
{
	switch(px)
		{
			case P1:{
					P1_POUT &= ~((uint8)(1)<<port_bit);
					P1_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
			case P2:{
					P2_POUT &= ~((uint8)(1)<<port_bit);
					P2_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
			case P3:{
					P3_POUT &= ~((uint8)(1)<<port_bit);
					P3_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
			case P4:{
					P4_POUT &= ~((uint8)(1)<<port_bit);
					P4_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
			case P5:{
					P5_POUT &= ~((uint8)(1)<<port_bit);
					P5_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
			case P6:{
					P6_POUT &= ~((uint8)(1)<<port_bit);
					P6_POUT |= ((uint8)(data1)<<port_bit);
				}
			break;
		}
	
}

/*
 * GPIO_Get
 * ȡ��GPIO�ڵ�����
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *
 * ���:
 *    ָ��GPIO�ڵ�8λ����
 *
 */
uint8 GPIO_Get(Px px)
{
	switch(px)
        {
	case P1:{
	    return P1_PIN;
	}
	case P2:{
	    return P2_PIN;
	}
	case P3:{
	    return P3_PIN;
	}
	case P4:{
	    return P4_PIN;
	}
	case P5:{
	    return P5_PIN;
	}
	case P6:{
            return P6_PIN;
	}
        }
	return 0;
}


/*
 * GPIO_Get_b
 * ȡ��GPIO��ĳһλ������
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--λ��
 *      |__0~7--GPIO�ڵĵ�0~7λ
 *
 * ���:
 *    ָ��GPIO�ڵ�ָ��λ���ĵ�ƽ
 *
 */
uint8 GPIO_Get_b(Px px, uint8 port_bit)
{
	
	switch(px)
		{
			case P1:{
					return (P1_PIN>>port_bit)&0x01;
				}
			case P2:{
					return (P2_PIN>>port_bit)&0x01;
				}
			case P3:{
					return (P3_PIN>>port_bit)&0x01;
				}
			case P4:{
					return (P4_PIN>>port_bit)&0x01;
				}
			case P5:{
					return (P5_PIN>>port_bit)&0x01;
				}
			case P6:{
					return (P6_PIN>>port_bit)&0x01;
				}
		}
	return 0;
}

/*
 * GPIO_Toggle
 * ����GPIO�˿�0~7�ĵ�ƽ��ת
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    data8--��ת����
 *      |__0x00~0xFF--�͵��ߴ���GPIO�ڵĵ�0~7λ�ķ�ת��1Ϊ��ת��0Ϊ���ֲ��䡣
 *
 * ���:
 *
 */
void GPIO_Toggle(Px px, uint8 data8)
{
	switch(px)
		{
			case P1:{
					P1_POUT ^= data8;
				}
			break;
			case P2:{
					P2_POUT ^= data8;
				}
			break;
			case P3:{
					P3_POUT ^= data8;
				}
			break;
			case P4:{
					P4_POUT ^= data8;
				}
			break;
			case P5:{
					P5_POUT ^= data8;
				}
			break;
			case P6:{
					P6_POUT ^= data8;
				}
			break;
		}
}


/*
 * GPIO_Toggle_b
 * ����GPIO�˿�һλ�ķ�ת
 * 
 * ����:
 *    px--�˿ں�
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--λ��
 *      |__0~7       --����GPIO�ڵ�һλ��ת
 *
 * ���:
 *
 */
void GPIO_Toggle_b(Px px, uint8 port_bit)
{
	switch(px)
	    {
	    	case P1:{
					P1_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
			case P2:{
					P2_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
			case P3:{
					P3_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
			case P4:{
					P4_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
			case P5:{
					P5_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
			case P6:{
					P6_POUT ^= ((uint8)(1)<<port_bit);
				}
			break;
		}
}








/************************************************�ж������*******************************************************/

/*******************************************
�������ƣ�P1_Isr
��    �ܣ�P1�˿ڵ��ⲿ�ж������
��    ������
����ֵ  ����
********************************************/
#pragma vector = PORT1_VECTOR
__interrupt void P1_Isr(void)
{
	uint8 i;
	//��ȡ��־λ��
	for(i=0;i<8;i++)
		{
			if((P1_PIFG>>i)&0x01)break;  
		}
	if(i<8)
		{
			P1_PIFG &= ~((uint8)(1)<<i);  //�����־λ
			P1_ISR[i]();    //�����û��жϷ������
		}
}

/*******************************************
�������ƣ�P2_Isr
��    �ܣ�P2�˿ڵ��ⲿ�ж������
��    ������
����ֵ  ����
********************************************/
#pragma vector = PORT2_VECTOR
__interrupt void P2_Isr(void)
{
	uint8 i;
	//��ȡ��־λ��
	for(i=0;i<8;i++)
		{
			if((P2_PIFG>>i)&0x01)break;  
		}
	if(i<8)
		{
			P2_PIFG &= ~((uint8)(1)<<i);  //�����־λ
			P2_ISR[i]();    //�����û��жϷ������
		}
}



