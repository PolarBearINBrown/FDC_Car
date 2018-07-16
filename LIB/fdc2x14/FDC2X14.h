#ifndef __FDC2X14_H
#define __FDC2X14_H			 
#include "sys.h"	 								  

#if defined _FDC2X14_C
///FDC2X14 IO初始化
void FDC2X14_Init(void);
void SetFDC2X14(u8 Address,u8 MSB,u8 LSB);
//数据读取
//index通道索引
int FDC_GetCH(u8 index);
int ReadFDC2X14(u8 firstAddress,u8 secondAddress);
#else
///FDC2X14 IO初始化
extern void FDC2X14_Init(void);
extern void SetFDC2X14(u8 Address,u8 MSB,u8 LSB);
//数据读取
//index通道索引
extern int FDC_GetCH(u8 index);
extern int ReadFDC2X14(u8 firstAddress,u8 secondAddress);

#endif

#endif	   
















