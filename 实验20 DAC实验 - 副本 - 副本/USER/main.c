#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "oled.h"
#include "usart.h"	 	 
#include "dac.h"
#include "adc.h"
#include "usmart.h"
 
/************************************************
 ALIENTEKս��STM32������ʵ��20
 DAC ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


 int main(void)
 {	 
	u16 adcx;
	float temp;
 	u8 t=0;	 
	u16 dacval=0;
	u8 key;
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	KEY_Init();			  //��ʼ����������
 	LED_Init();			     //LED�˿ڳ�ʼ��
	
 	Adc_Init();		  		//ADC��ʼ��
	Dac1_Init();				//DAC��ʼ��

	OLED_Init();			//��ʼ��OLED      
  OLED_ShowString(0,0,"ZHUYU",24);  
//	OLED_ShowString(0,24, "0.96' DAC TEST",16);  
// 	OLED_ShowString(0,40,"ATOM 2017/5/19",12);  
// 	OLED_ShowString(0,52,"ASCII:",12);  
// 	OLED_ShowString(64,52,"CODE:",12);  
  
	OLED_Refresh_Gram();		//������ʾ��OLED 
	
	 DAC_SetChannel1Data(DAC_Align_12b_R, 0);//��ʼֵΪ0	    	      
	while(1)
	{
		
//		Dac1_Set_Vol(2000);
//		t++;
//		key=KEY_Scan(0);			  
//		if(key==WKUP_PRES)
//		{		 
//			if(dacval<4000)dacval+=200;
//		 DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ	
//		}else if(key==KEY1_PRES)	
//		{
//			if(dacval>200)dacval-=200;
//			else dacval=0;
//		  DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ
//		}	 
//	 if(t==10||key==KEY1_PRES||key==WKUP_PRES) //WKUP/KEY1������,���߶�ʱʱ�䵽��
//		 if(t==10) 
//		{	  
//			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//��ȡǰ������DAC��ֵ
//			OLED_ShowChar(48,48,adcx,16,1);//��ʾASCII�ַ�	   
		  OLED_Refresh_Gram();   	//��ʾDAC�Ĵ���ֵ
		OLED_ShowString(0,0,"ZHUYU",24);  
//			temp=(float)adcx*(3.3/4096);			//�õ�DAC��ѹֵ
//			adcx=temp;
// 			  	//��ʾ��ѹֵ��������
// 			temp-=adcx;
//			temp*=1000;
//			//��ʾ��ѹֵ��С������
// 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//�õ�ADCת��ֵ	  
////			OLED_ShowChar(48,48,adcx,16,1);
//			temp=(float)adcx*(3.3/4096);			//�õ�ADC��ѹֵ
//			
//			adcx=temp;
// 			OLED_ShowNum(30,24,temp,1,16);    	//��ʾ��ѹֵ��������
//			OLED_ShowString(40,24,".",16); 
// 			temp-=adcx;
//			temp*=1000;
//			OLED_ShowNum(50,24,temp,3,16);  	//��ʾ��ѹֵ��С������
//			LED0=!LED0;	   
//			t=0;
//		}	    
//		delay_ms(10);	

	}
 }

