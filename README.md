# MSP430G2 SSD1306 OLED Display Library
This is a simple library for interfacing a MSP430G2 LaunchPad with a 128x64 SSD1306 OLED display using I2C. Much of the code for the display has been borrowed from Adafuit's wonderful SSD1306 Arduino library with modifications so that it will work with the limited RAM available on the MSP430G2553.

The example code uses 24 bytes of RAM and 2832 bytes of Flash. The MSP430G2553 has 512 bytes of RAM and 16384 bytes of Flash.

![Simple Example of Library Features](docs/sample.gif)


## Getting Started
### Prerequisites
To use this library you will need the following:
- MSP-EXP430G2 TI LaunchPad or MSP430G2553 uC
- PlatformIO or Code Composer Studio
- SSD1306 OLED with I2C
- 2x 10k or other value pullup resistors
- Wires for connecting display to LaunchPad
- Breadboard

### Installing
This repository contains [PlatformIO](https://platformio.org/) example code. If you are unfamiliar with PlatformIO it can be installed as an extension in [Visual Studio Code](https://code.visualstudio.com/). This repository can then be opened using the extension and will automatically be recognized. Edit `platformio.ini` for different [MSP430 boards or supported microcontrollers](https://docs.platformio.org/en/latest/platforms/timsp430.html). The example program is [/src/main.cpp](/src/main.cpp). The SSD1306 and I2C library are in [/lib](/lib/).

It should also be possible to use this library with [Code Composer Studio](https://www.ti.com/tool/CCSTUDIO) but I am unable to get it to install and launch on my Linux computers so I have abandoned developing MSP430 code using CCStudio.

You can also find the SSD1306 and I2C library source files in [releases](https://github.com/sdp8483/MSP430G2_SSD1306_OLED/releases) along with release notes.

### Hookup
- Connect Vcc on the display to 3.3v on the LaunchPad.  
- Connect Gnd on the display to gnd on the LaunchPad.  
- Use pullup resistors to connect the SLC and SDA pins to 3.3v.  
- Connect SLC on the display to P1.6 on the LaunchPad.  
- Connect SDA on the display to P1.7 on the LaunchPad.  

![Simple Schematic](docs/pcb/images/hookup_example.png)

## Usage
The following commands are used:
 
`i2c_init(void)`  
Initialize I2C on P1.6 and P1.7 

`ssd1306_init(void)`  
Initialize SSD1306 display, this sends all the setup commands to configure the display.

`ssd1306_clearDisplay(void)`  
Clear Display  


`ssd1306_printText(uint8_t x, uint8_t y, char *ptString)`  
Print single line of text on row `y` starting at horizontal pixel `x`. There are a total of `7` rows starting at `1`. The horizontal starting position can be from `0` to `127`.

`ssd1306_printTextBlock(uint8_t x, uint8_t y, char *ptString)`  
Print a block of text that can span multiple lines, the code will automagically split up the text on multiple lines. It will print the text block starting on row `y` at horizontal pixel `x`. There are a total of `7` rows starting at `1`. The horizontal starting position can be from `0` to `127`. Store the text block as a `char` array. Due to a bug add one extra element to the `char` array. For example:  
`char txtBlock[93] = "This is a long multiline text block. The code will automatically add extra lines as needed."`

`void ssd1306_printUI32( uint8_t x, uint8_t y, uint32_t val, uint8_t Hcenter)`  
Print the 32bit unsigned integer `val` on row `y` at horizontal pixel `x`. The code automagically adds thousands comma spacing to enable easy reading of large numbers. Use `Hcenter` to horizontally center the number at row `y` regardless of the value of `x`. `Hcenter` accepts `HCENTERUL_ON` and `HCENTERUL_OFF`.