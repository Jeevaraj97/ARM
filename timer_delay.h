//delay for seconds

void delay_sec(uc sec)
{
	T0PR  = 15000000-1;
	T0TCR = 0X01;
	while(T0TC < sec);
	T0TCR = 0X03;
	T0TCR = 0X00;	
}
//delay for milliseconds
void delay_ms(uc ms)
{
	T0PR  = 15000-1;
	T0TCR = 0X01;
	while(T0TC < ms);
	T0TCR = 0X03;
	T0TCR = 0X00;	
}

//delay for microseconds
void delay_micsec(uc micsec)
{
	T0PR  = 15-1;
	T0TCR = 0X01;
	while(T0TC < micsec);
	T0TCR = 0X03;
	T0TCR = 0X00;	
}
