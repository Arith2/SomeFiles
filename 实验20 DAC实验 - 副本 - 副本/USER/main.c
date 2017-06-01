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
 ALIENTEK战舰STM32开发板实验20
 DAC 实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


 int main(void)
 {	 
	u16 adcx;
	float temp;
 	u8 t=0;	 
	u16 dacval=0;
	u8 key;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	KEY_Init();			  //初始化按键程序
 	LED_Init();			     //LED端口初始化
	
 	Adc_Init();		  		//ADC初始化
	Dac1_Init();				//DAC初始化

	OLED_Init();			//初始化OLED      
  OLED_ShowString(0,0,"ZHUYU",24);  
//	OLED_ShowString(0,24, "0.96' DAC TEST",16);  
// 	OLED_ShowString(0,40,"ATOM 2017/5/19",12);  
// 	OLED_ShowString(0,52,"ASCII:",12);  
// 	OLED_ShowString(64,52,"CODE:",12);  
  
	OLED_Refresh_Gram();		//更新显示到OLED 
	
	 DAC_SetChannel1Data(DAC_Align_12b_R, 0);//初始值为0	    	      
	while(1)
	{
		
//		Dac1_Set_Vol(2000);
//		t++;
//		key=KEY_Scan(0);			  
//		if(key==WKUP_PRES)
//		{		 
//			if(dacval<4000)dacval+=200;
//		 DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值	
//		}else if(key==KEY1_PRES)	
//		{
//			if(dacval>200)dacval-=200;
//			else dacval=0;
//		  DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值
//		}	 
//	 if(t==10||key==KEY1_PRES||key==WKUP_PRES) //WKUP/KEY1按下了,或者定时时间到了
//		 if(t==10) 
//		{	  
//			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//读取前面设置DAC的值
//			OLED_ShowChar(48,48,adcx,16,1);//显示ASCII字符	   
		  OLED_Refresh_Gram();   	//显示DAC寄存器值
		OLED_ShowString(0,0,"ZHUYU",24);  
//			temp=(float)adcx*(3.3/4096);			//得到DAC电压值
//			adcx=temp;
// 			  	//显示电压值整数部分
// 			temp-=adcx;
//			temp*=1000;
//			//显示电压值的小数部分
// 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//得到ADC转换值	  
////			OLED_ShowChar(48,48,adcx,16,1);
//			temp=(float)adcx*(3.3/4096);			//得到ADC电压值
//			
//			adcx=temp;
// 			OLED_ShowNum(30,24,temp,1,16);    	//显示电压值整数部分
//			OLED_ShowString(40,24,".",16); 
// 			temp-=adcx;
//			temp*=1000;
//			OLED_ShowNum(50,24,temp,3,16);  	//显示电压值的小数部分
//			LED0=!LED0;	   
//			t=0;
//		}	    
//		delay_ms(10);	

	}
 }

