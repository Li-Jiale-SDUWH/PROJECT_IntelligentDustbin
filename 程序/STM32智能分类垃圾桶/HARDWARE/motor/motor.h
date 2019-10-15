#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
#include "delay.h"
//正反转
#define right 1
#define left 0
//电机1，驱动板上IN1-IN4分别接到开发板PF5-PF8
#define motor1_a PFout(5)
#define motor1_b PFout(6)
#define motor1_c PFout(7)
#define motor1_d PFout(8)
//电机2，驱动板上IN1-IN4分别接到开发板PF1-PF4
#define motor2_a PFout(1)
#define motor2_b PFout(2)
#define motor2_c PFout(3)
#define motor2_d PFout(4)
//电机3，驱动板上IN1-IN4分别接到开发板PA4-PA7
#define motor3_a PAout(4)
#define motor3_b PAout(5)
#define motor3_c PAout(6)
#define motor3_d PAout(7)
//电机4，驱动板上IN1-IN4分别接到开发板PC0-PC3
#define motor4_a PCout(0)
#define motor4_b PCout(1)
#define motor4_c PCout(2)
#define motor4_d PCout(3)


void motor_Init(void);//初始化
void motor1_drive(unsigned int speed,unsigned char direction);
void motor2_drive(unsigned int speed,unsigned char direction);
void motor3_drive(unsigned int speed,unsigned char direction);
void motor4_drive(unsigned int speed,unsigned char direction);
#endif
