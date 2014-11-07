/*changelog
version 1:
grid print done, class is setup
framework is in place
need to add turn based system for player and pc
version 2:
turns are in place
pc plays too simplistic
need to add priorities
possibly add offensive and defensive functions
check for ideas: http://lazyfoo.net/articles/article08/index.php
version 3:
instead of random, can add another function
take corners or middle box which are better boxes strategically*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


class Box
{
	private:
		string value;
		int idNumber;
		
	public:
		Box();
		string getValue();
		int getIdNumber();
		void setValue(string v);
		void setIdNumber(int n);
		

};
void printGrid(int ROWS, int COLUMNS, Box boxes[][3]);
void convertPlay(int play, int& a, int& b);
int isPlayValid(int a, int b, Box boxes[][3]);
int pcTurn(int& a, int& b, Box boxes[][3]);
int pcRand(int& a, int& b, Box boxes[][3]);
int pcOffense(int& a, int& b, Box boxes[][3]);
int pcDefense(int& a, int& b, Box boxes[][3]);
void checkWin(Box boxes[][3], string& symbol, int& win);

int main()
{
	srand(time(NULL));
	string symbol = "_";
	int win = 0;
	bool finish = 0;
	int valid = 0;
	int a = 0;
	int b = 0;
	int play = 0;
	string name;
	int choice = 4;
//	int select; //used to setup player character (X or O)
	const int ROWS = 3;
	const int COLUMNS = 3;
	int idCount = 0;
//turn 0 = computer
//turn 1 = player
	int turn = 0; 
	string pc = "O";
	string player = "X";

//creating individual box objects
//the boxes will contain individual ID numbers as well as
//a value (X or O).  It will also start off with a default "-"
//to signify that it is empty and it is a box that can be played

//setting the ID numbers and default values
	Box boxes[ROWS][COLUMNS];
	for (int i = 0; i <ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			boxes[i][j].setIdNumber(idCount);
			boxes[i][j].setValue("_");
			idCount++;
		}
	}


	cout <<"Tic Tac Toe"<<endl;
	cout <<"what is your name?"<<endl;
	cin >> name;
	cout <<"Hello " << name << "!"<<endl;
	cout <<"Would you like to go first?"<<endl;
	cout <<"(1) Yes" <<endl;
	cout <<"(2) No" <<endl;
	cout <<"(3) Quit" <<endl;
	while (choice > 3 || choice < 1)
	{
		cout <<"Please choose a number: ";
		cin >> choice;
		if (choice == 1)
		{
			turn = 1; //player goes first
/*
///////////////////////////////////////////////
///////leaving this out for now////////////////
///////set the PC to O and the player as X/////
///////////////////////////////////////////////

			cout <<"Would you like to be X or O?"<<endl;
			cout <<"(1) X"<<endl;
			cout <<"(2) O"<<endl;
			cin >> select;
//setting player character to X or O
			if (select == 1) 
			{
				pc = "O";
				player = "X";
			}
			else if (select == 2)
			{
				pc = "X";
				player = "O";
			}
*/
			while (finish == 0)
			{

				if (win == 1) //someone won!
				{
					cout << symbol << " wins!"<<endl;
					exit(1); 
				}
				else if (win == 2) //tie game!
				{
					cout <<"game over"<<endl;
					cout <<"tie game!"<<endl;
					exit(1);
				}
				else //game continues!
				{
					if (turn == 1) //player's turn
					{
						cout <<"It is now "<< name << "'s turn"<<endl;
						while (valid == 0)
						{
							cout << valid<<endl;
							printGrid(3, 3, boxes);
							cout <<"Which box would you like to play?"<<endl;
							cout <<"please select a number"<<endl;
							cin >> play;
							convertPlay(play, a, b);
							valid = isPlayValid(a, b, boxes);
						
						}
						boxes[a][b].setValue(player);
						printGrid(3, 3, boxes);
						valid = 0;
						turn = 2; //swap turns
					}
					else if (turn == 2) //pc turn
					{
						cout <<"It is now the computer's turn"<<endl;
						valid = pcTurn(a, b, boxes);
						if (valid == 1)
						{
							boxes[a][b].setValue(pc);
							valid = 0;
							turn = 1; //swap turns
						}		
					}
				}
				checkWin(boxes, symbol, win);
			}
		}
		if (choice == 2)
		{
			turn = 2; //player goes first
/*
///////////////////////////////////////////////
///////leaving this out for now////////////////
///////set the PC to O and the player as X/////
///////////////////////////////////////////////

			cout <<"Would you like to be X or O?"<<endl;
			cout <<"(1) X"<<endl;
			cout <<"(2) O"<<endl;
			cin >> select;
//setting player character to X or O
			if (select == 1) 
			{
				pc = "O";
				player = "X";
			}
			else if (select == 2)
			{
				pc = "X";
				player = "O";
			}
*/
			while (finish == 0)
			{

				if (win == 1) //someone won!
				{
					cout << symbol << " wins!"<<endl;
					exit(1); 
				}
				else if (win == 2) //tie game!
				{
					cout <<"game over"<<endl;
					cout <<"tie game!"<<endl;
					exit(1);
				}
				else //game continues!
				{
					if (turn == 1) //player's turn
					{
						cout <<"It is now "<< name << "'s turn"<<endl;
						while (valid == 0)
						{
							cout << valid<<endl;
							printGrid(3, 3, boxes);
							cout <<"Which box would you like to play?"<<endl;
							cout <<"please select a number"<<endl;
							cin >> play;
							convertPlay(play, a, b);
							valid = isPlayValid(a, b, boxes);
						
						}
						boxes[a][b].setValue(player);
						printGrid(3, 3, boxes);
						valid = 0;
						turn = 2; //swap turns
					}
					else if (turn == 2) //pc turn
					{
						cout <<"It is now the computer's turn"<<endl;
						valid = pcTurn(a, b, boxes);
						if (valid == 1)
						{
							boxes[a][b].setValue(pc);
							valid = 0;
							turn = 1; //swap turns
						}		
					}
				}
				checkWin(boxes, symbol, win);
			}
		}

		if (choice == 3)
		{
			cout <<"Thanks for playing!"<<endl;
			return 0;
		}
	}
	return 0;
}


Box::Box()
{

}

string Box::getValue()
{
	return value;
}

int Box::getIdNumber()
{
	return idNumber;
}

void Box::setValue(string v)
{
	value = v;
}

void Box::setIdNumber(int n)
{
	idNumber = n;
}

void printGrid(int ROWS, int COLUMNS, Box boxes[][3])
{
//prints grid
//if a box is not selected
//it will show an ID number
//which will make it easier for the player
//to select which box he/she wishes to play
	for (int k = 0; k < ROWS; k++)
	{
			cout <<endl;
			for (int l = 0; l < COLUMNS; l++)
			{
				if (boxes[k][l].getValue() != "_")
				{
					cout << " | " << boxes[k][l].getValue() << " | ";
				}
				else if (boxes[k][l].getValue() == "_")				
				{
					cout << " | " << boxes[k][l].getIdNumber() << " | ";
				}				
			}
			cout <<endl;
	}
}

void convertPlay(int play, int& a, int& b)
{
//converts the ID number that the player sees
//to the name for 2 dimensional array boxes
	if (play == 0)
	{
		a = 0;
		b = 0;
	}
	else if (play == 1)
	{
		a = 0;
		b = 1;
	}
	else if (play == 2)
	{
		a = 0;
		b = 2;
	}
	else if (play == 3)
	{
		a = 1;
		b = 0;
	}
	else if (play == 4)
	{
		a = 1;
		b = 1;
	}
	else if (play == 5)
	{
		a = 1;
		b = 2;
	}
	else if (play == 6)
	{
		a = 2;
		b = 0;
	}
	else if (play == 7)
	{
		a = 2;
		b = 1;
	}
	else if (play == 8)
	{
		a = 2;
		b = 2;
	}
}

int isPlayValid(int a, int b, Box boxes[][3])
{
//just makes sure that the box selected is available to be played
	if (boxes[a][b].getValue() == "_")
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

int pcTurn(int& a, int& b, Box boxes[][3])
{
//priority order of how I want the PC to play
//play offensively if the opportunity is there
//defensively is no win potential available
//if neither of the above, pick random box

	int valid = 0;
	while (valid == 0)
	{
		valid = pcOffense(a, b, boxes);
		if (valid == 0)
		{
			valid = pcDefense(a, b, boxes);
			if (valid == 0)
			{
				valid = pcRand(a, b, boxes);
			}
		}
	}
	return valid;
}

int pcRand(int& a, int& b, Box boxes[][3])
{
//setting the loop to run until a value is found
	cout <<"pc random"<<endl;
	int x = 0;
	while (x == 0)
	{
		a = rand() % 3;	
		b = rand() % 3;
		if (boxes[a][b].getValue() == "_")
		{
/*
just wanted to see the outputs at this step
			cout <<"a: "<< a <<endl;
			cout <<"b: "<< b <<endl;
*/
			return 1;
		}
	}
}

int pcOffense(int& a, int& b, Box boxes[][3])
{
//methodically checking all win possibilities
//if an opening is available
//the AI should attack
////////////////////////
////////TOP ROW/////////
////////////////////////
	if (boxes[0][0].getValue() == "O" &&  boxes[0][1].getValue() == "O" && boxes[0][2].getValue() == "_")
	{
		a = 0;
		b = 2;
		return 1;
	}
	else if (boxes[0][0].getValue() == "O" &&  boxes[0][1].getValue() == "_" && boxes[0][2].getValue() == "O")
	{
		a = 0;
		b = 1;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[0][1].getValue() == "O" && boxes[0][2].getValue() == "O")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
////////MID ROW/////////
////////////////////////
	else if (boxes[1][0].getValue() == "O" &&  boxes[1][1].getValue() == "O" && boxes[1][2].getValue() == "_")
	{
		a = 1;
		b = 2;
		return 1;
	}
	else if (boxes[1][0].getValue() == "O" &&  boxes[1][1].getValue() == "_" && boxes[1][2].getValue() == "O")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[1][0].getValue() == "_" &&  boxes[1][1].getValue() == "O" && boxes[1][2].getValue() == "O")
	{
		a = 1;
		b = 0;
		return 1;
	}
////////////////////////
////////BOT ROW/////////
////////////////////////
	else if (boxes[2][0].getValue() == "O" &&  boxes[2][1].getValue() == "O" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[2][0].getValue() == "O" &&  boxes[2][1].getValue() == "_" && boxes[2][2].getValue() == "O")
	{
		a = 2;
		b = 1;
		return 1;
	}
	else if (boxes[2][0].getValue() == "_" &&  boxes[2][1].getValue() == "O" && boxes[2][2].getValue() == "O")
	{
		a = 2;
		b = 0;
		return 1;
	}
////////////////////////
///////1st COLUMN///////
////////////////////////
	else if (boxes[0][0].getValue() == "O" &&  boxes[1][0].getValue() == "O" && boxes[2][0].getValue() == "_")
	{
		a = 2;
		b = 0;
		return 1;
	}
	else if (boxes[0][0].getValue() == "O" &&  boxes[1][0].getValue() == "_" && boxes[2][0].getValue() == "O")
	{
		a = 1;
		b = 0;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[1][0].getValue() == "O" && boxes[2][0].getValue() == "O")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
///////2nd COLUMN///////
////////////////////////
	else if (boxes[0][1].getValue() == "O" &&  boxes[1][1].getValue() == "O" && boxes[2][1].getValue() == "_")
	{
		a = 2;
		b = 1;
		return 1;
	}
	else if (boxes[0][1].getValue() == "O" &&  boxes[1][1].getValue() == "_" && boxes[2][1].getValue() == "O")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][1].getValue() == "_" &&  boxes[1][1].getValue() == "O" && boxes[2][1].getValue() == "O")
	{
		a = 0;
		b = 1;
		return 1;
	}
////////////////////////
///////3rd COLUMN///////
////////////////////////
	else if (boxes[0][2].getValue() == "O" &&  boxes[1][2].getValue() == "O" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[0][2].getValue() == "O" &&  boxes[1][2].getValue() == "_" && boxes[2][2].getValue() == "O")
	{
		a = 1;
		b = 2;
		return 1;
	}
	else if (boxes[0][2].getValue() == "_" &&  boxes[1][2].getValue() == "O" && boxes[2][2].getValue() == "O")
	{
		a = 0;
		b = 2;
		return 1;
	}
////////////////////////
////////L-R DIAG////////
////////////////////////
	else if (boxes[0][0].getValue() == "O" &&  boxes[1][1].getValue() == "O" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[0][0].getValue() == "O" &&  boxes[1][1].getValue() == "_" && boxes[2][2].getValue() == "O")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[1][1].getValue() == "O" && boxes[2][2].getValue() == "O")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
////////R-L DIAG////////
////////////////////////
	else if (boxes[0][2].getValue() == "O" &&  boxes[1][1].getValue() == "O" && boxes[2][0].getValue() == "_")
	{
		a = 2;
		b = 0;
		return 1;
	}
	else if (boxes[0][2].getValue() == "O" &&  boxes[1][1].getValue() == "_" && boxes[2][0].getValue() == "O")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][2].getValue() == "_" &&  boxes[1][1].getValue() == "O" && boxes[2][0].getValue() == "O")
	{
		a = 0;
		b = 2;
		return 1;
	}
	else
	{
		return 0;
	}
}
int pcDefense(int& a, int& b, Box boxes[][3])
{
//methodically checking all win possibilities for the opponent
//if an opening is available
//the AI should defend
////////////////////////
////////TOP ROW/////////
////////////////////////
	if (boxes[0][0].getValue() == "X" &&  boxes[0][1].getValue() == "X" && boxes[0][2].getValue() == "_")
	{
		a = 0;
		b = 2;
		return 1;
	}
	else if (boxes[0][0].getValue() == "X" &&  boxes[0][1].getValue() == "_" && boxes[0][2].getValue() == "X")
	{
		a = 0;
		b = 1;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[0][1].getValue() == "X" && boxes[0][2].getValue() == "X")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
////////MID ROW/////////
////////////////////////
	else if (boxes[1][0].getValue() == "X" &&  boxes[1][1].getValue() == "X" && boxes[1][2].getValue() == "_")
	{
		a = 1;
		b = 2;
		return 1;
	}
	else if (boxes[1][0].getValue() == "X" &&  boxes[1][1].getValue() == "_" && boxes[1][2].getValue() == "X")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[1][0].getValue() == "_" &&  boxes[1][1].getValue() == "X" && boxes[1][2].getValue() == "X")
	{
		a = 1;
		b = 0;
		return 1;
	}
////////////////////////
////////BOT ROW/////////
////////////////////////
	else if (boxes[2][0].getValue() == "X" &&  boxes[2][1].getValue() == "X" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[2][0].getValue() == "X" &&  boxes[2][1].getValue() == "_" && boxes[2][2].getValue() == "X")
	{
		a = 2;
		b = 1;
		return 1;
	}
	else if (boxes[2][0].getValue() == "_" &&  boxes[2][1].getValue() == "X" && boxes[2][2].getValue() == "X")
	{
		a = 2;
		b = 0;
		return 1;
	}
////////////////////////
///////1st COLUMN///////
////////////////////////
	else if (boxes[0][0].getValue() == "X" &&  boxes[1][0].getValue() == "X" && boxes[2][0].getValue() == "_")
	{
		a = 2;
		b = 0;
		return 1;
	}
	else if (boxes[0][0].getValue() == "X" &&  boxes[1][0].getValue() == "_" && boxes[2][0].getValue() == "X")
	{
		a = 1;
		b = 0;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[1][0].getValue() == "X" && boxes[2][0].getValue() == "X")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
///////2nd COLUMN///////
////////////////////////
	else if (boxes[0][1].getValue() == "X" &&  boxes[1][1].getValue() == "X" && boxes[2][1].getValue() == "_")
	{
		a = 2;
		b = 1;
		return 1;
	}
	else if (boxes[0][1].getValue() == "X" &&  boxes[1][1].getValue() == "_" && boxes[2][1].getValue() == "X")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][1].getValue() == "_" &&  boxes[1][1].getValue() == "X" && boxes[2][1].getValue() == "X")
	{
		a = 0;
		b = 1;
		return 1;
	}
////////////////////////
///////3rd COLUMN///////
////////////////////////
	else if (boxes[0][2].getValue() == "X" &&  boxes[1][2].getValue() == "X" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[0][2].getValue() == "X" &&  boxes[1][2].getValue() == "_" && boxes[2][2].getValue() == "X")
	{
		a = 1;
		b = 2;
		return 1;
	}
	else if (boxes[0][2].getValue() == "_" &&  boxes[1][2].getValue() == "X" && boxes[2][2].getValue() == "X")
	{
		a = 0;
		b = 2;
		return 1;
	}
////////////////////////
////////L-R DIAG////////
////////////////////////
	else if (boxes[0][0].getValue() == "X" &&  boxes[1][1].getValue() == "X" && boxes[2][2].getValue() == "_")
	{
		a = 2;
		b = 2;
		return 1;
	}
	else if (boxes[0][0].getValue() == "X" &&  boxes[1][1].getValue() == "_" && boxes[2][2].getValue() == "X")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][0].getValue() == "_" &&  boxes[1][1].getValue() == "X" && boxes[2][2].getValue() == "X")
	{
		a = 0;
		b = 0;
		return 1;
	}
////////////////////////
////////R-L DIAG////////
////////////////////////
	else if (boxes[0][2].getValue() == "X" &&  boxes[1][1].getValue() == "X" && boxes[2][0].getValue() == "_")
	{
		a = 2;
		b = 0;
		return 1;
	}
	else if (boxes[0][2].getValue() == "X" &&  boxes[1][1].getValue() == "_" && boxes[2][0].getValue() == "X")
	{
		a = 1;
		b = 1;
		return 1;
	}
	else if (boxes[0][2].getValue() == "_" &&  boxes[1][1].getValue() == "X" && boxes[2][0].getValue() == "X")
	{
		a = 0;
		b = 2;
		return 1;
	}
	else
	{
		return 0;
	}
}

void checkWin(Box boxes[][3], string& symbol, int& win)
{
//unless I am missing something, there should be 8 different win conditions per player (X or O)
//3 horizontal
//3 vertical
//2 diagonal
//this makes 16 total win conditions
//separate if statements to check all the possibilities
//if win condition is found, set win to 1
//to signify that a win condition was found
//otherwise, the game continues.

	if (boxes[0][0].getValue() == "X" && boxes[1][1].getValue() == "X" && boxes[2][2].getValue() == "X") //diagonal 1: X
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[0][0].getValue() == "O" && boxes[1][1].getValue() == "O" && boxes[2][2].getValue() == "O") //diagonal 1: O
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[0][2].getValue() == "X" && boxes[1][1].getValue() == "X" && boxes[2][0].getValue() == "X") //diagonal 2: X
	{
		symbol = boxes[0][2].getValue();
		win = 1;
	}
	if (boxes[0][2].getValue() == "O" && boxes[1][1].getValue() == "O" && boxes[2][0].getValue() == "O") //diagonal 2: O
	{
		symbol = boxes[0][2].getValue();
		win = 1;
	}
	if (boxes[0][0].getValue() == "X" && boxes[1][0].getValue() == "X" && boxes[2][0].getValue() == "X" ) //vertical 1: X
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[0][0].getValue() == "O" && boxes[1][0].getValue() == "O" && boxes[2][0].getValue() == "O") //vertical 1: O
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[0][1].getValue() == "X" && boxes[1][1].getValue() == "X" && boxes[2][1].getValue() == "X") //vertical 2: X
	{
		symbol = boxes[0][1].getValue();
		win = 1;
	}
	if (boxes[0][1].getValue() == "O" && boxes[1][1].getValue() == "O" && boxes[2][1].getValue() == "O") //vertical 2: O
	{
		symbol = boxes[0][1].getValue();
		win = 1;
	}
	if (boxes[0][2].getValue() == "X" && boxes[1][2].getValue() == "X" && boxes[2][2].getValue() == "X") //vertical 3: X
	{
		symbol = boxes[0][2].getValue();
		win = 1;
	}
	if (boxes[0][2].getValue() == "O" && boxes[1][2].getValue() == "O" && boxes[2][2].getValue() == "O") //vertical 3: O
	{
		symbol = boxes[0][2].getValue();
		win = 1;
	}
	if (boxes[0][0].getValue() == "X" && boxes[0][1].getValue() == "X" && boxes[0][2].getValue() == "X") //horizontal 1: X
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[0][0].getValue() == "O" && boxes[0][1].getValue() == "O" && boxes[0][2].getValue() == "O") //horizontal 1: O
	{
		symbol = boxes[0][0].getValue();
		win = 1;
	}
	if (boxes[1][0].getValue() == "X" && boxes[1][1].getValue() == "X" && boxes[1][2].getValue() == "X") //horizontal 2: X
	{
		symbol = boxes[1][0].getValue();
		win = 1;
	}
	if (boxes[1][0].getValue() == "O" && boxes[1][1].getValue() == "O" && boxes[1][2].getValue() == "O") //horizontal 2: O
	{
		symbol = boxes[1][0].getValue();
		win = 1;
	}
	if (boxes[2][0].getValue() == "X" && boxes[2][1].getValue() == "X" && boxes[2][2].getValue() == "X") //horizontal 3: X
	{
		symbol = boxes[2][0].getValue();
		win = 1;
	}
	if (boxes[2][0].getValue() == "O" && boxes[2][1].getValue() == "O" && boxes[2][2].getValue() == "O") //horizontal 3: O
	{
		symbol = boxes[2][0].getValue();
		win = 1;
	}
//I am really sorry about this line...
//I wanted to check if ALL boxes were played and 
//there is still NO winner, then to call the game as a tie.
//unfortunately there are 9 separate objects to check.
//so i have the code equivalent of a run-on sentence.
//i guess if you have a really wide monitor, this "line" might
//look so bad.
	if (boxes[0][0].getValue() != "_" && boxes[0][1].getValue() != "_" && boxes[0][2].getValue() != "_" && boxes[1][0].getValue() != "_" && boxes[1][1].getValue() != "_" && boxes[1][2].getValue() != "_" && boxes[2][0].getValue() != "_" && boxes[2][1].getValue() != "_" && boxes[2][2].getValue() != "_")
	{
		win = 2;
	}
}
