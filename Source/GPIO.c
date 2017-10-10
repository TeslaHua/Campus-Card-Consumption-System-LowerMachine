/******************************************************************
*描述:此文件中定义了操作IO的所有函数
*
*******************************************************************/
#include "MSP430.h"
#include "include.h"

void GPIO_Isr(void)
{;}
//用户自定义中断服务函数数组
GPIO_ISR_CALLBACK P1_ISR[8]={GPIO_Isr};

GPIO_ISR_CALLBACK P2_ISR[8]={GPIO_Isr};


/*
 * GPIO_Init
 * GPIO通用初始化函数
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    dir--端口数据方向
 *      |__DIR_INPUT  --输入
 *      |__DIR_OUTPUT --输出
 *
 * 输出:
 *   无
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
 * P1_2通用初始化函数
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--端口位数
 *      |__0~7
 *    fun--功能选择
 *      |__IO       --IO功能
 *      |__MOD    --外围模块功能
 *    dir--端口数据方向
 *      |__DIR_INPUT  --输入
 *      |__DIR_OUTPUT --输出
 *    irqc--输入中断
 *      |__IRQC_DIS   --不使能中断
 *      |__IRQC_RI    --上升沿触发中断
 *      |__IRQC_FA    --下降沿触发中断
 *
 * 输出:
 *   无
 */
void P1_2_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir, uint8 irqc)
{
	//清除中断标志位
	P1_PIFG = 0x00;
	P2_PIFG = 0x00;
	
	switch(px)
		{
			case P1:{
					if(fun==IO)
						{
							P1_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P1_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P1_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{
							P1_POUT |= ((uint8)(1)<<port_bit);
							P1_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
					
					switch(irqc)
						{
							case IRQC_DIS:{
									P1_PIE &= ~((uint8)(1)<<port_bit);  //关闭中断
								}
								break;
							case IRQC_RI:{
									P1_PIE |= ((uint8)(1)<<port_bit);   //打开中断
									P1_PIES &= ~((uint8)(1)<<port_bit);  //上升沿触发
								}
								break;
							case IRQC_FA:{
									P1_PIE |= ((uint8)(1)<<port_bit);  //打开中断
									P1_PIES |= ((uint8)(1)<<port_bit);  //下降沿触发
								}
								break;
						}
				}
				break;
			case P2:{
					if(fun==IO)
						{
							P2_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P2_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P2_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{
							P2_POUT |= ((uint8)(1)<<port_bit);
							P2_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
					switch(irqc)
						{
							case IRQC_DIS:{
									P2_PIE &= ~((uint8)(1)<<port_bit);  //关闭中断
								}
								break;
							case IRQC_RI:{
									P2_PIE |= ((uint8)(1)<<port_bit);   //打开中断
									P2_PIES &= ~((uint8)(1)<<port_bit);  //上升沿触发
								}
								break;
							case IRQC_FA:{
									P2_PIE |= ((uint8)(1)<<port_bit);  //打开中断
									P2_PIES |= ((uint8)(1)<<port_bit);  //下降沿触发
								}
								break;
						}
				}
				break;
		}
	
}

/*
 * P3_6_Init
 * P3_6通用初始化函数
 * 
 * 参数:
 *    px--端口号
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6 
 *    port_bit--端口位数
 *      |__0~7
 *    fun--功能选择
 *      |__IO       --IO功能
 *      |__MOD    --外围模块功能
 *    dir--端口数据方向
 *      |__DIR_INPUT  --输入
 *      |__DIR_OUTPUT --输出
 *
 * 输出:
 *   无
 */
void P3_6_Init(Px px, uint8 port_bit,uint8 fun, uint8 dir)
{
	switch(px)
		{
			case P3:{
					if(fun==IO)
						{
							P3_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P3_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P3_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{	
							P3_POUT |= ((uint8)(1)<<port_bit);
							P3_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
				}
			break;
			case P4:{
					if(fun==IO)
						{
							P4_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P4_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P4_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{
							P4_POUT |= ((uint8)(1)<<port_bit);
							P4_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
				}
			break;
			case P5:{
					if(fun==IO)
						{
							P5_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P5_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P5_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{
							P5_POUT |= ((uint8)(1)<<port_bit);
							P5_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
				}
			break;
			case P6:{
					if(fun==IO)
						{
							P6_PSEL &= ~((uint8)(1)<<port_bit);   //设置成GPIO
						}
					else
						{
							P6_PSEL |= ((uint8)(1)<<port_bit);   //设置成外围模块功能
						}
					if(dir==DIR_INPUT)
						{
							P6_PDIR &= ~((uint8)(1)<<port_bit);   //设置成输入功能
						}
					else
						{
							P6_POUT |= ((uint8)(1)<<port_bit);
							P6_PDIR |= ((uint8)(1)<<port_bit);    //设置成输出功能							
						}
				}
			break;
		}
}

/*
 * P1_2_SetIsr
 * 设置P1_2通道用户定义的中断服务函数，并使能中断
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--端口位数
 *      |__0~7
 *    isr_func--用户中断程序入口地址
 *      |__用户在工程文件下定义的中断函数名，函数必须为:无返回值,无参数(eg. void isr(void);)
 *
 * 输出:
 *	无
 */
void P1_2_SetIsr(Px px,uint8 port_bit, GPIO_ISR_CALLBACK isr_func)
{
	switch(px)
		{
			case P1:{
					P1_ISR[port_bit] = isr_func;
					P1_PIE |= ((uint8)(1)<<port_bit);//使能中断
				}
			break;
			case P2:{
					P2_ISR[port_bit] = isr_func;
					P2_PIE |= ((uint8)(1)<<port_bit);//使能中断
				}
			break;
		}
}

/*
 * P1_2_ClearIsr
 * 清除P1_2通道用户定义的中断服务函数，并禁用中断
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *    port_bit--端口位数
 *      |__0~7	
 * 输出:
 *	无
 */
void P1_2_ClearIsr(Px px,uint8 port_bit)
{
	switch(px)
		{
			case P1:{
					P1_ISR[port_bit] = GPIO_Isr;
					P1_PIE &= ~((uint8)(1)<<port_bit);//禁用中断
				}
			break;
			case P2:{
					P2_ISR[port_bit] = GPIO_Isr;
					P2_PIE &= ~((uint8)(1)<<port_bit);//使能中断
				}
			break;
		}
}

/*
 * GPIO_Set
 * 设置GPIO端口0~7位输出
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    data8--输出数据
 *      |__0x00~0xFF--低到高代表GPIO口的第0~8位数据
 *
 * 输出:
 *	无
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
 * 设置GPIO端口一位的输出
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--位数
 *      |__0~7       --GPIO口的第0~7位
 *    data1--输出数据
 *      |__0   --输出低电平
 *      |__1   --输出高电平
 *
 * 输出:
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
 * 取得GPIO口的数据
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *
 * 输出:
 *    指定GPIO口的8位输入
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
 * 取得GPIO口某一位的数据
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--位数
 *      |__0~7--GPIO口的第0~7位
 *
 * 输出:
 *    指定GPIO口的指定位数的电平
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
 * 设置GPIO端口0~7的电平翻转
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    data8--翻转数据
 *      |__0x00~0xFF--低到高代表GPIO口的第0~7位的翻转，1为反转，0为保持不变。
 *
 * 输出:
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
 * 设置GPIO端口一位的翻转
 * 
 * 参数:
 *    px--端口号
 *      |__P1        --Port 1
 *      |__P2        --Port 2
 *      |__P3        --Port 3
 *      |__P4        --Port 4
 *      |__P5        --Port 5
 *      |__P6        --Port 6
 *    port_bit--位数
 *      |__0~7       --设置GPIO口的一位翻转
 *
 * 输出:
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








/************************************************中断总入口*******************************************************/

/*******************************************
函数名称：P1_Isr
功    能：P1端口的外部中断总入口
参    数：无
返回值  ：无
********************************************/
#pragma vector = PORT1_VECTOR
__interrupt void P1_Isr(void)
{
	uint8 i;
	//提取标志位置
	for(i=0;i<8;i++)
		{
			if((P1_PIFG>>i)&0x01)break;  
		}
	if(i<8)
		{
			P1_PIFG &= ~((uint8)(1)<<i);  //清除标志位
			P1_ISR[i]();    //运行用户中断服务程序
		}
}

/*******************************************
函数名称：P2_Isr
功    能：P2端口的外部中断总入口
参    数：无
返回值  ：无
********************************************/
#pragma vector = PORT2_VECTOR
__interrupt void P2_Isr(void)
{
	uint8 i;
	//提取标志位置
	for(i=0;i<8;i++)
		{
			if((P2_PIFG>>i)&0x01)break;  
		}
	if(i<8)
		{
			P2_PIFG &= ~((uint8)(1)<<i);  //清除标志位
			P2_ISR[i]();    //运行用户中断服务程序
		}
}



