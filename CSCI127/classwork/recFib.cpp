#include <iostream>
using namespace std;

//function declaration
int recFib(int);

int main()
{
//variables
	int n;
	int fib;

//gather input
	cout << "Enter a number" <<endl;
	cin >> n;
	fib = recFib(n);
	cout << "The Fibonacci result is: " << fib <<endl;
	return 0;
}
//function definition
int recFib (int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return (recFib(n - 1) + recFib(n - 2));
	}
}
