#include "headers.h"
#include "led.h"
#include "myiic.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "pid.h"
#include "lcd.h"
#include "judge.h"
#include "move.h"

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
	Judge_Initial();
}

int main()
{
	System_Initial();
	ShowString(1,1,"Left=");
	ShowString(2,1,"Right=");
	ShowString(3,1,"Div=");
	ShowString(4,1,"PID=");
	while(1)
	{
		int P=Loc_PID_Cal(0,Judge_Dir()/2000)*0.4;
		ShowNum(4,7,P);
		if(P<0)
		{
			Move_Left(-P);
		}
		else
		{
			Move_Right(P);
		}
	}
}
