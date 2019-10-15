#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "24cxx.h"
#include "w25qxx.h"
#include "touch.h"
#include "motor.h" 
 
#define region1_sx	0
#define region1_sy	0
#define region1_ex	239
#define region1_ey	69

#define region2_sx	0
#define region2_sy	70
#define region2_ex	239
#define region2_ey	139

#define region3_sx	0
#define region3_sy	140
#define region3_ex	239
#define region3_ey	209

#define region4_sx	0
#define region4_sy	210
#define region4_ex	239
#define region4_ey	279

#define region_open_sx	0
#define region_open_sy	280
#define region_open_ex	119
#define region_open_ey	319

#define region_close_sx	121
#define region_close_sy	280
#define region_close_ex	239
#define region_close_ey	319

extern u16 char_BACK_COLOR;

void init_region1()
{
	POINT_COLOR=BLACK;
	char_BACK_COLOR = WHITE;
	LCD_Fill(0,0,239,69,GRAY);	//��������
	LCD_ShowString(5,5,100,16,16,"Disposables");
	LCD_ShowString(100,5,90,16,16,"Cigarette");
	LCD_ShowString(180,5,50,16,16,"Ceramic");
	
	LCD_ShowString(5,38,130,16,16,"Polluted paper");
	LCD_ShowString(125,38,80,16,16,"Dust");
	LCD_ShowString(165,38,70,16,16,"Pet Dung");
	
}
void init_region2()
{
	POINT_COLOR=BLACK;
	char_BACK_COLOR = WHITE;
	LCD_Fill(0,70,239,139,GRAY);	//�ɻ�������
	
	LCD_ShowString(20,73,40,16,16,"Glass");
	LCD_ShowString(75,73,100,16,16,"Milk Carton");
	LCD_ShowString(180,73,40,16,16,"Metal");
	
	LCD_ShowString(15,106,50,16,16,"Plastic");
	LCD_ShowString(80,106,100,16,16,"Wasted Paper");
	LCD_ShowString(185,106,40,16,16,"Cloth");

}
void init_region3()
{
	POINT_COLOR=BLACK;
	char_BACK_COLOR = WHITE;
	LCD_Fill(0,140,239,209,GRAY);	//��������
	LCD_ShowString(10,143,80,16,16,"Bone&Organ");
	LCD_ShowString(95,143,60,16,16,"Pericarp");
	LCD_ShowString(165,143,60,16,16,"Leftover");

	LCD_ShowString(10,176,90,16,16,"Tea Leaves");
	LCD_ShowString(100,176,130,16,16,"Vegetable Leaves");
}
void init_region4()
{
	POINT_COLOR=BLACK;
	char_BACK_COLOR = WHITE;
	LCD_Fill(0,210,239,279,GRAY);	//�к�����
	LCD_ShowString(15,210,70,16,16,"Ink Box");
	LCD_ShowString(110,210,110,16,16,"Out-dated Drug");
	
	LCD_ShowString(15,235,90,16,16,"Light Tube");
	LCD_ShowString(110,235,90,16,16,"Paint Bucket");
	
	LCD_ShowString(15,260,90,16,16,"Pesticide");
	LCD_ShowString(110,260,70,16,16,"Used Battery");
	
}

void clear_flag(u8 last_option)
{
	switch(last_option)
	{
		case 1:init_region1();break;
		case 2:init_region2();break;
		case 3:init_region3();break;
		case 4:init_region4();break;
		default:break;
	}
}
//������������
void SYS_handle(void)
{

	u8 last_option;  
	u8 motor_count;  
	while(1)
	{

		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<region1_ex && tp_dev.y[0]<region1_ey)
			{	
				clear_flag(last_option);
				last_option = 1;
				LCD_Fill(region1_ex-10,region1_ey-10,region1_ex,region1_ey,BLACK);	   
			}
			
			else if(tp_dev.x[0]<region2_ex && tp_dev.y[0]<region2_ey && tp_dev.y[0]>region2_sy && tp_dev.x[0]>region2_sx)
			{	
				clear_flag(last_option);
				last_option = 2;
				LCD_Fill(region2_ex-10,region2_ey-10,region2_ex,region2_ey,GBLUE);	   
			}
			
			else if(tp_dev.x[0]<region3_ex && tp_dev.y[0]<region3_ey && tp_dev.y[0]>region3_sy && tp_dev.x[0]>region3_sx)
			{	
				clear_flag(last_option);
				last_option = 3;
				LCD_Fill(region3_ex-10,region3_ey-10,region3_ex,region3_ey,GREEN);	   
			}
			
			else if(tp_dev.x[0]<region4_ex && tp_dev.y[0]<region4_ey && tp_dev.y[0]>region4_sy && tp_dev.x[0]>region4_sx)
			{	
				clear_flag(last_option);
				last_option = 4;
				LCD_Fill(region4_ex-10,region4_ey-10,region4_ex,region4_ey,BRRED);	   
			}
			//open
			else if(tp_dev.x[0]<region_open_ex && tp_dev.y[0]<region_open_ey && tp_dev.y[0]>region_open_sy && tp_dev.x[0]>region_open_sx)
			{
				while(motor_count<150)
				{
					switch(last_option)
					{
						case 1:motor1_drive(3,right);;break;
						case 2:motor2_drive(3,right);;break;
						case 3:motor3_drive(3,right);;break;
						case 4:motor4_drive(3,right);;break;
						default:break;
					}
					motor_count++;
				}
				motor_count = 0;
			}
			//close
			else if(tp_dev.x[0]<region_close_ex && tp_dev.y[0]<region_close_ey && tp_dev.y[0]>region_close_sy && tp_dev.x[0]>region_close_sx)
			{
				while(motor_count<150)
				{
					switch(last_option)
					{
						case 1:motor1_drive(3,left);;break;
						case 2:motor2_drive(3,left);;break;
						case 3:motor3_drive(3,left);;break;
						case 4:motor4_drive(3,left);;break;
						default:break;
					}
					motor_count++;
				}
				motor_count = 0;
			}
		}
	}
}


int main(void)
{	 		    
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	motor_Init();
	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();	
	KEY_Init();	 	
	tp_dev.init();
	
	POINT_COLOR=BLACK;//��������Ϊ��ɫ 
	
	init_region1();
	init_region2();
	init_region3();
	init_region4();

	char_BACK_COLOR = WHITE;
	POINT_COLOR=BRED;
	LCD_Fill(0,280,239,319,WHITE);	
	LCD_ShowString((130-16*4)/2,288,120,24,24,"OPEN");
	LCD_ShowString(130+(120-16*5)/2,288,120,24,24,"CLOSE");
	
	POINT_COLOR=BRRED;
	LCD_DrawLine(119, 280, 120, 319);
	LCD_DrawLine(120, 280, 120, 319);
	LCD_DrawLine(121, 280, 120, 319);
//	while(1)
//	{//	�������
//		if(KEY_Scan(1) == KEY0_PRES)	//��סKEY0���ţ������ת
//		{
//			motor4_drive(5,right);
//		}
//		if(KEY_Scan(1) == KEY1_PRES)	//��סKEY1���ţ������ת
//		{
//			motor4_drive(5,left);
//		}
//		if(KEY_Scan(1) == WKUP_PRES)	//����KEY_UP���˳��������
//		{
//			break;
//		}
//	}
	SYS_handle(); 
}

