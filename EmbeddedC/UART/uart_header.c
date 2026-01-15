#include<reg51.h>
#include"lcd_header.c"
void uart_init(void);
void uart_tx(unsigned char);
unsigned char uart_rx(void);
void main()
{
	unsigned int i = 0;
	unsigned char rx_data;
	LCD_INIT();
	uart_init();
	
	while(1)
	{
		rx_data = uart_rx();
			if(i==16)//LCD Transmit with two lines
			{
				LCD_CMD(0xc0);
			}
			if(i==32)//2nd row
			{
				LCD_INIT();
				i=0;
			}
		i++;
		LCD_DATA(rx_data);
		uart_tx(rx_data);
	}
}	
void uart_init(void)
{
	//PCON=0x80;//doubling the baud rate
	SCON = 0x50;//mode 1 REN enable
	TMOD = 0x20;/timer 1 mode 2
	TH1 = TL1 = 253;//setting baud rate
	TR1 = 1;//start timer 1
}
void uart_tx(unsigned char d)
{
	SBUF = d;
	while(TI == 0);//polling
	TI = 0;
}
unsigned char uart_rx(void)
{
	while(RI == 0);//polling RI FLag
	RI = 0;//clear RI Flag
	return SBUF;//stored
}