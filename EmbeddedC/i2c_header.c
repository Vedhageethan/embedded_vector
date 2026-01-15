#include<reg51.h>
#include<intrins.h>
#define lcd_d P1
sbit rs = P2^0;
sbit rw = P2^1;
sbit e = P2^2;
sbit scl = P3^6;
sbit sda = P3^7;
void delay(int dly)
{
	unsigned char d;
	for(;dly>0;dly--)
	{
		for(d=250;d>0;d--);
		for(d=247;d>0;d--);
	}
}
void lcd_cmd(unsigned char c)
{
	lcd_d = c;
	rs = 0;
	rw = 0;
	e = 1;
	delay(2);
	e = 0;
}
void lcd_data(unsigned char d)
{
	lcd_d = d;
	rs = 1;
	rw = 0;
	e = 1;
	delay(2);
	e = 0;
}
void lcd_init(void)
{
	lcd_cmd(0X01);
	lcd_cmd(0X02);
	lcd_cmd(0X0C);
	lcd_cmd(0X38);
	lcd_cmd(0X80);
}
void lcd_str(unsigned char *s)
{
	while(*s)
		lcd_data(*s++);
}
void i2c_start(void)
{
	scl = 1;
	sda = 1;
	sda = 0;
}
void i2c_stop(void)
{
	sda = 0;
	scl = 1;
	sda = 1;	
}
void i2c_bytewrite(unsigned char w)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		scl = 0;
		sda = w&(0X80>>i);
		scl = 1;
	}
}
unsigned char i2c_byteread(void)
{
	unsigned char i,buf = 0;
	for(i=0;i<8;i++)
	{
		scl = 0;
		_nop_(); //1 machine cycle
		scl = 1;
		if(sda)
			buf|=(0X80>>i);
	}
	return buf;
}
void i2c_ack(void)
{
	scl = 0;
	sda = 1;
	scl = 1;
	while(sda == 1);
	scl = 0;
}
void i2c_noack(void)
{
	scl = 0;
	sda = 1;
	scl = 1;
	scl = 0;
}
void write(unsigned char sa,unsigned char ra,unsigned char dbyte)
{
	i2c_start();
	i2c_bytewrite(sa);
	i2c_ack();
	i2c_bytewrite(ra);
	i2c_ack();
	i2c_bytewrite(dbyte);
	i2c_ack();
	i2c_stop();
}
unsigned char read(unsigned char sa,unsigned char ra)
{
	unsigned char buf;
	i2c_start();
	i2c_bytewrite(sa);
	i2c_ack();
	i2c_bytewrite(ra);
	i2c_ack(); //dummy
	i2c_start();
	i2c_bytewrite(sa|1);
	i2c_ack();
	buf = i2c_byteread();
	i2c_noack();
	i2c_stop();
	return buf;
}