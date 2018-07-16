#ifndef _PID_H_
#define _PID_H_

#include "Headers.h"

extern void PID_Initial(void);

extern int Inc_PID_Cal(float Target,float Now);
extern int Loc_PID_Cal(float Target,float Now);

#endif
