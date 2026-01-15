#include<reg51.h>
#include"lcd_header.c"
void main()
{
	//for displaying Integer both +ve and -ve
	while(1)
	{
		LCD_CMD(0x80);
		LCD_INT(-23);
		delay_1ms(1000);
		LCD_CMD(0x01);
		LCD_CMD(0x80);
		LCD_INT(0);
		delay_1ms(1000);
		LCD_CMD(0x01);
		LCD_CMD(0x80);
		LCD_INT(9512);
		delay_1ms(1000);
		LCD_CMD(0x01);//clear disp
	}
}	