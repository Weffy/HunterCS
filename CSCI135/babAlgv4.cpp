/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 8.

v.3 9/21/13
adding a check for accuracy
Homework #2
Ch. 2, Question 9.

v.4 9/27/13
changing how the guess is calculated
*/

#include <iostream>
#include <math.h> //adding the library to use absolute value function
using namespace std;

int main ()
{

//vars
	double r = 0;
	double n = -1;
	double oldGuess;
	double guess;
	int count = 1;

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
	while (count < 10) //the counter is mostly unneccessary.  just needed to have something here.  the loop should cease with the break.
	{	
		oldGuess = guess;
		r = n / guess;
		guess = (guess + r) / 2;
		if (((fabs(guess - oldGuess))/oldGuess) < .01)
		{
			break;
		}
	}
	

//formatting & output	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << guess <<endl; 

	return 0;
}
