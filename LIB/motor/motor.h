#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "headers.h"

#define FullSpeed 1000
#define M1_Dir1 PDout(15)
#define M1_Dir2 PGout(2)
#define M2_Dir2 PGout(3)
#define M2_Dir1 PGout(4)
#define M3_Dir1 PGout(5)
#define M3_Dir2 PGout(6)
#define M4_Dir1 PGout(7)
#define M4_Dir2 PGout(8)

extern void Motor_Initial(void);
extern int min(int a,int b);

extern void Set_Right_Speed(int Speed,int Limit);
extern void Set_Left_Speed(int Speed,int Limit);

#endif
