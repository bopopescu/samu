#ifndef __KEYPAD_H
#define __KEYPAD_H

#include "LPC17xx.h"

#define keypad_D0 4
#define keypad_D1 5
#define keypad_D2 6
#define keypad_D3 7
#define keypad_D4 24
#define keypad_D5 23
#define keypad_D6 22
#define keypad_D7 28

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
void keypad_init(void);
char key_fun(void);

#endif 
