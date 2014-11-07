/*
Title: Nim game
Created By: Krirk Pongsema
Created Date: 10/11/13
Description: lab project 1
Modified: 
Modified Date: 10-13
Modified By:
*/ 

/*
Things to add
function call works, figure out algorithm


*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

void clearScreen();
void onePlayerGame();
void twoPlayerGame();
void nimRules();
int skynet(int zero, int one, int two, int three);

int main()
{
	srand(time(NULL));
	clearScreen();
	int menuSelect = 0;
	cout <<"Nim: Mathematical Strategy Game"
	<<"\n4 heap version"
	<<"\n";
	while (menuSelect != 1 && menuSelect != 2)
	{
		cout <<"\nHow many players?"
		<<"\n (1) Player"
		<<"\n (2) Players"
		<<"\n (3) Rules"
		<<"\n Enter a selection: ";
		cin >> menuSelect;
		if (menuSelect == 1)
		{
			onePlayerGame();
			break;
		}
		else if (menuSelect == 2)
		{
			twoPlayerGame();
			break;
		}
		else if (menuSelect == 3)
		{
			nimRules();
		}
	}



}

void clearScreen()
{
	int count = 1;
	while (count < 10)
	{
		cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		count++;
	}
}

void onePlayerGame() //need to work on
{
	int a[4];
	int i = 0;
	int gameType = 0;
	string strPlayer[2];
	int p = 0;
	string strFirst = "meh";
	int token = 0;
	while (i <= 3) //populating array
	{
		a[i] = rand() % 30;
		i++;
	}
	while (gameType != 1 && gameType != 2)
	{
		cout <<"Do you want to play normal or misere?"
		<<"\n(1) normal"
		<<"\n(2) misere "<<endl;
		cin >> gameType;
	}

	while (p < 1) //getting player names
	{
		cout << "\nPlayer " << p + 1 << " please enter your name: ";
		cin >> strPlayer[p];
		p++;
	}
	strPlayer[1] = "Skynet";

	while (token == 0)
	{
		cout << "Would you like to go first?"
		<<"\n(yes/no) ";
		cin >> strFirst;
		p = 0;

		if (strFirst == "no" || strFirst == "n" || strFirst == "No")
		{
			p++;
			token = 1;
		} 
		else if (strFirst == "yes" || strFirst == "y" || strFirst == "Yes")
		{
			token = 1;
		}		
	}

	if (gameType == 1) // normal person who takes last stick wins
	{
		if ( p == 0 ) //player
		{
			string strPile = "meh";
			int sticks;
			while (a[0] + a[1] + a[2] + a[3] > 0)
			{
				token = 0;
				while (token == 0)
				{
					cout << strPlayer[p]<< "'s turn"<<endl;
					cout << "\nA: "<< a[0] << "\nB: " << a[1] << "\nC: " << a[2] << "\nD: "<< a[3]<< endl;
					cout << "Which Pile? ";
					cin >> strPile;
					if (strPile == "A" || strPile == "a")	
					{
						token = 1;
					}
					if (strPile == "B" || strPile == "b")	
					{
						token = 1;
					}
					if (strPile == "C" || strPile == "c")	
					{
						token = 1;
					}
					if (strPile == "D" || strPile == "d")	
					{
						token = 1;
					}		
				}

				cout << "How many? ";
				cin >> sticks;
				if (strPile == "A" || strPile == "a")
				{
					while (sticks > a[0] || sticks <= 0)					
					{
						cout << "How many? ";
						cin >> sticks;
					}
			
					a[0] = a[0] - sticks;
				
					if (a[0] + a[1] + a[2] + a[3] == 0)
					{
						cout << strPlayer[p] << " wins!"<<endl;			
					}
				}
				else if (strPile == "B" || strPile == "b")
				{
					while (sticks > a[1] || sticks <= 0)					
					{
						cout << "How many? ";
						cin >> sticks;
					}
				
					a[1] = a[1] - sticks;
					if (a[0] + a[1] + a[2] + a[3] == 0)
					{
						cout << strPlayer[p] << " wins!"<<endl;		
					}
				}
				else if (strPile == "C" || strPile == "c")
				{
					while (sticks > a[2] || sticks <= 0)					
					{
						cout << "How many? ";
						cin >> sticks;
					}

					a[2] = a[2] - sticks;
					if (a[0] + a[1] + a[2] + a[3] == 0)
					{
						cout << strPlayer[p] << " wins!"<<endl;		
					}
				}
				else if (strPile == "D" || strPile == "d")
				{
					while (sticks > a[3] || sticks <= 0)					
					{
						cout << "How many? ";
						cin >> sticks;
					}
					a[3] = a[3] - sticks;
					if (a[0] + a[1] + a[2] + a[3] == 0)
					{
						cout << strPlayer[p] << " wins!"<<endl;		
					}
				}
			
				if (p == 0)
				{
					p = 1;
				}
				else if (p == 1)
				{
					p = 0;
				}
			}
		}
		else if (p == 1) //computer
		{
			int zero = a[0];
			int one = a[1];
			int two = a[2];
			int three = a[3];
			skynet (zero, one, two, three);
			
		}
	}
	if (gameType == 2) // misere person who is left with last stick loses
	{	
		string strPile = "meh";
		int sticks;

		while (a[0] + a[1] + a[2] + a[3] > 0)
		{
			token = 0;
			while (token == 0)
			{
				cout << strPlayer[p]<< "'s turn"<<endl;
				cout << "\nA: "<< a[0] << "\nB: " << a[1] << "\nC: " << a[2] << "\nD: "<< a[3]<< endl;
				cout << "Which Pile? ";
				cin >> strPile;
				if (strPile == "A" || strPile == "a")	
				{
					token = 1;
				}
				if (strPile == "B" || strPile == "b")	
				{
					token = 1;
				}
				if (strPile == "C" || strPile == "c")	
				{
					token = 1;
				}
				if (strPile == "D" || strPile == "d")	
				{
					token = 1;
				}		
			}

			cout << "How many? ";
			cin >> sticks;
			if (strPile == "A" || strPile == "a")
			{
				while (sticks > a[0] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
			
				a[0] = a[0] - sticks;
				
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
		
			else if (strPile == "B" || strPile == "b")
			{
				while (sticks > a[1] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				
				a[1] = a[1] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "C" || strPile == "c")
			{
				while (sticks > a[2] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}

				a[2] = a[2] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "D" || strPile == "d")
			{
				while (sticks > a[3] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				a[3] = a[3] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			
			if (p == 0)
			{
				p = 1;
			}
			else if (p == 1)
			{
				p = 0;
			}
		}
	}
}

void twoPlayerGame() // should be finished
{
	int a[4];
	int i = 0;
	int gameType = 0;
	string strPlayer[2];
	int p = 0;
	int token = 0;	
	while (i <= 3) //populating array
	{
		a[i] = rand() % 30;
		i++;
	}
	while (gameType != 1 && gameType != 2)
	{
		cout <<"Do you want to play normal or misere?"
		<<"\n(1) normal"
		<<"\n(2) misere "<<endl;
		cin >> gameType;
	}
	while (p <= 1) //getting player names
	{
		cout << "\nPlayer " << p + 1 << " please enter your name: ";
		cin >> strPlayer[p];
		p++;
	}
	if (gameType == 1) // normal person who takes last stick wins
	{

		string strPile;
		int sticks;
		p = 0;
		while (a[0] + a[1] + a[2] + a[3] > 0)
		{
			token = 0;
			while (token == 0)
			{
				cout << strPlayer[p]<< "'s turn"<<endl;
				cout << "\nA: "<< a[0] << "\nB: " << a[1] << "\nC: " << a[2] << "\nD: "<< a[3]<< endl;
				cout << "Which Pile? ";
				cin >> strPile;
				if (strPile == "A" || strPile == "a")	
				{
					token = 1;
				}
				if (strPile == "B" || strPile == "b")	
				{
					token = 1;
				}
				if (strPile == "C" || strPile == "c")	
				{
					token = 1;
				}
				if (strPile == "D" || strPile == "d")	
				{
					token = 1;
				}		
			}

			cout << "How many? ";
			cin >> sticks;
			if (strPile == "A" || strPile == "a")
			{
				while (sticks > a[0] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
			
				a[0] = a[0] - sticks;
				
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{
					cout << strPlayer[p] << " wins!"<<endl;			
				}
			}
			else if (strPile == "B" || strPile == "b")
			{
				while (sticks > a[1] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				
				a[1] = a[1] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{
					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "C" || strPile == "c")
			{
				while (sticks > a[2] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}

				a[2] = a[2] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{
					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "D" || strPile == "d")
			{
				while (sticks > a[3] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				a[3] = a[3] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{
					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			
			if (p == 0)
			{
				p = 1;
			}
			else if (p == 1)
			{
				p = 0;
			}
		}
	}
	if (gameType == 2) // misere person who is left with last stick loses
	{	
		string strPile;
		int sticks;

		while (a[0] + a[1] + a[2] + a[3] > 0)
		{
			token = 0;
			while (token == 0)
			{
				cout << strPlayer[p]<< "'s turn"<<endl;
				cout << "\nA: "<< a[0] << "\nB: " << a[1] << "\nC: " << a[2] << "\nD: "<< a[3]<< endl;
				cout << "Which Pile? ";
				cin >> strPile;
				if (strPile == "A" || strPile == "a")	
				{
					token = 1;
				}
				if (strPile == "B" || strPile == "b")	
				{
					token = 1;
				}
				if (strPile == "C" || strPile == "c")	
				{
					token = 1;
				}
				if (strPile == "D" || strPile == "d")	
				{
					token = 1;
				}		
			}

			cout << "How many? ";
			cin >> sticks;
			if (strPile == "A" || strPile == "a")
			{
				while (sticks > a[0] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
			
				a[0] = a[0] - sticks;
				
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
		
			else if (strPile == "B" || strPile == "b")
			{
				while (sticks > a[1] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				
				a[1] = a[1] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "C" || strPile == "c")
			{
				while (sticks > a[2] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}

				a[2] = a[2] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			else if (strPile == "D" || strPile == "d")
			{
				while (sticks > a[3] || sticks <= 0)					
				{
					cout << "How many? ";
					cin >> sticks;
				}
				a[3] = a[3] - sticks;
				if (a[0] + a[1] + a[2] + a[3] == 0)
				{

					cout << strPlayer[p] << " wins!"<<endl;		
				}
			}
			
			if (p == 0)
			{
				p = 1;
			}
			else if (p == 1)
			{
				p = 0;
			}
		}
	}
}

void nimRules()
{
	cout <<"This version of Nim is played with 4 piles of objects."
	<<"\nEach pile can have anywhere from 1 - 30 objects."
	<<"\nThe Player can remove as many objects as they wish as long"
	<<"\nas it is from the same pile."
	<<"\n\nThe game has two variations, misere and normal."
	<<"\n\nIn a normal game, the player who takes the last object"
	<<"\nwins the game."
	<<"\n\nIn a misere game, the player who is left with the last"
	<<"\nobject loses the game."<<endl;
}

int skynet(int zero, int one, int two, int three)
{
	int bTen[4];
	int bits = 5;
	int bTwo;
	int i = 0;
	
	bits = pow(2, bits);
	bTen[0] = zero;
	bTen[1] = one;
	bTen[2] = two;
	bTen[3] = three;

	i = 0;
	while (i <= 3)
	{
		while (bits != 1)
		{
			bTwo = bTen[i] / bits;
			if (bTwo == 1)
			{
				cout << bTwo;
				bTen[i] = bTen[i] - bits;
				bits = bits / 2;
			}
			else
			{
				cout << bTwo;
				bits = bits / 2;
			}
		}
		i++;
	}
	cout <<endl;
	return 0;
}
