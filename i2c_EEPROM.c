#include<lpc21xx.h>

void i2c_start(void)
{
	I2CONSET = 1<<STA_BIT;
	I2CONCLR = 1<<STO_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	I2CONCLR = 1<<STA_BIT;
}
void i2c_write(uc dat)
{
	I2DAT = dat;
	I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
}
void i2c_stop(void)
{
	I2CONSET = 1<<STO_BIT;
	I2CONCLR = 1<<STA_BIT;
}
void i2c_restart(void)
{
	I2CONSET = 1<<STA_BIT;
	I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	I2CONCLR = 1<<STA_BIT;
}

uc i2c_nack(void)
{
	I2CONSET = 0X00;
//	I2CONCLR = 1<<SI_BIT;
	while(((I2CONSET>>SI_BIT)&1)==0);
	return I2DAT;
}
