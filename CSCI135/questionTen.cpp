/*
Krirk Pongsema
CSCI135
Homework #1
Ch. 1, Question 10.
*/

#include <iostream>
using namespace std;

int main ()
{
	double distance, time;
	const double accel = 32;
	cout <<"How far would an object drop in free fall for x amount of time?"<<endl;
	cout <<"This program will calculate the distance travelled in the amount of time you specify"<<endl;
	cout <<"Please enter an amount of time in seconds: ";
	cin >> time;
	distance = (time * time) * .5 * accel;
	cout <<"An object would travel "<< distance << " feet in " << time << " seconds."<<endl;
	
	return 0;
}
