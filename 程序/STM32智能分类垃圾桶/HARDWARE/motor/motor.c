#include "motor.h" 

void motor_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOF, ENABLE);	 
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_1|GPIO_Pin_2;	
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOF, &GPIO_InitStructure);					 //根据设定参数初始化
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;	
 GPIO_Init(GPIOA, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_0;	
 GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
// GPIO_SetBits(GPIOE,GPIO_Pin_5); 		 // GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
}

void motor1_drive(unsigned int speed,unsigned char direction)
{
	if(direction == right)
	{
		motor1_a = 1;
		motor1_b = 0;
		motor1_c = 0;
		motor1_d = 0;
		delay_ms(speed);
		motor1_a = 0;
		motor1_b = 1;
		motor1_c = 0;
		motor1_d = 0;
		delay_ms(speed);
		motor1_a = 0;
		motor1_b = 0;
		motor1_c = 1;
		motor1_d = 0;
		delay_ms(speed);
		motor1_a = 0;
		motor1_b = 0;
		motor1_c = 0;
		motor1_d = 1;
		delay_ms(speed);
	}
	else if(direction == left)
	{
		motor1_a = 0;
		motor1_b = 0;
		motor1_c = 0;
		motor1_d = 1;
		delay_ms(speed);
		motor1_a = 0;
		motor1_b = 0;
		motor1_c = 1;
		motor1_d = 0;
		delay_ms(speed);
		motor1_a = 0;
		motor1_b = 1;
		motor1_c = 0;
		motor1_d = 0;
		delay_ms(speed);
		motor1_a = 1;
		motor1_b = 0;
		motor1_c = 0;
		motor1_d = 0;
		delay_ms(speed);
	}
}

void motor2_drive(unsigned int speed,unsigned char direction)
{
	if(direction == right)
	{
		motor2_a = 1;
		motor2_b = 0;
		motor2_c = 0;
		motor2_d = 0;
		delay_ms(speed);
		motor2_a = 0;
		motor2_b = 1;
		motor2_c = 0;
		motor2_d = 0;
		delay_ms(speed);
		motor2_a = 0;
		motor2_b = 0;
		motor2_c = 1;
		motor2_d = 0;
		delay_ms(speed);
		motor2_a = 0;
		motor2_b = 0;
		motor2_c = 0;
		motor2_d = 1;
		delay_ms(speed);
	}
	else if(direction == left)
	{
		motor2_a = 0;
		motor2_b = 0;
		motor2_c = 0;
		motor2_d = 1;
		delay_ms(speed);
		motor2_a = 0;
		motor2_b = 0;
		motor2_c = 1;
		motor2_d = 0;
		delay_ms(speed);
		motor2_a = 0;
		motor2_b = 1;
		motor2_c = 0;
		motor2_d = 0;
		delay_ms(speed);
		motor2_a = 1;
		motor2_b = 0;
		motor2_c = 0;
		motor2_d = 0;
		delay_ms(speed);
	}
}

void motor3_drive(unsigned int speed,unsigned char direction)
{
	if(direction == right)
	{
		motor3_a = 1;
		motor3_b = 0;
		motor3_c = 0;
		motor3_d = 0;
		delay_ms(speed);
		motor3_a = 0;
		motor3_b = 1;
		motor3_c = 0;
		motor3_d = 0;
		delay_ms(speed);
		motor3_a = 0;
		motor3_b = 0;
		motor3_c = 1;
		motor3_d = 0;
		delay_ms(speed);
		motor3_a = 0;
		motor3_b = 0;
		motor3_c = 0;
		motor3_d = 1;
		delay_ms(speed);
	}
	else if(direction == left)
	{
		motor3_a = 0;
		motor3_b = 0;
		motor3_c = 0;
		motor3_d = 1;
		delay_ms(speed);
		motor3_a = 0;
		motor3_b = 0;
		motor3_c = 1;
		motor3_d = 0;
		delay_ms(speed);
		motor3_a = 0;
		motor3_b = 1;
		motor3_c = 0;
		motor3_d = 0;
		delay_ms(speed);
		motor3_a = 1;
		motor3_b = 0;
		motor3_c = 0;
		motor3_d = 0;
		delay_ms(speed);
	}
}

void motor4_drive(unsigned int speed,unsigned char direction)
{
	if(direction == right)
	{
		motor4_a = 1;
		motor4_b = 0;
		motor4_c = 0;
		motor4_d = 0;
		delay_ms(speed);
		motor4_a = 0;
		motor4_b = 1;
		motor4_c = 0;
		motor4_d = 0;
		delay_ms(speed);
		motor4_a = 0;
		motor4_b = 0;
		motor4_c = 1;
		motor4_d = 0;
		delay_ms(speed);
		motor4_a = 0;
		motor4_b = 0;
		motor4_c = 0;
		motor4_d = 1;
		delay_ms(speed);
	}
	else if(direction == left)
	{
		motor4_a = 0;
		motor4_b = 0;
		motor4_c = 0;
		motor4_d = 1;
		delay_ms(speed);
		motor4_a = 0;
		motor4_b = 0;
		motor4_c = 1;
		motor4_d = 0;
		delay_ms(speed);
		motor4_a = 0;
		motor4_b = 1;
		motor4_c = 0;
		motor4_d = 0;
		delay_ms(speed);
		motor4_a = 1;
		motor4_b = 0;
		motor4_c = 0;
		motor4_d = 0;
		delay_ms(speed);
	}
}
