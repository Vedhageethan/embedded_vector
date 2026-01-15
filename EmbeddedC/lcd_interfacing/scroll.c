//scroll the string from left to right
#include<reg51.h>
#include"lcd_header.c"
void main()
{
	unsigned char cmd;
	LCD_INIT();
	for(cmd=0x80;cmd<=0x8f;cmd++)
	{
		LCD_CMD(cmd);
		LCD_STR("VEDHA");
		delay_1ms(500);
		LCD_CMD(0x01);
	}
}