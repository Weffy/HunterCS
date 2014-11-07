/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 8.

v.3 9/21/13
adding a check for accuracy
Homework #2
Ch. 2, Question 9.
*/

#include <iostream>
#include <math.h> //adding the library to use sqrt function
using namespace std;

int main ()
{

//vars
	double r = 0;
	double n = -1;
	double guess = 2;
	double compare;
	double high;
	double low;

//description for user
	cout << "This program will use the Babylonian algorithm to"<<endl;
	cout << "calculate the square root of a positive number of your choosing"<<endl;	

//gathering input
//ensuring user input is positive
	while (n < 1)
	{
		cout << "Please enter a postive number: "; 
		cin >> n;
	}
	cout << "Please enter a guess of the square root: ";
	cin >> guess;

//using sqrt function to get a number to compare r to
	compare = sqrt(n);

//setting the high and low boundaries
	high = compare + (compare * .01);
	low = compare - (compare * .01);

	
//calculation
//using a do-while so it will run at least once
	do 
	{	
		r = n / guess;
		guess = (guess + r) / 2;
		
	}
	while (r <= low || r >= high);

//formatting & output	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << r <<endl; 

	return 0;
}
