#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "headers.h"

#define FullSpeed 1000
#define M1_Dir1 PDout(15)
#define M1_Dir2 PGout(2)
#define M2_Dir1 PGout(3)
#define M2_Dir2 PGout(4)
#define M3_Dir1 PGout(5)
#define M3_Dir2 PGout(6)
#define M4_Dir1 PGout(7)
#define M4_Dir2 PGout(8)

extern void Motor_Initial(void);

extern void Set_M1_speed(int speed);
extern void Set_M2_speed(int speed);
extern void Set_M3_speed(int speed);
extern void Set_M4_speed(int speed);

#endif
