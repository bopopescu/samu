//============================================================================
// Name        : day4_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A
{
public:
	void print()
	{
		cout<<"Inside class A";
	}
};

class B
{
public:
	void print()
	{
		cout<<"\n Inside class B";
	}
};




int main()
{
	A aobj;
	B bobj;
	aobj.print();
	bobj.print();
	return 0;
}
