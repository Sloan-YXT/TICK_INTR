#include "uart.h"
#include "interrupt_init.h"
#include "led.h"
#include "s3c2440_soc.h"
char startChar = 'A';
char zero = 0;
int main(void)
{
    key_led_init();
    timer0_init();
    led_init();
    GPBDAT = 0xffff;//可读可写！
    //GPBDAT = ~(1<<5|1<<8);
    puts("");
    int i=0;
    putHex(zero);
    puts("");
    //led_run();
    for(;;i++)
    {
        if(i==26)
        {
            i=0;
        }
        putchar(startChar+i);
        delay(0x10000);
    }
}
void putError(unsigned int a,char *b)
{
    putHex(a);
    putchar('\n');
    puts(b);
}