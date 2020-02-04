//============================================================================
// Name        : day1_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Employee
{
	int empid;
	int salary;

	void accept()
	{
		printf("Enter Empid");
		scanf("%d",&empid);

		printf("Enter Emp Salary");
		scanf("%d",&salary);

	}

	void disp()
	{
		printf("ID=%d SALARY=%d",empid,salary);
	}

};


int main(void)
{
	struct Employee emp; //declare the structure variable
	emp.accept();
	emp.disp();
	return EXIT_SUCCESS;
}


