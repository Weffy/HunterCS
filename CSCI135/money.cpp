/*
name: Krirk Pongsema
date: 11/7/13
description: more practice with structures and classes
CSCI135 Homework
Ch. 6 #8
*/

#include <iostream>
#include <string>
using namespace std;

class Money
{
private:
	int dollars;
	int cents;

public:
//accessors
	int getDollars(); // returns value stored in variable dollars
	int getCents(); // returns value stored in variable cents

//mutators
	void setDollars(); // sets the dollar amount
	void setCents(); // sets the amount of change
	double monAmount(); // displays the amount of both the dollars and cents

}x, y;

int main()
{
	string strInput;
	int choice;
	int blarg = 1; // i want the loop to run until we hit a break;
	while (blarg == 1) 
	{
		cout <<"Which account would you like to view?"<<endl;
		cout <<"account X or account Y (x, y)"<<endl;
		cin >> strInput;
		if (strInput == "x")
		{
			cout <<"What would you like to do?"<<endl;
			cout <<"1. set the amount of dollars"<<endl;
			cout <<"2. set the amount of cents"<<endl;
			cout <<"3. show the monetary amount"<<endl;
			cout <<"4. quit"<<endl;
			cin >> choice;
			if (choice == 1)
			{
				x.setDollars();
			}
			else if (choice == 2)
			{
				x.setCents();
			}
			else if (choice == 3)
			{
				double monies;
				monies = x.monAmount();
				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);
				cout << "$" << monies <<endl;
			}
			else if (choice == 4)
			{
				cout <<"have a nice day!"<<endl;
				break;
			}		
		}
		else if (strInput == "y")
		{
			cout <<"What would you like to do?"<<endl;
			cout <<"1. set the amount of dollars"<<endl;
			cout <<"2. set the amount of cents"<<endl;
			cout <<"3. show the monetary amount"<<endl;
			cout <<"4. quit"<<endl;
			cin >> choice;
			if (choice == 1)
			{
				y.setDollars();
			}
			else if (choice == 2)
			{
				y.setCents();
			}
			else if (choice == 3)
			{
				double monies;
				monies = y.monAmount();
				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);
				cout << "$" << monies <<endl;
			}
			else if (choice == 4)
			{
				cout <<"have a nice day!"<<endl;
				break;
			}
		}
	}
	return 0;
}

int Money::getDollars()
{
	return dollars;
}

int Money::getCents()
{
	return cents;
}

void Money::setDollars()
//precondition: user will enter an integer
{
	cout <<"please enter a whole number"<<endl;
	cin >> dollars;
}

void Money::setCents()
//precondition: user will not enter in a decimal number
{
	cout <<"please enter a whole number"<<endl;
	cout <<"no decimals"<<endl;
	cin >> cents;
}

double Money::monAmount()
{
	double tempCents;
	double tempAmount;
	tempCents = cents * .01;
	tempAmount = tempCents + dollars;
	return tempAmount;
}
