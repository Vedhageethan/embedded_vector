void delay_1ms(int dly)
{
	unsigned char d;
		for(;dly>0;dly--)
		{
			for(d=250;d>0;d--);
			for(d=247;d>0;d--);
		}
}