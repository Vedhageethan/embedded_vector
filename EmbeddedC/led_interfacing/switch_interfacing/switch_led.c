#include<reg51.h>
sbit AL_LED = P1^0;
sbit AL_SW  = P1^1;
void main()
{
	while(1)
	{
		if(AL_SW==0)
			AL_LED = 0;
		else
			AL_LED = 1;
	}
}