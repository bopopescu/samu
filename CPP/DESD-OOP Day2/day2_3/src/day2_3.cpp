//============================================================================
// Name        : day2_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	//constructor
	//parameterless constructor / default constructor
	Point()
	{
		cout<<"Inside Parameterless Constructor";
		x=10;
		y=20;
	}
	Point(int val)
	{
		cout<<"\n Inside Parameterized Constructor(one arg)";
		this->x=val;
		this->y=val;
	}
	Point(int x,int y)
	{
		cout<<"\n Inside Parameterized Constructor(two arg)";
		this->x=x;
		this->y=y;
	}

	~Point()
	{
		cout<<"\n inside desctructor";
	}
	void disp()
	{
		cout<<"\n Inside Display Function";
		cout<<"\n X = "<<this->x<<"\t Y = "<<this->y;
	}

};

int main()
{
	Point pt; //default constructor is called
	pt.disp();
	Point pt1(40); //one paramater constructor gets called
	pt1.disp();
	Point pt2(100,200);
	pt2.disp();
	return 0;
}


