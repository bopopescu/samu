#include "rtc.h"

void rtc_init(struct rtc_1 *obj)
{

	LPC_RTC->CCR|= BV(0) | BV(1);
 	LPC_RTC->DOM=obj->date;
 	LPC_RTC->MONTH=obj->month;
 	LPC_RTC->YEAR=obj->year;
 	LPC_RTC->HOUR=obj->hour;
 	LPC_RTC->MIN=obj->min;
 	LPC_RTC->SEC=obj->sec;
	LPC_RTC->CCR = BV(0) | BV(4);
}

void update_rtc(struct rtc_1 *obj)
{
	obj->date=LPC_RTC->DOM;
	obj->month=LPC_RTC->MONTH;
	obj->year=LPC_RTC->YEAR;
	obj->hour=LPC_RTC->HOUR;
	obj->min=LPC_RTC->MIN;
	obj->sec=LPC_RTC->SEC;
}

