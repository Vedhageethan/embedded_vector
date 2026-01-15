#include<reg51.h>
void main()
{
	TMOD = 0x01;//timer 0 mode 1
	/**set timer to required delay**/
	TH0 = 0x8D;//64536 higer bytes
	TL0 = 0xE0;//64536 lower bytes
	/********************************/
	TR0 = 1;//START TIMER 0
	while(TF0 == 0);
	TR0 = 0;//STOP TIMER0
	TF0 = 0;//CLEAR FLAG
}
/*****1ms******/
/*
void main()
{
	TMOD = 0x01;//timer 0 mode 1
	//set timer to required delay
	TH0 = 0xFC;//64536 higer bytes
	TL0 = 0x18;//64536 lower bytes
	
	TR0 = 1;//START TIMER 0
	while(TF0 == 0);
	TR0 = 0;//STOP TIMER0
	TF0 = 0;//CLEAR FLAG
}
*/