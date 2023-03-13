#include<lpc21xx.h>
#include"common_define.h"
#include"i2c_defines.h"

void start(void)
{
	I2CONSET = 1<<STA;
	while(((I2CONSET>>SI)&1)==0);
	I2CONCLR = 1<<STA;
}
void write(uc data)
{
	I2DAT = data;
	I2CONCLR = 1<<SI;
	while(((I2CONSET>>SI)&1)==0);
}
void restart(void)
{
	I2CONSET = 1<<STA;
	I2CONCLR = 1<<SI;
	while(((I2CONSET>>SI)&1)==0);
	I2CONCLR = 1<<STA;
}
void stop(void)
{
	I2CONSET = 1<<STO;
	I2CONCLR = 1<<STA;
}
uc nack(void)
{
	I2CONSET = 0x00;
	I2CONCLR = 1<<SI;
	while(((I2CONSET>>SI)&1)==0);
	return I2DAT;
}
uc master_ack(void)
{
	I2CONSET = 1<<AA;
	I2CONCLR = 1<<SI;
	while(((I2CONSET>>SI)&1)==0);
	I2CONCLR = 1<<AA;
	return I2DAT;
}
