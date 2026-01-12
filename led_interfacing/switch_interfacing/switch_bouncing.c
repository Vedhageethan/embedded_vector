#include<reg51.h>
#include"delay_1ms.c"
#define LED P1
sbit SW = P2^0;
void main()
{
	unsigned char pos = 0;
	while(pos<8)
	{
		if(SW==0)
		{
			delay_1ms(200);
			LED = (1<<pos++)^0x0f;
		}
	}
	pos = 0;
	while(pos<8)
	{
		if(SW==0)
		{
			delay_1ms(200);
			LED = (0x80>>pos++)^0x0f;
			while(SW==0);
		}
	}
}