#include <iostream>

using namespace std;

int main()
{
//initialization
	int iNumber = 21;
	bool bValue = false;
	float flNumber = .362;

	int *x;
	bool *y;
	float *z;

	x = &iNumber;
	cout << *x<<endl;
	cout << x <<endl;
	cout << &x <<endl;

	return 0;
}
