#include <iostream>
using namespace std;

//this program gets two integers from the user 
//and prints the minimum

int main()
{

//variables
	int x = 0;
	int y = 0;
	int min;
	double avg;
	double sum;
	double count=0;

//gathering input from user while keeping a count
	cout <<"Please enter a number: "<< endl;
	cin >> x;
	count = count + 1;
	cout << "Please enter another number: "<<endl;
	cin >> y;
	count = count + 1;

//if/then to determine min
	if (x < y)
	{
		min = x;
	}
	else
	{
		min = y;
	}

//calculating sum and average from values input
	sum = x + y;
	avg = sum / count;

//output
	cout <<"the smaller of "<< x <<" and "<< y <<" is: " << min <<endl;
	cout <<"the sum of "<< x <<" and " << y << " is: " << sum <<endl;
	cout <<"the average of "<< x << " and " << y << " is: " << avg <<endl;

	return 0;
}
