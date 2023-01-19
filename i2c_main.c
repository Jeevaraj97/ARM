#include<lpc21xx.h>
#include "i2c_define.h"
#include "i2c_EEPROM.c"
#include "timer_delay.h"
//LED define
#define gLED 1<<17 
#define rLED 1<<18

void I2C_init(void);
void I2C_EEPROM_WRITE(uc,uc,uc);
uc I2C_EEPROM_READ(uc,uc);

int main()
{
	uc ch;
		I2C_init();
		I2C_EEPROM_WRITE(EEPROM_Addr,0x00,'A');
		ch = I2C_EEPROM_READ(EEPROM_Addr,0x00);

	if(ch=='A')
		IOPIN0 = gLED;
	else
		IOPIN0 = gLED;

while(1);	
}
void I2C_init(void)
{
	PINSEL0 = SCL_EN|SDA_EN;
	I2SCLL = LOADVAL;
	I2SCLH = LOADVAL;
	I2CONSET =  1<<I2EN_BIT;
}
//transmit the data
void I2C_EEPROM_WRITE(uc slaveAddr,uc wBuffAddr,uc data)
{
		i2c_start();
		i2c_write(slaveAddr<<1);
		i2c_write(wBuffAddr);
		i2c_write(data);
		i2c_stop();
		delay_ms(10);	
}
//receive the data
uc I2C_EEPROM_READ(uc slaveAddr,uc wBuffAddr)
{
	uc res;
		i2c_start();
		i2c_write(slaveAddr<<1);
		i2c_write(wBuffAddr);
		i2c_restart();
		i2c_write((slaveAddr<<1)|1);
		res = i2c_nack();
		i2c_stop();
		delay_ms(10);	
	return res;
}
