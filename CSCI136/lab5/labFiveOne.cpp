/*
Title: call by reference & call by value
Created By: Krirk Pongsema
Created Date: 10/8/13
Description: Lab five, parts A & B
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>

using namespace std;
void firstFunc(int first, int second, int third); 
void firstFunc(int& first, int& second, int& third, int& fourth); //testing overloading


int main()
{
//initial var values
	int first = 1;
	int second = 2;
	int third = 3;
	int fourth = 4;

//showing call by value doesn't send the values back up to main
	firstFunc(first, second, third); //function call
	cout <<" "<<endl;
	cout <<"back in the main"<<endl;
	cout <<"first: "<<first<<endl;
	cout <<"second: "<<second<<endl;
	cout <<"third: "<<third<<endl;

//overloading firstFunc with 4 vars
	firstFunc(first, second, third, fourth);
	cout <<" "<<endl;
	cout <<"back in the main after second function"<<endl;
	cout <<"first: "<<first<<endl;
	cout <<"second: "<<second<<endl;
	cout <<"third: "<<third<<endl;
	cout <<"fourth: "<<fourth<<endl;


	
	return 0;
}

void firstFunc(int first, int second, int third)
{
	cout <<" "<<endl;
	cout <<"in first function"<<endl;	
	cout <<"before change"<<endl;	
	cout <<"first: "<<first<<endl;
	cout <<"second: "<<second<<endl;
	cout <<"third: "<<third<<endl;
	first = 5;
	second = 10;
	third = 15;
	cout <<" "<<endl;
	cout <<"after change"<<endl;
	cout <<"first: "<<first<<endl;
	cout <<"second: "<<second<<endl;
	cout <<"third: "<<third<<endl;

	
}

void firstFunc(int& first, int& second, int& third, int& fourth)
{
//cycling the variables.
	int temp;
	temp = first;
	first = fourth;
	fourth = second;
	second = temp;
	temp = third;
	third = fourth;
	fourth = temp;

}

