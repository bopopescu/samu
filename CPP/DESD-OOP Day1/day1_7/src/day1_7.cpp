//============================================================================
// Name        : day1_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std; //using namespace directive

int main(void)
{
	std::cout<<"Hello World"; //namespace_name :: variable name
	//using namespace namespace_name;
	return 0;
}


/*

namespace na
{
	int num=50;
}
int main(void)
{
	int num=100;
	cout<<"Local"<<num<<endl;

	cout<<"Name space variable"<<na::num;

	return 0;
}
*/

/*
int num=10; //global variable

namespace na //namespace definition
{
	int num=20; //namespace variable
}

namespace nb //nested namespace
{
	int num=40;
	namespace nc
	{
		int num=50;
	}
}

int main()
{
	int num=30;  //local variable
	cout<<"Local Variable"<<num<<" "<<&num<<endl;
	cout<<"Global Variable"<<::num<<" "<<&::num<<endl;//:: scope resolution operator
	cout<<"Variable of namespace na"<<na::num<<" "<<&na::num<<endl;
	cout<<"Nb=>num"<<nb::num<<" "<<&nb::num<<endl;
	cout<<"Nb::Nc::Num"<<nb::nc::num<<" "<<&nb::nc::num<<endl;

	return 0;
}
*/
