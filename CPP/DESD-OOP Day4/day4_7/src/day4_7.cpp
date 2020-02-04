//============================================================================
// Name        : day4_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person()
	{
		this->name="";
		this->age=0;

	}
	Person(string name , int age)
		{
			this->name=name;
			this->age=age;

		}

	void display()
	{
		cout<<"\n Name "<<this->name;
		cout<<"\n Age "<<this->age;

	}
};


class Employee : public Person
{
private:
	int empid;
public:
	Employee()
	{
		this->empid=0;
	}
	Employee(string name , int age,int empid):Person(name,age)
	//Person(name,age) will give a call to paramaterized constructor of base class Person
	{

		this->empid=empid;
	}

	void displaydata()
	{
		Person::display();
		cout<<"\n EMP ID = "<<this->empid;
	}

};

int main()
{
	Employee e("Akshita",30,1);
	e.displaydata();
	return 0;
}