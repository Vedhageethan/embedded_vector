#include<reg51.h>
#include"delay_1ms.c"
#define seg_d P2
sbit seg1 = P1^0;
sbit seg2 = P1^1;
sbit seg3 = P1^2;
sbit seg4 = P1^3;
code unsigned char seg_lut[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x98};
void disp_int(int);
void main()
{
	while(1)
	{
		disp_int(1234);
	}
}
void disp_int(int n)
{
	seg_d = seg_lut[n/1000];
	seg1 = 0;
	delay_1ms(5);
	seg1 = 1;
	seg_d = seg_lut[(n/100)%10];  
	seg2 = 0;
	delay_1ms(5);
	seg2 = 1;
	seg_d = seg_lut[(n/10)%10];
	seg3 = 0;
	delay_1ms(5);
	seg3 = 1;
	seg_d = seg_lut[n%10];
	seg4 = 0;
	delay_1ms(5);
	seg4 = 1;
}