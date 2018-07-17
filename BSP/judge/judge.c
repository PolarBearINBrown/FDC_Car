#include "judge.h"

int ADJUST;

void Judge_Initial(void)
{
	ADJUST=FDC_GetCH(3)-FDC_GetCH(2);
}

int Judge_Dir(void)
{
	int L=FDC_GetCH(3);
	int R=FDC_GetCH(2);
	int A=R-L+ADJUST;
	ShowNum(1,7,L);
	ShowNum(2,7,R);
	ShowNum(3,7,A);
	return A;
}
