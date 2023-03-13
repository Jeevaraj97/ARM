//SPI - protocol defines

#define CS 7

//pin selection for spi protocol
#define SCK 0X00000100
#define MIOS 0X00000400
#define MOSI 0X00001000
#define SSEL 0X00004000


//SPEED calculation...........
#define Fosc 12000000
#define Cclk Fosc*5
#define Pclk Cclk/4
#define SPI_SPCCR 60
#define speed_range (uc)(Pclk/SPI_SPCCR)

//SPI registers bits define....
//S0SPCR register.....
#define EN_bit 2
#define CPHA 3
#define CPOL 4
#define MSTR 5
#define LSBF 6
#define SPIE 7

//S0SPSR register.....
#define SPIF 7

#define SETBIT(WORD,POSITION)	(WORD|=(1<<POSITION))
#define CLRBIT(WORD,POSITION)	(WORD&=~(1<<POSITION))
#define READBIT(WORD,POSITION) ((WORD>>POSITION)&1)

#define mode1 0x00 
#define mode3 0x18



