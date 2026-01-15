void delay(void)
{
	unsigned char d;
	//for(d=0;d<=250;d++);
	//for(d=0;d<=247;d++);
	for(d=250;d>0;d--);
	for(d=247;d>0;d--);
}
void main()
{
	delay();
	while(1);
}