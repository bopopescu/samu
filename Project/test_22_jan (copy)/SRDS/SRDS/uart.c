#include <stdio.h>
#include "uart.h"
#include "keypad.h"
#include <string.h>

static int wr_index = 0;
static const char *wr_string;
static volatile int wr_flag = 1;

static volatile int rd_index = 0;
static char *rd_string = NULL;
static volatile int rd_flag = 1;


static int wr_index0 = 0;
static const char *wr_string0;
static volatile int wr_flag0 = 1;

static volatile int rd_index0 = 0;
static char *rd_string0 = NULL;
static volatile int rd_flag0 = 1;

char send[256] = "a";

char tag1[14] = "550000F913BF\n";
char tag2[14] = "5500E75B53BA\n";
char tag3[14] = "5500CCFE2A4D\n";
char tag4[14] = "5500B7970C79\n";
char tag5[14] = "5500993BB443\n";

void uart_init(uint32_t baud)
{
	uint16_t dl3, dl0;
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
	dl3 = (PCLK >> 4)/baud;
	dl0 = (PCLK >> 4)/baud;

	// set dl - DLL & DLM (to set ensure DLAB=1)	
	LPC_UART3->DLL = dl3 & 0x00FF;
	LPC_UART3->DLM = dl3 >> 8;
	LPC_UART3->LCR &= ~BV(LCR_DLAB);

	LPC_UART0->DLL = dl0 & 0x00FF;
	LPC_UART0->DLM = dl0 >> 8;
	LPC_UART0->LCR &= ~BV(LCR_DLAB);


	// enable UART3 interrupt in NVIC
	NVIC_EnableIRQ(UART3_IRQn);

	NVIC_EnableIRQ(UART0_IRQn);


	// enable tx interrupt
	LPC_UART3->IER = BV(IER_THREIE) | BV(IER_RDAIE) | BV(IER_RLSIE);

	LPC_UART0->IER = BV(IER_THREIE) | BV(IER_RDAIE) | BV(IER_RLSIE);

}

/*---------------------------------UART3---------------------------------------------*/
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

void uart_rx_isr(void)
{
	char ch;
	// recv char & add in string
	ch = LPC_UART3->RBR;
	rd_string[rd_index++] = ch;
	/*if(ch == '\r')
	{
		rd_string[rd_index++] = '\n';
		rd_string[rd_index] = '\0';
		rd_flag = 1;
	}*/
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
			rd_flag = 1;
			break;

		case IID_CTI:
			break;
	} 
}
/*-------------------------------------------------------------------------------------*/



/*---------------------------------UART0---------------------------------------------*/
void uart0_puts_busy_wait(void)
{	
	while(wr_flag0 == 0);
}

void uart0_gets_busy_wait(void)
{
	while(rd_flag0 == 0);
}

void uart0_puts(char str[])
{
	uart0_puts_busy_wait();
	wr_flag0 = 0;
	wr_index0 = 0;
	wr_string0 = str;
	LPC_UART0->THR = wr_string0[wr_index0++];
}

void uart0_gets(char str[])
{
	uart0_gets_busy_wait();
	rd_flag0 = 0;
	rd_string0 = str;
	rd_index0 = 0;
}

void uart0_tx_isr(void)
{
	// send next char
	if(wr_string0[wr_index0] != '\0')
		LPC_UART0->THR = wr_string0[wr_index0++];
	else
		wr_flag0 = 1;
}

void uart0_rx_isr(void)
{
	char ch;
	// recv char & add in string
	ch = LPC_UART0->RBR;
	rd_string0[rd_index0++] = ch;
	/*if(ch == '\r')
	{
		rd_string[rd_index++] = '\n';
		rd_string[rd_index] = '\0';
		rd_flag = 1;
	}*/
}

void UART0_IRQHandler(void)
{
	uint32_t iid, iir = LPC_UART0->IIR;

	iid = (iir >> 1) & IID_MASK;
	switch(iid)
	{
		case IID_THRE:
			uart0_tx_isr();
			break;

		case IID_RDA:
			uart0_rx_isr();
			rd_flag0 = 1;
			break;

		case IID_CTI:
			break;
	} 
}
/*-------------------------------------------------------------------------------------*/

void tag_compare(char str[])
{
	uart_puts("Welcome");
	uart_puts("\r\n");
	
	if((strncmp(str, tag1,12)) == 0)
	{
	
		uart_puts("User1");
		uart_puts("\r\n");
		/*uart0_puts("user_id:1");
		uart0_puts("\r\n");*/
		strcat(send, "user_id:1");
		//menu_material();
		//key = key_fun();
		ration(send);	
	
	}
	else if((strncmp(str, tag2, 12)) == 0)
	{
		uart_puts("User2");
		uart_puts("\r\n");
		uart_puts_busy_wait();
		/*uart0_puts("user_id:2");
		uart0_puts("\r\n");*/
		strcat(send, "user_id:2");
		
		//menu_material();
		//key = key_fun();
		ration(send);
	}
	else if(strncmp(str, tag3, 12) == 0)
	{
		uart_puts("User3");
		uart_puts("\r\n");
		uart_puts_busy_wait();
		/*uart0_puts("user_id:3");
		uart0_puts("\r\n");*/
		strcat(send, "user_id:3");

		//menu_material();
		//key = key_fun();
		ration(send);
	}
	else if(strncmp(str, tag4, 12) == 0)
	{
		uart_puts("User4");
		uart_puts("\r\n");
		uart_puts_busy_wait();
		/*uart0_puts("user_id:4");
		uart0_puts("\r\n");*/
		strcat(send, "user_id:4");
		
		//menu_material();
		//key = key_fun();
		ration(send);
	}
	else if(strncmp(str, tag5, 12) == 0)
	{
		uart_puts("User5");
		uart_puts("\r\n");
		uart_puts_busy_wait();
		/*uart0_puts("user_id:5");
		uart0_puts("\r\n");*/
		strcat(send, "user_id:5");

		//menu_material();
		//key = key_fun();
		ration(send);
	}
	else
	{
		uart_puts("Invalid");
		uart_puts_busy_wait();
	}
}

void ration(char send[])
{
	int kg;
		
		uart_puts("Select sugar between 1 and 5 kgs:\r\n");
		uart_puts("To exit press 0\r\n");
		kg=key_fun();
		while(1)
		{
			if(kg ==49)
			{
				uart_puts("You selected  ----->  Sugar 1 Kg <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "sugar:1");
				break;
			}
			else if(kg ==50)
			{
				uart_puts("You selected  ----->  Sugar 2 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "sugar:2");
				break;
			}
			else if(kg==51)
			{
				uart_puts("You selected  ----->  Sugar 3 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "sugar:3");
				break;
			}
			else if(kg ==52)
			{
				uart_puts("You selected  ----->  Sugar 4 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "sugar:4");
				break;
			}
			else if(kg ==53)
			{
				uart_puts("You selected  ----->  Sugar 5 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "sugar:5");
				break;
			}
			else if(kg ==48)
			{
				strcat(send, "sugar:0");
				break;
			}
			else
			{
				uart_puts("----Select appropriate values----\r\n");
				uart_puts_busy_wait();
			}
		}
		uart_puts("\r\n");
		uart_puts_busy_wait();

		
	
		uart_puts("Select wheat between 1 and 5 kgs:\r\n");
		uart_puts("To exit press 0\r\n");
		uart_puts_busy_wait();
		kg=key_fun();
		while(1)
		{
			if(kg ==49)
			{
				uart_puts("You selected  ----->  Wheat 1 Kg <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "wheat:1");
				break;
			}
			else if(kg ==50)
			{
				
				uart_puts("You selected  ----->  Wheat 2 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "wheat:2");
				break;
			}
			else if(kg ==51)
			{
				uart_puts("You selected  ----->  Wheat 3 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "wheat:3");
				break;
			}
			else if(kg ==52)
			{
				uart_puts("You selected  ----->  Wheat 4 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "wheat:4");
				break;
			}
			else if(kg ==53)
			{
				uart_puts("You selected  ----->  Wheat 5 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "wheat:5");
				break;
			}
			else if(kg ==48)
			{
				strcat(send, "wheat:0");
				break;
			}
			else
			{
				uart_puts("----Select appropriate values----\r\n");
				uart_puts_busy_wait();
			}
		}
		uart_puts("\r\n");
		uart_puts_busy_wait();
		
		uart_puts("Select oil between 1 and 5 ltrs:\r\n");
		uart_puts("To exit press 0\r\n");
		uart_puts_busy_wait();
		kg=key_fun();
		while(1)
		{
			if(kg ==49)
			{
				uart_puts("You selected  ----->  Oil 1 Ltr <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "oil:1");
				break;
			}
			else if(kg ==50)
			{
				uart_puts("You selected  ----->  Oil 2 Ltrs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "oil:2");
				break;
			}
			else if(kg ==51)
			{
				uart_puts("You selected  ----->  Oil 3 Ltrs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "oil:3");
				break;
			}
			else if(kg ==52)
			{
				uart_puts("You selected  ----->  Oil 4 Ltrs <-----\r\n");
				uart_puts_busy_wait();						
				strcat(send, "oil:4");
				break;
			}
			else if(kg ==53)
			{
				uart_puts("You selected  ----->  Oil 5 Ltrs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "oil:5");
				break;
			}
			else if(kg ==48)
			{
				strcat(send, "oil:0");
				break;
			}
			else
			{
				uart_puts("----Select appropriate values----\r\n");
				uart_puts_busy_wait();
			}
		}
		uart_puts("\r\n");
		uart_puts_busy_wait();
		
		uart_puts("Select rice between 1 and 5 kgs:\r\n");
		uart_puts("To exit press 0\r\n");
		uart_puts_busy_wait();
		kg=key_fun();
		while(1)
		{
			if(kg ==49)
			{
				uart_puts("You selected  ----->  Rice 1 Kg <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "rice:1");
				break;
			}

			else if(kg ==50)
			{
				uart_puts("You selected  ----->  Rice 2 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "rice:2");
				break;
			}
			else if(kg ==51)
			{
				uart_puts("You selected  ----->  Rice 3 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "rice:3");
				break;
			}
			else if(kg ==52)
			{
				uart_puts("You selected  ----->  Rice 4 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "rice:4");
				break;
			}
			else if(kg ==53)
			{
				uart_puts("You selected  ----->  Rice 5 Kgs <-----\r\n");
				uart_puts_busy_wait();
				strcat(send, "rice:5");
				break;
			}
			else if(kg ==48)
			{
				strcat(send, "rice:0");
				break;
			}
			else
			{
				uart_puts("----Select appropriate values----\r\n");
				uart_puts_busy_wait();
			}
		}
				
		
		uart0_puts(send);
		uart0_puts("\r\n");
		uart0_puts_busy_wait();
		strcpy(send, "");
}

/*void menu_material(void)
{
	
	uart_puts("Select : \r\n");
	uart_puts("0. Exit \r\n");
	uart_puts("1. Sugar \r\n");
	uart_puts("2. Wheat \r\n");
	uart_puts("3. Oil \r\n");
	uart_puts("4. Rice \r\n");

}*/
