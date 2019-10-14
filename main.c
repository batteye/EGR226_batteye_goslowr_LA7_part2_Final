/*******************************************************
* Name:                Emily Battey and Rebecca Goslow
* Course:            EGR 226 - Microcontroller Programming and Applications
* Project:            Lab 07 - Interfacing a 4x16 LCD to a MSP432
* Description:        print users names to the LCD and the EGR 266 centered
*******************************************************/
#include "msp.h"
#include "LCD.h"
//#include "LCD.c"


/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    innit_pins();
    LCD_innit();
    write_command(0b00000001);
    write_command(0b00000011);
    Systick_ms_delay(10);
    write_command(0b00001111);
    Systick_ms_delay(100);
    space(5);
    dataWrite(0x45);//E
    dataWrite(0x4D);//m
    dataWrite(0x49);//i
    dataWrite(0x4C);//l
    dataWrite(0x59);//y
    space(12);
    dataWrite(0x45);//e
    dataWrite(0x47);//g
    dataWrite(0x52);//r
    space(12);
    space(8);
    dataWrite(0x42);//b
    dataWrite(0x45);//e
    dataWrite(0x43);//c
    dataWrite(0x43);//c
    dataWrite(0x41);//a
    space(12);
    dataWrite(0x32);//2
    dataWrite(0x32);//2
    dataWrite(0x36);//6

    while(1){//hi
        //no
        //dataWrite(0x45);

    }
}
