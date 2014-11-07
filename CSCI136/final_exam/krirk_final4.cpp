#include <iostream>
#include <vector>
using namespace std;

//function declaration
int recFib(int);

int main()
{
//variables
	int n;
	int fib;
	int temp;
	vector<int>vecFib;
//gather input
	cout << "Enter the number of fibonnaci numbers you would like" <<endl;
	cin >> n;
	temp = n;
	while (n >= 0)
	{
		fib = recFib(n);
		vecFib.push_back(fib);
		n--;
	}
	temp = temp - 1;
		
	for (int i = temp; i >= 0;i--)
	{
		cout << vecFib[i]<< " ";
	}
	cout <<endl;
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
