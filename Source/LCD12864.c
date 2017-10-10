/***********************************************************
程序功能：在12864液晶上显示一屏汉字
测试说明：观察液晶显示
***********************************************************/
#include  "include.h"


#define LCD_DataIn    P4DIR=0x00    //数据口方向设置为输入
#define LCD_DataOut   P4DIR=0xff    //数据口方向设置为输出
#define LCD2MCU_Data  P4IN
#define MCU2LCD_Data  P4OUT
#define LCD_CMDOut    P5DIR|=0x0F      //P5口的低4位设置为输出（包括P5.3的蜂鸣器）
#define LCD_RS_H      P5OUT|=BIT0      //P5.0   写命令和写数据选择
#define LCD_RS_L      P5OUT&=~BIT0     //P5.0
#define LCD_RW_H      P5OUT|=BIT1      //P5.1   读写选择
#define LCD_RW_L      P5OUT&=~BIT1     //P5.1
#define LCD_EN_H      P5OUT|=BIT2      //P5.2   使能信号
#define LCD_EN_L      P5OUT&=~BIT2     //P5.2

/*******************************************/

uint8 RemindCardID[] = {"您的卡号："};
uint8 RemindDeduction[]={"扣费额度："};
uint8 RemindBalance[]={"余额："};
/*******************************************
函数名称：Delay_1ms
功    能：延时约1ms的时间
参    数：无
返回值  ：无
********************************************/
void Delay_1ms(void)
{
	uint8 i;
    
	for(i = 150;i > 0;i--)  _NOP();
} 
/*******************************************
函数名称：Delay_Nms
功    能：延时N个1ms的时间
参    数：n--延时长度
返回值  ：无
********************************************/
void Delay_Nms(uint32 n)
{
    uint32 i;
    
    for(i = n;i > 0;i--)    Delay_1ms();
}
/*******************************************
函数名称：Write_Cmd
功    能：向液晶中写控制命令
参    数：cmd--控制命令
返回值  ：无
********************************************/
void Write_Cmd(uint8 cmd)
{
    uint8 lcdtemp = 0;
			
    LCD_RS_L;
    LCD_RW_H;
    LCD_DataIn;  
    do                       //判忙
    {    
        LCD_EN_H;
       	_NOP();					
       	lcdtemp = LCD2MCU_Data; 
       	LCD_EN_L;  
    }
    while(lcdtemp & 0x80); 
    LCD_DataOut;    
    LCD_RW_L;  		
    MCU2LCD_Data = cmd; 
    LCD_EN_H;
    _NOP();						  			
    LCD_EN_L;
}
/*******************************************
函数名称：Write_Data
功    能：向液晶中写显示数据
参    数：dat--显示数据
返回值  ：无
********************************************/
void  Write_Data(uint8 dat)
{
    uint8 lcdtemp = 0;   
        
    LCD_RS_L;
    LCD_RW_H;  
    LCD_DataIn;   
    do                       //判忙
    {    
        LCD_EN_H;
        _NOP();						
        lcdtemp = LCD2MCU_Data; 
        LCD_EN_L;      
    }
    while(lcdtemp & 0x80);  
    
    LCD_DataOut; 
    LCD_RS_H;
    LCD_RW_L;  
        
    MCU2LCD_Data = dat;
    LCD_EN_H;
    _NOP();
    LCD_EN_L;
}  
/*******************************************
函数名称：Ini_Lcd
功    能：初始化液晶模块
参    数：无
返回值  ：无
********************************************/
void Init_Lcd(void)
{                  

    LCD_CMDOut;    //液晶控制端口设置为输出
    
    Delay_Nms(500);
    Write_Cmd(0x30);   //基本指令集
    Delay_1ms();
    Write_Cmd(0x02);   //地址归位
    Delay_1ms();
    Write_Cmd(0x0c);   //整体显示打开,游标关闭
    Delay_1ms();
    Write_Cmd(0x01);   //清除显示
    Delay_1ms();
    Write_Cmd(0x06);   //游标右移
    Delay_1ms();
    Write_Cmd(0x80);   //设定显示的起始地址
    
    /*液晶固定显示处*/
    Display(0x80,RemindCardID);   
    Display(0x88,RemindDeduction);
    Display(0x9A,RemindBalance);
}
/*******************************************
函数名称：Display
功    能：控制液晶显示汉字
参    数：addr--显示位置的首地址
          pt--指向显示数据的指针
返回值  ：无
********************************************/
void Display(uint8 addr,uint8 * pt)
{
    Write_Cmd(addr); 
    while((*pt)!='\0') 
      Write_Data(*(pt++)); 
} 
/*******************************************
函数名称：DisplayNum
功    能：控制液晶显示数字
参    数：addr--显示位置的首地址
          number--指向显示数据的指针
返回值  ：无
********************************************/
void DisplayChar(uint8 addr,uint8 number)
{
    Write_Cmd(addr);  
    if(number<10)
      Write_Data('0'+number); 
    else 
      Write_Data('7'+number);
}
