#include "stm8s.h"
#include "delay.h"

void delay_us(unsigned char n)
{
	for (; n > 0; n--)
	{
		asm("nop"); //在STM8里面，16M晶振，_nop_() 延时了 333ns
		asm("nop");
		asm("nop");
	}
}

//---- 毫秒级延时程序----------------------- 
void delay_ms(unsigned int time)
{
	unsigned int i;
	while (time--)
		for (i = 650; i > 0; i--)
			delay_us(1);
}