#include "ECT.h"

void Ect7_Init(void)
{
    TIOS_IOS7=tios_ios0; 
    TCTL3_EDG7x=edge_select0;
          
    #if input0_interrupt 
    TIE_C7I=1;
    #else
    TIE_C7I=0;    
    #endif
    
    #if tios_ios0       // Compare mode
    TC7H=tc0h;
    TC7L=tc0l;
    #endif
    
    TSCR2_PR=tscr2_pr0;    
    TSCR1_TEN=0;        // Unable
    
    PACTL_PEDGE=1;      // Rising edges on IOC7 pin cause the count to be incremented.                    
    PACTL_PAMOD=0;      // Event counter mode.
    PACTL_CLK0=1;       // Use PACLK as input to timer counter clock
    PACTL_PAEN=1;       // Enable
}

/***************************************16λ�����ۼ���*********************************************
* Ҫ�ֶ�����жϱ�־λ,��׽�������־Ϊ  PAFLG_PAIF   ����жϱ��ΪPAFLG_PAOVF
* �Ĵ���Ϊ PACNT����������
* ����Ĭ�ϲ���Ƶ  
***************************************************************************************************/
void Pulse_Add_Init(void)
{
 
    PACTL=0x42;  //0x42:16λ���������ʹ��;��������ж�ʹ��;��PACLK\256��Ϊ����ʱ��;
                 //0x40:16λ���������ʹ��;��������жϽ�ֹ;��PACLK\256��Ϊ����ʱ��;
    
    PACTL_CLK=3; //0---Use timer prescaler clock as timer counter clock
                 //1---Use PACLK as input to timer counter clock
                 //2---Use PACLK/256 as timer counter clock frequency
                 //3---Use PACLK/65536 as timer counter clock frequency        
    //TSCR2_PR=0;  //1��Ƶ

}








