#include "headers.h"
#include "led.h"
#include "myiic.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "pid.h"
#include "motor.h"
#include "lcd.h"

void System_Initial(void)
{
	delay_init();
	uart_init(115200);
	IIC_Init();
	FDC2X14_Init();
	LED_Initial();
	PID_Initial();
	Motor_Initial();
	LCD_Init();
}

int main()
{
	System_Initial();
//	while(1)
//	{
//		printf("CH0=%d\r\n",FDC_GetCH(0));
//		printf("CH1=%d\r\n",FDC_GetCH(1));
//		printf("CH2=%d\r\n",FDC_GetCH(2));
//		printf("CH3=%d\r\n",FDC_GetCH(3));
//		printf("\r\n");
//		delay_ms(500);
//	}
	while(1) 
	{	   	
		POINT_COLOR=RED;	  
		LCD_ShowString(30,50,200,16,16,"WarShip STM32 ^_^");	
		LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");	
		LCD_ShowString(30,90,200,16,16,"I make it!");		  //��ʾLCD	      					 

		LED1=!LED1;			 
		delay_ms(1000);	
	}
}
