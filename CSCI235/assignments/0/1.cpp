#include <iostream>
using namespace std;

int main()
{

	int *p1;
	p1 = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter an integer" <<endl;
		
		cin >> p1[i];
	}
	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] <<endl;
	}

	delete p1;
	return 0;
}
