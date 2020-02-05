#include "lcd.h"

void lcd_init(void)
{
	// make data & ctrl port pins as output
	LCD_CTRL->FIODIR |= BV(LCD_RS) | BV(LCD_RW) | BV(LCD_EN);
	LCD_DATA->FIODIR |= BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7);
	// small delay
	delay_ms(200);
	// lcd init
	lcd_write_byte(LCD_INSTR_FLAG, LCD_FNSET);
	lcd_write_byte(LCD_INSTR_FLAG, LCD_DISPCTRL);
	lcd_write_byte(LCD_INSTR_FLAG, LCD_CLEAR);
	lcd_write_byte(LCD_INSTR_FLAG, LCD_ENTRYMODE);
}

void lcd_write_nibble(uint8_t rs_flag, uint8_t data)
{
	// RS=0 for instruction & RS=1 for data
	if(rs_flag == LCD_DATA_FLAG)
		LCD_CTRL->FIOSET |= BV(LCD_RS);
	else
		LCD_CTRL->FIOCLR = BV(LCD_RS);

	// RW=0
	LCD_CTRL->FIOCLR = BV(LCD_RW);

	// write nibble on LCD
	LCD_DATA->FIOCLR = BV(LCD_D4) | BV(LCD_D5) | BV(LCD_D6) | BV(LCD_D7); 
	LCD_DATA->FIOSET |= (uint32_t)data << LCD_D4;

	// falling edge on EN
	LCD_CTRL->FIOSET |= BV(LCD_EN);
	delay_ms(1);
	LCD_CTRL->FIOCLR = BV(LCD_EN);
}

void lcd_write_byte(uint8_t rs_flag, uint8_t data)
{
	uint8_t hi, lo;
	
	hi = data >> 4;
	lcd_write_nibble(rs_flag, hi);
	
	lo = data & 0x0F;
	lcd_write_nibble(rs_flag, lo);
	
	lcd_busy_wait();
	
	delay_ms(3);
}

void lcd_busy_wait(void)
{
	// make D7 pin as input
	LCD_DATA->FIODIR &= ~BV(LCD_D7);
	// rs=0
	LCD_CTRL->FIOCLR = BV(LCD_RS);
	// rw=1 & en=1
	LCD_CTRL->FIOSET |= BV(LCD_RW) | BV(LCD_EN);
	// wait until D7 is 1
	while(LCD_DATA->FIOPIN & BV(LCD_D7))
		;
	// en=0
	LCD_CTRL->FIOCLR = BV(LCD_EN);
	// make D7 pin as output
	LCD_DATA->FIODIR |= BV(LCD_D7);
}

void lcd_puts(uint8_t line, char str[])
{
	int i;
	lcd_write_byte(LCD_INSTR_FLAG, line);
	for(i=0; str[i]!='\0'; i++)
		lcd_write_byte(LCD_DATA_FLAG, str[i]);
}











