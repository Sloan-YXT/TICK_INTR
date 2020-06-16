#include "s3c2440_soc.h"
#include "interrupt.h"
#include "interrupt_init.h"
void key_led_init()
{
	
	GPGCON &= ~(3|3<<6|3<<10|3<<12|3<<14);
	GPGCON |= 2|2<<6|2<<10|2<<12|2<<14;
	EXTINT1&=~(7|7<<12|7<<20|7<<24|7<<28);
	EXTINT1 |= 7|7<<12|7<<20|7<<24|7<<28;
	EINTMASK &= ~(1<<8|1<<11|1<<13|1<<14|1<<15);
	irq_regist(func_set,5,irq_key_led);
	//puts("key_led_init");
}
void irq_regist(FIRQ *func_set,int serial,FIRQ func)
{
	INTMSK &= ~(1<<serial);
	func_set[serial] = func;
	//puts("serial!!!");
	//putHex(serial);
	//puts("");
	//putHex(func);
	//puts("irq_init");
}
void timer0_init()
{
	GPBCON &= ~3;
	GPBCON |=2;
	TCFG1&=~3;
	TCFG1|=3;
	TCFG0&=~0xff;
	TCFG0|=0xff;
	TCNTB0=0Xffff;
	TCMPB0=0Xffff/2;
	TCON &=~0Xff;
	TCON |= 11;
	TCON &= ~2;
	irq_regist(func_set,10,irq_timer0);
}