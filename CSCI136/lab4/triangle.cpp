/*
Title: Triangle / practice with functions
Created By: Krirk Pongsema
Created Date: 10/1/13
Description: Lab four, task 1
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <cmath>
using namespace std;

//function declaration
int isItATriangle(int, int, int);

int main()
{
//vars
	int a;
	int b;
	int c;
	int triangle = 2;

//input

	cout <<"This program will compute if a triangle is possible "<<endl;
	cout <<"with the numbers you choose"<<endl;
	cout <<endl;
	while (triangle == 2)
	{
		cout <<"Please input the length of side A: ";
		cin >> a;
		cout <<"Please input the length of side B: ";
		cin >> b;
		cout <<"Please input the length of side C: ";
		cin >> c;

//function call
		triangle = isItATriangle(a, b, c);

//output
		if (triangle == 1)
		{
			cout <<"It is a triangle"<<endl;
		}
		else if (triangle == 2)
		{
			cout <<"It is not a triangle"<<endl;
			cout <<"Please enter valid numbers" <<endl;
			cout <<"such as 7, 6, 5"<<endl;
		}
	}
	return 0;
}

//function definition
int isItATriangle(int a, int b, int c)
{
	int x = abs(a*b);
	int y = abs(a*c);
	int z = abs(b*c);
	if (x + y > z && y + z > x && x + z > y)
	{
		return 1;
	}
	else
	{
		return 2;
	}

}
