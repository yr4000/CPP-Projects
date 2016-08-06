/*
 * Calculator.cpp
 *
 *  Created on: 28 αιεμ 2016
 *      Author: Yair
 */
#include "Calculator.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

Operation::Operation(){}
Operation::~Operation(){};

double Add::Perform(double A,double B){return A+B;}

double Subtract::Perform(double A,double B){return A-B;}

double Multiply::Perform(double A,double B){return A*B;}

double Divide::Perform(double A,double B){return A/B;}

double Calculator::calculate(string str){
	stringstream sts;
	sts<<str;
	double toRes = 0;
	double res = 0;
	double temp;
	int err = 0;
	char op;
	char PASop = '+';		//Previous Add or Subtract operation.

	sts>>toRes; //extract the first number to toRes
	if(sts.fail()){	err = 1 ; goto L1;} //if it fails, go to L1 and return NaN

	while(!sts.eof()){ //running over the equation string
		sts>>op; 	//gets the next operation
		if(sts.fail()){	err = 1 ; goto L1;}
		if(op=='x'){ 	// is op == 'x' multiply temp & toRes using a multiply object.
			sts>>temp;
			if(sts.fail()){	err = 1 ; goto L1;}
			toRes = mul.Perform(temp,toRes);
			continue;
		}
		else if(op=='/'){		//if op == '/' divide toRes by temp using a devision object
			sts>>temp;
			if(sts.fail()){	err = 1 ; goto L1;}
			toRes = dev.Perform(toRes,temp);
			continue;
		}
		else if(op=='+' or op =='-'){
			if(PASop == '+'){res = A.Perform(res,toRes);}		// if PASop == '+' add toRes to res and continue calculate
			else if(PASop == '-'){res = sub.Perform(res,toRes);}		// if PASop == '-' subtract toRes from res and continue calculate
			else {err = 1 ; goto L1;}
			PASop = op;
			sts>>toRes;
			if(sts.fail()){	err = 1 ; goto L1;}
			continue;
		}
		else{ // if op is invalid.
			err = 1;
			goto L1;
		}

	}
	L1:
	if(err==1){
		return numeric_limits<double>::quiet_NaN();

	}
	if(PASop == '+'){ res = A.Perform(res,toRes);} //add or subtract the last calculated toRes to res.
	else {res = sub.Perform(res,toRes);}
	return res;
}



