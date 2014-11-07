/*
Title: Arrays
Created By: Krirk Pongsema
Created Date: 10/8/13
Description: Lab five, part C
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{

	srand(time(NULL)); //vor rng
	int numbers[1000]; //array
	int count[11]; //used to count the random values in the array
	int i = 0; //primarily used as a counter
	int maxCount = 0; //to keep track of the number of occurances of max
	int minCount = 1000; //to keep track of the number of occurances of min
	int maxValue = 0; //the actual value of the number which occurred the most
	int minValue = 1000; //the actual value of the number which occurred the least


//populating arrays with values
	while (i <= 1000)
	{
		numbers[i] = rand() % 11;
		i++;
	}
	i = 0;
	while (i <= 10)
	{
		count[i] = 0;
		i++;	
	}
	i = 0;

//goes through each number in the array and counts
	while (i <= 1000)
	{
		if (numbers[i] == 0)
		{
			count[0] = count[0]++;
		}
		else if (numbers[i] == 1)
		{
			count[1] = count[1]++;
		}
		else if (numbers[i] == 2)
		{
			count[2] = count[2]++;
		}
		else if (numbers[i] == 3)
		{
			count[3] = count[3]++;
		}
		else if (numbers[i] == 4)
		{
			count[4] = count[4]++;
		}
		else if (numbers[i] == 5)
		{
			count[5] = count[5]++;
		}
		else if (numbers[i] == 6)
		{
			count[6] = count[6]++;
		}
		else if (numbers[i] == 7)
		{
			count[7] = count[7]++;
		}
		else if (numbers[i] == 8)
		{
			count[8] = count[8]++;
		}
		else if (numbers[i] == 9)
		{
			count[9] = count[9]++;
		}
		else if (numbers[i] == 10)
		{
			count[10] = count[10]++;
		}
		i++;
	}
	i = 0;
/*
	while (i <= 10) //to see the occurances of each individual number
	{
		cout << i <<": "<<count[i]<<endl;
		i++;
	}
	i = 0;
*/
	while (i <= 10) //goes through each of the numbers in the count array, keeps the highest/lowest value and count for output
	{
		if (count[i] > maxCount)
		{
			maxValue = i;
			maxCount = count[i];
		}
		if (count[i] < minCount)
		{
			minValue = i;
			minCount = count[i];
		}
		i++;
	}
	cout << "Most appearing number is "<<maxValue<<" and it appeared "<<maxCount<<" times."<<endl;
	cout << "Least appearing number is "<<minValue<<" and it appeared "<<minCount<<" times."<<endl;


	return 0;
}


