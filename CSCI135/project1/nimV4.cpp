/*
Title: Nim game
Created By: Krirk Pongsema
Created Date: 10/11/13
Description: lab project 1
Modified: 
Modified Date: 10-23
Modified By:
*/ 


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void clearScreen();
void nimRules();
void onePlayerGame();
void twoPlayerGame();
int skynet(int[], int& k);


int main()
{
//vars
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

void nimRules()
{
	cout <<"This version of Nim is played with 4 piles of objects."
	<<"\nEach pile can have anywhere from 1 - 30 objects."
	<<"\nThe Player can remove as many objects as they wish as long"
	<<"\nas it is from the same pile."
	<<"\n\nThe game has two variations, misere and normal."
	<<"\nmisere mode is not enabled in this version."
	<<"\n\nIn a normal game, the player who takes the last object"
	<<"\nwins the game."
	<<"\n\nIn a misere game, the player who is left with the last"
	<<"\nobject loses the game."<<endl;
}

void onePlayerGame()
{
	int a[4];
	int i = 0;
	string strPlayer[2];
	int p = 0;
	int token = 0;	
	while (i <= 3) //populating array
	{
		a[i] = rand() % 30 + 1;
		i++;
	}
	cout << "\nPlayer " << p + 1 << " please enter your name: ";
	cin >> strPlayer[p];
	strPlayer[1] = "Skynet";
	string strPile;
	int sticks;
	p = 0;
	int k = 0;
	while (a[0] + a[1] + a[2] + a[3] > 0)
	{
		if (p == 0)
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
		if (p == 1)
		{

			sticks = skynet(a, k);
			if (k == 0)
			{
				a[k] = a[k] - sticks;
				cout << "Skynet chooses " << sticks <<" from pile A"<<endl;
			}
			else if (k == 1)
			{
				a[k] = a[k] - sticks;
				cout << "Skynet chooses " << sticks <<" from pile B"<<endl;
			}
			else if (k == 2)
			{
				a[k] = a[k] - sticks;
				cout << "Skynet chooses " << sticks <<" from pile C"<<endl;
			}
			else if (k == 3)
			{
				a[k] = a[k] - sticks;
				cout << "Skynet chooses " << sticks <<" from pile D"<<endl;
			}

			if (a[0] + a[1] + a[2] + a[3] == 0)
			{
				cout << strPlayer[p] << " wins!"<<endl;		
			}
			else if (p == 0)
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

void twoPlayerGame()
{
	int a[4];
	int i = 0;
	string strPlayer[2];
	int p = 0;
	int token = 0;	
	while (i <= 3) //populating array
	{
		a[i] = rand() % 30;
		i++;
	}

	while (p <= 1) //getting player names
	{
		cout << "\nPlayer " << p + 1 << " please enter your name: ";
		cin >> strPlayer[p];
		p++;
	}
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

int skynet(int a[], int& k)
{
	int n = 4;
	int i = 0;
	int pileA[5];
	int pileB[5];
	int pileC[5];
	int pileD[5];
	int pileAB[5];
	int pileCD[5];
	int pileABCD[5];
	int sticks = 0;
	int temp = 0;

//winning condition 1) all sticks are in 1 pile	
	if (a[1] + a[2] + a[3] == 0)
	{
		return a[0];
	}
	if (a[0] + a[2] + a[3] == 0)
	{
		return a[1];
	}
	if (a[0] + a[1] + a[3] == 0)
	{
		return a[2];
	}
	if (a[0] + a[1] + a[2] == 0)
	{
		return a[3];
	}
//not all in one pile
//convert to binary
//xor piles to find nim sum
	temp = a[0];
	while (n >= 0) //convert pile A to binary
	{
		pileA[n] = a[0] / pow(2,n);
		if (pileA[n] == 1)
		{
			a[0] = a[0] - pow(2,n);
		}
		n--;
	}
	a[0] = temp;
	temp = a[1];
	n = 4;
	
	while (n >= 0) //convert pile B to binary
	{
		pileB[n] = a[1] / pow(2,n);
		if (pileB[n] == 1)
		{
			a[1] = a[1] - pow(2,n);
		}
		n--;
	}
	a[1] = temp;
	temp = a[2];
	n = 4;
	
	while (n >= 0) //convert pile C to binary
	{
		pileC[n] = a[2] / pow(2,n);
		if (pileC[n] == 1)
		{
			a[2] = a[2] - pow(2,n);
		}
		n--;
	}
	a[2] = temp;
	temp = a[3];
	n = 4;
	
	while (n >= 0) //convert pile D to binary
	{
		pileD[n] = a[3] / pow(2,n);
		if (pileD[n] == 1)
		{
			a[3] = a[3] - pow(2,n);
		}
		n--;
	}
	a[3] = temp;
	n = 4;

	i = 0;
	while (i <= 4) //A XOR B
	{
		pileAB[i] = pileA[i] xor pileB[i];
		i++;
	}
	i = 0;
	while (i <= 4) //C XOR D
	{
		pileCD[i] = pileC[i] xor pileD[i];
		i++;
	}
	i = 0;
	while (i <= 4) //AB XOR CD
	{
		pileABCD[i] = pileAB[i] xor pileCD[i];
		i++;
	}
	i = 4;

//convert back to decimal, set to sticks
	while (i >=0)
	{
		if (pileABCD[i] == 1)
		{
			sticks = sticks + pow(2,i);
		}	
		i--;
	}

//if block from v3

	if (a[0] > sticks)
	{
		if (pileABCD[4] == pileA[4] && pileABCD[3] == pileA[3] && pileABCD[2] == pileA[2] && pileABCD[1] == pileA[1] && pileABCD[0] == pileA[0])
		{
			k = 0;
			return sticks;

		}
		else if (pileABCD[3] == pileA[3] && pileABCD[2] == pileA[2] && pileABCD[1] == pileA[1] && pileABCD[0] == pileA[0])
		{
			k = 0;
			return sticks;

		}
		else if (pileABCD[2] == pileA[2] && pileABCD[1] == pileA[1] && pileABCD[0] == pileA[0])
		{
			k = 0;
			return sticks;

		}
		else if (pileABCD[1] == pileA[1] && pileABCD[0] == pileA[0])
		{
			k = 0;
			return sticks;

		}
		else if (pileABCD[0] == pileA[0])
		{
			k = 0;
			return sticks;

		}
	}
	else if (a[1] > sticks)
	{
		if (pileABCD[4] == pileB[4] && pileABCD[3] == pileB[3] && pileABCD[2] == pileB[2] && pileABCD[1] == pileB[1] && pileABCD[0] == pileB[0])
		{
			k = 1;
			return sticks;
		}
		else if (pileABCD[3] == pileB[3] && pileABCD[2] == pileB[2] && pileABCD[1] == pileB[1] && pileABCD[0] == pileB[0])
		{
			k = 1;
			return sticks;

		}
		else if (pileABCD[2] == pileB[2] && pileABCD[1] == pileB[1] && pileABCD[0] == pileB[0])
		{
			k = 1;
			return sticks;

		}
		else if (pileABCD[1] == pileB[1] && pileABCD[0] == pileB[0])
		{
			k = 1;
			return sticks;

		}
		else if (pileABCD[0] == pileB[0])
		{
			k = 1;
			return sticks;

		}
		
	}
	else if (a[2] > sticks)
	{
		if (pileABCD[4] == pileC[4] && pileABCD[3] == pileC[3] && pileABCD[2] == pileC[2] && pileABCD[1] == pileC[1] && pileABCD[0] == pileC[0])
		{
			k = 2;
			return sticks;

		}
		else if (pileABCD[3] == pileC[3] && pileABCD[2] == pileC[2] && pileABCD[1] == pileC[1] && pileABCD[0] == pileC[0])
		{
			k = 2;
			return sticks;

		}
		else if (pileABCD[2] == pileC[2] && pileABCD[1] == pileC[1] && pileABCD[0] == pileC[0])
		{
			k = 2;
			return sticks;

		}
		else if (pileABCD[1] == pileC[1] && pileABCD[0] == pileC[0])
		{
			k = 2;
			return sticks;

		}
		if (pileABCD[0] == pileC[0])
		{
			k = 2;
			return sticks;

		}
			
	}
	else if (a[3] > sticks)
	{
		if (pileABCD[4] == pileD[4] && pileABCD[3] == pileD[3] && pileABCD[2] == pileD[2] && pileABCD[1] == pileD[1] && pileABCD[0] == pileD[0])
		{
			k = 3;
			return sticks;

		}
		else if (pileABCD[3] == pileD[3] && pileABCD[2] == pileD[2] && pileABCD[1] == pileD[1] && pileABCD[0] == pileD[0])
		{
			k = 3;
			return sticks;

		}
		else if (pileABCD[2] == pileD[2] && pileABCD[1] == pileD[1] && pileABCD[0] == pileD[0])
		{
			k = 3;
			return sticks;

		}
		else if (pileABCD[1] == pileD[1] && pileABCD[0] == pileD[0])
		{
			k = 3;
			return sticks;

		}
		else if (pileABCD[0] == pileD[0])
		{
			k = 3;
			return sticks;

		}
	}
	else //if no bit matches, do something!
	{
		if (a[0] > 0)
		{
			k = 0;
			return 1;
		} 
		else if (a[1] > 0)
		{
			k = 1;
			return 1;
		}
		else if (a[2] > 0)
		{
			k = 2;
			return 1;
		}
		else if (a[3] > 0)
		{
			k = 3;
			return 1;
		}
	}		
	

}		

