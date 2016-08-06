/*
 * Calculator.h
 *
 *  Created on: 28 αιεμ 2016
 *      Author: Yair
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
using namespace std;

class Operation{
public:
	Operation();
	virtual ~Operation();
	virtual double Perform(double A, double B) = 0;

};

class Add: public Operation{
public:
	double Perform(double A, double B);
};

class Subtract: public Operation{
public:
	double Perform(double A, double B);
};

class Multiply: public Operation{
public:
	double Perform(double A, double B);
};

class Divide: public Operation{
public:
	double Perform(double A, double B);
};

class Calculator{
	private:
	Add A;
	Subtract sub;
	Multiply mul;
	Divide dev;

	public:
	double calculate(string str);
};



#endif /* CALCULATOR_H_ */
