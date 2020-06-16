#include "s3c2440_soc.h"
#include "led.h"

void  led_run()
{
    int i=5;
    while(1)
    {
        if(i==9)i=5;
        GPBDAT = ~(1<<i);
        delay(10000);
        i++;
    } 
}
void led_init()
{
    GPBCON &=~(3<<12|3<<10|3<<14|3<<16);
    GPBCON |= 1<<12|1<<10|1<<14|1<<16;
}

void delay(int i)
{
    while(i--);
}