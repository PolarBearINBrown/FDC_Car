#include "headers.h"
#include "led.h"
#include "myiic.h"
#include "FDC2X14.h"
#include "pretreat.h"
#include "pid.h"
#include "motor.h"

void System_Initial(void)
{
	delay_init();
	uart_init(115200);
	IIC_Init();
	FDC2X14_Init();
	LED_Initial();
	PID_Initial();
	Motor_Initial();
}

int main()
{
	System_Initial();
	while(1)
	{
		printf("CH0=%d\r\n",FDC_GetCH(0));
		printf("CH1=%d\r\n",FDC_GetCH(1));
		printf("\r\n");
		delay_ms(500);
	}
}
