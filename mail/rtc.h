#ifndef __RTC_H
#define __RTC_H

#include "LPC17xx.h"

struct rtc_1
{
	int date,month,year;
	int hour,min,sec;
};

void rtc_init(struct rtc_1 *obj);
void update_rtc(struct rtc_1 *obj);
#endif
