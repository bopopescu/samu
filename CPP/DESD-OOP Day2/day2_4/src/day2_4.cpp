//============================================================================
// Name        : day2_4.cpp
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
	//Constructor's member initializer list
	Point() : x(10),y(20)
	{}

	/*Point()
	{
		x=10;
		y=10;
	}
	*/
	Point(int val) : x(val),y(val)
	{}

	Point(int x1,int y1) : x(x1),y(y1)
	{  }

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


/*

class Point
{
private:
	int x;
	int y;
public:
	void disp();
	Point();
	Point(int val);
	Point(int x,int y);

	~Point()
		{
			cout<<"\n inside desctructor";
		}
};

Point::Point()
{
	cout<<"Inside Parameterless Constructor";
	x=10;
	y=20;
}
Point::Point(int val)
{
	cout<<"\n Inside Parameterized Constructor(one arg)";
	this->x=val;
	this->y=val;
}
Point::Point(int x,int y)
{
	cout<<"\n Inside Parameterized Constructor(two arg)";
	this->x=x;
	this->y=y;
}

void Point:: disp()
{
	cout<<"\n Inside Display Function";
	cout<<"\n X = "<<this->x<<"\t Y = "<<this->y;
}


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


*/

