
#include "include.h"

uint8 KeyValue;    //实际按键值
uint8 Read_Buffer[16];
uint8 Halt_Buffer[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8 ArrayDeduction[10];
uint8 arraynum=0;
uint8 FindCardflag=0;
extern uint8 index;
extern uint8 ReceiveBalance[10];

/*******************************************
函数名称：Transformation
功    能：薄膜矩阵键盘与实际转换
参    数：number--实际值
返回值  ：薄膜键盘上的值
********************************************/
uint8 Transformation(uint8 number)
{
    switch(number)
    {
      case 0:return 10;
      case 1:return 3;
      case 2:return 2;
      case 3:return 1;
      case 4:return 11;
      case 5:return 6;
      case 6:return 5;
      case 7:return 4;
      case 8:return 12;
      case 9:return 9;
      case 10:return 8;
      case 11:return 7;
      case 12:return 13;
      case 13:return 15;
      case 14:return 0;
      case 15:return 14;
    }
}
/*******************************************
函数名称：扣费显示以及确认通信
参    数：按键值，其中*号代表小数点，#代表输入结束
返回值  ：无
********************************************/
void Deduction_display(uint8 KeyValue)
{
     if(FindCardflag)  //有卡输入
     {
         Write_Cmd(0x8D);  //扣费金额输入固定位置
         if(Transformation(KeyValue)==15)  //按下确认键(井号键)
         {
              Send1Char(UART1,100);  //发送100标志以区别卡号输入（卡号最大是0x99）
              Send1Char(UART1,100);  //在发送一个100，防止无扣费金额，上位机read()读取阻塞
              for(int i=0;i<arraynum;i++)
              {
                  Send1Char(UART1,ArrayDeduction[i]);//扣费金额发送到上位机
                  ArrayDeduction[i]=0;               //此次输入结束，清空以便下次输入
                  Write_Data(' ');                   //清空扣费显示
              }
              FindCardflag=0;  //清发现卡的标志位
              arraynum=0;      //清空以便下次输入
              /*清空卡号显示处，清空防重复识卡数组*/
              Write_Cmd(0x90); 
              for(int i=0;i<16;i++)
              {
                  Write_Data(' ');
                  Halt_Buffer[i]=0;
              }
              /*清空余额显示处，清空余额存放数组*/
              Write_Cmd(0x9D); 
              for(int i=0;i<index;i++)
              {
                 ReceiveBalance[i]=0;
                 Write_Data(' ');
              }
              index=0;             
         }
         else if(Transformation(KeyValue)==12){   //(输入有误时)清除一个输入扣费位（C字符）
             if(arraynum>0)
             {  
                 for(int i=0;i<arraynum;i++)  //显示扣费每位
                 {
                     if(i==arraynum-1)
                        Write_Data(' ');
                     else if(ArrayDeduction[i]!='.')
                        Write_Data('0'+ArrayDeduction[i]);
                     else
                        Write_Data('.');
                 }
                 arraynum--;
             }
         }
         else{
             if(Transformation(KeyValue)==14) //存入小数点（星号键）
                ArrayDeduction[arraynum]='.';
             else
                ArrayDeduction[arraynum]=Transformation(KeyValue);  //把扣费每位存入数组
             for(int i=0;i<=arraynum;i++)  //显示扣费每位
             {
                 if(ArrayDeduction[i]!='.')
                    Write_Data('0'+ArrayDeduction[i]);
                 else
                    Write_Data('.');
             }
             arraynum++;
         }
     }
}
/*******************************************
函数名称：KeyDown
功    能：薄膜矩阵键盘扫描
参    数：无
返回值  ：无
********************************************/
void KeyDown(void)
{
	uint8 a = 0;
        P6DIR |= 0x0F;  //P6端口低四位为输出，高四位不变        
        P6OUT |= 0x0F;  //P6端口低四位输出为1，高四位不变                       
        P6DIR &= 0xF0;  //P6端口低四位为输入，高四位不变
        
        P5DIR |= 0xF0;   //P5端口高四位为输出，低四位不变       
        P5OUT &= 0x0F;   //P5端口高四位输出为0,低四位不变 
        
	if((P6IN&0x0F)!=0x0F)//读取按键是否按下
	{     
		Delay(100);    //延时10ms进行消抖
		if((P6IN&0x0F)!=0x0F)//再次检测键盘是否按下
		{
                        //P1OUT &= ~(BIT4);
                        P6DIR |= 0x0F;  //P6端口低四位为输出，高四位不变        
                        P6OUT |= 0x0F;  //P6端口低四位输出为1，高四位不变                       
                        P6DIR &= 0xF0;  //P6端口低四位为输入，高四位不变
                        
                        P5DIR |= 0xF0;   //P5端口高四位为输出，低四位不变       
                        P5OUT &= 0x0F;   //P5端口高四位输出为0,低四位不变 
			switch(P6IN&0x0F)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d):     KeyValue=8;break;
				case(0X0e):	KeyValue=12;break;
			}
                        P6DIR |= 0x0F;  //P6端口低四位为输出，高四位不变        
                        P6OUT &= 0xF0;  //P6端口低四位输出为0，高四位不变                       
                        
                        P5DIR |= 0xF0;   //P5端口高四位为输出，低四位不变       
                        P5OUT |= 0xF0;   //P5端口高四位输出为1,低四位不变
                        P5DIR &= 0x0F;    //P5端口高四位为输入，低四位不变
			switch(P5IN&0xF0)
			{
				case(0X70):	KeyValue=KeyValue+3;break;
				case(0Xb0):	KeyValue=KeyValue+2;break;
				case(0Xd0):     KeyValue=KeyValue+1;break;
				case(0Xe0):	KeyValue=KeyValue;break;
			}
			while((a<10) && ((P5IN&0xF0)!=0xF0))	 //检测按键松手检测
			{
				Delay(10);
				a++;
			}
                        Deduction_display(KeyValue);//处理按键值以及发送上位机
                        BuzzerOn1s();  //蜂鸣器提示音
		}
	}
}
void main(void)
{
    WDTCTL     = WDTPW + WDTHOLD  ; // 关看门狗
    CLK_Init();        //初始化时钟
    Init_Port();       //MFRC522模块端口初始化
    UART_Init(UART1);  //串口初始化
    PcdReset();        //复位RC522
    PcdAntennaOn();    //开启天线发射 
    _EINT();           //开总中断
    UART_RIE_Enable(UART1, UART1_GetCharINT);//开串口一中断，UART_GetCharINT回调函数
    Init_Lcd();         //12864液晶初始化，固定显示
    while(1)
    {     
       if(Auto_Reader())  //自动识别卡号
       {   
           if(PcdRead(1,Read_Buffer)==MI_OK)  //读取0扇区，块1地址。因为块0地址不可修改
           {   
               if(!EqualBuffer(Halt_Buffer,Read_Buffer))//两次卡号不相同
               {  
                   /*显示卡号部分*/
                   Write_Cmd(0x91);
                   for(int i=10;i<16;i++)
                   {
                      if(Read_Buffer[i]<10)
                      {
                          if(i==10)
                             Write_Data('0'+Read_Buffer[i]);
                          else{
                             Write_Data('0');
                             Write_Data('0'+Read_Buffer[i]);
                          }
                      }
                      else{
                        Write_Data('0'+Read_Buffer[i]/10);
                        Write_Data('0'+Read_Buffer[i]%10);
                      } 
                   }
                   BuzzerOn1s();  //蜂鸣器提示音
                   FindCardflag=1; //发现IC卡置标志位，以便发送有效扣费信息
                   /*显示卡号部分*/
                   for(int i=0;i<16;i++)
                     Halt_Buffer[i]=Read_Buffer[i];
                   for(int i=10;i<16;i++)
                     Send1Char(UART1,Read_Buffer[i]);  //卡号发送到上位机
                   /*液晶余额显示*/
                   Write_Cmd(0x9D);
                   Delay(1000);  //延时让上位机有足够时间发送余额给下位机
                   Delay(1000);
                   Delay(1000);
                   for(int i=0;i<index;i++)  //开始显示余额
                   {
                       if((i==0)&(ReceiveBalance[i]==0)){
                           continue;
                       }
                       else{
                          if(ReceiveBalance[i]<10)
                            Write_Data('0'+ReceiveBalance[i]); 
                          else //显示小数点
                            Write_Data('7'+ReceiveBalance[i]);
                       }
                   }
               }
           }
       }
       KeyDown();
    }
}


