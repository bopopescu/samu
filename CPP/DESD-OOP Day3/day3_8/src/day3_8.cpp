//============================================================================
// Name        : day3_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
class ArithmeticExc
{
private:
	string name;
public:
	ArithmeticExc()
	{
		this->name="";
	}
	ArithmeticExc(string name)
		{
			this->name=name;
		}

	void print()
	{
		cout<<this->name;
	}

	void accept(int &num);
};

void ArithmeticExc::accept(int &num)
{
	cout<<"Enter number";
	cin>>num;
}



int main()
{
	int n1,n2;
	ArithmeticExc e;
	e.accept(n1);
	e.accept(n2);
	try
	{
		if(n2==0)
			throw e;
		cout<<n1/n2;
	}
	catch(ArithmeticExc e)
	{
		cout<<"Exception occured";
	}

	return 0;
}
