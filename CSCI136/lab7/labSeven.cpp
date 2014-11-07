/*
Title: lab seven
Created By: Krirk Pongsema
Created Date: 10/29/13
Description: structures and classes practice
Modified: figured out how to pass an struct array to a function
Modified Date: 11/4/13
Modified By:
*/ 

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Class of tables
class Table
{
public:
//mutators
	void setTable(int name, char location, int size, bool status);
	void checkTable(); //check if a table is available
	void freeTable(); //sets status to true so others can sit down
	void drawTable(); //print table on screen
	void assignTable(struct Groups g[]); //go through guest list and seat guests
//accessors
	bool getStatus(); //return table's status
	int getName(); //return table name
	char getLocation(); //return table location
	int getSize(); //return table size

private:
	int size;
	int name;
	char location;
	bool status;
}; // end of class


// guest structure
struct Groups
{
	int gSize;
	char location1;
	char location2;
	char where; //needed this so the function would stop looking at groups who were sitting already.
};

const int NUMTABLES = 25; // number of tables
const int NUMGROUPS = 10; // number of groups
// main function
int main()
{
	int choice;
	string done = "n";
//table vars
	int n; //name
	int s; // capacity of table
	int st; //if the table is free or not
	char loc; //location of table (i, w, o)

//group vars
	int groupSize; //group size
	char loc1; //preferred table location
	char loc2; //backup selection for table
	
//creating arrays for tables and groups
	Table tab[NUMTABLES];
	Groups grp[NUMGROUPS] = {{5, 'w', 'b', 'b'}, //grp 1
	{2, 'a', 'a', 'b'}, // grp 2
	{8, 'o', 'w', 'b'}, // grp 3
	{2, 'w', 'b', 'b'}, // grp 4
	{4, 'o', 'w', 'b'}, // grp 5
	{5, 'i', 'b', 'b'}, // grp 6
	{1, 'o', 'b', 'b'}, // grp 7
	{3, 'o', 'b', 'b'}, // grp 8
	{3, 'i', 'b', 'b'}, // grp 9
	{4, 'i', 'b', 'b'}}; // grp 10*
//a = anywhere
//b = bar aka dont have a 2nd pref
//i = inside
//o = outside
//w = window


//setting table information
	for (int i=0; i<NUMTABLES;i++)
	{
		cout << "Please enter info for table " << i+1 <<endl;
		cout << "(name, location, size, status)"<<endl;
		cin >> n >> loc >> s >> st;
		tab[i].setTable(n, loc, s, st);
	}

	while (done != "y")
	{
		cout << "what would you like to do?"<<endl;
		cout << "1: check the status of a table"<<endl;
		cout << "2. see status of all the tables"<<endl;
		cout << "3. clear a table"<<endl;
		cout << "4. go through guest list and assign table"<<endl;
		cout << "5. quit"<<endl;
		cin >> choice;
		if (choice == 1) //check status of 1 table
		{
			int i = 0;
			cout <<"which table?"<<endl;
			cout <<"please enter a number"<<endl;
			cin >> i;
			i = i + 1;
			tab[i].checkTable();
		}
		else if (choice == 2) //check status of all tables
		{
			for (int j=0; j<NUMTABLES; j++) //lists table information
			{
				tab[j].drawTable();
			}
		}
		else if (choice == 3) //clears a table
		{
			int i = 0;
			cout <<"which table would you like to make available?"<<endl;
			cout <<"please enter a number"<<endl;
			cin >> i;
			i = i + 1;
			tab[i].freeTable();
			cout <<"table "<< i <<endl;
		}
		else if (choice == 4)
		{
			
			for (int i = 0; i < NUMTABLES; i++)
			{
				bool stat = tab[i].getStatus();
				if (stat == 1) //table is available
				{
					tab[i].assignTable(grp);
				}
			}
		}
		else if (choice == 5) //quit
		{
			cout << "enjoy your meal!"<<endl;
			done = "y";
		}		
	}



		


	return 0;
}

void Table::checkTable() //check if status is true (1) / false (0)
{
	if (status == 1)
	{
		cout <<"the table is free"<<endl;
	}
	else if (status == 0)
	{
		cout <<"the table is occupied"<<endl;
	}
}

void Table::freeTable() //set status to true (1) (available)
{
	status = 1;

}

void Table::setTable(int name, char location, int size, bool status)
{
	this-> name = name;
	this-> location = location;
	this-> size = size;
	this-> status = status;

}

bool Table::getStatus()
{
	return status;
}

int Table::getName()
{
	return name;
}

char Table::getLocation()
{
	return location;
}

void Table::drawTable()
{
	cout << "\nTable name is: " << name <<endl;
	cout << "Table location is: " << location <<endl;
	cout << "Table status is: " << status <<endl;
	cout << "Table size is: " << size <<endl;
}

void Table::assignTable(struct Groups g[])
{
	for (int i = 0; i < NUMGROUPS; i++)
	{
		if (g[i].where == 'b')
		{
			if ((g[i].location1 == location || g[i].location1 == 'a') && g[i].gSize <= size)
//does location match OR does customer care where they sit AND does the size of the party fit the table
			{
				status = 0;
				cout <<"group " << i+1<< " seated at table " <<name<<endl;
				g[i].where = 's'; //seated
				break;
			}
			else if ((g[i].location2 == location || g[i].location2 == 'a') && g[i].gSize <= size)
//does location match OR does customer care where they sit AND does the size of the party fit the table
			{
				status = 0;
				cout <<"group " << i+1<< " seated at table " <<name<<endl;
				g[i].where = 's'; //seated
				break;
			}
		}

	}
}

