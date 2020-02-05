#ifndef __TIMER_H
#define __TIMER_H

#include "LPC17xx.h"

#define IR_MR1 1
#define T1_EN     0
#define T1_RESET  1
#define T1_CTCR 0x00
#define PR_VAL 18
#define T1_MR1I 3 
#define T1_MR1R 4

void timer_init(uint32_t ms);

#endif
