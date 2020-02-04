//============================================================================
// Name        : day3_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
class Product
{
private:
	string name;
	static int price; //declared
public:
	Product()
	{
		this->name="";

	}
	Product(string name)
	{
		this->name=name;
	}
	void setPrice(int price)
	{
		this->price=price;
	}

	void disp()
	{
		cout<<"\n Product name "<<this->name;
		cout<<"\n Product Price "<<this->price;
	}
};

int Product::price=10000;

int main()
{
	Product p("Laptop");
	p.setPrice(30000);
	p.disp();
	return 0;
}
