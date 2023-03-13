//SPI protocol for get the frequent temperature reading by using lm35  temperature sensor and mcp3204

#include<lpc21xx.h>
#include"common_define.h"
#include"common_delay.h"
#include"SPI_define.h"
#include"lcd_display_unit.c"

void SPI_init(void)
{
	//pin functionality selection
	PINSEL0 |= (SCK|MIOS|MOSI|SSEL);
	S0SPCCR = speed_range;
	S0SPCR = (1<<MSTR|mode3);
	SETBIT(IOPIN0,CS);
	SETBIT(IODIR0,CS);
	//IOPIN0 |= 1<<CS;
	//IODIR0 |= 1<<CS;
}

uc SPI0(uc data)
{
//	uc stat;
//	stat = S0SPSR;
//	S0SPSR = 0x00;
	S0SPDR = data;
	while(((S0SPSR>>SPIF)&1)==0);
	return S0SPDR;
}

float spi_sensor_read(uc channel)
{
	uc h_byte,l_byte;
	float adc_val = 0;
	CLRBIT(IOPIN0,CS);
//	IOPIN0 &= ~(1<<CS);
	SPI0(0X06);
	h_byte = SPI0(channel<<6);
	l_byte = SPI0(0x00);
	SETBIT(IOPIN0,CS);
//	IOPIN0 |= 1<<CS;
	adc_val=(((h_byte&0x0f)<<8)|l_byte);
	return (((adc_val*3.3)/4096));
}

int main()
{
	f T;
	uc chan = 0;
	SPI_init();
	LCD_init();
	
	while(1)
	{
		lcd_cmd(0XC0);
		lcd_string("Temp:");
		T = spi_sensor_read(chan);
		lcd_float(T);
		delay_sec(1);
	}
}
