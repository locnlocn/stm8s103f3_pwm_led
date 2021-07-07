#include "stm8s.h"
#include "delay.h"

void delay_us(unsigned char n)
{
	for (; n > 0; n--)
	{
		asm("nop"); //��STM8���棬16M����_nop_() ��ʱ�� 333ns
		asm("nop");
		asm("nop");
	}
}

//---- ���뼶��ʱ����----------------------- 
void delay_ms(unsigned int time)
{
	unsigned int i;
	while (time--)
		for (i = 650; i > 0; i--)
			delay_us(1);
}