#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	srand(time(NULL));
	int randNum;
	int count = 0;
	vector<int>imReallyADynamicArray;
	while (count != 100)
	{
		randNum = rand() & 1001;
		if (randNum > 9 && randNum< 100)
		{
			imReallyADynamicArray.push_back(randNum);
			count++;
		}
	}
	for (int i = 0; i < imReallyADynamicArray.size(); i++)
	{
		cout << imReallyADynamicArray[i] <<endl;
	}
}
