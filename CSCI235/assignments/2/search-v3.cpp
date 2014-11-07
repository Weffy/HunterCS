#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;

class Box
{
	private:
		int id;
		int value;
	public:
		Box();
		int getID();
		int getValue();
		void setID(int x);
		void setValue(int x);

};

void printGrid(Box boxes[]);
void fillGrid(Box boxes[]);
int numOfDigits(long targetWhole);
void fillTargetArray(int targetArray[], long targetWhole, int max, Box boxes[]);
int checkTargetArray(int targetArray[], Box boxes[], int max, int targetCounter, int indexCounter);
int checkMoves(int objID);
void move(int objID, int moves[], int max);
int left(int objID);
int upLeft(int objID);
int up(int objID);
int upRight(int objID);
int right(int objID);
int downRight(int objID);
int down(int objID);
int downLeft(int objID);


int main()
{
	srand(time(NULL));
	long targetWhole;
	Box boxes[81];
	fillGrid(boxes);
	printGrid(boxes);
	ifstream inputFile;
	inputFile.open("numbers.txt");
	while (!inputFile.eof())
	{
		inputFile >> targetWhole;
		int max = numOfDigits(targetWhole);
		int targetArray[max];
		fillTargetArray(targetArray, targetWhole, max, boxes);
		int targetCounter = 0;
		int indexCounter = 0;
		checkTargetArray(targetArray, boxes, max, targetCounter, indexCounter);

	}

	inputFile.close();
	return 0;
}

Box::Box()
{

}

int Box::getID()
{
	return id;
}

int Box::getValue()
{
	return value;
}

void Box::setID(int x)
{
	id = x;
}

void Box::setValue(int x)
{
	value = x;
}

void printGrid(Box boxes[])
{
	int num = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout<<boxes[num].getValue()<< " ";
			num++;
		}
		cout<<endl;
		cout <<endl;

	}
}

void fillGrid(Box boxes[])
{
	int x = 0;
	int random;
	for (int i = 0; i < 81; i++)
	{
		boxes[i].setValue(rand() % 10);
		boxes[i].setID(x);
		x++;
	}

	
}
int numOfDigits(long targetWhole)
{
	int done = 1;
	long divisor = 1;	
	int count = 0;
/*
while loop to separate number we imported (stuff) into its individual parts
this will eventually be placed into a temporary array that we will use to search the matrix
*/
	while (done != 0)
	{
		done = targetWhole / divisor;
		divisor = divisor * 10;
		count++;	
	}
	count = count - 1;
	return count;
}

void fillTargetArray(int targetArray[], long targetWhole, int max, Box boxes[])
{
/*
this loop populates the new temp array with each individual digit that we imported
i.e.,3245 will be distributed:
targetArray[0] = 3
targetArray[1] = 2
targetArray[2] = 4
targetArray[3] = 5
*/
	int j = 1;
	for (int i = 0; i < max; i++)
	{
		targetArray[i] = targetWhole/pow(10, max-j);
		targetWhole = targetWhole - targetArray[i] * pow(10, max-j);
		j++;
		cout << targetArray[i]<< " "; //stub so i can test the output
	}
	cout <<endl;
}

int checkTargetArray(int targetArray[], Box boxes[], int max, int targetCounter, int indexCounter)
{

		if (targetCounter == max) //keeps the array within its defined bounds
		{
			cout <<"targetCounter: "<<targetCounter<<endl;
			cout <<"max: "<<max<<endl;
			return 0;	
		}
		if (targetArray[targetCounter] != boxes[indexCounter].getValue()) //if not equal, check the next index
		{
			checkTargetArray(targetArray, boxes, max, targetCounter, indexCounter+1);
		}

		else //if equal, say where we found the match.  increases the target to check for next number
		{
			cout <<"targetArray["<<targetCounter<<"]: "<<targetArray[targetCounter]<<endl;
			cout << "found a match at: " << indexCounter <<endl;
			cout << boxes[indexCounter].getValue()<<endl;

/*
figuring out the next move
figure out the next move based on the ID number
and how it changes based on direction
if the move is legal, save into a vector
*/
			int objID = 0;
			objID = boxes[indexCounter].getID();
			int maxMoves = checkMoves(objID);
			int moves[maxMoves];
			move(objID, moves, max);

			for (int i = 0; i < maxMoves; i++)
			{
				indexCounter = moves[0];
				cout <<"targetCounter2: "<<targetCounter<<endl;
				checkTargetArray(targetArray, boxes, max, targetCounter+1, indexCounter);

			}
		}

}

void move(int objID, int moves[], int max)
{
	int x;
	int i = 0;
	x = left(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	upLeft(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	up(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	upRight(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	right(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	downRight(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	down(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
	downLeft(objID);
	if (x >= 0)
	{
		moves[i] = x;
		i++;
	}
}

int left(int objID)
{
	objID = objID - 1;
	return objID;
}
int upLeft(int objID)
{
	objID = objID - 10;
	return objID;
}
int up(int objID)
{
	objID = objID - 9;
	return objID;
}
int upRight(int objID)
{
	objID = objID - 8;
	return objID;
}
int right(int objID)
{
	objID = objID + 1;
	return objID;
}
int downRight(int objID)
{
	objID = objID + 10;
	return objID;
}
int down(int objID)
{
	objID = objID + 9;
	return objID;
}
int downLeft(int objID)
{
	objID = objID + 8;
	return objID;
}
int checkMoves(int objID)
{
	int max = 0;
//corners
	if (objID == 0 || objID == 8 || objID == 72 || objID == 80)
	{
		max = 3;
		return max;
	}
//side A
	else if (objID == 9 || objID == 18 || objID == 27 || objID == 36 || objID == 45 || objID == 54 || objID == 63)
	{
		max = 5;
		return max;
	}
//side B
	else if (objID == 17 || objID == 26 || objID == 35 || objID == 44 || objID == 53 || objID == 62 || objID == 71)
	{
		max = 5;
		return max;
	}
//top
	else if (objID >= 1 && objID <= 7)
	{
		max = 5;
		return max;
	}
//bot
	else if (objID >= 73 && objID <= 79)
	{
		max = 5;
		return max;
	}
//mid A
	else if (objID >= 10 && objID <= 16)
	{
		max = 8;
		return max;
	}
//mid B
	else if (objID >= 19 && objID <= 25)
	{
		max = 8;
		return max;
	}
//mid C
	else if (objID >= 28 && objID <= 34)
	{
		max = 8;
		return max;
	}
//mid D
	else if (objID >= 37 && objID <= 43)
	{
		max = 8;
		return max;
	}
//mid E
	else if (objID >= 46 && objID <= 52)
	{
		max = 8;
		return max;
	}
//mid F
	else if (objID >= 55 && objID <= 61)
	{
		max = 8;
		return max;
	}
//mid G
	else if (objID >= 64 && objID <= 70)
	{
		max = 8;
		return max;
	}
}
