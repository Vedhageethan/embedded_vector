#include<reg51.h>
#include"lcd_header.c"
void main()
{

//for displaying float numbers

	while(1)
		{
			LCD_CMD(0x80);
			LCD_FLOAT(77.60);
			delay_1ms(1000);
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_FLOAT(90.66);
			delay_1ms(1000);
			LCD_CMD(0x01);
			LCD_CMD(0x80);
			LCD_FLOAT(94.4);
			delay_1ms(1000);
			LCD_CMD(0x01);//clear disp
		}
	}