#include "pid.h"

float LastError,PrevError,SumError;
float Proportion,Integral,Derivative;
float Limit;

void PID_Initial(void)
{
	LastError=0;
	PrevError=0;
	SumError=0;
	Proportion=170;
	Integral=0.4;
	Derivative=20;
	Limit=250.0;
}

int Inc_PID_Cal(float Target,float Now)
{
	float iError,ilncpid;
	
	iError=Target-Now;
	ilncpid=Proportion*iError-Integral*LastError+Derivative*PrevError;
	PrevError=LastError;
	LastError=iError;
	
	return ilncpid;
}

int Loc_PID_Cal(float Target,float Now)
{
  float iError,dError;
	
	iError=Target-Now;
	SumError+=iError;
	if(SumError>Limit)
	{
		SumError=Limit;
	}
	else if(SumError<-Limit)
	{
		SumError=-Limit;	
	}
	dError=iError-LastError;
	LastError=iError;
	
	return(Proportion*iError+Integral*SumError+Derivative*dError);
}
