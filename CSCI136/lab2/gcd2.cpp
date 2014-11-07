/*
Krirk Pongsema
CSCI136
Lab #2
Exercise #3
9/23/13
*/

#include <iostream>
using namespace std;

//function declaration
int gcdEuclid(int numeratorParameter, int denominatorParameter);

int main ()
{
//vars
	int n, m = 1, gcd;

//data collection	
	cout << "Enter the numerator" <<endl;
	cin >> n;	

//instead of providing an error message, i decided having the user go back into a loop would suffice
//used a do-while so it would run at least once
	do
	{
		cout << "Enter the denominator (this number cannot be less than or equal to 0)" <<endl;
		cin >> m;
	}
	while (m <= 0);

//function call
	gcd = gcdEuclid(n, m);
	cout << "The GCD of " << n << " and " << m << " is " << gcd <<endl;


	return 0;
}

//function definition
int gcdEuclid(int n, int m)
//citing my source
//http://people.cis.ksu.edu/~schmidt/301s12/Exercises/euclid_alg.html
{
	while (m != 0)
	{
		int r = n % m;
		n = m;
		m = r;	
	}
	return n;	
}
