/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 8.
*/

#include <iostream>
using namespace std;

int main ()
{

//vars
	double r, n = -1, guess = 2, count = 5;

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

//calculation
	while (count > 0)
	{	
		r = n / guess;
		guess = (guess + r) / 2;
		count--;
	}

//formatting & output	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << r <<endl; 







	return 0;
}
