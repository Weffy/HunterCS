/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 8.
edit 9/20 for csci136
adding a controlable level of accuracy
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
	
//variable control of accuracy
	cout << "How accurate would you like this program to be?"<<endl;
	cout << "entering a higher larger will just increase the"<<endl;
	cout << "number of iterations to take place"<<endl;
	cin >> count;

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
