#include "keypad.h"
#include "uart.h"

void keypad_init(void)
{
	LPC_GPIO2->FIODIR = (BV(keypad_D0) | BV(keypad_D1) | BV(keypad_D2) | BV(keypad_D3));
	LPC_GPIO1->FIODIR &= ~(BV(keypad_D4) | BV(keypad_D5) | BV(keypad_D6));
	LPC_GPIO0->FIODIR &= ~(BV(keypad_D7));

	/*LPC_PINCON->PINSEL4 &= ~(BV(keypad_D0) | BV(keypad_D1) | BV(keypad_D2) | BV(keypad_D3) | BV(keypad_D7));
	LPC_PINCON->PINSEL3 &= ~(BV(keypad_D4) | BV(keypad_D5) | BV(keypad_D6));
*/
}

char key_fun(void)
{
while(1)
{
	LPC_GPIO2->FIOCLR |= BV(keypad_D0);
	LPC_GPIO2->FIOSET |= BV(keypad_D1) | BV(keypad_D2) | BV(keypad_D3);
	if(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)))
	{

		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)));
		//uart_puts("1");
		return 49;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)));
		//uart_puts("2");
		return 50;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)));
		//uart_puts("3");
		return 51;
	}
	else if(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)))
	{
	while(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)));
		//uart_puts("A");
		return 65;
	}
	else
	{}


	LPC_GPIO2->FIOCLR |= BV(keypad_D1);
	LPC_GPIO2->FIOSET |= BV(keypad_D0) | BV(keypad_D2) | BV(keypad_D3);

	if(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)));
		//uart_puts("4");
		return 52;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)))
	{
	while(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)));
		//uart_puts("5");
		return 53;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)))
	{
	while(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)));
		//uart_puts("6");
		return 54;
	}
	else if(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)))
	{
	while(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)));
		//uart_puts("B");
		return 66;
	}
	else
	{}


	LPC_GPIO2->FIOCLR |= BV(keypad_D2);
	LPC_GPIO2->FIOSET |= BV(keypad_D1) | BV(keypad_D0) | BV(keypad_D3);

	if(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)));
			//uart_puts("7");
		return 55;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)));
			//uart_puts("8");
		return 56;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)))
	{
	while(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)));
			//uart_puts("9");
		return 57;
	}
	else if(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)))
	{
		while(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)));

			//uart_puts("C");
		return 67;
	}
	else
	{}


	LPC_GPIO2->FIOCLR |= BV(keypad_D3);
	LPC_GPIO2->FIOSET |= BV(keypad_D1) | BV(keypad_D2) | BV(keypad_D0);

	if(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D4)));
			//uart_puts("*");
		return 42;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)))
	{
		while(!(LPC_GPIO1->FIOPIN & BV(keypad_D5)));
			//uart_puts("0");
		return 48;
	}
	else if(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)))
	{
	while(!(LPC_GPIO1->FIOPIN & BV(keypad_D6)));
			//uart_puts("#");
		return 35;
	}
	else if(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)))
	{
	while(!(LPC_GPIO0->FIOPIN & BV(keypad_D7)));
			//uart_puts("D");
		return 68;
	}
	else
	{}
}
}
	
