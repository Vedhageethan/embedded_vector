#include"i2c_header.c"
#include"lcd_header.c"
void main()
{
	LCD_INIT();
	LCD_STR("I2C_EEPROM:");
		i2cdevwrite(0xa0,0x00,'A');
		LCD_DATA(i2cdevread(0xa0,0x00));
		while(1);
}