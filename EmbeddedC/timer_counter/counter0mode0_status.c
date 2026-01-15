#include<reg51.h>
sbit led = P2^0;
void main()
{
	int cnt = 0;
	TMOD = 0x04;//counter 0 mode 0 selected
	TR0 = 1;//strt counter 0
	while(cnt < 36)
	{
		cnt = (TH0*32)+TL0;
	}
	led = 0;//turn on AL led
	TR0 = 0;//stop counter
	while(1);
}