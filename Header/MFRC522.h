#ifndef __MFRC522_H
#define __MFRC522_H

#define MAXRLEN        18
#define MIN_STRENGTH  228
#define OK  1
#define ERROR  0
extern unsigned char Read_Buffer[16];  //��ȡIC����һ������
extern unsigned char Password_Buffer[6]; // ����Ĭ������
extern unsigned char Write_Buffer[16];
//***************************************************************************//
//                                                                           //
//                       ���Ź��ܶ���                                        //
//                                                                           //
//***************************************************************************//
#define RF_LPCTL               BIT4  // P2.4 ��Ƶ�����߿��� ------RST   
#define RF_SS                  BIT3  // p2.3 ��Ƶ���ӻ�ѡ��(SS)---SDA
#define RF_SCLK                BIT7  // p1.7 ��Ƶ������ʱ�����(SCLK)
#define RF_DATA_OUT            BIT1  // p2.1 ��Ƶ���������(MOSI)
#define RF_DATA_IN             BIT0  // p2.0 ��Ƶģ������(MISO) 

//#define RF_LPCTL               BIT3  // P2.4 ��Ƶ�����߿��� ------RST   
//#define RF_SS                  BIT7  // p2.3 ��Ƶ���ӻ�ѡ��(SS)---SDA
//#define RF_SCLK                BIT6  // p2.7 ��Ƶ������ʱ�����(SCLK)
//#define RF_DATA_OUT            BIT5  // p2.1 ��Ƶ���������(MOSI)
//#define RF_DATA_IN             BIT0  // p2.0 ��Ƶģ������(MISO) 
//****************************************************************************
//                                                                           *
//                           RC522�����궨��                                      *
//                                                                           *
//****************************************************************************
//#define    RF_POWER_ON             P8OUT &=~RF_PCTL                      // ��Ƶģ���ϵ�
//#define    RF_POWER_OFF            P8OUT |= RF_PCTL                      // ��Ƶģ���µ�
#define    RF_POWER_ON             _NOP()                                // ��Ƶģ���ϵ�
#define    RF_POWER_OFF            _NOP()                                // ��Ƶģ���µ�

#define    RF_SLEEP                P2OUT &=~RF_LPCTL                     // ��Ƶģ�黽��
#define    RF_WAKEUP               P2OUT |= RF_LPCTL                     // ��Ƶģ������
#define    SCLK_HIGH               P1OUT |= RF_SCLK                      // ����ʱ���ø�
#define    SCLK_LOW                P1OUT &=~RF_SCLK                      // ����ʱ���õ�
#define    DATA_OUT_HIGH           P2OUT |= RF_DATA_OUT                  // �����ø�
#define    DATA_OUT_LOW            P2OUT &=~RF_DATA_OUT                  // �����õ�
#define    SS_HIGH                 P2OUT |= RF_SS                        // �ӻ�ѡ����Ч
#define    SS_LOW                  P2OUT &=~RF_SS                        // �ӻ�ѡ����Ч
#define    DATA_IN                 P2IN  &  RF_DATA_IN                   // ��������

#define    NSS522_1                P2OUT |= RF_SS                        // �ӻ�ѡ����Ч       
#define    NSS522_0                P2OUT &=~RF_SS                        // �ӻ�ѡ����Ч
#define    SCK522_1                P1OUT |= RF_SCLK                      // ����ʱ���ø�
#define    SCK522_0                P1OUT &=~RF_SCLK                      // ����ʱ���õ�
#define    SI522_1                 P2OUT |= RF_DATA_OUT                  // �����ø�        
#define    SI522_0                 P2OUT &=~RF_DATA_OUT                  // �����õ�        
#define    SO522                   P2IN  &  RF_DATA_IN           // ��������
#define    RST522_1                P2OUT |= RF_LPCTL
#define    RST522_0                P2OUT &=~RF_LPCTL


//------------------------------ �������  ---------------------------------------//
#define    SUCCESS                    0
#define    FAILURE                    1
#define    CRC_ERROR                  2

//******************************************************************/
//                       RC522 FIFO���ȶ���                            /
//******************************************************************/
#define DEF_FIFO_LENGTH             64           //FIFO size=64byte

//******************************************************************/
//                       RC522������                                /
//******************************************************************/
#define PCD_IDLE                  0x00           //ȡ����ǰ����
#define PCD_AUTHENT               0x0E           //��֤��Կ
#define PCD_RECEIVE               0x08           //��������
#define PCD_TRANSMIT              0x04           //��������
#define PCD_TRANSCEIVE            0x0C           //���Ͳ���������
#define PCD_RESETPHASE            0x0F           //��λ
#define PCD_CALCCRC               0x03           //CRC����

//******************************************************************/
//                   Mifare_One��Ƭ������                          */
//******************************************************************/
#define PICC_REQIDL               0x26           //Ѱ��������δ��������״̬
#define PICC_REQALL               0x52           //Ѱ��������ȫ����
#define PICC_ANTICOLL1            0x93           //����ײ
#define PICC_ANTICOLL2            0x95           //����ײ
#define PICC_AUTHENT1A            0x60           //��֤A��Կ
#define PICC_AUTHENT1B            0x61           //��֤B��Կ
#define PICC_READ                 0x30           //����
#define PICC_WRITE                0xA0           //д��
#define PICC_DECREMENT            0xC0           //�ۿ�
#define PICC_INCREMENT            0xC1           //��ֵ
#define PICC_RESTORE              0xC2           //�������ݵ�������
#define PICC_TRANSFER             0xB0           //���滺����������
#define PICC_HALT                 0x50           //����

//******************************************************************/
//                        MF522�Ĵ�������                           /
//******************************************************************/
// PAGE 0
#define     RFU00                 0x00    
#define     CommandReg            0x01    
#define     ComIEnReg             0x02    
#define     DivlEnReg             0x03    
#define     ComIrqReg             0x04    
#define     DivIrqReg             0x05
#define     ErrorReg              0x06    
#define     Status1Reg            0x07    
#define     Status2Reg            0x08    
#define     FIFODataReg           0x09
#define     FIFOLevelReg          0x0A
#define     WaterLevelReg         0x0B
#define     ControlReg            0x0C
#define     BitFramingReg         0x0D
#define     CollReg               0x0E
#define     RFU0F                 0x0F
// PAGE 1     
#define     RFU10                 0x10
#define     ModeReg               0x11
#define     TxModeReg             0x12
#define     RxModeReg             0x13
#define     TxControlReg          0x14
#define     TxASKReg              0x15
#define     TxSelReg              0x16
#define     RxSelReg              0x17
#define     RxThresholdReg        0x18
#define     DemodReg              0x19
#define     RFU1A                 0x1A
#define     RFU1B                 0x1B
#define     MifareReg             0x1C
#define     RFU1D                 0x1D
#define     RFU1E                 0x1E
#define     SerialSpeedReg        0x1F
// PAGE 2    
#define     RFU20                 0x20  
#define     CRCResultRegM         0x21
#define     CRCResultRegL         0x22
#define     RFU23                 0x23
#define     ModWidthReg           0x24
#define     RFU25                 0x25
#define     RFCfgReg              0x26
#define     GsNReg                0x27
#define     CWGsCfgReg            0x28
#define     ModGsCfgReg           0x29
#define     TModeReg              0x2A
#define     TPrescalerReg         0x2B
#define     TReloadRegH           0x2C
#define     TReloadRegL           0x2D
#define     TCounterValueRegH     0x2E
#define     TCounterValueRegL     0x2F
// PAGE 3      
#define     RFU30                 0x30
#define     TestSel1Reg           0x31
#define     TestSel2Reg           0x32
#define     TestPinEnReg          0x33
#define     TestPinValueReg       0x34
#define     TestBusReg            0x35
#define     AutoTestReg           0x36
#define     VersionReg            0x37
#define     AnalogTestReg         0x38
#define     TestDAC1Reg           0x39  
#define     TestDAC2Reg           0x3A   
#define     TestADCReg            0x3B   
#define     RFU3C                 0x3C   
#define     RFU3D                 0x3D   
#define     RFU3E                 0x3E   
#define     RFU3F		  0x3F

//******************************************************************/
//                            RC522ͨѶ���ش������                         /
//******************************************************************/
#define MI_ERR                      0xFE 
//#define MI_ERR                         //(-2)


// Mifare Error Codes 
// Each function returns a status value, which corresponds to the 
// mifare error codes. 

#define MI_OK                          0 
#define MI_CHK_OK                      0 
#define MI_CRC_ZERO                    0 

#define MI_CRC_NOTZERO                 1 

#define MI_NOTAGERR                 0xFF 
#define MI_CHK_FAILED               0xFF 
#define MI_CRCERR                   0xFE 
#define MI_CHK_COMPERR              0xFE 
#define MI_EMPTY                    0xFD 
#define MI_AUTHERR                  0xFC 
#define MI_PARITYERR                0xFB 
#define MI_CODEERR                  0xFA 

#define MI_SERNRERR                 0xF8 
#define MI_KEYERR                   0xF7 
#define MI_NOTAUTHERR               0xF6 
#define MI_BITCOUNTERR              0xF5 
#define MI_BYTECOUNTERR             0xF4 
#define MI_IDLE                     0xF3 
#define MI_TRANSERR                 0xF2 
#define MI_WRITEERR                 0xF1 
#define MI_INCRERR                  0xF0 
#define MI_DECRERR                  0xEF 
#define MI_READERR                  0xEE 
#define MI_OVFLERR                  0xED 
#define MI_POLLING                  0xEC 
#define MI_FRAMINGERR               0xEB 
#define MI_ACCESSERR                0xEA 
#define MI_UNKNOWN_COMMAND          0xE9 
#define MI_COLLERR                  0xE8 
#define MI_RESETERR                 0xE7 
#define MI_INITERR                  0xE7 
#define MI_INTERFACEERR             0xE7 
#define MI_ACCESSTIMEOUT            0xE5 
#define MI_NOBITWISEANTICOLL        0xE4 
#define MI_QUIT                     0xE2 

#define MI_RECBUF_OVERFLOW          0xCF 
#define MI_SENDBYTENR               0xCE 

#define MI_SENDBUF_OVERFLOW         0xCC 
#define MI_BAUDRATE_NOT_SUPPORTED   0xCB 
#define MI_SAME_BAUDRATE_REQUIRED   0xCA 

#define MI_WRONG_PARAMETER_VALUE    0xC5 

#define MI_BREAK                    0x9E 
#define MI_NY_IMPLEMENTED           0x9D 
#define MI_NO_MFRC                  0x9C 
#define MI_MFRC_NOTAUTH             0x9B 
#define MI_WRONG_DES_MODE           0x9A 
#define MI_HOST_AUTH_FAILED         0x99 

#define MI_WRONG_LOAD_MODE          0x97 
#define MI_WRONG_DESKEY             0x96 
#define MI_MKLOAD_FAILED            0x95 
#define MI_FIFOERR                  0x94 
#define MI_WRONG_ADDR               0x93 
#define MI_DESKEYLOAD_FAILED        0x92 

#define MI_WRONG_SEL_CNT            0x8F 
#define MI_RC531_WRONG_READVALUE    0x8E //LI ADDED 09-4-24 
#define MI_WRONG_TEST_MODE          0x8C 
#define MI_TEST_FAILED              0x8B 
#define MI_TOC_ERROR                0x8A 
#define MI_COMM_ABORT               0x89 
#define MI_INVALID_BASE             0x88 
#define MI_MFRC_RESET               0x87 
#define MI_WRONG_VALUE              0x86 
#define MI_VALERR                   0x85

//******************************************************************/
//                         ��������                                 /
//******************************************************************/
void Init_Port(void);  //��Ӧ�˿ڶ���
void Delay(uint16 time);//�����ʱ
char PcdHalt(void);   //��Ƭ��������״̬
char PcdReset(void);  //��λRC522
void PcdAntennaOn(void);  //�����߽���
void PcdAntennaOff(void); //�����߽���
char PcdRequest(unsigned char req_code,unsigned char *pTagType);//Ѱ��    
char PcdAnticoll(unsigned char *pSnr);//����ײ
char PcdSelect(unsigned char *pSnr);  //ѡ��       
char PcdAuthState(unsigned char auth_mode,unsigned char addr,
                  unsigned char *pKey,unsigned char *pSnr); //��֤��Ƭ����    
char PcdRead(unsigned char addr,unsigned char *pData); //��ȡһ������    
char PcdWrite(unsigned char addr,unsigned char *pData); //д��һ������   
//�ۿ�ͳ�ֵ
char PcdValue(unsigned char dd_mode,unsigned char addr,unsigned char *pValue);
//����Ǯ��
char PcdBakValue(unsigned char sourceaddr, unsigned char goaladdr);  

char PcdComMF522(unsigned char Command, unsigned char *pInData, 
                 unsigned char InLenByte,unsigned char *pOutData, 
                 unsigned int  *pOutLenBit); //ͨ��RC522��ISO14443��ͨѶ
void CalulateCRC(unsigned char *pIndata,unsigned char len,
                 unsigned char *pOutData);//��MF522����CRC16����
void WriteRawRC(unsigned char Address,unsigned char value);//дRC522�Ĵ���
unsigned char ReadRawRC(unsigned char Address);  //��RC522�Ĵ���
void SetBitMask(unsigned char reg,unsigned char mask); //��RC522�Ĵ���λ
void ClearBitMask(unsigned char reg,unsigned char mask);//���RC522�Ĵ���λ 

uint8 EqualBuffer(uint8 Read_Buffer[],uint8 HaltBuffer[]);
unsigned char Auto_Reader(void);//�Զ�Ѱ������
#endif