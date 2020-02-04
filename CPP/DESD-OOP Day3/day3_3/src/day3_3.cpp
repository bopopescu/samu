//============================================================================
// Name        : day3_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class MathDemo
{
public:
	 static void sum(int n1,int n2);//static member declaration
};

void MathDemo::sum(int n1,int n2) //static member function definition
{
	int res;
	res=n1+n2;
	cout<<"Addition : "<<res;
}

int main()
{
	MathDemo::sum(20,10); //function call
	return 0;
}
