/**********************************************
 Title:         : 8puzzle.cpp
 Author         : Krirk Pongsema
 Created on     : 4/25/2014
 Description    : Uses a list to find the 
		  solution to the 8 puzzle game
***********************************************/
#include<iostream>
#include<list>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

struct Puzzle
{
	int board[3][3];
	string move;
	Puzzle *parent;
};

bool checkSolution(Puzzle*);
void printPath(list<Puzzle*>);
void findTheBlank(Puzzle* b,int& x, int& y);
void left(list<Puzzle *>&, list<Puzzle *>&, Puzzle*, int, int);
void right(list<Puzzle *>&, list<Puzzle *>&, Puzzle*, int, int);
void up(list<Puzzle *>&, list<Puzzle *>&, Puzzle*, int, int);
void down(list<Puzzle *>&, list<Puzzle *>&, Puzzle*, int, int);

int main()
{
//b1 & b2 will be used for coordinates on the 3x3 grid
	int b1;
	int b2;
	list<Puzzle*>open;
	list<Puzzle*>closed;
//set values for struct variables	
	Puzzle* p = new Puzzle;
//sets the board
	int initialState[3][3]= {{1,2,3},{4,5,6},{7,8,0}};
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			p->board[i][j]=initialState[i][j];
		}
	}
//sets parent
	p->parent=NULL;
//sets move
	p->move =" ";

	open.push_back(p);
	while(!open.empty())
	{
		findTheBlank(open.front(),b1, b2); //finds the zero.
//checks if move is valid before calling function
		if(b2-1>=0) 
		{
			left(open, closed, open.front(), b1,b2);
		}
		if(b1-1>=0)
		{
			up(open, closed, open.front(), b1,b2);
		}
		if(b2+1<=2)
		{
			right(open, closed, open.front(), b1,b2);
		}

		if(b1+1<=2)
		{
			down(open, closed, open.front(), b1,b2);
		}

		closed.push_back(open.front());
		open.pop_front();
	} 
 
return 0;
}
//finds the zero on the grid
void findTheBlank(Puzzle* b,int& x, int& y)
{
	for(int i=0; i<3; i++)  
	{
		for(int j=0; j<3; j++)
		{
			if(b->board[i][j]==0)
			{
				x=i; 
				y=j;
			}
		}
	}
}
void left(list<Puzzle*>& open, list<Puzzle*>& closed, Puzzle* curr , int b1, int b2)
{
	Puzzle* Node= new Puzzle;
//copies the board that was passed to the function to a new pointer declared in the line above
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			Node->board[i][j]=curr->board[i][j];
		}
	}
	Node->board[b1][b2]=curr->board[b1][b2-1]; //sets the value of the box where the zero is to the value of where it is going
	Node->board[b1][b2-1]=0; //completes the swap
//allows us to keep track of the path to the solution
	Node->parent=curr; 
	Node->move="left"; 
//checks if solution is found
	if(checkSolution(Node))
	{
		closed.push_back(Node);
		printPath(closed); 
	}
	else
	{ 

		open.push_back(Node);

	}              
}
void right(list<Puzzle*>& open, list<Puzzle*>& closed, Puzzle* curr , int b1, int b2)
{
	Puzzle* Node= new Puzzle;
//copies the board that was passed to the function to a new pointer declared in the line above
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			Node->board[i][j]=curr->board[i][j];
		}
	}
	Node->board[b1][b2]=curr->board[b1][b2+1]; //sets the value of the box where the zero is to the value of where it is going
	Node->board[b1][b2+1]=0; //completes the swap
//allows us to keep track of the path to the solution
	Node->parent=curr;
	Node->move="right";
//checks if solution is found
	if(checkSolution(Node))
	{
		closed.push_back(Node);
		printPath(closed); 
	}
	else
	{ 

		open.push_back(Node);

	}              
}
void up(list<Puzzle*>& open, list<Puzzle*>& closed, Puzzle* curr , int b1, int b2)
{
	Puzzle* Node= new Puzzle;
//copies the board that was passed to the function to a new pointer declared in the line above
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			Node->board[i][j]=curr->board[i][j];
		}
	}
	Node->board[b1][b2]=curr->board[b1-1][b2]; //sets the value of the box where the zero is to the value of where it is going
	Node->board[b1-1][b2]=0; //completes the swap
//allows us to keep track of the path to the solution
	Node->parent=curr;
	Node->move="up";
//checks if solution is found
	if(checkSolution(Node))
	{
		closed.push_back(Node);
		printPath(closed); 
	}
	else
	{ 

		open.push_back(Node);

	}              
}
void down(list<Puzzle*>& open, list<Puzzle*>& closed, Puzzle* curr , int b1, int b2)
{
	Puzzle* Node= new Puzzle;
//copies the board that was passed to the function to a new pointer declared in the line above
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			Node->board[i][j]=curr->board[i][j];
		}
	}
	Node->board[b1][b2]=curr->board[b1+1][b2]; //sets the value of the box where the zero is to the value of where it is going
	Node->board[b1+1][b2]=0; //completes the swap
//allows us to keep track of the path to the solution
	Node->parent=curr;
	Node->move="down";
//checks if solution is found
	if(checkSolution(Node))
	{
		closed.push_back(Node);
		printPath(closed); 
	}
	else
	{ 

		open.push_back(Node);

	}              
}
bool checkSolution(Puzzle* Node)
{
	int goal[3][3]={{1,2,3},{4,0,5},{6,7,8}};
//if we find a non match, return false
	for(int i=0; i<3; i++) 
	{
		for(int j=0; j<3; j++)
		{
			if(Node->board[i][j]!=goal[i][j])
			{
				return false;
			}
		}
	}
	
	return true; //otherwise return true
}
void printPath(list<Puzzle*> closed)
{
//outputs to txt file
	ofstream outFile;
	outFile.open("path.txt");


	list<Puzzle*> solution;	//list to save the path
	Puzzle* Node = closed.back(); //goal board
	Puzzle* tempNode = Node->parent; //needed to make swaps
 //pushes from the front so we can maintain the order of the events
	solution.push_front(Node); 
	while (Node->parent != NULL)
	{
		solution.push_front(Node->parent);
		Node = tempNode;
		tempNode = Node->parent;
	}
	Puzzle* printNode; //probably didnt need ANOTHER pointer, but I wanted to play it safe
	cout <<"initial state";
	outFile <<"initial state";
	while (!solution.empty())
	{
		printNode = solution.front();
 //will print the list of moves and the board showing the move
		cout <<printNode->move<<endl;
		outFile <<printNode->move<<endl;
		for(int i=0; i<3; i++) 
		{
			for(int j=0; j<3; j++)
			{
				cout <<printNode->board[i][j]<<" ";
				outFile <<printNode->board[i][j]<<" ";
			}
			cout <<endl;
			outFile<<endl;
		}
		solution.pop_front();//removes the pointer so we can go through the list
	}
	cout<<"Goal state"<<endl;
	outFile<<"Goal state"<<endl;
	outFile.close();
	exit(1);
}

