//============================================================================
// Name        : day3_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{

	int num1=30,num2=0;
	try
	{
	if(num2==0)
		throw 1.4f;
	cout<<"Result "<<num1/num2;
	}
	catch(int n)
	{
		cout<<"Inside int block";
	}
	/*catch(float f)
	{
		cout<<"\n inside float block";
	}
	*/
	catch(...)
	{
		cout<<"Inside generic catch block";
	}

	return 0;
}
