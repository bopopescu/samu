#include <stdio.h>
#include "uart.h"

/*
   UART Tx Interrrupt Handling
   1. Implement ISR
   2. Enable Interrupt in NVIC
   3. Enable Interrupt in UART (IER)

   UART Tx Interrrupt Logic
   1. Send first character.
   2. When char is transmitted, interrupt will be generated & ISR will be called.
   3. In ISR, send next char (if string is not finished \0).
 */

static int wr_index = 0;
static const char *wr_string = NULL;
static volatile int wr_flag = 1;

static volatile int rd_index = 0;
static char *rd_string = NULL;
static volatile int rd_flag = 1;

void uart_init(uint32_t baud)
{
	uint16_t dl;
	// set P0.0(tx) as output & P0.1(rx) as input
	LPC_GPIO0->FIODIR |= BV(0);
	LPC_GPIO0->FIODIR &= ~BV(1);

	LPC_GPIO0->FIODIR |= BV(2);
	LPC_GPIO0->FIODIR &= ~BV(3);

	// use P0.0 & P0.1 as UART3 pins - PINSEL0
	LPC_PINCON->PINSEL0 &= ~(BV(3) | BV(2) | BV(1) | BV(0));
	LPC_PINCON->PINSEL0 |= BV(3) | BV(1);

	LPC_PINCON->PINSEL0 &= ~(BV(7) | BV(6) | BV(5) | BV(4));
	LPC_PINCON->PINSEL0 |= BV(6) | BV(4);

	// config UART - 8-bits, No parity, 1-stop bits - LCR
	LPC_UART3->LCR = BV(LCR_DLAB) | BV(LCR_DL0) | BV(LCR_DL1);
	LPC_UART0->LCR = BV(LCR_DLAB) | BV(LCR_DL0) | BV(LCR_DL1);

	// calculate dl - dl = (PCLK>>4)/baud
	dl = (PCLK >> 4)/baud;

	// set dl - DLL & DLM (to set ensure DLAB=1)	
	LPC_UART3->DLL = dl & 0x00FF;
	LPC_UART3->DLM = dl >> 8;
	LPC_UART3->LCR &= ~BV(LCR_DLAB);

	LPC_UART0->DLL = dl & 0x00FF;
	LPC_UART0->DLM = dl >> 8;
	LPC_UART0->LCR &= ~BV(LCR_DLAB);

	// enable UART3 interrupt in NVIC
	NVIC_EnableIRQ(UART3_IRQn);
	NVIC_EnableIRQ(UART0_IRQn);

	// enable tx interrupt
	LPC_UART3->IER = BV(IER_THREIE) | BV(IER_RDAIE) | BV(IER_RLSIE);
	LPC_UART0->IER = BV(IER_THREIE) | BV(IER_RDAIE) | BV(IER_RLSIE);
}

void uart_puts_busy_wait(void)
{	
	while(wr_flag == 0);
}

void uart_gets_busy_wait(void)
{
	while(rd_flag == 0);
}

void uart_puts(char str[])
{
	uart_puts_busy_wait();
	wr_flag = 0;
	wr_index = 0;
	wr_string = str;
	LPC_UART3->THR = wr_string[wr_index++];
}

void uart0_puts(char str[])
{
	uart_puts_busy_wait();
	wr_flag = 0;
	wr_index = 0;
	wr_string = str;
	LPC_UART0->THR = wr_string[wr_index++];
}

void uart_gets(char str[])
{
	uart_gets_busy_wait();
	rd_flag = 0;
	rd_string = str;
	rd_index = 0;
}

void uart_tx_isr(void)
{
	// send next char
	if(wr_string[wr_index] != '\0')
		LPC_UART3->THR = wr_string[wr_index++];
	else
		wr_flag = 1;
}

void uart0_tx_isr(void)
{
	// send next char
	if(wr_string[wr_index] != '\0')
		LPC_UART0->THR = wr_string[wr_index++];
	else
		wr_flag = 1;
}

void uart_rx_isr(void)
{
	char ch;
	// recv char & add in string
	ch = LPC_UART3->RBR;
	rd_string[rd_index++] = ch;
	if(ch == '\r')
	{
		rd_string[rd_index++] = '\n';
		rd_string[rd_index] = '\0';
		rd_flag = 1;
	}
}

void uart0_rx_isr(void)
{
	char ch;
	// recv char & add in string
	ch = LPC_UART0->RBR;
	rd_string[rd_index++] = ch;
	if(ch == '\r')
	{
		rd_string[rd_index++] = '\n';
		rd_string[rd_index] = '\0';
		rd_flag = 1;
	}
}

void UART3_IRQHandler(void)
{
	uint32_t iid, iir = LPC_UART3->IIR;

	iid = (iir >> 1) & IID_MASK;
	switch(iid)
	{
		case IID_THRE:
			uart_tx_isr();
			break;

		case IID_RDA:
			uart_rx_isr();
			break;

		case IID_CTI:
			break;
	} 
}

void UART0_IRQHandler(void)
{
	uint32_t iid, iir = LPC_UART0->IIR;

	iid = (iir >> 1) & IID_MASK;
	switch(iid)
	{
		case IID_THRE:
			uart_tx_isr();
			break;

		case IID_RDA:
			uart_rx_isr();
			break;

		case IID_CTI:
			break;
	} 
}


