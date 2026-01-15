#include<reg51.h>
#include"delay_1ms.c"
#define LED P1
void main()
{
	int i;
	for(i=0;i<256;i++)
	{
		LED=(i)^0x0f;
		delay_1ms(500);
	}
}