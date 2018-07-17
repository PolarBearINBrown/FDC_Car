#include "motor.h"

int min(int a,int b)
{
	return a>b? b:a;
}

void Dir_Initial(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOG,ENABLE);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOG, &GPIO_InitStructure);
}

void Timer_Initial(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);

	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler = psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_Cmd(TIM3, ENABLE);
}

void Motor_Initial(void)
{
	Dir_Initial();
	Timer_Initial(999,1439);
}

void Set_M1_Speed(int Speed)
{
	if(Speed>0)
	{
		M1_Dir1=1;
		M1_Dir2=0;
		TIM_SetCompare1(TIM3,min(FullSpeed,Speed));
	}
	else if(Speed==0)
	{
		M1_Dir1=1;
		M1_Dir2=1;
		TIM_SetCompare1(TIM3,FullSpeed);
	}
	else
	{
		M1_Dir1=0;
		M1_Dir2=1;
		TIM_SetCompare1(TIM3,min(FullSpeed,-Speed));
	}
}

void Set_Right_Speed(int Speed,int Limit)
{
	if(Speed>0)
	{
		M2_Dir1=0;
		M2_Dir2=1;
		TIM_SetCompare2(TIM3,min(Limit,Speed));
	}
	else if(Speed==0)
	{
		M2_Dir1=1;
		M2_Dir2=1;
		TIM_SetCompare2(TIM3,FullSpeed);
	}
	else
	{
		M2_Dir1=1;
		M2_Dir2=0;
		TIM_SetCompare2(TIM3,min(Limit,-Speed));
	}
}

void Set_M3_Speed(int Speed)
{
	if(Speed>0)
	{
		M3_Dir1=1;
		M3_Dir2=0;
		TIM_SetCompare3(TIM3,min(FullSpeed,Speed));
	}
	else if(Speed==0)
	{
		M3_Dir1=1;
		M3_Dir2=1;
		TIM_SetCompare3(TIM3,FullSpeed);
	}
	else
	{
		M3_Dir1=0;
		M3_Dir2=1;
		TIM_SetCompare3(TIM3,min(FullSpeed,-Speed));
	}
}

void Set_Left_Speed(int Speed,int Limit)
{
	if(Speed>0)
	{
		M4_Dir1=0;
		M4_Dir2=1;
		TIM_SetCompare4(TIM3,min(Limit,Speed));
	}
	else if(Speed==0)
	{
		M4_Dir1=1;
		M4_Dir2=1;
		TIM_SetCompare4(TIM3,FullSpeed);
	}
	else
	{
		M4_Dir1=1;
		M4_Dir2=0;
		TIM_SetCompare4(TIM3,min(Limit,-Speed));
	}
}
