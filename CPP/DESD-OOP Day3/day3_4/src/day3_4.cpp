//============================================================================
// Name        : day3_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	const int num1=40; //allowed in C++

	/*Not Ok
	const int num2; //error: uninitialized const ‘num2’
	num2=30;
 	 */
	cout<<num1;
	//cout<<num2; //error: uninitialized const ‘num2’

	return 0;
}
