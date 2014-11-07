#include <iostream>
using namespace std;

int main()
{
//variables
	int levels;
	int sum = 0;

//obtain data
	cout << "How many levels in the pyramid?" <<endl;
	cin >> levels;

//calculate number of blocks
	while (levels > 0)
	{
		sum = levels * levels + sum;
		levels = levels - 1;
	}

//output
	cout <<"You need " << sum << " blocks." <<endl;
	
	return 0;
}
