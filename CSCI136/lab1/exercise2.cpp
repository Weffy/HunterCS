/*
**************************************
Title: exercise2.cpp
Author: Krirk Pongsema
Created on: September 3, 2013
Description: obtain user input and display a series of strats in addition to blank lines
Purpose: Lab exercise
**************************************
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
//vars
	string name, address, city, email;

//gathering input
	cout <<"Please enter your first and last name:"<<endl;
	getline(cin, name);
	cout <<"Please enter your street address:"<<endl;
	getline (cin, address);
	cout <<"city/state/zip code:"<<endl;
	getline (cin, city);
	cout <<"Please enter your e-mail address:"<<endl;
	getline (cin, email);

//output
	cout <<"********************"<<endl;
	cout <<endl;
	cout <<name<<endl;
	cout <<endl;
	cout <<address<<endl;
	cout <<endl;
	cout <<city<<endl;
	cout <<endl;
	cout <<email<<endl;
	cout <<endl;
	cout <<"********************"<<endl;

	return 0;
}
