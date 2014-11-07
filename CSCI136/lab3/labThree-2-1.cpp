/*
Title: Practice with rand() function
Created By: Krirk Pongsema
Created Date: 9/24/13
Description: Lab three, Task 2-1
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
	int thick;
	int temp;

//gathering input
	cout << "Enter the number of columns: ";
	cin >> column;
	thick = column;
	temp = column;
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "************************************************************************************************************" <<endl;	
	while (row > 0) //controls the number of rows
	{	
		while (thick > 0) //the thickness was equal to the number of columns.  needed another loop for the thickness
		{
			while (column > 0) //prints the individual lines for each of the columns
			{
				cout << rand() << " | ";
				column--;
			}
			cout <<endl;
		//reset inner loop
			column = temp;
			thick--;
		}
		cout << "************************************************************************************************************" <<endl;
		//reset inner loops
		thick = temp; 
		column = temp;		
		row--;
	}
	return 0;
}
