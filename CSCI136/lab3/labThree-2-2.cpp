/*
Title: Practice with rand() function
Created By: Krirk Pongsema
Created Date: 9/24/13
Description: Lab three, Task 2-2
Modified:
Modified Date: 
Modified By:
*/ 

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

//vars
	int column;
	int row;
	int temp;
	int r;

//gathering input
	cout << "Enter the number of columns: ";
	cin >> column;
	temp = column;
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "********************************************" <<endl;	
	while (row > 0) //controls the number of rows
	{	
		
		while (column > 0) //prints the individual lines for each of the columns
		{
			r = rand() % 10 + 1;
			cout << r << " | ";
			column--;
		}
	
		//reset inner loop
		column = temp;
		cout << endl;	

		//reset inner loops
		column = temp;		
		row--;
	}
	cout << "********************************************" <<endl;
	return 0;
}
