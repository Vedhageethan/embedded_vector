void delay_1ms(int dly)//to create 1ms delay this runs based on machine cycle.
{
	unsigned char d;
		for(;dly>0;dly--)//used to increase the machine cycles of compilation.
		{
			for(d=250;d>0;d--);
			for(d=247;d>0;d--);
		}
}