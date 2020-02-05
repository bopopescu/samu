#include "LPC17xx.h"
#include "timer.h"
#include "lcd.h"
#include <stdio.h>
#include "rtc.h"

int flag=0;
int count=0;
char strx[0];
char time[8];

int main()
{
	struct rtc_1 obj;
	lcd_init();
	rtc_init(&obj);
	obj.date=2;
	obj.month=10;
	obj.year=2019;
	obj.hour=0x02;
	obj.min=0x00;
	obj.sec=0x00;
	delay_ms(100);
	lcd_puts(0x80,"Sankalp Mahajan");
	lcd_puts(0xC0,"DESD");
	timer_init(4000);
	while(1)
	{
		if(flag==1)
		{
			lcd_init();
			sprintf(strx, "%d", count);
			lcd_puts(0x80,"count=");
			lcd_puts(0x86,strx);
			update_rtc(&obj);
			sprintf(time, "%d:%d:%d", obj.hour,obj.min,obj.sec);
			lcd_puts(0xC0,time);
			flag=0;
		}
	}

	return 0;
}

