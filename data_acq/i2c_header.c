#include<reg51.h>
#include<intrins.h>
#include"delay_1ms.c"
sbit scl = P3^6;
sbit sda = P3^7;
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

void i2c_bytewrite(unsigned char d)
{
	unsigned char j;
	for(j=0;j<8;j++)//msb first
	{
		scl = 0;
		sda = d&(0x80>>j)?1:0;//writing bit by bit from MSB
		scl = 1;
	}
}

unsigned char i2c_byteread(void)
{
	unsigned char j,buf = 0;
	for(j=0;j<8;j++)//msb first
	{
		scl = 0;
		_nop_();//wait to slave response
		scl = 1;
		if(sda)
			buf |= (0x80>>j);//reading bit by bit from MSB
	}
	return buf;//storing that byte data to a character buffer
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
void i2cdevwrite(unsigned char sa,unsigned char r_addr, unsigned char dat)//write algorithm
{
	i2c_start();
	i2c_bytewrite(sa);
	i2c_ack();
	
	i2c_bytewrite(r_addr);
	i2c_ack();
	
	i2c_bytewrite(dat);
	i2c_ack();
	i2c_stop();
	delay_1ms(10);
}
unsigned char i2cdevread(unsigned char sa,unsigned char r_addr)//read algorithm
{
	unsigned char buff;
	//dummy write
	i2c_start();
	i2c_bytewrite(sa);
	i2c_ack();
	i2c_bytewrite(r_addr);
	i2c_ack();
	
	//read operation
	i2c_start();
	i2c_bytewrite(sa|1);
	i2c_ack();
	
	buff = i2c_byteread();
	i2c_noack();
	i2c_stop();
	return buff;
}