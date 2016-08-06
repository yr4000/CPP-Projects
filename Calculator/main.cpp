/*
 * main.cpp
 *
 *  Created on: 29 αιεμ 2016
 *      Author: Yair
 */
#include "Calculator.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <limits>
#include <math.h>

using namespace std;

int main(){
	string message = "Welcome to Yairs calculator!\nWhenever you want to exit, type the char '#'\nPlease make sure you enter a valid equation.\nEnjoy!\n\n";
	string eq;
	Calculator cal;
	int escape = 0;
	cout<<message;

	while(escape == 0){ // this loop allows you to use the calculator as a long as you want.
		cout<<"Enter your equation:\n";
		getline(cin,eq);
		if(eq.compare("#")==0){ //condition of escape
			cout<<"Bye!";
			escape = 1;
			continue;
		}
		double res = cal.calculate(eq);
		if(!isnan(res)){
			cout<<"The answer for your equation is: "<<res<<"\n\n";
		}
		else{
			cout<<"Invalid value. Please enter a valid one\n\n";
		}
	}
	return 0;
}



