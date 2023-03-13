//i2c protocol for EEPROM

#include<lpc21xx.h>
#include"common_define.h"
#include"i2c_defines.h"
#include"common_delay.h"
#include"i2c_comm_pro.c"
#include"lcd_display_unit.c"
#include<string.h>
void i2c_init(void)
{
	//SDA and SCL pin selection
	PINSEL0 |= SCL|SDA;
	//Set the speed as 100khz
	I2SCLL = loadval;
	I2SCLH = loadval;
	//enable the i2c communicaion 
	I2CONSET = 1<<I2EN;
}
//write rtc value..............................................
void i2c_rtc_write(uc wslave_addr,uc wreg_addr,uc data)
{
	start();
	write(wslave_addr<<1);
	write(wreg_addr);
	write(data);
	stop();
	delay_ms(10);
}
//read rtc value...............................................
uc i2c_rtc_read(uc rslave_addr,uc rreg_addr)
{
	uc ret;
	start();
	write(rslave_addr<<1);
	write(rreg_addr);
	restart();
	write((rslave_addr<<1)|1);
	ret = nack();
	stop();
	delay_ms(10);
	return ret;
}
//main function................................................
int main()
{
	ui t;
	uc hr=0;
	uc min=0;
	uc sec=0;
	i2c_init();
	LCD_init();
	i2c_rtc_write(RTC_addr,0X02,0x20);
	i2c_rtc_write(RTC_addr,0X01,0x12);
	i2c_rtc_write(RTC_addr,0X00,0x30);	
	while(1)
	{		
			lcd_cmd(0x01);
			lcd_cmd(0x02);
			lcd_cmd(0x80);
			lcd_string("Time:");
			hr = i2c_rtc_read(RTC_addr,0X02);
			lcd_data(hr/16+48);
			lcd_data(hr%16+48);
			lcd_data(':');
//			delay_ms(2);
			min = i2c_rtc_read(RTC_addr,0X01);
			lcd_data(min/16+48);
			lcd_data(min%16+48);
			lcd_data(':');
//			delay_ms(2);			
			sec = i2c_rtc_read(RTC_addr,0X00);
			lcd_data(sec/16+48);
			lcd_data(sec%16+48);

			delay_sec(1);			
	}
}

