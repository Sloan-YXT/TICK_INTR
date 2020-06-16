#include "s3c2440_soc.h"
#include "interrupt.h"
FIRQ func_set[32];
void irq_key_led(unsigned int);
static unsigned int a=0xffff;
void firq()
{
	//putHex(INTOFFSET);
	unsigned int levelOne = INTOFFSET;
	func_set[levelOne](levelOne);
	SRCPND = 1<<levelOne;
	INTPND = 1<<levelOne;
}
void irq_key_led(unsigned int levelOne)
{
	unsigned int b;
	//puts("ifq_key_led");
	//foputHex(levelOne);
	if(levelOne==5)
	{
		/*puts("GPBDATA TEST:::");
		putHex(GPBDAT);
		这里为什么能正确实现？难道GPDATA能读能写吗？*/
		/*putHex(GPGDAT);
		if(EINTPEND&&1<<8)
		{
			putHex(EINTPEND);
		if(!(GPGDAT&&1))
		{
			puts("what the fuck!");
			GPBDAT &= ~(1<<5);
		}
		else 
		{
			GPBDAT |= (1<<5);
		}
		}
		else if(EINTPEND&&1<<11)
		{
			putHex(EINTPEND);
		if(!(GPGDAT&&1<<3))
		{
			GPBDAT &=~(1<<6);
		}
		else
		{
			{
				GPBDAT |=1<<6;
			}
		}
		}
		else if(EINTPEND&&1<<13)
		{
			putHex(EINTPEND);
		if(!(GPGDAT&&1<<5))	
		{
			GPBDAT &=~(1<<7);
		}
		else
		{
			GPBDAT |=1<<7;
		}
		}
		else if(EINTPEND&&1<<14)
		{
			putHex(EINTPEND);
		if(!(GPGDAT&&1<<6))
		{
			GPBDAT &=~(1<<8);
		}
		else
		{
			GPBDAT |=1<<8;
		}
		}
		else if(EINTPEND&&1<<15)
		{
			putHex(EINTPEND);
		if(!(GPGDAT&&1<<7))
		{
			GPBDAT&= ~(1<<5|1<<6|1<<7|1<<8);
		}
		else
		{
			GPBDAT|= (1<<5|1<<6|1<<7|1<<8);
		}
		}*/
		#a problem
		if(EINTPEND&1<<8)
		{
			b = a&1<<5;
			b|=~(1<<5);
			a = a&~(unsigned int)(1<<5);
			a= a|~b;
			GPBDAT=a;
		}
		else if(EINTPEND&1<<11)
		{
			b = a&1<<6;
			b|=~(1<<6);
			a = a&~(1<<6);
			
			a= a|~b;
			GPBDAT =a;
		}
		else if(EINTPEND&1<<13)
		{
			b = a&1<<7;
			b|=~(1<<7);
			a = a&~(1<<7);
			
			a= a|~b;
			GPBDAT=a;
		}
		else if(EINTPEND&1<<14)
		{
			b = a&1<<8;
			b|=~(1<<8);
			a = a&~(1<<8);
			
			a= a|~b;
			GPBDAT=a;
		}
		else if(EINTPEND&1<<15)
		{
			b = a&(1<<5|1<<6|1<<7|1<<8);
			b|=~(1<<5|1<<6|1<<7|1<<8);
			a = a&~(1<<5|1<<6|1<<7|1<<8);
			
			a=a|~b;
			GPBDAT=a;
		}
	}
	EINTPEND = EINTPEND;
}
void irq_timer0(unsigned int serial)
{
	unsigned int b;
	b= a&(1<<7|1<<8);
	b|=~(1<<7|1<<8);//除了第7、8位，其他位或进去不产生影响:x|0=x;
	a= a&~(1<<7|1<<8);
	a = a|~b;
	GPBDAT = a;
}