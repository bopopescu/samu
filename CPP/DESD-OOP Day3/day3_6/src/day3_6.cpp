//============================================================================
// Name        : day3_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class constDemo
{
private:
	int n;
	const int c;
	mutable int m;

public:
	constDemo():c(5) //default constructor
	{
		n=100;
		m=300;
	}

/*
	constDemo(int nn,int cc,int mm):c(cc)
		{
			this->n=nn;
			this->m=mm;
		}
*/


	constDemo(int nn,int cc,int mm):n(nn),c(cc),m(mm)
	{ }

	void print() const
	{
		cout<<"\n Num ="<<this->n<<endl;
		cout<<"\n Constant value = "<<this->c<<endl;
		cout<<"\n Mutable value = "<<this->m<<endl;
		//c++; //constDemo::c’ in read-only object
		//n++;//error: increment of member ‘constDemo::n’ in read-only object
		//cout<<"\n Num ="<<this->n<<endl;
		m++;
		cout<<"\n Mutable value = "<<this->m<<endl;

	}

};

int main()
{
	constDemo d;
	d.print();
	return 0;
}
