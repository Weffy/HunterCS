#include <iostream>
using namespace std;

//declare function
int recRabbit(int);

int main()
{
//variables
	int months;
	int rabbits;
	int rabbits_now = 0;
	int rabbits_lastMonth = 1;
	int rabbits_twoMonthsAgo = 0;
	int count = 1;

//gather input
	cout << "Please enter the number of months: " <<endl;
	cin >> months;
	rabbits = recRabbit(months);
	cout << "according to the recursive function, there are " << rabbits << " rabbits in the field"<<endl;

//calculate the number of pairs of rabbits using a loop
	while (count <= months)
	{
		if (months == 0)
		{
			rabbits_now = 0;
		}
		else if (months = 1)
		{
			rabbits_now = 1;
		}
		else
		{
			rabbits_lastMonth = ; 
			rabbits_twoMonthsAgo = ;
			rabbits_now = (rabbits_lastMonth + rabbits_twoMonthsAgo);	
		}

		count++;
	}
	cout << "according to the loop, there are " << rabbits_now << " rabbits in the field"<<endl;


	return 0;
}

//define function
int recRabbit(int months)
{

	if (months == 0)
	{
		return 0;
	}

	else if (months == 1)
	{
		return 1;
	}
	else 
	{
		return (recRabbit(months - 1) + recRabbit(months - 2));
	}
}
