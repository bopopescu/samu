//============================================================================
// Name        : day1_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

inline void disp()
{
	cout<<"Inside Display function";
}

inline void max(int x,int y)
{
	int res;
	res=(x>y)?x:y;
	cout<<"Greater number  is"<<res;

}

int main()
{

	disp();
	max(5,4);
	return 0;
}
