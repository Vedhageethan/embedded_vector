#include<reg51.h>
#include"delay_1ms.c"
#define LED P1
void main()
{
	while(1)
	{
		LED = 0x5A;//active low on
		delay_1ms(500);
		LED = 0xA5;//off
		delay_1ms(500);
	}
}