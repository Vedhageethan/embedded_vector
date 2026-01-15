#include"i2c_header.c"
#include"lcd_header.c"
void main()
{
	unsigned char t;
	LCD_INIT();
	LCD_CMD(0x80);
	LCD_STR("TIME:");
	//LCD_STR("TIME-  :  :  ");
	i2cdevwrite(0xd0,0x00,0x00);
	i2cdevwrite(0xd0,0x01,0x59);
	i2cdevwrite(0xd0,0x02,0x12);
	while(1)
	{
		LCD_CMD(0x80);
		LCD_STR("TIME:");
		t=i2cdevread(0xd0,0x02);
		LCD_DATA(t/16+48);
		LCD_DATA(t%16+48);
		LCD_DATA(':');
		t=i2cdevread(0xd0,0x01);
		LCD_DATA(t/16+48);
		LCD_DATA(t%16+48);
		LCD_DATA(':');
		t=i2cdevread(0xd0,0x00);
		LCD_DATA(t/16+48);
		LCD_DATA(t%16+48);
		LCD_CMD(0xc0);
		LCD_STR("VED & DILLI");
	}
}