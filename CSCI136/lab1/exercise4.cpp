/*
**************************************
Title: exercise4.cpp
Author: Krirk Pongsema
Created on: September 3, 2013
Description: Convert Kilometer in to miles
Purpose: Lab exercise
**************************************
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
//vars
	double kmInput, miles;

//gathering input
	cout <<"please enter the distance travelled in kilometers:"<<endl;
	cin >> kmInput;
	miles = kmInput * .621;
	cout <<"you travelled "<<miles<<" miles."<<endl;
	return 0;
}
