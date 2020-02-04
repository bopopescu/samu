/*
 * emp.h
 *
 *  Created on: 24-Jan-2020
 *      Author: sunbeam
 */

#ifndef EMP_H_
#define EMP_H_

class Employee
{
private:
	int empid;
	int sal;
public:
	Employee();
	Employee(int empid,int sal);
	void accept();

};



#endif /* EMP_H_ */
