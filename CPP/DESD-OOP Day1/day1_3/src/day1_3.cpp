//============================================================================
// Name        : day1_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//======================b======================================================

#include <iostream>
using namespace std;

void swap(int a,int b);

int main(void)
{
	int n1=5,n2=4;
	cout<<"Before Swap";
	cout<<"N1="<<n1<<endl;
	cout<<"N2="<<n2<<endl;
	swap(n1,n2);
	cout<<"After Swap";
	cout<<"N1="<<n1<<endl;
	cout<<"N2="<<n2<<endl;


	return 0;
}

void swap(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}




/*

int main(void)
{
	int num1;
	cout<<"Enter value"; //<< extraction operator
	cin>>num1; // >>insertion operator
	cout<<"Value of Num1="<<num1;
	return 0;
}
*/


/*
//function
//function declaration / function signature/ function prototype
//fuction definition
//functioncall

void sum(int a,int b);

int main()
{
	int n1=10,n2=5;
	sum(n1,n2); //fn call
	return 0;
}


void sum(int a,int b) //fn definition
{
	int res=a+b;
	cout<<"res"<<res;
}
*/
