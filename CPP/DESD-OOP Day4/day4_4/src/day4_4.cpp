//============================================================================
// Name        : day4_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class Base
{
public:
	virtual void show()
	{
		cout<<"Inside Base Class";
	}
};

class Derived : public Base //public is mode of inheritance
{
public:
	void show()
	{
		Base::show();
		cout<<"\n Inside Derived class";
	}
};

int main()
{

	Base *bptr; //bptr is base class pointer / object
	Derived d;
	bptr=&d;//base class pointer is pointing to derived class object
	bptr->show(); // output :  Inside Derived class //late binding
	return 0;
}




/*
class Base
{
public:
	void show()
	{
		cout<<"Inside Base Class";
	}
};

class Derived : public Base //public is mode of inheritance
{
public:
	void show()
	{
		cout<<"\n Inside Derived class";
	}
};


int main()
{

	Base *bptr; //bptr is base class pointer / object
	Derived d;
	bptr=&d;
	bptr->show(); // output :  Inside Base Class //early binding
	return 0;
}
*/
