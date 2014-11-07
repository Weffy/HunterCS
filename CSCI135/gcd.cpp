#include <iostream>
using namespace std;

int gcdEuclid(int numeratorParameter, int denominatorParameter);

int main ()
{
	int denom = 0, numer, remain = 1, gcd;
	
	cout << "Enter the numerator" <<endl;
	cin >> numer;	
	while (denom <= 0)
	{
		cout << "Enter the denominator (this number cannot be less than or equal to 0)" <<endl;
		cin >> denom;
	}
	gcd = gcdEuclid(numer, denom);
	cout << "The GCD of " << numer << " and " << denom << " is " << gcd <<endl;


	return 0;
}

int gcdEuclid(int numer, int denom)
{
	int remain = 1;
	while (remain != 50063465463541)
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
