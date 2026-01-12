#include<reg51.h>
#include"delay_1ms.c"
#define LED P0
void main()
{
	while(1)
	{
		LED = 0;//active low on
		delay_1ms(500);
		LED = 0xff;//off
		delay_1ms(500);
	}
}