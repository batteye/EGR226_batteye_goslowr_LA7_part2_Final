/*******************************************************
* Name:                Emily Battey and Rebecca Goslow
* Course:            EGR 226 - Microcontroller Programming and Applications
* Project:            Lab 07 - Interfacing a 4x16 LCD to a MSP432
* Description:        print users names to the LCD and the EGR 266 centered
*******************************************************/
#include "msp.h"
#include "LCD.h"
#include <string.h>
//#include "LCD.c"


/**
 * main.c
 */
void main(void)
{
    volatile uint8_t lone[] = "EMILY";
    volatile uint8_t ltwo[] = "BECCA";
    volatile uint8_t lthree[] = "EGR";
    volatile uint8_t lfour[] = "226";

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    innit_pins();
    write_command(0b00000011);
    LCD_innit();
    write_command(0b00000001);
    write_command(0b00000011);
    Systick_ms_delay(10);
    write_command(0b00001111);
    Systick_ms_delay(100);
    space(5);
    int i = 0;
    for(i = 0;i<5;i++){
            dataWrite((int)lone[i]);//print to LCD
        }
    space(12);
    for(i = 0;i<3;i++){
            dataWrite((int)lthree[i]);//print to LCD
        }
    space(12);
    space(8);
    for(i = 0;i<5;i++){
            dataWrite((int)ltwo[i]);//print to LCD
        }
    space(12);
    for(i = 0;i<3;i++){
            dataWrite((int)lfour[i]);//print to LCD
        }

    while(1){
        //keeps loop from exiting
        //dataWrite(0x45);

    }
}
