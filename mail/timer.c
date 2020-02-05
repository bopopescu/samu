#include "timer.h"

extern int flag;
extern int count;

void timer_init(uint32_t ms)
{

	uint32_t cnt;
	count=0;
	LPC_TIM1->TCR= BV(T1_EN) | BV(T1_RESET);

	LPC_TIM1->CTCR = T1_CTCR;

	LPC_TIM1->PR = PR_VAL-1;

	cnt=(PCLK/1000)*(ms/PR_VAL);

	LPC_TIM1->MR1 = cnt-1;

	LPC_TIM1->MCR |= BV(T1_MR1I) | BV(T1_MR1R);

	NVIC_EnableIRQ(TIMER1_IRQn);

	//enable the timer
	LPC_TIM1->TCR = BV(T1_EN);
}

void TIMER1_IRQHandler(void)
{
	//perform task
	count++;
	flag=1;
	//clear the interrupt
	LPC_TIM1->IR |= BV(IR_MR1);
}



