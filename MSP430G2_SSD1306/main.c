/**
 * main.c
 *
 * Example usage of SSD1306 library created for MSP-EXP430G2 TI LaunchPad
 * Complied using TI v18.12.2.LTS
 *
 * SSD1306 library based on Adafuit's wonderful Arduino library with modifications
 *  and less features to fit the small amount of RAM available on the MSP430G2553 *
 *
 */

#include <msp430.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "SSD1306.h"
#include "i2c.h"

#define OLED_PWR    BIT0                        // OLED power connect/disconnect on pin P1.0

#define ANUMBER     19052019
#define MAX_COUNT   4.2e9

#define LONG_DELAY  __delay_cycles(3000000)
#define SHORT_DELAY __delay_cycles(50000)

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;	                // stop watchdog timer

    i2c_init();                                 // initialize I2C to use with OLED

    P1DIR = OLED_PWR;                           // P1.0 output, else input
    P1OUT ^= OLED_PWR;                          // turn on power to display

    ssd1306_init();                             // Initialize SSD1306 OLED
    ssd1306_clearDisplay();                     // Clear OLED display

    while(1) {
        // =========================================
        // Display a Long Text Block
        // =========================================
        // There seems to be a bug in the ssd1306_printTextBlock code,
        //  long text blocks like below need 1 extra character in their array
        //  so the code does not read outside of the array. The below 91 character
        //  text block should only need a array of 92 but to fix the bug use an array of 93.
        //  !!!! MUST FIX BUG IN THE FUTURE !!!!
        char txtBlock[93] = "This is a long multiline text block. The code will automatically add extra lines as needed.";
        ssd1306_printTextBlock(0, 1, txtBlock);
        LONG_DELAY;                             // Avoid delay loops in real code, use timer
        ssd1306_clearDisplay();

        // =========================================
        // Print Single Lines of Text at each row
        // =========================================
        ssd1306_printText(0, 1, "Line 1");
        ssd1306_printText(0, 2, "Line 2");
        ssd1306_printText(0, 3, "Line 3");
        ssd1306_printText(0, 4, "Line 4");
        ssd1306_printText(0, 5, "Line 5");
        ssd1306_printText(0, 6, "Line 6");
        ssd1306_printText(0, 7, "Line 7");

        // Print these at a column other then zero
        ssd1306_printText(40, 1, "40");
        ssd1306_printText(50, 2, "50");
        ssd1306_printText(60, 3, "60");
        ssd1306_printText(70, 4, "70");
        ssd1306_printText(80, 5, "80");
        ssd1306_printText(90, 6, "90");
        ssd1306_printText(100, 7, "100");

        // Hold screen for some time before displaying the next sample
        LONG_DELAY;                              // Avoid delay loops in real code, use timer
        ssd1306_clearDisplay();

        // =========================================
        // Print Unsigned 32 bit number
        // =========================================
        ssd1306_printUI32(0, 1, ANUMBER, HCENTERUL_OFF);  // Print number on line 1
        ssd1306_printUI32(0, 2, ANUMBER, HCENTERUL_ON);   // Print number on line 2, horizontally centered

        // Print counting on line 6 horizontally centered
        uint32_t i = 1;
        uint32_t j;
        uint32_t val = 0;
        while (i<1e9) {
            for(j=0; j<10; j++) {
                val = i * j;
                ssd1306_printUI32(0, 6 , val, HCENTERUL_ON);
                SHORT_DELAY;
            }
            i *= 10;
        }

        for (j=0; j<5; j++) {
            val = i * j;
            ssd1306_printUI32(0, 6 , val, HCENTERUL_ON);
            SHORT_DELAY;
        }

        LONG_DELAY;
        ssd1306_clearDisplay();
    }
}
