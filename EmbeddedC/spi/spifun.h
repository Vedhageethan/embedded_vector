sbit _cs=P1^3;
sbit mosi=P1^4;
sbit miso=P1^5;
sbit clk=P1^6;
float spi_adc_read(bit d1,bit d2)
{
	unsigned int adc_val=0;char j;
	_cs=0;//cms
	clk=0;
	mosi=1;
	clk=1;
	
	clk=0;
	mosi=1;
	clk=1;
	
	clk=0;
	clk=1;
	
	clk=0;
	mosi=d1;
	clk=1;
	
	clk=0;
	mosi=d2;
	clk=1;
	
	clk=0;
	clk=1;
	
	clk=0;
	clk=1;
	
	for(j=11;j>=0;j--)
	{
		clk=0;
		if(miso)
			adc_val|=(1<<j);
		clk=1;
	}
	_cs=1;
	return ((adc_val*5.0)/4096);
}