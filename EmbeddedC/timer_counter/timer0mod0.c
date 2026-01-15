#include<reg51.h>
void main()
{
	TMOD = 0x00;//timer 0 mode 0
	/**set timer to required delay**/
	TH0 = 0xE0;
	TL0 = 0x18;
	/********************************/
	TR0 = 1;//START TIMER 0
	while(TF0 == 0);
	TR0 = 0;//STOP TIMER0
	TF0 = 0;//CLEAR FLAG
}