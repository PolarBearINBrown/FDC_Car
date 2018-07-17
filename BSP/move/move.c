#include "move.h"

#define LINE 200

void Move_Straight(void)
{
	Set_Left_Speed(LINE,LINE);
	Set_Right_Speed(LINE,LINE);
}

void Move_Right(int Speed)
{
	Set_Left_Speed(LINE,LINE);
	Set_Right_Speed(LINE-Speed,LINE);
}

void Move_Left(int Speed)
{
	Set_Right_Speed(LINE,LINE);
	Set_Left_Speed(LINE-Speed,LINE);
}

void Move_Back(void)
{
	Set_Left_Speed(-(LINE>>1),LINE>>1);
	Set_Right_Speed(-(LINE>>1),LINE>>1);
}

void Move_Stop(void)
{
	Set_Left_Speed(0,0);
	Set_Right_Speed(0,0);
}
