#include <iostream>
using namespace std;

//function declaration
int factorial (int);

int main()
{
	int n;
	int result;
	cout <<"Please enter a positive number" << endl;
	cin >> n;
	result = factorial(n);
	cout << n << " factorial is " << result << endl;
	return 0;
}

//recursive function definition
int factorial (int n)
{
	//base case
	if (n == 0)
	{
		return 1;
	}
	//recursive case
	else	
	{
		return (n + factorial(n-1));
	}
}
