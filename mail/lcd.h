#ifndef __LCD_H
#define __LCD_H

#include "LPC17xx.h"

#define LCD_DATA_FLAG	1
#define LCD_INSTR_FLAG	0

#define LCD_LINE1	0x80
#define LCD_LINE2	0xC0

#define LCD_CLEAR		0x01
#define LCD_ENTRYMODE	0x06
#define LCD_DISPCTRL	0x0C
#define LCD_FNSET		0x28

#define LCD_RS		24
#define LCD_RW		23
#define LCD_EN		22

#define LCD_D4		4
#define LCD_D5		5
#define LCD_D6		6
#define LCD_D7		7

#define LCD_DATA	LPC_GPIO2
#define LCD_CTRL	LPC_GPIO1

void lcd_init(void);
void lcd_write_nibble(uint8_t rs_flag, uint8_t data);
void lcd_write_byte(uint8_t rs_flag, uint8_t data);
void lcd_busy_wait(void);
void lcd_puts(uint8_t line, char str[]);

#endif

