#include<reg51.h>
#include"delay_1ms.c"
#define LCD P2
sbit RS = P1^0;
sbit RW = P1^1;
sbit E  = P1^2;
code cgram_lut[]={0x07,0x05,0x05,0x07,0x00,0x00,0x00,0x00};//Alphanumeric LCD 16 X 2
void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STR(unsigned char*);
void LCD_INT(int n);
void LCD_FLOAT(float);


void LCD_INIT(void)
{
	LCD_CMD(0x01);//CLEAR THE DISPLAY
	LCD_CMD(0x02);//RETURN TO HOME POSITION
	LCD_CMD(0x0c);//DISPLAY ON CURSOR OFF
	LCD_CMD(0x38);//8BIT INTERFACE MODE
	LCD_CMD(0x80);//SELECT DDRAM ADDRESS
}
void LCD_CMD(unsigned char c)
{
	LCD = c;//ASSIGNING COMMAND BYTES TO DATA PINS
	RS  = 0;//SELECTING COMMAND REGISTER
	RW  = 0;//WRITE TO LCD
	E   = 1;//LATCH THE DATA TO LCD
	delay_1ms(2);//INTERNAL OPERATIONS MODE
	E   = 0;//RE-LATCH THE DATA
}
void LCD_DATA(unsigned char d)
{
	LCD = d;//ASSIGNING DATA BYTES TO DATA PINS
	RS  = 1;//SELECTING DATA REGISTER
	RW  = 0;//WRITE TO LCD
	E   = 1;//LATCH THE DATA TO LCD
	delay_1ms(2);//INTERNAL OPERATIONS MODE
	E   = 0;//RE-LATCH THE DATA
}


void LCD_STR(unsigned char *s)
{
	while(*s)
	{
		LCD_DATA(*s++);
	}
}


void LCD_INT(int n)
{
	signed char arr[5],i=0;
	if(n==0)
		LCD_DATA('0');
	else
	{
		if(n<0)//condition for -ve number
		{
			LCD_DATA('-');//print -ve sign
			n=-n;//change -ve to +ve no.
		}
		while(n>0)
		{
			arr[i++] = (n%10)+48;//converting to eqiv. ascii
			n/=10;
		}
		for(--i;i>=0;i--)//init -> --i for dec the i which is previously incremented
			LCD_DATA(arr[i]);
	}
}

void LCD_FLOAT(float f_val)
{
	unsigned int n_val;
	n_val = f_val;//assigning the number before decimal
	LCD_INT(n_val);//before decimal value print
	LCD_DATA('.');//to display decimal dot
	n_val=(f_val-n_val)*100;//2-decimal digit
	LCD_INT(n_val);
}
void cgram_write(void)
{
unsigned char k;
LCD_CMD(0x40);
for(k=0;k<8;k++)
LCD_DATA(cgram_lut[k]);
}
