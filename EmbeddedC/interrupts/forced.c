#include<reg51.h>
sbit LED0 = P1^0;
sbit LED1 = P1^1;
void ext_int0_ist(void) interrupt 0
{
	LED0 = 0;
	LED0 = 1;
}
void ext_int1_ist(void) interrupt 2
{
	LED1 = 0;
	LED1 = 1;
}
void main()
{
	unsigned int cnt = 0;
	EA = 1;//global interrupt enable
	EX0 = 1;//External interrupt 0 enable 
	IT0 = 1;//falling edge triggering
	EX1 = 1;//External interrupt 1 enable 
	IT1 = 1;//falling edge triggering
	PX0 = 1;
	while(1)
	{
		cnt++;
	}
}