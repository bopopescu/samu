//============================================================================
// Name        : day3_11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T> //T : Type Parameter
void swap_number( T &o1, T &o2 )
{
	T temp = o1;
	o1 = o2;
	o2 = temp;
}
int main( void )
{
	int num1 = 10;
	int num2 = 20;
	swap_number<int>( num1, num2 );

	//Here int is type argument
	cout<<"Num1 : "<<num1<<endl;
	cout<<"Num2 : "<<num2<<endl;


	float f1=30.5;
	float f2=40.5;
	swap_number<float>(f1,f2);
	//Here float is type argument
	cout<<"Float Value 1 : "<<f1<<endl;
	cout<<"Float Value 2: "<<f2<<endl;



	return 0;
}


