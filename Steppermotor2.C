/*     ******* Stepper Motor Driver PIC18F4550********
             ----www.rakeshmondal.info-----
 Source Code 2 Steppermotor2.c
 *  Author: Rakesh Mondal
 * This Software is free software: you free to redistribute it or
 * modify the code way you wish. This software is for educational purpose only.
 *
 * The author will not be responsible for any loss or liability whatsoever.
 * In any circumstances www.rakeshmondal.info shall not be liable for any
 * special, incidental or consequential damages, for any reason whatsoever.
 * No guarantee or warranty whatsoever. Free to share
/*--------------------------------------------------------------------*/

#include <p18f4550.h>
#include "headerzz.h";
#define _XTAL_FREQ 2000000 //20 for the Delays 
#define port_d_op TRISD = 0;
#define port_b_op TRISB = 0;


void singlestepping (void)
{
    int a;

    PORTB = 0b00000111; __delay_ms(60);
    PORTB = 0b00000001; __delay_ms(60);

 for(a=0;a<10;a++)
   {
     PORTD = 0b10000000;    __delay_ms(60);
     PORTD = 0b01000000;    __delay_ms(60);
     PORTD = 0b00100000;    __delay_ms(60);
     PORTD = 0b00010000;    __delay_ms(60);
   }
}


void halfstepping (void)
{
    int b;
    PORTB = 0b00000111;  __delay_ms(60);
    PORTB = 0b00000010;  __delay_ms(60);

 for(b=0;b<10;b++)
   {
     PORTD = 0b10000000;  __delay_ms(60);
     PORTD = 0b11000000;  __delay_ms(60);
     PORTD = 0b01000000;  __delay_ms(60);
     PORTD = 0b01100000;  __delay_ms(60);
     PORTD = 0b00100000;  __delay_ms(60);
     PORTD = 0b00110000;  __delay_ms(60);
     PORTD = 0b00010000;  __delay_ms(60);
     PORTD = 0b10010000;  __delay_ms(60);
   }
 }

void fullstepping (void)
{
    int c;
    PORTB = 0b00000111;  __delay_ms(60);
    PORTB = 0b00000100;  __delay_ms(60);

 for(c=0;c<10;c++)
   {
     PORTD = 0b11000000;  __delay_ms(60);
     PORTD = 0b01100000;  __delay_ms(60);
     PORTD = 0b00110000;  __delay_ms(60);
     PORTD = 0b10010000;  __delay_ms(60);
   }
}

void main (void)
{
    port_d_op; // Make Pord D output
    port_b_op; // make Port B output

    while(1) // Steppings
    {
       
        singlestepping();
        halfstepping();
        fullstepping();
    }
}
