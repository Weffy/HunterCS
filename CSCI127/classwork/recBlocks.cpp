#include <iostream>
using namespace std;

int recBlocks(int);

int main()
{
//variables
	int n;
	int result;

	cout <<"How many levels?"<<endl;
	cin >> n;
	result = recBlocks(n);
	cout <<"the number of blocks needed is: "<< result <<endl;
	return 0;
}
int recBlocks (int n)
{
//base case
	if (n == 0)
	{
		return 0;
	}
//recursive case
	else
	{
		return (n * n + recBlocks(n-1));
	}	
}
