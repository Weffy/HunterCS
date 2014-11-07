/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 4.
*/

#include <iostream>
using namespace std;

int main ()
{

//vars
	double rate = .5, loanAmount, monthlyPayment, interest;
	float duration;

//obtaining input from user
	cout << "Please enter the amount of the loan: $";
	cin >> loanAmount;

//while loop to ensure we get the rate and not the decimal amount.
//this feels simpler than specifying the user to input the actual percentage.
	while (rate < 1)
	{
		cout << "Please enter the interest rate: ";
		cin >> rate;		
	}

//converting rate and duration to the number we will be using in the calculations	
	rate = rate * .01;
	cout << "How many months will you need to pay back the loan? ";
	cin >> duration;
	duration = duration / 12;
	
//calculations
	interest = loanAmount * rate;
	interest = interest * duration;	
	loanAmount = loanAmount + interest;
	monthlyPayment = loanAmount / (duration * 12);

//output
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Your monthly payment will be: $"<<monthlyPayment << endl;

	return 0;
}
