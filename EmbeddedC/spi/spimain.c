#include<reg51.h>
#include"lcd_header.c"
#include"spifun.h"
void main()
{
	LCD_INIT();
	LCD_STR("MCP-3204...");
	
	while(1)
	{
		LCD_CMD(0xc0);
		LCD_FLOAT(spi_adc_read(0,0));
		LCD_DATA('V');
		
	}
}