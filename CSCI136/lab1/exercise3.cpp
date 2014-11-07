/*
**************************************
Title: exercise3.cpp
Author: Krirk Pongsema
Created on: September 3, 2013
Description: obtain user input and display while using more variables
Purpose: Lab exercise
**************************************
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
//vars
	string firstName, lastName, streetAdd, city, email, stateZip;

//gathering input
	cout <<"Please enter your first name:"<<endl;
	getline (cin, firstName);
	cout <<"Please enter your last name:"<<endl;
	getline (cin, lastName);
	cout <<"Please enter your street address:"<<endl;
	getline (cin, streetAdd);
	cout <<"What city do you live in?"<<endl;
	getline (cin, city);
	cout <<"Please enter your state and zipcode:"<<endl;
	getline (cin, stateZip);
	cout <<"Please enter your e-mail address:"<<endl;
	cin >> email; 

//output
	cout <<"********************"<<endl;
	cout <<endl;
	cout <<firstName<<" "<<lastName<<endl;
	cout <<endl;
	cout <<streetAdd<<endl;
	cout <<endl;
	cout <<city<<", "<<stateZip<<endl;
	cout <<endl;
	cout <<email<<endl;
	cout <<endl;
	cout <<"********************"<<endl;

	return 0;
}
