/*
Krirk Pongsema
CSCI135
Homework #2
Ch. 2, Question 7.
*/

#include <iostream>
using namespace std;

int main()
{
//declare vars
	int count = 0;
	int x = 0;
	double temp;
	double test = 0;
	double total = 0;

//output
	cout <<"How many exercises to input? ";
	cin >> count;

//loop to gather information
	while (x < count)
	{
		x++;
		cout<<"Score received for test # "<<x<<": ";
		cin >> temp;
		test = test + temp;
		cout<<"What was the total possible score for assignment number "<<x<<"? ";
		cin >> temp;
		total = total + temp;	
	}

//formatting for 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout <<"Your total is "<<test<<" out of "<<total<<", or "<<(test / total) * 100<<"%"<<endl;
	
	return 0;
}
