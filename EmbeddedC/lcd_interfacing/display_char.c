#include<reg51.h>
#include"lcd_header.c"
void main()
{
	while(1)
	{
		LCD_DATA('V');
		LCD_DATA('E');
		LCD_DATA('D');
	}
}



