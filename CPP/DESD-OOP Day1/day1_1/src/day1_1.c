/*
 ============================================================================
 Name        : day1_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Employee
{
	int empid;
	int salary;
};

void accept(struct Employee *e); //function declaration
void disp(struct Employee *e);


int main(void)
{
	struct Employee emp; //declare the structure variable
	accept(&emp);
	disp(&emp);
	return EXIT_SUCCESS;
}
void accept(struct Employee *e)
{
	printf("Enter Empid");
	scanf("%d",&e->empid);

	printf("Enter Emp Salary");
	scanf("%d",&e->salary);

}

void disp(struct Employee *e)
{
	printf("ID=%d SALARY=%d",e->empid,e->salary);
}



