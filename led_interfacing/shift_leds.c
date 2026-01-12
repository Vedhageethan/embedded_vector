#include<reg51.h>
#include"delay_1ms.c"
#define LED P1
void main()
{
	unsigned char pos = 0;
	while(pos<8)
	{
		LED = (1<<pos++)^0x0f;//right to left
		delay_1ms(500);
	}
	pos = 0;
	while(pos<8)
	{
		LED = (0x80>>pos++)^0x0f;//left to right
		delay_1ms(500);
	}
}