#include <reg51.h>

sbit led = P1^7;

unsigned char pwm_counter = 0;
unsigned char duty = 0;


/*====================================================
              TIMER 0 INTERRUPT
====================================================*/

void Timer0_ISR(void) interrupt 1
{
    /* Reload Timer 0 */

    TH0 = 0xFF;
    TL0 = 0xED;

    /* Software PWM */

    pwm_counter++;

    if(pwm_counter >= 50)
    {
        pwm_counter = 0;
    }

    /* Active-HIGH LED */

    if(pwm_counter < duty)
    {
        led = 1;       // LED ON
    }
    else
    {
        led = 0;       // LED OFF
    }
}


/*====================================================
                    MAIN
====================================================*/

void main(void)
{
    unsigned int i;

    /* LED initially OFF */

    led = 0;

    /* Timer 0, Mode 1 */

    TMOD = 0x01;

    /* Timer reload value */

    TH0 = 0xFF;
    TL0 = 0xED;

    /* Enable Timer 0 interrupt */

    ET0 = 1;

    /* Enable global interrupt */

    EA = 1;

    /* Start Timer 0 */

    TR0 = 1;


    while(1)
    {
        /*--------------------------------------------
          Increase brightness: 0% ? 100%
        --------------------------------------------*/

        for(duty = 0; duty <= 50; duty++)
        {
            for(i = 0; i < 300; i++)
            {
            }
        }


        /*--------------------------------------------
          Decrease brightness: 100% ? 0%
        --------------------------------------------*/

        for(duty = 50; duty > 0; duty--)
        {
            for(i = 0; i < 300; i++)
            {
            }
        }
    }
}