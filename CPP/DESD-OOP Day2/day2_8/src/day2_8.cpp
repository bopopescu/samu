//============================================================================
// Name        : day2_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


void swap_by_val(int n1,int n2); // call by value
void swap_by_add(int *n1,int *n2); // call by address
void swap_by_ref(int &n1,int &n2); // call by reference


int main()
{
	int num1=5,num2=4;
	cout<<"\n Before Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;
	swap_by_val(num1,num2);
	cout<<"\n After Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;

	cout<<"\n Before Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;
	swap_by_add(&num1,&num2);
	cout<<"\n After Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;

	cout<<"\n Before Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;
	swap_by_ref(num1,num2);
	cout<<"\n After Swap : Num1 : "<<num1<<" Num2 : "<<num2<<endl;

	return 0;
}

void swap_by_val(int n1,int n2)
{
	int temp;
	temp=n1;
	n1=n2;
	n2=temp;
}

void swap_by_add(int *n1,int *n2) // call by address
{
	int temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}

void swap_by_ref(int &n1,int &n2) //call by reference
{
	int temp;
	temp=n1;
	n1=n2;
	n2=temp;
}



