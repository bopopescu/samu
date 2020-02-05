#include "keypad.h"
#include "uart.h"
#include "LPC17xx.h"
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[12];
	keypad_init();
	uart_init(9600);
	
	while(1)
	{
		uart_puts("***Waiting for Scan .....***\r\n");
		uart_puts_busy_wait();		
		
		uart_gets(str);
		uart_gets_busy_wait();

		uart_puts("***.....................................***\r\n");
		uart_puts_busy_wait();	

		tag_compare(str);

		uart_puts("________________________________________________\r\n");	

		//uart0_puts("Hello\r\n");
		//uart_puts_busy_wait0();

	

	}
	
	return 0;
}


