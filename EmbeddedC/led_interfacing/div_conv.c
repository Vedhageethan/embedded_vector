#include<reg51.h>
#include"delay_1ms.c"
#define LED P1

void main()
{
/*
{
	int i,a[8]={0x8E,0x4D,0x2B,0x17,0x17,0x2B,0x4D,0x8E};
	while(1)
	{
		for(i=0;i<8;i++)
		{
			LED = a[i];
			delay_1ms(100);
		}
	}
}
*/
///*{
	int i=0,j=7;
	for(;i<=7;i++,j--)
	{
		LED = ((1<<i)^0x0f)^(1<<j);
		delay_1ms(500);
	}
}
//*/