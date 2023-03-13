#include <LPC21xx.h>
#include "spi.h"
#include "lcd.h"
#include "type.h"

main()
{
	f32 f;
	Init_SPI0(); //hw SPI initialisation
	lcd_init();	
  while(1)
  {
		lcd_cmd(0xC0);
		string("Temp:");
    f=Read_ADC_MCP3204(0);
		Float_display(f);
		delay_milliseconds(500);
	}
}	

