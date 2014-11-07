#include <iostream>
#include <string>
using namespace std;

int main()
{
	int count = 1;
	int numOfGuests;
	double number;
	int choice;
	double quotient;
	string done = "n";
	while (done != "y")
	{
		cout <<"what would you like to do?"<<endl;
		cout <<"(1) calculate the number of guests"<<endl;
		cout <<"(2) quit"<<endl;
		cin >> choice;
		if (choice == 1)
		{
			cout <<"how many guests?"<<endl;
			cin >> numOfGuests;
			for (int i = 0; i < numOfGuests;i++)
			{
				quotient = 367 - numOfGuests;
				quotient = quotient / 366;
				
			}
		}
		else if (choice == 2)
		{
			done = "y";
		}






	
	}



	return 0;
}
