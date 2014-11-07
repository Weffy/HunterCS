#include <iostream>
using namespace std;

//Program to estimate deer population
//based off different weather conditions

int main()
{
//Variables
	int year;
	int pop;
	int weather;
	int count = 1;

//Obtain initial information from user
	cout <<"==Deer population simulation program=="<<endl;
	cout <<"Please enter the starting year."<<endl;
	cin >> year;
	cout <<"Please enter the starting population for the deer."<<endl;
	cin >> pop;

//loop to gather weather for 10 years	
	while (count <= 10)
	{
		cout <<"What was the lowest winter temperature in " << year << "?"<<endl;
		cin >> weather;

//if block to calculate deer population based on user input	
		if (weather < 0)
		{
			pop = pop - pop * .15;	
		}
		else if (weather >= 0 and weather <= 25)
		{
			pop = pop - pop * .1;
		}
		else if (weather >=31 and weather <= 35)
		{
			pop = pop + pop * .12;
		}
		else if (weather > 35)
		{
			pop = pop + pop * .14;
		}

//output
		cout <<"In spring "<< year << ", the deer population is " << pop <<"."<<endl;
		year = year + 1;
		count = count + 1; //counter to get out of loop
	}


	return 0;
}
