# MSP430G2 SSD1306 OLED Display Library
This is a simple library for interfacing a MSP430G2 LaunchPad with a 128x64 SSD1306 OLED display using i2c. Much of the code for the display has been borrowed from Adafuit's wonderful SSD1306 Arduino library with modifications so that it will work with the limited RAM avalible on the MSP430G2553.

![Simple Example of Library Features](sample.gif)

## Getting Started
### Prerequisites
To use this library you will need the following:
- MSP-EXP430G2 TI LaunchPad or MSP430G2553 uC
- Code Composer Studio
- SSD1306 OLED with I2C
- 2x 10k or other value pullup resistors
- Wires for connecting display to LauchPad
- Breadboard

The Library was written using Code Composer Studio 9.0.1.00004 and TI MSP430 complier version 18.12.2.LTS. Other versions may work.

### Installing
Copy the following files from this repository into your Code Composer Studio project:
- main.c
- i2c.h
- i2c.c
- ssd1306.h
- ssd1306.c
- font_5x7.h

Importing it may also work so give that a try.

### Hookup
Connect Vcc on the display to 3.3v on the LauchPad.
Connect Gnd on the display to gnd on the lauchPad.
Use pullup resistors to connect the SLC and SDA pins to 3.3v.
Connect SLC on the display to P1.6 on the LauchPad
Connect SDA on the display to P1.7 on the LauchPad



## Usage
