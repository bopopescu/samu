#include<reg51.h>
sbit sw=P0^0;
sbit led=P1^0;
void delay(unsigned char x)
{
int i,j;
for(i=0;i<x;i++)
for(j=0;j<1275;j++);
}
void main()
{
P0=0XFF;
P1=0X00;
	while(1)
	{
		while(sw==0)
		{
			led=1;
		}
	
	}
}