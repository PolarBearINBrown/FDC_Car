#include "pretreat.h"

int Threshold=888;
int CHvalue[4];
int CHbit[4];

#define Length 20
int Queue[Length];

void Get_CH(void)
{
	for(int i=0;i<4;i++)
	{
		CHvalue[i]=FDC_GetCH(i);
		CHbit[i]=(CHvalue[i]>Threshold);
	}
}

int Get_Status(void)
{
	int k=1;
	int Ans=0;
	Get_CH();
	for(int i=0;i<4;i++)
	{
		Ans+=CHbit[i]*k;
		k<<=1;
	}
	return Ans;
}

void Status_In_Queue(int Delay)
{
	int Tmp=Get_Status();
	if(Tmp!=Queue[0])
	{
		for(int i=Length;i>0;i--)
		{
			Queue[i]=Queue[i-1];
		}
		Queue[0]=Tmp;
	}
}
