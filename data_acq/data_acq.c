#include"i2c_header.c"
#include"spifun.h"
#include"uart_header.c"
void main()//main proogram
{
	unsigned char t,t1;
	uart_init();
	cgram_write();
	LCD_INIT();
	i2cdevwrite(0xd0,0x00,0x55);// DS1307 RTC (RTC addr,Reg. addr,add for hr,min,secs)
	i2cdevwrite(0xd0,0x01,0x59);
	i2cdevwrite(0xd0,0x02,0x23);
	LCD_CMD(0xc9);//TMP100 temperature sensor
	//LCD_DATA(0);
	LCD_DATA('V');//voltage indicator
while(1)
{
	float f;
	LCD_CMD(0x80);
  LCD_STR("TIME:");
	//**Hr**//
	t=i2cdevread(0xd0,0x02);
	t1=t;
	LCD_CMD(0x8d);
  if(t==0)
	{
		t=t+18;
		LCD_STR("am");//AM PM changing config code
  }
	else if(t>18)
	{
		t=t-18;
		LCD_STR("pm");
  }
	else
	{
		if(t==18)
			LCD_STR("pm");
			else
		LCD_STR("am");
	}
	LCD_CMD(0x85);
	LCD_DATA(t/16+48);
	LCD_DATA(t%16+48);
	LCD_DATA(':');
	uart_str("TIME:");
	uart_tx(t/16+48);//1st digit , ASCII
	uart_tx(t%16+48);//2nd digit , ASCII
	uart_tx(':');
	//**Minutes**//
	t=i2cdevread(0xd0,0x01);
	LCD_DATA(t/16+48);
	LCD_DATA(t%16+48);
	LCD_DATA(':');
	uart_tx(t/16+48);
	uart_tx(t%16+48);
	uart_tx(':');
	//**Seconds**//
	t=i2cdevread(0xd0,0x00);
	LCD_DATA(t/16+48);
	LCD_DATA(t%16+48);
	uart_tx(t/16+48);
	uart_tx(t%16+48);
	if(t1==0)
	 uart_str("am");
	else if(t1>18)
	 uart_str("pm");
	else
	{
		if(t1==18)
			uart_str("pm");
		else
		uart_str("am");
	}
	uart_str("\r\n");
	LCD_CMD(0xc0);
  LCD_STR("VOLT:");
	f=spi_adc(0,0);//ADC for voltage level
	LCD_FLOAT(f);
	uart_str("VOLT:");
	uart_float(f);
	uart_str("V");
	uart_str("\r\n");//to print in new line of hyperterminal
	delay_1ms(500);// delay for each cycle
	}
}