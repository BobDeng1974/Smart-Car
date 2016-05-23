/*============================================
����MC9S12XS128�๦�ܿ����� 
Designed by Chiu Sir
E-mail:chiusir@163.com
����汾:V1.1
������:2009��11��26��
�����Ϣ�ο����е�ַ��
��վ��  http://www.lqist.cn
�Ա��꣺http://shop36265907.taobao.com   
============================================*/
#include "derivative.h" 

#include "SDdriver.h"
#include "mc9s12xs128.h"
         
#define SD_Sel()   PTM_PTM3=0        //�͵�ƽ
#define SD_deSel() PTM_PTM3=1        //�ߵ�ƽ

extern byte RXBUF[]; 

#pragma CODE_SEG DEFAULT  
void Dly_ms(int ms)
{   
   int ii,jj;
   if (ms<1) ms=1;
   for(ii=0;ii<ms;ii++)
     for(jj=0;jj<1335;jj++);  //16MHz--1ms
     
}
void New_Buf8(byte buffer[],byte ch)
{
    //-- Tx & Rx Buffer initialize
    int i, j=0;
    for(i=0;i<512;i++)
		*(buffer+i)=ch;   
}

void CLS_Buf8(byte buffer[])
{
    //-- Flushing Rx buffer 
    int i;     
    for(i=0;i<512;i++)
		*(buffer+i)=0;
}                                                 

void Init_Dev(void)
{
  //SetBusCLK_16M();
  InitPorts();
  PORTB=0;   
  //SCI_Init();      
}   
 
//д����һ���ֽ�
byte SPI_RdWr_Byte(byte val)
{
	while (!SPI0SR_SPTEF);   
	SPI0DRL = val;
	while(!(SPI0SR_SPIF));
	return SPI0DRL;
}
void SPI_High_Rate(void) 
{ 
  //��߲������ʲ��ܸ���25Mbps
  SPI0BR  = 0x00; //BR=busclk/((SPPR + 1)�� 2^(SPR + 1))=32M/8=2M                
};
//sd����ʼ��
void SD_Init(void)
{ 	
  SPI0CR2 = 0x10;
  SPI0CR1 = 0x5e;    
  SPI0BR  = 0x77;    
	SD_deSel();
}

//sd��д����
byte SD_Send_Cmd(byte cmd, dword arg)
{
	byte r1;
	byte retry=0;
	
	(void)SPI_RdWr_Byte(0xff);
	SD_Sel();
	
	(void)SPI_RdWr_Byte(cmd | 0x40);          //�ֱ�д������
	(void)SPI_RdWr_Byte((byte)(arg>>24));
	(void)SPI_RdWr_Byte((byte)(arg>>16));
	(void)SPI_RdWr_Byte((byte)(arg>>8));
	(void)SPI_RdWr_Byte((byte)(arg));
	(void)SPI_RdWr_Byte(0x95);
	r1 = SPI_RdWr_Byte(0xff);
	while(r1== 0xff) //�ȴ���Ӧ��
	{
	  r1 = SPI_RdWr_Byte(0xff);
		if(++retry > 100) break;                //��ʱ�˳�
	}
	SD_deSel();

	return r1;                                //����״ֵ̬
}

//sd����λ
byte SD_Reset(void)
{
	byte i;
	byte retry;
	byte r1=0;
	retry = 0; 	
	do
	{
		for(i=0;i<10;i++) 
		  (void)SPI_RdWr_Byte(0xff);
		r1 = SD_Send_Cmd(0, 0);                 //��idle���� 	
		if(++retry>100) return 1;               //��ʱ�˳�
	}while(r1 != 0x01);   

	retry = 0;
	do
	{
		r1 = SD_Send_Cmd(1, 0);           //��active����  		
		if(++retry>100) return 1;         //��ʱ�˳�
	} while(r1);
	
	r1 = SD_Send_Cmd(59, 0);            //��crc

	r1 = SD_Send_Cmd(16, 512);          //��������С512

	return 0;                           //��������
}


#pragma CODE_SEG DEFAULT
//дһ������
byte Wt_Block(dword sector, byte* buffer)//����512�ֽ�
{
	byte r1;
	word i;
	//byte retry=0;
  if(sector<1) return 0xff;         //Ϊ�˱���SD������������������
	r1 = SD_Send_Cmd(24, sector<<9);  //д����
	if(r1 != 0x00) return r1;

	SD_Sel();
	
	(void)SPI_RdWr_Byte(0xff);
	(void)SPI_RdWr_Byte(0xff);
	(void)SPI_RdWr_Byte(0xff); 
	(void)SPI_RdWr_Byte(0xfe);        //����ʼ��
	
	for(i=0; i<512; i++)              //��512�ֽ�����
	{
		(void)SPI_RdWr_Byte(*buffer++);
	}
	
	(void)SPI_RdWr_Byte(0xff);
	(void)SPI_RdWr_Byte(0xff);
	
	r1 = SPI_RdWr_Byte(0xff);
	
	if((r1&0x1f) != 0x05)             //�ȴ��Ƿ�ɹ�
	{
	  SD_deSel();
		return r1;
	}
	//�ȴ�������
	while(!SPI_RdWr_Byte(0xff));      //if(++retry > 50){SPI_CS_Deassert();return 1;}

  SD_deSel();

	return 0;     
}
 
//��һ������
byte Rd_Block(dword sector, byte* buffer)
{
	byte r1;          
	word i;
	//byte retry=0;

	r1 = SD_Send_Cmd(17, sector<<9);//������ 	
	if(r1 != 0x00) 		return r1;

	SD_Sel();
	//�����ݵĿ�ʼ
	while(SPI_RdWr_Byte(0xff) != 0xfe);//if(++retry > 50){SD_deSel();return 1;}

	for(i=0; i<512; i++)//��512������
	{
		*buffer++ = SPI_RdWr_Byte(0xff);
	}

	(void)SPI_RdWr_Byte(0xff);//αcrc
	(void)SPI_RdWr_Byte(0xff);  	
	SD_deSel();

	return 0;
} 


#pragma CODE_SEG DEFAULT 


