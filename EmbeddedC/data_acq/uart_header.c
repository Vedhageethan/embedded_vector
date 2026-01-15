#include<reg51.h>
#include"lcd_header.c"
void uart_init(void);
void uart_tx(unsigned char);
//unsigned char uart_rx(void);	
void uart_init(void)//initialisation of UART baud
{
	//PCON=0x80;//doubling the baud rate
	SCON = 0x50;//mode 1 REN enable
	TMOD = 0x20;//timer 1 mode 2
	TH1 = TL1 = 253;//setting baud rate
	TR1 = 1;//start timer 1
}
void uart_tx(unsigned char d)//transmission of message
{
	SBUF = d;
	while(TI == 0);//polling
	TI = 0;
}
/*
unsigned char uart_rx(void)
{
	while(RI == 0);//polling RI FLag
	RI = 0;//clear RI Flag
	return SBUF;//stored
}
*/
void uart_str(unsigned char *d)//for string types
{
	while(*d)
	uart_tx(*d++);
}
void uart_int(int n)//for integer types
{
signed char arr[5],i=0;
	if(n==0)
		uart_tx('0');
	else
	{
   if(n<0)
	 {
		 uart_tx('-');
		 n=-n;
   }
	 while(n>0)
	 {
    arr[i++]=(n%10)+48;
		 n/=10;
   }
	 for(--i;i>=0;i--)
	 uart_tx(arr[i]);
  }
}
void uart_float(float f)//for float types
{
int i=f;
	uart_int(i);
	uart_tx('.');
	i=(f-i)*100;
	uart_int(i);
}