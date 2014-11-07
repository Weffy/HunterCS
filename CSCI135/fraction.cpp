/*
name: Krirk Pongsema
date: 11/7/13
description: more practice with structures and classes
CSCI135 Homework
Ch. 6 #5
*/

#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
	int num;
	int den;
public:
//mutators
	void setNum(); // sets value for numerator
	void setDen(); // sets value for denominator
//accessor
	double divDec(); // value given as a decimal
	void divFrac(); // value represented as a fraction

	
};
	
int gcd(int, int); //global function

int main()
{
	Fraction a;
	int choice;
	string done = "n";
	while (done != "y")
	{
		cout <<"What would you like to do?"<<endl;
		cout <<"1. set the numerator"<<endl;
		cout <<"2. set the denominator"<<endl;
		cout <<"3. show the quotient as a decimal"<<endl;
		cout <<"4. show the fraction in lowest terms"<<endl;
		cout <<"5. quit"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			a.setNum();
		}
		else if (choice == 2)
		{
			a.setDen();
		}
		else if (choice == 3)
		{
			cout << a.divDec();
			cout <<endl;
		}
		else if (choice == 4)
		{
			a.divFrac();
		}
		else if (choice == 5)
		{
			cout <<"have a nice day!"<<endl;
			break;
		}
	}



	return 0;
}

void Fraction::setNum()
{
	cout <<"please type in a whole value for the numerator"<<endl;
	cin >> num;
}

void Fraction::setDen()
{
	cout <<"please type in a whole value for the denominator"<<endl;
	cin >> den;
}

double Fraction::divDec()
//precondition: the user will have initialized the numerator and denominator values by selecting choices 1 & 2 before using this function
//postcondition: output will be a decimal value
{
	return (num * 1.0) / den;
}

void Fraction::divFrac()
//precondition: the user will have initialized the numerator and denominator values by selecting choices 1 & 2 before using this function
{
	int gcdev = gcd(num, den);
	num = num / gcdev;
	den = den / gcdev;
	cout <<num<<"/"<<den<<endl;
	
}


int gcd(int numer, int denom)
{
	int remain = 1;
	int x = 10;
	while (x == 10)
	{	
		if (remain == 0)
		{
			cout <<numer<<endl;
			return numer;	
		}
		else
		{
			remain = numer % denom;
			numer = denom;
			denom = remain;	
		}
	}
}
