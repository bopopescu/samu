#ifndef __UART_H
#define __UART_H

#include "LPC17xx.h"

#define		LCR_DL0		0
#define		LCR_DL1		1
#define		LCR_STOP	2
#define		LCR_PAREN	3
#define		LCR_DLAB	7

#define		LSR_RDR		0
#define		LSR_THRE	5

#define		FCR_EN		0

#define		IER_RDAIE	0
#define		IER_THREIE	1
#define		IER_RLSIE	2

#define		IIR_PEND	0
#define		IID_RLS		0x03	
#define		IID_RDA		0x02	
#define		IID_CTI		0x06	
#define		IID_THRE	0x01	
#define		IID_MASK	0x07

void uart_init(uint32_t baud);
void uart_gets(char str[]);
void uart_puts(char str[]);
void uart_puts_busy_wait(void);
void uart_gets_busy_wait(void);

void uart0_init(uint32_t baud);
void uart0_gets(char str[]);
void uart0_puts(char str[]);
void uart0_puts_busy_wait(void);
void uart0_gets_busy_wait(void);

void UART3_IRQHandler(void);
void UART0_IRQHandler(void);

#endif

