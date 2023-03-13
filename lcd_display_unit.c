//LCD DISPLAY UNIT
//#include<lpc21xx.h>
//#include"common_define.h"
//#include"common_delay.h"

//LCD PIN DEFINE
#define LCD_D 0xff<<7
#define rs 1<<5
#define e 1<<6

//LCD commend function............
void lcd_cmd(uc cmd)
{
	IOPIN0 = cmd<<7;
	IOCLR0 = rs;
	IOSET0 = e;
	delay_ms(2);
	IOCLR0 = e;	
}
//LCD data function..............
void lcd_data(uc d)
{
	IOPIN0 = d<<7;
	IOSET0 = rs;
	IOSET0 = e;
	delay_ms(2);
	IOCLR0 = e;	
}
//LCD initialization..............
void LCD_init(void)
{
	IODIR0 = LCD_D|rs|e;
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x80);	
}
//string data display.............
void lcd_string(uc *s)
{
	while(*s)
	{
		lcd_data(*s++);
	}
}
//LCD integer display................
void lcd_integer(si n)
{ 
	uc arr[10];
	int i=0;
	if(n==0)
	{
		lcd_data('0');
	}
	else if(n<0)
	{
		lcd_data('-');
		n = -n;
	}
	while(n!=0)
	{
		arr[i++] = n%10;
		n = n/10;
	}
	for(--i;i>=0;i--)
	{
		lcd_data(arr[i]+48);
	}
}
//LCD float display..............
void lcd_float(f val)
{
	int t = val;
	lcd_integer(t);
	lcd_data('.');
	if(val>0)
			t = (val-t)*1000000;
	else
			t = -(val-t)*1000000;

	lcd_integer(t);
}
//main function..........
/*
int main()
{
	f num = 123.4321;
	LCD_init();
//	lcd_string("Embedded");	
//	lcd_integer(num);
	lcd_float(num);
	num = num+2.32;
	lcd_cmd(0xc0);	
	lcd_float(num);
}
*/
