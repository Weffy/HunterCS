#include <iostream>
using namespace std;

int main()

//program that obtains 10 numbers from the user
//and will output the min and max values
//as well as the sum and average of the values
{

//variables
	int count = 1;
	double input;
	double max;
	double min;
	double sum = 0;
	double avg;

//initial input from user to set initial values
	cout << "Please enter a number: " <<endl;
	cin >> input;
	max = input;
	min = input;
	sum = sum + input;
	avg = sum / count;
	count = count + 1;

	while (count <=10)
	{

		cout << "Please enter a number: " <<endl;
		cin >> input;
		sum = sum + input;
		avg = sum / count;

//if block to determine min/max		
		if (input < min)
		{
			min = input;		
		}
		else if (input > max)
		{
			max = input;
		}

//increase counter		
		count = count + 1;	
	}

//output
		cout << "The minimum is: " << min <<endl;
		cout << "The maximum is: " << max <<endl;
		cout << "The sum is: " << sum <<endl;
		cout << "The average is: " << avg <<endl;
		
	return 0;
}
