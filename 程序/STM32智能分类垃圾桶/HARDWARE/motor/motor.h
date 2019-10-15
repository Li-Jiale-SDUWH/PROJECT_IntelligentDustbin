#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
#include "delay.h"
//����ת
#define right 1
#define left 0
//���1����������IN1-IN4�ֱ�ӵ�������PF5-PF8
#define motor1_a PFout(5)
#define motor1_b PFout(6)
#define motor1_c PFout(7)
#define motor1_d PFout(8)
//���2����������IN1-IN4�ֱ�ӵ�������PF1-PF4
#define motor2_a PFout(1)
#define motor2_b PFout(2)
#define motor2_c PFout(3)
#define motor2_d PFout(4)
//���3����������IN1-IN4�ֱ�ӵ�������PA4-PA7
#define motor3_a PAout(4)
#define motor3_b PAout(5)
#define motor3_c PAout(6)
#define motor3_d PAout(7)
//���4����������IN1-IN4�ֱ�ӵ�������PC0-PC3
#define motor4_a PCout(0)
#define motor4_b PCout(1)
#define motor4_c PCout(2)
#define motor4_d PCout(3)


void motor_Init(void);//��ʼ��
void motor1_drive(unsigned int speed,unsigned char direction);
void motor2_drive(unsigned int speed,unsigned char direction);
void motor3_drive(unsigned int speed,unsigned char direction);
void motor4_drive(unsigned int speed,unsigned char direction);
#endif
