//5 external events using counter 0 mode 0 
#include<reg51.h>
sbit led = P2^0;
void main()
{
	TMOD = 0x04;//counter 0 mode 0 selected
	TR0 = 1;//strt counter 0
	while(TL0 < 5);
	led = 0;//turn on AL led
	led = 1;//turn off AL led
	TR0 = 0;//stop counter
	while(1);
}