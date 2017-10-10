
#include "include.h"

uint8 KeyValue;    //ʵ�ʰ���ֵ
uint8 Read_Buffer[16];
uint8 Halt_Buffer[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8 ArrayDeduction[10];
uint8 arraynum=0;
uint8 FindCardflag=0;
extern uint8 index;
extern uint8 ReceiveBalance[10];

/*******************************************
�������ƣ�Transformation
��    �ܣ���Ĥ���������ʵ��ת��
��    ����number--ʵ��ֵ
����ֵ  ����Ĥ�����ϵ�ֵ
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
�������ƣ��۷���ʾ�Լ�ȷ��ͨ��
��    ��������ֵ������*�Ŵ���С���㣬#�����������
����ֵ  ����
********************************************/
void Deduction_display(uint8 KeyValue)
{
     if(FindCardflag)  //�п�����
     {
         Write_Cmd(0x8D);  //�۷ѽ������̶�λ��
         if(Transformation(KeyValue)==15)  //����ȷ�ϼ�(���ż�)
         {
              Send1Char(UART1,100);  //����100��־�����𿨺����루���������0x99��
              Send1Char(UART1,100);  //�ڷ���һ��100����ֹ�޿۷ѽ���λ��read()��ȡ����
              for(int i=0;i<arraynum;i++)
              {
                  Send1Char(UART1,ArrayDeduction[i]);//�۷ѽ��͵���λ��
                  ArrayDeduction[i]=0;               //�˴��������������Ա��´�����
                  Write_Data(' ');                   //��տ۷���ʾ
              }
              FindCardflag=0;  //�巢�ֿ��ı�־λ
              arraynum=0;      //����Ա��´�����
              /*��տ�����ʾ������շ��ظ�ʶ������*/
              Write_Cmd(0x90); 
              for(int i=0;i<16;i++)
              {
                  Write_Data(' ');
                  Halt_Buffer[i]=0;
              }
              /*��������ʾ����������������*/
              Write_Cmd(0x9D); 
              for(int i=0;i<index;i++)
              {
                 ReceiveBalance[i]=0;
                 Write_Data(' ');
              }
              index=0;             
         }
         else if(Transformation(KeyValue)==12){   //(��������ʱ)���һ������۷�λ��C�ַ���
             if(arraynum>0)
             {  
                 for(int i=0;i<arraynum;i++)  //��ʾ�۷�ÿλ
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
             if(Transformation(KeyValue)==14) //����С���㣨�Ǻż���
                ArrayDeduction[arraynum]='.';
             else
                ArrayDeduction[arraynum]=Transformation(KeyValue);  //�ѿ۷�ÿλ��������
             for(int i=0;i<=arraynum;i++)  //��ʾ�۷�ÿλ
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
�������ƣ�KeyDown
��    �ܣ���Ĥ�������ɨ��
��    ������
����ֵ  ����
********************************************/
void KeyDown(void)
{
	uint8 a = 0;
        P6DIR |= 0x0F;  //P6�˿ڵ���λΪ���������λ����        
        P6OUT |= 0x0F;  //P6�˿ڵ���λ���Ϊ1������λ����                       
        P6DIR &= 0xF0;  //P6�˿ڵ���λΪ���룬����λ����
        
        P5DIR |= 0xF0;   //P5�˿ڸ���λΪ���������λ����       
        P5OUT &= 0x0F;   //P5�˿ڸ���λ���Ϊ0,����λ���� 
        
	if((P6IN&0x0F)!=0x0F)//��ȡ�����Ƿ���
	{     
		Delay(100);    //��ʱ10ms��������
		if((P6IN&0x0F)!=0x0F)//�ٴμ������Ƿ���
		{
                        //P1OUT &= ~(BIT4);
                        P6DIR |= 0x0F;  //P6�˿ڵ���λΪ���������λ����        
                        P6OUT |= 0x0F;  //P6�˿ڵ���λ���Ϊ1������λ����                       
                        P6DIR &= 0xF0;  //P6�˿ڵ���λΪ���룬����λ����
                        
                        P5DIR |= 0xF0;   //P5�˿ڸ���λΪ���������λ����       
                        P5OUT &= 0x0F;   //P5�˿ڸ���λ���Ϊ0,����λ���� 
			switch(P6IN&0x0F)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=4;break;
				case(0X0d):     KeyValue=8;break;
				case(0X0e):	KeyValue=12;break;
			}
                        P6DIR |= 0x0F;  //P6�˿ڵ���λΪ���������λ����        
                        P6OUT &= 0xF0;  //P6�˿ڵ���λ���Ϊ0������λ����                       
                        
                        P5DIR |= 0xF0;   //P5�˿ڸ���λΪ���������λ����       
                        P5OUT |= 0xF0;   //P5�˿ڸ���λ���Ϊ1,����λ����
                        P5DIR &= 0x0F;    //P5�˿ڸ���λΪ���룬����λ����
			switch(P5IN&0xF0)
			{
				case(0X70):	KeyValue=KeyValue+3;break;
				case(0Xb0):	KeyValue=KeyValue+2;break;
				case(0Xd0):     KeyValue=KeyValue+1;break;
				case(0Xe0):	KeyValue=KeyValue;break;
			}
			while((a<10) && ((P5IN&0xF0)!=0xF0))	 //��ⰴ�����ּ��
			{
				Delay(10);
				a++;
			}
                        Deduction_display(KeyValue);//������ֵ�Լ�������λ��
                        BuzzerOn1s();  //��������ʾ��
		}
	}
}
void main(void)
{
    WDTCTL     = WDTPW + WDTHOLD  ; // �ؿ��Ź�
    CLK_Init();        //��ʼ��ʱ��
    Init_Port();       //MFRC522ģ��˿ڳ�ʼ��
    UART_Init(UART1);  //���ڳ�ʼ��
    PcdReset();        //��λRC522
    PcdAntennaOn();    //�������߷��� 
    _EINT();           //�����ж�
    UART_RIE_Enable(UART1, UART1_GetCharINT);//������һ�жϣ�UART_GetCharINT�ص�����
    Init_Lcd();         //12864Һ����ʼ�����̶���ʾ
    while(1)
    {     
       if(Auto_Reader())  //�Զ�ʶ�𿨺�
       {   
           if(PcdRead(1,Read_Buffer)==MI_OK)  //��ȡ0��������1��ַ����Ϊ��0��ַ�����޸�
           {   
               if(!EqualBuffer(Halt_Buffer,Read_Buffer))//���ο��Ų���ͬ
               {  
                   /*��ʾ���Ų���*/
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
                   BuzzerOn1s();  //��������ʾ��
                   FindCardflag=1; //����IC���ñ�־λ���Ա㷢����Ч�۷���Ϣ
                   /*��ʾ���Ų���*/
                   for(int i=0;i<16;i++)
                     Halt_Buffer[i]=Read_Buffer[i];
                   for(int i=10;i<16;i++)
                     Send1Char(UART1,Read_Buffer[i]);  //���ŷ��͵���λ��
                   /*Һ�������ʾ*/
                   Write_Cmd(0x9D);
                   Delay(1000);  //��ʱ����λ�����㹻ʱ�䷢��������λ��
                   Delay(1000);
                   Delay(1000);
                   for(int i=0;i<index;i++)  //��ʼ��ʾ���
                   {
                       if((i==0)&(ReceiveBalance[i]==0)){
                           continue;
                       }
                       else{
                          if(ReceiveBalance[i]<10)
                            Write_Data('0'+ReceiveBalance[i]); 
                          else //��ʾС����
                            Write_Data('7'+ReceiveBalance[i]);
                       }
                   }
               }
           }
       }
       KeyDown();
    }
}


