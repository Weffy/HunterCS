/*
Krirk Pongsema
CSCI135
11/1/13
Homework 10/28 part 1
Ch. 5, Question 10.
booking seats on a small airplane
using multi-dimensional arrays
*/

#include <iostream>
#include <string>

using namespace std;


int main()
{
	string res = "y"; 
	int x, y;
	string z;
	const int ROWS = 7;
	const int SEATS = 4;
//initializing the array
	char layout[ROWS][SEATS] = {{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'},
	{'A', 'B', 'C', 'D'}};

//precondition: res starts as y to enter loop
	while (res == "y")
	{

		cout << "would you like to reserve a seat? (y/n): "<<endl;
		//postcondition: user response will only be y or n.
		cin >> res;
		if (res == "n")
		{
			cout <<"Have a nice flight!"<<endl;
			break;
		}
		cout <<" *********"<<endl;
		cout <<"1: " << layout[0][0] << " " << layout[0][1] << " " << layout[0][2] << " " << layout[0][3]<<endl;
		cout <<"2: " << layout[1][0] << " " << layout[1][1] << " " << layout[1][2] << " " << layout[1][3]<<endl;
		cout <<"3: " << layout[2][0] << " " << layout[2][1] << " " << layout[2][2] << " " << layout[2][3]<<endl;
		cout <<"4: " << layout[3][0] << " " << layout[3][1] << " " << layout[3][2] << " " << layout[3][3]<<endl;
		cout <<"5: " << layout[4][0] << " " << layout[4][1] << " " << layout[4][2] << " " << layout[4][3]<<endl;
		cout <<"6: " << layout[5][0] << " " << layout[5][1] << " " << layout[5][2] << " " << layout[5][3]<<endl;
		cout <<"7: " << layout[6][0] << " " << layout[6][1] << " " << layout[6][2] << " " << layout[6][3]<<endl;
		cout <<" *********"<<endl;
		//if you are here, then we are reserving a seat
		cout <<"which row and seat would you like to sit in? would you like to sit in?"<<endl;
		cout <<"separate your answers using a space"<<endl;
		cout <<"[row number] [seat letter]"<<endl;
		//postcondition user will follow correct syntax
		cin >> x >> z;
		x = x - 1;
		if (z =="a" ||z =="A")
		{
			y = 0;
		}
		else if (z =="b" || z =="B")
		{
			y = 1;
		}
		else if (z =="c" || z =="C")
		{
			y = 2;
		}
		else if (z =="d" || z=="D")
		{
			y = 3;
		}
		
		if (layout[x][y] == 'A' || layout[x][y] == 'B' || layout[x][y] == 'C' || layout[x][y] == 'D')
		{
			layout[x][y] = 'X';
			cout <<"you have just reserved the seat in row: " << x+1 << " seat: " << z << endl;
		}
		else
		{
			cout << "that seat is taken"<<endl;
		}

		
	}



	return 0;
}


