#include <string.h>
#include "LPC17xx.h"
#include "uart.h"

int main()
{
	char str[32];
	uart_init(9600);
	uart_puts("Hello DESD\r\n");
	uart_puts("Enter String: \r\n");
	uart_puts_busy_wait();
	while(1)
	{
		uart_gets(str);
		uart_gets_busy_wait();
		strupr(str);
		uart_puts(str);
		uart_puts_busy_wait();

		/*uart0_puts(str);
		uart_puts_busy_wait();
		uart_gets(str);
		uart_puts_busy_wait();*/
	}
}

