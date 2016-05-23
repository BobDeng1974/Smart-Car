#include "PWM.h"


void Pwm0_Init(void)
{
  
    PWMCLK_PCLK0=pwmclk_pclk00;    /*Ԥ��Ƶ���ʱ��ԴΪSA��A*/
    PWMPRCLK_PCKA=pwmprclk_pcka0;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk00==1
    PWMSCLA=pwmscla0;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLA*2*/
    #endif
    PWMPOL_PPOL0=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE0=0;    /*�����*/
    PWMPER0=pwmper0;    /*����*/
    PWMDTY0=pwmdty0;    /*ռ�ձ�*/
    PWME_PWME0=1;    /*����PWM*/
}


void Pwm1_Init(void)
{
   
    PWMCLK_PCLK1=pwmclk_pclk11;    /*Ԥ��Ƶ���ʱ��ԴΪSA��A*/
    PWMPRCLK_PCKA=pwmprclk_pcka1;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk11==1
    PWMSCLA=pwmscla1;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLA*2*/
    #endif
    PWMPOL_PPOL1=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE1=0;    /*�����*/
    PWMPER1=pwmper1;    /*����*/
    PWMDTY1=pwmdty1;    /*ռ�ձ�*/
    PWME_PWME1=1;    /*����PWM*/
}


void Pwm2_Init(void)
{
   
    PWMCLK_PCLK2=pwmclk_pclk22;    /*Ԥ��Ƶ���ʱ��ԴΪSB��B*/
    PWMPRCLK_PCKB=pwmprclk_pckb2;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk22==1
    PWMSCLB=pwmsclb2;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLB*2*/
    #endif
    PWMPOL_PPOL2=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE2=0;    /*�����*/
    PWMPER2=pwmper2;    /*����*/
    PWMDTY2=pwmdty2;    /*ռ�ձ�*/
    PWME_PWME2=1;    /*����PWM*/
}


void Pwm3_Init(void)
{
   
    PWMCLK_PCLK3=pwmclk_pclk33;    /*Ԥ��Ƶ���ʱ��ԴΪSB��B*/
    PWMPRCLK_PCKB=pwmprclk_pckb3;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk33==1
    PWMSCLB=pwmsclb3;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLB*2*/
    #endif
    PWMPOL_PPOL3=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE3=0;    /*�����*/
    PWMPER3=pwmper3;    /*����*/
    PWMDTY3=pwmdty3;    /*ռ�ձ�*/
    PWME_PWME3=1;    /*����PWM*/
}


void Pwm4_Init(void)
{
   
    PWMCLK_PCLK4=pwmclk_pclk44;    /*Ԥ��Ƶ���ʱ��ԴΪSA��A*/
    PWMPRCLK_PCKA=pwmprclk_pcka4;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk44==1
    PWMSCLA=pwmscla4;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLA*2*/
    #endif
    PWMPOL_PPOL4=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE4=0;    /*�����*/
    PWMPER4=pwmper4;    /*����*/
    PWMDTY4=pwmdty4;    /*ռ�ձ�*/
    PWME_PWME4=1;    /*����PWM*/
}


void Pwm5_Init(void)
{
   
    PWMCLK_PCLK5=pwmclk_pclk55;    /*Ԥ��Ƶ���ʱ��ԴΪSA��A*/
    PWMPRCLK_PCKA=pwmprclk_pcka5;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk55==1
    PWMSCLA=pwmscla5;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLA*2*/
    #endif
    PWMPOL_PPOL5=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE5=0;    /*�����*/
    PWMPER5=pwmper5;    /*����*/
    PWMDTY5=pwmdty5;    /*ռ�ձ�*/
    PWME_PWME5=1;    /*����PWM*/
}


void Pwm6_Init(void)
{
   
    PWMCLK_PCLK6=pwmclk_pclk66;    /*Ԥ��Ƶ���ʱ��ԴΪSB��B*/
    PWMPRCLK_PCKB=pwmprclk_pckb6;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk66==1
    PWMSCLB=pwmsclb6;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLB*2*/
    #endif
    PWMPOL_PPOL6=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE6=0;    /*�����*/
    PWMPER6=pwmper6;    /*����*/
    PWMDTY6=pwmdty6;    /*ռ�ձ�*/
    PWME_PWME6=1;    /*����PWM*/
}


void Pwm7_Init(void)
{
  
    PWMCLK_PCLK7=pwmclk_pclk77;    /*Ԥ��Ƶ���ʱ��ԴΪSB��B*/
    PWMPRCLK_PCKB=pwmprclk_pckb7;    /*Ԥ��Ƶ0--128*/
    #if  pwmclk_pclk77==1
    PWMSCLB=pwmsclb7;    /*��Ƶ0--256����Ƶ���Ҫ����2���� PWMSCLB*2*/
    #endif
    PWMPOL_PPOL7=1;    /*��ʼΪ�ߵ�ƽ�����ʱΪ�͵�ƽ*/
    PWMCAE_CAE7=0;    /*�����*/
    PWMPER7=pwmper7;    /*����*/
    PWMDTY7=pwmdty7;    /*ռ�ձ�*/
    PWME_PWME7=1;    /*����PWM*/
}