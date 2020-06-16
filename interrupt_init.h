#ifndef INTERRUPT_INIT
#define	INTERRUPT_INIT
#include "s3c2440_soc.h"
void key_led_init(void);
void irq_init(void);
void timer0_init(void);
void irq_regist(FIRQ *,int,FIRQ);
#endif
