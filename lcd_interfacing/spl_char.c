#include<reg51.h>
#include"lcd_header.c"
code unsigned char cgram[]=
							{
								0x04,0x06,0x04,0x04,0x0c,0x1c,0x0c,0x00,//tone
								0x04,0x0a,0x0a,0x0a,0x1b,0x1b,0x1b,0x00 //headphone
							};
void cgram_write(void);
void cgram_write(void)
{
	unsigned char k;
	LCD_CMD(0x40);
	for(k=0;k<16;k++)
		LCD_DATA(cgram[k]);
}

void main()
{
	unsigned char rod,rod1;
	LCD_INIT();
	for(rod=0x80,rod1=0x87;rod<=0x8f;rod++,rod1++)
	{
		LCD_CMD(rod);
		LCD_STR("MusiX:");
		cgram_write();
		LCD_CMD(rod1);
		LCD_DATA(0);
		LCD_DATA(1);
		delay_1ms(500);
		LCD_CMD(0x01);
	}
	//while(1);
}
