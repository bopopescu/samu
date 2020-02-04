	//============================================================================
// Name        : day3_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Demo
{
private:
	const int num1;
public:
	Demo(void)  : num1(10)
	{
		cout<<num1;
	}

	/*// ERROR error: assignment of read-only member ‘Demo::num1’
	Demo(void)
		{
			this->num1=num1;
		}
*/

};

int main()
{
	Demo d;
	return 0;
}
