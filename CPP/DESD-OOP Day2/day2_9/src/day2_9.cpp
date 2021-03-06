//============================================================================
// Name        : day2_9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//We should not return local variable from function by reference.
//following code will get terminated as (exit -value =-1)
int& getNumber( void )
{
	int num1 = 10;
	return num1;
}
int main( void )
{
	int &num2 = ::getNumber();
	//num2 will become Dangling reference
	cout<<"Number : "<<num2<<endl;
	return 0;
}

/*



//If we want to return local variable from function by address
//then we should use static keyword.
int* getNumber( void )
{
	static int number = 10;
	return &number;
}
int main( void )
{
	int *ptr = ::getNumber();
	cout<<"Number : "<<*ptr<<endl;
	return 0;
}



*/

//we can not return reference variable as a return value from a function
//following code will get terminated as (exit -value =-1)
/*int* getNumber( void )
{
	int number = 10;
	return &number;
}
int main( void )
{
	int *ptr = ::getNumber();
	cout<<"Number : "<<*ptr<<endl;
	return 0;
}*/
