/*
Krirk Pongsema
CSCI135
11/3/13
Homework 10/28 part 3
Ch. 6, Question 3.
*/

#include <iostream>
#include <string>
using namespace std;

class Point
{

public:
	void set(); // sets X and Y value of coordinate pair
	void move(); // moves the point according to user input
	void rotate(); //rotates clockwise 90 degrees.  (aka -90/270 degrees)
	int getX() const; //returns x value for output.  const modifier so we can't change the value
	int getY() const; //returns y value for output.  const modifier so we can't change the value

private:
	int x;
	int y;
};

int main()
{
	string done = "n";
	int choice;
	Point pairXY; 
	pairXY.set(); //initial setup
	while (done != "y") //gives user a way to quit program
	{
		cout <<"What would you like to do?"<<endl;
		cout <<"please enter the corresponding number"<<endl;
		cout <<"\n1. setup a new start point"<<endl;
		cout <<"2. move the point"<<endl;
		cout <<"3. rotate the point"<<endl;
		cout <<"4. display current location of the point"<<endl;
		cout <<"5. quit"<<endl;
		cin >> choice;
//precondition: user input will follow correct syntax
		if (choice == 1)
		{
			pairXY.set();
		}
		else if (choice == 2)
		{
			pairXY.move();
		}
		else if (choice == 3)
		{
			pairXY.rotate();
		}
		else if (choice == 4)
		{
			cout << "the point is located at: ("<< pairXY.getX() << ", " << pairXY.getY() <<")"<<endl;
		}
		else if (choice == 5)
		{
			cout <<"have a nice day!"<<endl;
			done = "y";
		}
	}

	return 0;
}

void Point::set()
{
//precondition: user input will follow correct syntax
	cout <<"Enter a X value"<<endl;
	cout <<"horizontal plane"<<endl;
	cin >> x;
	cout <<"Enter a Y value"<<endl;
	cout <<"vertical plane"<<endl;
	cin >> y;
}

void Point::move()
{
//precondition: user input will follow correct syntax
	int w;
	int z;
	cout <<"where would you like to move the x value?"<<endl;
	cin >> w;
	x = x + w;
	cout <<"where would you like to move the y value?"<<endl;
	cin >> z;
	y = y + z;

}

void Point::rotate()
{
//as per http://www.mathwarehouse.com/transformations/rotations-in-math.php
// (A, B) -> (B, -A)
	int temp = x;
	x = y;
	y = temp * -1;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}
