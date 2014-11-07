#include <iostream>
using namespace std;

int recSum(int);

int main()
{
//variables
	int n;
	int result;

	cout <<"Please enter a number: "<<endl;
	cin >> n;
	result = recSum(n);
	cout <<"the sum of the numbers up to "<< n <<" is: "<< result <<endl;
	return 0;
}
int recSum (int n)
{
//base case
	if (n == 0)
	{
		return 0;
	}

//recursive case
	else
	{
		return (n + recSum(n-1));
	}
}
