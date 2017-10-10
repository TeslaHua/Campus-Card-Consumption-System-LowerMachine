/***********************************************************
�����ܣ���12864Һ������ʾһ������
����˵�����۲�Һ����ʾ
***********************************************************/
#include  "include.h"


#define LCD_DataIn    P4DIR=0x00    //���ݿڷ�������Ϊ����
#define LCD_DataOut   P4DIR=0xff    //���ݿڷ�������Ϊ���
#define LCD2MCU_Data  P4IN
#define MCU2LCD_Data  P4OUT
#define LCD_CMDOut    P5DIR|=0x0F      //P5�ڵĵ�4λ����Ϊ���������P5.3�ķ�������
#define LCD_RS_H      P5OUT|=BIT0      //P5.0   д�����д����ѡ��
#define LCD_RS_L      P5OUT&=~BIT0     //P5.0
#define LCD_RW_H      P5OUT|=BIT1      //P5.1   ��дѡ��
#define LCD_RW_L      P5OUT&=~BIT1     //P5.1
#define LCD_EN_H      P5OUT|=BIT2      //P5.2   ʹ���ź�
#define LCD_EN_L      P5OUT&=~BIT2     //P5.2

/*******************************************/

uint8 RemindCardID[] = {"���Ŀ��ţ�"};
uint8 RemindDeduction[]={"�۷Ѷ�ȣ�"};
uint8 RemindBalance[]={"��"};
/*******************************************
�������ƣ�Delay_1ms
��    �ܣ���ʱԼ1ms��ʱ��
��    ������
����ֵ  ����
********************************************/
void Delay_1ms(void)
{
	uint8 i;
    
	for(i = 150;i > 0;i--)  _NOP();
} 
/*******************************************
�������ƣ�Delay_Nms
��    �ܣ���ʱN��1ms��ʱ��
��    ����n--��ʱ����
����ֵ  ����
********************************************/
void Delay_Nms(uint32 n)
{
    uint32 i;
    
    for(i = n;i > 0;i--)    Delay_1ms();
}
/*******************************************
�������ƣ�Write_Cmd
��    �ܣ���Һ����д��������
��    ����cmd--��������
����ֵ  ����
********************************************/
void Write_Cmd(uint8 cmd)
{
    uint8 lcdtemp = 0;
			
    LCD_RS_L;
    LCD_RW_H;
    LCD_DataIn;  
    do                       //��æ
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
�������ƣ�Write_Data
��    �ܣ���Һ����д��ʾ����
��    ����dat--��ʾ����
����ֵ  ����
********************************************/
void  Write_Data(uint8 dat)
{
    uint8 lcdtemp = 0;   
        
    LCD_RS_L;
    LCD_RW_H;  
    LCD_DataIn;   
    do                       //��æ
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
�������ƣ�Ini_Lcd
��    �ܣ���ʼ��Һ��ģ��
��    ������
����ֵ  ����
********************************************/
void Init_Lcd(void)
{                  

    LCD_CMDOut;    //Һ�����ƶ˿�����Ϊ���
    
    Delay_Nms(500);
    Write_Cmd(0x30);   //����ָ�
    Delay_1ms();
    Write_Cmd(0x02);   //��ַ��λ
    Delay_1ms();
    Write_Cmd(0x0c);   //������ʾ��,�α�ر�
    Delay_1ms();
    Write_Cmd(0x01);   //�����ʾ
    Delay_1ms();
    Write_Cmd(0x06);   //�α�����
    Delay_1ms();
    Write_Cmd(0x80);   //�趨��ʾ����ʼ��ַ
    
    /*Һ���̶���ʾ��*/
    Display(0x80,RemindCardID);   
    Display(0x88,RemindDeduction);
    Display(0x9A,RemindBalance);
}
/*******************************************
�������ƣ�Display
��    �ܣ�����Һ����ʾ����
��    ����addr--��ʾλ�õ��׵�ַ
          pt--ָ����ʾ���ݵ�ָ��
����ֵ  ����
********************************************/
void Display(uint8 addr,uint8 * pt)
{
    Write_Cmd(addr); 
    while((*pt)!='\0') 
      Write_Data(*(pt++)); 
} 
/*******************************************
�������ƣ�DisplayNum
��    �ܣ�����Һ����ʾ����
��    ����addr--��ʾλ�õ��׵�ַ
          number--ָ����ʾ���ݵ�ָ��
����ֵ  ����
********************************************/
void DisplayChar(uint8 addr,uint8 number)
{
    Write_Cmd(addr);  
    if(number<10)
      Write_Data('0'+number); 
    else 
      Write_Data('7'+number);
}
