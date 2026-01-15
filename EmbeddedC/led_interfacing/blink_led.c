#include<reg51.h>
#include"delay_1ms.c"
sbit LED = P1^0;
void main()
{
	while(1)
	{
		LED = 0;//active low on
		delay_1ms(500);
		LED = 1;//off
		delay_1ms(500);
	}
}