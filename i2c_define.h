
typedef unsigned char uc;
typedef signed char sc;
typedef unsigned int ui;
typedef signed int si;
typedef float f;

//SDA and SCL pin selection
#define SCL_EN 0X00000010   // p0.2 -->SCL
#define SDA_EN 0X00000040		// P0.3 -->SDA

//CONSET register bit define
#define AA_BIT 2
#define SI_BIT 3
#define STO_BIT 4
#define STA_BIT 5
#define I2EN_BIT 6

//I2C speed config
#define Cclk 60000000		//60 mhz
#define Pclk Cclk/4			//15 mhz
#define I2C_speed 100000   //100 kbps
#define LOADVAL ((Pclk/I2C_speed)/2)

//EEPROM details
#define EEPROM_Addr 0x05



