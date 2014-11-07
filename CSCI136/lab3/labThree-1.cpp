/*
Title: Defined & Predefined functions
Created By: Krirk Pongsema
Created Date: 9/24/13
Description: Lab three, Task 1
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <cmath>
using namespace std;

//declarations
void computesqr1(int);
double computesqr2(int);
float computepow(float, float);


int main()
{
//vars
	int x;
	int y;
	float b;
	float e;
	int sqx;
	int sqy;
	float pwr;
//using function 1
	cout <<"Enter a number: ";
	cin >> x;
	computesqr1(x);
//using function 2
	cout <<"Enter a second number: ";
	cin >> y;
	sqy = computesqr2(y);
	cout << "using function #2, the square root is "<< sqy <<endl;
//using function 3 
	cout <<"Enter a third number: ";
	cin >> b;
	cout <<"Enter the degree to raise it to: ";
	cin >> e;
	pwr = computepow(b, e);
	cout << "using function #3, " << b << " raised to the power of " << e << " is " << pwr <<endl;
	return 0;
}

void computesqr1(int x)
{
	int sqx;
	sqx = sqrt(x);
	cout << "using function #1, the square root is "<< sqx <<endl;
}

double computesqr2(int y)
{
	int sqy;	
	sqy = sqrt(y);
	return sqy;
}

float computepow(float b, float e)
{
	float pwr;
	pwr = pow(b, e);
	return pwr;
}
