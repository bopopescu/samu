//============================================================================
// Name        : day2_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Complex
{
private:
	int real;
	int imag;
public:
	Complex()
	{
		real=0;
		imag=0;
	}

	Complex(int real , int imag)
		{
			this->real=real;
			this->imag=imag;
		}

	Complex (const Complex &c3)
	{
		this->real=c3.real;
		this->imag=c3.imag;
	}


	Complex sum(const Complex &c2)
	{
		Complex temp;
		temp.real=this->real+c2.real;
		temp.imag=this->imag+c2.imag;
		return temp;
	}
	void print()
	{
		cout<<" \n Real = "<<this->real;
		cout<<" \n Imag = "<<this->imag;

	}
	~Complex()
	{
		cout<<"\n inside desctructor";

	}
};

int main()
{

	Complex c1(10,5);
	Complex c2(5,20);
//	c1.print();
	//c2.print();
	Complex c3(c2);
	//c3.print();

	Complex c4 =c1.sum(c2);
	c4.print();

	return 0;
}
