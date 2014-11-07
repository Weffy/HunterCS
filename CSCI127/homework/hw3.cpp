#include <iostream>
using namespace std;

//declare function
int recRabbit(int);

int main()
{

//variables
	int months;
	int count = 0;
	int rabbits = 0;
	int dead_rabbits = 0;
	int temp = 0;
	int total = 0;


//gather input from user
	cout <<"Enter the number of months: "<<endl;
	cin >> months;
	total = recRabbit(months);
	
//loop & if with nested if to calculate number of rabbits
	while (count <= months)
	{
		if (count == 0)
		{
			rabbits = 0;
			dead_rabbits = 0;
		}
		else if (count == 1)
		{
			rabbits = 1;
			dead_rabbits = 0;
		}
		else
		{
			if (count % 2 == 0)
			{
				rabbits = rabbits;
				dead_rabbits = dead_rabbits;
			}

//rabbit population doubles every other month.
//it also coincides with the odd months.
			else
			{
				rabbits = (rabbits * 2);
				temp = rabbits;
				while (temp >= 1)
				{
					temp = rabbits / 2;
					dead_rabbits = dead_rabbits + temp;
					break;
				}
			}
		}
	count++;
	}
//output	
	cout <<"According to the loop, after "<< months <<" month(s), the number of pairs of rabbits in the field will be: "<< rabbits <<endl;
	if (dead_rabbits < 1)
	{
	cout <<"According to the loop, no rabbits were harmed during this test!"<<endl;
	}
	else
	{
	cout <<"According to the loop, there was " << dead_rabbits <<" pairs of rabbits harmed because you tested this! :(" <<endl;
	}
	cout <<"According to the function, the number of rabbits in the field is: "<< total <<endl;
	return 0;
}

//define function
int recRabbit(int months)
{
//base cases
	if (months == 0)
	{
		return 0;
	}
	else if (months == 1)
	{
		return 1;
	}
	else if (months == 2)
	{
		return 1;
	}
//recursion
	else
	{
		if (months % 2 == 0) //even
		{
			return recRabbit(months - 2) + recRabbit(months - 3);
		}
		else //odd
		{
			return recRabbit(months - 1) + recRabbit(months - 2);
		}
	}
}
