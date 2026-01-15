#include<reg51.h>
void main()
{
	TMOD = 0x03;//timer 0 mode 2
	//set timer to required delay
	TH0 = 0x00;//
	TL0 = 0x00;//
	
	TR0 = 1;//START TIMER 0
//	TR1 = 1;//START TIMER 1 since timer1 mode3 is disabled
	while(TF0 == 0);
	TR0 = 0;//STOP TIMER0
//	TR1 = 0;//STOP TIMER0
	TF0 = 0;//CLEAR FLAG
	while(1);
}