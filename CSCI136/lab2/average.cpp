/*
Krirk Pongsema
CSCI136
Lab #2
Exercise 1.
9/17/13
*/

#include <iostream>
using namespace std;

int main ()
{
//vars
	double hwAvg = 0, quizAvg = 0,midAvg = 0, avg, grade, final;
	int count = 1;

//loop to collect homework grades
	while (count <= 10)
	{
		cout << "Enter your homework grade number: "<< count <<endl;
		cin >> grade;
		hwAvg = hwAvg + grade;
		count++;
	}
	hwAvg = hwAvg / (count - 1); //calculates hw average
	count = 1;

//loop to collect quiz grades
	while (count <= 5)
	{
		cout << "Enter your quiz grade number: "<<count <<endl;
		cin >> grade;
		quizAvg = quizAvg + grade;
		count++;
	}
	quizAvg = quizAvg / (count - 1);
	count = 1;

//loop to collect midterm grades
	while (count <= 2)
	{
		cout << "Enter your midterm grade number: "<<count <<endl;
		cin >> grade;
		midAvg = midAvg + grade;
		count++;		
	}
	midAvg = midAvg / (count - 1);
	cout << "Enter your final exam grade: "<<endl;
	cin >> final;
	avg = (final + hwAvg + quizAvg + midAvg) / 4;


//if block to display letter grade
	if (avg >= 98)
	{
		cout <<"you earned an A+"<<endl;	
	}
	else if (avg >= 90)
	{
		cout <<"You earned an A"<<endl;	
	}
	else if (avg >= 80)
	{
		cout <<"You earned an A-"<<endl;	
	}
	else if (avg >= 75)
	{
		cout <<"You earned an B+"<<endl;	
	}

	else if (avg >= 70)
	{
		cout <<"You earned an B"<<endl;	
	}

	else if (avg >= 65)
	{
		cout <<"You earned an B-"<<endl;	
	}
	else if (avg >= 60)
	{
		cout <<"You earned an C+"<<endl;	
	}
	else if (avg >= 55)
	{
		cout <<"You earned an C"<<endl;	
	}
	else if (avg >= 50)
	{
		cout <<"You earned an D"<<endl;	
	}
	else
	{
		cout <<"You earned an F"<<endl;
	}



	return 0;
}
