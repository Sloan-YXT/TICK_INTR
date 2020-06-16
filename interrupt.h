#ifndef INTERRUPT
#define INTERRUPT
#include "s3c2440_soc.h"
void firq();
void irq_key_led(unsigned int levelOne);
void irq_timer0(unsigned int);
extern FIRQ func_set[32];
#endif