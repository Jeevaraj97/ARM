//define for i2c protocols

//I2CONSET register bits.....
#define AA 2
#define SI 3
#define STO 4
#define STA 5
#define I2EN 6

//pin selection.......
#define SCL 0x00000010
#define SDA 0x00000040

//speed calculation....
#define Fsoc 12000000
#define Cclk Fsoc*5
#define Pclk Cclk/4
#define speed 100000    //100 khzs
#define loadval ((Pclk/speed)/2)

//LED pin selection
//#define Gled 1<<0
//#define Rled 1<<1

//slave details.....
#define RTC_addr 0x68
