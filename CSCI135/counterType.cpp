/*
Krirk Pongsema
CSCI135
11/1/13
Homework 10/28 part 2
Ch. 6, Question 2.
using a class' member functions to change its attributes
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class CounterType
{
public:
//mutators
	void setCount(); //sets the counter to a count given as an argument
	void upByOne(); //increases count by 1
	void downByOne(); //decreases count by 1
//accessors
	int currentCount(); //returns the count to be output
	void outputCount(); //outputs the count from currentCount

private:
	int count; //non-negative whole number

}k;

int main()
{

	int choice = 0;
	cout <<"Please set the counter"<<endl;
	k.setCount();
	while (choice != 5)
	{
		cout <<"what would you like to do?"<<endl;
		cout <<"1. display the count"<<endl;
		cout <<"2. set a new amount for the count"<<endl;
		cout <<"3. increase the count by 1"<<endl;
		cout <<"4. decrease the count by 1"<<endl;
		cout <<"5. quit"<<endl;
		cout <<"please choose 1 - 5"<<endl;
		cin >> choice;
//precondition: user will follow syntax and only enter 1, 2, 3, 4, 5
		if (choice == 1)
		{
			k.outputCount();
		}
		else if (choice == 2)
		{
			k.setCount();
		}
		else if (choice == 3)
		{
			k.upByOne();
		}
		else if (choice == 4)
		{
			k.downByOne();
		}
		else if (choice == 5)
		{
			cout <<"have a nice day!"<<endl;
			break;
		}
	}
	
	return 0;
}

void CounterType::setCount() //sets the counter to a count given as an argument
{
	count = 0;
	do
	{
		cout <<"What would you like to set the count to?"<<endl;
		cin >> count;
	} while (count < 0);
}

void CounterType::upByOne() //increases count by 1
{
	count = count + 1;
}

void CounterType::downByOne() //decreases count by 1
{
	count = count - 1;
	if (count < 0)
	{
		count = 0;
		cout <<"the value of count must be greater than or equal to zero."<<endl;
		cout <<"value defaulted to zero"<<endl;
	}
}	

int CounterType::currentCount() //returns the count to be output
{
	return count;
}

void CounterType::outputCount() //outputs the count from currentCount
{

	cout <<"the count is: "<< k.currentCount()<<endl;
}
