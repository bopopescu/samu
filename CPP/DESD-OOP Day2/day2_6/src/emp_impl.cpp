/*
 * emp_impl.cpp
 *
 *  Created on: 24-Jan-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include"../include/emp.h"

Employee::Employee()
{
	this->empid=1;
	this->sal=50000;
}

Employee::Employee(int empid,int sal)
{
	this->empid=empid;
	this->sal=sal;
}

void Employee:: accept()
{
	Employee e;
	cout<<"\n Enter Empid";
	cin>>e.empid;
	cout<<"\n Enter sal";
	cin>>e.sal;

	cout<<"\n EMPID = "<<e.empid;
	cout<<"\n EMPSAL = "<<e.sal;

}



